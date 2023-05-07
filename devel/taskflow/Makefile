PORTNAME=	taskflow
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only library for parallel tasks in modern C++
WWW=		https://github.com/taskflow/taskflow

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang
USE_GITHUB=	yes

CMAKE_OFF=	TF_BUILD_CUDA TF_BUILD_TESTS TF_BUILD_EXAMPLES
CMAKE_TESTING_ON=	BUILD_TESTING TF_BUILD_TESTS

NO_ARCH=	yes

.include <bsd.port.mk>
