# New Ports collection makefile for:	founts
# Date created:		2012-05-01
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	founts
PORTVERSION=	12
CATEGORIES=	graphics games
MASTER_SITES=	http://www.linuxmotors.com/founts/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	A demo/program inspired by Erics cascade

LICENSE=	GPLv2

USE_SDL=	sdl

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	Changelog README

.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} && ${CC} -o ${PORTNAME} ${CFLAGS} \
		-lm `${SDL_CONFIG} --cflags --libs` founts.c

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
