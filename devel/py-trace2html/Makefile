# New ports collection makefile for:	py-trace2html
# Date created:		Feb. 26, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	trace2html
PORTVERSION=	0.2.1
CATEGORIES=	devel python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/t/trace2html/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	HTML coverage report generator for trace.py

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-O 1 -N -S ${PYTHON_SITELIBDIR} ${WRKSRC}/dist/${PYTRACE2HTML_EGG}

PYTRACE2HTML_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

PLIST_SUB+=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYTRACE2HTML_EGG=${PYTRACE2HTML_EGG} \
		PYTRACE2HTML_EGG_VER="${PORTNAME}==${PORTVERSION}"

.include <bsd.port.mk>
