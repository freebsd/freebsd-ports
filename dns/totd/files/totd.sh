#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: totd
# REQUIRE: SERVERS
# BEFORE:  DAEMON
# KEYWORD: FreeBSD
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move totd.sh to /etc/rc.d/totd

prefix=%%PREFIX%%

# Define these totd_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/totd
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
totd_enable=${totd_enable:-"NO"}		# Enable totd
#totd_program="${prefix}/sbin/totd"		# Location of totd
totd_flags=${totd_flags:-""}			# Flags to totd program

. %%RC_SUBR%%

name="totd"
rcvar=`set_rcvar`
command="${prefix}/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="${prefix}/etc/${name}.conf"

load_rc_config $name
run_rc_command "$1"
