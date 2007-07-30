# New ports collection makefile for:	py-protocols-devel
# Date created:		15 December 2006
# Whom:			Dryice Liu	<dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	PyProtocols
PORTVERSION=	1.0.a0.r2082
CATEGORIES=	devel python
MASTER_SITES=	http://peak.telecommunity.com/snapshots/ \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-1.0a0dev_r2082

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	Protocol Definition, Declaration, and Adaptation for Python

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_PACKAGE=	not yet

PLIST_FILES=	${PYTHON_SITELIBDIR:S,${PREFIX}/,,}/${PYPROTOCOLS_EGG}
PLIST_SUB=	PYPROTOCOLS_EGG="${PYPROTOCOLS_EGG}"

SUB_FILES+=	pkg-deinstall pkg-install
SUB_LIST+=	EGG="PyProtocols==${PYPROTOCOLS_VER}" \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	1.0a0
USE_ZIP=	yes

PYDISTUTILS_NOEGGINFO=	yes # XXX convert easy_install support to bsd.python.mk's
PYPROTOCOLS_EGG=	PyProtocols-${PYPROTOCOLS_VER}-py${PYTHON_VERSION:S/^python//}-${OPSYS:L}-${OSRELEASE}-${ARCH}.egg
PYPROTOCOLS_VER?=	1.0a0

.include <bsd.port.pre.mk>

OSRELEASE!=	${DESTDIR}/usr/bin/uname -r

.include <bsd.port.post.mk>
