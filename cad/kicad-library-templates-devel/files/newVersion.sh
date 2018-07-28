#!/bin/sh

#GIT_SRC_HASH=`cd kicad-repo; git log -n 1 --pretty=format:"%H"`
#GIT_SRC_DATE=`cd kicad-repo; git log -n 1 --date=iso-local -n 1 --pretty=format:"%cd" | \
#        cut -c '1-19' | sed -e 's,-,,g' -e 's,:,,g' -e 's, ,,g'`

CURDIR=`pwd`
WRKDIR=`pwd`/work
#mkdir -p "${WRKDIR}"

if [ \! -d "${CURDIR}/kicad-templates" ]; then
 git clone https://github.com/KiCad/kicad-templates.git -b master "${CURDIR}/kicad-templates";
else
  cd "${CURDIR}/kicad-templates"
  git pull;
fi
cd "${CURDIR}/kicad-templates"
GIT_TMPL_HASH=`git log -n 1 --pretty=format:"%H"`;
GIT_TMPL_DATE=`git log -n 1 --date=iso-local -n 1 --pretty=format:"%cd" | \
    cut -c '1-19' | sed -e 's,-,,g' -e 's,:,,g' -e 's, ,,g'`

echo "$GIT_TMPL_HASH, $GIT_TMPL_DATE"
echo "GIT_TMPL_HASH=  ${GIT_TMPL_HASH}"    > ${CURDIR}/Makefile.git_rev
echo "GIT_TMPL_DATE=  ${GIT_TMPL_DATE}"   >> ${CURDIR}/Makefile.git_rev

