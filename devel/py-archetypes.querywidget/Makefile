# $FreeBSD$

PORTNAME=	archetypes.querywidget
PORTVERSION=	1.0.9
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Widget for creating catalog queries

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.app.querystring>=1.0.3:${PORTSDIR}/www/py-plone.app.querystring \
		${PYTHON_PKGNAMEPREFIX}plone.app.jquerytools>=0:${PORTSDIR}/www/py-plone.app.jquerytools

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USE_ZIP=		yes

.include <bsd.port.mk>
