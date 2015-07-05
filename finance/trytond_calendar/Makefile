# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond_calendar
PORTVERSION=	2.4.4
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann.it
COMMENT=	Tryton Application Platform (Calendar Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		${PYTHON_PKGNAMEPREFIX}vobject>=0.8.1:${PORTSDIR}/deskutils/py-vobject \
		${PYTHON_PKGNAMEPREFIX}PyWebDAV>=0:${PORTSDIR}/www/py-pywebdav \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:${PORTSDIR}/devel/py-dateutil

DEPRECATED=	Upstream project no longer supports the Tryton 2.4 series
EXPIRATION_DATE=	2015-08-05

CONFLICTS=	trytond28_calendar-2.8.*

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
