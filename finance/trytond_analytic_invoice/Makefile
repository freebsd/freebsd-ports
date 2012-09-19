# Created by: Matthias Petermann<matthias@petermann.it>
# $FreeBSD$

PORTNAME=	trytond_analytic_invoice
PORTVERSION=	2.4.1
CATEGORIES=	finance python
MASTER_SITES=	http://downloads2.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann.it
COMMENT=	Tryton Application Platform (Analytic Invoice Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_analytic_account>=2.4.1:${PORTSDIR}/finance/trytond_analytic_account \
		trytond_account_invoice>=2.4.1:${PORTSDIR}/finance/trytond_account_invoice

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
