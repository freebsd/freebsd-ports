# $FreeBSD$

PORTNAME=	archetypes.referencebrowserwidget
PORTVERSION=	2.5.7
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Implementation of referencebrowser widget for Archetypes

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.formlib>=0:devel/py-zope.formlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.form>=0:www/py-plone.app.form@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.jquerytools>=1.1:www/py-plone.app.jquerytools@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
