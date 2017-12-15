# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_account_invoice
PORTVERSION=	2.8.8
CATEGORIES=	finance python
MASTER_SITES=	CHEESESHOP \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_account_invoice-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Account Invoice Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_account_product>=2.8.0:finance/trytond28_account_product

CONFLICTS=	trytond_account_invoice-2.[46].*

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
