# $FreeBSD$

PORTNAME=	opencollada
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.47
PORTREVISION=	1
CATEGORIES=	graphics devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for reading and writing COLLADA files

LICENSE=	MIT

LIB_DEPENDS=	libpcre.so:devel/pcre

BROKEN_powerpc64=	Does not build: c++: Internal error: Killed (program cc1plus)

USES=		cmake:outsource compiler dos2unix iconv pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	OpenCOLLADA

USE_GNOME=	libxml2
USE_LDCONFIG=	${PREFIX}/lib/opencollada
CFLAGS+=	-I/${LOCALBASE}/include
CMAKE_ARGS+=	-DUSE_SHARED:BOOL=ON -DUSE_STATIC:BOOL=OFF

BROKEN_sparc64=	cannot build: runaway process

# for files/patch-2d66943
DOS2UNIX_FILES=	COLLADABaseUtils/src/COLLADABUURI.cpp

post-patch:
	@${REINPLACE_CMD} -e 's|$${OPENCOLLADA_INST_LIBRARY}/cmake|${PREFIX}/share/cmake/Modules|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
