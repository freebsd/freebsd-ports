PORTNAME=	transwarp
DISTVERSION=	2.2.2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only library for task concurrency

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	bloomen

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/transwarp.h

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -Dtranswarp_build_tests:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
