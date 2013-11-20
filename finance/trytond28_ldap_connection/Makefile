# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_ldap_connection
PORTVERSION=	2.8.0
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_ldap_connection/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_ldap_connection-${PORTVERSION}

MAINTAINER=	matthias@petermann.it
COMMENT=	Tryton Application Platform (LDAP Connection Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28>=2.8.2:${PORTSDIR}/finance/trytond28 \
		${PYTHON_PKGNAMEPREFIX}ldap2>=2.4.10:${PORTSDIR}/net/py-ldap2

CONFLICTS=	trytond_ldap_connection-2.[46].*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYEASYINSTALL_EGG=${DISTNAME}-py${PYTHON_VER}${PYEASYINSTALL_OSARCH}.egg

.include <bsd.port.mk>
