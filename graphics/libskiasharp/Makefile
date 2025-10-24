PORTNAME=	libskiasharp
DISTVERSIONPREFIX=	v
DISTVERSION=	116
PORTREVISION=	2
PORTREPOCH=	1
CATEGORIES=	graphics

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Complete 2D graphic library for drawing Text, Geometries, and Images
WWW=		https://skia.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gn:devel/gn
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libwebp.so:graphics/webp

USES=		jpeg ninja python:build

USE_GITHUB=	yes
GH_ACCOUNT=	mono
GH_PROJECT=	skia
GH_TAGNAME=	c16e913577083761d847146db7a04b8d3b3bf755

USE_LDCONFIG=	yes
USE_BINUTILS=	yes

SOVERSION=	116.0.0

GN_ARGS=	is_official_build=true \
		skia_enable_tools=false \
		target_os="linux" \
		skia_use_icu=false \
		skia_use_sfntly=false \
		skia_use_piex=true \
		skia_use_harfbuzz=false \
		skia_use_wuffs=false \
		skia_use_system_expat=true \
		skia_use_system_libjpeg_turbo=true \
		skia_use_system_freetype2=true \
		skia_use_system_libpng=true \
		skia_use_system_libwebp=true \
		skia_use_system_zlib=true \
		skia_enable_gpu=true \
		ska_enable_ganesh=true \
		skia_enable_skottie=true \
		skia_enable_pdf=true \
		skia_use_dng_sdk=false \
		extra_cflags=[ \
		"-DSKIA_C_DLL", \
		"-I${LOCALBASE}/include", \
		"-I${LOCALBASE}/include/freetype2"] \
		extra_ldflags=["-L${LOCALBASE}/lib", \
		"-Wl,--version-script=${FILESDIR}/libskiasharp.map" ] \
		linux_soname_version="${SOVERSION}"

BINARY_ALIAS=	python3=${PYTHON_CMD} \
		ar=${LOCALBASE}/bin/ar

ALL_TARGET=	SkiaSharp
BUILD_WRKSRC=	${WRKSRC}/out

PLIST_FILES=	lib/libSkiaSharp.so \
		lib/libSkiaSharp.so.${SOVERSION}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} gn gen 'out' --args='${GN_ARGS}'

do-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/libSkiaSharp.so.${SOVERSION} \
		${STAGEDIR}${PREFIX}/lib
	${RLN} ${STAGEDIR}${PREFIX}/lib/libSkiaSharp.so.${SOVERSION} \
		${STAGEDIR}${PREFIX}/lib/libSkiaSharp.so

.include <bsd.port.mk>
