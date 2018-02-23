#!/bin/sh
#Script to update the ports-mgmt/trueos-ports-src port (for packaging the port tree itself)
portsdir=$1
if [ -z "${portsdir}" ] ; then
  echo "Missing ports dir input!!"
  echo "Usage: setup_trueos-ports-src.sh <ports_dir_root>"
  exit 1
fi

port="ports-mgmt/trueos-ports-src"

ghTag=`git log -n 1 . | grep '^commit ' | awk '{print $2}'`
verTag=$(date '+%Y%m%d%H%M')

if [ -z "${ghTag}" ] then
  #not a git repository - some other checkout of the sources
  exit 1
fi

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
find ${portsdir} | grep -v "${port}" | sort > ${portsdir}/${port}/pkg-plist
sed -i '' "s|${portsdir}/|/usr/ports/|g" ${portsdir}/${port}/pkg-plist
#need to remove the directories from this pkg-plist somehow (or get find to not list dirs)

#If everything is successful now - go ahead and activate the port in the categories Makefile

