# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	repoze.what-pylons
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	The repoze.what v1 plugin for Pylons/TG2 integration

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylons>=0.9.7:www/py-pylons@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}repoze.what>=0:devel/py-repoze.what@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=3.5.2:devel/py-zope.interface@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
