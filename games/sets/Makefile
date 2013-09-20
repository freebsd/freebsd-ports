# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	sets
PORTVERSION=	1.0.0
CATEGORIES=	games
MASTER_SITES=	http://www.linuxmotors.com/sets/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	This is an implementation of the sets game

LICENSE=	GPLv3

USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME}
USE_SDL=	sdl image

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

post-install:
# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
