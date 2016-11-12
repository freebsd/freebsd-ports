# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	wyrmgus
PORTVERSION=	1.9.9
DISTVERSIONPREFIX=	v
CATEGORIES=	games devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Modified Stratagus engine for Wyrmsun

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libtolua++-${LUA_VER}.so:lang/tolua++

USE_GITHUB=     yes
GH_ACCOUNT=     Andrettin
GH_PROJECT=     Wyrmgus

USE_GL=		gl glu
USE_SDL=	sdl
USES=		compiler:c++11-lib cmake:outsource lua:51 pkgconfig sqlite
CMAKE_ARGS=	-DGAMEDIR:STRING="bin" \
		-DTOLUA++_APP:STRING="tolua++-${LUA_VER}" \
		-DTOLUA++_INCLUDE_DIR:STRING="${LUA_INCDIR}" \
		-DTOLUA++_LIBRARY:STRING="${LUA_LIBDIR}/libtolua++.so" \
		-DENABLE_USEGAMEDIR:BOOL=OFF

PORTDOCS=	*

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/wyrmsun.ico

OPTIONS_DEFINE=	MIKMOD MNG THEORA VORBIS X11 FLUIDSYNTH PHYSFS DOCS
OPTIONS_DEFAULT=VORBIS X11

MIKMOD_LIB_DEPENDS=	libmikmod.so:audio/libmikmod
MIKMOD_CMAKE_ON=	-DWITH_MIKMOD:BOOL=ON
MIKMOD_CMAKE_OFF=	-DWITH_MIKMOD:BOOL=OFF

MNG_DESC=		MNG image library support
MNG_LIB_DEPENDS=	libmng.so:graphics/libmng
MNG_CMAKE_ON=		-DWITH_MNG:BOOL=ON
MNG_CMAKE_OFF=		-DWITH_MNG:BOOL=OFF

THEORA_LIB_DEPENDS=	libtheora.so:multimedia/libtheora
THEORA_CMAKE_ON=	-DWITH_THEORA:BOOL=ON
THEORA_CMAKE_OFF=	-DWITH_THEORA:BOOL=OFF

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_CMAKE_ON=	-DWITH_OGGVORBIS:BOOL=ON
VORBIS_CMAKE_OFF=	-DWITH_OGGVORBIS:BOOL=OFF

X11_DESC=		X11 clipboard pasting support
X11_USE=		XORG=x11
X11_CMAKE_ON=		-DWITH_X11:BOOL=ON
X11_CMAKE_OFF=		-DWITH_X11:BOOL=OFF

FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CMAKE_ON=	-DWITH_FLUIDSYNTH:BOOL=ON
FLUIDSYNTH_CMAKE_OFF=	-DWITH_FLUIDSYNTH:BOOL=OFF

PHYSFS_DESC=		PhysFS support
PHYSFS_LIB_DEPENDS=	libphysfs.so:devel/physfs
PHYSFS_CMAKE_ON=	-DWITH_PHYSFS:BOOL=ON
PHYSFS_CMAKE_OFF=	-DWITH_PHYSFS:BOOL=OFF

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-D_GLIBCXX_USE_C99 # gcc c++11 support is broken on FreeBSD
.endif

do-install:
	${INSTALL_PROGRAM} ${CONFIGURE_WRKSRC}/stratagus ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/win32/wyrmsun.ico ${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.post.mk>
