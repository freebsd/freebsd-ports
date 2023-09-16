PORTNAME=	sdbus-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	9dacffae0d33.patch:-p1 # https://github.com/Kistler-Group/sdbus-cpp/pull/358

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	High-level C++ D-Bus library
WWW=		https://github.com/Kistler-Group/sdbus-cpp

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbasu.so:devel/basu \
		libexpat.so:textproc/expat2
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	Kistler-Group
CMAKE_ON=	BUILD_CODE_GEN
CMAKE_OFF=	BUILD_DOC
CMAKE_TESTING_ON=	BUILD_TESTS

# XXX Drop after FreeBSD 12.4 EOL around 2023-12-31
# https://cgit.freebsd.org/src/commit/?id=7a202823aa54
.if !exists(/usr/include/sys/eventfd.h)
LIB_DEPENDS+=	libepoll-shim.so:devel/libepoll-shim
CFLAGS+=	`pkg-config --cflags epoll-shim`
LDFLAGS+=	`pkg-config --libs epoll-shim`
.endif

.include <bsd.port.mk>
