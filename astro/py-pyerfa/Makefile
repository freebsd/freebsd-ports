PORTNAME=	pyerfa
DISTVERSION=	2.0.0.1
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python wrapper for the ERFA library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.17.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.17.0,1:math/py-numpy@${PY_FLAVOR}

USES=		python:3.6-3.9
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
