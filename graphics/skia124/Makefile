PORTNAME=	skia
DISTVERSIONPREFIX=	m
DISTVERSION=	124
DISTVERSIONSUFFIX=	-08a5439a6b
CATEGORIES=	graphics
PKGNAMESUFFIX=	124

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Skia library fork used by aseprite and laf
WWW=		https://github.com/aseprite/skia

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gn:devel/gn
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz \
		libicuuc.so:devel/icu \
		libpng16.so:graphics/png \
		libwebp.so:graphics/webp

USES=		compiler:c++17-lang jpeg ninja python:build

USE_GITHUB=	yes
GH_ACCOUNT=	aseprite
GH_PROJECT=	skia

GN_ARGS=	is_debug=false \
		is_official_build=true \
		skia_use_system_expat=true \
		skia_use_system_icu=true \
		skia_use_system_libjpeg_turbo=true \
		skia_use_system_libpng=true \
		skia_use_system_libwebp=true \
		skia_use_libwebp_decode=false \
		skia_use_libwebp_encode=false \
		skia_use_system_zlib=true \
		skia_use_freetype=true \
		skia_use_harfbuzz=true \
		skia_pdf_subset_harfbuzz=true \
		skia_use_system_freetype2=true \
		skia_use_system_harfbuzz=true \
		skia_use_dng_sdk=false \
		skia_use_wuffs=false \
		skia_use_libavif=false \
		extra_cflags=["-I${LOCALBASE}/include","-I${LOCALBASE}/include/harfbuzz","-I${LOCALBASE}/include/freetype2"] \
		extra_ldflags=["-L${LOCALBASE}/lib"]

BUILD_WRKSRC=	${WRKSRC}/out

ALL_TARGET=	skia modules

post-extract: # BINARY_ALIAS doesn't work in this case
	${MKDIR} ${WRKDIR}/.bin
	${LN} -sf ${PYTHON_CMD} ${WRKDIR}/.bin/python3

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} PATH=${WRKDIR}/.bin:${PATH} ${LOCALBASE}/bin/gn gen out --args='${GN_ARGS}'

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/aseprite-skia
	${INSTALL_DATA} ${BUILD_WRKSRC}/*.a ${STAGEDIR}${PREFIX}/lib/aseprite-skia/
	${MKDIR} ${STAGEDIR}${PREFIX}/include/aseprite-skia/include
	${MKDIR} ${STAGEDIR}${PREFIX}/include/aseprite-skia/modules
	${MKDIR} ${STAGEDIR}${PREFIX}/include/aseprite-skia/src
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/aseprite-skia/include '-name *.h')
	(cd ${WRKSRC}/modules && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/aseprite-skia/modules '-name *.h')
	(cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/aseprite-skia/src '-name *.h')

.include <bsd.port.mk>
