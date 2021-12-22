PORTNAME=	sdbus-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	High-level C++ D-Bus library

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

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD || ${OSVERSION} < 1300134
LIB_DEPENDS+=	libepoll-shim.so:devel/libepoll-shim
CFLAGS+=	`pkg-config --cflags epoll-shim`
LDFLAGS+=	`pkg-config --libs epoll-shim`
.endif

.include <bsd.port.mk>
