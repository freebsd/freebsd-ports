PORTNAME?=	openexr
PORTVERSION?=	3.3.5 # ALSO update openexr-website-docs! -- verify sigstore: make makesum verify-sigstore
PORTREVISION?=	0
CATEGORIES=	graphics devel
.if !defined(MASTERDIR)
MASTER_SITES=	https://raw.githubusercontent.com/AcademySoftwareFoundation/openexr-images/v1.0/:testimages \
		https://github.com/AcademySoftwareFoundation/openexr/releases/download/v${PORTVERSION}/:DEFAULT \
		LOCAL/mandree/openexr/:DEFAULT \
		LOCAL/mandree/openexr/:testimages
DISTFILES=	${EXTRACT_ONLY}:DEFAULT
DISTFILES+=	Beachball/multipart.0001.exr:testimages
DISTFILES+=	Beachball/singlepart.0001.exr:testimages
DISTFILES+=	Chromaticities/Rec709_YC.exr:testimages
DISTFILES+=	Chromaticities/Rec709.exr:testimages
DISTFILES+=	Chromaticities/XYZ_YC.exr:testimages
DISTFILES+=	Chromaticities/XYZ.exr:testimages
DISTFILES+=	LuminanceChroma/Flowers.exr:testimages
DISTFILES+=	LuminanceChroma/Garden.exr:testimages
DISTFILES+=	MultiResolution/ColorCodedLevels.exr:testimages
DISTFILES+=	MultiResolution/WavyLinesCube.exr:testimages
DISTFILES+=	MultiResolution/WavyLinesLatLong.exr:testimages
DISTFILES+=	MultiView/Adjuster.exr:testimages
DISTFILES+=	TestImages/GammaChart.exr:testimages
DISTFILES+=	TestImages/GrayRampsHorizontal.exr:testimages
DISTFILES+=	v2/LeftView/Balls.exr:testimages
DISTFILES+=	v2/Stereo/Trunks.exr:testimages
.endif
DIST_SUBDIR=	openexr # hardcode - not using ${PORTNAME} - so we can share the distdir with openexr-website-docs, avoiding double download of ...
EXTRACT_ONLY=	openexr-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	High dynamic-range (HDR) image file format
WWW=		https://www.openexr.com/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS?=	help2man:misc/help2man
# exact libImath version required to avoid hard-to-debug issues
LIB_DEPENDS?=	libImath-3_1.so.29:math/Imath \
		libdeflate.so:archivers/libdeflate

USES?=		cmake:testing compiler:c++14-lang cpe pathfix pkgconfig

#USE_GITHUB=	yes
#GH_TUPLE=	AcademySoftwareFoundation:openexr:v${PORTVERSION}

USE_LDCONFIG=	yes

CMAKE_ARGS?=	-DCMAKE_DEBUG_POSTFIX=

CMAKE_OFF=	BUILD_TESTING \
		OPENEXR_TEST_LIBRARIES \
		OPENEXR_TEST_PYTHON \
		OPENEXR_TEST_TOOLS

CMAKE_TESTING_ON=	BUILD_TESTING \
			OPENEXR_TEST_LIBRARIES \
			OPENEXR_TEST_PYTHON \
			OPENEXR_TEST_TOOLS

CPPFLAGS+=	-I.
# must be linked with -l{thr|pthread} explicitly
LDFLAGS+=	-lpthread

_MAJORVER=	3_3
_VER=		32
_REL=		${PORTVERSION}
PLIST_SUB+=	MAJORVER=${_MAJORVER} \
		VER=${_VER} \
		REL=${_REL}

PORTDOCS=	*
PORTEXAMPLES=	*

.if !defined(MASTERDIR)
OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes
DOCS_CMAKE_BOOL=OPENEXR_INSTALL_DOCS INSTALL_DOCS

_DOCSRCDIR1=	${WRKSRC}
_DOC_FILES1=	CHANGES.md CONTRIBUTING.md GOVERNANCE.md LICENSE.md SECURITY.md \
		CODE_OF_CONDUCT.md CONTRIBUTORS.md README.md

# too many reports about compilation failures, so
# sanity check we are using the same C++ standard library
_imath_libcxx=	${COMPILER_FEATURES:Mlib*c++}

# This would be better placed in pre-test to avoid wasting space,
# but if we do that, the cmake in src/test/bin will go downloading the files,
# so we do not benefit from our checksumming and the distdir caching.
post-extract:
	${MKDIR} ${CONFIGURE_WRKSRC}/src/test/bin
.for i in ${DISTFILES:M*.exr?testimages}
	d="$$(dirname "${CONFIGURE_WRKSRC}/src/test/bin/${i:S/:testimages//}")" \
	  && ${MKDIR} "$$d" \
	  && ${CP} ${DISTDIR}/${DIST_SUBDIR}/${i:S/:testimages//} "$$d"
.endfor

pre-configure:
	@${READELF} -d ${LOCALBASE}/lib/libImath.so \
	| ${EGREP} -q '\<NEEDED\>.*\[${_imath_libcxx:C/\+/\\+/g}\.' \
	|| {	${ECHO_CMD} "*** Your Imath package uses a different C++ standard library than ***" ; \
		${ECHO_CMD} "*** OpenEXR would. Please recompile and reinstall Imath with the  ***" ; \
		${ECHO_CMD} "*** same C++ std. library before trying to build OpenEXR.  Abort. ***" ; \
		exit 1; }

post-install-EXAMPLES-on:
	${MV} \
		${STAGEDIR}${PREFIX}/share/doc/OpenEXR/examples/ ${STAGEDIR}${EXAMPLESDIR}
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/doc/OpenEXR 2>/dev/null || :

post-install-EXAMPLES-off:
	${RM} -R ${STAGEDIR}${PREFIX}/share/doc/OpenEXR/examples/
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/doc/OpenEXR 2>/dev/null || :

verify-sigstore: openexr-${PORTVERSION}.tar.gz.sigstore.json
	sigstore verify github --cert-identity https://github.com/AcademySoftwareFoundation/openexr/.github/workflows/release-sign.yml@refs/tags/v${PORTVERSION} ${DISTDIR}/${DIST_SUBDIR}/openexr-${PORTVERSION}.tar.gz --bundle openexr-${PORTVERSION}.tar.gz.sigstore.json

openexr-${PORTVERSION}.tar.gz.sigstore.json:
	${FETCH_CMD} https://github.com/AcademySoftwareFoundation/openexr/releases/download/v${PORTVERSION}/openexr-${PORTVERSION}.tar.gz.sigstore.json

.endif
.include <bsd.port.mk>
