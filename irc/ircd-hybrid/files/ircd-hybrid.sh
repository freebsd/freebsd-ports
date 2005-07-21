#!/bin/sh
PIDFILE=/var/run/ircd.pid

if [ $# -eq 0 -o x$1 = xstart ]; then
  if [ -x %PREFIX%/bin/ircd ]; then
    touch $PIDFILE 
    chown ircd $PIDFILE  
    su -fm ircd -c %PREFIX%/bin/ircd && echo ' ircd'
  fi
fi
if [ x$1 = xstop ]; then
  if [ -s $PIDFILE ]; then
    kill `cat $PIDFILE`
  else
    # oh well
    killall ircd
  fi
  rm -f $PIDFILE
fi
