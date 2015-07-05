# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond_ldap_authentication
PORTVERSION=	2.4.1
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann.it
COMMENT=	Tryton Application Platform (LDAP Authentication Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_ldap_connection>=2.4.0:${PORTSDIR}/finance/trytond_ldap_connection

DEPRECATED=	Upstream project no longer supports the Tryton 2.4 series
EXPIRATION_DATE=	2015-08-05

CONFLICTS=	trytond28_ldap_authentication-2.8.*

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
