#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: moftpd
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable moftpd:
# moftpd_enable (bool):      Set to "NO" by default.
# moftpdlimits_enable (bool):Set to "NO" by default.
#                             Set it to yes to run `limits $limits_args`
#                             just before moftpd starts.
# moftpd_flags (str):        Set to "" by default.
#                             Extra flags passed to start command
# moftpdlimits_args (str):   Default to "-e -C daemon"
#                             Arguments of pre-start limits run.
#
. %%RC_SUBR%%

name="moftpd"
rcvar=`set_rcvar`

command="%%PREFIX%%/sbin/moftpd"
pidfile="/var/run/moftpd.pid"
required_files=%%PREFIX%%/etc/moftpd.conf

[ -z "$moftpd_enable" ]       && moftpd_enable="NO"
[ -z "$moftpd_flags" ]        && moftpd_flags=""
[ -z "$moftpdlimits_enable" ] && moftpdlimits_enable="NO"
[ -z "$moftpdlimits_args" ]   && moftpdlimits_args="-e -C daemon"

load_rc_config $name

checkyesno moftpdlimits_enable && \
			start_precmd="eval `/usr/bin/limits ${moftpdlimits_args}` 2>/dev/null"

run_rc_command "$1"
