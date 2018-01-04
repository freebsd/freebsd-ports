# $FreeBSD$

PORTNAME=	zope.app.generations
PORTVERSION=	3.7.1
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	ZMI UI for zope.generations

LICENSE=	ZPL21

RUN_DEPENDS=	zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.publication>=0:devel/py-zope.app.publication@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.renderer>=0:devel/py-zope.app.renderer@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.applicationcontrol>=0:devel/py-zope.applicationcontrol@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.generations>=0:devel/py-zope.generations@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.processlifetime>=0:devel/py-zope.processlifetime@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
