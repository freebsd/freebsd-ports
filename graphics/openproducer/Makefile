# New ports collection makefile for:	openproducer
# Date created:		22 July 2003
# Whom:			Ying-Chieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	openproducer
PORTVERSION=	1.0.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.openscenegraph.org/downloads/snapshots/
#
# the following master distribution contains the version of OpenProducer
# as described above by PORTVERSION and PORTREVISION.
DISTNAME=	OSG_OP_OT-1.0

MAINTAINER=	lawrance@FreeBSD.org
COMMENT=	A cross-platform C++/OpenGL library focused on camera control

BUILD_DEPENDS=	${LOCALBASE}/lib/libOpenThreads.so:${PORTSDIR}/devel/openthreads

USE_ZIP=	yes
USE_X_PREFIX=	yes
USE_GL=		yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/Producer
MAKEFILE=	GNUmakefile
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}

# Optimisation/Debug flags:
#   opt = optimized ($OPTF added)
#   debug = debug ($DBGF added)
# opt is default
#
ALL_TARGET=	opt

.include <bsd.port.mk>
