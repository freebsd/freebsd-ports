PORTNAME=	docopt.cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++11 options parser based on help messages

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

TEST_DEPENDS=	python${PYTHON_DEFAULT}:lang/python${PYTHON_DEFAULT:S/.//}

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	docopt
USE_LDCONFIG=	yes

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DWITH_TESTS=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		python${PYTHON_DEFAULT} run_tests

.include <bsd.port.mk>
