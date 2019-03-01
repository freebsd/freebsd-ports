# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl_image
PORTVERSION=	1.2.12
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/SDL_image/release/
DISTNAME=	SDL_image-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple library to load images of various formats as SDL surfaces

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool localbase pkgconfig pathfix sdl
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-jpg-shared --disable-png-shared \
		--disable-tif-shared --disable-webp-shared
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	JPEG PNG TIFF WEBP
OPTIONS_DEFAULT=JPEG PNG TIFF WEBP

JPEG_USES=		jpeg
JPEG_CONFIGURE_ENABLE=	jpg
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_ENABLE=	png
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_ENABLE=	tif
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CONFIGURE_ENABLE=	webp

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/showimage ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
