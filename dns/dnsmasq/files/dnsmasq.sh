#! /bin/sh
#
#
# PROVIDE: dnsmasq
# REQUIRE: DAEMON NETWORKING SERVERS
# KEYWORD: FreeBSD
#
# Add the following line to /etc/rc.conf to enable dnsmasq:
#
# dnsmasq_enable="YES"
#

# override these variables in /etc/rc.conf
dnsmasq_enable=NO


. %%RC_SUBR%%

name=dnsmasq
rcvar=$(set_rcvar)

command=%%PREFIX%%/sbin/${name}
pidfile=/var/run/${name}.pid
required_files=${dnsmasq_conf}
#start_precmd=${name}_precmd

load_rc_config ${name}
run_rc_command "$1"

