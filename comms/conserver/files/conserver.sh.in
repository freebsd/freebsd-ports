#!/bin/sh

# $FreeBSD$

# PROVIDE: conserver
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: shutdown

# To enable conserver, add lines like below to /etc/rc.conf.
#
# conserver_enable="YES"

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    # echo "$0: Cannot determine the PREFIX" >&2
    # exit 1
fi

conserver_enable=${conserver_enable:-"no"}
conserver_configfile=${conserver_configfile:-"${PREFIX}/etc/conserver.cf"}

. /etc/rc.subr

name=conserver
rcvar=`set_rcvar`

command=${PREFIX}/sbin/conserver
command_args="-d -n -C ${conserver_configfile}"

load_rc_config $name

case "$1" in
start)	if [ -x ${command} -a -f ${configfile} ]; then
		run_rc_command "$1"
	fi
	;;
*)
	run_rc_command "$1"
	;;
esac

exit 0
