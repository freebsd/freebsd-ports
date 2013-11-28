# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_calendar_todo
PORTVERSION=	2.8.0
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_calendar_todo/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_calendar_todo-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Calendar Todo Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_calendar>=2.8.0:${PORTSDIR}/finance/trytond28_calendar

CONFLICTS=	trytond_calendar_todo-2.[46].*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYEASYINSTALL_EGG=${DISTNAME}-py${PYTHON_VER}${PYEASYINSTALL_OSARCH}.egg

.include <bsd.port.mk>
