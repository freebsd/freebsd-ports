PORTNAME=	zope.browserresource
PORTVERSION=	3.10.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Browser resources implementation for Zope

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.component>=3.8.0:devel/py-zope.component@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.contenttype>=0:devel/py-zope.contenttype@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:devel/py-zope.location@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=3.8:devel/py-zope.publisher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>3.7:devel/py-zope.traversing@${PY_FLAVOR}

USES=		python:3.6+ zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
