#!/bin/sh

# Start or stop cyrus-imspd
# $FreeBSD$

case "$1" in
start)
	if [ -x /usr/local/sbin/imspd -a \
	     -f /var/imsp/options ]; then
		/usr/local/sbin/imspd >/dev/null &
		echo -n ' imspd'
	fi
	;;
stop)
	kill `ps -U root | awk '/imspd$/ {print $1}'` && echo -n ' imspd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
