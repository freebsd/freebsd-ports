PORTNAME=	acstore
PORTVERSION=	20230519
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/log2timeline/acstore/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Attribute Container Storage
WWW=		https://github.com/log2timeline/acstore

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist concurrent
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD}
TEST_TARGET=	run_tests.py

post-patch:
	${REINPLACE_CMD} "s,share/doc/acstore,${DOCSDIR_REL}," ${WRKSRC}/setup.py
	${REINPLACE_CMD} "/pip/d" ${WRKSRC}/requirements.txt

.include <bsd.port.mk>
