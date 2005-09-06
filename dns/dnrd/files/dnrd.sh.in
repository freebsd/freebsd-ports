#! /bin/sh
#
#
# PROVIDE: dnrd
# REQUIRE: DAEMON NETWORKING SERVERS
# KEYWORD: FreeBSD
#
# Add the following line to /etc/rc.conf to enable dnrd:
#
# dnrd_enable="YES"
#

# override these variables in /etc/rc.conf
dnrd_enable=${dnrd_enable-"NO"}

. %%RC_SUBR%%

name=dnrd
rcvar=$(set_rcvar)

command=%%PREFIX%%/sbin/${name}
pidfile=/var/run/${name}.pid

load_rc_config ${name}

case $1 in
	"stop")
		echo "Stopping dnrd."
		${command} -k
		;;
	*)
		run_rc_command "$1"
		;;
esac

