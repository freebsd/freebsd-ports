#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: dns_balance
# REQUIRE: DAEMON
# KEYWORD: FreeBSD

dns_balance_enable="NO"
dns_balance_pidfile="/var/run/dns_balance.pid"
dns_balance_flags="-l /var/log/dns_balance.log -p ${dns_balance_pidfile}"

. %%RC_SUBR%%

name=dns_balance
rcvar=`set_rcvar`

command="env ROOT=%%PREFIX%%/lib/dns_balance %%PREFIX%%/sbin/dns_balance"
pidfile=${dns_balance_pidfile}

load_rc_config ${name}
run_rc_command "$1"
