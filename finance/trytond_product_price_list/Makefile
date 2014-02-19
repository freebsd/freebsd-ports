# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond_product_price_list
PORTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann.it
COMMENT=	Tryton Application Platform (Product Price List Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_product>=2.4.0:${PORTSDIR}/finance/trytond_product \
		trytond_party>=2.4.0:${PORTSDIR}/finance/trytond_party \
		trytond_company>=2.4.0:${PORTSDIR}/finance/trytond_company

CONFLICTS=	trytond28_product_price_list-2.8.*

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
