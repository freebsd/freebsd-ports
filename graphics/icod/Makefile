# New ports collection makefile for:	icod
# Version required:			1.0
# Date created:				02 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	icod.1.0
PKGNAME=	icod-1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.linuxberg.com/files/x11/graphics/

MAINTAINER=	jedgar@fxp.org

WRKSRC=		${WRKDIR}/icod
ALL_TARGET=	icod

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/icod ${PREFIX}/bin

.include <bsd.port.mk>
