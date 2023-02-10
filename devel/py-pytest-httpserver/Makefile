PORTNAME=	pytest-httpserver
PORTVERSION=	1.0.6
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytest_httpserver-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP server for pytest
WWW=		https://github.com/csernazs/pytest-httpserver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}werkzeug>=2.0.0:www/py-werkzeug@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-requests>=0:devel/py-types-requests@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes
TEST_ENV=	PYTEST_HTTPSERVER_HOST=127.0.0.1 PYTEST_HTTPSERVER_PORT=80

.include <bsd.port.mk>
