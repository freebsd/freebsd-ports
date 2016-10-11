# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	twine
PORTVERSION=	1.8.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Collection of utilities for interacting with PyPI

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}clint>=0:devel/py-clint \
		${PYTHON_PKGNAMEPREFIX}pkginfo>=0:sysutils/py-pkginfo \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0:www/py-requests-toolbelt \
		${PYTHON_PKGNAMEPREFIX}setuptools27>=0:devel/py-setuptools27

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
