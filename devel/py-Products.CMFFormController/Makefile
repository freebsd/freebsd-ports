# $FreeBSD$

PORTNAME=	Products.CMFFormController
PORTVERSION=	3.0.6
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Form validation mechanism for Zope CMF

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.structuredtext>=0:textproc/py-zope.structuredtext@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.tales>=0:devel/py-zope.tales@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:devel/py-Products.GenericSetup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
