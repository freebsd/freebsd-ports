# $FreeBSD$

PORTNAME=	zope.pagetemplate
PORTVERSION=	3.6.3
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Page Templates

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.tal>=0:textproc/py-zope.tal \
		${PYTHON_PKGNAMEPREFIX}zope.tales>=0:devel/py-zope.tales \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:devel/py-zope.traversing

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
