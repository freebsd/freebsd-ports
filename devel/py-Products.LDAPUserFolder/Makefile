# Created by: Lawrence Stewart <lstewart@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Products.LDAPUserFolder
PORTVERSION=	2.27
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	LDAP-enabled Zope 2 user folder

LICENSE=	ZPL21

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-git>=0.4.2:devel/py-setuptools-git
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap>=2.0.6:net/py-ldap

OPTIONS_DEFINE=		POSIXGROUP_PATCH
POSIXGROUP_PATCH_DESC=	Use posixGroup for group membership
OPTIONS_DEFAULT=	POSIXGROUP_PATCH

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPOSIXGROUP_PATCH}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-posixgroup
.endif

.include <bsd.port.mk>
