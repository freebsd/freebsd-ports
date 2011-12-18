# New ports collection makefile for:	py-Products.GenericSetup
# Date created:				18 December 2011
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	Products.GenericSetup
PORTVERSION=	1.6.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Read Zope configuration state from profile dirs / tarballs

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}five.localsitemanager>=0:${PORTSDIR}/devel/py-five.localsitemanager \
		${PYTHON_PKGNAMEPREFIX}zope.formlib>=0:${PORTSDIR}/devel/py-zope.formlib

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
