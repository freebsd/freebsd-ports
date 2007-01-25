# New ports collection makefile for:	py-turbokid
# Date created:		2006-12-02
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	TurboKid
PORTVERSION=	0.9.9
CATEGORIES=	devel python
MASTER_SITES=	http://cheeseshop.python.org/packages/${PYTHON_VER}/T/TurboKid/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYTURBOKID_EGG}
EXTRACT_SUFX=

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python template plugin that supports Kid templates

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}
RUN_DEPENDS+=	kid:${PORTSDIR}/devel/py-kid

USE_PYTHON=	2.4

NO_BUILD=	yes

PLIST_SUB+=	PYTURBOKID_EGG=${PYTURBOKID_EGG}

SUB_FILES+=	pkg-deinstall pkg-install
SUB_LIST+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		EGG="${PORTNAME}==${PORTVERSION}"

EASY_INSTALL=	${LOCALBASE}/bin/easy_install
EASY_INSTALL_ARGS=	-N -b ${WRKSRC} -d ${PYTHON_SITELIBDIR} -s ${PREFIX}/bin

PYTURBOKID_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

do-extract:
	${MKDIR} ${WRKSRC}

do-install:
	${EASY_INSTALL} ${EASY_INSTALL_ARGS} ${DISTDIR}/${DISTFILES}

.include <bsd.port.mk>
