# New ports collection makefile for:	sdl_image
# Date created:				20 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl_image
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/SDL_image/release/
DISTNAME=	SDL_image-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple library to load images of various formats as SDL surfaces

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_SDL=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lm"
CONFIGURE_ARGS=	--enable-tif --enable-xcf
MAKE_ARGS=	LT_CURRENT=10 LT_REVISION=0 LT_AGE=0
INSTALLS_SHLIB=	yes

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/showimage ${PREFIX}/bin

.include <bsd.port.mk>
