PORTNAME=	umpire
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.09.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	API for memory management on NUMA & GPU architectures
WWW=		https://umpire.readthedocs.io/en/develop/sphinx/tutorial.html \
		https://github.com/LLNL/Umpire

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcamp.so:devel/camp \
		libfmt.so:devel/libfmt

USES=		cmake:testing compiler:c++17-lang localbase:ldflags pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_PROJECT=	Umpire
GH_TUPLE=	LLNL:blt:e783e30:blt/blt

CMAKE_ARGS=	-DUMPIRE_FMT_TARGET=fmt
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	UMPIRE_ENABLE_EXAMPLES \
		ENABLE_TESTS
CMAKE_TESTING_ON=	ENABLE_TESTS

CXXFLAGS+=	-Dftruncate64=ftruncate \
		-DMAP_NORESERVE=0
LDFLAGS+=	-lexecinfo

# tests as of 2025.09.0: 100% tests passed, 0 tests failed out of 38

.include <bsd.port.mk>
