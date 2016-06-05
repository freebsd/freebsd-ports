# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	fxsudoku
PORTVERSION=	0.5.1
PORTREVISION=	26
CATEGORIES=	games
MASTER_SITES=	http://www.fifthplanet.net/files/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Implementation of the Sudoku game

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LIB_DEPENDS=	libFOX-1.6.so:x11-toolkits/fox16

USES=		tar:bzip2 gmake
PLIST_FILES=	bin/fxsudoku

post-extract:
	${CP} ${FILESDIR}/config.freebsd ${WRKSRC}/build

do-build:
	cd ${WRKSRC} && MAKE=${MAKE_CMD} ./gb

do-install:
	cd ${WRKSRC} && MAKE=${MAKE_CMD} ./gb install --prefix=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
