#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: mysql
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: shutdown

#
# Add the following line to /etc/rc.conf to enable mysql:
# mysql_enable (bool):		Set to "NO" by default.
#				Set it to "YES" to enable MySQL.
# mysqllimits_enable (bool):	Set to "NO" by default.
#				Set it to yes to run `limits $limits_args`
#				just before mysql starts.
# mysqllimits_args (str):	Default to "-e -U mysql"
#				Arguments of pre-start limits run.
#

. %%RC_SUBR%%

name="mysql"
rcvar=`set_rcvar`
mysql_dbdir="%%DB_DIR%%"
mysql_user="mysql"
pidfile="${mysql_dbdir}/`/bin/hostname`.pid"
command="%%PREFIX%%/bin/mysqld_safe"
command_args="--user=${mysql_user} --datadir=${mysql_dbdir} --pid-file=${pidfile} > /dev/null &"
procname="%%PREFIX%%/libexec/mysqld"
start_precmd="${name}_prestart"

[ -z "$mysql_enable" ]		&& mysql_enable="NO"
[ -z "$mysqllimits_enable" ]	&& mysqllimits_enable="NO"
[ -z "$mysqllimits_args" ]	&& mysqllimits_args="-e -U ${mysql_user}"

mysql_prestart()
{
	if checkyesno mysqllimits_enable; then
		eval `/usr/bin/limits ${mysqllimits_args}` 2>/dev/null
	else
		return 0
	fi
}

required_dirs="${mysql_dbdir}"
required_files="${mysql_dbdir}/mysql/host.frm ${mysql_dbdir}/mysql/user.frm ${mysql_dbdir}/mysql/db.frm"

load_rc_config $name
run_rc_command "$1"
