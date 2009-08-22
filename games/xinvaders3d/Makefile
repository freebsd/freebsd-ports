# New ports collection makefile for:	xinv3d
# Date created:				21 January 2000
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xinvaders3d
PORTVERSION=	1.3.6
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/XInvaders%203d/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D Vector-graphics Space Invaders clone for X

USE_XORG=	x11
PLIST_FILES=	bin/xinv3d
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xinv3d ${PREFIX}/bin

.include <bsd.port.mk>
