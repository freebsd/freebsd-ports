PORTNAME=	nanopb
DISTVERSION=	0.4.8
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Protocol Buffers with small code size
WWW=		https://jpa.kapsi.fi/nanopb/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	protoc:devel/protobuf \
		${PY_SETUPTOOLS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR} \
		${PY_SETUPTOOLS} # for the pkg_resources package
TEST_DEPENDS=	scons:devel/scons

USES=		cmake python shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes

SHEBANG_FILES=	generator/nanopb_generator \
		generator/nanopb_generator.py \
		extra/script_wrappers/nanopb_generator.py.in \
		generator/protoc-gen-nanopb

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD}

BINARY_ALIAS=	python3=${PYTHON_CMD} # only for tests

post-install:
	${PYTHON_CMD} -m compileall -d ${PREFIX}/bin -f ${STAGEDIR}${PREFIX}/bin
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} -f ${STAGEDIR}${PYTHON_SITELIBDIR}
	${PYTHON_CMD} -O -m compileall -d ${PREFIX}/bin -f ${STAGEDIR}${PREFIX}/bin
	${PYTHON_CMD} -O -m compileall -d ${PYTHON_SITELIBDIR} -f ${STAGEDIR}${PYTHON_SITELIBDIR}

do-test:
	@cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} scons LINKLIBS=-lm

.include <bsd.port.mk>
