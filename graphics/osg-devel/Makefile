# New ports collection makefile for:	Open Scene Graph
# Date created:				26 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	osg
PORTVERSION=	0.9.6.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openscenegraph
DISTNAME=	OpenSceneGraph-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	C++ OpenGL scene graph library for real-time rendering

BUILD_DEPENDS=	${LOCALBASE}/lib/libOpenThreads.so:${PORTSDIR}/devel/openthreads \
		${X11BASE}/lib/libProducer.so:${PORTSDIR}/graphics/openproducer
RUN_DEPENDS=	${BUILD_DEPENDS}

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2 \
		xml2.5:${PORTSDIR}/textproc/libxml2

BROKEN=		"Does not compile"

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_MESA=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
MAKE_ENV=	OSGHOME=${WRKSRC} \
		PTHREAD_LIBS=${PTHREAD_LIBS}
MAKEFILE=	GNUmakefile
WRKSRC=		${WRKDIR}/OpenSceneGraph-${PORTVERSION:R}-${PORTVERSION:E}

# opt = optimized ($OPTF added); debug = debug ($DBGF added); opt is default
ALL_TARGET=	opt

.include <bsd.port.pre.mk>

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s|malloc\.h|stdlib.h|"
	 @${REINPLACE_CMD} -e 's,%%CXXFLAGS%%,${CXXFLAGS},g' \
		${WRKSRC}/Make/makedefs

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -r ${WRKSRC}/doc/ ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
