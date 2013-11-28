# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_project
PORTVERSION=	2.8.0
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_project/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_project-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Project Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28>=2.8.2:${PORTSDIR}/finance/trytond28 \
		trytond28_timesheet>=2.8.0:${PORTSDIR}/finance/trytond28_timesheet \
		trytond28_party>=2.8.0:${PORTSDIR}/finance/trytond28_party

CONFLICTS=	trytond_project-2.[46].*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYEASYINSTALL_EGG=${DISTNAME}-py${PYTHON_VER}${PYEASYINSTALL_OSARCH}.egg

.include <bsd.port.mk>
