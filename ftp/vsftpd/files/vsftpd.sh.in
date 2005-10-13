#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: vsftpd
# REQUIRE: DAEMON
# KEYWORD: FreeBSD

# Add the following line to /etc/rc.conf to enable `vsftpd':
#
# vsftpd_enable="YES"
# vsftpd_flags="/some/path/conf.file" # Not required
#

. "%%RC_SUBR%%"

name="vsftpd"
rcvar=`set_rcvar`

load_rc_config "$name"
: ${vsftpd_enable="NO"}
: ${vsftpd_flags=""}

command="%%PREFIX%%/libexec/$name ${vsftpd_flags}"
required_files="%%PREFIX%%/etc/$name.conf"

vsftpd_check()
{
	cat ${required_files} | egrep -E "^listen.*=.*YES$" > /dev/null
	if [ $? = 1 ]; then
		err 1 "vsftpd script need "listen=YES" on config file"
	fi
	cat ${required_files} | egrep -E "^background.*=.*YES$" > /dev/null
	if [ $? = 1 ]; then
		err 1 "vsftpd script need "background=YES" on config file"
	fi
}

vsftpd_check

run_rc_command "$1"
