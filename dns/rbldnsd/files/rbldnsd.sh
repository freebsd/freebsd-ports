#!/bin/sh
#
# $Id$
#

# PROVIDE: rbldnsd
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown
#
# Add the following lines to /etc/rc.conf to enable rbldnsd:
#
#   rbldnsd_enable="YES"
#
# See rbldnsd(8) for flags.
#

. %%RC_SUBR%%

name=rbldnsd
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/rbldnsd
pidfile=/var/run/rbldnsd.pid

stop_postcmd=stop_postcmd

stop_postcmd()
{
  rm -f $pidfile
}

# set defaults, enforce pidfile by making it last option before db

rbldnsd_enable=${rbldnsd_enable:-"NO"}
rbldnsd_flags=${rbldnsd_flags:-"-r /usr/local/etc/rbldnsd -b 127.0.0.1 bl.example.com:ip4set:example"}
rbldnsd_flags="${rbldnsd_flags% *} -p $pidfile ${rbldnsd_flags##* }"

load_rc_config $name
run_rc_command "$1"

