PORTNAME=	corsixth
DISTVERSIONPREFIX=	v
DISTVERSION=	0.69.0
CATEGORIES=	games

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open source clone of Theme Hospital
WWW=		https://github.com/CorsixTH/CorsixTH

LICENSE=	MIT

LIB_DEPENDS=	libfreetype.so:print/freetype2
RUN_DEPENDS=	${LUA_REFMODLIBDIR}/lfs.so:devel/luafilesystem@${LUA_FLAVOR} \
		${LUA_REFMODLIBDIR}/lpeg.so:devel/lua-lpeg@${LUA_FLAVOR}

USES=		cmake:insource compiler:c++11-lib desktop-file-utils dos2unix \
		iconv lua pkgconfig sdl
DOS2UNIX_FILES=	CMake/FindFFmpeg.cmake \
		CorsixTH/CMakeLists.txt \
		CorsixTH/Src/iso_fs.cpp
USE_GITHUB=	yes
GH_ACCOUNT=	CorsixTH
GH_PROJECT=	CorsixTH
USE_SDL=	mixer2
CMAKE_ARGS=	-DWITH_LUAJIT=OFF \
		-DWITH_UPDATE_CHECK=OFF
CFLAGS+=	-I${ICONV_PREFIX}/include
DATADIR=	${PREFIX}/share/corsix-th

OPTIONS_DEFINE=	MOVIES TOOLS
OPTIONS_DEFAULT=MOVIES TOOLS
OPTIONS_SUB=	yes

MOVIES_DESC=	Play in-game movies
TOOLS_DESC=	Tools for decoding RNC files

MOVIES_LIB_DEPENDS=	libswresample.so:multimedia/ffmpeg
MOVIES_CMAKE_ON=	-DWITH_MOVIES=ON
MOVIES_CMAKE_OFF=	-DWITH_MOVIES=OFF

TOOLS_CMAKE_ON=		-DBUILD_TOOLS=ON
TOOLS_CMAKE_OFF=	-DBUILD_TOOLS=OFF

post-install-TOOLS-on:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/rnc/rnc_decode ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
