# $FreeBSD$

PORTNAME=	zope.browserresource
PORTVERSION=	3.10.3
PORTEPOCH=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Browser resources implementation for Zope

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.component>=3.8.0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:${PORTSDIR}/devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.contenttype>=0:${PORTSDIR}/devel/py-zope.contenttype \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:${PORTSDIR}/devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:${PORTSDIR}/devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=3.8:${PORTSDIR}/devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>3.7:${PORTSDIR}/devel/py-zope.traversing

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
