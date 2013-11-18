# $FreeBSD$

PORTNAME=	trytond_party
PORTVERSION=	2.4.1
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann.it
COMMENT=	Tryton Application Platform (Party Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_country>=2.4.0:${PORTSDIR}/finance/trytond_country \
		${PYTHON_PKGNAMEPREFIX}vatnumber>=1.0.0:${PORTSDIR}/finance/py-vatnumber

CONFLICTS=	trytond_party-2.[68].*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
