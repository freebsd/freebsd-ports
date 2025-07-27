#!/bin/sh

CURDIR=`pwd`
WRKDIR=`pwd`/work
#mkdir -p "${WRKDIR}"

if [ \! -d "${CURDIR}/kicad-repo" ]; then
 git clone https://gitlab.com/kicad/code/kicad.git -b master "${CURDIR}/kicad-repo";
else
  cd "${CURDIR}/kicad-repo"
  git pull https://gitlab.com/kicad/code/kicad.git;
fi

cd "${CURDIR}/kicad-repo"
GIT_SRC_HASH=`git log -n 1 --pretty=format:"%H"`;
GIT_SRC_DATE=`git log -n 1 --date=iso-local -n 1 --pretty=format:"%cd" | \
    cut -c '1-19' | sed -e 's,-,,g' -e 's,:,,g' -e 's, ,,g'`
GIT_SRC_DATE2=`git log -n 1 --date=iso-local -n 1 --pretty=format:"%cd" --date=format-local:'%Y.%m.%d' | \
    cut -c '1-19' | sed -e 's,-,,g' -e 's,:,,g' -e 's, ,,g'`


echo "$GIT_SRC_HASH, $GIT_SRC_DATE"
echo "GIT_SRC_HASH=  ${GIT_SRC_HASH}"    > ${CURDIR}/Makefile.git_rev
echo "GIT_SRC_DATE=  ${GIT_SRC_DATE}"   >> ${CURDIR}/Makefile.git_rev
echo "GIT_SRC_DATE2=  ${GIT_SRC_DATE2}"   >> ${CURDIR}/Makefile.git_rev

