#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: %%SERVICE%%
# REQUIRE: SERVERS
# BEFORE: DAEMON
# KEYWORD: FreeBSD shutdown
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move %%SERVICE%%.sh to /etc/rc.d/%%SERVICE%%

prefix=%%PREFIX%%

# Define these %%SERVICE%%_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/%%SERVICE%%
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
%%SERVICE%%_enable=${%%SERVICE%%_enable:-"NO"}
%%SERVICE%%_flags=${%%SERVICE%%_flags:-""}	# Can be "-f /path/alternate_rc"

. %%RC_SUBR%%

name="%%SERVICE%%"
rcvar=`set_rcvar`
command="${prefix}/sbin/${name}"
command_args="| /usr/bin/logger -p daemon.notice -t %%SERVICE%% &"

load_rc_config $name

flags="${%%SERVICE%%_flags}"

run_rc_command "$1"
