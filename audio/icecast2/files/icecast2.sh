#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/audio/icecast2/files/Attic/icecast2.sh,v 1.1 2004-12-10 21:41:23 lofi Exp $
#

# PROVIDE: icecast2
# REQUIRE: DAEMON
# BEFORE:  login
# KEYWORD: FreeBSD shutdown

# Add the following line to /etc/rc.conf to enable `icecast2':
#
#icecast_enable="YES"
#icecast_flags=""
#

. "/etc/rc.subr"

name="icecast"
rcvar=`set_rcvar`

command="/usr/local/bin/icecast"
command_args="1>/dev/null 2>&1"
pidfile="/usr/local/share/icecast/$name.pid"
required_files="/usr/local/etc/$name.xml"

# read configuration and set defaults
load_rc_config "$name"
: ${icecast_enable="NO"}
: ${icecast_flags=""}

run_rc_command "$1"
