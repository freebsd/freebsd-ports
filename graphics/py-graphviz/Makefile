# New ports collection makefile for:	py-graphviz
# Date created:		25 December 2001
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$

PORTNAME=	graphviz
PORTVERSION=	0.1
CATEGORIES=	graphics python
MASTER_SITES=	http://www.cs.brown.edu/~er/software/Agraph.py/ \
		http://www.research.att.com/sw/tools/graphviz/dist/:gv
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${MODFILES} ${PORTNAME}-${GV_VERSION}.tgz:gv
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${GV_VERSION}.tgz

MAINTAINER=	perky@FreeBSD.org

BUILD_DEPENDS=	${SWIG_CMD}:${PORTSDIR}/devel/swig13

NO_CDROM=	"Can't be included in a commercial product"

MODFILES=	gv.i __init__.py
WRKSRC=		${WRKDIR}/graphviz-${GV_VERSION}/agraph
GV_VERSION?=	1.7.7

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
SWIG_CMD=	${LOCALBASE}/bin/swig1.3
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,^${LOCALBASE}/,,g}

post-patch:
	@${CP} ${DISTDIR}/graphviz/gv.i ${FILESDIR}/setup.py ${WRKSRC}
	@${MKDIR} ${WRKSRC}/graphviz
	@${CP} ${DISTDIR}/graphviz/__init__.py ${WRKSRC}/graphviz

pre-build:
	@cd ${WRKSRC} && ${SWIG_CMD} -python gv.i

.include <bsd.port.mk>
