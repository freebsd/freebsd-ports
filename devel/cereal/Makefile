PORTNAME=		cereal
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0-10
DISTVERSIONSUFFIX=	-g64f50dbd
CATEGORIES=	devel

MAINTAINER=	teodor@sigaev.ru
COMMENT=	C++11 library for serialization

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
RUN_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	USCiLab

CFLAGS+=	-Wno-unused-private-field

CMAKE_ON=	SKIP_PORTABILITY_TEST
CMAKE_OFF=	BUILD_TESTS WITH_WERROR

NO_ARCH=	yes

post-install:
	${FIND} ${STAGEDIR}${PREFIX} -name LICENSE -delete

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
