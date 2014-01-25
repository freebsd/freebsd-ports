# $FreeBSD$

PORTNAME=	Products.ATReferenceBrowserWidget
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Reference widget for Archetypes

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}archetypes.referencebrowserwidget>=0:${PORTSDIR}/devel/py-archetypes.referencebrowserwidget \
		${PYTHON_PKGNAMEPREFIX}zope.deprecation>=0:${PORTSDIR}/devel/py-zope.deprecation

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USE_ZIP=		yes

.include <bsd.port.mk>
