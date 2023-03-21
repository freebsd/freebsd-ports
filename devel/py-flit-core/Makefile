PORTNAME=	flit-core
PORTVERSION=	3.8.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	flit_core-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Distribution-building parts of Flit
WWW=		https://github.com/pypa/flit/tree/main/flit_core

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}testpath>=0:devel/py-testpath@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	allflavors autoplist concurrent pep517 pytest

NO_ARCH=	yes

PEP517_BUILD_CMD=	${PYTHON_CMD} -m flit_core.wheel
PEP517_BUILD_DEPEND=	# empty
PEP517_INSTALL_CMD=	${PYTHON_CMD} ${WRKSRC}/bootstrap_install.py --installdir ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} ${WRKSRC}/dist/${DISTNAME}*.whl
PEP517_INSTALL_DEPEND=	# empty

.include <bsd.port.mk>
