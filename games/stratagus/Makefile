# Created by: Travis Poppe <tlp@liquidx.org>

PORTNAME=	stratagus
PORTVERSION=	3.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free cross-platform real-time strategy gaming engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libtolua++-${LUA_VER}.so:lang/tolua++
RUN_DEPENDS=	zenity:x11/zenity

USE_GITHUB=	yes
GH_ACCOUNT=	Wargus

USES=		cmake compiler:c++17-lang lua:51 pkgconfig sdl
USE_SDL=	sdl2 mixer2 image2
CMAKE_ARGS=	-DGAMEDIR:STRING="bin" \
		-DTOLUA++_APP:STRING="tolua++-${LUA_VER}" \
		-DTOLUA++_INCLUDE_DIR:STRING="${LUA_INCDIR}" \
		-DTOLUA++_LIBRARY:STRING="${LUA_LIBDIR}/libtolua++.so"
CMAKE_ON=	ENABLE_DEV
CMAKE_OFF=	WITH_STACKTRACE  # not in ports

PORTDOCS=	*

OPTIONS_DEFINE=	MNG THEORA VORBIS DOCS
OPTIONS_DEFAULT=MNG THEORA VORBIS

MNG_DESC=		MNG image library support
MNG_LIB_DEPENDS=	libmng.so:graphics/libmng
MNG_CMAKE_BOOL=		WITH_MNG

THEORA_LIB_DEPENDS=	libtheora.so:multimedia/libtheora
THEORA_CMAKE_BOOL=	WITH_THEORA

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg
VORBIS_CMAKE_BOOL=	WITH_OGGVORBIS

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-register  # incompatible code included from lcms
.endif

.include <bsd.port.post.mk>
