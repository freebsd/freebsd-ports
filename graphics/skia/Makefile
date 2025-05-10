PORTNAME=	skia
DISTVERSIONPREFIX=	chrome/m
DISTVERSION=	140
CATEGORIES=	graphics

MAINTAINER=	me@svmhdvn.name
COMMENT=	Complete 2D graphic library for drawing Text, Geometries, and Images
WWW=		https://skia.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gn:devel/gn \
		spirv-tools>0:graphics/spirv-tools
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libicuuc.so:devel/icu \
		libGL.so:graphics/libglvnd \
		libpng16.so:graphics/png \
		libwebp.so:graphics/webp

USES=		compiler:c++17-lang jpeg ninja python:build

USE_LDCONFIG=		yes
USE_GITHUB=		yes
GH_ACCOUNT=		google

# TODO port wuffs and add as dependency
GN_ARGS=	is_official_build=true \
		is_component_build=true \
		is_debug=false \
		target_os="linux" \
		skia_use_dng_sdk=false \
		skia_use_wuffs=false \
		extra_cflags=[ \
			"-I${LOCALBASE}/include", \
			"-I${LOCALBASE}/include/harfbuzz", \
			"-I${LOCALBASE}/include/freetype2"] \
		extra_ldflags=["-L${LOCALBASE}/lib"]

BINARY_ALIAS=	python3=${PYTHON_CMD} \
		ar=llvm-ar

BUILD_WRKSRC=	${WRKSRC}/out

SUB_FILES=	skia.pc
SUB_LIST=	SKIA_VERSION=${DISTVERSION}

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/BUILD.gn

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} gn gen out --args='${GN_ARGS}' && ${SETENV} ${CONFIGURE_ENV} gn ls out --args='${GN_ARGS}'

do-install:
	(cd ${BUILD_WRKSRC} && \
		ls -1 *.so | xargs -I% ${INSTALL_LIB} % ${STAGEDIR}${PREFIX}/lib/%.${DISTVERSION} && \
		ls -1 *.so | xargs -I% ${RLN} ${STAGEDIR}${PREFIX}/lib/%.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/%)
	${INSTALL_DATA} ${BUILD_WRKSRC}/*.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/skia.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/
	${MKDIR} ${STAGEDIR}${PREFIX}/include/skia/modules
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/skia '-name *.h')
	(cd ${WRKSRC}/modules && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/skia/modules '-name *.h')

.include <bsd.port.mk>
