# New ports collection makefile for:	gengameng
# Date created:			Apr 12, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	gengameng
PORTVERSION=	4.1
CATEGORIES=	devel
MASTER_SITES=	http://www3.sympatico.ca/sarrazip/dev/

MAINTAINER=	markp@FreeBSD.org

LIB_DEPENDS=	SDL_image.10:${PORTSDIR}/graphics/sdl_image
RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash2

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ARGS+=	--program-prefix=""
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include" \
		LDFLAGS="${LDFLAGS} -L${X11BASE}/lib" \
		SDL_CONFIG="${SDL_CONFIG}"

post-patch:
	${REINPLACE_CMD} -e "s|sdl-config|${SDL_CONFIG}|g; \
		s|/bin/sh|/usr/local/bin/bash|g" ${WRKSRC}/gengameng-config.in
	${REINPLACE_CMD} -e "s/sdl_image.m4//" ${WRKSRC}/macros/Makefile.in

.include <bsd.port.mk>
