# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	OpenEXR
PORTVERSION=	2.1.0
PORTREVISION=	3
CATEGORIES=	graphics devel
MASTER_SITES=	SAVANNAH/openexr/
DISTNAME=	openexr-${DISTVERSION}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	High dynamic-range (HDR) image file format

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libImath.so:${PORTSDIR}/graphics/ilmbase

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		compiler:features gmake libtool:keepla pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-ilmbasetest --enable-imfexamples
USE_LDCONFIG=	yes

# must be linked with -l{thr|pthread} explicitly
LDFLAGS+=	${PTHREAD_LIBS}

PORTDOCS=	*
PORTEXAMPLES=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog NEWS README

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	*.pdf

OPTIONS_DEFINE=		DOCS EXAMPLES LARGE_STACK
LARGE_STACK_DESC=	Enable sys-dependant large stack optimizations

OPTIONS_SUB=	yes

LARGE_STACK_CONFIGURE_ENABLE=	large-stack

.include <bsd.port.options.mk>

MAJORVER=	2_1
VER=	21

PLIST_SUB=	MAJORVER=${MAJORVER}
PLIST_SUB+=	VER=${VER}

post-patch:
	@${REINPLACE_CMD} -e 's|== x|= x|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e 's|$$(datadir)/doc/OpenEXR-@OPENEXR_VERSION@/examples|$$(prefix)/share/examples/${PORTNAME}|' \
		${WRKSRC}/IlmImfExamples/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(datadir)/doc/OpenEXR-@OPENEXR_VERSION@||' \
		-e 's|$$(EXTRA_DIST)||' \
		${WRKSRC}/doc/Makefile.am ${WRKSRC}/doc/Makefile.in

# too many reports about compileration failures, so sanity check C++
# library
_ilm_libcxx=${COMPILER_FEATURES:Mlib*c++}
pre-configure:
	@${OBJDUMP} -p ${LOCALBASE}/lib/libImath.so \
	| ${EGREP} -q '^[[:space:]]*NEEDED[[:space:]]+${_ilm_libcxx:C/\+/\\+/g}\.' \
	|| {	${ECHO_CMD} "*** Your ilmbase package uses a different C++ standard library than ***" ; \
		${ECHO_CMD} "*** OpenEXR would. Please recompile and reinstall ilmbase with the  ***" ; \
		${ECHO_CMD} "*** same C++ std. library before trying to build OpenEXR.  Abort.   ***" ; \
		exit 1; }


.if ! ${PORT_OPTIONS:MEXAMPLES}
EXTRA_PATCHES+=${FILESDIR}/extra-patch-IlmImfExamples__Makefile.in
.endif

regression-test regression test check:	build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libIlmImf-Imf_${MAJORVER}.so.${VER}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
