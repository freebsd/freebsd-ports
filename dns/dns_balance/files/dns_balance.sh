#!/bin/sh
#
# $FreeBSD$

dns_balance="!!PREFIX!!/sbin/dns_balance"
pidfile="/var/run/dns_balance.pid"
logfile="/var/log/dns_balance.log"
#listen="-i 192.168.0.1"

case "$1" in
start)
	if [ -x $dns_balance ]; then
	    echo -n ' dns_balance'
	    $dns_balance -l $logfile -p $pidfile $listen
	fi
	;;
stop)
	if [ -f $pidfile ]; then
	    kill `cat $pidfile` && echo -n ' dns_balance'
	else
	    echo ' dns_balance: not running'
	fi
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
