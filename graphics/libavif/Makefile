PORTNAME=	libavif
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Library for encoding and decoding .avif files
WWW=		https://github.com/AOMediaCodec/libavif

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png
TEST_DEPENDS=	googletest>0:devel/googletest \
		bash:shells/bash

USES=		cmake:testing compiler:c11 cpe jpeg pkgconfig
CPE_VENDOR=	aomedia
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	AOMediaCodec
CMAKE_ON=	AVIF_BUILD_APPS
CMAKE_TESTING_ON=	AVIF_BUILD_TESTS

OPTIONS_DEFINE=	AOM DAV1D GAV1 LIBSHARPYUV LIBYUV PIXBUF RAV1E SVTAV1
OPTIONS_DEFAULT=AOM DAV1D PIXBUF
OPTIONS_SUB=	yes

AOM_DESC=		AV1 encoding/decoding via libaom
AOM_LIB_DEPENDS=	libaom.so:multimedia/aom
AOM_CMAKE_BOOL=		AVIF_CODEC_AOM

DAV1D_DESC=		AV1 decoding via libdav1d
DAV1D_LIB_DEPENDS=	libdav1d.so:multimedia/dav1d
DAV1D_CMAKE_BOOL=	AVIF_CODEC_DAV1D

GAV1_DESC=		AV1 decoding via libgav1
GAV1_LIB_DEPENDS=	libgav1.so:multimedia/libgav1
GAV1_CMAKE_BOOL=	AVIF_CODEC_LIBGAV1

LIBSHARPYUV_DESC=		Colorspace conversion via libsharpyuv
LIBSHARPYUV_LIB_DEPENDS=	libsharpyuv.so:graphics/webp
LIBSHARPYUV_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_libsharpyuv

LIBYUV_DESC=		Colorspace conversion via libyuv
LIBYUV_BUILD_DEPENDS=	libyuv>=0.0.1774:graphics/libyuv
LIBYUV_LIB_DEPENDS=	libyuv.so:graphics/libyuv
LIBYUV_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_libyuv

PIXBUF_USES=		gnome
PIXBUF_USE=		GNOME=gdkpixbuf2
PIXBUF_CMAKE_BOOL=	AVIF_BUILD_GDK_PIXBUF

RAV1E_DESC=		AV1 encoding via librav1e
RAV1E_LIB_DEPENDS=	librav1e.so:multimedia/librav1e
RAV1E_CMAKE_BOOL=	AVIF_CODEC_RAV1E

SVTAV1_DESC=		AV1 encoding via SVT-AV1
SVTAV1_LIB_DEPENDS=	libSvtAv1Enc.so:multimedia/svt-av1
SVTAV1_CMAKE_BOOL=	AVIF_CODEC_SVT

.include <bsd.port.mk>
