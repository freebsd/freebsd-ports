# Created by: Lawrence Stewart <lstewart@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Products.LDAPMultiPlugins
PORTVERSION=	1.14
PORTREVISION=	2
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	LDAP-backed plugins for the Zope2 PluggableAuthService

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap>=2.0.6:${PORTSDIR}/net/py-ldap \
		${PYTHON_PKGNAMEPREFIX}Products.LDAPUserFolder>=2.9:${PORTSDIR}/devel/py-Products.LDAPUserFolder \
		${PYTHON_PKGNAMEPREFIX}Products.PluggableAuthService>=1.4.0:${PORTSDIR}/security/py-Products.PluggableAuthService

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
