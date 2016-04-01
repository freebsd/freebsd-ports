# $FreeBSD$

PORTNAME=	zope.app.zcmlfiles
PORTVERSION=	3.7.1
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope application server ZCML files

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.annotation>=0:devel/py-zope.annotation \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.componentvocabulary>=0:devel/py-zope.componentvocabulary \
		${PYTHON_PKGNAMEPREFIX}zope.copypastemove>=0:devel/py-zope.copypastemove \
		${PYTHON_PKGNAMEPREFIX}zope.dublincore>=0:devel/py-zope.dublincore \
		${PYTHON_PKGNAMEPREFIX}zope.formlib>=0:devel/py-zope.formlib \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.size>=0:devel/py-zope.size \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:devel/py-zope.traversing \
		${PYTHON_PKGNAMEPREFIX}zope.app.applicationcontrol>=0:devel/py-zope.app.applicationcontrol \
		${PYTHON_PKGNAMEPREFIX}zope.app.appsetup>=0:devel/py-zope.app.appsetup \
		${PYTHON_PKGNAMEPREFIX}zope.app.basicskin>=0:devel/py-zope.app.basicskin \
		${PYTHON_PKGNAMEPREFIX}zope.app.broken>=0:devel/py-zope.app.broken \
		${PYTHON_PKGNAMEPREFIX}zope.app.component>=0:devel/py-zope.app.component \
		${PYTHON_PKGNAMEPREFIX}zope.app.container>=0:devel/py-zope.app.container \
		${PYTHON_PKGNAMEPREFIX}zope.app.content>=0:devel/py-zope.app.content \
		${PYTHON_PKGNAMEPREFIX}zope.app.dependable>=0:devel/py-zope.app.dependable \
		${PYTHON_PKGNAMEPREFIX}zope.app.error>=0:devel/py-zope.app.error \
		${PYTHON_PKGNAMEPREFIX}zope.app.exception>=0:devel/py-zope.app.exception \
		${PYTHON_PKGNAMEPREFIX}zope.app.folder>=0:devel/py-zope.app.folder \
		${PYTHON_PKGNAMEPREFIX}zope.app.form>=0:devel/py-zope.app.form \
		${PYTHON_PKGNAMEPREFIX}zope.app.generations>=0:devel/py-zope.app.generations \
		${PYTHON_PKGNAMEPREFIX}zope.app.http>=0:devel/py-zope.app.http \
		${PYTHON_PKGNAMEPREFIX}zope.app.i18n>=0:textproc/py-zope.app.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.app.locales>=3.6.0:textproc/py-zope.app.locales \
		${PYTHON_PKGNAMEPREFIX}zope.app.pagetemplate>=0:devel/py-zope.app.pagetemplate \
		${PYTHON_PKGNAMEPREFIX}zope.app.principalannotation>=0:security/py-zope.app.principalannotation \
		${PYTHON_PKGNAMEPREFIX}zope.app.publication>=0:devel/py-zope.app.publication \
		${PYTHON_PKGNAMEPREFIX}zope.app.publisher>=0:devel/py-zope.app.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.app.rotterdam>=0:devel/py-zope.app.rotterdam \
		${PYTHON_PKGNAMEPREFIX}zope.app.schema>=0:devel/py-zope.app.schema \
		${PYTHON_PKGNAMEPREFIX}zope.app.security>=0:security/py-zope.app.security \
		${PYTHON_PKGNAMEPREFIX}zope.app.wsgi>=0:www/py-zope.app.wsgi \
		${PYTHON_PKGNAMEPREFIX}zope.app.zopeappgenerations>=0:devel/py-zope.app.zopeappgenerations

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
