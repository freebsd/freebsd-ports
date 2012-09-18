# New ports collection makefile for:	trytond_product_price_list
# Date created:		07 September, 2012
# Whom:			Matthias Petermann<matthias@petermann.it>
#
# $FreeBSD$
#

PORTNAME=	trytond_product_price_list
PORTVERSION=	2.4.0
CATEGORIES=	finance python
MASTER_SITES=	http://downloads2.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann.it
COMMENT=	Tryton Application Platform (Product Price List Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_product>=2.4.0:${PORTSDIR}/finance/trytond_product \
		trytond_party>=2.4.0:${PORTSDIR}/finance/trytond_party \
		trytond_company>=2.4.0:${PORTSDIR}/finance/trytond_company

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
