#!/bin/sh
# -*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# %%APP_TITLE%% startup script.
#
# $FreeBSD: /tmp/pcvs/ports/java/jboss4/files/Attic/startup.sh,v 1.2 2004-12-18 02:11:35 hq Exp $
#

# PROVIDE: %%APP_SHORTNAME%%
# REQUIRE: NETWORKING SERVERS

# Add the following lines to /etc/rc.conf to enable %%APP_SHORTNAME%%:
# %%APP_SHORTNAME%%_enable (bool):		Set to "NO" by default.
#				Set it to "YES" to enable %%APP_SHORTNAME%%
# %%APP_SHORTNAME%%_flags (str):		Set to "-server" by default.
#				Extra JVM flags.
#
. %%RC_SUBR%%

name="%%APP_SHORTNAME%%"
rcvar=`set_rcvar`

start_cmd="%%APP_SHORTNAME%%_start"
restart_cmd="%%APP_SHORTNAME%%_restart"
pidfile="%%PID_FILE%%"
procname="%%JAVA%%"

[ -z "$%%APP_SHORTNAME%%_enable" ]	&& %%APP_SHORTNAME%%_enable="NO"
[ -z "$%%APP_SHORTNAME%%_flags" ]	&& %%APP_SHORTNAME%%_flags="-server"

%%APP_SHORTNAME%%_start ()
{
	checkyesno %%APP_SHORTNAME%%_enable &&
		%%CONTROL_SCRIPT%% -q ${%%APP_SHORTNAME%%_flags} start &&
		echo -n " %%APP_SHORTNAME%%"
}

%%APP_SHORTNAME%%_restart ()
{
	checkyesno %%APP_SHORTNAME%%_enable &&
		%%CONTROL_SCRIPT%% -q ${%%APP_SHORTNAME%%_flags} restart
}

load_rc_config $name
run_rc_command "$1"
