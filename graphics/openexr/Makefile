# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	openexr
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${PORTVERSION}/:dist \
		LOCAL/mandree/:test
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:dist \
		${PORTNAME}-2.2.0-comp_dwa-test-images.tar.xz:test

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	High dynamic-range (HDR) image file format

LICENSE=	BSD3CLAUSE

# exact version required to avoid hard-to-debug issues
LIB_DEPENDS=	libImath-2_3.so.24:graphics/ilmbase

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		compiler:c++14-lang gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-ilmbasetest --enable-imfexamples
USE_LDCONFIG=	yes
TEST_TARGET=	check

CPPFLAGS+=	-I. -I../IlmImf
# must be linked with -l{thr|pthread} explicitly
LDFLAGS+=	-lpthread

PORTDOCS=	*
PORTEXAMPLES=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog NEWS README.md

DOCSRCDIR2=	${WRKSRC}/doc
DOC_FILES2=	*.pdf

OPTIONS_DEFINE=		DOCS EXAMPLES LARGE_STACK
LARGE_STACK_DESC=	Enable sys-dependent large stack optimizations

OPTIONS_SUB=	yes

LARGE_STACK_CONFIGURE_ENABLE=	large-stack

.include <bsd.port.pre.mk>

.if ${ARCH} == powerpc
USE_GCC=	yes
.endif

MAJORVER=	2_3
VER=		24

PLIST_SUB+=	MAJORVER=${MAJORVER}
PLIST_SUB+=	VER=${VER}

post-patch:
	@${REINPLACE_CMD} -e 's|== x|= x|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e 's|$$(datadir)/doc/OpenEXR-@OPENEXR_VERSION@/examples|$$(prefix)/share/examples/${PORTNAME}|' \
		${WRKSRC}/IlmImfExamples/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(datadir)/doc/OpenEXR-@OPENEXR_VERSION@||' \
		-e 's|$$(EXTRA_DIST)||' \
		${WRKSRC}/doc/Makefile.am ${WRKSRC}/doc/Makefile.in

# too many reports about compilation failures, so sanity check C++
# library
_ilm_libcxx=${COMPILER_FEATURES:Mlib*c++}
pre-configure:
	@${READELF} -d ${LOCALBASE}/lib/libImath.so \
	| ${EGREP} -q '\<NEEDED\>.*\[${_ilm_libcxx:C/\+/\\+/g}\.' \
	|| {	${ECHO_CMD} "*** Your ilmbase package uses a different C++ standard library than ***" ; \
		${ECHO_CMD} "*** OpenEXR would. Please recompile and reinstall ilmbase with the  ***" ; \
		${ECHO_CMD} "*** same C++ std. library before trying to build OpenEXR.  Abort.   ***" ; \
		exit 1; }

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/lib/libIlmImf-${MAJORVER}.so.${VER} \
		${STAGEDIR}${PREFIX}/lib/libIlmImfUtil-${MAJORVER}.so.${VER}

post-install-EXAMPLES-on:
	${MV} \
		${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}/examples/ ${STAGEDIR}${EXAMPLESDIR}
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME} 2>/dev/null || :

post-install-EXAMPLES-off:
	${RM} -R ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}/examples/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR}

post-install-DOCS-off:
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME} 2>/dev/null || :
.include <bsd.port.post.mk>
