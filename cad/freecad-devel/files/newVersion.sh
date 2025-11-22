#!/bin/sh

CURDIR=`pwd`
WRKDIR=`pwd`/work
#mkdir -p "${WRKDIR}"

if [ \! -d "${CURDIR}/freecad-repo" ]; then
 git clone https://github.com/FreeCAD/FreeCAD -b main "${CURDIR}/freecad-repo";
else
  cd "${CURDIR}/freecad-repo"
  # git pull https://github.com/FreeCAD/FreeCAD;
  git pull
fi

cd "${CURDIR}/freecad-repo"
GIT_SRC_HASH=`git log -n 1 --pretty=format:"%H"`;
GIT_SRC_DATE=`git log -n 1 --date=iso-local -n 1 --pretty=format:"%cd" | \
    cut -c '1-19' | sed -e 's,-,,g' -e 's,:,,g' -e 's, ,,g'`
GIT_SRC_DATE2=`git log -n 1 --date=iso-local -n 1 --pretty=format:"%cd" --date=format-local:'%Y.%m.%d' | \
    cut -c '1-19' | sed -e 's,-,,g' -e 's,:,,g' -e 's, ,,g'`
GIT_ONDSEL_HASH=`git ls-tree HEAD src/3rdParty/OndselSolver/ | awk '{print $3}'`
GIT_GSL_HASH=`git ls-tree HEAD src/3rdParty/GSL/ | awk '{print $3}'`
GIT_GTEST_HASH=`git ls-tree HEAD tests/lib/ | awk '{print $3}'`
GIT_ADDONMGR_HASH=`git ls-tree HEAD src/Mod/AddonManager/ | awk '{print $3}'`

echo "$GIT_SRC_HASH, $GIT_SRC_DATE"
echo "GIT_SRC_HASH=  ${GIT_SRC_HASH}"    > ${CURDIR}/Makefile.git_rev
echo "GIT_SRC_DATE=  ${GIT_SRC_DATE}"   >> ${CURDIR}/Makefile.git_rev
echo "GIT_SRC_DATE2=  ${GIT_SRC_DATE2}"   >> ${CURDIR}/Makefile.git_rev
echo "GIT_ONDSEL_HASH= ${GIT_ONDSEL_HASH}"   >> ${CURDIR}/Makefile.git_rev
echo "GIT_GSL_HASH= ${GIT_GSL_HASH}"   >> ${CURDIR}/Makefile.git_rev
echo "GIT_GTEST_HASH= ${GIT_GTEST_HASH}"   >> ${CURDIR}/Makefile.git_rev
echo "GIT_ADDONMGR_HASH= ${GIT_ADDONMGR_HASH}"   >> ${CURDIR}/Makefile.git_rev
