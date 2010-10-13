# New ports collection makefile for:	gpxloggerd
# Date created:		8 December 2010
# Whom:			glebius
#
# $FreeBSD$
#

PORTNAME=	gpxloggerd
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	LOCAL/glebius

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	A daemon that connects to the GPSD daemon and logs GPS traces

LIB_DEPENDS=	gps.19:${PORTSDIR}/astro/gpsd

USE_RC_SUBR=	${PORTNAME}
PLIST_FILES=	sbin/${PORTNAME}
MAN8=		${PORTNAME}.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${PREFIX}/man/man8/

.include <bsd.port.mk>
