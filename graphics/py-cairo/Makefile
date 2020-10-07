# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cairo
PORTVERSION=	1.18.2
CATEGORIES=	graphics python
MASTER_SITES=	https://github.com/pygobject/pycairo/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Python bindings for Cairo

LICENSE=	LGPL21 MPL11
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING-LGPL-2.1
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING-MPL-1.1

USES=		compiler:c11 gnome meson pkgconfig python:3.6+,build
USE_PYTHON=	flavors py3kplist
USE_GNOME=	cairo

MESON_ARGS=	-Dpython=${PYTHON_CMD}

PLIST_SUB=	PORTVER=${PORTVERSION}

PORTSCOUT=	limitw:1,even

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cairo/_cairo.so
	@${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR}/${PORTNAME} \
		"${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}"
	@${PYTHON_CMD} -O -m compileall -d ${PYTHON_SITELIBDIR}/${PORTNAME} \
		"${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}"

.include <bsd.port.mk>
