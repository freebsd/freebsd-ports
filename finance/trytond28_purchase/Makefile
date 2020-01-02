# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_purchase
PORTVERSION=	2.8.4
PORTREVISION=	2
CATEGORIES=	finance python
MASTER_SITES=	CHEESESHOP \
		http://downloads-cdn.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_purchase-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Purchase Module)

DEPRECATED=	Outdated, uses EOLed python27
EXPIRATION_DATE=	2020-02-03

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_stock>=2.8.2:finance/trytond28_stock \
		trytond28_account_invoice>=2.8.2:finance/trytond28_account_invoice

CONFLICTS=	trytond_purchase-2.[46].*

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
