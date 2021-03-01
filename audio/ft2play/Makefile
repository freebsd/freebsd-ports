# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ft2play
DISTVERSION=	g20210124
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Bit-accurate C port of Fasttracker's XM replayer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		sdl
USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	8bitbubsy
GH_TAGNAME=	5730b16
USE_SDL=	sdl2

CFLAGS+=	-DAUDIODRIVER_SDL -DNDEBUG `sdl2-config --cflags`
LDFLAGS+=	-lm -lpthread `sdl2-config --libs`

PLIST_FILES=	bin/ft2play

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/audiodrivers/sdl/*.c \
		${WRKSRC}/*.c ${WRKSRC}/ft2play/src/*.c \
		-o ${WRKSRC}/ft2play/release/other/ft2play

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ft2play/release/other/ft2play \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
