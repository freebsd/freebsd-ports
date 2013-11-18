# $FreeBSD$

PORTNAME=	trytond_analytic_sale
PORTVERSION=	2.4.2
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann.it
COMMENT=	Tryton Application Platform (Analytic Sale Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_analytic_account>=2.4.1:${PORTSDIR}/finance/trytond_analytic_account \
		trytond_analytic_invoice>=2.4.1:${PORTSDIR}/finance/trytond_analytic_invoice \
		trytond_sale>=2.4.0:${PORTSDIR}/finance/trytond_sale

CONFLICTS=	trytond_analytic_sale-2.[68].*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
