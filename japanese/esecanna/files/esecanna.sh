#!/bin/sh
#
# $FreeBSD$

# PROVIDE: esecanna
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown

. %%RC_SUBR%%

name=esecanna
rcvar=`set_rcvar`

esecannaserver=%%PREFIX%%/sbin/esecannaserver

# XXX
command=/usr/bin/nohup
command_args=">/dev/null $esecannaserver"
procname=$esecannaserver

pidfile=/var/run/esecanna/esecanna.pid
esecanna_chdir="$(dirname $pidfile)"
required_files=%%PREFIX%%/etc/esecannarc

start_precmd="esecanna_prestart"

[ -z "$esecanna_enable" ] && esecanna_enable=NO

esecanna_prestart ()  {
	if [ -f %%PREFIX%%/vje30/.version ] \
	   && grep -qw 'FREE TRIAL VERSION' %%PREFIX%%/vje30/.version; then
		echo '** Using VJE-Delta 3.0 trial, it is unable to connect to vjed on startup.'
		echo '** Please execute $esecannaserver manually after once you run vje.'
		exit 255
	fi

	/bin/rm -f /tmp/.iroha_unix/IROHA
}

load_rc_config $name
run_rc_command "$1"
