#!/bin/sh

case "$1" in
    start)
	if [ -x %%PREFIX%%/bin/noip -a -f %%PREFIX%%/etc/no-ip.conf ]; then
            echo -n ' noip';
            su -m noip -c '%%PREFIX%%/bin/noip' 2> /dev/null > /dev/null
        fi
    ;;
    stop)
        echo -n ' noip';
	killall noip
    ;;
    *)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 1
    ;;
esac
exit 0
