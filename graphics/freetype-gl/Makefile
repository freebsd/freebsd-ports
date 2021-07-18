PORTNAME=	freetype-gl
DISTVERSION=	g20210208
PORTREVISION=	3
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	a38359cdcd97bfcf5d02dd65c66f516eac8208ad.patch:-p1 # https://github.com/rougier/freetype-gl/pull/233: Remove the STATIC requirement from the library
PATCHFILES+=	00a13d4c9e31f9c4e68e8ab30e2f7ec5b0e4bf60.patch:-p1 # https://github.com/rougier/freetype-gl/pull/235: Fix Fontconfig dependency name in demos

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C OpenGL Freetype engine library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2
TEST_DEPENDS=	ImageMagick${IMAGEMAGICK_DEFAULT}-nox11>0:graphics/ImageMagick${IMAGEMAGICK_DEFAULT}-nox11

USES=		cmake:noninja gl
USE_GL=		glew
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rougier
GH_TAGNAME=	647b062

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	freetype-gl_BUILD_APIDOC freetype-gl_BUILD_TESTS

LDFLAGS+=	-L${LOCALBASE}/lib -lGLEW -lfreetype # https://github.com/rougier/freetype-gl/issues/236

OPTIONS_DEFINE=		DEMOS
OPTIONS_SUB=		yes

DEMOS_DESC=		Build and install demo programs
DEMOS_USE=		GL=gl,glu
DEMOS_CMAKE_BOOL=	freetype-gl_BUILD_DEMOS
DEMOS_LIB_DEPENDS=	libAntTweakBar.so:graphics/anttweakbar \
			libfontconfig.so:x11-fonts/fontconfig \
			libglfw.so:graphics/glfw

post-patch-DEMOS-on:
	@${REINPLACE_CMD} -i '' 's|"data/|"${DATADIR}/data/|g ; s|"fonts/|"${DATADIR}/fonts/|g ; s|"shaders/|"${DATADIR}/shaders/|g' ${WRKSRC}/demos/*.c

do-test: # build breaks: https://github.com/rougier/freetype-gl/issues/234
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -Dfreetype-gl_BUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

do-install-DEMOS-on:
.for e in ansi atb-agg benchmark cartoon console cube distance-field distance-field-2 distance-field-3 embedded-font font gamma glyph lcd markup outline subpixel texture
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/demos/${e} ${STAGEDIR}${PREFIX}/bin/ftgl-demo-${e}
.endfor
	cd ${BUILD_WRKSRC}/demos && ${COPYTREE_SHARE} "data fonts shaders" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
