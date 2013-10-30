# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	caph
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/caphgame/${PORTNAME}/caphgame-${PORTVERSION}/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Physics-based sandbox game

LICENSE=	GPLv3

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png

USES=		iconv
USE_BZIP2=	yes
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
OPTIONS_DEFAULT=DOCS OPTIMIZED_CFLAGS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math
.endif

do-build:
	cd ${BUILD_WRKSRC} && ${CC} ${CFLAGS} -o caph -I../include *.c \
		`${SDL_CONFIG} --libs --cflags` -D_OPENGL -lGL -lpng ${ICONV_LIB}

post-patch:
	@${REINPLACE_CMD} -e 's|../share/caph|${DATADIR}|' ${BUILD_WRKSRC}/caph.c

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/share/caph && ${COPYTREE_SHARE} '*' ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/caph && ${INSTALL_DATA} README CHANGELOG ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
