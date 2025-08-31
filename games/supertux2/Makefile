PORTNAME=	supertux
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
DISTVERSIONSUFFIX=	-Source
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	https://github.com/SuperTux/supertux/releases/download/v${PORTVERSION}/
PKGNAMESUFFIX=	2
DISTNAME=	SuperTux-${DISTVERSIONFULL}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Side-scroller game similar to Super Mario Brothers
WWW=		https://supertux.org/

BUILD_DEPENDS=	glm>0:math/glm
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libharfbuzz.so:print/harfbuzz \
		libfribidi.so:converters/fribidi \
		libfreetype.so:print/freetype2 \
		libogg.so:audio/libogg \
		libphysfs.so:devel/physfs \
		libpng.so:graphics/png \
		libraqm.so:print/libraqm \
		libvorbis.so:audio/libvorbis

USES=		cmake:noninja compiler:c++14-lang dos2unix gl iconv \
		localbase openal:al pkgconfig sdl
USE_GL=		gl glew glu
USE_SDL=	sdl2 image2

CMAKE_ARGS=	-DINSTALL_SUBDIR_BIN=bin \
		-DBUILD_SHARED_LIBS=off \
		-DBUILD_DOCUMENTATION=off # doxygen
LDFLAGS_i386=	-Wl,-znotext

DOS2UNIX_FILES=	external/squirrel/squirrel/sqvm.cpp
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
