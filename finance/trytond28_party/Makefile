# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_party
PORTVERSION=	2.8.0
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_party/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_party-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Party Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28>=2.8.2:${PORTSDIR}/finance/trytond28 \
		trytond28_country>=2.8.0:${PORTSDIR}/finance/trytond28_country \
		${PYTHON_PKGNAMEPREFIX}vatnumber>=1.0.0:${PORTSDIR}/finance/py-vatnumber

CONFLICTS=	trytond_party-2.[46].*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYEASYINSTALL_EGG=${DISTNAME}-py${PYTHON_VER}${PYEASYINSTALL_OSARCH}.egg

.include <bsd.port.mk>
