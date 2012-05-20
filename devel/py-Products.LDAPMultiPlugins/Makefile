# New ports collection makefile for:	py-Products.LDAPMultiPlugins
# Date created:				20 May 2012
# Whom:					Lawrence Stewart <lstewart@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	Products.LDAPMultiPlugins
PORTVERSION=	1.14
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	LDAP-backed plugins for the Zope2 PluggableAuthService

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap2>=2.0.6:${PORTSDIR}/net/py-ldap2 \
		${PYTHON_PKGNAMEPREFIX}Products.LDAPUserFolder>=2.9:${PORTSDIR}/devel/py-Products.LDAPUserFolder \
		${PYTHON_PKGNAMEPREFIX}Products.PluggableAuthService>=1.4.0:${PORTSDIR}/security/py-Products.PluggableAuthService

DIST_SUBDIR=	zope
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
