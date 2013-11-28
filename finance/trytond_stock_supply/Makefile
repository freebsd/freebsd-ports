# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond_stock_supply
PORTVERSION=	2.4.4
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Stock Supply Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_stock>=2.4.0:${PORTSDIR}/finance/trytond_stock \
		trytond_purchase>=2.4.0:${PORTSDIR}/finance/trytond_purchase

CONFLICTS=	trytond28_stock_supply-2.8.*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
