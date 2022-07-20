PORTNAME=	openexr
PORTVERSION=	3.1.5
CATEGORIES=	graphics devel

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	High dynamic-range (HDR) image file format

LICENSE=	BSD3CLAUSE

# exact version required to avoid hard-to-debug issues
LIB_DEPENDS=	libImath-3_1.so.29:math/Imath

USES=		cmake compiler:c++14-lang cpe pathfix pkgconfig

USE_GITHUB=	yes
GH_TUPLE=	AcademySoftwareFoundation:openexr:v${PORTVERSION}

USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DCMAKE_DEBUG_POSTFIX=
CPPFLAGS+=	-I.
# must be linked with -l{thr|pthread} explicitly
LDFLAGS+=	-lpthread

PATCH_STRIP=	-p0

_MAJORVER=	3_1
_VER=		30
_MINVER=	5
_PLVER=		1

PLIST_SUB+=	MAJORVER=${_MAJORVER} \
		VER=${_VER} \
		MINVER=${_MINVER} \
		PLVER=${_PLVER}

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes
DOCS_BUILD_DEPENDS=breathe-apidoc:devel/py-breathe
DOCS_CMAKE_BOOL=DOCS

_DOCSRCDIR1=	${WRKSRC}
_DOC_FILES1=	CHANGES.md CONTRIBUTING.md GOVERNANCE.md LICENSE.md SECURITY.md \
		CODE_OF_CONDUCT.md CONTRIBUTORS.md README.md

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
	( cd ${BUILD_WRKSRC}/docs/sphinx && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} )
	${RM} -r ${STAGEDIR}${DOCSDIR}/.??* ${STAGEDIR}${DOCSDIR}/../OpenEXR/sphinx

post-install-DOCS-off:
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
