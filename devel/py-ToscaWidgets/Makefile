# New ports collection makefile for:	py-ToscaWidgets
# Date created:		1st July, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$

PORTNAME=	ToscaWidgets
PORTVERSION=	0.9.7.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A python framework for building reusable web components

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}webob>=0:${PORTSDIR}/www/py-webob \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:${PORTSDIR}/devel/py-simplejson
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
