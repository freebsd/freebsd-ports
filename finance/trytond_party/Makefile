# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond_party
PORTVERSION=	2.4.2
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann.it
COMMENT=	Tryton Application Platform (Party Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_country>=2.4.0:${PORTSDIR}/finance/trytond_country \
		${PYTHON_PKGNAMEPREFIX}vatnumber>=1.0.0:${PORTSDIR}/finance/py-vatnumber

DEPRECATED=	Upstream project no longer supports the Tryton 2.4 series
EXPIRATION_DATE=	2015-08-05

CONFLICTS=	trytond28_party-2.8.*

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
