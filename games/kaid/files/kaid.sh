#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: kaid
# REQUIRE: NETWORKING
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable  kaid:
#
# kaid_enable="YES"
#
kaid_enable="NO"

. /etc/rc.subr

name=kaid
rcvar=`set_rcvar`

command=/usr/local/sbin/${name}
command_args=-d
required_files=/usr/local/etc/kaid.conf

load_rc_config ${name}
run_rc_command "$1"
