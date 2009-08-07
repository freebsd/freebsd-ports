# New ports collection makefile for:	py-repoze.who-testutil
# Date created:		3rd August,2009
# Whom:	      		Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	repoze.who-testutil
PORTVERSION=	1.0r1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-1.0rc1

MAINTAINER=	wenheping@gmail.com
COMMENT=	Test utilities for repoze.who-powered applications

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}repoze.who>=1.0.15:${PORTSDIR}/devel/py-repoze.who \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.3.3:${PORTSDIR}/www/py-pastedeploy
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	repoze.who_testutil
PYDISTUTILS_PKGVERSION=	1.0rc1

.include <bsd.port.mk>
