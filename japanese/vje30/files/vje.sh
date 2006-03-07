#!/bin/sh
#
# $FreeBSD$

# PROVIDE: vjed
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: shutdown

. %%RC_SUBR%%

name=vjed
rcvar=`set_rcvar`

required_files=%%PREFIX%%/etc/vje30/vje.cfg
start_precmd='/sbin/ldconfig -m %%PREFIX%%/lib/compat'
command=%%PREFIX%%/vje30/bin/vjed

[ -z "$vjed_enable" ] && vjed_enable=NO

load_rc_config $name
run_rc_command "$1"
