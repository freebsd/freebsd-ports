# New ports collection makefile for:	gengameng
# Date created:			Apr 12, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	gengameng
PORTVERSION=	4.1
PORTREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	http://ftp.osuosl.org/pub/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An SDL game engine library

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_AUTOTOOLS=	libtool
USE_SDL=	image sdl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=	--program-prefix=""
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

post-patch:
	${REINPLACE_CMD} -e "s|sdl-config|${SDL_CONFIG}|g; \
		s|^function ||g" ${WRKSRC}/gengameng-config.in
	${REINPLACE_CMD} -e "s/sdl_image.m4//" ${WRKSRC}/macros/Makefile.in

.include <bsd.port.mk>
