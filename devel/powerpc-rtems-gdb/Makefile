# New ports collection makefile for:	powerpc-rtems-gdb
# Date created:		9 June 2000
# Whom:			James Housley <jim@thehousleys.net>
#
# $FreeBSD$
#

PORTNAME=	gdb

MAINTAINER=	jeh@FreeBSD.org

LCLTARGET=	powerpc-rtems
CONFIGURE_ARGS=	--verbose --enable-sim --enable-sim-powerpc \
		--enable-sim-timebase --enable-sim-hardware
.include "${.CURDIR}/../i386-rtems-gdb/Makefile"
