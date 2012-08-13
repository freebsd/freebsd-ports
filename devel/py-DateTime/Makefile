# New ports collection makefile for:	py-DateTime
# Date created:				10 October, 2011
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	DateTime
PORTVERSION=	3.0
PORTEPOCH=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope 2 DateTime data type

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>=0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface

USE_PYTHON=	-2.7
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes

.include <bsd.port.mk>
