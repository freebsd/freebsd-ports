PORTNAME=	inja
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.0
CATEGORIES=	devel

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Template Engine for Modern C++
WWW=		https://pantor.github.io/inja/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		nlohmann-json>=3:devel/nlohmann-json

USES=		bison cmake:noninja compiler:c++17-lang gettext pathfix pkgconfig python:build shebangfix

SHEBANG_FILES=	scripts/update_single_include.sh third_party/amalgamate/amalgamate.py
BINARY_ALIAS=	python3=${PYTHON_CMD}

USE_GITHUB=	yes
GH_ACCOUNT=	pantor

OPTIONS_DEFINE=	TESTS

TESTS_DESC=		Build self tests
TESTS_CMAKE_BOOL=	BUILD_TESTING BUILD_BENCHMARK
#TESTS_MESON_TRUE=	build_tests build_benchmark

CMAKE_OFF=	INJA_USE_EMBEDDED_JSON

.include <bsd.port.mk>
