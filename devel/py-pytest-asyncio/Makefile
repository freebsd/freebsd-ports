PORTNAME=	pytest-asyncio
DISTVERSION=	0.23.8
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytest_asyncio-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Py.test plugin providing fixtures and markers for asyncio
WWW=		https://pypi.org/project/pytest-asyncio/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# note that the next version requires pytest 8.2.0, while ports still only have 8.1.1 ATOW
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=6.1.0:devel/py-pytest@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=6.1.0:devel/py-pytest@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=5.7.1:devel/py-hypothesis@${PY_FLAVOR} \

USES=		python
USE_PYTHON=	autoplist distutils pytest
NO_ARCH=	yes

post-patch:
	@${ECHO_CMD} 'from setuptools import setup; setup()' > ${WRKSRC}/setup.py

.include <bsd.port.mk>
