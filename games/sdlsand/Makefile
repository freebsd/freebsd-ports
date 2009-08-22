# New ports collection makefile for:	sdlsand
# Date created:		22 Apr 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	sdlsand
PORTVERSION=	20061017
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simulation of falling sand and other materials

USE_ZIP=	yes
USE_SDL=	sdl

WRKSRC=		${WRKDIR}/SDL\ Sand/SDL\ Sand

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	readme.txt

post-patch:
	@${REINPLACE_CMD} -e '/crtdbg/ d' ${WRKSRC}/CmdLine.cpp

do-build:
	cd ${WRKSRC} && ${CXX} -o ${PORTNAME} ${CXXFLAGS} \
		`${SDL_CONFIG} --cflags --libs` main.cpp CmdLine.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
