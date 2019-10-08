# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_dashboard
PORTVERSION=	2.8.0
PORTREVISION=	3
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_dashboard/ \
		http://downloads-cdn.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_dashboard-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Dashboard Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28>=2.8.2:finance/trytond28

CONFLICTS=	trytond_dashboard-2.[46].*

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
