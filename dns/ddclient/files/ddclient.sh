#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: ddclient
# REQUIRE: LOGIN
# KEYWORD: shutdown

#
# Add the following line to /etc/rc.conf to enable ddclient:
#
#ddclient_enable="YES"
#
ddclient_enable=${ddclient_enable-"NO"}
ddclient_flags=${ddclient_flags-"-daemon 300"}

. %%RC_SUBR%%

name="ddclient"
rcvar=`set_rcvar`
command="%%PREFIX%%/sbin/${name}"
required_files="%%PREFIX%%/etc/${name}.conf"

load_rc_config ${name}

run_rc_command "$1"
