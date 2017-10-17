# Created by: Viacheslav Mikerov <SlavaMikerov@gmail.com>
# $FreeBSD$

PORTNAME=	json
PORTVERSION=	2.1.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	nlohmann-

MAINTAINER=	SlavaMikerov@gmail.com
COMMENT=	JSON library for Modern C++

LICENSE=	BSD2CLAUSE

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	nlohmann
GH_PROJECT=	json

PLIST_FILES=	share/cmake/Modules/nlohmann_jsonConfig.cmake \
		share/cmake/Modules/nlohmann_jsonConfigVersion.cmake \
		share/cmake/Modules/nlohmann_jsonTargets.cmake \
		include/nlohmann/json.hpp

USES=		compiler:c++11-lib cmake:outsource
OPTIONS_DEFINE=	TEST
TEST_CMAKE_OFF=	-DBuildTests=OFF

post-patch:
	@${REINPLACE_CMD} -e \
		's|set(JSON_CONFIG_DESTINATION "cmake")|set(JSON_CONFIG_DESTINATION "share/cmake/Modules")|g' \
		${WRKSRC}/CMakeLists.txt

do-test-TEST-on:
	@cd ${WRKDIR}/.build && ${MAKE_CMD} test

.include <bsd.port.mk>
