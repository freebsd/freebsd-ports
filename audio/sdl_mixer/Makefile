# New ports collection makefile for:	sdl_mixer
# Date created:				24 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl_mixer
PORTVERSION=	1.2.1
CATEGORIES=	audio
MASTER_SITES=	http://www.libsdl.org/projects/SDL_mixer/release/
DISTNAME=	SDL_mixer-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=  	SDL-1.1.3:${PORTSDIR}/devel/sdl12 \
		smpeg.1:${PORTSDIR}/graphics/smpeg \
		vorbis.1:${PORTSDIR}/audio/libvorbis

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config

USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="-I${X11BASE}/include"

post-configure:
	@${PERL} -pi -e 's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

.include <bsd.port.mk>
