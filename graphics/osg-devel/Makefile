# New ports collection makefile for:	Open Scene Graph
# Date created:				26 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	osg
PORTVERSION=	0.9.8
CATEGORIES=	graphics
MASTER_SITES=	http://www.openscenegraph.org/downloads/snapshots/
DISTNAME=	OSG_OP_OT-${PORTVERSION}-2

MAINTAINER=	rrghphar@bigpond.net.au
COMMENT=	C++ OpenGL scene graph library for real-time rendering

BUILD_DEPENDS=	${LOCALBASE}/lib/libOpenThreads.so:${PORTSDIR}/devel/openthreads \
		${X11BASE}/lib/libProducer.so:${PORTSDIR}/graphics/openproducer
RUN_DEPENDS=	${LOCALBASE}/lib/libOpenThreads.so:${PORTSDIR}/devel/openthreads \
		${X11BASE}/lib/libProducer.so:${PORTSDIR}/graphics/openproducer
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2 \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_ZIP=	yes
USE_X_PREFIX=	yes
USE_GL=		yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
MAKE_ENV=	OSGHOME="${WRKSRC}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		EXAMPLESDIR="${EXAMPLESDIR}" \
		DOCSDIR="${DOCSDIR}" \
		DATADIR="${DATADIR}" \
		OPTF="${CXXFLAGS}"
MAKEFILE=	GNUmakefile
WRKSRC=		${WRKDIR}/${DISTNAME}/OpenSceneGraph

# opt = optimized ($OPTF added); debug = debug ($DBGF added); opt is default
ALL_TARGET=	opt

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
EXTRA_PATCHES=	${FILESDIR}/freebsd4-osg-patches
.endif

.if !defined(NOPORTDOCS)

BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen	\
		dot:${PORTSDIR}/graphics/graphviz
PORTDOCS=	html

pre-patch:
	${REINPLACE_CMD} -e 's,[[:cntrl:]]*$$,,' \
		${WRKSRC}/examples/osgtesselate/osgtesselate.cpp

post-build:
	cd ${WRKSRC}/doc/Doxyfiles && OSGHOME=${WRKSRC} doxygen all_Doxyfile

pre-install:
	${FIND} ${WRKSRC} -name '*.orig' -delete

post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -r ${WRKSRC}/doc/doxygen/ ${DOCSDIR}

.endif

.include <bsd.port.post.mk>
