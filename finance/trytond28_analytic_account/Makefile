# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_analytic_account
PORTVERSION=	2.8.2
PORTREVISION=	2
CATEGORIES=	finance python
MASTER_SITES=	CHEESESHOP \
		http://downloads-cdn.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_analytic_account-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Analytic Account Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_company>=2.8.0:finance/trytond28_company \
		trytond28_party>=2.8.0:finance/trytond28_party \
		trytond28_currency>=2.8.0:finance/trytond28_currency \
		trytond28_account>=2.8.1:finance/trytond28_account

CONFLICTS=	trytond_analytic_account-2.[46].*

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
