PORTNAME=	responses
PORTVERSION=	0.25.0
PORTREVISION=	2
CATEGORIES=	devel www python
MASTER_SITES=	PYPI \
		https://github.com/getsentry/responses/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility library for mocking out the requests Python library
WWW=		https://github.com/getsentry/responses

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.30.0<3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.25.10,1<3.0,1:net/py-urllib3@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=6.0.0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-httpserver>=0:devel/py-pytest-httpserver@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}tomli-w>=0:textproc/py-tomli-w@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-pyyaml>=0:devel/py-types-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-requests>=0:devel/py-types-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
