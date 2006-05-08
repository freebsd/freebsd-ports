# New ports collection makefile for:	sdlsand
# Date created:		22 Apr 2006
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	sdlsand
PORTVERSION=	20060207
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	sldsand-src-${PORTVERSION}

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Simulation of falling sand and other materials

USE_ZIP=	yes
USE_SDL=	sdl

WRKSRC=		${WRKDIR}/${DISTNAME}/SDL\ Sand/SDL\ Sand

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	readme.txt

do-build:
	cd ${WRKSRC} && ${CXX} -o ${PORTNAME} ${CXXFLAGS} \
		`${SDL_CONFIG} --cflags --libs` main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
