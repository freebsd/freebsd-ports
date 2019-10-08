# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_purchase_invoice_line_standalone
PORTVERSION=	2.8.1
PORTREVISION=	2
CATEGORIES=	finance python
MASTER_SITES=	CHEESESHOP \
		http://downloads-cdn.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_purchase_invoice_line_standalone-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Purchase Invoice Line Standalone Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_purchase>=2.8.0:finance/trytond28_purchase \
		trytond28_account_invoice_line_standalone>=2.8.0:finance/trytond28_account_invoice_line_standalone

CONFLICTS=	trytond_purchase_invoice_line_standalone-2.[46].*

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
