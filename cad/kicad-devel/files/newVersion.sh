#!/bin/sh

#GIT_SRC_HASH=`cd kicad-repo; git log -n 1 --pretty=format:"%H"`
#GIT_SRC_DATE=`cd kicad-repo; git log -n 1 --date=iso-local -n 1 --pretty=format:"%cd" | \
#        cut -c '1-19' | sed -e 's,-,,g' -e 's,:,,g' -e 's, ,,g'`

CURDIR=`pwd`
WRKDIR=`pwd`/work
#mkdir -p "${WRKDIR}"

#if [ \! -d "${CURDIR}/kicad-library" ]; then
# git clone https://github.com/KiCad/kicad-library.git -b master "${CURDIR}/kicad-library";
#else
#  cd "${CURDIR}/kicad-library"
#  git pull;
#fi

if [ \! -d "${CURDIR}/kicad-repo" ]; then
 git clone https://github.com/KiCad/kicad-source-mirror.git -b master "${CURDIR}/kicad-repo";
else
  cd "${CURDIR}/kicad-repo"
  git pull https://github.com/KiCad/kicad-source-mirror.git;
fi

cd "${CURDIR}/kicad-repo"
GIT_SRC_HASH=`git log -n 1 --pretty=format:"%H"`;
GIT_SRC_DATE=`git log -n 1 --date=iso-local -n 1 --pretty=format:"%cd" | \
    cut -c '1-19' | sed -e 's,-,,g' -e 's,:,,g' -e 's, ,,g'`

echo "$GIT_SRC_HASH, $GIT_SRC_DATE"
echo "GIT_SRC_HASH=  ${GIT_SRC_HASH}"    > ${CURDIR}/Makefile.git_rev
echo "GIT_SRC_DATE=  ${GIT_SRC_DATE}"   >> ${CURDIR}/Makefile.git_rev

#mkdir -p "${WRKDIR}/kicad-library-master"
#mkdir -p "${WRKDIR}/kicad-r${GIT_SRC_DATE}"
#cd "${CURDIR}/kicad-repo"
#find . -type d -name .git -prune -o -print | cpio -pdamuv "${WRKDIR}/kicad-r${GIT_SRC_DATE}";
#cd "${CURDIR}/kicad-library"
#find . -type d -name .git -prune -o -print | cpio -pdamuv "${WRKDIR}/kicad-library-master"
#cd "${WRKDIR}"
#tar cvfy /usr/ports/distfiles/kicad/kicad-r${GIT_SRC_DATE}.tar.bz2 \
#  kicad-r${GIT_SRC_DATE} kicad-library-master
