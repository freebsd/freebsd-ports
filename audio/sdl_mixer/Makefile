# New ports collection makefile for:	sdl_mixer
# Date created:		24 Aprim 2000
# Whom:			Maxim Sobolev <sobomax@altavista.net>
#
# $FreeBSD$
#

PORTNAME=	sdl_mixer
PORTVERSION=	1.0.5
CATEGORIES=	audio
MASTER_SITES=	http://www.devolution.com/~slouken/SDL/projects/SDL_mixer/src/
DISTNAME=	SDL_mixer-${PORTVERSION}

MAINTAINER=	sobomax@altavista.net

LIB_DEPENDS=  	SDL-1.1.2:${PORTSDIR}/devel/sdl-devel \
		smpeg-0.3.0:${PORTSDIR}/graphics/smpeg \
		mikmod.2:${PORTSDIR}/audio/libmikmod

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="-I${X11BASE}/include"

.include <bsd.port.mk>
