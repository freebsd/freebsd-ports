# New ports collection makefile for:	icod
# Date created:				02 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	icod
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	http://linux.tucows.com/files/x11/graphics/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	jedgar@fxp.org

WRKSRC=		${WRKDIR}/icod
ALL_TARGET=	icod

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/icod ${PREFIX}/bin

.include <bsd.port.mk>
