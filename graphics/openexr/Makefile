# Created by: nork@FreeBSD.org

PORTNAME=	openexr
PORTVERSION=	3.0.5
CATEGORIES=	graphics devel

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	High dynamic-range (HDR) image file format

LICENSE=	BSD3CLAUSE

# exact version required to avoid hard-to-debug issues
LIB_DEPENDS=	libImath-3_0.so.28:math/Imath

USES=		cmake compiler:c++14-lang pathfix pkgconfig

USE_GITHUB=	yes
GH_TUPLE=	AcademySoftwareFoundation:openexr:v${PORTVERSION}

USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DCMAKE_DEBUG_POSTFIX=
CPPFLAGS+=	-I.
# must be linked with -l{thr|pthread} explicitly
LDFLAGS+=	-lpthread

PATCH_STRIP=	-p1

_MAJORVER=	3_0
_VER=		29
_MINVER=	0
_PLVER=		0

PLIST_SUB+=	MAJORVER=${_MAJORVER} \
		VER=${_VER} \
		MINVER=${_MINVER} \
		PLVER=${_PLVER}

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

_DOCSRCDIR1=	${WRKSRC}
_DOCSRCDIR2=	${WRKSRC}/docs
_DOC_FILES1=	CHANGES.md CONTRIBUTING.md GOVERNANCE.md LICENSE.md SECURITY.md \
		CODE_OF_CONDUCT.md CONTRIBUTORS.md README.md
_DOC_FILES2=	*.odt *.pdf

# too many reports about compilation failures, so
# sanity check we are using the same C++ standard library
_imath_libcxx=	${COMPILER_FEATURES:Mlib*c++}
pre-configure:
	@${READELF} -d ${LOCALBASE}/lib/libImath.so \
	| ${EGREP} -q '\<NEEDED\>.*\[${_imath_libcxx:C/\+/\\+/g}\.' \
	|| {	${ECHO_CMD} "*** Your Imath package uses a different C++ standard library than ***" ; \
		${ECHO_CMD} "*** OpenEXR would. Please recompile and reinstall Imath with the  ***" ; \
		${ECHO_CMD} "*** same C++ std. library before trying to build OpenEXR.  Abort. ***" ; \
		exit 1; }

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DOC_FILES1:S|^|${_DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DOC_FILES2:S|^|${_DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR}

post-install-DOCS-off:
	${RM} ${STAGEDIR}${DOCSDIR:H}/OpenEXR/*.pdf
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME} 2>/dev/null || :

post-install-EXAMPLES-on:
	${MV} \
		${STAGEDIR}${PREFIX}/share/doc/OpenEXR/examples/ ${STAGEDIR}${EXAMPLESDIR}
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/doc/OpenEXR 2>/dev/null || :

post-install-EXAMPLES-off:
	${RM} -R ${STAGEDIR}${PREFIX}/share/doc/OpenEXR/examples/
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/doc/OpenEXR 2>/dev/null || :

do-test:
	cd ${BUILD_WRKSRC} && ctest -j ${MAKE_JOBS_NUMBER}

.include <bsd.port.mk>
