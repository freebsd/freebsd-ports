#!/bin/sh

CURDIR=`pwd`
WRKDIR=`pwd`/work
#mkdir -p "${WRKDIR}"

if [ \! -d "${CURDIR}/kicad-repo" ]; then
 git clone https://github.com/mossmann/hackrf.git -b master "${CURDIR}/hackrf-repo";
else
  cd "${CURDIR}/hackrf-repo"
  git pull https://github.com/mossmann/hackrf.git;
fi

cd "${CURDIR}/hackrf-repo"
GIT_SRC_HASH=`git log -n 1 --pretty=format:"%H"`;
GIT_SRC_DATE=`git log -n 1 --date=iso-local -n 1 --pretty=format:"%cd" | \
    cut -c '1-10' | sed -e 's,-,.,g' `

echo "$GIT_SRC_HASH, $GIT_SRC_DATE"
echo "GIT_SRC_HASH=  ${GIT_SRC_HASH}"    > ${CURDIR}/Makefile.git_rev
echo "GIT_SRC_DATE=  ${GIT_SRC_DATE}"   >> ${CURDIR}/Makefile.git_rev

