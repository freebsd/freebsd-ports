# New ports collection makefile for:	sdl_ttf
# Date created:				20 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl_ttf
PORTVERSION=	1.2.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.devolution.com/~slouken/SDL/projects/SDL_ttf/src/
DISTNAME=	SDL_ttf-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.2:${PORTSDIR}/devel/sdl-devel

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config

USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_FREETYPE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

post-extract:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|-release \$$\(LT_RELEASE\)||g'

post-configure:
	@${PERL} -pi -e 's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

.include <bsd.port.mk>
