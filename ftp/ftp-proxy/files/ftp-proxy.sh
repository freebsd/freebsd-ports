#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: ftp-proxy
# REQUIRE: DAEMON
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move ftp-proxy.sh to /etc/rc.d/ftp-proxy
# Define these ftp-proxy_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/ftp-proxy
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#

ftpproxy_enable=${ftp-proxy_enable:-"NO"}	# Enable ftp-proxy
ftpproxy_flags=${ftp-proxy_flags:-""}		# Flags to ftp-proxy program
#ftpproxy_program="%%PREFIX%%/sbin/ftp-proxy"	# Location of ftp-proxy

. %%RC_SUBR%%

name="ftp-proxy"
rcvar=`set_rcvar`
command="%%PREFIX%%/sbin/${name}"

load_rc_config $name

run_rc_command "$1"
