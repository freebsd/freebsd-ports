#!/bin/sh

case "$1" in
start)
	if [ -x %%PREFIX%%/libexec/ftpd-tls ]; then
		%%PREFIX%%/libexec/ftpd-tls -DUl > /dev/null
		echo -n ' ftpd-tls'
	fi
	;;
stop)
	if [ -r /var/run/ftpd-tls.pid ]; then
		kill -TERM `cat /var/run/ftpd-tls.pid`
		rm -f /var/run/ftpd-tls.pid
		echo -n ' ftpd-tls'
	fi
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
