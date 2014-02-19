# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond_stock_split
PORTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Stock Split Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_stock>=2.4.0:${PORTSDIR}/finance/trytond_stock

CONFLICTS=	trytond28_stock_split-2.8.*

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
