# Created by: Lawrence Stewart <lstewart@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Products.LDAPMultiPlugins
PORTVERSION=	1.14
PORTREVISION=	3
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	LDAP-backed plugins for the Zope2 PluggableAuthService

DEPRECATED=	Outdated, uses EOLed python27
EXPIRATION_DATE=	2020-02-05

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap>=2.0.6:net/py-ldap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.LDAPUserFolder>=2.9:devel/py-Products.LDAPUserFolder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.PluggableAuthService>=1.4.0:security/py-Products.PluggableAuthService@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
