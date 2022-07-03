PORTNAME=	nanopb
DISTVERSION=	0.4.6.4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Protocol Buffers with small code size

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	protoc:devel/protobuf
TEST_DEPENDS=	scons:devel/scons

USES=		cmake python shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes

SHEBANG_FILES=	generator/nanopb_generator.py

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD}

do-test: # tests fail to build, see https://github.com/nanopb/nanopb/issues/792
	@cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} scons

.include <bsd.port.mk>
