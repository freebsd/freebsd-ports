#!/bin/sh
#
# $FreeBSD$

case "$1" in
start)
  if [ -x %PREFIX%/sbin/dancer-services ]; then
    su -fm ircservices -c %PREFIX%/sbin/dancer-services && echo ' dancer-services'
  fi
  ;;

stop)
  if [ -f /var/run/dancer-services.pid ]; then
    kill `cat /var/run/dancer-services.pid`
  else
    # oh well
    killall dancer-services
  fi
  ;;

*)
  echo "usage: $0 {start|stop}" >&2
  exit 64
  ;;
esac
