# New ports collection makefile for:	xinv3d
# Version required:			1.3
# Date created:				21 January 2000
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	xinv3d.1.3
PKGNAME=	xinvaders3d-1.3
CATEGORIES=	games
MASTER_SITES= 	http://www.fiu.edu/~dllopi01/

MAINTAINER=	jedgar@FreeBSD.org

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/xinv3d

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xinv3d ${PREFIX}/bin

.include <bsd.port.mk>
