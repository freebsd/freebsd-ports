# $FreeBSD$

PORTNAME=	trytond_account_invoice_line_standalone
PORTVERSION=	2.4.1
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann.it
COMMENT=	Tryton Application Platform (Account Invoice Line Standalone Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_account_invoice>=2.4.1:${PORTSDIR}/finance/trytond_account_invoice

CONFLICTS=	trytond_account_invoice_line_standalone-2.[68].*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
