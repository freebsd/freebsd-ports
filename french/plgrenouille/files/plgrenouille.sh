#! /bin/sh
#
# $FreeBSD$
#
# PROVIDE: plgrenouille
# REQUIRE: DAEMON
# KEYWORD: FreeBSD
#
# Add the following line to /etc/rc.conf to enable upclient:
#
# plgrenouille_enable="YES"
#

plgrenouille_enable=NO
plgrenouille_flags=-b

. %%RC_SUBR%%

name=plgrenouille
rcvar=$(set_rcvar)

command=%%LBIN_DIR%%/${name}
command_interpreter=%%PERL%%
pidfile=%%RUN_DIR%%/${name}.pid
logfile=%%LOG_DIR%%/${name}.log
required_files=%%CONF_DIR%%/grenouillerc
extra_commands=configure
configure_cmd="${command} -c"

load_rc_config ${name}
run_rc_command "$1"
