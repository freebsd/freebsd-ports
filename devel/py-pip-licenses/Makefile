PORTNAME=	pip-licenses
PORTVERSION=	5.5.5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pip_licenses-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dump the software license list of Python packages installed with pip
WWW=		https://github.com/raimon49/pip-licenses

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}prettytable>=3.12.0:devel/py-prettytable@${PY_FLAVOR} \
		${PY_TOMLI}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0,1:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli-w>=0:textproc/py-tomli-w@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
