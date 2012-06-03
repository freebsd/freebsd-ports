# New ports collection makefile for:	py-zope.tales
# Date created:				20 August 2011
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	zope.tales
PORTVERSION=	3.5.2
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Template Application Language Expression Syntax (TALES)

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.tal>=0:${PORTSDIR}/textproc/py-zope.tal \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface

USE_PYTHON=	-2.7
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
