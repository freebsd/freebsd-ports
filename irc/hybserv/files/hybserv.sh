#!/bin/sh
if [ $# -eq 0 -o x$1 = xstart ]; then
  if [ -x %PREFIX%/hybserv/hybserv ]; then
    su -fm hybserv -c %PREFIX%/hybserv/hybserv && echo ' hybserv'
  fi
fi
if [ x$1 = xstop ]; then
  if [ -f %PREFIX%/hybserv/hybserv.pid ]; then
    kill `cat %PREFIX%/hybserv/hybserv.pid`
  else
    # oh well
    killall hybserv
  fi
fi

