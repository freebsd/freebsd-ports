PORTNAME=	flit-core
DISTVERSION=	3.8.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/[-_]+/_/g}-${DISTVERSIONFULL}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Distribution-building parts of Flit
WWW=		https://github.com/pypa/flit/tree/main/flit_core

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}testpath>=0:devel/py-testpath@${PY_FLAVOR}

USES=		python
USE_PYTHON=	allflavors autoplist concurrent pep517 pytest
PEP517_BUILD_CMD=	${PYTHON_CMD} -m ${PORTNAME:C/[-_]+/_/g}.wheel
PEP517_BUILD_DEPEND=
PEP517_INSTALL_CMD=	${PYTHON_CMD} ${BUILD_WRKSRC}/bootstrap_install.py \
			-i ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} ${BUILD_WRKSRC}/dist/${PORTNAME:C/[-_]+/_/g}-*.whl
PEP517_INSTALL_DEPEND=

NO_ARCH=	yes

.include <bsd.port.mk>
