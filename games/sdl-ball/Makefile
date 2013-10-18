# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl-ball
PORTVERSION=	1.01
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Arkanoid/Breakout clone with pretty graphics

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gmake
USE_BZIP2=	yes
USE_SDL=	sdl mixer image ttf
USE_GL=		gl glu
MAKE_ENV=	DATADIR=${DATADIR}/
USE_DOS2UNIX=	main.cpp

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} `${SDL_CONFIG} --cflags --libs` \
		-lGL -lGLU -lSDL_image -lSDL_ttf -lSDL_mixer \
		-DDATADIR="\"${DATADIR}/\"" main.cpp -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/themes && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
