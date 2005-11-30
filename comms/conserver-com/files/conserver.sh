#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: conserver
# KEYWORD: FreeBSD

. %%RC_SUBR%%

name="conserver"
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/${name}
pidfile=/var/run/conserver.pid
required_files=%%PREFIX%%/etc/conserver.cf

load_rc_config $name
: ${conserver_enable="NO"}
: ${conserver_flags="-d"}

run_rc_command "$1"
