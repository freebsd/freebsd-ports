#!/bin/sh
# script to create the lock directory in case it was
# removed in /etc/rc
#echo -n ' Xemacs'

case $1 in
start)
	if [ -d /var/run/emacs/lock ]
	then
	# delete any junk which may have been left around
		rm -f /var/run/emacs/lock/*
	else
		mkdir -p /var/run/emacs/lock
	fi
	# can always do this
	chmod 1777 /var/run/emacs/lock
	;;
stop)
	# nothing to do
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
