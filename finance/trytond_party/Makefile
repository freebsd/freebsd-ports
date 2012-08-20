# New ports collection makefile for:	trytond_party
# Date created:		12 August, 2012
# Whom:			Matthias Petermann<matthias@petermann.it>
#
# $FreeBSD$
#

PORTNAME=	trytond_party
PORTVERSION=	2.4.0
CATEGORIES=	finance python
MASTER_SITES=	http://downloads2.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann.it
COMMENT=	The Party Module for Tryton

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_country>=2.4.0:${PORTSDIR}/finance/trytond_country \
		${PYTHON_PKGNAMEPREFIX}vatnumber>=1.0.0:${PORTSDIR}/finance/py-vatnumber

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
