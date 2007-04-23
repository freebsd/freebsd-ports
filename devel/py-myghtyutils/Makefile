# New ports collection makefile for:	py-myghtyutils
# Date created:		April 23 2007
# Whom:			Dryice Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	myghtyutils
PORTVERSION=	0.52
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	source/M/MyghtyUtils
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	MyghtyUtils-${PORTVERSION}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	Container and Utility Functions from the Myghty Template Framework

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_ZIP=	yes
USE_PYDISTUTILS=	yes

PYMYGHTYUTILS_EGG=	MyghtyUtils-${PORTVERSION}-py${PYTHON_VER}.egg

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYMYGHTYUTILS_EGG=${PYMYGHTYUTILS_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

.include <bsd.port.mk>
