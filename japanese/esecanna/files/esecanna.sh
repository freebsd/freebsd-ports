#!/bin/sh

esecannaserver="!!PREFIX!!/sbin/esecannaserver"

case "$1" in
restart)
	if [ -x $esecannaserver ]; then
	    rm -f /tmp/.iroha_unix/IROHA
	    echo -n ' esecannai: '
	    $esecannaserver
	fi
	;;
start)
	if [ -f !!PREFIX!!/vje30/.version ] \
	 && grep -qw 'FREE TRIAL VERSION' !!PREFIX!!/vje30/.version \
	 && [ X"$1" != X"restart" ]; then
	    echo ""
	    echo "esecanna:"
	    echo "  Using VJE-Delta 3.0 trial, it is unable to connect to vjed on startup."
	    echo "  Please execute \`$0 restart' manually"
	    echo "  after once you run vje."
	    exit 1
	fi

	if [ -x $esecannaserver ]; then
	    rm -f /tmp/.iroha_unix/IROHA
	    echo -n ' esecannai: '
	    $esecannaserver
	fi
	;;
stop)
	killall $esecannaserver && echo -n ' esecannai'
	;;
*)
	echo "Usage: `basename $0` {restart|start|stop}" >&2
	exit 64
	;;
esac

exit 0
