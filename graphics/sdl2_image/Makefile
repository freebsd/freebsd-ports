# $FreeBSD$

PORTNAME=	sdl2_image
PORTVERSION=	2.0.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/SDL_image/release/
DISTNAME=	SDL2_image-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple library to load images of various formats as SDL surfaces

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		gmake libtool localbase pkgconfig pathfix sdl
USE_SDL=	sdl2
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

post-extract:
	@${RM} -rf ${WRKSRC}/external

.include <bsd.port.mk>
