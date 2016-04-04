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

RUN_DEPENDS=	zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}zope.app.publication>=0:devel/py-zope.app.publication \
		${PYTHON_PKGNAMEPREFIX}zope.app.renderer>=0:devel/py-zope.app.renderer \
		${PYTHON_PKGNAMEPREFIX}zope.applicationcontrol>=0:devel/py-zope.applicationcontrol \
		${PYTHON_PKGNAMEPREFIX}zope.generations>=0:devel/py-zope.generations \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.processlifetime>=0:devel/py-zope.processlifetime

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
