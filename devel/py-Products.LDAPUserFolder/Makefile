# Created by: Lawrence Stewart <lstewart@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Products.LDAPUserFolder
PORTVERSION=	2.23
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	LDAP-enabled Zope 2 user folder

LICENSE=	ZPL21

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-git>=0.4.2:${PORTSDIR}/devel/py-setuptools-git
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap2>=2.0.6:${PORTSDIR}/net/py-ldap2

OPTIONS_DEFINE=	POSIXGROUP_PATCH
POSIXGROUP_PATCH_DESC=	Use posixGroup for group membership

OPTIONS_DEFAULT=	POSIXGROUP_PATCH

DIST_SUBDIR=	zope
USE_PYTHON=	2
USE_PYDISTUTILS=easy_install
#USES=		zope

NO_STAGE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPOSIXGROUP_PATCH}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-posixgroup
.endif

.include <bsd.port.mk>
