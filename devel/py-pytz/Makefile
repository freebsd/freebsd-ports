# New ports collection makefile for:	py-tz
# Date created:			Mar 22, 2006
# Whom:				Khairil Yusof <kaeru@inigo-tech.com>
#
# $FreeBSD$
#

PORTNAME=	pytz
PORTVERSION=	2007d
CATEGORIES=	devel python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/p/pytz/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pytz
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	World Timezone Definitions for Python

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-O 1 -N -S ${PYTHON_SITELIBDIR} ${WRKSRC}/dist/${PYPYTZ_EGG}

PYPYTZ_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

PLIST_SUB+=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYPYTZ_EGG=${PYPYTZ_EGG} \
		PYPYTZ_EGG_VER="${PORTNAME}==${PORTVERSION}"

.include <bsd.port.mk>
