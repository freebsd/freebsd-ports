#!/bin/sh
#
# Add the following line to /etc/rc.conf to enable wolfpack:
#
# wolfpack_enable="YES"
#

. %%RC_SUBR%%

name=wolfpack
rcvar=`set_rcvar`

wolfdir="%%PREFIX%%/wolfpack"

command="$wolfdir/bin/emp_server"
pidfile="$wolfdir/data/wolfpack.pid"

wolfpack_enable=${wolfpack_enable:-"NO"}
wolfpack_user=${wolfpack_user:-"wolfpack"}
wolfpack_flags=${wolfpack_flags:-"-P $pidfile"}

load_rc_config $name

run_rc_command "$1"

