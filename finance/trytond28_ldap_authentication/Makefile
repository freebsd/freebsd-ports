# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_ldap_authentication
PORTVERSION=	2.8.1
CATEGORIES=	finance python
MASTER_SITES=	CHEESESHOP \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_ldap_authentication-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (LDAP Authentication Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_ldap_connection>=2.8.0:finance/trytond28_ldap_connection

CONFLICTS=	trytond_ldap_authentication-2.[46].*

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
