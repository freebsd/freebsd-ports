#!/bin/sh
#

# PROVIDE: musicpd
# REQUIRE:
# BEFORE:
# KEYWORD: FreeBSD shutdown

# Add the following line to /etc/rc.conf to enable mpd:
#
#musicpd_enable="YES"

. %%RC_SUBR%%

name=musicpd
rcvar=`set_rcvar`

config=%%PREFIX%%/etc/mpd.conf
command=%%PREFIX%%/bin/mpd
required_files=$config

musicpd_flags="$musicpd_flags $config"

[ -z "$musicpd_enable" ] && musicpd_enable="NO"
[ -z "$musicpd_flags" ]  && musicpd_flags=

load_rc_config $name

run_rc_command "$1"
