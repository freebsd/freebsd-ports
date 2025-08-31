PORTNAME=	stratagus
PORTVERSION=	3.3.2
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free cross-platform real-time strategy gaming engine
WWW=		https://stratagus.com/stratagus.html \
		https://github.com/Wargus/stratagus

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libtolua++-${LUA_VER}.so:lang/tolua++
RUN_DEPENDS=	zenity:x11/zenity

USES=		cmake compiler:c++17-lang lua:51 pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	Wargus
USE_SDL=	sdl2 mixer2 image2
CMAKE_ARGS=	-DGAMEDIR:STRING="bin" \
		-DTOLUA++_APP:STRING="tolua++-${LUA_VER}" \
		-DTOLUA++_INCLUDE_DIR:STRING="${LUA_INCDIR}" \
		-DTOLUA++_LIBRARY:STRING="${LUA_LIBDIR}/libtolua++.so"
CMAKE_ON=	ENABLE_DEV
CMAKE_OFF=	WITH_STACKTRACE  # not in ports

PORTSCOUT=	limit:^3\.

PORTDOCS=	*

OPTIONS_DEFINE=	MNG THEORA VORBIS EAGER_LOAD DOCS
OPTIONS_DEFAULT=MNG THEORA VORBIS
.if exists(/usr/include/omp.h)
OPTIONS_DEFINE+=OPENMP
OPTIONS_DEFAULT+=OPENMP
.endif

MNG_DESC=		MNG image library support
MNG_LIB_DEPENDS=	libmng.so:graphics/libmng
MNG_CMAKE_BOOL=		WITH_MNG

THEORA_LIB_DEPENDS=	libtheora.so:multimedia/libtheora
THEORA_CMAKE_BOOL=	WITH_THEORA
THEORA_IMPLIES=		VORBIS  # https://github.com/Wargus/stratagus/issues/396

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg
VORBIS_CMAKE_BOOL=	WITH_OGGVORBIS

EAGER_LOAD_DESC=	Load all game data at startup (more memory, less stutter)
EAGER_LOAD_CMAKE_BOOL=	EAGER_LOAD

OPENMP_CMAKE_BOOL=	WITH_OPENMP

.include <bsd.port.mk>
