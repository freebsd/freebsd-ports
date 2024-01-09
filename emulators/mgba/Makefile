PORTNAME=	mgba
DISTVERSION=	0.10.3
CATEGORIES=	emulators

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Game Boy Advance (GBA) emulator/debugger
WWW=		https://mgba.io

LICENSE=	MPL20 BSD3CLAUSE LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/src/third-party/inih/LICENSE.txt
LICENSE_FILE_LGPL21+ =	${WRKSRC}/src/third-party/blip_buf/license.txt
LICENSE_FILE_MPL20=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libelf.so:devel/elfutils \
		libpng.so:graphics/png

USES=		cmake compiler:c++14-lang gl gnome localbase:ldflags lua \
		pkgconfig sdl sqlite:3

USE_GITHUB=	yes
GH_ACCOUNT=	mgba-emu

USE_GL=		gl glu

USE_LDCONFIG=	yes

USE_SDL=	sdl2

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR:STRING="${DOCSDIR}" \
		-DUSE_ELF:BOOL=ON \
		-DUSE_MINIZIP:BOOL=OFF \
		-DUSE_LIBZIP:BOOL=OFF \
		-DUSE_ZLIB:BOOL=ON \
		-DUSE_LZMA:BOOL=ON \
		-DUSE_SQLITE3:BOOL=ON \
		-DUSE_DISCORD_RPC:BOOL=OFF \
		-DBUILD_GL:BOOL=ON \
		-DBUILD_GLES2:BOOL=OFF
LDFLAGS+=	-Wl,--as-needed # glu

OPTIONS_DEFINE=	DEBUGGERS FFMPEG LIBRETRO MAGICK QT5 DOCS
OPTIONS_DEFAULT=	DEBUGGERS FFMPEG LIBRETRO MAGICK QT5
OPTIONS_SUB=	yes

DEBUGGERS_DESC=	Debugging infrastructure (CLI debugger, GDB remote stub)
FFMPEG_DESC=	FFmpeg video recording support
LIBRETRO_DESC=	libretro core
MAGICK_DESC=	ImageMagick GIF recording support
QT5_DESC=	Qt 5 frontend

DEBUGGERS_USES=		libedit
DEBUGGERS_CMAKE_BOOL=	USE_DEBUGGERS USE_EDITLINE USE_GDB_STUB

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	USE_FFMPEG

LIBRETRO_CMAKE_BOOL=	BUILD_LIBRETRO
LIBRETRO_CMAKE_ON=	-DLIBRETRO_LIBDIR:PATH="${PREFIX}/lib/libretro"
LIBRETRO_CONFLICTS_INSTALL=	libretro-mgba

MAGICK_USES=		magick
MAGICK_CMAKE_BOOL=	USE_MAGICK

QT5_USES=	desktop-file-utils qt:5
QT5_USE=	qt=qmake:build,buildtools:build,core,gui,widgets,network,opengl,multimedia
QT5_CMAKE_BOOL=	BUILD_QT

.include <bsd.port.mk>
