# $FreeBSD$

PORTNAME=	zope.publisher
PORTVERSION=	3.13.0
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Publishes Python objects on the web

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.proxy>=0:${PORTSDIR}/net/py-zope.proxy \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:${PORTSDIR}/devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:${PORTSDIR}/devel/py-zope.testing \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:${PORTSDIR}/devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.browser>=0:${PORTSDIR}/devel/py-zope.browser \
		${PYTHON_PKGNAMEPREFIX}zope.contenttype>=3.5:${PORTSDIR}/devel/py-zope.contenttype \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:${PORTSDIR}/devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.exceptions>=0:${PORTSDIR}/devel/py-zope.exceptions \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:${PORTSDIR}/devel/py-zope.i18n

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
