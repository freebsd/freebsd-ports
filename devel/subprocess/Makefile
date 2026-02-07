PORTNAME=	subprocess
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ subprocess library similar in design to Python subprocess library
WWW=		https://github.com/benman64/subprocess

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing python:build

USE_GITHUB=	yes
GH_ACCOUNT=	benman64

CMAKE_ON=	BUILD_SHARED_LIBS

BINARY_ALIAS=	python3=${PYTHON_CMD}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/cpp/subprocess.hpp ${STAGEDIR}${PREFIX}/include
	${MKDIR} ${STAGEDIR}${PREFIX}/include/subprocess
.for inc in basic_types.hpp pipe.hpp PipeVar.hpp ProcessBuilder.hpp shell_utils.hpp environ.hpp
	${INSTALL_DATA} ${WRKSRC}/src/cpp/subprocess/${inc} ${STAGEDIR}${PREFIX}/include/subprocess
.endfor
	${INSTALL_LIB} ${BUILD_WRKSRC}/subprocess/libsubprocess.so ${STAGEDIR}${PREFIX}/lib

# tests as of 0.6.0: 100% tests passed, 0 tests failed out of 1

.include <bsd.port.mk>
