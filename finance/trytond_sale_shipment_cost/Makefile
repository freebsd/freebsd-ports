# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond_sale_shipment_cost
PORTVERSION=	2.4.1
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Sale Shipment Cost Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_carrier>=2.4.1:${PORTSDIR}/finance/trytond_carrier \
		trytond_sale>=2.4.0:${PORTSDIR}/finance/trytond_sale \
		trytond_account_invoice>=2.4.1:${PORTSDIR}/finance/trytond_account_invoice \
		trytond_stock>=2.4.0:${PORTSDIR}/finance/trytond_stock

CONFLICTS=	trytond_sale_shipment_cost-2.[68].*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
