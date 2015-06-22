# $FreeBSD$

PORTNAME=	sdl2_image
PORTVERSION=	2.0.0
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/SDL_image/release/
DISTNAME=	SDL2_image-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Simple library to load images of various formats as SDL surfaces

LICENSE=	ZLIB

USES=		pkgconfig:build pathfix gmake libtool
USE_SDL=	sdl2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lm
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	JPEG PNG TIFF WEBP
OPTIONS_DEFAULT=JPEG PNG TIFF WEBP

JPEG_USES=		jpeg
JPEG_CONFIGURE_ENABLE=	jpg
PNG_LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png
PNG_CONFIGURE_ENABLE=	png
TIFF_LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff
TIFF_CONFIGURE_ENABLE=	tif
WEBP_LIB_DEPENDS=	libwebp.so:${PORTSDIR}/graphics/webp
WEBP_CONFIGURE_ENABLE=	webp

.include <bsd.port.mk>
