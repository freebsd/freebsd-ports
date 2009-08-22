# New ports collection makefile for:	blinkensisters
# Date created:		26 Mar 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	blinkensisters
PORTVERSION=	0.5.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Blinkensisters%20-%20Lost%20Pixels/LostPixels%20${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Parallax-style 2D scrolling platform game

USE_SDL=	sdl image ttf
USE_PERL5_BUILD=	yes
USE_CMAKE=	yes

CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/blinkensisters/lostpixels/game/software
ADDONS_WRKSRC=	${WRKDIR}/blinkensisters/lostpixels/game/addons

PORTDOCS=	*

OPTIONS=	ADDONS	"Install addons (~200 MB download size)" off \
		SDL_MIXER	"Build with sound support" on \
		SDL_NET	"Build with network support" on \
		THEORA	"Build with theora support" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if defined(WITH_ADDONS)
DISTNAME=	LostPixels-${PORTVERSION}-source-with-addons
PKGNAMESUFFIX=	-with-addons
PLIST_SUB+=	ADDONS=""
.else
DISTNAME=	LostPixels-${PORTVERSION}-source
PLIST_SUB+=	ADDONS="@comment "
.endif

.if defined(WITHOUT_SDL_MIXER)
CMAKE_ARGS+=	-DUSE_SDL_MIXER:BOOL=OFF
PLIST_SUB+=	SDL_MIXER="@comment "
.else
USE_SDL+=	mixer
PLIST_SUB+=	SDL_MIXER=""
.endif

.if defined(WITHOUT_SDL_NET)
CMAKE_ARGS+=	-DUSE_SDL_NET:BOOL=OFF
PLIST_SUB+=	SDL_NET="@comment "
.else
USE_SDL+=	net
PLIST_SUB+=	SDL_NET=""
.endif

.if defined(WITH_THEORA)
CMAKE_ARGS+=	-DUSE_THEORA:BOOL=ON
.else
LIB_DEPENDS+=	theora.0:${PORTSDIR}/multimedia/libtheora
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^INSTALL.*doc/ d' ${WRKSRC}/CMakeLists.txt
.endif
	@${REINPLACE_CMD} -e 's|share/blinkensisters|${DATADIR:S,${PREFIX}/,,}|; \
		s|share/doc/blinkensisters|${DOCSDIR:S,${PREFIX}/,,}|' \
		${WRKSRC}/CMakeLists.txt
.if defined(WITH_ADDONS)
	@${FIND} ${ADDONS_WRKSRC} -name "Makefile" | ${XARGS} \
		${REINPLACE_CMD} -e 's|bmfcompress|${WRKSRC}/&|'
.endif

.if defined(WITH_ADDONS)
post-build:
	cd ${ADDONS_WRKSRC} && ${MAKE}

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${ADDONS_WRKSRC}/for_upload/*.bmf ${DATADIR}
.endif

.include <bsd.port.post.mk>
