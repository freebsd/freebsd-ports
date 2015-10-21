#!/bin/sh
# MAINTAINER: portmgr@FreeBSD.org
# $FreeBSD$

if [ -z "${STAGEDIR}" -o -z "${PREFIX}" -o -z "${LOCALBASE}" ]; then
	echo "STAGEDIR, PREFIX, LOCALBASE required in environment." >&2
	exit 1
fi

LF=$(printf '\nX')
LF=${LF%X}

warn() {
	echo "Warning: $@" >&2
}

err() {
	echo "Error: $@" >&2
}

shebangonefile() {
	local f interp rc

	f="$@"
	rc=0

	# blacklist of files which are not intended to be runnable
	case "${f##*/}" in
	*.pm|*.pod|*.txt)
		return 0
		;;
	esac

	interp=$(sed -n -e '1s/^#![[:space:]]*\([^[:space:]]*\).*/\1/p;2q' "$f")
	case "$interp" in
	"") ;;
	${LINUXBASE}/*) ;;
	${LOCALBASE}/*) ;;
	${PREFIX}/*) ;;
	/bin/csh) ;;
	/bin/sh) ;;
	/bin/tcsh) ;;
	/usr/bin/awk) ;;
	/usr/bin/env) ;;
	/usr/bin/nawk) ;;
	/usr/bin/sed) ;;
	/usr/sbin/dtrace) ;;
	*)
		err "'${interp}' is an invalid shebang you need USES=shebangfix for '${f#${STAGEDIR}${PREFIX}/}'"
		rc=1
		;;
	esac

	return ${rc}
}

shebang() {
	local f l link rc

	rc=0
	
	while read f; do
		# No results presents a blank line from heredoc.
		[ -z "${f}" ] && continue
		shebangonefile "${f}" || rc=1
	# Use heredoc to avoid losing rc from find|while subshell
	done <<-EOF
	$(find ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/sbin \
	    ${STAGEDIR}${PREFIX}/libexec ${STAGEDIR}${PREFIX}/www \
	    -type f -perm +111 2>/dev/null)
	EOF

	# Split stat(1) result into 2 lines and read each line separately to
	# retain spaces in filenames.
	while read l; do
		# No results presents a blank line
		[ -z "${l}" ] && continue
		read link

		case "${link}" in
		/*) f="${STAGEDIR}${link}" ;;
		*) f="${l%/*}/${link}" ;;
		esac
		if [ -f "${f}" ]; then
			shebangonefile "${f}" || rc=1
		fi
	# Use heredoc to avoid losing rc from find|while subshell
	done <<-EOF
	$(find ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/sbin \
	    ${STAGEDIR}${PREFIX}/libexec ${STAGEDIR}${PREFIX}/www \
	    -type l -exec stat -f "%N${LF}%Y" {} + 2>/dev/null)
	EOF

	return ${rc}
}

baselibs() {
	local rc
	[ "${PKGBASE}" = "pkg" -o "${PKGBASE}" = "pkg-devel" ] && return
	while read f; do
		case ${f} in
		*NEEDED*\[libarchive.so.[56]])
			err "Bad linking on ${f##* } please add USES=libarchive"
			rc=1
			;;
		*NEEDED*\[libedit.so.7])
			err "Bad linking on ${f##* } please add USES=libedit"
			rc=1
			;;
		esac
	done <<-EOF
	$(find ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/sbin \
		${STAGEDIR}${PREFIX}/lib ${STAGEDIR}${PREFIX}/libexec \
		-type f -exec readelf -d {} + 2>/dev/null)
	EOF
	return ${rc}
}

symlinks() {
	local rc

	rc=0

	# Split stat(1) result into 2 lines and read each line separately to
	# retain spaces in filenames.
	while read l; do
		# No results presents a blank line from heredoc.
		[ -z "${l}" ] && continue
		read link
		case "${link}" in
			${STAGEDIR}*)
				err "Bad symlink '${l#${STAGEDIR}${PREFIX}/}' pointing inside the stage directory"
				rc=1
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

	while read f; do
		# No results presents a blank line from heredoc.
		[ -z "${f}" ] && continue
		# Ignore false-positive/harmless files
		case "${f}" in
			*/lib/ruby/gems/*/Makefile) continue ;;
			*/lib/ruby/gems/*/Makefile.html) continue ;;
			*/lib/ruby/gems/*/mkmf.log) continue ;;
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
	find ${STAGEDIR} -type f ! -name '*.a' \
	    -exec readelf -S {} + 2>/dev/null | awk '\
	    /File:/ {sub(/File: /, "", $0); file=$0} \
	    /SYMTAB/ {print file}' |
	    while read f; do
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

	filelist=`find ${STAGEDIR} -type f \
		\( -perm -u+x -or -perm -g+x -or -perm -o+x \) \
		\( -perm -u+s -or -perm -g+s \)`
	if [ -n "${filelist}" ]; then
		warn "setuid files in the stage directory (are these necessary?):"
		ls -liTd ${filelist}
	fi
	return 0
}

libtool() {
	if [ -z "${USESLIBTOOL}" ]; then
		find ${STAGEDIR} -name '*.la' | while read f; do
			grep -q 'libtool library' "${f}" &&
				err ".la libraries found, port needs USES=libtool" &&
				return 1 || true
		done
		# The return above continues here.
	fi
}

libperl() {
	local has_some_libperl_so files found
	if [ -n "${SITE_ARCH_REL}" -a -d "${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}" ]; then
		has_some_libperl_so=0
		files=0
		while read f; do
			# No results presents a blank line from heredoc.
			[ -z "${f}" ] && continue
			files=$((files+1))
			found=`readelf -d $f | awk "BEGIN {libperl=1; rpath=10; runpath=100}
				/NEEDED.*${LIBPERL}/  { libperl = 0 }
				/RPATH.*perl.*CORE/   { rpath   = 0 }
				/RUNPATH.*perl.*CORE/ { runpath = 0 }
				END {print libperl+rpath+runpath}
				"`
			# FIXME When 8.4 goes out of commission, replace the ;;
			# with ;& in the case below.  Also, change the logic on
			# detecting if there was a file with libperl.so
			if [ "$found" -ne "0" ]; then
				case "$found" in
					*1)
						warn "${f} is not linked with ${LIBPERL}, not respecting lddlflags?"
						;; #;&
					*1?)
						has_some_libperl_so=1
						warn "${f} does not have a rpath to ${LIBPERL}, not respecting lddlflags?"
						;; #;&
					1??)
						has_some_libperl_so=1
						warn "${f} does not have a runpath to ${LIBPERL}, not respecting lddlflags?"
						;; #;&
				esac
			else
				has_some_libperl_so=1
			fi
		# Use heredoc to avoid losing rc from find|while subshell
		done <<-EOT
		$(find ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL} -name '*.so')
		EOT

		if [ $files -gt 0 -a $has_some_libperl_so -eq 0 ]; then
			err "None of the .so in ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL} are linked with ${LIBPERL}, see above for the full list."
			return 1
		else
			return 0
		fi
	fi
}

prefixvar() {
	if test -d ${STAGEDIR}${PREFIX}/var; then
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

checks="shebang symlinks paths stripped desktopfileutils sharedmimeinfo suidfiles libtool libperl prefixvar baselibs terminfo"

ret=0
cd ${STAGEDIR}
for check in ${checks}; do
	${check} || ret=1
done

exit $ret
