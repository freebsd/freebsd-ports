#!/bin/sh

uox3dir=/usr/local/uox3

case "$1" in
start)
	if [ -x ${uox3dir}/uox3 ]; then
		cd ${uox3dir}
		uox3 > ${uox3dir}/stdout.log &
		echo -n ' uox3'
	fi
	;;
stop)
	killall uox3 && echo -n ' uox3'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac
