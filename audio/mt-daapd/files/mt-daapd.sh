#!/bin/sh
# $FreeBSD$

MT_DAAPD=/usr/local/sbin/mt-daapd
MT_DAAPD_CONF=/usr/local/etc/mt-daapd.conf


case "$1" in
	start)
		if [ -r "${MT_DAAPD_CONF}" ]; then
			${MT_DAAPD} -c ${MT_DAAPD_CONF} 
			echo -n ' mt-daapd'
		fi
		;;
	stop)
		killall -TERM mt-daapd
		;;
	*)
		echo ""
		echo "Usage: `basename $0` { start | stop }"
		echo ""
		exit 64
		;;
esac
