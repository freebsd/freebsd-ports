# New ports collection makefile for:   lgeneral
# Date created:                27 Aug 2002
# Whom:                        Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	lgeneral
PORTVERSION=	1.1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lgeneral

MAINTAINER=	filippo@widestore.net

LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
