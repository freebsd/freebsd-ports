#!/bin/sh
#Script to update the ports-mgmt/trueos-ports-src port (for packaging the port tree itself)
portsdir=$1
if [ -z "${portsdir}" ] ; then
  echo "Missing ports dir input!!"
  echo "Usage: setup_trueos-ports-src.sh <ports_dir_root>"
  exit 1
fi

port="ports-mgmt/trueos-ports-src"
origportdir="${portsdir}/Tools/trueos-ports-src"

ghTag=`git log -n 1 . | grep '^commit ' | awk '{print $2}'`
verTag=$(date '+%Y%m%d%H%M')

if [ -z "${ghTag}" ] ; then
  #not a git repository - some other checkout of the sources
  exit 1
fi

if [ -d "${portsdir}/${port}" ] ; then
  rm -r "${portsdir}/${port}"
fi
#Copy the port files over
cp -R "${origportdir}" "${portsdir}/${port}"

# Set the version numbers
sed -i '' "s|%%CHGVERSION%%|${verTag}|g" ${portsdir}/${port}/Makefile
sed -i '' "s|%%GHTAG%%|${ghTag}|g" ${portsdir}/${port}/Makefile

origdir=`pwd`
#Generate the distinfo
cd ${portsdir}/${port}
make makesum
if [ ! $? ] ; then
  echo "Unable to fetch ports repository distfile";
  exit 1
fi

#generate the pkg-plist
# Files
find ${portsdir} ! -type d ! -ipath "*/work/*" ! -ipath "*/.git*" ! -ipath "*/${port}/*"  ! -ipath "*/distfiles/*"| sort > ${portsdir}/${port}/pkg-plist
sed -i '' "s|${portsdir}/|/usr/ports/|g" ${portsdir}/${port}/pkg-plist
#Directories
find ${portsdir} -type d > ${portsdir}/${port}/pkg-plist.dirs
sed -i '' "s|${portsdir}/|@dir /usr/ports/|g" ${portsdir}/${port}/pkg-plist.dirs
cat "${portsdir}/${port}/pkg-plist.dirs" >> "${portsdir}/${port}/pkg-plist"
rm "${portsdir}/${port}/pkg-plist.dirs" #remove the temporary file

#If everything is successful now - go ahead and activate the port in the categories Makefile
cd ${portsdir}/ports-mgmt
comment="`cat Makefile | grep 'COMMENT ='`"
  echo "# \$FreeBSD\$
#

$comment
" > Makefile.tmp

  for d in `ls`
  do
    if [ "$d" = ".." ]; then continue ; fi
    if [ "$d" = "." ]; then continue ; fi
    if [ "$d" = "Makefile" ]; then continue ; fi
    if [ ! -f "$d/Makefile" ]; then continue ; fi
    echo "    SUBDIR += $d" >> Makefile.tmp
  done
  echo "" >> Makefile.tmp
  echo ".include <bsd.port.subdir.mk>" >> Makefile.tmp
  mv Makefile.tmp ${portsdir}/ports-mgmt/Makefile


#Now return back to the origin directory (just in case)
cd ${origdir}
