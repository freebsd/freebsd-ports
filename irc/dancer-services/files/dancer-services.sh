#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: dancer-services
# KEYWORD: FreeBSD

. %%RC_SUBR%%

name=dancer_services
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/dancer-services
pidfile=/var/run/dancer-services/dancer-services.pid
required_files=%%PREFIX%%/etc/dancer-services/services.conf

[ -z "$dancer_services_enable" ] && dancer_services_enable=NO
[ -z "$dancer_services_user" ] && dancer_services_user=ircservices

load_rc_config $name

run_rc_command "$1"
