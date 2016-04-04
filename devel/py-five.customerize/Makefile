# $FreeBSD$

PORTNAME=	five.customerize
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	TTW customization of template-based Zope views

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.portlets>=0:www/py-plone.portlets \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.componentvocabulary>=0:devel/py-zope.componentvocabulary \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>=0:devel/py-zope.dottedname \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.pagetemplate>=0:devel/py-zope.pagetemplate \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:devel/py-zope.testing \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:devel/py-zope.traversing \
		${PYTHON_PKGNAMEPREFIX}zope.viewlet>=0:devel/py-zope.viewlet \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition

USE_PYTHON=	distutils autoplist
USES=		python:2 zope zip

.include <bsd.port.mk>
