# New ports collection makefile for:	py-zope.schema
# Date created:				2011-03-21
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zope.schema
PORTVERSION=	3.8.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Zope Interface extension for defining data schemas

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zopeInterface>=3.3.0:${PORTSDIR}/devel/py-zopeInterface \
    		${PYTHON_PKGNAMEPREFIX}zopeevent>=0:${PORTSDIR}/devel/py-zopeevent
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
