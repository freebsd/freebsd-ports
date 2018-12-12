# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_analytic_purchase
PORTVERSION=	2.8.0
PORTREVISION=	2
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_analytic_purchase/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_analytic_purchase-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Analytic Purchase Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_analytic_account>=2.8.0:finance/trytond28_analytic_account \
		trytond28_analytic_invoice>=2.8.0:finance/trytond28_analytic_invoice \
		trytond28_purchase>=2.8.0:finance/trytond28_purchase

CONFLICTS=	trytond_analytic_purchase-2.[46].*

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
