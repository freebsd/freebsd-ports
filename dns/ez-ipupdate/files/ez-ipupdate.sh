#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: ez-ipupdate
# REQUIRE:
# BEFORE:
# KEYWORD: FreeBSD shutdown

# Add the following line to /etc/rc.conf to enable ez-ipupdate:
#
#ez_ipupdate_enable="YES"
#

: ${ez_ipupdate_enable="NO"}
: ${ez_ipupdate_pidfile="/var/run/ez-ipupdate.pid"}
: ${ez_ipupdate_configfile="%%PREFIX%%/etc/ez-ipupdate.conf"}
: ${ez_ipupdate_flags="-d -c $ez_ipupdate_configfile -F $ez_ipupdate_pidfile"}

. %%RC_SUBR%%

name=ez_ipupdate
rcvar=`set_rcvar`

command=%%PREFIX%%/bin/ez-ipupdate
pidfile=$ez_ipupdate_pidfile
required_files=$ez_ipupdate_configfile
sig_stop=QUIT

load_rc_config $name
run_rc_command "$1"
