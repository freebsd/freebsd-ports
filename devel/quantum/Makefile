PORTNAME=	quantum
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2
CATEGORIES=	devel
PKGNAMESUFFIX=	-parallelization-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-threaded coroutine dispatcher and parallel execution engine

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
RUN_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		cmake:testing compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	bloomberg

CMAKE_TESTING_ON=	QUANTUM_ENABLE_TESTS # tests are broken, see https://github.com/bloomberg/quantum/issues/151

NO_ARCH=	yes

.include <bsd.port.mk>
