#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: frox
# REQUIRE: NETWORKING
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable frox:
#
#frox_enable="YES"
#
# See frox(8) for flags
#

. %%RC_SUBR%%

name=frox
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/frox
pidfile=/var/run/frox.pid
required_files=%%PREFIX%%/etc/frox.conf

start_precmd=start_precmd
stop_postcmd=stop_postcmd

# if require start from inetd?
start_precmd()
{
  if grep -iq '^[[:space:]]*frominetd[[:space:]]*yes' %%PREFIX%%/etc/frox.conf;
  then
	  return 1
  else
	  return 0
  fi
}

stop_postcmd()
{
   rm -f $pidfile
}

# set defaults

frox_enable=${frox_enable:-"NO"}
frox_flags=${frox_flags:-""}

load_rc_config $name
run_rc_command "$1"
