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

. /etc/rc.subr

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/${0##*/}\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

name="ez_ipupdate"
rcvar=`set_rcvar`
command="$PREFIX/bin/ez-ipupdate"
pidfile="/var/run/ez-ipupdate.pid"
required_files="$PREFIX/etc/ez-ipupdate.conf"
sig_stop="QUIT"

ez_ipupdate_enable="NO"
ez_ipupdate_flags="-c $PREFIX/etc/ez-ipupdate.conf -d -F $pidfile"

load_rc_config $name
run_rc_command "$1"
