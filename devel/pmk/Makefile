# New ports collection makefile for:	pmk
# Date created:		October 13, 2003
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pmk
PORTVERSION=	0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	premk

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Pre Make Kit, a sane replacement for autoconf

MAN1=	pmk.1 pmkscan.1
MAN5=	pmk.conf.5 pmkfile.5
MAN8=	pmksetup.8

post-extract:
	cd ${WRKDIR}; ${MAKE} clean

do-configure:
	cd ${WRKSRC}; ${MAKE} cfgrm

.include <bsd.port.mk>
