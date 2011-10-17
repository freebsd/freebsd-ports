# New ports collection makefile for:	quantumminigolf
# Date created:		13 Sep 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	quantumminigolf
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A computer game visualizing quantum mechanics

LIB_DEPENDS=	fftw3f:${PORTSDIR}/math/fftw3-float \
		fftw3:${PORTSDIR}/math/fftw3

USE_GMAKE=	yes
USE_SDL=	sdl ttf
MAKE_ARGS=	CXX=${CXX}

PORTDOCS=	README THANKS

DESKTOP_ENTRIES="Quantum Minigolf" \
		"A game of minigolf where the ball obeys the laws of quantum mechanics" \
		"${DATADIR}/gfx/icon.bmp" \
		"quantumminigolf" \
		"Game;ArcadeGame;" \
		false

OPTIONS=	OCFLAGS	"Use optimized compiler flags" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OCFLAGS)
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
	${INSTALL_PROGRAM} ${WRKSRC}/quantumminigolf ${PREFIX}/bin
	${MKDIR} ${DATADIR}/gfx ${DATADIR}/fonts ${DATADIR}/tracks
	${INSTALL_DATA} ${WRKSRC}/gfx/*.bmp ${DATADIR}/gfx
	${INSTALL_DATA} ${WRKSRC}/fonts/*.ttf ${DATADIR}/fonts
	${INSTALL_DATA} ${WRKSRC}/tracks/*.bmp ${WRKSRC}/tracks/*.cfg \
		${DATADIR}/tracks

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
