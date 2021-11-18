# Created by: Travis Poppe <tlp@liquidx.org>

PORTNAME=	wyrmgus
PORTVERSION=	5.2.4
DISTVERSIONPREFIX=	v
CATEGORIES=	games devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Modified Stratagus engine for Wyrmsun

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtolua++-${LUA_VER}.so:lang/tolua++
BUILD_DEPENDS=	${LOCALBASE}/include/boost/tokenizer.hpp:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	Andrettin
GH_PROJECT=	Wyrmgus

USES=		cmake compiler:c++17-lang lua:51 pkgconfig sdl sqlite qt:5 xorg
USE_QT=		core gui widgets multimedia location \
		quickcontrols quickcontrols2 graphicaleffects \
		qmake_build buildtools_build
USE_XORG=	x11
USE_SDL=	sdl2 mixer2
CMAKE_ARGS=	-DGAMEDIR:STRING="bin" \
		-DTOLUA++_APP:STRING="tolua++-${LUA_VER}" \
		-DTOLUA++_INCLUDE_DIR:STRING="${LUA_INCDIR}" \
		-DTOLUA++_LIBRARY:STRING="${LUA_LIBDIR}/libtolua++.so" \
		-DENABLE_USEGAMEDIR:BOOL=OFF

PORTDOCS=	*

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/wyrmsun.ico

OPTIONS_DEFINE=	OPENGL DOCS
OPTIONS_DEFAULT=OPENGL

OPENGL_USES=		gl
OPENGL_USE=		GL=gl,glu
OPENGL_CMAKE_ON=	-DWITH_RENDERER="OpenGL"
OPENGL_CMAKE_OFF=	-DWITH_RENDERER="NativeSDL"

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/win32/wyrmsun.ico ${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
