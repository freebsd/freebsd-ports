# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond_account_stock_continental
PORTVERSION=	2.4.3
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Account Stock Continental Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_account_product>=2.4.1:${PORTSDIR}/finance/trytond_account_product \
		trytond_stock>=2.4.0:${PORTSDIR}/finance/trytond_stock

DEPRECATED=	Upstream project no longer supports the Tryton 2.4 series
EXPIRATION_DATE=	2015-08-05

CONFLICTS=	trytond28_account_stock_continental-2.8.*

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
