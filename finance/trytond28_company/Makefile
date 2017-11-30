# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_company
PORTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_company/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_company-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Company Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_party>=2.8.0:finance/trytond28_party \
		trytond28_currency>=2.8.0:finance/trytond28_currency

CONFLICTS=	trytond_company-2.[46].*

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
