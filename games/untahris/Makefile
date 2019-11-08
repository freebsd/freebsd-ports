# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	untahris
PORTVERSION=	3.1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Play several classic fun, simple arcade games in multiplayer mode

USES=		dos2unix sdl
USE_SDL=	sdl net ttf mixer
DOS2UNIX_FILES=	intface.cpp
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|VeraBd.ttf|${DATADIR}/VeraBd.ttf|; \
		s|graph%d|${DATADIR}/&|; s|[a-z]*\.wav|${DATADIR}/&|' \
		${WRKSRC}/intface.cpp

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} `${SDL_CONFIG} --libs --cflags` \
		-lSDL_net -lSDL_ttf -lSDL_mixer untahris.cpp -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
.for f in VeraBd.ttf graph16*.unt *.wav
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}/
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
