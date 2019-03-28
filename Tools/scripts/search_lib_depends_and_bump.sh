#!/bin/sh
#
# You pass the script a port where the library has changed its ABI.
# The script will search for this port over the complete directory you are located now
# and will bump all ports using `Tools/scripts/bump-revision.sh`
#
# Version 0.1
# License: MIT
# Matthias Fechner <mfechner@FreeBSD.org>

usage() {
	echo "$0 devel/libgit2"
	echo ""
	echo "Search for all ports having devel/libgit2 as a LIB_DEPENDS"
	echo "and bump the REVISION using the script 'Tools/scripts/bump-revision.sh'"
	echo "After this check all modified ports with portlint."
	echo ""
	echo "Make sure you execute the script in the ports directory."
	exit 1
}

[ "${1}" != "" ] || usage

# check that portlint is available
if [ x`which portlint` = x"" ]; then
	echo "Please install portlint with"
	echo "pkg install portlint"
	echo "to continue."
	exit 1;
fi

PORT_TO_SEARCH=${1}
BASEDIR=$(pwd)
# Get a list of all ports
echo "Prepare a list of all ports"
ports=$(find . -name Makefile -path "./editors/*" ! -path "./Tools/* | sort")
echo "done."
echo

PORTS_TO_BUMP=""
echo Check ports with dependency to ${PORT_TO_SEARCH}
for port in ${ports}; do
	DIR=$(dirname "${port}")
	printf "Analyse ${DIR}"
	LIBDEPENDS=$(make -n -V LIB_DEPENDS -C ${DIR})
	#echo "Search >${PORT_TO_SEARCH}< in >${LIBDEPENDS}<"
	case "${LIBDEPENDS}" in
		*"${PORT_TO_SEARCH}"*)
			PORTS_TO_BUMP="${PORTS_TO_BUMP} ${DIR}";;
	esac
	printf "\033[2K\r"
done
echo "done."

echo "Bump PORTREVISION of following ports:"
for PORT_TO_BUMP in ${PORTS_TO_BUMP}; do
	echo ${PORT_TO_BUMP}
done
echo
read -p "Press CTRL+c to stop or ENTER to continue..." USERINPUT

for PORT_TO_BUMP in ${PORTS_TO_BUMP}; do
	sh ./Tools/scripts/bump-revision.sh ${PORT_TO_BUMP}
done

# Now we run portlint on all port we modified
# I borrowed here code from doportlint
echo
TMPFILE=$(mktemp)
while [ "1" = "1" ]
do
	FAILED_PORTS=""
	FAILURES=0
	echo "Use TMP file ${TMPFILE}"
	for PORT in ${PORTS_TO_BUMP}; do
		FAILURE=0
		echo "Running portlint in ${PORT}"
		cd ${PORT}
		portlint > ${TMPFILE} 2> /dev/null || FAILURE=1
		grep '^looks fine\.$' ${TMPFILE} > /dev/null 2> /dev/null || FAILURE=1
		
		if [ x${FAILURE} = "x1" ]; then
			FAILURES=$((${FAILURES}+1))
			FAILED_PORTS="${FAILED_PORTS} ${PORT}"
			{ echo '--------------- portlint failed for '${PORT}; \
			grep -v '^OK:' ${TMPFILE} |\
			sed -e 's/^0 fatal errors and //'; }
			echo ""
		fi
		rm -f ${TMPFILE}
		cd ${BASEDIR}
	done
	if [ x${FAILURES} = "x0" ]; then
		echo "All portlint test successfull, please review the changes before you commit them carefully."
		echo "You maybe want to run now"
		echo "git diff"
		echo "svn diff"
		echo
		break;
	fi
	PORTS_TO_BUMP=${FAILED_PORTS}
	read -p "${FAILURES} failures, please fix portlint error and warnings and press ENTER to retest" USERINPUT
	echo
	echo
	echo "------------------------------------ NEW Portlint -----------------------------"
done

