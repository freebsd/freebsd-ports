#!/bin/sh
# $FreeBSD$

LDMUD_USER=mud
LDMUD=%%PREFIX%%/sbin/ldmud
LDMUD_LOG=%%LOGDIR%%/ldmud.log
LDMUD_PID=/var/run/ldmud.pid

case "$1" in
	start)
		if [ -x "${LDMUD}" ]; then
			su ${LDMUD_USER} -c "${LDMUD}" >> "${LDMUD_LOG}" 2>&1 &
			echo $(($!+1)) > "${LDMUD_PID}"
			echo -n ' ldmud'
		fi
		;;
	stop)
		kill -TERM `cat "${LDMUD_PID}"` && rm -f "${LDMUD_PID}"
		;;
	*)
		echo ""
		echo "Usage: `basename $0` { start | stop }"
		echo ""
		exit 64
		;;
esac
