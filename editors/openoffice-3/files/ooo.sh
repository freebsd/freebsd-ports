#!/bin/sh
# Openoffice.org build and uploader for FreeBSD.
# Nakata Maho (maho@FreeBSD.org) 2010/2/13.
# this file is public domain.
# $Id$

MILESTONE=`make -V OOOTAG`
fbsdmajor=`uname -r | sed 's/\..*$//g'`
fbsdarch=`uname -m`
OOODIR=/home/ftp/pub/OpenOffice.org/FreeBSD/packages-$fbsdmajor-$fbsdarch
SITE=build.good-day.net
USER=maho

#build
/usr/bin/time -h sudo -u $USER make WITH_CCACHE=yes >log.en.$MILESTONE 2>&1
/usr/bin/time -h make deinstall package package-rename >> log.en.$MILESTONE 2>&1
/usr/bin/time -h make sdk ure >> log.en.$MILESTONE 2>&1
/usr/bin/time -h make deinstall >> log.en.$MILESTONE 2>&1

/usr/bin/time -h make clean >log.ja.$MILESTONE 2>&1
/usr/bin/time -h sudo -u $USER make LOCALIZED_LANG=ja WITH_CCACHE=yes >log.ja.$MILESTONE 2>&1
/usr/bin/time -h make LOCALIZED_LANG=ja deinstall package package-rename languagepack >> log.ja.$MILESTONE 2>&1
/usr/bin/time -h make LOCALIZED_LANG=ja deinstall >> log.ja.$MILESTONE 2>&1

OOOENUSPACKAGE1=`ls openoffice.org*tbz`
OOOENUSPACKAGE2=`ls OOo*install_en-US.tbz`
OOOJAPACKAGE1=`ls ja-openoffice.org*tbz`
OOOJAPACKAGE2=`ls OOo*install_ja.tbz`

#upload
bzip2 log.en.$MILESTONE log.ja.$MILESTONE
sudo -u $USER ssh $SITE mkdir $OOODIR
sudo -u $USER scp *openoffice*.tbz *SDK* *URE* log.* $SITE:$OOODIR 

if [ x$OOOENUSPACKAGE1 != x"" ]; then
sudo -u $USER ssh $SITE "ln -sf $OOODIR/$OOOENUSPACKAGE1 $OOODIR/$OOOENUSPACKAGE2"
fi
if [ x$OOOJAPACKAGE1 != x"" ]; then
sudo -u $USER ssh $SITE "ln -sf $OOODIR/$OOOJAPACKAGE1   $OOODIR/$OOOJAPACKAGE2"
fi



