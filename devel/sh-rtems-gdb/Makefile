# New ports collection makefile for:	sh-rtems-gdb
# Date created:		9 June 2000
# Whom:			James Housley <jim@thehousleys.net>
#
# $FreeBSD$
#

PORTNAME=	gdb

MAINTAINER=	jeh@FreeBSD.org

LCLTARGET=	sh-rtems
CONFIGURE_ARGS=	--verbose --enable-sim

MAN1=		${LCLTARGET}-run.1

MASTERDIR=	${.CURDIR}/../i386-rtems-gdb
.include "${MASTERDIR}/Makefile"
