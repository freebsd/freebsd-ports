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

shebang() {
	local IFS rc

	rc=0
	IFS="$LF"
	
	for f in `find ${STAGEDIR} -type f -perm +111`; do
		interp=$(sed -n -e '1s/^#![[:space:]]*\([^[:space:]]*\).*/\1/p;2q' $f)
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
	done

	return ${rc}
}

symlinks() {
	local rc

	rc=0

	while read l link; do
		[ -z "${l}" ] && continue
		case "${link}" in
			${STAGEDIR}*)
				err "Bad symlinks ${l} pointing inside the stage directory"
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
		err "${f} is referring to ${STAGEDIR}"
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
			ELF\ *,\ not\ stripped*) warn "${f} is not stripped consider using \${STRIP_CMD}" ;;
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
	if [ -z "${USESSHAREDMIMEINFO}" ]; then
		find ${STAGEDIR}${PREFIX}/share/mime/packages/*.xml ! -name "freedesktop\.org\.xml" -quit 2>/dev/null &&
		warn "you need USES=shared-mime-info"
	else
		find ${STAGEDIR}${PREFIX}/share/mime/packages/*.xml ! -name "freedesktop\.org\.xml" -quit 2>/dev/null ||
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
