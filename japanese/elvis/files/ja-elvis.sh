#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	virecovery=`echo /var/tmp/elv_*`
	if [ "$virecovery" != '/var/tmp/elv_*' ]; then
		echo 'Recovering ja-elvis editor sessions'
		for i in $$virecovery; do
			${PREFIX}/bin/elvprsv "$i"
		done
	fi
	;;
stop)
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
