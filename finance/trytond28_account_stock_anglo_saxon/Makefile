# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_account_stock_anglo_saxon
PORTVERSION=	2.8.0
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_account_stock_anglo_saxon/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_account_stock_anglo_saxon-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Account Stock Anglo Saxon Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_account_invoice>=2.8.2:${PORTSDIR}/finance/trytond28_account_invoice \
		trytond28_account_stock_continental>=2.8.1:${PORTSDIR}/finance/trytond28_account_stock_continental

CONFLICTS=	trytond_account_stock_anglo_saxon-2.[46].*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYEASYINSTALL_EGG=${DISTNAME}-py${PYTHON_VER}${PYEASYINSTALL_OSARCH}.egg

.include <bsd.port.mk>
