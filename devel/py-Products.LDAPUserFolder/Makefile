# New ports collection makefile for:	py-Products.LDAPUserFolder
# Date created:				20 May 2012
# Whom:					Lawrence Stewart <lstewart@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	Products.LDAPUserFolder
PORTVERSION=	2.23
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	A LDAP-enabled Zope 2 user folder

LICENSE=	ZPL21

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-git>=0.4.2:${PORTSDIR}/devel/py-setuptools-git
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap2>=2.0.6:${PORTSDIR}/net/py-ldap2

OPTIONS=	POSIXGROUP_PATCH "Use posixGroup for group membership" On

DIST_SUBDIR=	zope
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
#USE_ZOPE=	yes

.include <bsd.port.options.mk>

.if defined(WITH_POSIXGROUP_PATCH)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-posixgroup
.endif

.include <bsd.port.mk>
