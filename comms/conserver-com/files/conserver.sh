#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: conserver
# KEYWORD: FreeBSD

. %%RC_SUBR%%

name=conserver
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/conserver
pidfile=/var/run/conserver.pid
required_files=%%PREFIX%%/etc/conserver.cf

# set defaults
[ -z "$conserver_enable" ]	&& conserver_enable=NO
[ -z "$conserver_flags" ]	&& conserver_flags="-d"

load_rc_config $name

run_rc_command "$1"
