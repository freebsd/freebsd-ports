PORTNAME=	nanopb
DISTVERSION=	0.4.7
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Protocol Buffers with small code size
WWW=		https://jpa.kapsi.fi/nanopb/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	protoc:devel/protobuf \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR}
TEST_DEPENDS=	scons:devel/scons

USES=		cmake python shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes

SHEBANG_FILES=	generator/nanopb_generator.py generator/protoc-gen-nanopb

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD}

BINARY_ALIAS=	python3=${PYTHON_CMD} # only for tests

do-test:
	@cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} scons LINKLIBS=-lm

.include <bsd.port.mk>
