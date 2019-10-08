# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_stock_supply_day
PORTVERSION=	2.8.1
PORTREVISION=	2
CATEGORIES=	finance python
MASTER_SITES=	CHEESESHOP \
		http://downloads-cdn.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_stock_supply_day-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Stock Supply Day Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_stock>=2.8.2:finance/trytond28_stock \
		trytond28_purchase>=2.8.0:finance/trytond28_purchase

CONFLICTS=	trytond_stock_supply_day-2.[46].*

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
