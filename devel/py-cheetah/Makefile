# New ports collection makefile for:	py-cheetah
# Date created:		26 November 2003
# Whom:	      		Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	cheetah
DISTVERSION=	2.0.r7
CATEGORIES=	devel textproc www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cheetahtemplate
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Cheetah-2.0rc7

MAINTAINER=	perky@FreeBSD.org
COMMENT=	HTML template engine for Python

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_PACKAGE=	not yet
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	Cheetah
PYDISTUTILS_PKGVERSION=	2.0rc7
MAKE_ENV=	CHEETAH_USE_SETUPTOOLS=yes
PYDISTUTILS_CONFIGUREARGS=	bdist_egg --plat-name=""
PYDISTUTILS_NOEGGINFO=	yes # XXX convert easy_install support to bsd.python.mk's
CHEETAHVER=	2.0rc7
PYTHONVER?=	${_PYTHON_VERSION}
PLIST_SUB=	CHEETAHVER=${CHEETAHVER} \
		PYTHONVER=${PYTHONVER} \
		OSINFOS=${OSINFOS} \
		EGG="Cheetah==${CHEETAHVER}"
OSINFOS=	${OPSYS:L}-${OSRELEASE}-${ARCH}
PYCHEETAH_EGG=	Cheetah-${CHEETAHVER}-py${PYTHON_VERSION:S/^python//}-${OSINFOS}.egg

.include <bsd.port.pre.mk>

OSRELEASE!=	${DESTDIR}/usr/bin/uname -r

.include <bsd.port.post.mk>
