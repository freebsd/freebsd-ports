PORTNAME=	zope.publisher
PORTVERSION=	3.13.1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Publishes Python objects on the web

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.proxy>=0:net/py-zope.proxy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:devel/py-zope.location@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:devel/py-zope.testing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browser>=0:devel/py-zope.browser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.contenttype>=3.5:devel/py-zope.contenttype@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.exceptions>=0:devel/py-zope.exceptions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n@${PY_FLAVOR}

USES=		python:3.6+ zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
