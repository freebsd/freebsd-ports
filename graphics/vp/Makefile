# New ports collection makefile for:	vp
# Date created:			Apr 13, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	vp
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://math.smsu.edu/~erik/files/

MAINTAINER=	markp@FreeBSD.org
COMMENT=	An image viewer for X

LIB_DEPENDS=	SDL_image.10:${PORTSDIR}/graphics/sdl_image

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
USE_GETOPT_LONG=yes
USE_LIBTOOL=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		SDL_CONFIG="${SDL_CONFIG}" \
		ac_cv_func_getopt_long=yes
USE_REINPLACE=	yes
MAN1=		vp.1

post-patch:
	${REINPLACE_CMD} 's@ getopt_long/Makefile@@g' ${WRKSRC}/configure

.include <bsd.port.mk>
