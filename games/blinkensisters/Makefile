# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	blinkensisters
PORTVERSION=	0.5.3
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Blinkensisters%20-%20Lost%20Pixels/LostPixels%20${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Parallax-style 2D scrolling platform game

USE_SDL=	sdl image ttf
USE_PERL5_BUILD=	yes
USES=		cmake

CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/blinkensisters/lostpixels/game/software
ADDONS_WRKSRC=	${WRKDIR}/blinkensisters/lostpixels/game/addons

PORTDOCS=	*

OPTIONS_DEFINE=	ADDONS SDL_MIXER SDL_NET THEORA
ADDONS_DESC=	Install addons (~200 MB download size)
SDL_MIXER_DESC=	Build with sound support
SDL_NET_DESC=	Build with network support

OPTIONS_DEFAULT=	SDL_MIXER SDL_NET

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${PORT_OPTIONS:MADDONS}
DISTNAME=	LostPixels-${PORTVERSION}-source-with-addons
PKGNAMESUFFIX=	-with-addons
PLIST_SUB+=	ADDONS=""
.else
DISTNAME=	LostPixels-${PORTVERSION}-source
PLIST_SUB+=	ADDONS="@comment "
.endif

.if ${PORT_OPTIONS:MSDL_MIXER}
USE_SDL+=	mixer
PLIST_SUB+=	SDL_MIXER=""
.else
CMAKE_ARGS+=	-DUSE_SDL_MIXER:BOOL=OFF
PLIST_SUB+=	SDL_MIXER="@comment "
.endif

.if ${PORT_OPTIONS:MSDL_NET}
USE_SDL+=	net
PLIST_SUB+=	SDL_NET=""
.else
CMAKE_ARGS+=	-DUSE_SDL_NET:BOOL=OFF
PLIST_SUB+=	SDL_NET="@comment "
.endif

.if ${PORT_OPTIONS:MTHEORA}
CMAKE_ARGS+=	-DUSE_THEORA:BOOL=ON
.else
LIB_DEPENDS+=	theora:${PORTSDIR}/multimedia/libtheora
.endif

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^INSTALL.*doc/ d' ${WRKSRC}/CMakeLists.txt
.endif
	@${REINPLACE_CMD} -e 's|share/blinkensisters|${DATADIR:S,${PREFIX}/,,}|; \
		s|share/doc/blinkensisters|${DOCSDIR:S,${PREFIX}/,,}|' \
		${WRKSRC}/CMakeLists.txt
.if ${PORT_OPTIONS:MADDONS}
	@${FIND} ${ADDONS_WRKSRC} -name "Makefile" | ${XARGS} \
		${REINPLACE_CMD} -e 's|bmfcompress|${WRKSRC}/&|'
.endif

.if ${PORT_OPTIONS:MADDONS}
post-build:
	cd ${ADDONS_WRKSRC} && ${MAKE}

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${ADDONS_WRKSRC}/for_upload/*.bmf ${DATADIR}
.endif

.include <bsd.port.mk>
