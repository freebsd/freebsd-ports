# New ports collection makefile for:	vp
# Date created:			Apr 13, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	vp
PORTVERSION=	1.5
CATEGORIES=	graphics
MASTER_SITES=	http://math.smsu.edu/~erik/files/

MAINTAINER=	markp@FreeBSD.org

BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool
LIB_DEPENDS=	SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -lgnugetopt" \
		ac_cv_func_getopt_long=yes
MAN1=	vp.1

post-patch:
	@${PERL} -pi -e 's@ getopt_long/Makefile@@g' ${WRKSRC}/configure

.include <bsd.port.mk>
