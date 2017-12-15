# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	repoze.what
PORTVERSION=	1.0.9
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Authorization for WSGI applications

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Paste>=1.7.2:www/py-paste@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}repoze.who-testutil>=0:devel/py-repoze.who-testutil@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
