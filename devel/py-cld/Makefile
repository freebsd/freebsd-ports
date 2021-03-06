# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cld
PORTVERSION=	20150113
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	LOCAL/demon
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	chromium_compact_language_detector-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Python bindings for compact language detector library

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcld2.so:devel/cld2

USES=		python:3.6+
USE_PYTHON=	flavors

PLIST_FILES=	${PYTHON_SITELIBDIR}/chromium_compact_language_detector-2.0-py${PYTHON_VER}.egg-info \
		${PYTHON_SITELIBDIR}/cld2${PYTHON_EXT_SUFFIX}.so \
		${PYTHON_SITELIBDIR}/cld2full${PYTHON_EXT_SUFFIX}.so

post-patch:
	${REINPLACE_CMD} -e "s#\.\./cld2#${LOCALBASE}/include/cld#" ${WRKSRC}/setup.py ${WRKSRC}/setup_full.py

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py build
	cd ${WRKSRC} && ${PYTHON_CMD} setup_full.py build

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py install -c -O1 --prefix=${PREFIX} --root=${STAGEDIR}
	cd ${WRKSRC} && ${PYTHON_CMD} setup_full.py install -c -O1 --prefix=${PREFIX} --root=${STAGEDIR}

.include <bsd.port.mk>
