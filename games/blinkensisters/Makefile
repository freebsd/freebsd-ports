# New ports collection makefile for:	blinkensisters
# Date created:		26 Mar 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	blinkensisters
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	LostPixels-${PORTVERSION}-source

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Parallax-style 2D scrolling platform game

USE_SDL=	sdl image ttf
WRKSRC=		${WRKDIR}//blinkensisters/lostpixels/game/software
USE_CMAKE=	yes

CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include

OPTIONS=	SOUND	"Build with souns support" on \
		NETWORK	"Build with network support" on

.include <bsd.port.pre.mk>

post-patch:
.if defined(WITHOUT_SOUND)
	@${REINPLACE_CMD} -e '/FIND_PACKAGE.*SDL_mixer/ d' \
		${WRKSRC}/CMakeLists.txt
.endif

.if defined(WITHOUT_NETWORK)
	@${REINPLACE_CMD} -e '/FIND_PACKAGE.*SDL_net/ d' \
		${WRKSRC}/CMakeLists.txt
.endif

.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^INSTALL.*doc/ d' ${WRKSRC}/CMakeLists.txt
.endif

	@${REINPLACE_CMD} -e 's|share/blinkensisters|${DATADIR:S,${PREFIX}/,,}|; \
		s|share/doc/blinkensisters|${DOCSDIR:S,${PREFIX}/,,}|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.post.mk>
