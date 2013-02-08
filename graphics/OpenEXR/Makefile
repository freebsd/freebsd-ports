# New ports collection makefile for:	OpenEXR
# Date created:				2003/01/26
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	OpenEXR
PORTVERSION=	1.7.1
CATEGORIES=	graphics devel
MASTER_SITES=	http://cloud.github.com/downloads/openexr/openexr/
DISTNAME=	${PORTNAME:L}-${DISTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	High dynamic-range (HDR) image file format

LICENSE=	BSD

LIB_DEPENDS=	Imath:${PORTSDIR}/graphics/ilmbase

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_GMAKE=	yes
USE_PKGCONFIG=	build
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--enable-imfexamples

# must be explicitely linked with -l{thr|pthread}
LDFLAGS+=	${PTHREAD_LIBS}

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog NEWS README

DOCSRCDIR2=	${WRKSRC}/doc
DOC_FILES2=	MultiViewOpenEXR.pdf OpenEXRFileLayout.pdf \
		ReadingAndWritingImageFiles.pdf TechnicalIntroduction.pdf

OPTIONS_DEFINE=		LARGE_STACK
LARGE_STACK_DESC=	Enable sys-dependant large stack optimizations

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLARGE_STACK}
CONFIGURE_ARGS+=--enable-large-stack
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|examplesdir = $$(datadir)/doc/OpenEXR-@OPENEXR_VERSION@/examples|examplesdir = $$(prefix)/share/examples/OpenEXR|' \
		${WRKSRC}/IlmImfExamples/Makefile.in
	@${REINPLACE_CMD} -e 's|pkgconfigdir = $$(libdir)/pkgconfig|pkgconfigdir = $$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|docdir=$$(datadir)/doc/OpenEXR-@OPENEXR_VERSION@|docdir = $$(datadir)/doc/OpenEXR|' \
	-e 's|doc_DATA = $$(EXTRA_DIST)|doc_DATA =|' ${WRKSRC}/doc/Makefile.am ${WRKSRC}/doc/Makefile.in

regression-test regression test check:	build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR}
.endif

# IlmImfTest hangs indefinitely
#
#.if defined(PACKAGE_BUILDING)
#.if ${ARCH} != sparc64 || ${OSVERSION} >= 700055
#.if ${ARCH} != amd64 || ${OSVERSION} < 800000
#pre-install:	test
#.endif
#.endif
#.endif

.include <bsd.port.mk>
