# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	untahris
PORTVERSION=	3.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Play several classic fun, simple arcade games in multiplayer mode

USE_SDL=	sdl net ttf mixer
USE_DOS2UNIX=	intface.cpp
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|VeraBd.ttf|${DATADIR}/VeraBd.ttf|; \
		s|graph%d|${DATADIR}/&|; s|[a-z]*\.wav|${DATADIR}/&|' \
		${WRKSRC}/intface.cpp

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} `${SDL_CONFIG} --libs --cflags` \
		-lSDL_net -lSDL_ttf -lSDL_mixer untahris.cpp -o untahris

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/untahris ${PREFIX}/bin/
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
.for f in VeraBd.ttf graph16*.unt *.wav
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}/
.endfor
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}/
.endif

.include <bsd.port.mk>
