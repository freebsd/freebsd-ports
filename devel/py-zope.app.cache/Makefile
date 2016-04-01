# $FreeBSD$

PORTNAME=	zope.app.cache
PORTVERSION=	3.7.0
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Caching Framework

LICENSE=	ZPL21

RUN_DEPENDS=	zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}zope.annotation>=0:devel/py-zope.annotation \
		${PYTHON_PKGNAMEPREFIX}zope.app.form>=0:devel/py-zope.app.form \
		${PYTHON_PKGNAMEPREFIX}zope.app.pagetemplate>=0:devel/py-zope.app.pagetemplate \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.componentvocabulary>=0:devel/py-zope.componentvocabulary \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.proxy>=0:net/py-zope.proxy \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.ramcache>=0:devel/py-zope.ramcache \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:devel/py-zope.traversing

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
