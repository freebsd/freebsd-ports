# $FreeBSD$

PORTNAME=	fmt
# Make sure to check devel/spdlog consumers too
PORTVERSION=	7.0.3
MASTER_SITES=	https://github.com/fmtlib/fmt/releases/download/${PORTVERSION}/
CATEGORIES=	devel
PKGNAMEPREFIX=	lib

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Formatting library for C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

USES=		cmake compiler:c++11-lang zip

USE_LDCONFIG=	yes

CMAKE_OFF=	FMT_DOC FMT_TEST
CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_SUB=	SHL1=${PORTVERSION:R:R} \
		SHL3=${PORTVERSION}

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DFMT_TEST:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
