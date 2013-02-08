# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	caph
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/caphgame/${PORTNAME}/caphgame-${PORTVERSION}/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Physics-based sandbox game

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/doc/caph/COPYING

USE_BZIP2=	yes
USE_SDL=	sdl
USE_GL=		gl

BUILD_WRKSRC=	${WRKSRC}/src

PORTDOCS=	README CHANGELOG

DESKTOP_ENTRIES="Caph" \
		"Physics-based sandbox game" \
		"${DATADIR}/brush.png" \
		"caph" \
		"Game;LogicGame;" \
		false

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=OPTIMIZED_CFLAGS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math
.endif

do-build:
	cd ${BUILD_WRKSRC} && ${CC} ${CFLAGS} -o caph -I../include *.c \
		`${SDL_CONFIG} --libs --cflags` -D_OPENGL -lGL -lpng

post-patch:
	@${REINPLACE_CMD} -e 's|../share/caph|${DATADIR}|' ${BUILD_WRKSRC}/caph.c

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/share/caph && ${COPYTREE_SHARE} '*' ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc/caph && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
