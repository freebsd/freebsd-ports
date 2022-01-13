# Created by: nwhitehorn

PORTNAME=	astropy
DISTVERSION=	5.0
PORTEPOCH=	2
CATEGORIES=	astro
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Community-developed python astronomy tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}extension-helpers>=0:astro/py-extension-helpers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pyerfa>=0:astro/py-pyerfa@${PY_FLAVOR}

USES=		compiler:c11 python:3.8+
USE_PYTHON=	autoplist cython distutils

CONFLICTS_INSTALL=	p5-Data-ShowTable # bin/showtable

.include <bsd.port.mk>
