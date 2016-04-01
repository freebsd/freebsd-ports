# $FreeBSD$

PORTNAME=	Products.validation
PORTVERSION=	2.0.1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Data validation package for Archetypes

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:devel/py-DateTime

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
