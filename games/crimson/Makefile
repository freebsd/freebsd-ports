# New ports collection makefile for:	crimson
# Date created:				3 May 2001
# Whom:					Jan Jungnickel <jan@jungnickel.com>
#
# $FreeBSD$

PORTNAME=	crimson
PORTVERSION=	0.3.5
CATEGORIES=	games
MASTER_SITES=	http://crimson.seul.org/files/
PKGNAMESUFFIX=	-fields
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	Jan.Stocker@t-online.de
COMMENT=	Tactical war game in the tradition of Battle Isle

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

USE_BZIP2=	yes
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"
USE_GMAKE=	yes

MAN6=	crimson.6

.include <bsd.port.mk>
