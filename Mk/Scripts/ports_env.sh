#! /bin/sh

# MAINTAINER: portmgr@FreeBSD.org
# $FreeBSD$

if [ -z "${SCRIPTSDIR}" ]; then
	echo "Must set SCRIPTSDIR" >&2
	exit 1
fi

. ${SCRIPTSDIR}/functions.sh

export_ports_env
