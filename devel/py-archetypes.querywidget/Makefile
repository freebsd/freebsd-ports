# $FreeBSD$

PORTNAME=	archetypes.querywidget
PORTVERSION=	1.0.9
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Widget for creating catalog queries

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.app.querystring>=1.0.3:${PORTSDIR}/www/py-plone.app.querystring \
		${PYTHON_PKGNAMEPREFIX}plone.app.jquerytools>=0:${PORTSDIR}/www/py-plone.app.jquerytools

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes

NO_STAGE=	yes

.include <bsd.port.mk>
