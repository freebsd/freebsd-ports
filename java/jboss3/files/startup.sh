#!/bin/sh
# -*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# %%APP_TITLE%% startup script.
#
# $FreeBSD: /tmp/pcvs/ports/java/jboss3/files/Attic/startup.sh,v 1.1 2004-06-21 16:42:59 vanilla Exp $
#


# Set some variables
MYSELF=`basename $0`
JAVA_OPTS="%%JAVA_OPTS%%"

case "$1" in
	start)
		echo -n ' '
		truncate -s 0 %%PID_FILE%%
		chown %%USER%%:%%GROUP%% %%PID_FILE%%
		chmod 600 %%PID_FILE%%
		su -f -m %%USER%% -c "exec %%CONTROL_SCRIPT%% ${JAVA_OPTS} start" >/dev/null && echo -n '%%APP_SHORTNAME%%'
		;;
	stop)
		echo -n ' '
		chown %%USER%%:%%GROUP%% %%PID_FILE%%
		chmod 600 %%PID_FILE%%
		su -f -m %%USER%% -c "exec %%CONTROL_SCRIPT%% stop" >/dev/null 2>&1 ; echo -n '%%APP_SHORTNAME%%'
		;;
	*)
		echo ""
		echo "Usage: ${MYSELF} { start | stop }"
		echo ""
		exit 64
		;;
esac
