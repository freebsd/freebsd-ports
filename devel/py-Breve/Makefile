# New ports collection makefile for:	py-breve
# Date created:		2007-02-14
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Breve
PORTVERSION=	1.0.35
CATEGORIES=	devel python
MASTER_SITES=	http://breve.twisty-industries.com/downloads/ \
		LOCAL/nivit
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A Python s-expression style template engine

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-N -s ${PREFIX}/bin -S ${PYTHON_SITELIBDIR} dist/${PYBREVE_EGG}

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION} \
		PYBREVE_EGG=${PYBREVE_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

PYBREVE_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

.include <bsd.port.mk>
