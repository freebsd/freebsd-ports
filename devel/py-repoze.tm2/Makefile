# New ports collection makefile for:	py-repoze.tm2
# Date created:		9th August,2009
# Whom:	      		Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	repoze.tm2
PORTVERSION=	1.0a4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Zope-like transaction manager via WSGI middleware

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}transaction>=1.0.0:${PORTSDIR}/devel/py-transaction
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
