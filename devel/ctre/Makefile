# $FreeBSD$

PORTNAME=	ctre
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only library for Compile Time Regular Expressions

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	hanickadot
GH_PROJECT=	compile-time-regular-expressions

CMAKE_OFF=	BUILD_TESTING

NO_BUILD=	yes
NO_ARCH=	yes

do-test: # https://github.com/hanickadot/compile-time-regular-expressions/issues/162
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON -DCTRE_BUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ctre-test && \
		ctest --progress --no-tests=ignore --output-on-failure

.include <bsd.port.mk>
