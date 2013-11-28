# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_account_asset
PORTVERSION=	2.8.0
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_account_asset/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_account_asset-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Account Asset Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_product>=2.8.0:${PORTSDIR}/finance/trytond28_product \
		trytond28_account_invoice>=2.8.2:${PORTSDIR}/finance/trytond28_account_invoice

CONFLICTS=	trytond_account-2.[46].*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYEASYINSTALL_EGG=${DISTNAME}-py${PYTHON_VER}${PYEASYINSTALL_OSARCH}.egg

.include <bsd.port.mk>
