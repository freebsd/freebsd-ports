PORTNAME=	snakeviz
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Web-based viewer for Python profiler output
WWW=		https://jiffyclub.github.io/snakeviz/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tornado>=2.0:www/py-tornado@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest

NO_ARCH=	yes

post-extract:
	@${ECHO_CMD} 'from setuptools import setup; setup()' > ${WRKSRC}/setup.py

.include <bsd.port.mk>
