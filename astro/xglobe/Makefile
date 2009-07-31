# New ports collection makefile for:   xglobe
# Date created:        20 January 1998
# Whom:                Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xglobe
PORTVERSION=	0.5
PORTREVISION=	7
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=kris

MAINTAINER=	kris@FreeBSD.org
COMMENT=	Displays a view of the Earth (like xearth) with a rendered photo map

USE_QT_VER=	3
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}

do-install:
	@${MKDIR} ${PREFIX}/share/xglobe/
	@${INSTALL_PROGRAM} ${WRKSRC}/xglobe ${PREFIX}/bin/
	@${INSTALL_DATA} ${WRKSRC}/map.bmp ${PREFIX}/share/xglobe/
	@${INSTALL_DATA} ${WRKSRC}/xglobe-markers ${PREFIX}/share/xglobe/

.include <bsd.port.mk>
