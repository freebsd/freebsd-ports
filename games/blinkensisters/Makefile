# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	blinkensisters
PORTVERSION=	0.5.3
PORTREVISION=	17
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Blinkensisters%20-%20Lost%20Pixels/LostPixels%20${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Parallax-style 2D scrolling platform game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/DOC/LICENSE

BROKEN_sparc64=	does not compile on sparc64

# actually, old gcc fails in theora.h
USES=		cmake:insource compiler:c++11-lang localbase perl5 sdl
USE_SDL=	sdl image ttf
USE_PERL5=	build

CXXFLAGS+=	-Wno-c++11-narrowing

WRKSRC=		${WRKDIR}/blinkensisters/lostpixels/game/software
ADDONS_WRKSRC=	${WRKDIR}/blinkensisters/lostpixels/game/addons

PLIST_FILES=	bin/LostPixels \
		bin/bmfcompress \
		bin/bmfdecompress
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	ADDONS SDL_MIXER SDL_NET THEORA DOCS
OPTIONS_DEFAULT=ADDONS SDL_MIXER SDL_NET THEORA

ADDONS_DESC=	Install addons (~200 MB download size)
SDL_MIXER_DESC=	Build with sound support
SDL_NET_DESC=	Build with network support

SDL_MIXER_USE=		SDL=mixer
SDL_MIXER_CMAKE_OFF=	-DUSE_SDL_MIXER:BOOL=OFF
SDL_MIXER_PLIST_FILES=	bin/BlinkenPlayer

SDL_NET_USE=		SDL=net
SDL_NET_CMAKE_OFF=	-DUSE_SDL_NET:BOOL=OFF
SDL_NET_PLIST_FILES=	bin/blpmatrix \
			bin/blpviewer \
			bin/bxxviewer \
			bin/mcufviewer

THEORA_CMAKE_ON=	-DUSE_THEORA:BOOL=ON
THEORA_LIB_DEPENDS=	libtheora.so:multimedia/libtheora

ADDONS_VARS=		DISTNAME=LostPixels-${PORTVERSION}-source-with-addons \
			PKGNAMESUFFIX=-with-addons
ADDONS_VARS_OFF=	DISTNAME=LostPixels-${PORTVERSION}-source

post-patch:
	@${REINPLACE_CMD} -e 's|share/blinkensisters|${DATADIR_REL}|; \
		s|share/doc/blinkensisters|${DOCSDIR_REL}|' \
		${WRKSRC}/CMakeLists.txt

post-patch-ADDONS-on:
	@${FIND} ${ADDONS_WRKSRC} -name "Makefile" | ${XARGS} \
		${REINPLACE_CMD} -e 's|bmfcompress|${WRKSRC}/&|'

post-build-ADDONS-on:
	cd ${ADDONS_WRKSRC} && ${MAKE}

post-install-ADDONS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${ADDONS_WRKSRC}/for_upload/*.bmf ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
