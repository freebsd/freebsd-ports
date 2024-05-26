PORTNAME=	pybind11-json
DISTVERSION=	0.2.14
CATEGORIES=	devel python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Using nlohmann::json with pybind11
WWW=		https://github.com/pybind/pybind11_json

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11 \
		nlohmann-json>0:devel/nlohmann-json
RUN_DEPENDS=	pybind11>:devel/pybind11 \
		nlohmann-json>0:devel/nlohmann-json
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++11-lang python:build

USE_GITHUB=	yes
GH_ACCOUNT=	pybind
GH_PROJECT=	${PORTNAME:S/-/_/}

CMAKE_OFF=	PYBIND11_TEST

CMAKE_TESTING_ON=	BUILD_TESTS
CMAKE_TESTING_TARGET=	${ALL_TARGET}

NO_ARCH=	yes

PLIST_FILES=	include/pybind11_json/pybind11_json.hpp \
		share/cmake/pybind11_json/pybind11_jsonConfig.cmake \
		share/cmake/pybind11_json/pybind11_jsonConfigVersion.cmake \
		share/cmake/pybind11_json/pybind11_jsonTargets.cmake

post-test: # workaround for https://github.com/pybind/pybind11_json/issues/60
	@${BUILD_WRKSRC}/test/test_pybind11_json

.include <bsd.port.mk>
