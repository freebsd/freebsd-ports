# New ports collection makefile for:	py-Products.OFSP
# Date created:				Nov 14, 2011
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	Products.OFSP
PORTVERSION=	2.13.2
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	General Zope 2 help screens

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}AccessControl>=0:${PORTSDIR}/security/py-AccessControl \
		${PYTHON_PKGNAMEPREFIX}Persistence>=0:${PORTSDIR}/devel/py-Persistence

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes

.include <bsd.port.mk>
