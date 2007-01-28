# New ports collection makefile for:	py-turbojson
# Date created:		2006-12-02
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	TurboJson
PORTVERSION=	1.0
CATEGORIES=	devel python
MASTER_SITES=	http://files.turbogears.org/eggs/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYTURBOJSON_EGG}
EXTRACT_SUFX=

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python template plugin for TurboGears that supports json

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/${PYRULEDISPATCH_EGG}:${PORTSDIR}/devel/py-ruledispatch \
		${PYTHON_SITELIBDIR}/${PYSIMPLEJSON_EGG}:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_SITELIBDIR}/${PYSQLOBJECT_EGG}/sqlobject/__init__.py:${PORTSDIR}/databases/py-sqlobject

NO_BUILD=	yes

USE_PYTHON=	2.4

PLIST_SUB+=	PYTURBOJSON_EGG=${PYTURBOJSON_EGG}

SUB_FILES+=	pkg-deinstall pkg-install
SUB_LIST+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		EGG="${PORTNAME}==${PORTVERSION}"

EASY_INSTALL=	${LOCALBASE}/bin/easy_install
EASY_INSTALL_ARGS=	-N -b ${WRKSRC} -d ${PYTHON_SITELIBDIR} -s ${PREFIX}/bin

PYTURBOJSON_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

do-extract:
	${MKDIR} ${WRKSRC}

do-install:
	${EASY_INSTALL} ${EASY_INSTALL_ARGS} ${DISTDIR}/${DISTFILES}

.include <bsd.port.pre.mk>

PYRULEDISPATCH_EGG!=	${MAKE} -f ${PORTSDIR}/devel/py-ruledispatch/Makefile -V PYRULEDISPATCH_EGG
PYSIMPLEJSON_EGG!=	${MAKE} -f ${PORTSDIR}/devel/py-simplejson/Makefile -V PYSIMPLEJSON_EGG
PYSQLOBJECT_EGG!=	${MAKE} -f ${PORTSDIR}/databases/py-sqlobject/Makefile -V PYSQLOBJECT_EGG

.include <bsd.port.post.mk>
