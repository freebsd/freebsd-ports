PORTNAME=	limesuite
DISTVERSIONPREFIX=	v
DISTVERSION=	20.10.0
PORTREVISION=	4
CATEGORIES=	comms astro hamradio

MAINTAINER=	tomek@cedro.info
COMMENT=	Software Defined Radio Software Suite from Lime Microsystems

LICENSE=	APACHE20

BUILD_DEPENDS=	gnuplot:math/gnuplot
RUN_DEPENDS=	sqlite3:databases/sqlite3

USES=		cmake compiler:c11
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	myriadrf
GH_PROJECT=	LimeSuite

CMAKE_ARGS=	-DENABLE_SIMD_FLAGS:STRING="none"
# DESKTOP IS LINUX ONLY.
# SPI IS LINUX ONLY.
# STREAM UNITE BROKEN UPSTREAM
CMAKE_OFF=	ENABLE_DESKTOP \
		ENABLE_SPI \
		ENABLE_STREAM \
		ENABLE_STREAM_UNITE

CMAKE_ON=	ENABLE_LIBRARY \
		ENABLE_LIME_UTIL \
		ENABLE_EXAMPLES \
		ENABLE_LIMERFE \
		ENABLE_EVB7COM

OPTIONS_DEFINE=		DOCS GUI QUICKTEST OCTAVE REMOTE SOAPYSDR DEBUG
OPTIONS_DEFAULT=	GUI QUICKTEST SOAPYSDR DEBUG
OPTIONS_UNSET=		DOCS
OPTIONS_SUB=		yes
QUICKTEST_DESC=		Build QuickTest Self-Test suite
OCTAVE_DESC=		Enable Octave integration
REMOTE_DESC=		Enable remote testing operations
SOAPYSDR_DESC=		Build LMS7 SoapySDR bindings

PLIST_SUB=		PORTVERSION=${PORTVERSION}

DOCS_CMAKE_BOOL=	ENABLE_API_DOXYGEN
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen

GUI_CMAKE_BOOL=		ENABLE_GUI

QUICKTEST_CMAKE_BOOL=	ENABLE_QUICKTEST
QUICKTEST_LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

OCTAVE_CMAKE_BOOL=	ENABLE_OCTAVE
OCTAVE_BUILD_DEPENDS=	octave:math/octave

REMOTE_CMAKE_BOOL=	ENABLE_REMOTE

SOAPYSDR_CMAKE_BOOL=	ENABLE_SOAPY_LMS7
SOAPYSDR_LIB_DEPENDS=	libSoapySDR.so:misc/soapysdr

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGUI}
USES+=		gl xorg
USE_XORG+=	x11 ice sm xcursor xext xfixes xinerama xft xrender
USE_GL+=		gl glu
USE_WX+=		3.1
WX_COMPS+=	wx:lib
LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig
.endif

.if ${PORT_OPTIONS:MOCTAVE}
.include "${.CURDIR}/../../math/octave/Makefile.version"
OCTAVE_OCT_SITE_DIR=	"lib/octave/${OCTAVE_VERSION}/site/oct/${CONFIGURE_TARGET}/"
PLIST_SUB+=	OCTAVE_OCT_SITE_DIR=${OCTAVE_OCT_SITE_DIR}
OCTAVE_M_SITE_DIR=	"share/octave/${OCTAVE_VERSION}/site/m/"
PLIST_SUB+=	OCTAVE_M_SITE_DIR=${OCTAVE_M_SITE_DIR}
.endif

.if ${PORT_OPTIONS:MDEBUG}
WITH_DEBUG=	yes
.endif

post-build:
# N.B. COPYTREE_BIN here chmods 555 which breaks CMAKE_INSTALL in user mode!
	(cd ${BUILD_WRKSRC}/bin && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/bin)
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MGUI}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	(cd ${WRKSRC}/Desktop && ${CP} *.png ${STAGEDIR}${PREFIX}/share/pixmaps/)
	(cd ${WRKSRC}/Desktop && ${CP} lime-suite.desktop ${STAGEDIR}${PREFIX}/share/applications/)
.endif

.include <bsd.port.post.mk>
