# $FreeBSD$

PORTNAME=	gnuradio
PORTVERSION=	3.7.4
PORTREVISION=	3
CATEGORIES=	comms astro hamradio
MASTER_SITES=	http://gnuradio.org/releases/gnuradio/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio Software defined radio

LICENSE=	GPLv3

BUILD_DEPENDS=	sdl-config:${PORTSDIR}/devel/sdl12 \
		swig2.0:${PORTSDIR}/devel/swig20 \
		cheetah:${PORTSDIR}/devel/py-cheetah \
		${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}qt4>0:${PORTSDIR}/devel/py-qt4 \
		xdg-open:${PORTSDIR}/devel/xdg-utils \
		guile:${PORTSDIR}/lang/guile \
		icebox:${PORTSDIR}/devel/ice \
		aconnect:${PORTSDIR}/audio/alsa-utils \
		git:${PORTSDIR}/devel/git \
		${PYNUMPY} \
		${PYTHON_SITELIBDIR}/ephem/__init__.py:${PORTSDIR}/astro/pyephem
LIB_DEPENDS=	libcppunit.so:${PORTSDIR}/devel/cppunit \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libqwt.so:${PORTSDIR}/x11-toolkits/qwt5 \
		libboost_python.so:${PORTSDIR}/devel/boost-python-libs \
		libportaudio.so:${PORTSDIR}/audio/portaudio \
		libjack.so:${PORTSDIR}/audio/jack \
		libasound.so:${PORTSDIR}/audio/alsa-lib \
		libgsl.so:${PORTSDIR}/math/gsl
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		iconv cmake:outsource perl5 python:2.7 shebangfix
SHEBANG_FILES=	grc/freedesktop/grc_setup_freedesktop.in
CMAKE_ENV+=	LD_PRELOAD="${GCC_LIBS}/libstdc++.so:${GCC_LIBS}/libgcc_s.so.1" 
CMAKE_ARGS+=	-DSWIG_EXECUTABLE:STRING="${LOCALBASE}/bin/swig2.0"
CMAKE_ARGS+=	-DICONV_PREFIX:STRING="${ICONV_PREFIX}" \
		-DICONV_LIB:STRING="X${ICONV_LIB}" \
		-DICE_CONFIG_INCLUDE_DIR="${LOCALBASE}/include/"
# for detailed debugging uncomment the next line
#CMAKE_ARGS+=	--debug-output --trace
DOCSDIR=	share/doc/${PORTNAME}-${PORTVERSION}
USE_GNOME=	pygtk2
USE_WX=		3.0+
USE_QT4=	gui xml qmake moc rcc uic
WX_COMPS=	wx wx:build wx:run python:build python:run
USE_LDCONFIG=	yes
PLIST_SUB+=	MAJOR_VERSION="3"
PORTDOCS=	*

OPTIONS_DEFINE=		USRP TESTING
# Unfortunately building docs on i386 fails
##OPTIONS_EXCLUDE_${i386}=	DOCS
# Yay. building docs is broken on 10 and HEAD too so turn them all off
OPTIONS_EXCLUDE=	DOCS
OPTIONS_DEFAULT=	USRP
USRP_DESC=	Include USRP support (UHD) from Ettus
TESTING_DESC=	Include testing support

PLIST_SUB+=	PORTVERSION=${PORTVERSION}
VP=		${GCC_DEFAULT:S/.//}
GCC_LIBS=	${LOCALBASE}/lib/gcc${VP}

.include <bsd.port.pre.mk>

# Only use port clang34 on 10 if not RELEASE. I think this should do it.
.if ${OSVERSION} <= 1000510 && ${OSVERSION} > 1000000
# Debug hack
#.if ${OSVERSION} <= 1200000
BUILD_DEPENDS+=	clang34:${PORTSDIR}/lang/clang34
CC=		clang34
CXX=		clang++34
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
		${LOCALBASE}/bin/sphinx-apidoc:${PORTSDIR}/textproc/py-sphinx \
		dot:${PORTSDIR}/graphics/graphviz \
		xmlto:${PORTSDIR}/textproc/xmlto \
		freefont-ttf>0:${PORTSDIR}/x11-fonts/freefont-ttf
CMAKE_ARGS+=	-DENABLE_DOXYGEN:STRING="ON"
CMAKE_ARGS+=	-DENABLE_DOCS:STRING="ON"
CMAKE_ARGS+=	-DENABLE_BAD_BOOST="ON"
HAVE_PORTDOCS=	YES
.else
CMAKE_ARGS+=	-DENABLE_DOXYGEN:STRING="OFF"
CMAKE_ARGS+=	-DENABLE_DOCS:STRING="OFF"
CMAKE_ARGS+=	-DENABLE_BAD_BOOST="ON"
.endif

.if ${PORT_OPTIONS:MUSRP}
CMAKE_ARGS+=	-DENABLE_GR_UHD:STRING="ON"
BUILD_DEPENDS+=	${LOCALBASE}/include/uhd/config.hpp:${PORTSDIR}/comms/usrp
PLIST_SUB+=	UHD=""
.else
CMAKE_ARGS+=	-DENABLE_GR_UHD:STRING="OFF"
PLIST_SUB+=	UHD="@comment "
.endif

.if ${PORT_OPTIONS:MTESTING}
CMAKE_ARGS+=	-DENABLE_TESTING:STRING="ON"
BUILD_DEPENDS+=	cppunit-config:${PORTSDIR}/devel/cppunit
.else
CMAKE_ARGS+=	-DENABLE_TESTING:STRING="OFF"
.endif

post-patch:
	@${FIND} ${WRKSRC}/.. -name CMakeLists.txt | \
	    ${XARGS} ${REINPLACE_CMD} -e \
		 "s|{GR_LIBRARY_DIR}/pkgconfig|{GR_PKGCONFIG_DIR}/pkgconfig|g"

	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/docs/doxygen/Doxyfile.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/FindPortaudio.cmake

.include <bsd.port.post.mk>
