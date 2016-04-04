# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_account_statement
PORTVERSION=	2.8.1
CATEGORIES=	finance python
MASTER_SITES=	CHEESESHOP \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_account_statement-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Account Statement Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_account_invoice>=2.8.2:finance/trytond28_account_invoice

CONFLICTS=	trytond_account_statement-2.[46].*

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
