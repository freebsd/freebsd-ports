#!/bin/sh

case "$1" in
	start)
		/sbin/ldconfig -m %%PREFIX%%/lib/bigloo/%%BIGLOO_VERSION%%
		;;
	stop)
		;;
	*)
		echo ""
		echo "Usage: `basename $0` { start | stop }"
		echo ""
		exit 64
		;;
esac
