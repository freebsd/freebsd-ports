# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_stock_supply
PORTVERSION=	2.8.1
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_stock_supply/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_stock_supply-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Stock Supply Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_stock>=2.8.2:${PORTSDIR}/finance/trytond28_stock \
		trytond28_purchase>=2.8.0:${PORTSDIR}/finance/trytond28_purchase

CONFLICTS=	trytond_stock_supply-2.[46].*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYEASYINSTALL_EGG=${DISTNAME}-py${PYTHON_VER}${PYEASYINSTALL_OSARCH}.egg

.include <bsd.port.mk>
