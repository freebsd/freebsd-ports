# Created by: ijliao
# $FreeBSD$

PORTNAME=	drumpiler
PORTVERSION=	0.9.0
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drum machine compiler

NO_STAGE=	yes
USE_SDL=	sdl
CFLAGS+=	`${SDL_CONFIG} --cflags` -Wno-return-type
LIBS+=		`${SDL_CONFIG} --libs`
PLIST_FILES=	bin/drumpiler

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -DUSESDL -o drumpiler drumpiler.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/drumpiler ${PREFIX}/bin

.include <bsd.port.mk>
