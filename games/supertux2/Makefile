# $FreeBSD$

PORTNAME=	supertux
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	https://github.com/SuperTux/supertux/releases/download/v${PORTVERSION}/
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Side-scroller game similar to Super Mario Brothers

BUILD_DEPENDS=	${LOCALBASE}/include/boost/smart_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libphysfs.so:devel/physfs \
		libcurl.so:ftp/curl \
		libvorbis.so:audio/libvorbis

BROKEN_FreeBSD_10=	does not build on 10.x

USE_SDL=	sdl2 image2
USE_GL=		glew
USES=		cmake:outsource compiler:c++11-lib dos2unix iconv \
		openal:al pkgconfig tar:bzip2
# Unhide std::to_string() to fix build with GCC (see ports/193528 for details)
CFLAGS+=	-D_GLIBCXX_USE_C99
CMAKE_ARGS=	-DINSTALL_SUBDIR_BIN=bin \
		-DBUILD_SHARED_LIBS=off
DOS2UNIX_FILES=	external/squirrel/CMakeLists.txt
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e '/^Icon=/s,supertux.png,supertux2,' \
		${WRKSRC}/supertux2.desktop

.include <bsd.port.mk>
