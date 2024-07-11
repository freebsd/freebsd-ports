PORTNAME=	dtfabric
PORTVERSION=	20230520
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/libyal/dtfabric/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Tooling for data type and structure management
WWW=		https://github.com/libyal/dtfabric

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist concurrent
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD}
TEST_TARGET=	run_tests.py

post-patch:
	${REINPLACE_CMD} "s,share/doc/dtfabric,${DOCSDIR_REL}," ${WRKSRC}/setup.py
	${REINPLACE_CMD} "/pip/d" ${WRKSRC}/requirements.txt

.include <bsd.port.mk>
