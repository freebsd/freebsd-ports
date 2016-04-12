# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pytest-django
PORTVERSION=	2.9.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Django plugin for py.test

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django18>=0:www/py-django18 \
		${PYTHON_PKGNAMEPREFIX}django-configurations>=0:www/py-django-configurations \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0:devel/py-pytest-xdist \
		${PYTHON_PKGNAMEPREFIX}tox>=0:devel/py-tox \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel \
		${PYTHON_PKGNAMEPREFIX}twine>=0:devel/py-twine \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm \
		${PYTHON_PKGNAMEPREFIX}south>=0:databases/py-south
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
