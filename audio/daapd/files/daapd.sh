#!/bin/sh
# $FreeBSD$

DAAPD_USER=%%USER%%
DAAPD=%%PREFIX%%/sbin/daapd
DAAPD_LOG=%%LOGDIR%%/daapd.log
DAAPD_PID=/var/run/daapd.pid
DAAPD_CONF=%%PREFIX%%/etc/daapd.conf

case "$1" in
	start)
		if [ -r "${DAAPD_CONF}" ]; then
			su -m ${DAAPD_USER} -c "${DAAPD} -c ${DAAPD_CONF}" \
				>> ${DAAPD_LOG} 2>&1 &
			echo $(($!+1)) > "${DAAPD_PID}"
			echo -n ' daapd'
		fi
		;;
	stop)
		kill -TERM `cat "${DAAPD_PID}"` && rm -f "${DAAPD_PID}"
		;;
	*)
		echo ""
		echo "Usage: `basename $0` { start | stop }"
		echo ""
		exit 64
		;;
esac
