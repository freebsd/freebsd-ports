# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	openexr
PORTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	LOCAL/mandree/:test
DISTFILES=	${PORTNAME}-2.2.0-comp_dwa-test-images.tar.xz:test

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	High dynamic-range (HDR) image file format

LICENSE=	BSD3CLAUSE

# exact version required to avoid hard-to-debug issues
LIB_DEPENDS=	libImath-2_4.so.24:graphics/ilmbase

USES=		cmake compiler:c++14-lang libtool pathfix pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TUPLE=	AcademySoftwareFoundation:openexr:v${PORTVERSION}

CPPFLAGS+=	-I. -I../IlmImf
# must be linked with -l{thr|pthread} explicitly
LDFLAGS+=	-lpthread

PORTDOCS=	*
PORTEXAMPLES=	*

DOCSRCDIR1=	${WRKSRC:H}/
DOC_FILES1=	CHANGES.md CONTRIBUTING.md GOVERNANCE.md LICENSE.md SECURITY.md \
		CODE_OF_CONDUCT.md CONTRIBUTORS.md README.md

DOCSRCDIR2=	${WRKSRC}/doc
DOC_FILES2=	*.odt *.pdf

OPTIONS_DEFINE=		DOCS EXAMPLES

WRKSRC_SUBDIR=	OpenEXR

OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == powerpc
USE_GCC=	yes
.endif

MAJORVER=	2_4
VER=		24

PLIST_SUB+=	MAJORVER=${MAJORVER}
PLIST_SUB+=	VER=${VER}

# too many reports about compilation failures, so
# sanity check we are using the same C++ standard library
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
		${STAGEDIR}${PREFIX}/share/doc/OpenEXR/examples/ ${STAGEDIR}${EXAMPLESDIR}
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/doc/OpenEXR 2>/dev/null || :

post-install-EXAMPLES-off:
	${RM} -R ${STAGEDIR}${PREFIX}/share/doc/OpenEXR/examples/
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/doc/OpenEXR 2>/dev/null || :

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${DOCSDIR:H}/OpenEXR/[a-df-zA-Z]* ${STAGEDIR}${DOCSDIR}

post-install-DOCS-off:
	${RM} ${STAGEDIR}${DOCSDIR:H}/OpenEXR/*.pdf
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME} 2>/dev/null || :

regression-test check test:
	cd ${BUILD_WRKSRC} && ctest -j ${MAKE_JOBS_NUMBER}

.include <bsd.port.post.mk>
