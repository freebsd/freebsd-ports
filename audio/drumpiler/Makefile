# ex:ts=8
# Ports collection makefile for:	drumpiler
# Date created:			Jan 15, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	drumpiler
PORTVERSION=	0.9.0
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drum machine compiler

USE_SDL=	sdl
CFLAGS+=	`${SDL_CONFIG} --cflags`
LIBS+=		`${SDL_CONFIG} --libs`
PLIST_FILES=	bin/drumpiler

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -DUSESDL -o drumpiler drumpiler.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/drumpiler ${PREFIX}/bin

.include <bsd.port.mk>
