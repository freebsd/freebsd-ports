# $FreeBSD$

PORTNAME=	libretro-pcsx2
PORTVERSION=	0.20201030
CATEGORIES=	emulators games

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Standalone port of pcsx2 to libretro

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.GPLv3

ONLY_FOR_ARCHS=	>i386 amd64

LIB_DEPENDS=	libcdio.so:sysutils/libcdio \
		libharfbuzz.so:print/harfbuzz \
		libpng16.so:graphics/png \
		libportaudio.so:audio/portaudio \
		libSoundTouch.so:audio/soundtouch

USES=		cmake compiler:c++11-lib

CPPFLAGS+=		-I${LOCALBASE}/include/wx-3.0
USE_CXXSTD=		c++11
#LDFLAGS+=	-L${LOCALBASE}/lib -I/usr/lib
USE_LDCONFIG=		yes
CMAKE_CPP_FLAGS=	${CPPFLAGS}
CMAKE_PREFIX_PATH=	${LOCALBASE}/include/wx-3.0
CMAKE_C_FLAGS=		${CFLAGS}
CMAKE_CXX_FLAGS=	${CFLAGS}
CMAKE_ARGS+=		-DLIBRETRO=yes
CMAKE_ARGS+=		-Dgtk_INCLUDE_DIR="${LOCALBASE}/include/gtk-3.0" \
			-DwxWidgets_INCLUDE_DIRS="${LOCALBASE}/include/wx-3.0"

# lib depends on devel/ccache
WITH_CCACHE_BUILD=	yes

HAVE_GTK3=	true
#USES=		gnome xorg gl sdl dos2unix cmake:insource iconv gettext linux:c7 pkgconfig
#USE_LINUX=	libaio
USE_WX=		3.0+
#USE_XORG=	ice x11 xv xext xxf86vm xtst xrandr xi
USE_GL=		gl glew glu
USE_GNOME=	glib20
#USE_SDL=	sdl2

MAKE_JOBS_UNSAFE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	pcsx2
GH_TAGNAME=	1251fa4

PLIST_FILES=	lib/libretro/pcsx2_libretro.so

post-patch:
	${CP} files/3rdparty_wxwidgets3.0_src_unix_fswatcher__kqueue.cpp \
		${WRKSRC}/3rdparty/wxwidgets3.0/src/unix/fswatcher_kqueue.cpp

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKDIR}/.build/pcsx2/pcsx2_libretro.so \
		${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
