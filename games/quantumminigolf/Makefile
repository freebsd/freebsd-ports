# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	quantumminigolf
PORTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A computer game visualizing quantum mechanics

LIB_DEPENDS=	libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libfftw3.so:${PORTSDIR}/math/fftw3

USES=		gmake
USE_SDL=	sdl ttf

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README THANKS
PORTDATA=	*

DESKTOP_ENTRIES="Quantum Minigolf" \
		"A game of minigolf where the ball obeys the laws of quantum mechanics" \
		"${DATADIR}/gfx/icon.bmp" \
		"quantumminigolf" \
		"Game;ArcadeGame;" \
		false

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DOCS
OPTIONS_DEFAULT=OPTIMIZED_CFLAGS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CXXFLAGS+=	-O3 -fomit-frame-pointer -finline-functions -funroll-all-loops
.	if ${ARCH} == "i386"
CXXFLAGS+=	-malign-double
.	endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gfx/|${DATADIR}/&|' ${WRKSRC}/Renderer.cpp
	@${REINPLACE_CMD} -e 's|fonts/|${DATADIR}/&|' ${WRKSRC}/Renderer.cpp
	@${REINPLACE_CMD} -e 's|tracks/|${DATADIR}/&|' ${WRKSRC}/TrackSelector.cpp
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/QuantumSimulator.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quantumminigolf ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/gfx ${STAGEDIR}${DATADIR}/fonts \
		${STAGEDIR}${DATADIR}/tracks
	${INSTALL_DATA} ${WRKSRC}/gfx/*.bmp ${STAGEDIR}${DATADIR}/gfx
	${INSTALL_DATA} ${WRKSRC}/fonts/*.ttf ${STAGEDIR}${DATADIR}/fonts
	${INSTALL_DATA} ${WRKSRC}/tracks/*.bmp ${WRKSRC}/tracks/*.cfg \
		${STAGEDIR}${DATADIR}/tracks

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
