# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	repoze.who-testutil
PORTVERSION=	1.0.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Test utilities for repoze.who-powered applications

LICENSE=	BSD4CLAUSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-12-12

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}repoze.who>=1.0.15:devel/py-repoze.who@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pastedeploy>=1.3.3:www/py-pastedeploy@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
