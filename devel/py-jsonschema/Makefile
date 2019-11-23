# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jsonschema
PORTVERSION=	3.2.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	JSON Schema validation for Python

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vcversioner>0:devel/py-vcversioner@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.7:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=17.4.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyrsistent>=0.14.0:devel/py-pyrsistent@${PY_FLAVOR}
py27_RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}functools32>0:devel/py-functools32@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
