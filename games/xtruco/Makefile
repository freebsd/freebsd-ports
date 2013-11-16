# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xtruco
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple version for X Window of the famous card game Super Truco

USE_XORG=	x11
PLIST_FILES=	bin/xtruco

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtruco ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
