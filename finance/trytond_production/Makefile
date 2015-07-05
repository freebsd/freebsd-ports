# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond_production
PORTVERSION=	2.4.4
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Production Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_product>=2.4.0:${PORTSDIR}/finance/trytond_product \
		trytond_company>=2.4.0:${PORTSDIR}/finance/trytond_company \
		trytond_stock>=2.4.0:${PORTSDIR}/finance/trytond_stock

DEPRECATED=	Upstream project no longer supports the Tryton 2.4 series
EXPIRATION_DATE=	2015-08-05

CONFLICTS=	trytond28_production-2.8.*

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
