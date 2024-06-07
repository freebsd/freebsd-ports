PORTNAME=	subprocess
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0-6
DISTVERSIONSUFFIX=	-g29d01c7
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	2caf8c1e119d5f14f4ae31316ddfd03126e101ac.patch:-p1 # https://github.com/benman64/subprocess/pull/17
PATCHFILES+=	cef6823e5834053a20144b790945f7ed1808c28c.patch:-p1 # https://github.com/benman64/subprocess/pull/18

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

.include <bsd.port.mk>
