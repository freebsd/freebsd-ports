PORTNAME=	pytest-runner
PORTVERSION=	6.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Test support for pytest runner in setup.py
WWW=		https://github.com/pytest-dev/pytest-runner

LICENSE=	MIT

DEPRECATED=	pytest-runner depends on deprecated features of setuptools
EXPIRATION_DATE=	2024-12-31

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=3.4.1:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
