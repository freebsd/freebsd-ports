PORTNAME=	einstein-newton
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.12.19
CATEGORIES=	emulators

MAINTAINER=	laurent@FreeBSD.org
COMMENT=	Apple Newton Emulator
WWW=		https://github.com/pguyot/Einstein

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libffi.so:devel/libffi \
		libfontconfig.so:x11-fonts/fontconfig \
		libpulse.so:audio/pulseaudio
TEST_DEPENDS=	googletest>=0:devel/googletest

USES=		bison cmake:testing compiler:c++17-lang llvm:build xorg

USE_GITHUB=	yes
GH_ACCOUNT=	pguyot
GH_PROJECT=	Einstein
GH_TUPLE=	fltk:fltk:release-1.4.4:fltk/fltk-src \
		MatthiasWM:NEWT64:d1a1aa1:newt64/newt64-src
USE_XORG=	ice sm x11 xcursor xext xfixes xinerama xft xrender

CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_Doxygen:BOOL=TRUE \
		-DCMAKE_DISABLE_FIND_PACKAGE_LATEX:BOOL=TRUE \
		-DCMAKE_DISABLE_FIND_PACKAGE_SDL3:BOOL=TRUE \
		-DFLTK_BACKEND_WAYLAND:BOOL=OFF \
		-DFLTK_GRAPHICS_CAIRO:BOOL=OFF \
		-DFLTK_OPTION_CAIRO_EXT:BOOL=OFF \
		-DFLTK_OPTION_CAIRO_WINDOW:BOOL=OFF \
		-DFLTK_USE_DBUS:BOOL=OFF \
		-DFLTK_USE_LIBDECOR_GTK:BOOL=OFF \
		-DFLTK_USE_PANGO:BOOL=OFF \
		-DFLTK_USE_SYSTEM_LIBJPEG:BOOL=TRUE \
		-DFLTK_USE_SYSTEM_LIBDECOR:BOOL=OFF \
		-DFLTK_USE_SYSTEM_LIBPNG:BOOL=TRUE \
		-DFLTK_USE_SYSTEM_ZLIB:BOOL=TRUE
CMAKE_OFF=	BUILD_TESTING EINSTEIN_FETCH_GTEST

ALL_TARGET=	Einstein

BINARY_ALIAS=	clang-format=clang-format${LLVM_DEFAULT}

EXTRACT_AFTER_ARGS=	--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/libffi* \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/portaudio

PLIST_FILES=	bin/Einstein

PORTDOCS=	*
OPTIONS_DEFINE=	DOCS

post-extract:
	${MKDIR} ${BUILD_WRKSRC}/_deps
	${RLN} ${WRKSRC_fltk}  ${BUILD_WRKSRC}/_deps/fltk-src
	${RLN} ${WRKSRC_newt64} ${BUILD_WRKSRC}/_deps/newt64-src

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/Einstein ${STAGEDIR}${PREFIX}/bin/Einstein

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/Documentation && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING=ON ${CMAKE_SOURCE_PATH} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} EinsteinTests && \
		${SETENVI} ${WRK_ENV} ${TEST_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
