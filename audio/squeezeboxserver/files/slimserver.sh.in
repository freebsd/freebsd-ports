#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: slimserver
# REQUIRE: LOGIN
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable slimserver:
#
#slimserver_enable="YES"
#

. %%RC_SUBR%%

name=slimserver
stop_cmd="slimserver_stop"
rcvar=`set_rcvar`

command=%%PREFIX%%/%%SLIMDIR%%/slimserver.pl
pidfile=/var/run/${name}.pid
conffile=/var/db/slimserver/slimserver.conf
logfile=/var/log/slimserver.log
u=slimserv
g=slimserv
command_args="--daemon --prefsfile=${conffile} --logfile=${logfile} --user=${u} --group=${g} --pidfile=${pidfile}"

slimserver_stop()
{
	if [ ! -f ${pidfile} ]; then
		exit
	fi
	echo 'Stopping SlimServer.'
	rc_pid=`cat ${pidfile}`
	rc_pid=`pgrep -u ${u} | grep ${rc_pid}`
	if [ -n "${rc_pid}" ]; then
		rc_pids="${rc_pid} `pgrep -u ${u} mDNSResponderPosix`"

		kill $sig_stop $rc_pids
		wait_for_pids $rc_pids
	else
		echo "${name} not running? (check ${pidfile})"
	fi

	rm -f ${pidfile}
}

# set defaults

slimserver_enable=${slimserver_enable:-"NO"}
slimserver_flags=${slimserver_flags:-""}

load_rc_config ${name}
run_rc_command "$1"
