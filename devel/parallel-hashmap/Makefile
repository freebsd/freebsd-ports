PORTNAME=	parallel-hashmap
DISTVERSION=	1.33
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of excellent hash map implementations (a C++ header-only library)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	greg7mdp

NO_BUILD=	yes
NO_ARCH=	yes

do-test: # clones googletest
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DPHMAP_BUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
