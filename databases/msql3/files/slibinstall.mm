#!/bin/sh

. $MACRO_DIR/makegen/makegen.cf

maj=$1
src=$2
destd=$3
mode=$4
owner=$5
group=$6

echo	"install ::"
echo	"	cp $src.$maj $destd/$src.$maj"
echo	"	ln -sf $src.$maj $destd/$src"
if test "$mode." != "."
then
	echo	"	$chmod $mode $destd/$src.$maj"
fi
if test "$owner." = "root."
then
	echo	"	$chown $owner $destd/$src.$maj"
fi
if test "$group." != "."
then
	echo	"	$chgrp $group $destd/$src.$maj"
fi
echo
