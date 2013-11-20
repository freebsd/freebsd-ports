# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_analytic_sale
PORTVERSION=	2.8.0
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_analytic_sale/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_analytic_sale-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Analytic Sale Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_analytic_account>=2.8.0:${PORTSDIR}/finance/trytond28_analytic_account \
		trytond28_analytic_invoice>=2.8.0:${PORTSDIR}/finance/trytond28_analytic_invoice \
		trytond28_sale>=2.8.1:${PORTSDIR}/finance/trytond28_sale

CONFLICTS=	trytond_analytic_sale-2.[46].*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYEASYINSTALL_EGG=${DISTNAME}-py${PYTHON_VER}${PYEASYINSTALL_OSARCH}.egg

.include <bsd.port.mk>
