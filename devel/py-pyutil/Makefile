# New ports collection makefile for:	py-pyutil
# Date created:		2007-5-31
# Whom:			Chao Shin <quakelee@cn.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyutil
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=	source/p/pyutil
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	quakelee@cn.FreeBSD.org
COMMENT=	A collection of mature utilities for Python programmers

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

USE_PYTHON=	2.4
USE_PYDISTUTILS=	yes
PYTHONVER?=	${_PYTHON_VERSION}

PLIST_SUB+=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYTHONVER=${PYTHONVER} \
		PYUTIL_EGG=${PYUTIL_EGG} \
		PYUTIL_EGG_VER="${PORTNAME}==${PORTVERSION}"
OSINFOS=	${OPSYS:L}-${OSRELEASE}-${ARCH}
PYUTIL_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}-${OSINFOS}.egg

post-patch:
	@${REINPLACE_CMD} -e 's|^from\ ez\_setup|#from\ ez\_setup|' \
	-e 's|^use_setuptools|#use_setuptools|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.pre.mk>

OSRELEASE!=	${DESTDIR}/usr/bin/uname -r

.include <bsd.port.post.mk>
