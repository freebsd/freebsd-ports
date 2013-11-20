# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_purchase
PORTVERSION=	2.8.0
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_purchase/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_purchase-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Purchase Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_stock>=2.8.2:${PORTSDIR}/finance/trytond28_stock \
		trytond28_account_invoice>=2.8.2:${PORTSDIR}/finance/trytond28_account_invoice

CONFLICTS=	trytond_purchase-2.[46].*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYEASYINSTALL_EGG=${DISTNAME}-py${PYTHON_VER}${PYEASYINSTALL_OSARCH}.egg

.include <bsd.port.mk>
