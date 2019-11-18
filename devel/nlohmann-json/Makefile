# Created by: Viacheslav Mikerov <SlavaMikerov@gmail.com>
# $FreeBSD$

PORTNAME=	json
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7.3
CATEGORIES=	devel
PKGNAMEPREFIX=	nlohmann-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	JSON library for Modern C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.MIT

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	nlohmann

NO_BUILD=	yes
NO_ARCH=	yes

CMAKE_OFF=	JSON_BuildTests

PLIST_FILES=	lib/cmake/nlohmann_json/nlohmann_jsonConfig.cmake \
		lib/cmake/nlohmann_json/nlohmann_jsonConfigVersion.cmake \
		lib/cmake/nlohmann_json/nlohmann_jsonTargets.cmake \
		include/nlohmann/json.hpp

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DJSON_BuildTests:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
