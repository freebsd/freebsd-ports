# $FreeBSD$

PORTNAME=	libfmt
# Make sure to check devel/spdlog consumers too
DISTVERSION=	6.2.1
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Formatting library for C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	fmtlib
GH_PROJECT=	fmt
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
