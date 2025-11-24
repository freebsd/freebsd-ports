PORTNAME=	taskflow
DISTVERSIONPREFIX=	v
DISTVERSION=	3.11.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only library for parallel tasks in modern C++
WWW=		https://taskflow.github.io/ \
		https://github.com/taskflow/taskflow

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang
USE_GITHUB=	yes

CMAKE_OFF=	TF_BUILD_CUDA TF_BUILD_TESTS TF_BUILD_EXAMPLES
CMAKE_TESTING_ON=	BUILD_TESTING TF_BUILD_TESTS

NO_ARCH=	yes

# tests as of 3.11.0: 100% tests passed, 0 tests failed out of 2190

.include <bsd.port.mk>
