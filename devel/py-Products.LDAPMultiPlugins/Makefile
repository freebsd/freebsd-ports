# Created by: Lawrence Stewart <lstewart@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Products.LDAPMultiPlugins
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	LDAP-backed plugins for the Zope2 PluggableAuthService

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap2>=2.0.6:${PORTSDIR}/net/py-ldap2 \
		${PYTHON_PKGNAMEPREFIX}Products.LDAPUserFolder>=2.9:${PORTSDIR}/devel/py-Products.LDAPUserFolder \
		${PYTHON_PKGNAMEPREFIX}Products.PluggableAuthService>=1.4.0:${PORTSDIR}/security/py-Products.PluggableAuthService

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
