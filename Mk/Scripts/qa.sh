#!/bin/sh
# MAINTAINER: portmgr@FreeBSD.org
# $FreeBSD$

set -o pipefail

if [ -z "${STAGEDIR}" -o -z "${PREFIX}" -o -z "${LOCALBASE}" ]; then
	echo "STAGEDIR, PREFIX, LOCALBASE required in environment." >&2
	exit 1
fi

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_QA}" ] && set -x

LF=$(printf '\nX')
LF=${LF%X}

notice() {
	echo "Notice: $*" >&2
}

warn() {
	echo "Warning: $*" >&2
}

err() {
	echo "Error: $*" >&2
}

list_stagedir_elfs() {
	cd ${STAGEDIR} && find -s . -type f \( -perm +111 -o -name '*.so*' \) "$@"
}

shebangonefile() {
	local f interp interparg badinterp rc

	f="$*"
	rc=0

	# whitelist some files
	case "${f}" in
	*.pm|*.pod|*.txt|${STAGEDIR}${LINUXBASE}/*)
		return 0
		;;
	esac

	interp=$(sed -n -e '1s/^#![[:space:]]*\([^[:space:]]*\).*/\1/p;2q' "${f}")
	badinterp=""
	case "${interp}" in
	"") ;;
	/bin/rc)
		# whitelist some interpreters
		;;
	${LOCALBASE}/bin/python|${PREFIX}/bin/python|${LOCALBASE}/bin/python2|${PREFIX}/bin/python2|${LOCALBASE}/bin/python3|${PREFIX}/bin/python3)
		badinterp="${interp}"
		;;
	${LINUXBASE}/*) ;;
	${LOCALBASE}/bin/perl5.* | ${PREFIX}/bin/perl5.*)
		# lang/perl5* are allowed to have these shebangs.
		if ! expr ${PKGORIGIN} : '^lang/perl5.*' > /dev/null; then
			err "'${interp}' is an invalid shebang for '${f#${STAGEDIR}${PREFIX}/}' you must use ${LOCALBASE}/bin/perl."
			err "Either pass \${PERL} to the build or use USES=shebangfix"
			rc=1
		fi
		;;
	${LOCALBASE}/*) ;;
	${PREFIX}/*) ;;
	/bin/csh) ;;
	/bin/sh) ;;
	/bin/tcsh) ;;
	/usr/bin/awk) ;;
	/usr/bin/env)
		interparg=$(sed -n -e '1s/^#![[:space:]]*[^[:space:]]*[[:space:]]*\([^[:space:]]*\).*/\1/p;2q' "${f}")
		case "${interparg}" in
		python|python2|python3)
			badinterp="${interp} ${interparg}"
			;;
		esac
		;;
	/usr/bin/nawk) ;;
	/usr/bin/sed) ;;
	/usr/sbin/dtrace) ;;
	/usr/bin/make) ;;
	/usr/libexec/atf-sh) ;;
	*)
		badinterp="${interp}"
		;;
	esac

	if [ -n "${badinterp}" ]; then
		err "'${badinterp}' is an invalid shebang you need USES=shebangfix for '${f#${STAGEDIR}${PREFIX}/}'"
		rc=1
	fi

	return ${rc}
}

shebang() {
	local f l link rc

	rc=0

	while read -r f; do
		# No results presents a blank line from heredoc.
		[ -z "${f}" ] && continue
		shebangonefile "${f}" || rc=1
	# Use heredoc to avoid losing rc from find|while subshell
	done <<-EOF
	$(find ${STAGEDIR}${PREFIX} \
	    -type f -perm +111 2>/dev/null)
	EOF

	return ${rc}
}

baselibs() {
	local rc
	local found_openssl
	local file
	[ "${PKGBASE}" = "pkg" -o "${PKGBASE}" = "pkg-devel" ] && return
	while read -r f; do
		case ${f} in
		File:\ .*)
			file=${f#File: .}
			;;
		*NEEDED*\[libarchive.so.[56]])
			err "Bad linking on ${f##* } for ${file} please add USES=libarchive"
			rc=1
			;;
		*NEEDED*\[libedit.so.7])
			err "Bad linking on ${f##* } for ${file} please add USES=libedit"
			rc=1
			;;
		*NEEDED*\[libcrypto.so.*]|*NEEDED*\[libssl.so.*])
			found_openssl=1
			;;
		esac
	done <<-EOF
	$(list_stagedir_elfs -exec readelf -d {} + 2>/dev/null)
	EOF
	if [ -z "${USESSSL}" -a -n "${found_openssl}" ]; then
		warn "you need USES=ssl"
	elif [ -n "${USESSSL}" -a -z "${found_openssl}" ]; then
		warn "you may not need USES=ssl"
	fi
	return ${rc}
}

symlinks() {
	local rc

	rc=0

	# Split stat(1) result into 2 lines and read each line separately to
	# retain spaces in filenames.
	while read -r l; do
		# No results presents a blank line from heredoc.
		[ -z "${l}" ] && continue
		read -r link
		case "${link}" in
			${STAGEDIR}*)
				err "Bad symlink '${l#${STAGEDIR}${PREFIX}/}' pointing inside the stage directory"
				rc=1
				;;
			/*)
				# Only warn for symlinks within the package.
				if [ -e "${STAGEDIR}${link}" ]; then
					warn "Bad symlink '${l#${STAGEDIR}}' pointing to an absolute pathname '${link}'"
				fi
				# Also warn if the symlink exists nowhere.
				if [ ! -e "${STAGEDIR}${link}" -a ! -e "${link}" ]; then
					warn "Symlink '${l#${STAGEDIR}}' pointing to '${link}' which does not exist in the stage directory or in localbase"
				fi
				;;
		esac
	# Use heredoc to avoid losing rc from find|while subshell.
	done <<-EOF
	$(find ${STAGEDIR} -type l -exec stat -f "%N${LF}%Y" {} +)
	EOF

	return ${rc}
}

paths() {
	local rc

	rc=0

	while read -r f; do
		# No results presents a blank line from heredoc.
		[ -z "${f}" ] && continue
		# Ignore false-positive/harmless files
		case "${f}" in
			*/lib/ruby/gems/*) continue ;;
			*/share/texmf-var/web2c/*/*.fmt) continue ;;
			*/share/texmf-var/web2c/*/*.log) continue ;;
		esac
		err "'${f#${STAGEDIR}${PREFIX}/}' is referring to ${STAGEDIR}"
		rc=1
	# Use heredoc to avoid losing rc from find|while subshell
	done <<-EOF
	$(find ${TMPPLIST} ${STAGEDIR} -type f -exec grep -l "${STAGEDIR}" {} +)
	EOF

	return ${rc}
}

# For now do not raise an error, just warnings
stripped() {
	[ -x /usr/bin/file ] || return # this is fatal
	[ -n "${STRIP}" ] || return 0
	# Split file and result into 2 lines and read separately to ensure
	# files with spaces are kept intact.
	# Using readelf -h ... /ELF Header:/ will match on all ELF files.
	find ${STAGEDIR} -type f ! -name '*.a' ! -name '*.o' \
	    -exec sh -c 'readelf -S -- /dev/null "$@" || :' -- {} + 2>/dev/null | awk '
	    /File:/ {sub(/File: /, "", $0); file=$0}
	    /[[:space:]]\.debug_info[[:space:]]*PROGBITS/ {print file}' |
	    while read -r f; do
		warn "'${f#${STAGEDIR}${PREFIX}/}' is not stripped consider trying INSTALL_TARGET=install-strip or using \${STRIP_CMD}"
	done
}

desktopfileutils() {
	if [ -z "${USESDESKTOPFILEUTILS}" ]; then
		grep -q MimeType= ${STAGEDIR}${PREFIX}/share/applications/*.desktop 2>/dev/null &&
		warn "you need USES=desktop-file-utils"
	else
		grep -q MimeType= ${STAGEDIR}${PREFIX}/share/applications/*.desktop 2>/dev/null ||
		warn "you may not need USES=desktop-file-utils"
	fi
	return 0
}

sharedmimeinfo() {
	local f found

	found=0
	for f in ${STAGEDIR}${PREFIX}/share/mime/packages/*.xml; do
		[ "${f}" = "${STAGEDIR}${PREFIX}/share/mime/packages/*.xml" ] && break #no matches
		[ "${f}" = "${STAGEDIR}${PREFIX}/share/mime/packages/freedesktop.org.xml" ] && continue
		found=1
		break
	done
	if [ -z "${USESSHAREDMIMEINFO}" -a ${found} -eq 1 ]; then
		warn "you need USES=shared-mime-info"
	elif [ -n "${USESSHAREDMIMEINFO}" -a ${found} -eq 0 ]; then
		warn "you may not need USES=shared-mime-info"
	fi
	return 0
}

suidfiles() {
	local filelist

	filelist=$(find ${STAGEDIR} -type f \
		\( -perm -u+x -or -perm -g+x -or -perm -o+x \) \
		\( -perm -u+s -or -perm -g+s \))
	if [ -n "${filelist}" ]; then
		warn "setuid files in the stage directory (are these necessary?):"
		ls -liTd ${filelist}
	fi
	return 0
}

libtool() {
	if [ -z "${USESLIBTOOL}" ]; then
		find ${STAGEDIR} -name '*.la' | while read -r f; do
			if grep -q 'libtool library' "${f}"; then
				err ".la libraries found, port needs USES=libtool"
				return 1
			fi
		done
		# The return above continues here.
	fi
}

libperl() {
	local has_some_libperl_so files found
	if [ -n "${SITE_ARCH_REL}" -a -d "${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}" ]; then
		has_some_libperl_so=0
		files=0
		while read -r f; do
			# No results presents a blank line from heredoc.
			[ -z "${f}" ] && continue
			files=$((files+1))
			found=$(readelf -d ${f} | awk "BEGIN {libperl=1}
				/NEEDED.*${LIBPERL}/  { libperl = 0 }
				END {print libperl}
				")
			case "${found}" in
				1)
					warn "${f} is not linked with ${LIBPERL}, not respecting lddlflags?"
					;;
				0)
					has_some_libperl_so=1
					;;
			esac
		# Use heredoc to avoid losing rc from find|while subshell
		done <<-EOT
		$(find ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL} -name '*.so')
		EOT

		if [ ${files} -gt 0 -a ${has_some_libperl_so} -eq 0 ]; then
			err "None of the ${files} .so in ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL} are linked with ${LIBPERL}, see above for the full list."
			return 1
		else
			return 0
		fi
	fi
}

prefixvar() {
	if [ ${PREFIX} != ${LINUXBASE} -a -d ${STAGEDIR}${PREFIX}/var ]; then
		warn "port uses ${PREFIX}/var instead of /var"
	fi
}

terminfo() {
	local f found

	for f in ${STAGEDIR}${PREFIX}/share/misc/*.terminfo; do
		[ "${f}" = "${STAGEDIR}${PREFIX}/share/misc/*.terminfo" ] && break #no matches
		found=1
		break
	done
	for f in ${STAGEDIR}${PREFIX}/share/misc/terminfo.db*; do
		[ "${f}" = "${STAGEDIR}${PREFIX}/share/misc/terminfo.db*" ] && break #no matches
		found=1
		break
	done
	if [ -z "${USESTERMINFO}" -a -n "${found}" ]; then
		warn "you need USES=terminfo"
	elif [ -n "${USESTERMINFO}" -a -z "${found}" ]; then
		warn "you may not need USES=terminfo"
	fi
	return 0
}

listcontains() {
	local str lst elt
	str=$1
	lst=$2

	for elt in ${lst} ; do
		if [ ${elt} = ${str} ]; then
			return 0
		fi
	done
	return 1
}

proxydeps_suggest_uses() {
	local pkg=$1
	local lib_file=$2

	# miscellaneous USE clauses
	if [ ${pkg} = 'devel/gettext-runtime' ]; then
		warn "you need USES+=gettext-runtime"
	elif [ ${pkg} = 'databases/sqlite3' ]; then
		warn "you need USES+=sqlite"
	elif [ ${pkg} = 'databases/sqlite2' ]; then
		warn "you need USES+=sqlite:2"
	# Gnome -> same as port
	# grep LIB_DEPENDS= Mk/Uses/gnome.mk |sed -e 's|\(.*\)_LIB_DEPENDS.*:\(.*\)\/\(.*\)|[ "\1" = "\3" ] \&\& echo "\\${pkg} = \\\"\2/\3\\\" -o \\\\"|'|sort|sh
	elif [ ${pkg} = "accessibility/atk" -o \
		${pkg} = "accessibility/atkmm" -o \
		${pkg} = "graphics/cairo" -o \
		${pkg} = "graphics/cairomm" -o \
		${pkg} = "devel/dconf" -o \
		${pkg} = "devel/gconf2" -o \
		${pkg} = "devel/gconfmm26" -o \
		${pkg} = "devel/glib20" -o \
		${pkg} = "devel/glibmm" -o \
		${pkg} = "audio/gsound" -o \
		${pkg} = "x11-toolkits/gtk20" -o \
		${pkg} = "x11-toolkits/gtk30" -o \
		${pkg} = "www/gtkhtml3" -o \
		${pkg} = "www/gtkhtml4" -o \
		${pkg} = "x11-toolkits/gtkmm20" -o \
		${pkg} = "x11-toolkits/gtkmm24" -o \
		${pkg} = "x11-toolkits/gtkmm30" -o \
		${pkg} = "x11-toolkits/gtksourceview" -o \
		${pkg} = "x11-toolkits/gtksourceview2" -o \
		${pkg} = "x11-toolkits/gtksourceview3" -o \
		${pkg} = "x11-toolkits/gtksourceviewmm3" -o \
		${pkg} = "devel/libbonobo" -o \
		${pkg} = "x11-toolkits/libbonoboui" -o \
		${pkg} = "databases/libgda5" -o \
		${pkg} = "databases/libgda5-ui" -o \
		${pkg} = "databases/libgdamm5" -o \
		${pkg} = "devel/libglade2" -o \
		${pkg} = "x11/libgnome" -o \
		${pkg} = "graphics/libgnomecanvas" -o \
		${pkg} = "x11/libgnomekbd" -o \
		${pkg} = "x11-toolkits/libgnomeui" -o \
		${pkg} = "devel/libgsf" -o \
		${pkg} = "www/libgtkhtml" -o \
		${pkg} = "x11-toolkits/libgtksourceviewmm" -o \
		${pkg} = "graphics/librsvg2" -o \
		${pkg} = "devel/libsigc++12" -o \
		${pkg} = "devel/libsigc++20" -o \
		${pkg} = "x11-toolkits/libwnck" -o \
		${pkg} = "x11-toolkits/libwnck3" -o \
		${pkg} = "textproc/libxml++26" -o \
		${pkg} = "textproc/libxml2" -o \
		${pkg} = "textproc/libxslt" -o \
		${pkg} = "x11-wm/metacity" -o \
		${pkg} = "x11-toolkits/pango" -o \
		${pkg} = "x11-toolkits/pangomm" -o \
		${pkg} = "x11-toolkits/pangox-compat" -o \
		${pkg} = "x11-toolkits/vte" -o \
		${pkg} = "x11-toolkits/vte3" ]; then
		warn "you need USE_GNOME+=${pkg#*/}"
	# Gnome different as port
	# grep LIB_DEPENDS= Mk/Uses/gnome.mk |sed -e 's|\(.*\)_LIB_DEPENDS.*:\(.*\)\/\(.*\)|[ "\1" = "\3" ] \|\| echo "elif [ \\${pkg} = \\\"\2/\3\\\" ]; then; warn \\\"you need USE_GNOME+=\1\\\""|'|sort|sh
	elif [ ${pkg} = "databases/evolution-data-server" ]; then warn "you need USE_GNOME+=evolutiondataserver3"
	elif [ ${pkg} = "graphics/gdk-pixbuf" ]; then warn "you need USE_GNOME+=gdkpixbuf"
	elif [ ${pkg} = "graphics/gdk-pixbuf2" ]; then warn "you need USE_GNOME+=gdkpixbuf2"
	elif [ ${pkg} = "x11/gnome-desktop" ]; then warn "you need USE_GNOME+=gnomedesktop3"
	elif [ ${pkg} = "devel/gnome-vfs" ]; then warn "you need USE_GNOME+=gnomevfs2"
	elif [ ${pkg} = "devel/gobject-introspection" ]; then warn "you need USE_GNOME+=introspection"
	elif [ ${pkg} = "graphics/libart_lgpl" ]; then warn "you need USE_GNOME+=libartlgpl2"
	elif [ ${pkg} = "devel/libIDL" ]; then warn "you need USE_GNOME+=libidl"
	elif [ ${pkg} = "x11-fm/nautilus" ]; then warn "you need USE_GNOME+=nautilus3"
	elif [ ${pkg} = "devel/ORBit2" ]; then warn "you need USE_GNOME+=orbit2"
	elif [ ${pkg} = "graphics/librsvg2-rust" ]; then warn "you need USE_GNOME+=librsvg2"
	# mate
	# grep LIB_DEPENDS= Mk/Uses/mate.mk |sed -e 's|\(.*\)_LIB_DEPENDS.*:\(.*\)\/\(.*\)|elif [ ${pkg} = "\2/\3" ]; then warn "you need USE_MATE+=\1"|'
	elif [ ${pkg} = "x11-fm/caja" ]; then warn "you need USE_MATE+=caja"
	elif [ ${pkg} = "sysutils/mate-control-center" ]; then warn "you need USE_MATE+=controlcenter"
	elif [ ${pkg} = "x11/mate-desktop" ]; then warn "you need USE_MATE+=desktop"
	elif [ ${pkg} = "x11/libmatekbd" ]; then warn "you need USE_MATE+=libmatekbd"
	elif [ ${pkg} = "net/libmateweather" ]; then warn "you need USE_MATE+=libmateweather"
	elif [ ${pkg} = "x11-wm/marco" ]; then warn "you need USE_MATE+=marco"
	elif [ ${pkg} = "x11/mate-menus" ]; then warn "you need USE_MATE+=menus"
	elif [ ${pkg} = "x11/mate-panel" ]; then warn "you need USE_MATE+=panel"
	elif [ ${pkg} = "sysutils/mate-polkit" ]; then warn "you need USE_MATE+=polkit"
	# KDE
	# grep -B1 _LIB= Mk/Uses/kde.mk | grep _PORT=|sed -e 's/^kde-\(.*\)_PORT=[[:space:]]*\([^[:space:]]*\).*/elif [ ${pkg} = "\2" ]; then warn "you need to use USE_KDE+=\1"/' 
	# KDE Applications
	elif [ ${pkg} = "net/akonadi-contacts" ]; then warn "you need to use USE_KDE+=akonadicontacts"
	elif [ ${pkg} = "deskutils/akonadi-import-wizard" ]; then warn "you need to use USE_KDE+=akonadiimportwizard"
	elif [ ${pkg} = "net/akonadi-mime" ]; then warn "you need to use USE_KDE+=akonadimime"
	elif [ ${pkg} = "net/akonadi-notes" ]; then warn "you need to use USE_KDE+=akonadinotes"
	elif [ ${pkg} = "net/akonadi-calendar" ]; then warn "you need to use USE_KDE+=akonadicalendar"
	elif [ ${pkg} = "net/akonadi-search" ]; then warn "you need to use USE_KDE+=akonadisearch"
	elif [ ${pkg} = "net/kalarmcal" ]; then warn "you need to use USE_KDE+=alarmcalendar"
	elif [ ${pkg} = "net/calendarsupport" ]; then warn "you need to use USE_KDE+=calendarsupport"
	elif [ ${pkg} = "net/kcalcore" ]; then warn "you need to use USE_KDE+=calendarcore"
	elif [ ${pkg} = "net/kcalutils" ]; then warn "you need to use USE_KDE+=calendarutils"
	elif [ ${pkg} = "net/kcontacts" ]; then warn "you need to use USE_KDE+=contacts"
	elif [ ${pkg} = "net/eventviews" ]; then warn "you need to use USE_KDE+=eventviews"
	elif [ ${pkg} = "net/libkgapi" ]; then warn "you need to use USE_KDE+=gapi"
	elif [ ${pkg} = "deskutils/grantleetheme" ]; then warn "you need to use USE_KDE+=grantleetheme"
	elif [ ${pkg} = "net/libgravatar" ]; then warn "you need to use USE_KDE+=gravatar"
	elif [ ${pkg} = "net/kidentitymanagement" ]; then warn "you need to use USE_KDE+=identitymanagement"
	elif [ ${pkg} = "net/kimap" ]; then warn "you need to use USE_KDE+=imap"
	elif [ ${pkg} = "net/incidenceeditor" ]; then warn "you need to use USE_KDE+=incidenceeditor"
	elif [ ${pkg} = "deskutils/kdepim-apps-libs" ]; then warn "you need to use USE_KDE+=kdepim-apps-libs"
	elif [ ${pkg} = "net/kitinerary" ]; then warn "you need to use USE_KDE+=kitinerary"
	elif [ ${pkg} = "net/kontactinterface" ]; then warn "you need to use USE_KDE+=kontactinterface"
	elif [ ${pkg} = "net/kf5-kdav" ]; then warn "you need to use USE_KDE+=kdav"
	elif [ ${pkg} = "security/kpkpass" ]; then warn "you need to use USE_KDE+=kpkpass"
	elif [ ${pkg} = "net/ksmtp" ]; then warn "you need to use USE_KDE+=ksmtp"
	elif [ ${pkg} = "net/kldap" ]; then warn "you need to use USE_KDE+=ldap"
	elif [ ${pkg} = "deskutils/libkdepim" ]; then warn "you need to use USE_KDE+=libkdepim"
	elif [ ${pkg} = "security/libkleo" ]; then warn "you need to use USE_KDE+=libkleo"
	elif [ ${pkg} = "net/libksieve" ]; then warn "you need to use USE_KDE+=libksieve"
	elif [ ${pkg} = "net/mailcommon" ]; then warn "you need to use USE_KDE+=mailcommon"
	elif [ ${pkg} = "net/mailimporter" ]; then warn "you need to use USE_KDE+=mailimporter"
	elif [ ${pkg} = "net/kmailtransport" ]; then warn "you need to use USE_KDE+=mailtransport"
	elif [ ${pkg} = "net/kmbox" ]; then warn "you need to use USE_KDE+=mbox"
	elif [ ${pkg} = "net/messagelib" ]; then warn "you need to use USE_KDE+=messagelib"
	elif [ ${pkg} = "net/kmime" ]; then warn "you need to use USE_KDE+=mime"
	elif [ ${pkg} = "net/pimcommon" ]; then warn "you need to use USE_KDE+=pimcommon"
	elif [ ${pkg} = "net/kpimtextedit" ]; then warn "you need to use USE_KDE+=pimtextedit"
	elif [ ${pkg} = "net/ktnef" ]; then warn "you need to use USE_KDE+=tnef"
	elif [ ${pkg} = "databases/akonadi" ]; then warn "you need to use USE_KDE+=akonadi"
	elif [ ${pkg} = "sysutils/baloo-widgets" ]; then warn "you need to use USE_KDE+=baloo-widgets"
	elif [ ${pkg} = "audio/libkcddb" ]; then warn "you need to use USE_KDE+=libkcddb"
	elif [ ${pkg} = "audio/libkcompactdisc" ]; then warn "you need to use USE_KDE+=libkcompactdisc"
	elif [ ${pkg} = "graphics/libkdcraw" ]; then warn "you need to use USE_KDE+=libkdcraw"
	elif [ ${pkg} = "games/libkdegames" ]; then warn "you need to use USE_KDE+=libkdegames"
	elif [ ${pkg} = "misc/libkeduvocdocument" ]; then warn "you need to use USE_KDE+=libkeduvocdocument"
	elif [ ${pkg} = "graphics/libkexiv2" ]; then warn "you need to use USE_KDE+=libkexiv2"
	elif [ ${pkg} = "graphics/libkipi" ]; then warn "you need to use USE_KDE+=libkipi"
	elif [ ${pkg} = "graphics/libksane" ]; then warn "you need to use USE_KDE+=libksane"
	elif [ ${pkg} = "astro/marble" ]; then warn "you need to use USE_KDE+=marble"
	elif [ ${pkg} = "graphics/okular" ]; then warn "you need to use USE_KDE+=okular"
	# KDE Plasma
	elif [ ${pkg} = "x11/plasma5-kactivitymanagerd" ]; then warn "you need to use USE_KDE+=activitymanagerd"
	elif [ ${pkg} = "x11-wm/plasma5-kdecoration" ]; then warn "you need to use USE_KDE+=decoration"
	elif [ ${pkg} = "devel/plasma5-khotkeys" ]; then warn "you need to use USE_KDE+=hotkeys"
	elif [ ${pkg} = "sysutils/plasma5-kmenuedit" ]; then warn "you need to use USE_KDE+=kmenuedit"
	elif [ ${pkg} = "security/plasma5-kscreenlocker" ]; then warn "you need to use USE_KDE+=kscreenlocker"
	elif [ ${pkg} = "x11/plasma5-libkscreen" ]; then warn "you need to use USE_KDE+=libkscreen"
	elif [ ${pkg} = "sysutils/plasma5-libksysguard" ]; then warn "you need to use USE_KDE+=libksysguard"
	elif [ ${pkg} = "deskutils/plasma5-milou" ]; then warn "you need to use USE_KDE+=milou"
	elif [ ${pkg} = "x11-themes/plasma5-oxygen" ]; then warn "you need to use USE_KDE+=oxygen"
	elif [ ${pkg} = "x11/plasma5-plasma-workspace" ]; then warn "you need to use USE_KDE+=plasma-workspace"
	elif [ ${pkg} = "sysutils/plasma5-powerdevil" ]; then warn "you need to use USE_KDE+=powerdevil"
	# KDE Frameworks
	elif [ ${pkg} = "x11-toolkits/kf5-attica" ]; then warn "you need to use USE_KDE+=attica"
	elif [ ${pkg} = "sysutils/kf5-baloo" ]; then warn "you need to use USE_KDE+=baloo"
	elif [ ${pkg} = "x11/kf5-frameworkintegration" ]; then warn "you need to use USE_KDE+=frameworkintegration"
	elif [ ${pkg} = "devel/kf5-kcmutils" ]; then warn "you need to use USE_KDE+=kcmutils"
	elif [ ${pkg} = "devel/kf5-kdeclarative" ]; then warn "you need to use USE_KDE+=kdeclarative"
	elif [ ${pkg} = "x11/kf5-kded" ]; then warn "you need to use USE_KDE+=kded"
	elif [ ${pkg} = "x11/kf5-kdelibs4support" ]; then warn "you need to use USE_KDE+=kdelibs4support"
	elif [ ${pkg} = "security/kf5-kdesu" ]; then warn "you need to use USE_KDE+=kdesu"
	elif [ ${pkg} = "www/kf5-kdewebkit" ]; then warn "you need to use USE_KDE+=kdewebkit"
	elif [ ${pkg} = "www/kf5-khtml" ]; then warn "you need to use USE_KDE+=khtml"
	elif [ ${pkg} = "devel/kf5-kio" ]; then warn "you need to use USE_KDE+=kio"
	elif [ ${pkg} = "lang/kf5-kross" ]; then warn "you need to use USE_KDE+=kross"
	elif [ ${pkg} = "x11/kf5-plasma-framework" ]; then warn "you need to use USE_KDE+=plasma-framework"
	elif [ ${pkg} = "graphics/kf5-prison" ]; then warn "you need to use USE_KDE+=prison"
	elif [ ${pkg} = "misc/kf5-purpose" ]; then warn "you need to use USE_KDE+=purpose"
	elif [ ${pkg} = "devel/kf5-solid" ]; then warn "you need to use USE_KDE+=solid"
	elif [ ${pkg} = "textproc/kf5-sonnet" ]; then warn "you need to use USE_KDE+=sonnet"
	elif [ ${pkg} = "net/kf5-syndication" ]; then warn "you need to use USE_KDE+=syndication"
	elif [ ${pkg} = "textproc/kf5-syntax-highlighting" ]; then warn "you need to use USE_KDE+=syntaxhighlighting"
	elif [ ${pkg} = "devel/kf5-threadweaver" ]; then warn "you need to use USE_KDE+=threadweaver"
	elif expr ${pkg} : '.*/kf5-.*' > /dev/null; then
		warn "you need USE_KDE+=$(echo ${pkg} | sed -E 's|.*/kf5-k||')"
	# GStreamer 0.10
	elif [ ${pkg} = "multimedia/gstreamer" ]; then warn "you need to use USE_GSTREAMER+=yes"
	elif [ ${pkg} = "multimedia/gstreamer-plugins" ]; then warn "you need to use USE_GSTREAMER+=yes"
	elif [ ${pkg} = "multimedia/gstreamer-plugins-bad" ]; then warn "you need to use USE_GSTREAMER+=bad"
	# GStreamer 1
	elif [ ${pkg} = "multimedia/gstreamer1" ]; then warn "you need to use USE_GSTREAMER1+=yes"
	elif [ ${pkg} = "multimedia/gstreamer1-plugins" ]; then warn "you need to use USE_GSTREAMER1+=yes"
	elif [ ${pkg} = "multimedia/gstreamer1-plugins-bad" ]; then warn "you need to use USE_GSTREAMER1+=bad"
	# boost related
	elif [ ${pkg} = "devel/boost-python-libs" ]; then warn "you need to add LIB_DEPENDS+=\${PY_BOOST} and maybe USES+=python"
	# sdl-related
	elif [ ${pkg} = 'devel/sdl12' ]; then
		warn "you need USE_SDL+=sdl"
	elif echo ${pkg} | grep -E '/sdl_(console|gfx|image|mixer|mm|net|pango|sound|ttf)$' > /dev/null; then
		warn "you need USE_SDL+=$(echo ${pkg} | sed -E 's|.*/sdl_||')"
	elif [ ${pkg} = 'devel/sdl20' ]; then
		warn "you need USE_SDL+=sdl2"
	elif echo ${pkg} | grep -E '/sdl2_(gfx|image|mixer|net|ttf)$' > /dev/null; then
		warn "you need USE_SDL+=$(echo ${pkg} | sed -E 's|.*/sdl2_||')2"
	# gl-related
	elif expr ${lib_file} : "${LOCALBASE}/lib/libGL.so.*$" > /dev/null; then
		warn "you need USE_GL+=gl"
	elif expr ${lib_file} : "${LOCALBASE}/lib/libgbm.so.*$" > /dev/null; then
		warn "you need USE_GL+=gbm"
	elif expr ${lib_file} : "${LOCALBASE}/lib/libGLESv2.so.*$" > /dev/null; then
		warn "you need USE_GL+=glesv2"
	elif expr ${lib_file} : "${LOCALBASE}/lib/libEGL.so.*$" > /dev/null; then
		warn "you need USE_GL+=egl"
	elif [ ${pkg} = 'graphics/glew' ]; then
		warn "you need USE_GL+=glew"
	elif [ ${pkg} = 'graphics/libGLU' ]; then
		warn "you need USE_GL+=glu"
	elif [ ${pkg} = 'graphics/libGLw' ]; then
		warn "you need USE_GL+=glw"
	elif [ ${pkg} = 'graphics/freeglut' ]; then
		warn "you need USE_GL+=glut"
	# Xorg-libraries: this should be by XORG_MODULES @ bsd.xorg.mk
	elif echo ${pkg} | grep -E '/lib(X11|Xau|Xdmcp|Xext|SM|ICE|Xfixes|Xft|Xdamage|Xcomposite|Xcursor|Xinerama|Xmu|Xmuu|Xpm|Xt|Xtst|Xi|Xrandr|Xrender|Xres|XScrnSaver|Xv|Xxf86vm|Xxf86dga|Xxf86misc|xcb)$' > /dev/null; then
		warn "you need USE_XORG+=$(echo ${pkg} | sed -E 's|.*/lib||' | tr '[:upper:]' '[:lower:]')"
	elif [ ${pkg} = 'x11/pixman' ]; then
		warn "you need USE_XORG+=pixman"
	# Qt5
	elif expr ${pkg} : '.*/qt5-.*' > /dev/null; then
		warn "you need USES=qt:5 and USE_QT+=$(echo ${pkg} | sed -E 's|.*/qt5-||')"
	# MySQL
	elif expr ${lib_file} : "${LOCALBASE}/lib/mysql/[^/]*$" > /dev/null; then
		warn "you need USES+=mysql"
	# postgresql
	elif expr ${pkg} : "^databases/postgresql.*-client" > /dev/null; then
		warn "you need USES+=pgsql"
	# bdb
	elif expr ${pkg} : "^databases/db[456]" > /dev/null; then
		warn "you need USES+=bdb"
	# fam/gamin
	elif [ ${pkg} = "devel/fam" -o ${pkg} = "devel/gamin" ]; then
		warn "you need USES+=fam"
	# firebird
	elif [ ${pkg} = "databases/firebird25-client" ]; then
		warn "you need USES+=firebird"
	# fuse
	elif [ ${pkg} = "sysutils/fusefs-libs" ]; then
		warn "you need USES+=fuse"
	# gnustep
	elif [ ${pkg} = "lang/gnustep-base" ]; then
		warn "you need USES+=gnustep and USE_GNUSTEP+=base"
	elif [ ${pkg} = "x11-toolkits/gnustep-gui" ]; then
		warn "you need USES+=gnustep and USE_GNUSTEP+=gui"
	# iconv
	elif [ ${pkg} = "converters/libiconv" ]; then
		warn "you need USES+=iconv, USES+=iconv:wchar_t, or USES+=iconv:translit depending on needs"
	# jpeg
	elif [ ${pkg} = "graphics/jpeg-turbo" ]; then
		warn "you need USES+=jpeg"
	# libarchive
	elif [ ${pkg} = "archivers/libarchive" ]; then
		warn "you need USES+=libarchive"
	elif [ ${pkg} = "devel/libedit" ]; then
		warn "you need USES+=libedit"
	# lua
	elif expr ${pkg} : "^lang/lua" > /dev/null; then
		warn "you need USES+=lua"
	# motif
	elif [ ${pkg} = "x11-toolkits/lesstif" -o ${pkg} = "x11-toolkits/open-motif" ]; then
		warn "you need USES+=motif"
	# ncurses
	elif [ ${pkg} = "devel/ncurses" ]; then
		warn "you need USES+=ncurses"
	# objc
	elif [ ${pkg} = "lang/libobjc2" ]; then
		warn "you need USES+=objc"
	# openal
	elif [ ${pkg} = "audio/openal" -o ${pkg} = "audio/openal-soft" -o ${pkg} = "audio/freealut" ]; then
		warn "you need USES+=openal"
	# readline
	elif [ ${pkg} = "devel/readline" ]; then
		warn "you need USES+=readline"
	# ssl
	elif [ ${pkg} = "security/openssl" -o ${pkg} = "security/openssl111" \
	  -o ${pkg} = "security/libressl" -o ${pkg} = "security/libressl-devel" \
	  ]; then
		warn "you need USES=ssl"
	# Tcl
	elif expr ${pkg} : "^lang/tcl" > /dev/null; then
		warn "you need USES+=tcl"
	# Tk
	elif expr ${pkg} : "^x11-toolkits/tk" > /dev/null; then
		warn "you need USES+=tk"
	# Xfce
	# grep LIB_DEPENDS= Mk/Uses/xfce.mk |sed -e 's|\(.*\)_LIB_DEPENDS.*:\(.*\)\/\(.*\)|elif [ ${pkg} = "\2/\3" ]; then warn "you need USE_XFCE+=\1"|'
	elif [ ${pkg} = "sysutils/garcon" ]; then warn "you need USE_XFCE+=garcon"
	elif [ ${pkg} = "x11/libexo" ]; then warn "you need USE_XFCE+=libexo"
	elif [ ${pkg} = "x11-toolkits/libxfce4gui" ]; then warn "you need USE_XFCE+=libgui"
	elif [ ${pkg} = "x11/libxfce4menu" ]; then warn "you need USE_XFCE+=libmenu"
	elif [ ${pkg} = "x11/libxfce4util" ]; then warn "you need USE_XFCE+=libutil"
	elif [ ${pkg} = "x11-wm/xfce4-panel" ]; then warn "you need USE_XFCE+=panel"
	elif [ ${pkg} = "x11-fm/thunar" ]; then warn "you need USE_XFCE+=thunar"
	elif [ ${pkg} = "x11/xfce4-conf" ]; then warn "you need USE_XFCE+=xfconf"
	# default
	elif expr ${lib_file} : "${LOCALBASE}/lib/[^/]*$" > /dev/null; then
		lib_file=${lib_file#${LOCALBASE}/lib/}
		lib_file=${lib_file%.so*}.so
		warn "you need LIB_DEPENDS+=${lib_file}:${pkg}"
	fi
}

proxydeps() {
	local file dep_file dep_file_pkg already rc

	rc=0

	# Check all dynamicaly linked ELF files
	# Some .so are not executable, but we want to check them too.
	while read -r file; do
		# No results presents a blank line from heredoc.
		[ -z "${file}" ] && continue
		while read -r dep_file; do
			# No results presents a blank line from heredoc.
			[ -z "${dep_file}" ] && continue
			# Skip files we already checked.
			if listcontains ${dep_file} "${already}"; then
				continue
			fi
			if pkg which -q ${dep_file} > /dev/null 2>&1; then
				dep_file_pkg=$(pkg which -qo ${dep_file})

				# Check that the .so we need has a SONAME
				if [ "${dep_file_pkg}" != "${PKGORIGIN}" ]; then
					if ! readelf -d "${dep_file}" | grep -q SONAME; then
						err "${file} is linked to ${dep_file} which does not have a SONAME.  ${dep_file_pkg} needs to be fixed."
					fi
				fi

				# If we don't already depend on it, and we don't provide it
				if ! listcontains ${dep_file_pkg} "${LIB_RUN_DEPENDS} ${PKGORIGIN}"; then
					# If the package has a flavor, check that the dependency is not on that particular flavor.
					flavor=$(pkg annotate -q -S "$(pkg which -q "${dep_file}")" flavor)
					if [ -n "${flavor}" ]; then
						if listcontains ${dep_file_pkg}@${flavor} "${LIB_RUN_DEPENDS} ${PKGORIGIN}"; then
							continue
						fi
					fi
					err "${file} is linked to ${dep_file} from ${dep_file_pkg} but it is not declared as a dependency"
					proxydeps_suggest_uses ${dep_file_pkg} ${dep_file}
					rc=1
				fi
			else
				err "${file} is linked to ${dep_file} that does not belong to any package"
				rc=1
			fi
			already="${already} ${dep_file}"
		done <<-EOT
		$(env LD_LIBMAP_DISABLE=1 ldd -a "${STAGEDIR}${file}" | \
			awk '
			BEGIN {section=0}
			/^\// {section++}
			!/^\// && section<=1 && ($3 ~ "^'${PREFIX}'" || $3 ~ "^'${LOCALBASE}'") {print $3}')
		EOT
	done <<-EOT
	$(list_stagedir_elfs | \
		file -F $'\1' -f - | \
		grep -a 'ELF.*FreeBSD.*dynamically linked' | \
		cut -f 1 -d $'\1'| \
		sed -e 's/^\.//')
	EOT

	[ -z "${PROXYDEPS_FATAL}" ] && return 0

	return ${rc}
}

sonames() {
	[ ! -d ${STAGEDIR}${PREFIX}/lib -o -n "${BUNDLE_LIBS}" ] && return 0
	while read -r f; do
		# No results presents a blank line from heredoc.
		[ -z "${f}" ] && continue
		# Ignore symlinks
		[ -f "${f}" -a ! -L "${f}" ] || continue
		if ! readelf -d ${f} | grep -q SONAME; then
			warn "${f} doesn't have a SONAME."
			warn "pkg(8) will not register it as being provided by the port."
			warn "If another port depend on it, pkg will not be able to know where it comes from."
			case "${f}" in
				${STAGEDIR}${PREFIX}/lib/*/*)
					warn "It is in a subdirectory, it may not be used in another port."
					;;
				*)
					warn "It is directly in ${PREFIX}/lib, it is probably used by other ports."
					;;
			esac
		fi
	# Use heredoc to avoid losing rc from find|while subshell
	done <<-EOT
	$(find ${STAGEDIR}${PREFIX}/lib -name '*.so.*')
	EOT
}

perlcore_port_module_mapping() {
	case "$1" in
		Net)
			echo "Net::Config"
			;;
		libwww)
			echo "LWP"
			;;
		*)
			echo "$1" | sed -e 's/-/::/g'
			;;
	esac
}

perlcore() {
	local portname version module gotsome
	[ -x "${LOCALBASE}/bin/corelist" ] || return 0
	for dep in ${UNIFIED_DEPENDS}; do
		portname=$(expr "${dep}" : ".*/p5-\(.*\)")
		if [ -n "${portname}" ]; then
			gotsome=1
			module=$(perlcore_port_module_mapping "${portname}")
			version=$(expr "${dep}" : ".*>=*\([^:<]*\)")

			while read -r l; do
				case "${l}" in
					*was\ not\ in\ CORE*)
						# This never was with Perl
						# CORE, so nothing to do here
						;;
					*and\ removed*)
						# This was in Perl CORE but has
						# been removed since.
						warn "${dep##*:} was in Perl CORE.  Check with \`corelist ${module} ${version}\` and \`corelist -a ${module}\` if it should be conditionally added depending on PERL_LEVEL"
						;;
					*deprecated*in*)
						# This is in Perl CORE but is
						# deprecated.
						warn "${dep##*:} is in Perl CORE but deprecated.  Check with \`corelist ${module} ${version}\` and \`corelist -a ${module}\` if the dependency is really needed or if it should be conditionally added depending on PERL_LEVEL"
						;;
					*was\ first\ released*)
						# This is in Perl CORE and is
						# maybe not needed.
						warn "${dep##*:} is present in Perl CORE.  Check with \`corelist ${module} ${version}\` and \`corelist -a ${module}\` if the dependency is really needed or if it should be conditionally added depending on PERL_LEVEL"
						;;
					*)
						err "This line is not handled: \"${l}\""
				esac
			done <<-EOT
			$(${LOCALBASE}/bin/corelist "${module}"|tail -1)
			EOT
		fi
	done
	if [ -n "${gotsome}" ] && ! pkg info -e devel/p5-Module-CoreList; then
		notice "You have some Perl modules as dependencies but you do not have devel/p5-Module-CoreList installed, the perlcore QA check gets better results when using it, especially with older Perl versions."
	fi
}

no_arch() {
	[ -z "$NO_ARCH" ] && return
	rc=0
	while read -r f; do
		[ -z "$f" ] && continue
		if [ -n "$NO_ARCH_IGNORE" ]; then
			skip=
			for blacklist in $NO_ARCH_IGNORE; do
				case $f in
					*$blacklist) skip=1; break;;
				esac
			done
			[ "$skip" ] && continue
		fi
		err "'${f#.}' is a architecture specific binary file and you have set NO_ARCH.  Either remove NO_ARCH or add '$(basename $f)' to NO_ARCH_IGNORE."
		rc=1
	done <<-EOF
	$(list_stagedir_elfs  \
		| file -F $'\1' -f - -N \
		| grep -aE 'ELF .* [LM]SB .*, .*, version [0-9]+ \(FreeBSD\)' \
		| cut -f 1 -d $'\1')
	EOF
	return $rc
}

gemdeps()
{
	rc=0
	if [ "${PKGBASE%%-*}" = "rubygem" ]; then
		# shellcheck disable=SC2153
		# In the heredoc, ${PORTNAME} comes from the environment, not
		# to be confused with ${portname}
		while read -r l; do
			if [ -n "${l}" ]; then
				name=${l%% *}
				vers=${l#* }
				while read -r v; do
					if ! while read -r p; do
						${LOCALBASE}/bin/ruby -e "puts 'OK' if Gem::Dependency.new('${name}','${v}').match?('${name}','${p}')"
					done | grep -qFx OK; then
						err RubyGem dependency ${name} ${v} is not satisfied.
						rc=1
					fi <<-EOF
					$(${LOCALBASE}/bin/gem list -e "${name}" \
						| sed "s|.*(\(.*\))|\1|" \
						| tr -d ' ' \
						| tr , '\n')
					EOF
				done <<-EOF
				$(while echo "${vers}" | grep -q '"'; do
					echo "${vers}" | cut -d '"' -f2
					vers=$(echo "${vers}"|cut -d '"' -f3-)
				done)
				EOF
			fi
		done <<-EOF
		$(grep -a 'add_runtime_dependency' ${STAGEDIR}${PREFIX}/lib/ruby/gems/*/specifications/${PORTNAME}-*.gemspec \
			| sed 's|.*<\(.*\)>.*\[\(.*\)\])|\1 \2|' \
			| sort -u)
		EOF
	fi
	return $rc
}

# If an non rubygem-port has a 'Gemfile' file
# it is checked with bundle to be sure
# all dependencies are satisfied.
# Without the check missing/wrong dependencies
# are just found when executing the application
gemfiledeps()
{
	# skip check if port does not use ruby at all
	if [ -z "$USE_RUBY" ]; then
		return 0
	fi
	
	# skip check if port is a rubygem-* one; they have no Gemfiles
	if [ "${PKGBASE%%-*}" = "rubygem" ]; then
		return 0
	fi
	
	# advise install of bundler if its not present for check
	if ! type bundle > /dev/null 2>&1; then
		notice "Please install sysutils/rubygem-bundler for additional Gemfile-checks"
		return 0
	fi
 
	# locate the Gemfile(s)
	while read -r f; do
	
		# no results presents a blank line from heredoc
		[ -z "$f" ] && continue
	
		# if there is no Gemfile everything is fine - stop here
		[ ! -f "$f" ] && return 0;

		# use bundle to check if Gemfile is satisfied
		# if bundle returns 1 the Gemfile is not satisfied
		# and so stage-qa isn't also
		if ! bundle check --dry-run --gemfile $f > /dev/null 2>&1; then
			warn "Dependencies defined in ${f} are not satisfied"
		fi
      
	done <<-EOF
		$(find ${STAGEDIR} -name Gemfile)
		EOF
	return 0
}

flavors()
{
	local rc pkgnames uniques
	rc=0
	if [ -n "${FLAVOR}" ]; then
		pkgnames=$(make -C "${CURDIR}" flavors-package-names|sort)
		uniques=$(echo "${pkgnames}"|uniq)
		if [ "$pkgnames" != "${uniques}" ]; then
			err "Package names are not unique with flavors:"
			make -C "${CURDIR}" pretty-flavors-package-names >&2
			err "maybe use <flavor>_PKGNAMEPREFIX/SUFFIX".
			rc=1
		fi
	fi
	return ${rc}
}

license()
{
	local lic autoaccept pkgmirror #distsell distmirror pkgsell

	if [ -n "$DISABLE_LICENSES" ]; then
		warn "You have disabled the licenses framework with DISABLE_LICENSES, unable to run checks"
	elif [ -n "$LICENSE" ]; then
		for lic in $LICENSE_PERMS; do
			case "$lic" in
				auto-accept) autoaccept=1 ;;
				#dist-mirror) distmirror=1 ;;
				#dist-sell)   distsell=1   ;;
				pkg-mirror)  pkgmirror=1  ;;
				#pkg-sell)    pkgsell=1    ;;
			esac
		done

		if [ -z "$autoaccept" ]; then
			warn "License is not auto-accepted, packages will not be built, ports depending on this one will be ignored."
		fi
		if [ -z "$pkgmirror" ]; then
			warn "License does not allow package to be distributed, ports depending on this one will be ignored"
		fi
	fi

	return 0
}

# This is to prevent adding dependencies to meta ports that are only there to
# improve the end user experience.
depends_blacklist()
{
	local dep rc instead

	rc=0

	for dep in ${UNIFIED_DEPENDS}; do
		origin=$(expr "${dep}" : ".*:\([^@]*\)")
		instead=""

		case "$origin" in
			lang/python|lang/python2|lang/python3)
				# lang/python depends on lang/pythonX, but it's
				# ok, it is also in the blacklist.
				if [ ${PKGORIGIN} != lang/python ]; then
					instead="USES=python:xy with a specific version"
				fi
				;;
			lang/gcc)
				instead="USE_GCC"
				;;
			lang/julia)
				instead="a dependency on lang/julia\${JULIA_DEFAULT:S/.//}"
				;;
			devel/llvm)
				instead="a dependency on devel/llvm\${LLVM_DEFAULT}"
				;;
			www/py-django)
				instead="one of the www/py-djangoXYZ port"
				;;
		esac

		if [ -n "${instead}" ]; then
			err "$origin should not be depended upon. Instead, use $instead."
			rc=1
		fi
	done

	return $rc
}

pkgmessage()
{
	for message in ${PKGMESSAGES}; do
		if [ -f "${message}" ]; then
			if ! head -1 "${message}" | grep -q '^\['; then
				warn "${message} not in UCL format, will be shown on initial install only."
				warn "See https://www.freebsd.org/doc/en/books/porters-handbook/pkg-files.html#porting-message"
			fi
		fi
	done

	return 0
}

reinplace()
{
	if [ -f ${REWARNFILE} ]; then
		warn "Possible REINPLACE_CMD issues:"
		cat ${REWARNFILE}
	fi
}

checks="shebang symlinks paths stripped desktopfileutils sharedmimeinfo"
checks="$checks suidfiles libtool libperl prefixvar baselibs terminfo"
checks="$checks proxydeps sonames perlcore no_arch gemdeps gemfiledeps flavors"
checks="$checks license depends_blacklist pkgmessage reinplace"

ret=0
cd ${STAGEDIR} || exit 1
for check in ${checks}; do
	eval check_test="\$IGNORE_QA_$check"
	if [ -z "${check_test}" ]; then
		${check} || ret=1
	else
		warn "Ignoring $check QA test"
	fi
done

exit ${ret}
