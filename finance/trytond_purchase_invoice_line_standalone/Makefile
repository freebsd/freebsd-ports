# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond_purchase_invoice_line_standalone
PORTVERSION=	2.4.2
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann.it
COMMENT=	Tryton Application Platform (Purchase Invoice Line Standalone Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_purchase>=2.4.0:${PORTSDIR}/finance/trytond_purchase \
		trytond_account_invoice_line_standalone>=2.4.1:${PORTSDIR}/finance/trytond_account_invoice_line_standalone

DEPRECATED=	Upstream project no longer supports the Tryton 2.4 series
EXPIRATION_DATE=	2015-08-05

CONFLICTS=	trytond28_purchase_invoice_line_standalone-2.8.*

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
