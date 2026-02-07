#!/bin/sh

#GIT_SRC_HASH=`cd kicad-repo; git log -n 1 --pretty=format:"%H"`
#GIT_SRC_DATE=`cd kicad-repo; git log -n 1 --date=iso-local -n 1 --pretty=format:"%cd" | \
#        cut -c '1-19' | sed -e 's,-,,g' -e 's,:,,g' -e 's, ,,g'`

CURDIR=`pwd`
WRKDIR=`pwd`/work
#mkdir -p "${WRKDIR}"

if [ \! -d "${CURDIR}/kicad-footprints" ]; then
 git clone https://gitlab.com/kicad/libraries/kicad-footprints.git -b master "${CURDIR}/kicad-footprints";
else
  cd "${CURDIR}/kicad-footprints"
  git pull;
fi
cd "${CURDIR}/kicad-footprints"
GIT_FP_HASH=`git log -n 1 --pretty=format:"%H"`;
GIT_FP_DATE=`git log -n 1 --date=iso-local -n 1 --pretty=format:"%cd" | \
    cut -c '1-19' | sed -e 's,-,,g' -e 's,:,,g' -e 's, ,,g'`

echo "$GIT_FP_HASH, $GIT_FP_DATE"
echo "GIT_FP_HASH=  ${GIT_FP_HASH}"    > ${CURDIR}/Makefile.git_rev
echo "GIT_FP_DATE=  ${GIT_FP_DATE}"   >> ${CURDIR}/Makefile.git_rev

