PORTNAME=	docopt.cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3-5
DISTVERSIONSUFFIX=	-g400e6dd
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++11 options parser based on help messages
WWW=		https://github.com/docopt/docopt.cpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cmake:testing compiler:c++11-lang python:test
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	docopt

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	WITH_TESTS
CMAKE_TESTING_TARGET=	${ALL_TARGET}

post-test:
	@cd ${BUILD_WRKSRC} && \
		${PYTHON_CMD} run_tests

.include <bsd.port.mk>
