# $FreeBSD$

PORTNAME=	protobuf-compiler
DISTVERSION=	1.0.20
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Compile all protobuf files and create package distributions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC_tests}/LICENSE

BUILD_DEPENDS=	${_MY_DEPENDS}
RUN_DEPENDS=	${_MY_DEPENDS}

USES=		python:3.6+ shebangfix
USE_GITHUB=	nodefault
GH_TUPLE=	netsaj:python-${PORTNAME}:7cb32ab8188cbfecb91034cbf7803394ed1c25b6:tests
USE_PYTHON=	autoplist concurrent distutils
SHEBANG_GLOB=	*.py

TEST_ENV=	PYTHONPATH="${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}"
NO_ARCH=	yes
TEST_WRKSRC=	${WRKSRC_tests}

_MY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bleach>=2.1.0:www/py-bleach@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.3.3:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio-tools>=1.18.0:devel/py-grpcio-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.18.0:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=1.1.0:devel/py-termcolor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.31.1:misc/py-tqdm@${PY_FLAVOR}

post-patch:
	${REINPLACE_CMD} 's|%%PYTHON_CMD%%|${PYTHON_CMD}|g' \
		${WRKSRC}/protobuf_compiler/main.py

do-test:
# Loosely based on the upstream test_protopy.py.
	${RM} -r ${TEST_WRKSRC}/run_test
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} \
		${PYTHON_CMD} ${STAGEDIR}${PREFIX}/bin/protopy \
		-o ./run_test -d ./test -p mytesting -v 1.0.1
	${TEST} -e ${TEST_WRKSRC}/run_test/mytesting-1.0.1.tar.gz

.include <bsd.port.mk>
