PORTNAME=	fire-hpp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ single header library to create a CLI from a function signature

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENCE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake localbase:ldflags # localbase only for tests but localbase doesn't have the 'test' argument

USE_GITHUB=	yes
GH_ACCOUNT=	kongaskristjan

CMAKE_OFF=	FIRE_EXAMPLES FIRE_UNIT_TESTS

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/fire-hpp/fire.hpp \
		lib/cmake/fire-hpp/fire-hpp-config.cmake

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DFIRE_UNIT_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${BUILD_WRKSRC}/tests/run_tests

.include <bsd.port.mk>
