# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	sdlsand
PORTVERSION=	20061017
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simulation of falling sand and other materials

USES=		dos2unix sdl zip
DOS2UNIX_FILES=	CmdLine.cpp
USE_SDL=	sdl

WRKSRC=		${WRKDIR}/SDL\ Sand/SDL\ Sand

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/crtdbg/ d' ${WRKSRC}/CmdLine.cpp

do-build:
	cd ${WRKSRC} && ${CXX} -o ${PORTNAME} ${CXXFLAGS} \
		`${SDL_CONFIG} --cflags --libs` main.cpp CmdLine.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
