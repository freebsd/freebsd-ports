# New ports collection makefile for:	py-zopeInterface
# Date created:		13 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	zopeInterface
PORTVERSION=	3.3.0.1
CATEGORIES=	devel zope python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/z/zope.interface/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	zope.interface-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	Zope.interface package from Zope 3

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

MANUAL_PACKAGE_BUILD=Doesn't build in tinderbox environment

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-O 1 -N -S ${PYTHON_SITELIBDIR} ${WRKSRC}/dist/${PYZOPEINTERFACE_EGG}

PYZOPEINTERFACE_EGG=	zope.interface-${PORTVERSION}-py${PYTHON_VER}-${OPSYS:L}-${OSRELEASE}-${ARCH}.egg

PLIST_SUB+=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYZOPEINTERFACE_EGG=${PYZOPEINTERFACE_EGG} \
		PYZOPEINTERFACE_EGG_VER="zope.interface==${PORTVERSION}"

.include <bsd.port.pre.mk>

OSRELEASE!=	${DESTDIR}/usr/bin/uname -r

.include <bsd.port.post.mk>
