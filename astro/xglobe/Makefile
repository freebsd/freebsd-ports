# New ports collection makefile for:   xglobe
# Date created:        20 January 1998
# Whom:                Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xglobe
PORTVERSION=	0.5
CATEGORIES=	astro
MASTER_SITES=	http://www.uni-karlsruhe.de/~uddn/xglobe/

MAINTAINER=	kris@FreeBSD.org

USE_QT_VER=	1
USE_X_PREFIX=	yes
USE_GMAKE=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/xglobe/
	@${INSTALL_PROGRAM} ${WRKSRC}/xglobe ${PREFIX}/bin/
	@${INSTALL_DATA} ${WRKSRC}/map.bmp ${PREFIX}/share/xglobe/
	@${INSTALL_DATA} ${WRKSRC}/xglobe-markers ${PREFIX}/share/xglobe/

.include <bsd.port.mk>
