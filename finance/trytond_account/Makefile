# New ports collection makefile for:	trytond_account
# Date created:		12 August, 2012
# Whom:			Matthias Petermann<matthias@petermann.it>
#
# $FreeBSD$
#

PORTNAME=	trytond_account
PORTVERSION=	2.4.1
CATEGORIES=	finance python
MASTER_SITES=	http://downloads2.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann.it
COMMENT=	The Account Module for Tryton

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_company>=2.4.0:${PORTSDIR}/finance/trytond_company \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:${PORTSDIR}/devel/py-dateutil

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
