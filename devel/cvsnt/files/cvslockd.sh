#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: cvslockd
# REQUIRE: LOGIN
# KEYWORD: FreeBSD shutdown
#
. %%RC_SUBR%%

[ -z "$cvslockd_enable" ] && cvslockd_enable="NO"

name=cvslockd
rcvar=`set_rcvar`
command=%%PREFIX%%/bin/${name}

load_rc_config ${name}
run_rc_command "$1"
