# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	wyrmgus
PORTVERSION=	3.5.4
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	games devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Modified Stratagus engine for Wyrmsun

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libtolua++-${LUA_VER}.so:lang/tolua++ \
		libogg.so:audio/libogg \
		liboaml.so:audio/oaml
BUILD_DEPENDS=	${LOCALBASE}/include/boost/tokenizer.hpp:devel/boost-libs

USE_GITHUB=     yes
GH_ACCOUNT=     Andrettin
GH_PROJECT=     Wyrmgus

USES=		cmake compiler:c++11-lib lua:51 pkgconfig sdl sqlite
USE_SDL=	sdl
CMAKE_ARGS=	-DGAMEDIR:STRING="bin" \
		-DTOLUA++_APP:STRING="tolua++-${LUA_VER}" \
		-DTOLUA++_INCLUDE_DIR:STRING="${LUA_INCDIR}" \
		-DTOLUA++_LIBRARY:STRING="${LUA_LIBDIR}/libtolua++.so" \
		-DENABLE_USEGAMEDIR:BOOL=OFF \
		-DWITH_MIKMOD:BOOL=OFF \
		-DWITH_THEORA:BOOL=OFF

PORTDOCS=	*

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/wyrmsun.ico

OPTIONS_DEFINE=	OPENGL DOCS
OPTIONS_DEFAULT=OPENGL

OPENGL_USES=		gl
OPENGL_USE=		GL=gl,glu
OPENGL_CMAKE_ON=	-DWITH_RENDERER="OpenGL"
OPENGL_CMAKE_OFF=	-DWITH_RENDERER="NativeSDL"

post-patch:
# fix debug build
	@${REINPLACE_CMD} -e 's|OAML_LIBRARIES_SHARED_DEBUG|OAML_LIBRARIES_SHARED|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/stratagus-dbg/ d' ${WRKSRC}/CMakeLists.txt

do-install:
	${INSTALL_PROGRAM} ${CONFIGURE_WRKSRC}/stratagus ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/win32/wyrmsun.ico ${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
