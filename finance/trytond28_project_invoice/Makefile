# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_project_invoice
PORTVERSION=	2.8.2
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_project_invoice/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_project_invoice-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Project Invoice Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_timesheet>=2.8.0:${PORTSDIR}/finance/trytond28_timesheet \
		trytond28_project_revenue>=2.8.0:${PORTSDIR}/finance/trytond28_project_revenue \
		trytond28_account_invoice>=2.8.2:${PORTSDIR}/finance/trytond28_account_invoice \
		trytond28_product>=2.8.0:${PORTSDIR}/finance/trytond28_product

CONFLICTS=	trytond_project_invoice-2.[46].*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYEASYINSTALL_EGG=${DISTNAME}-py${PYTHON_VER}${PYEASYINSTALL_OSARCH}.egg

.include <bsd.port.mk>
