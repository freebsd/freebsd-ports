# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_sale_shipment_cost
PORTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_sale_shipment_cost/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_sale_shipment_cost-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Sale Shipment Cost Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_carrier>=2.8.0:finance/trytond28_carrier \
		trytond28_sale>=2.8.1:finance/trytond28_sale \
		trytond28_account_invoice>=2.8.2:finance/trytond28_account_invoice \
		trytond28_stock>=2.8.2:finance/trytond28_stock

CONFLICTS=	trytond_sale_shipment_cost-2.[46].*

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
