# New ports collection makefile for:	sdl_ttf
# Date created:				20 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl_ttf
PORTVERSION=	2.0.6
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/SDL_ttf/release/
DISTNAME=	SDL_ttf-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library to use TrueType fonts to render text in SDL applications

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_SDL=	yes
USE_GL=		yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS=	LT_CURRENT=3 LT_REVISION=0 LT_AGE=0
INSTALLS_SHLIB=	yes

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/glfont ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/showfont ${PREFIX}/bin

.include <bsd.port.mk>
