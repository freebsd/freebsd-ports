# New ports collection makefile for:	gengameng
# Date created:			Apr 12, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	gengameng
PORTVERSION=	3.0
CATEGORIES=	devel
MASTER_SITES=	http://sites.netscape.net/sarrazip/

MAINTAINER=	markp@FreeBSD.org

LIB_DEPENDS=	SDL_image.10:${PORTSDIR}/graphics/sdl_image

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include" LDFLAGS="${LDFLAGS} -L${X11BASE}/lib"

pre-patch:
	${PERL} -pi -e "s|sdl-config|${SDL_CONFIG}|g; \
		s|include/SDL/|include/SDL11/|g" ${WRKSRC}/configure

post-configure:
	${PERL} -pi -e \
		"s/^deplibs_check_method=.*/deplibs_check_method=pass_all/" \
		${WRKSRC}/libtool

.include <bsd.port.mk>
