# New Ports collection makefile for:	sets
# Date created:		2012-04-21
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

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

PLIST_FILES=	bin/sets

PORTDOCS=	README

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

post-install:
# Documentation
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
