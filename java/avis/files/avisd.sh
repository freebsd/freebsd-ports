#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: avisd
# REQUIRE: LOGIN
# KEYWORD: shutdown

# Add the following line to /etc/rc.conf to enable `avisd':
#
#avisd_enable="YES"
#
# See avisd(1) for avisd_flags
#

. "/etc/rc.subr"

name="avisd"
rcvar=`set_rcvar`

logfile="/var/log/avis.log"
command="/usr/local/sbin/avisd"
pidfile="/var/run/$name.pid"
command_args="-c /usr/local/etc/$name.conf -daemon -pidfile $pidfile -logfile $logfile"
command_interpreter=/bin/sh
required_files="/usr/local/etc/$name.conf"

# read configuration and set defaults
load_rc_config "$name"
: ${avisd_enable="NO"}
: ${avisd_flags=""}

run_rc_command "$1"
