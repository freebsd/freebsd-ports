#!/bin/sh
#
# Start/stop the TeamSpeak 2 server
#

TSHOME=%%TSHOME%%
PIDFILE=${TSHOME}/server.pid

cd "$TSHOME"

case "$1" in
	start)
		su -fm nobody -c './server_linux >/dev/null 2>&1' && echo -n ' teamspeak_server'
		;;
	stop)
		kill -TERM `cat "$PIDFILE"`
		;;
	restart)
		$0 stop
		echo 5 second pause before restart. . .
		sleep 5
		$0 start
		;;
	*)
	echo "Usage: $0 {start|stop|restart}"
	exit 1
esac
exit 0

