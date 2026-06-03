PORTNAME=	chai
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.09.1
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMESUFFIX=	-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Copy-hiding array abstraction for data migration
WWW=		https://github.com/LLNL/CHAI

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcamp.so:devel/camp \
		libRAJA.so:misc/raja \
		libumpire.so:devel/umpire \
		libfmt.so:devel/libfmt
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang localbase:ldflags pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_PROJECT=	${PORTNAME:tu}
GH_TUPLE=	LLNL:blt:e783e30:blt/blt

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	UMPIRE_ENABLE_EXAMPLES \
		ENABLE_TESTS
CMAKE_TESTING_ON=	ENABLE_TESTS

LDFLAGS+=	-lexecinfo

# tests as of 2025.09.1: 100% tests passed, 0 tests failed out of 10

.include <bsd.port.mk>
