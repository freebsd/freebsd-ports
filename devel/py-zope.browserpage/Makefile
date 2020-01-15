# $FreeBSD$

PORTNAME=	zope.browserpage
PORTVERSION=	4.1.0
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	ZCML directives for configuring browser views for Zope

LICENSE=	ZPL21

DEPRECATED=	Old, uses EOLed python27
EXPIRATION_DATE=	2020-02-20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.pagetemplate>=0:devel/py-zope.pagetemplate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=3.7:devel/py-zope.component@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.contenttype>=0:devel/py-zope.contenttype@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=3.8:devel/py-zope.publisher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.security>=3.8:security/py-zope.security@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=3.7:devel/py-zope.traversing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browsermenu>=0:devel/py-zope.browsermenu@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
