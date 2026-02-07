#!/bin/sh

#GIT_SRC_HASH=`cd kicad-repo; git log -n 1 --pretty=format:"%H"`
#GIT_SRC_DATE=`cd kicad-repo; git log -n 1 --date=iso-local -n 1 --pretty=format:"%cd" | \
#        cut -c '1-19' | sed -e 's,-,,g' -e 's,:,,g' -e 's, ,,g'`

CURDIR=`pwd`
WRKDIR=`pwd`/work
#mkdir -p "${WRKDIR}"

if [ \! -d "${CURDIR}/kicad-symbols" ]; then
 git clone https://gitlab.com/kicad/libraries/kicad-symbols.git -b master "${CURDIR}/kicad-symbols";
else
  cd "${CURDIR}/kicad-symbols"
  git pull;
fi
cd "${CURDIR}/kicad-symbols"
GIT_SYM_HASH=`git log -n 1 --pretty=format:"%H"`;
GIT_SYM_DATE=`git log -n 1 --date=iso-local -n 1 --pretty=format:"%cd" | \
    cut -c '1-19' | sed -e 's,-,,g' -e 's,:,,g' -e 's, ,,g'`

echo "$GIT_SYM_HASH, $GIT_SYM_DATE"
echo "GIT_SYM_HASH=  ${GIT_SYM_HASH}"    > ${CURDIR}/Makefile.git_rev
echo "GIT_SYM_DATE=  ${GIT_SYM_DATE}"   >> ${CURDIR}/Makefile.git_rev

