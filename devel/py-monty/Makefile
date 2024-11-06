PORTNAME=	monty
DISTVERSIONPREFIX=	v
DISTVERSION=	2024.10.21
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Monty is the missing complement to Python
WWW=		https://github.com/materialsvirtuallab/monty

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>0:devel/py-ruamel.yaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	materialsvirtuallab

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
