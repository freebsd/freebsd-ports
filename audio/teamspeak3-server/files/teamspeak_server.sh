#!/bin/sh
#
# Start/stop the TeamSpeak 2 server
#

TSHOME=%%TSHOME%%
PIDFILE=${TSHOME}/server.pid

cd "$TSHOME"

case "$1" in
    start)
        ./server_linux >/dev/null 2>&1
        ;;
    stop)
        kill -TERM `cat "$PIDFILE"`
        ;;
    restart)
        $0 stop && $0 start || exit 1
        ;;
    *)
        echo "Usage: $0 {start|stop|restart}"
        exit 1
esac
exit 0

