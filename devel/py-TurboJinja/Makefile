# New ports collection makefile for:	py-TurboJinja
# Date created:		2007-02-14
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	TurboJinja
PORTVERSION=	0.9
CATEGORIES=	devel python
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	tgwidgets
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYTURBOJINJA_EGG}
EXTRACT_SUFX=

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Jinja (Django & Smarty-like) template for TurboGears

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_PKGNAMEPREFIX}TurboGears>=1.0.1:${PORTSDIR}/www/py-turbogears
RUN_DEPENDS=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Jinja>=0.9:${PORTSDIR}/devel/py-Jinja

USE_PYTHON=	2.4

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION} \
		PYTURBOJINJA_EGG=${PYTURBOJINJA_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}
PYTURBOJINJA_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

do-build:
	@${DO_NADA}

do-install:
	@${EASY_INSTALL_CMD} -N ${DISTDIR}/${PYTURBOJINJA_EGG}

.include <bsd.port.mk>
