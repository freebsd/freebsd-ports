# ex:ts=8
# Ports collection makefile for:	drumpiler
# Date created:			Jan 15, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	drumpiler
PORTVERSION=	0.9.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drum machine compiler

USE_REINPLACE=	yes
USE_SDL=	yes
CFLAGS+=	`${SDL_CONFIG} --cflags`
LIBS+=		`${SDL_CONFIG} --libs`
PLIST_FILES=	bin/drumpiler

post-patch:
	@${REINPLACE_CMD} -e "s|SDL.h|SDL11/SDL.h|" ${WRKSRC}/drumpiler.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -DUSESDL -o drumpiler drumpiler.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/drumpiler ${PREFIX}/bin

.include <bsd.port.mk>
