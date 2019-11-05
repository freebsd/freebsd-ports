# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	caph
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/caphgame/${PORTNAME}/caphgame-${PORTVERSION}/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Physics-based sandbox game

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/doc/caph/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gl iconv sdl tar:bzip2
USE_SDL=	sdl
USE_GL=		gl

BUILD_WRKSRC=	${WRKSRC}/src

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*

DESKTOP_ENTRIES="Caph" \
		"Physics-based sandbox game" \
		"${DATADIR}/brush.png" \
		"caph" \
		"Game;LogicGame;" \
		false

OPTIONS_DEFINE=	DOCS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=OPTIMIZED_CFLAGS
OPTIMIZED_CFLAGS_CFLAGS=	-O3 -ffast-math

do-build:
	cd ${BUILD_WRKSRC} && ${CC} ${CFLAGS} -o caph -I../include *.c \
		`${SDL_CONFIG} --libs --cflags` -D_OPENGL -lGL -lpng -lm ${ICONV_LIB}

post-patch:
	@${REINPLACE_CMD} -e 's|../share/caph|${DATADIR}|' ${BUILD_WRKSRC}/caph.c

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/share/caph && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/caph && ${INSTALL_DATA} README CHANGELOG ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
