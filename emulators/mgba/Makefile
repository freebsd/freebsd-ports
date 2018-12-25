# $FreeBSD$

PORTNAME=	mgba
DISTVERSION=	0.6.1
PORTREVISION=	6
CATEGORIES=	emulators

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	a7a51a11373f.patch:-p1 \
		a2b8c4ae807a.patch:-p1

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Game Boy Advance (GBA) emulator/debugger

LICENSE=	MPL20 BSD3CLAUSE LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/src/third-party/inih/LICENSE.txt
LICENSE_FILE_LGPL21+=	${WRKSRC}/src/third-party/blip_buf/license.txt
LICENSE_FILE_MPL20=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libpng.so:graphics/png

USES=		cmake compiler:c++11-lang localbase:ldflags pkgconfig sqlite:3

USE_GITHUB=	yes
GH_ACCOUNT=	mgba-emu

USE_GL=		gl glu
USE_SDL=	sdl2

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR:STRING="${DOCSDIR}" \
		-DUSE_MINIZIP:BOOL=OFF \
		-DUSE_LIBZIP:BOOL=OFF \
		-DUSE_ZLIB:BOOL=ON \
		-DUSE_LZMA:BOOL=ON \
		-DUSE_SQLITE3:BOOL=ON \
		-DBUILD_GL:BOOL=ON \
		-DBUILD_GLES2:BOOL=OFF
LDFLAGS+=	-Wl,--as-needed # glu

OPTIONS_DEFINE=	DEBUGGERS FFMPEG MAGICK QT5 DOCS
OPTIONS_DEFAULT=	DEBUGGERS FFMPEG MAGICK QT5
OPTIONS_SUB=	yes

DEBUGGERS_DESC=	Debugging infrastructure (CLI debugger, GDB remote stub)
FFMPEG_DESC=	FFmpeg video recording support
MAGICK_DESC=	ImageMagick GIF recording support
QT5_DESC=	Qt 5 frontend

DEBUGGERS_CMAKE_BOOL=	USE_DEBUGGERS USE_EDITLINE USE_GDB_STUB
DEBUGGERS_USES=		libedit

FFMPEG_CMAKE_BOOL=	USE_FFMPEG
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
			libavformat.so:multimedia/ffmpeg \
			libavresample.so:multimedia/ffmpeg \
			libavutil.so:multimedia/ffmpeg \
			libswscale.so:multimedia/ffmpeg

MAGICK_CMAKE_BOOL=	USE_MAGICK
MAGICK_LIB_DEPENDS=	libMagickWand-6.so:graphics/ImageMagick6 \
			libMagickCore-6.so:graphics/ImageMagick6

QT5_CMAKE_BOOL=	BUILD_QT
QT5_USE=	qt=qmake_build,buildtools_build,core,gui,widgets,network,opengl,multimedia
QT5_USES=	desktop-file-utils qt:5
QT5_VARS=	installs_icons=yes

.include <bsd.port.mk>
