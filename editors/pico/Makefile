# New ports collection makefile for:	pico
# Date created:			16 December 2000
# Whom:				Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#
# This port tracks Pine4
# All patch files have been taken from mail/pine4

PORTNAME=	pico
PORTVERSION= 	3.7
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/
DISTNAME=	pine${pineversion}

MAINTAINER=	jeremy@external.org

WRKSRC=		${WRKDIR}/pine${pineversion}/pico
PATCH_WRKSRC=	${WRKSRC}/..

pineversion=	4.21

MAKEFILE=	makefile.bsf
ALL_TARGET=	pico

MAN1=		pico.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pico ${PREFIX}/bin/pico
	${INSTALL_MAN} ${WRKSRC}/../doc/pico.1 ${PREFIX}/man/man1/pico.1

.include <bsd.port.mk>
