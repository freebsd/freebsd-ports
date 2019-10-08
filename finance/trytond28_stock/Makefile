# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_stock
PORTVERSION=	2.8.9
PORTREVISION=	2
CATEGORIES=	finance python
MASTER_SITES=	CHEESESHOP \
		http://downloads-cdn.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_stock-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Stock Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_party>=2.8.0:finance/trytond28_party \
		trytond28_product>=2.8.0:finance/trytond28_product \
		trytond28_company>=2.8.0:finance/trytond28_company \
		trytond28_currency>=2.8.0:finance/trytond28_currency

CONFLICTS=	trytond_stock-2.[46].*

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
