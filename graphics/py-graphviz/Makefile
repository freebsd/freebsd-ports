# New ports collection makefile for:	py-graphviz
# Date created:		25 December 2001
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$

PORTNAME=	graphviz
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://www.cs.brown.edu/~er/software/Agraph.py/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	gv.i __init__.py
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to GraphViz agraph

BUILD_DEPENDS=	${SWIG_CMD}:${PORTSDIR}/devel/swig13 \
		${LOCALBASE}/lib/graphviz/libagraph.so:${PORTSDIR}/graphics/graphviz

NO_CDROM=	"Can't be included in a commercial product"

USE_PYTHON=	yes
SWIG_CMD=	${LOCALBASE}/bin/swig1.3
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,^${LOCALBASE}/,,g}
GV_PORT=	${PORTSDIR}/graphics/graphviz
MAKE_ENV=	PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR} \
		GRAPHVIZ_INCLUDEDIR=${LOCALBASE}/include/graphviz \
		SWIG_CMD=${SWIG_CMD}

post-patch:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/graphviz/gv.i ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${MKDIR} ${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/__init__.py \
		${WRKSRC}/_graphviz.so ${WRKSRC}/graphviz.py \
		${PYTHON_SITELIBDIR}/${PORTNAME}

post-install:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/py_compile.py \
		${PYTHON_SITELIBDIR}/${PORTNAME}/__init__.py
	${PYTHON_CMD} ${PYTHON_LIBDIR}/py_compile.py \
		${PYTHON_SITELIBDIR}/${PORTNAME}/graphviz.py

.include <bsd.port.mk>
