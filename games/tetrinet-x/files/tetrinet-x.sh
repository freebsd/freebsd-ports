#!/bin/sh

tetrixdir=/usr/local/tetrinet-x
tetrix=tetrix.freebsd

case "$1" in
start)
	[ -x ${tetrixdir}/${tetrix} ] && cd ${tetrixdir} && \
		${tetrixdir}/${tetrix} > /dev/null && echo -n ' tetrinet-x'
	;;
stop)
	killall ${tetrix} && echo -n ' tetrinet-x'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac
