#!/bin/sh
case $1 in
stop)
	if ! [ -f /var/run/tclhttd.pid ] ; then
		echo tclhttd does not seem to be running
		exit 1
	fi
	echo "Not sure if `cat /var/run/tclhttd.pid` \
		(from /var/run/tclhttd.pid) is what you wish killed."
	exit 2
	;;
start|"")
	COMMAND_LINE &
	test -n "$!" && echo $! > /var/run/tclhttd.pid
	;;
esac
