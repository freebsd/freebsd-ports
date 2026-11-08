PORTNAME=	libcds
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.3-102
DISTVERSIONSUFFIX=	-g9985d2a8
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library of Concurrent Data Structures
WWW=		https://github.com/khizmax/libcds

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	khizmax

CMAKE_TESTING_ON=	LIBCDS_WITH_TESTS # tests fail to compile, see https://github.com/khizmax/libcds/issues/173
CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility, see https://github.com/khizmax/libcds/issues/190

.include <bsd.port.mk>
