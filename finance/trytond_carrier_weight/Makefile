# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond_carrier_weight
PORTVERSION=	2.4.0
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann.it
COMMENT=	Tryton Application Platform (Carrier Weight Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_product_measurements>=2.4.0:${PORTSDIR}/finance/trytond_product_measurements \
		trytond_carrier>=2.4.1:${PORTSDIR}/finance/trytond_carrier

CONFLICTS=	trytond28_carrier_weight-2.8.*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
