PORTNAME=	stack-data
PORTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	stack_data-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extract data from python stack frames and tracebacks for informative displays
WWW=		https://github.com/alexmojaki/stack_data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=44:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.3:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asttokens>=2.1.0:devel/py-asttokens@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}executing>=1.2.0:devel/py-executing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pure-eval>=0:devel/py-pure-eval@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}littleutils>=0:devel/py-littleutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0,1:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typeguard>=0:devel/py-typeguard@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython_test pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
