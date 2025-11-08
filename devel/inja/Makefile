PORTNAME=	inja
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5.0
CATEGORIES=	devel

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Template Engine for Modern C++
WWW=		https://pantor.github.io/inja/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		nlohmann-json>=3:devel/nlohmann-json

USES=		bison cmake:testing compiler:c++17-lang gettext pathfix \
		pkgconfig shebangfix python:build

SHEBANG_FILES=	scripts/update_single_include.sh third_party/amalgamate/amalgamate.py
BINARY_ALIAS=	python3=${PYTHON_CMD}
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	pantor

CMAKE_OFF=		INJA_USE_EMBEDDED_JSON BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING BUILD_BENCHMARK

.include <bsd.port.mk>
