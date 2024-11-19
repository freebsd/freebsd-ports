PORTNAME=	libskiasharp
DISTVERSIONPREFIX=	v
DISTVERSION=	2.88.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	LOCAL/bapt:libjpeg_turbo
DISTFILES=	libjpeg_turbo-${LIBJPEG_TURBO_REV}.tar.gz:libjpeg_turbo

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

LIBJPEG_TURBO_REV=	22f1a22c99e9dde8cd3c72ead333f425c5a7aa77

USE_LDCONFIG=	yes
USE_BINUTILS=	yes

SOVERSION=	118.0.0
#
# see https://github.com/libjpeg-turbo/libjpeg-turbo/issues/795#issuecomment-2484148592
GN_ARGS=	is_official_build=true \
		skia_enable_tools=false \
		target_os="linux" \
		skia_use_icu=false \
		skia_use_sfntly=false \
		skia_use_piex=true \
		skia_use_harfbuzz=false \
		skia_use_system_expat=true \
		skia_use_system_libjpeg_turbo=false \
		skia_use_system_freetype2=true \
		skia_use_system_libpng=true \
		skia_use_system_libwebp=true \
		skia_use_system_zlib=true \
		skia_enable_gpu=true \
		skia_enable_skottie=true \
		skia_enable_pdf=true \
		skia_use_dng_sdk=false \
		extra_cflags=[ \
		"-DSKIA_C_DLL", \
		"-I${LOCALBASE}/include", \
		"-I${LOCALBASE}/include/freetype2"] \
		extra_ldflags=["-L${LOCALBASE}/lib"] \
		linux_soname_version="${SOVERSION}"

BINARY_ALIAS=	python=${PYTHON_CMD} \
		ar=${LOCALBASE}/bin/ar

ALL_TARGET=	SkiaSharp
BUILD_WRKSRC=	${WRKSRC}/out

PLIST_FILES=	lib/libSkiaSharp.so \
		lib/libSkiaSharp.so.${SOVERSION}

post-extract:
	${MKDIR} ${WRKSRC}/third_party/externals
	${RLN} ${WRKDIR}/libjpeg_turbo ${WRKSRC}/third_party/externals/libjpeg-turbo

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} gn gen 'out' --args='${GN_ARGS}'

do-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/libSkiaSharp.so.${SOVERSION} \
		${STAGEDIR}${PREFIX}/lib
	${RLN} ${STAGEDIR}${PREFIX}/lib/libSkiaSharp.so.${SOVERSION} \
		${STAGEDIR}${PREFIX}/lib/libSkiaSharp.so

.include <bsd.port.mk>
