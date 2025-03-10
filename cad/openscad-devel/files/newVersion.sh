#!/bin/sh

CURDIR=`pwd`
WRKDIR=`pwd`/work
#mkdir -p "${WRKDIR}"

if [ \! -d "${CURDIR}/openscad-repo" ]; then
 git clone https://github.com/openscad/openscad -b master "${CURDIR}/openscad-repo";
else
  cd "${CURDIR}/openscad-repo"
  git pull https://github.com/openscad/openscad;
fi

cd "${CURDIR}/openscad-repo"
GIT_SRC_HASH=`git log -n 1 --pretty=format:"%H"`;
GIT_SRC_DATE=`git log -n 1 --date=iso-local -n 1 --pretty=format:"%cd" --date=format-local:'%Y.%m.%d' | \
    cut -c '1-19' | sed -e 's,-,,g' -e 's,:,,g' -e 's, ,,g'`
GIT_MCAD_HASH=`git ls-tree HEAD libraries/MCAD/ | awk '{print $3}'`
GIT_CLIPPER2_HASH=`git ls-tree HEAD submodules/Clipper2/ | awk '{print $3}'`
GIT_OPENCSG_HASH=`git ls-tree HEAD submodules/OpenCSG/ | awk '{print $3}'`
GIT_MANIFOLD_HASH=`git ls-tree HEAD submodules/manifold/ | awk '{print $3}'`
GIT_MIMALLOC_HASH=`git ls-tree HEAD submodules/mimalloc/ | awk '{print $3}'`
GIT_SANITIZERSCMAKE_HASH=`git ls-tree HEAD submodules/sanitizers-cmake/ | awk '{print $3}'`

echo "$GIT_SRC_HASH, $GIT_SRC_DATE"
echo "GIT_SRC_HASH=  ${GIT_SRC_HASH}"    > ${CURDIR}/Makefile.git_rev
echo "GIT_SRC_DATE=  ${GIT_SRC_DATE}"   >> ${CURDIR}/Makefile.git_rev
echo "GIT_MCAD_HASH= ${GIT_MCAD_HASH}"   >> ${CURDIR}/Makefile.git_rev
echo "GIT_CLIPPER2_HASH= ${GIT_CLIPPER2_HASH}"   >> ${CURDIR}/Makefile.git_rev
echo "GIT_OPENCSG_HASH= ${GIT_OPENCSG_HASH}"   >> ${CURDIR}/Makefile.git_rev
echo "GIT_MANIFOLD_HASH= ${GIT_MANIFOLD_HASH}"   >> ${CURDIR}/Makefile.git_rev
echo "GIT_MIMALLOC_HASH= ${GIT_MIMALLOC_HASH}"   >> ${CURDIR}/Makefile.git_rev
echo "GIT_SANITIZERSCMAKE_HASH= ${GIT_SANITIZERSCMAKE_HASH}"   >> ${CURDIR}/Makefile.git_rev

