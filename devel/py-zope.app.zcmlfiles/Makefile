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

DEPRECATED=	Old, uses EOLed python27
EXPIRATION_DATE=	2020-02-18

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.annotation>=0:devel/py-zope.annotation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.componentvocabulary>=0:devel/py-zope.componentvocabulary@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.copypastemove>=0:devel/py-zope.copypastemove@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.dublincore>=0:devel/py-zope.dublincore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.formlib>=0:devel/py-zope.formlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:devel/py-zope.location@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.size>=0:devel/py-zope.size@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:devel/py-zope.traversing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.applicationcontrol>=0:devel/py-zope.app.applicationcontrol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.appsetup>=0:devel/py-zope.app.appsetup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.basicskin>=0:devel/py-zope.app.basicskin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.broken>=0:devel/py-zope.app.broken@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.component>=0:devel/py-zope.app.component@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.container>=0:devel/py-zope.app.container@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.content>=0:devel/py-zope.app.content@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.dependable>=0:devel/py-zope.app.dependable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.error>=0:devel/py-zope.app.error@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.exception>=0:devel/py-zope.app.exception@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.folder>=0:devel/py-zope.app.folder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.form>=0:devel/py-zope.app.form@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.generations>=0:devel/py-zope.app.generations@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.http>=0:devel/py-zope.app.http@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.i18n>=0:textproc/py-zope.app.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.locales>=3.6.0:textproc/py-zope.app.locales@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.pagetemplate>=0:devel/py-zope.app.pagetemplate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.principalannotation>=0:security/py-zope.app.principalannotation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.publication>=0:devel/py-zope.app.publication@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.publisher>=0:devel/py-zope.app.publisher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.rotterdam>=0:devel/py-zope.app.rotterdam@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.schema>=0:devel/py-zope.app.schema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.security>=0:security/py-zope.app.security@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.wsgi>=0:www/py-zope.app.wsgi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.zopeappgenerations>=0:devel/py-zope.app.zopeappgenerations@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
