#!/bin/sh

if ! test -x /usr/local/sbin/f4a.ftpd
then
	exit 0
fi

case $1 in
start)
	echo -n ' ftp4all.ftpd'
	/usr/local/sbin/f4a.ftpd
	;;
stop)
	echo -n ' ftp4all.ftpd'
	kill `head -1 /var/run/ftpd.run`
	;;
*)
	echo "Usage: $0: [ start | stop ]" 2>&1
	exit 65
	;;
esac
