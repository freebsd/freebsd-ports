#!/bin/sh
#
# $FreeBSD$

case "$1" in
start)
  if [ -x %PREFIX%/bin/dancer-ircd ]; then
    su -fm ircd -c %PREFIX%/bin/dancer-ircd && echo ' dancer-ircd'
  fi
  ;;

stop)
  if [ -f /var/run/dancer-ircd.pid ]; then
    kill `cat /var/run/dancer-ircd.pid`
  else
    # oh well
    killall dancer-ircd
  fi
  ;;

*)
  echo "usage: $0 {start|stop}" >&2
  exit 64
  ;;
esac
