# New ports collection makefile for:	sdl_mixer
# Date created:		24 April 2000
# Whom:			Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl_mixer
PORTVERSION=	1.0.6
CATEGORIES=	audio
MASTER_SITES=	http://www.devolution.com/~slouken/SDL/projects/SDL_mixer/src/
DISTNAME=	SDL_mixer-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=  	SDL-1.1.2:${PORTSDIR}/devel/sdl-devel \
		smpeg.0:${PORTSDIR}/graphics/smpeg \
		mikmod.2:${PORTSDIR}/audio/libmikmod

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config

USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="-I${X11BASE}/include"

.include <bsd.port.mk>
