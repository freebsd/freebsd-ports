#!/bin/sh
# $FreeBSD: /tmp/pcvs/ports/java/jdk12/scripts/Attic/check_wrkdir_links.sh,v 1.1 2003-08-23 15:17:29 glewis Exp $

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
