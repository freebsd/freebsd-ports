#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: bnetd
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable bnetd:
#
#bnetd_enable="YES"
#
# See bnetd(1) for flags
#

. %%RC_SUBR%%

name=bnetd
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/bnetd
pidfile=/var/run/pvpgn/bnetd.pid
required_files=%%PREFIX%%/etc/pvpgn/bnetd.conf

stop_postcmd=stop_postcmd

stop_postcmd()
{
  rm -f $pidfile
}

# set defaults

bnetd_enable=${bnetd_enable:-"NO"}
bnetd_flags=${bnetd_flags:-""}

load_rc_config $name
run_rc_command "$1"
