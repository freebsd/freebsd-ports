#!/bin/sh
# $FreeBSD$

WRKDIRPREFIX=$1
LINUXBASE=$2

if [ "x${WRKDIRPREFIX}" = "x" -o "x${LINUXBASE}" = "x" ]; then
	exit 0
fi

LINUXWRKDIRPREFIX="${LINUXBASE}/${WRKDIRPREFIX}"

while [ "x${LINUXWRKDIRPREFIX}" != "x" ]; do
	if [ -L "${LINUXWRKDIRPREFIX}" -a \
	     x`ls -ld "${LINUXWRKDIRPREFIX}" 2>/dev/null | \
	       awk '/->/{print $NF;exit 0}END{exit 1}'` = \
	     x"${WRKDIRPREFIX}" ]; then
		echo "link"
		exit 1
	fi
	if [ -L "${LINUXWRKDIRPREFIX}" ]; then
		LINUXWRKDIRPREFIX=`ls -ld "${LINUXWRKDIRPREFIX}" 2>/dev/null | \
		                   awk '/->/{print $NF;exit 0}END{exit 1}'`
	else
		break
	fi
done

exit 0
