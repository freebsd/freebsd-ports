# ex:ts=8
# Ports collection makefile for:	eboxy
# Date created:			Sep 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	eboxy
PORTVERSION=	0.3.3
PORTCOMMENT=	Create simple GUI interfaces for entertainment PC
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.bluelightning.org/ebox/files/eboxy/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libSDL_gui.so:${PORTSDIR}/x11-toolkits/sdl_gui
LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		SDL_ttf.3:${PORTSDIR}/graphics/sdl_ttf \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		xml2.5:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	${LOCALBASE}/lib/libSDL_gui.so:${PORTSDIR}/x11-toolkits/sdl_gui

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}"  LDFLAGS="${LDFLAGS}" \
		SDL_CONFIG="${SDL_CONFIG}"
CONFIGURE_ARGS=	--disable-lirc

CPPFLAGS=	`${SDL_CONFIG} --cflags` -I${LOCALBASE}/include
LDFLAGS=	`${SDL_CONFIG} --libs` -L${LOCALBASE}/lib -lgnugetopt

post-patch:
	@${GREP} -lR "malloc.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s|malloc.h|stdlib.h|g"
	@${REINPLACE_CMD} -e 's|sdl-config |\$$\{SDL_CONFIG\} |g' \
		${WRKSRC}/plugins/simplemusic/Makefile.in

.include <bsd.port.mk>
