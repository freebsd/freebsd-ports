#!/bin/sh
#

# PROVIDE: memcached
# REQUIRE: NETWORKING

#
# Add the following lines to /etc/rc.conf to run memcached:
#
#memcached_enable="YES"
#memcached_flags=""
#
. %%RC_SUBR%%

name="memcached"
rcvar=`set_rcvar`
command=%%PREFIX%%/bin/memcached
command_args="-du nobody ${memcached_flags}"

load_rc_config $name
run_rc_command "$1"
