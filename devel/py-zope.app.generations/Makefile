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

DEPRECATED=	Old, uses EOLed python27
EXPIRATION_DATE=	2020-02-18

RUN_DEPENDS=	zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.publication>=0:devel/py-zope.app.publication@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.renderer>=0:devel/py-zope.app.renderer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.applicationcontrol>=0:devel/py-zope.applicationcontrol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.generations>=0:devel/py-zope.generations@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.processlifetime>=0:devel/py-zope.processlifetime@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
