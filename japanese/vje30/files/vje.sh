#!/bin/sh
#
# $FreeBSD$

# PROVIDE: vjed
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown

. %%RC_SUBR%%

name=vjed
rcvar=`set_rcvar`

command=%%PREFIX%%/vje30/bin/vjed

required_files=%%PREFIX%%/etc/vje30/vje.cfg

[ -z "$vjed_enable" ] && vjed_enable=NO

load_rc_config $name
run_rc_command "$1"
