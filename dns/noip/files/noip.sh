#!/bin/sh

case "$1" in
    start)
	if [ -x %%PREFIX%%/bin/noip2 -a -f %%PREFIX%%/etc/no-ip2.conf ]; then
            echo -n ' noip';
            su -m noip -c '%%PREFIX%%/bin/noip2' 2> /dev/null > /dev/null
        fi
    ;;
    stop)
        echo -n ' noip';
	killall noip2
    ;;
    *)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 1
    ;;
esac
exit 0
