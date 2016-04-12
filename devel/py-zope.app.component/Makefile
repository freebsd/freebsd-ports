# $FreeBSD$

PORTNAME=	zope.app.component
PORTVERSION=	3.9.3
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Local Zope Component Support

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.site>=0:devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}zope.app.container>=0:devel/py-zope.app.container \
		${PYTHON_PKGNAMEPREFIX}zope.app.pagetemplate>=0:devel/py-zope.app.pagetemplate \
		${PYTHON_PKGNAMEPREFIX}zope.component>=3.8:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.deprecation>=0:devel/py-zope.deprecation \
		${PYTHON_PKGNAMEPREFIX}zope.exceptions>=0:devel/py-zope.exceptions \
		${PYTHON_PKGNAMEPREFIX}zope.formlib>=0:devel/py-zope.formlib \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=3.12.0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:devel/py-zope.traversing \
		${PYTHON_PKGNAMEPREFIX}zope.componentvocabulary>=0:devel/py-zope.componentvocabulary

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
