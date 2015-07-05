# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond_account_stock_anglo_saxon
PORTVERSION=	2.4.6
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Account Stock Anglo Saxon Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_account_invoice>=2.4.1:${PORTSDIR}/finance/trytond_account_invoice \
		trytond_account_stock_continental>=2.4.1:${PORTSDIR}/finance/trytond_account_stock_continental

DEPRECATED=	Upstream project no longer supports the Tryton 2.4 series
EXPIRATION_DATE=	2015-08-05

CONFLICTS=	trytond28_account_stock_anglo_saxon-2.8.*

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
