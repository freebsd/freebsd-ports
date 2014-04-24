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
	interp=$(sed -n -e '1s/^#![[:space:]]*\([^[:space:]]*\).*/\1/p;2q' "$f")
	case "$interp" in
	"") ;;
	/usr/bin/env) ;;
	${LOCALBASE}/*) ;;
	${PREFIX}/*) ;;
	/usr/bin/awk) ;;
	/usr/bin/sed) ;;
	/usr/bin/nawk) ;;
	/bin/csh) ;;
	/bin/sh) ;;
	*)
		err "${interp} is an invalid shebang you need USES=shebangfix for ${f#${STAGEDIR}${PREFIX}/}"
		rc=1
		;;
	esac

	return ${rc}
}

shebang() {
	local f l link rc

	rc=0
	
	while read f; do
		[ -z "${f}" ] && continue
		shebangonefile "${f}" || rc=1
	# Use heredoc to avoid losing rc from find|while subshell
	done << EOF
$(find ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/sbin ${STAGEDIR}${PREFIX}/libexec -type f -perm +111 2>/dev/null)
EOF
	while read l link; do
		[ -z "${l}" ] && continue
		case "${link}" in
		/*) f="${STAGEDIR}${link}" ;;
		*) f="${l%/*}/${link}" ;;
		esac
		if [ -f "${f}" ]; then
			shebangonefile "${f}" || rc=1
		fi
	# Use heredoc to avoid losing rc from find|while subshell
	done << EOF
$(find ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/sbin ${STAGEDIR}${PREFIX}/libexec -type l -exec stat -f "%N %Y" {} + 2>/dev/null)
EOF

	return ${rc}
}

symlinks() {
	local rc

	rc=0

	while read l link; do
		[ -z "${l}" ] && continue
		case "${link}" in
			${STAGEDIR}*)
				err "Bad symlinks ${l#${STAGEDIR}${PREFIX}/} pointing inside the stage directory"
				rc=1
				;;
		esac
	# Use heredoc to avoid losing rc from find|while subshell
	done << EOF
$(find ${STAGEDIR} -type l -exec stat -f "%N %Y" {} +)
EOF

	return ${rc}
}

paths() {
	local rc

	rc=0

	while read f; do
		[ -z "${f}" ] && continue
		# Ignore false-positive/harmless files
		case "${f}" in
			*/lib/ruby/gems/*/Makefile) continue ;;
			*/lib/ruby/gems/*/Makefile.html) continue ;;
			*/lib/ruby/gems/*/mkmf.log) continue ;;
		esac
		err "${f#${STAGEDIR}${PREFIX}/} is referring to ${STAGEDIR}"
		rc=1
	# Use heredoc to avoid losing rc from find|while subshell
	done << EOF
$(find ${STAGEDIR} -type f -exec grep -l "${STAGEDIR}" {} +)
EOF

	return ${rc}
}

# For now do not raise an error, just warnings
stripped() {
	[ -x /usr/bin/file ] || return # this is fatal
	[ -n "${STRIP}" ] || return 0
	find ${STAGEDIR} -type f -exec /usr/bin/file -nNF '' {} + | while
	    read f output; do
		case "${output}" in
			ELF\ *\ executable,\ *FreeBSD*,\ not\ stripped*|ELF\ *\ shared\ object,\ *FreeBSD*,\ not\ stripped*)
				warn "${f#${STAGEDIR}${PREFIX}/} is not stripped consider using \${STRIP_CMD}"
				;;
		esac
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

checks="shebang symlinks paths stripped desktopfileutils sharedmimeinfo suidfiles"

ret=0
cd ${STAGEDIR}
for check in ${checks}; do
	${check} || ret=1
done

exit $ret
