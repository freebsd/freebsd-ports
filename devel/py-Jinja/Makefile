# New ports collection makefile for:	jinja
# Date created:		2007-02-14
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Jinja
PORTVERSION=	0.9
CATEGORIES=	devel python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/J/${PORTNAME}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A fast, and easy to use stand-alone template engine

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION} \
		PYJINJA_EGG=${PYJINJA_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}
PYJINJA_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

.include <bsd.port.mk>
