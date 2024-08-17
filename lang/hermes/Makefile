PORTNAME=	hermes
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
CATEGORIES=	lang
PKGNAMESUFFIX=	-javascript-engine

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	JavaScript engine
WWW=		https://github.com/facebook/hermes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicui18n.so:devel/icu
TEST_DEPENDS=	googletest>0:devel/googletest \
		zip:archivers/zip

USES=		cmake compiler:c++14-lang cpe ncurses python:build readline
USE_LDCONFIG=	yes
CPE_VENDOR=	facebook

USE_GITHUB=	yes
GH_ACCOUNT=	facebook

CMAKE_OFF=	HERMES_ENABLE_TEST_SUITE

BINARY_ALIAS=	python=${PYTHON_CMD} python3=${PYTHON_CMD}

do-test: # 5 unexpected test failures
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DHERMES_ENABLE_TEST_SUITE:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} check-hermes

.include <bsd.port.mk>
