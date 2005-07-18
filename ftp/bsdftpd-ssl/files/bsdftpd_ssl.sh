#!/bin/sh

# PROVIDE: bsdftpd_ssl
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown

#
# You need to set "bsdftpd_ssl_enable=YES" in either /etc/rc.conf,
# /etc/rc.conf.local or /etc/rc.conf.d/bsdftpd_ssl to make this script actually
# do something. There you can also set bsdftpd_ssl_flags. Note: the "-D" and
# "-p" options will be added automatically, you should not specify them. Please
# see the examples and the ftpd-ssl(8) man page for more information.
#

. %%RC_SUBR%%

name="bsdftpd_ssl"
rcvar=`set_rcvar`
pidfile="/var/run/ftpd.pid"
command="%%PREFIX%%/libexec/ftpd"
command_args="-D -p ${pidfile}"

stop_postcmd="rm -f /var/run/ftpd.pid"

# Set defaults

bsdftpd_ssl_enable=${bsdftpd_ssl_enable:-"NO"}
bsdftpd_ssl_flags=${bsdftpd_ssl_flags:-""}

# Run the daemon

load_rc_config $name
run_rc_command "$1"
