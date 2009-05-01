# New ports collection makefile for:	py-zopetesting
# Date created:		22 Nov, 2008
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	zopetesting
PORTVERSION=	3.7.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	zope.testing-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Zope Testing Framework(including the testrunner script)

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zopeInterface>=3.3.0:${PORTSDIR}/devel/py-zopeInterface
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	zope.testing

.include <bsd.port.mk>
