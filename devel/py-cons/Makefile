PORTNAME=	cons
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.7
#MASTER_SITES=	PYPI # no tests
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of Lisp/Scheme-like cons in Python
WWW=		https://github.com/pythological/python-cons/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}logical-unification>=0.4.0:math/py-logical-unification@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # tests fail intermittently, see https://github.com/pythological/python-cons/issues/15

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	pythological
GH_PROJECT=	python-cons

NO_ARCH=	yes

# tests as of 0.4.7: 8 passed in 0.35s

.include <bsd.port.mk>
