# $FreeBSD$

PORTNAME=	zope.globalrequest
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

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

USES=		python zip
USE_PYTHON=	distutils autoplist

post-extract:
	@${CHMOD} -R a+rX ${WRKSRC}

.include <bsd.port.mk>
