# ex:ts=8
# Ports collection makefile for:	eboxy
# Date created:			Sep 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	eboxy
PORTVERSION=	0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.bluelightning.org/ebox/files/eboxy/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libSDL_gui.a:${PORTSDIR}/x11-toolkits/sdl_gui
LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt \
		xml2:${PORTSDIR}/textproc/libxml2 \
		SDL-1.1:${PORTSDIR}/devel/sdl12 \
		SDL_ttf:${PORTSDIR}/graphics/sdl_ttf \
		SDL_image:${PORTSDIR}/graphics/sdl_image

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -lgnugetopt -lstdc++"

post-patch:
	@${GREP} -lR "malloc.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s|malloc.h|stdlib.h|g"

.include <bsd.port.mk>
