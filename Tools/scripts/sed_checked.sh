#!/bin/sh

# Rationale:
# The ports tree has accumulated quite a bit of REINPLACE_CMD lines
# in its Makefile. Some of these have gone stale as ports were updated
# upstream, or as the ports have evolved.

# For DEVELOPERS, we check the effectiveness of REINPLACE_CMD lines
# by requesting backup files be written, and comparing them against
# source files.

set -eu

DEBUG=:
#DEBUG=echo

check_dash_i() {
    # this must be called from a subshell so as not to clobber $@
    # WARNING: assumes that -i is given at least once!
    unset OPTIND
    $DEBUG >&2 DEBUG: check_dash_i "$@"
    while getopts :EI:ae:f:i:lnru var ; do
	$DEBUG >&2 DEBUG: option "$var" '"'"${OPTARG-""}"'"'
	case "$var" in [iI])
	    last_i="$OPTARG"
	esac
    done

    $DEBUG >&2 DEBUG: last_i='"'"$last_i"'"'
    printf '"%s"\n' "$last_i"
}

shadowed="$( (check_dash_i -i.bak "$@") )"
if [ "$shadowed" != '".bak"' ] ; then
    echo >&2 "WARNING: $0 -i.bak clobbered by caller's backup suffix $shadowed"
fi

${SED-/usr/bin/sed} -i.bak "$@"
check() {
    issues=0
    files=0
    args=
    for x in "${@}" ; do
	# we decide very simply whether the argument we are looking at is
	# a sed command or a file: if it's not a regular file, it must be
	# a sed argument worth collecting for our warning message,
	# so that maintainers can identify the failing sed command.
	#
	# We cannot easily relate to Makefile lines here.
	if [ -f "${x}" ]; then
	    # File? Check if sed was effective.
	    files=$(($files + 1))
	    if cmp -s "${x}" "${x}".bak ; then
		issues=$(($issues + 1))
		if [ $issues -eq 1 ] ; then
		    echo "sed failed:${args} ..."
		fi
		echo "  - file content unchanged from backup: ${x#${WRKSRC}/}"
	    fi
	else
	    # Not a file? Collect sed(1) command.
	    args="${args} ${x}"
	fi
    done

    if [ ${issues} -gt 0 ] ; then
	action="review"
	if [ ${issues} -eq ${files} ] ; then
	    action=" FIX " # blanks at either end
	else
	    action="review"
	fi
	echo "--- issues found: ${issues}, files to edit: ${files}, please ${action} ---"
    fi
}

if [ ! -z "${REWARNFILE}" ] ; then
    check "$@" | tee -a ${REWARNFILE}
    # if ${REWARNFILE} is a regular file (not /dev/null) and empty, delete it.
    if [ -f "${REWARNFILE}" -a ! -s "${REWARNFILE}" ] ; then rm -f "${REWARNFILE}" ; fi
else
    check "$@"
fi

