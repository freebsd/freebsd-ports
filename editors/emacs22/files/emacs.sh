#!/bin/sh

case "$1" in
start)
	if [ -d /var/run/emacs/lock ]
	then
	    rm -f /var/run/emacs/lock/*
	else
	    mkdir -p /var/run/emacs/lock
	fi
	chmod 1777 /var/run/emacs/lock
	;;
stop)
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
