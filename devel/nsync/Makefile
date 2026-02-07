PORTNAME=	nsync
DISTVERSION=	1.27.0
CATEGORIES=	devel

MAINTAINER=	amzo1337@gmail.com
COMMENT=	C library that exports various synchronization primitives like mutexes
WWW=		https://github.com/google/nsync

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	google
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	NSYNC_ENABLE_TESTS
CMAKE_TESTING_ON=	NSYNC_ENABLE_TESTS

.include <bsd.port.mk>
