# $FreeBSD$

PORTNAME=	DocumentTemplate
PORTVERSION=	2.13.2
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Document Templating Markup Language (DTML)

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}AccessControl>=0:security/py-AccessControl \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:devel/py-ExtensionClass \
		${PYTHON_PKGNAMEPREFIX}RestrictedPython>=0:security/py-RestrictedPython \
		${PYTHON_PKGNAMEPREFIX}zExceptions>=0:devel/py-zExceptions \
		${PYTHON_PKGNAMEPREFIX}zope.sequencesort>=0:devel/py-zope.sequencesort \
		${PYTHON_PKGNAMEPREFIX}zope.structuredtext>=0:textproc/py-zope.structuredtext

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
