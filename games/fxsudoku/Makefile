# New ports collection makefile for:    games/fxsudoku
# Date created:         31 March 2006
# Whom:			Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	fxsudoku
PORTVERSION=	0.5.1
CATEGORIES=	games
MASTER_SITES=	http://www.fifthplanet.net/files/

MAINTAINER=	edwin@mavetju.org
COMMENT=	An implementation of the Sudoku game

LIB_DEPENDS=	FOX-1.6.1:${PORTSDIR}/x11-toolkits/fox16

USE_BZIP2=	yes
USE_GMAKE=	yes
PLIST_FILES=	bin/fxsudoku

post-extract:
	${CP} ${FILESDIR}/config.freebsd ${WRKSRC}/build

do-build:
	cd ${WRKSRC} && MAKE=${GMAKE} ./gb

do-install:
	cd ${WRKSRC} && MAKE=${GMAKE} ./gb install --prefix=${PREFIX}

.include <bsd.port.mk>
