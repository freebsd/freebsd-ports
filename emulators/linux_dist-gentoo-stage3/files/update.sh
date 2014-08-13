#!/bin/sh

#
# This script is used for port development. Do not manually run it.
#
cd ${GENTOODIR}
wget -q ftp://ftp.dei.uc.pt/pub/linux/gentoo/releases/x86/autobuilds/current-stage3-i486/ >/dev/null
NEWVER=$(grep -o '\".*current-stage3.*"' index.html | grep 'stage3-i486-.*bz2"' | sed -e "s|.*/||g" | grep -o "2014[0-9]*")
OLDVER=$(make -V PORTVERSION)
#rm index.html

if [ ${NEWVER} -gt ${OLDVER} ]; then
	sed -i '' "s|${OLDVER}|${NEWVER}|g" Makefile
	make update-port
else
	echo "Port is up-to-date."
fi
