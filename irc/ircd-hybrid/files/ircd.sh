#!/bin/sh
if [ $# -eq 0 -o x$1 = xstart ]; then
  if [ -x %PREFIX%/bin/ircd ]; then
    su -fm ircd -c %PREFIX%/bin/ircd && echo ' ircd'
  fi
fi
if [ x$1 = xstop ]; then
  if [ -f %PREFIX%/etc/ircd.pid ]; then
    kill `cat %PREFIX%/etc/ircd.pid`
  else
    # oh well
    killall ircd
  fi
fi
