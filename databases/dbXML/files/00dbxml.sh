#!/bin/sh

JAVA_HOME=%%JAVA_HOME%%
export JAVA_HOME
DBXML_HOME=%%PREFIX%%/share/java/dbXML
export DBXML_HOME

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	[ -x ${PREFIX}/bin/dbxmlctl ] && ${PREFIX}/bin/dbxmlctl start > /dev/null && echo -n ' dbXML'
	;;
stop)
	[ -r /var/run/dbXML.pid ] && ${PREFIX}/bin/dbxmlctl stop > /dev/null && echo -n ' dbXML'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
