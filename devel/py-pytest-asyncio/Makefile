PORTNAME=	pytest-asyncio
DISTVERSION=	0.23.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytest_asyncio-${DISTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Py.test plugin providing fixtures and markers for asyncio
WWW=		https://pypi.org/project/pytest-asyncio/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}pytest4-asyncio

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=6.1.0:devel/py-pytest@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=6.1.0:devel/py-pytest@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=5.7.1:devel/py-hypothesis@${PY_FLAVOR} \

USES=		python
USE_PYTHON=	autoplist distutils pytest
NO_ARCH=	yes

post-patch:
	@${ECHO_CMD} 'from setuptools import setup; setup()' > ${WRKSRC}/setup.py

.include <bsd.port.mk>
