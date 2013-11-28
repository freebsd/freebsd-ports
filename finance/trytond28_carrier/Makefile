# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_carrier
PORTVERSION=	2.8.0
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_carrier/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_carrier-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Carrier Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_party>=2.8.0:${PORTSDIR}/finance/trytond28_party \
		trytond28_product>=2.8.0:${PORTSDIR}/finance/trytond28_product

CONFLICTS=	trytond_carrier-2.[46].*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYEASYINSTALL_EGG=${DISTNAME}-py${PYTHON_VER}${PYEASYINSTALL_OSARCH}.egg

.include <bsd.port.mk>
