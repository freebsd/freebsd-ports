# New ports collection makefile for:	py-zope.app.generations
# Date created:				20 December 2011
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	zope.app.generations
PORTVERSION=	3.7.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	ZMI UI for zope.generations

LICENSE=	ZPL21

RUN_DEPENDS=	zodb${PYTHON_PKGNAMESUFFIX}>=0:${PORTSDIR}/databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}zope.app.publication>=0:${PORTSDIR}/devel/py-zope.app.publication \
		${PYTHON_PKGNAMEPREFIX}zope.app.renderer>=0:${PORTSDIR}/devel/py-zope.app.renderer \
		${PYTHON_PKGNAMEPREFIX}zope.applicationcontrol>=0:${PORTSDIR}/devel/py-zope.applicationcontrol \
		${PYTHON_PKGNAMEPREFIX}zope.generations>=0:${PORTSDIR}/devel/py-zope.generations \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.processlifetime>=0:${PORTSDIR}/devel/py-zope.processlifetime

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
