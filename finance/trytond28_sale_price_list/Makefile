# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_sale_price_list
PORTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_sale_price_list/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_sale_price_list-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Sale Price List Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_party>=2.8.0:finance/trytond28_party \
		trytond28_sale>=2.8.1:finance/trytond28_sale \
		trytond28_product_price_list>=2.8.0:finance/trytond28_product_price_list

CONFLICTS=	trytond_sale_price_list-2.[46].*

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
