PORTNAME=	corsixth
DISTVERSIONPREFIX=	v
DISTVERSION=	0.70.1
CATEGORIES=	games

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open source clone of Theme Hospital
WWW=		https://github.com/CorsixTH/CorsixTH

LICENSE=	MIT

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng16.so:graphics/png
RUN_DEPENDS=	${LUA_REFMODLIBDIR}/lfs.so:devel/luafilesystem@${LUA_FLAVOR} \
		${LUA_REFMODLIBDIR}/lpeg.so:devel/lua-lpeg@${LUA_FLAVOR}

USES=		cmake:insource compiler:c++11-lib desktop-file-utils dos2unix \
		iconv localbase:ldflags lua pkgconfig sdl
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

OPTIONS_DEFINE=	MIDI MOVIES TOOLS
OPTIONS_DEFAULT=MOVIES TOOLS
OPTIONS_SUB=	yes

MIDI_DESC=	Support MIDI devices
MOVIES_DESC=	Play in-game movies
TOOLS_DESC=	Tools for decoding RNC files

MIDI_LIB_DEPENDS=	librtmidi.so:audio/rtmidi
MIDI_CMAKE_ON=		-DWITH_MIDI_DEVICE=ON
MIDI_CMAKE_OFF=		-DWITH_MIDI_DEVICE=OFF

MOVIES_LIB_DEPENDS=	libswresample.so:multimedia/ffmpeg
MOVIES_CMAKE_ON=	-DWITH_MOVIES=ON
MOVIES_CMAKE_OFF=	-DWITH_MOVIES=OFF

TOOLS_CMAKE_ON=		-DBUILD_TOOLS=ON
TOOLS_CMAKE_OFF=	-DBUILD_TOOLS=OFF

post-install-TOOLS-on:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/rnc/rnc_decode ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
