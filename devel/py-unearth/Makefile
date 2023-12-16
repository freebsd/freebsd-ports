PORTNAME=	unearth
PORTVERSION=	0.12.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility to fetch and download python packages
WWW=		https://unearth.readthedocs.io/en/latest/ \
		https://github.com/frostming/unearth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>=0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=20:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=2.1.2:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-httpserver>=1.0.4:devel/py-pytest-httpserver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-wsgi-adapter>=0.4.1:www/py-requests-wsgi-adapter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trustme>=0.9.0:security/py-trustme@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
