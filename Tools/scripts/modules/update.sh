#!/bin/sh

# $FreeBSD$

cd /g/hubgnats/gnats-aa/modules

make clean
make

pl=`wc -l modules-ports | awk '{ print $1 }'`
ml=`wc -l modules | awk '{ print $1 }'`
diff=`expr $pl - $ml`
if [ $diff -lt 0 ]; then
	diff=`expr 0 - $diff`
fi
echo Difference is $diff lines.
if [ $diff -gt 50 ]; then
	date | mail -s "DIFF > $diff" edwin@FreeBSD.org
	exit
fi

make commit
