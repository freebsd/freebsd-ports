# ex:ts=8
# Ports collection makefile for:	sdl_gfx
# Date created:			Apr 25, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sdl_gfx
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.ferzkopp.net/Software/SDL_gfx-${PORTVERSION:R}/
DISTNAME=	SDL_gfx-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	SDL-1.1:${PORTSDIR}/devel/sdl12

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
