# New ports collection makefile for:	py-turbocheetah
# Date created:		2006-12-01
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	TurboCheetah
PORTVERSION=	0.9.5
CATEGORIES=	devel python
MASTER_SITES=	http://files.turbogears.org/eggs/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYTURBOCHEETAH_EGG}
EXTRACT_SUFX=

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	TurboGears plugin to support use of Cheetah templates

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}
RUN_DEPENDS+=	cheetah:${PORTSDIR}/devel/py-cheetah

USE_PYTHON=	2.4

BROKEN=		does not install

NO_BUILD=	yes

SUB_FILES+=	pkg-deinstall pkg-install
SUB_LIST+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		EGG="${PORTNAME}==${PORTVERSION}"

EASY_INSTALL=	${LOCALBASE}/bin/easy_install
EASY_INSTALL_ARGS=	-b ${WRKSRC} -N -d ${PYTHON_SITELIBDIR} -s ${PREFIX}/bin

DATADIR=	${PYTHON_SITELIBDIR}/${PYTURBOCHEETAH_EGG}

PYTURBOCHEETAH_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

do-extract:
	@${MKDIR} ${WRKSRC}

do-install:
	${EASY_INSTALL} ${EASY_INSTALL_ARGS} ${DISTDIR}/${DISTFILES}

.include <bsd.port.mk>
