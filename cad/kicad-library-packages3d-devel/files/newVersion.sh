#!/bin/sh

#GIT_SRC_HASH=`cd kicad-repo; git log -n 1 --pretty=format:"%H"`
#GIT_SRC_DATE=`cd kicad-repo; git log -n 1 --date=iso-local -n 1 --pretty=format:"%cd" | \
#        cut -c '1-19' | sed -e 's,-,,g' -e 's,:,,g' -e 's, ,,g'`

CURDIR=`pwd`
WRKDIR=`pwd`/work
#mkdir -p "${WRKDIR}"

if [ \! -d "${CURDIR}/kicad-packages3D" ]; then
 git clone https://gitlab.com/kicad/libraries/kicad-packages3D.git -b master "${CURDIR}/kicad-packages3D";
else
  cd "${CURDIR}/kicad-packages3D"
  git pull;
fi
cd "${CURDIR}/kicad-packages3D"
GIT_P3D_HASH=`git log -n 1 --pretty=format:"%H"`;
GIT_P3D_DATE=`git log -n 1 --date=iso-local -n 1 --pretty=format:"%cd" | \
    cut -c '1-19' | sed -e 's,-,,g' -e 's,:,,g' -e 's, ,,g'`

echo "$GIT_P3D_HASH, $GIT_P3D_DATE"
echo "GIT_P3D_HASH=  ${GIT_P3D_HASH}"    > ${CURDIR}/Makefile.git_rev
echo "GIT_P3D_DATE=  ${GIT_P3D_DATE}"   >> ${CURDIR}/Makefile.git_rev

