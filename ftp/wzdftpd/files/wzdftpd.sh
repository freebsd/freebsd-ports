#!/bin/sh

# Start or stop wzdftpd
# $FreeBSD$

# PROVIDE: wzdftpd
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown
#

prefix=%%PREFIX%%

wzdftpd_enable=${wzdftpd_enable:-"NO"}		# Enable wzdftpd
wzdftpd_program="${prefix}/sbin/wzdftpd"	# Location of wzdftpd
wzdftpd_flags=${wzdftpd_flags:-""}		# Flags to wzdftpd

. %%RC_SUBR%%

name="wzdftpd"
rcvar=`set_rcvar`
command="${prefix}/sbin/${name}"
required_files="${prefix}/etc/wzd.cfg"

load_rc_config $name
run_rc_command "$1"
