PORTNAME=	pathlib2
DISTVERSION=	2.3.7.post1
PORTEPOCH=	1 # adding PORTEPOCH because when only .postN is appended to the version of a Python package no other methods work (like suggested in the ports@ ML discussion recently)
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Object-oriented filesystem paths
WWW=		https://pypi.org/project/pathlib2/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python dos2unix
USE_PYTHON=	distutils autoplist pytest
NO_ARCH=	yes

DOS2UNIX_FILES=	tests/test_pathlib2.py

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKDIR=	${WRKSRC}/tests

# tests as of 2.3.7.post1: 313 passed, 115 skipped in 6.31s

.include <bsd.port.mk>
