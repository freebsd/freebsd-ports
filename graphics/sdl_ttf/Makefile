# New ports collection makefile for:	sdl_ttf
# Date created:				20 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl_ttf
PORTVERSION=	2.0.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/SDL_ttf/release/
DISTNAME=	SDL_ttf-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	SDL-1.1.3:${PORTSDIR}/devel/sdl12 \
		freetype.8:${PORTSDIR}/print/freetype2

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config

USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include/freetype2 \
			  -I${LOCALBASE}/include"

post-extract:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|-release \$$\(LT_RELEASE\)||g'

post-configure:
	@${PERL} -pi -e 's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

.include <bsd.port.mk>
