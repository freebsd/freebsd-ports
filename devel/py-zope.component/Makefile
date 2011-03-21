# New ports collection makefile for:	py-zope.component
# Date created:				2011-03-21
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zope.component
PORTVERSION=	3.10.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Zope Component Architecture

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zopeInterface>=3.3.0:${PORTSDIR}/devel/py-zopeInterface \
    		${PYTHON_PKGNAMEPREFIX}zopeevent>=0:${PORTSDIR}/devel/py-zopeevent
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
