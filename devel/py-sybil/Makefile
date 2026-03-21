PORTNAME=	sybil
DISTVERSION=	9.3.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Automated testing for the examples in your code and documentation
WWW=		https://sybil.readthedocs.io/ \
		https://github.com/simplistix/sybil

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mypy>0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}myst-parser>0:textproc/py-myst-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}seedir>0:devel/py-seedir@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testfixtures>0:devel/py-testfixtures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-pyyaml>0:devel/py-types-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
