# $FreeBSD$

PORTNAME=	opencollada
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.25
CATEGORIES=	graphics devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for reading and writing COLLADA files

LICENSE=	MIT

LIB_DEPENDS=	libpcre.so:devel/pcre

BROKEN_powerpc64=	Does not build

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	OpenCOLLADA

USE_GNOME=	libxml2
USE_LDCONFIG=	${PREFIX}/lib/opencollada
USES=		cmake:outsource compiler iconv pkgconfig
CFLAGS+=	-I/${LOCALBASE}/include
CMAKE_ARGS+=	-DUSE_SHARED:BOOL=ON -DUSE_STATIC:BOOL=OFF

BROKEN_sparc64=	cannot build: runaway process

post-patch:
	@${REINPLACE_CMD} -e 's|$${OPENCOLLADA_INST_LIBRARY}/cmake|${PREFIX}/share/cmake/Modules|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
