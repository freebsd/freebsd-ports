# $FreeBSD$

PORTNAME=	zope.app.zopeappgenerations
PORTVERSION=	3.6.1
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Application ZODB Update Generations

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.annotation>=0:devel/py-zope.annotation@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.authentication>=0:security/py-zope.app.authentication@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.component>=0:devel/py-zope.app.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.copypastemove>=0:devel/py-zope.copypastemove@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.dublincore>=0:devel/py-zope.dublincore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.generations>=0:devel/py-zope.generations@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
