#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	if [ -x ${PREFIX}/libexec/ftpd ]; then
		${PREFIX}/libexec/ftpd -D -l -p /var/run/ftpd.pid > /dev/null
		echo -n ' BSDftpd-ssl'
	fi
	;;
stop)
	if [ -r /var/run/ftpd.pid ]; then
		kill -TERM `cat /var/run/ftpd.pid`
		rm -f /var/run/ftpd.pid
		echo -n ' BSDftpd-ssl'
	fi
	;;
*)
	echo ""
	echo "Usage: `basename $0` { start | stop }"
	echo ""
	exit 1
	;;
esac

exit 0
