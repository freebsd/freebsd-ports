#!/bin/sh
# $FreeBSD$

# PROVIDE: daapd
# REQUIRE: DAEMON
# KEYWORD: FreeBSD shutdown

# Define these daapd_* variables in one of these files:
#       /etc/rc.conf
#       /etc/rc.conf.local
#       /etc/rc.conf.d/daapd
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
daapd_enable=${daapd_enable-"NO"}
daapd_flags=""

. %%RC_SUBR%%

name="daapd"
rcvar=`set_rcvar`

daapd_user="%%USER%%"
daapd_group="%%USER%%"
prefix="%%PREFIX%%"
logdir="%%LOGDIR%%"
cache="%%CACHE%%"

daapdBin="${prefix}/sbin/daapd"
daapdCfg="${prefix}/etc/daapd.conf"
daapdLog="${logdir}/daapd.log"

required_files="${daapdCfg}"

start_precmd="touch ${daapdLog}; chown ${daapd_user} ${daapdLog}; touch ${cache}; chown ${daapd_user} ${cache};"

command="${daapdBin}"
command_args="${daapd_flags} >>${daapdLog} 2>&1 &"

load_rc_config $name
run_rc_command "$1"
