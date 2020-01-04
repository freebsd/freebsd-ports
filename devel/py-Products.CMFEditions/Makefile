# $FreeBSD$

PORTNAME=	Products.CMFEditions
PORTVERSION=	2.2.19
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Versioning for Plone

DEPRECATED=	Outdated, uses EOLed python27
EXPIRATION_DATE=	2020-02-05

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.copy>0:devel/py-zope.copy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>=0:devel/py-zope.dottedname@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=2.1:devel/py-Products.CMFCore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDiffTool>=0:devel/py-Products.CMFDiffTool@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFUid>=0:devel/py-Products.CMFUid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=1.4.0:devel/py-Products.GenericSetup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ZopeVersionControl>=0:devel/py-Products.ZopeVersionControl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:devel/py-DateTime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction@${PY_FLAVOR} \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
