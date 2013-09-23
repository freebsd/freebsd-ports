# $FreeBSD$

PORTNAME=	zope.globalrequest
PORTVERSION=	1.0
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Global way of retrieving the currently active request

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.testing>=0:${PORTSDIR}/devel/py-zope.testing \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:${PORTSDIR}/devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.app.publisher>=0:${PORTSDIR}/devel/py-zope.app.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.app.securitypolicy>=0:${PORTSDIR}/security/py-zope.app.securitypolicy \
		${PYTHON_PKGNAMEPREFIX}zope.app.testing>=0:${PORTSDIR}/devel/py-zope.app.testing \
		${PYTHON_PKGNAMEPREFIX}zope.app.zcmlfiles>=0:${PORTSDIR}/devel/py-zope.app.zcmlfiles \
		${PYTHON_PKGNAMEPREFIX}zope.testbrowser>=0:${PORTSDIR}/devel/py-zope.testbrowser

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes

NO_STAGE=	yes

.include <bsd.port.mk>
