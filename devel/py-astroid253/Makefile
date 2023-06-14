PORTNAME=	astroid
PORTVERSION=	2.5.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	253

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Abstract syntax tree for Python with inference support (legacy version)
WWW=		https://github.com/PyCQA/astroid

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lazy-object-proxy>=0:devel/py-lazy-object-proxy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=0:devel/py-wrapt@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR} \
		${PYNUMPY}

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

CONFLICTS=	${PYTHON_PKGNAMEPREFIX}astroid

NO_ARCH=	yes
PYTEST_IGNORED_TESTS=	test_find_distutils_submodules_in_virtualenv

PORTSCOUT=	ignore:1

.include <bsd.port.mk>
