# New ports collection makefile for:	iview
# Date created:			Apr 13, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	iview
PORTVERSION=	1.01
CATEGORIES=	graphics
MASTER_SITES=	http://math.smsu.edu/~erik/files/

MAINTAINER=	mark@kyne.com.au

LIB_DEPENDS=	SDL_image.10:${PORTSDIR}/graphics/sdl_image

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" CPPFLAGS="-I${LOCALBASE}/include"

MAN1=	iview.1

.include <bsd.port.mk>
