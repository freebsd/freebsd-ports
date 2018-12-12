# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_purchase_shipment_cost
PORTVERSION=	2.8.0
PORTREVISION=	2
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_purchase_shipment_cost/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_purchase_shipment_cost-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Purchase Shipment Cost Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_carrier>=2.8.0:finance/trytond28_carrier \
		trytond28_currency>=2.8.0:finance/trytond28_currency \
		trytond28_stock>=2.8.2:finance/trytond28_stock

CONFLICTS=	trytond_purchase_shipment_cost-2.[46].*

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
