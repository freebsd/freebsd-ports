#! /bin/sh
# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org
#
# This script is used by poudriere and tinderbox(soon) as the source-of-truth for
# what should be considered a leftover and what is whitelisted.
#
# !!!! This script's input/output format must remain backwards-compatible.
# !!!! If you want to change it, create a new script and have the calling
# !!!! scripts use the new one if available.
#
# Usage: env PORTSDIR=... check_leftovers.sh category/port
# stdin:
#  - missing-file
#  + new-file
#  M modified-file reason...
#
# stdout:
#  same -/+/M format, but with files substituted, without approved
#  whitelisted files, and hides any directories already in plist.
#
# The PLIST_SUB feature can be disabled by setting PLIST_SUB_SED=
# in environment.

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_CHECK_LEFTOVERS}" ] && set -x

origin="$1"
[ $# -eq 1 ] || { echo "Must supply ORIGIN as parameter" >&2; exit 1; }
[ -n "${PORTSDIR}" ] || { echo "PORTSDIR must be set" >&2; exit 1; }

portdir="${PORTSDIR}/${origin}"

# PREFIX/LOCALBASE may be set in env or want default from port.
if [ -n "${PREFIX}" ]; then
	PORT_FLAGS="${PORT_FLAGS} PREFIX=${PREFIX}"
else
	PREFIX=$(make -C ${portdir} -VPREFIX)
fi
if [ -n "${LOCALBASE}" ]; then
	PORT_FLAGS="${PORT_FLAGS} LOCALBASE=${LOCALBASE}"
else
	LOCALBASE=$(make -C ${portdir} -VLOCALBASE)
fi
if [ -z "${CCACHE_DIR}" ]; then
	CCACHE_DIR=$(make -C ${portdir} -VCCACHE_DIR)
fi
homedirs=$(awk -F: -v users=$(make -C ${portdir} -V USERS|sed -e 's, ,|,g;/^$/d;s,^,^(,;s,$,)$,') 'users && $1 ~ users {print $9}' ${PORTSDIR}/UIDs|sort -u|sed -e "s|/usr/local|${PREFIX}|"|tr "\n" " ")
plistsub_sed=$(make -C ${portdir} -VPLIST_SUB_SED | /bin/sh ${PORTSDIR}/Mk/Scripts/plist_sub_sed_sort.sh)
tmpplist=$(make -C ${portdir} -VTMPPLIST)

while read modtype path extra; do
	# Ignore everything from these files/directories
	case "${path}" in
		${CCACHE_DIR}/*|\
		/compat/linux/proc/*|\
		/dev/*|\
		/etc/make.conf.bak|\
		/proc/*|\
		/tmp/*|\
		/var/db/pkg/*|\
		/var/db/ports/*|\
		/var/log/*|\
		/var/mail/*|\
		/var/run/*|\
		/var/tmp/*) continue ;;
		# fc-cache - skip for now
		/var/db/fontconfig/*) continue ;;
	esac

	ignore_path=0
	sub_path=$(echo "$path" | sed -e "s|^${PREFIX}/||" -e "${plistsub_sed}")
	orig_sub_path="${sub_path}"
	# If this is a directory, use @dir in output
	is_dir=0
	if [ -d "${path}" ]; then
		is_dir=1
		sub_path="@dir ${sub_path}"
	fi

	# Handle PORTDOCS/PORTEXAMPLES/etc
	case "${orig_sub_path}" in
		%%DOCSDIR%%*) sub_path="%%PORTDOCS%%${sub_path}" ;;
		%%EXAMPLESDIR%%*) sub_path="%%PORTEXAMPLES%%${sub_path}" ;;
	esac

	case $modtype in
	+)
		if [ ${is_dir} -eq 1 ]; then
			# home directory of users created
			case " ${homedirs} " in
			*\ ${path}\ *) continue ;;
			*\ ${path}/*\ *) continue ;;
			esac
			# Don't show dirs already in plist (due to parents)
			grep -qE \
			    "^@(unexec rmdir \"?(%D/|${PREFIX})?${path#${PREFIX}/}[ \"]|dir(rm|rmtry)? ${path#${PREFIX}/}\$)" \
			    ${tmpplist} && continue
		fi

		# Check absolute paths
		case "${path}" in
			# Leave qmail's queue dir alone to not cause lost mail
			# during upgrades, just as /var/mail is left alone.
			/var/qmail/queue/*|/var/qmail/queue) continue ;;
		esac

		# Check relative/plist paths
		case "${sub_path}" in
			# gconftool-2 --makefile-uninstall-rule is unpredictable
			etc/gconf/gconf.xml.defaults/%gconf-tree*.xml) ;;
			*) echo "+ ${sub_path}" ;;
		esac
		;;
	-)
		# Skip removal of PREFIX and PREFIX/info from
		# bsd.port.mk for now.
		# Skip if it is PREFIX and non-LOCALBASE. See misc/kdehier4
		# or mail/qmail for examples
		[ "${path}" = "${PREFIX}" -a "${LOCALBASE}" != "${PREFIX}" ] &&
		    ignore_path=1

		# The removal of info may be a bug; it's part of BSD.local.dist.
		# See ports/74691

		[ "${sub_path}" = "info" -a "${LOCALBASE}" != "${PREFIX}" ] &&
		    ignore_path=1

		[ $ignore_path -eq 0 ] && echo "- ${sub_path}"
		;;
	M)
		# Check relative/plist paths
		case "${sub_path}" in
			# gconftool-2 --makefile-uninstall-rule is unpredictable
			etc/gconf/gconf.xml.defaults/%gconf-tree*.xml) ;;
			# This is a cache file for gio modules could be modified
			# for any gio modules
			lib/gio/modules/giomodule.cache) ;;
			# removal of info files leaves entry uneasy to cleanup
			# in info/dir
			info/dir) ;;
			*/info/dir) ;;
			# The is pear database cache
			%%PEARDIR%%/.depdb|%%PEARDIR%%/.filemap) ;;
			#ls-R files from texmf are often regenerated
			*/ls-R) ;;
			# Octave packages database, blank lines can be inserted
			# between pre-install and post-deinstall
			share/octave/octave_packages) ;;
			# xmlcatmgr is constantly updating catalog.ports ignore
			# modification to that file
			share/xml/catalog.ports) ;;
			# Ignore common system config files
			/etc/group|\
			/etc/make.conf|\
			/etc/master.passwd|\
			/etc/passwd|\
			/etc/pwd.db|\
			/etc/shells|\
			/etc/spwd.db) ;;
			*) echo "M ${sub_path#@dir } ${extra}" ;;
		esac
		;;
	esac
done

exit 0
