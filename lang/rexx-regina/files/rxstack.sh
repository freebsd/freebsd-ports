#!/bin/sh

case "$1" in
start)
	[ -x /usr/local/bin/rxstack ] && /usr/local/bin/rxstack -d && \
		echo -n "Starting Regina Stack"
	;;
stop)
	killall rxstack && echo -n "Shutting down Regina Stack"
	;;
esac
