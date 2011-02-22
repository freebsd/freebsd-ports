# New ports collection makefile for:	py-zopetesting
# Date created:		22 Nov, 2008
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	zopetesting
PORTVERSION=	3.10.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	zope.testing-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Zope Testing Framework(including the testrunner script)

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zopeInterface>=3.3.0:${PORTSDIR}/devel/py-zopeInterface \
		${PYTHON_PKGNAMEPREFIX}zope.exceptions>=3.5.2:${PORTSDIR}/devel/py-zope.exceptions
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	zope.testing

.include <bsd.port.mk>
