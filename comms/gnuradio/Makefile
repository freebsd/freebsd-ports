# $FreeBSD$

PORTNAME=	gnuradio
PORTVERSION=	3.7.8
CATEGORIES=	comms astro hamradio
MASTER_SITES=	http://gnuradio.org/releases/gnuradio/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio Software defined radio

LICENSE=	GPLv3

BUILD_DEPENDS=	sdl-config:devel/sdl12 \
		swig2.0:devel/swig20 \
		cheetah:devel/py-cheetah \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}qt4>0:devel/py-qt4 \
		xdg-open:devel/xdg-utils \
		guile:lang/guile \
		aconnect:audio/alsa-utils \
		git:devel/git \
		${PYNUMPY} \
		${PYTHON_SITELIBDIR}/ephem/__init__.py:astro/pyephem
LIB_DEPENDS=	libcppunit.so:devel/cppunit \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libqwt.so:x11-toolkits/qwt5 \
		libboost_python.so:devel/boost-python-libs \
		libportaudio.so:audio/portaudio \
		libjack.so:audio/jack \
		libasound.so:audio/alsa-lib \
		libgsl.so:math/gsl
RUN_DEPENDS:=	${BUILD_DEPENDS}

# USES=compiler:c11 is necessary because base GCC fails:
# volk/lib/volk_cpu.c: In function 'i_can_has_3dnow':
# volk/lib/volk_cpu.c:62: error: can't find a register in class 'BREG' while reloading 'asm'
# volk/lib/volk_cpu.c:62: error: 'asm' operand has impossible constraints
USES=		cmake:outsource compiler:c11 iconv perl5 python:2.7 shebangfix
SHEBANG_FILES=	grc/freedesktop/grc_setup_freedesktop.in
CMAKE_ARGS+=	-DSWIG_EXECUTABLE:STRING="${LOCALBASE}/bin/swig2.0"
CMAKE_ARGS+=	-DICONV_PREFIX:STRING="${ICONV_PREFIX}" \
		-DICONV_LIB:STRING="X${ICONV_LIB}" \
		-DENABLE_GR_CTRLPORT="YES"
# for detailed debugging uncomment the next line
#CMAKE_ARGS+=	--debug-output --trace
MAJOR_SUB_VER=	3.7.8
DOCSDIR=	share/doc/${PORTNAME}-${MAJOR_SUB_VER}
USE_GNOME=	pygtk2
USE_WX=		3.0+
USE_QT4=	gui xml qmake moc rcc uic
WX_COMPS=	wx wx:build wx:run python:build python:run
USE_LDCONFIG=	yes
PLIST_SUB+=	MAJOR_VERSION="3"
PLIST_SUB+=	MAJOR_SUB_VER="${MAJOR_SUB_VER}"
LIBSTRIP_FILES=	analog atsc audio blocks channels digital dtv fcd fec fft\
		filter noaa pager pmt qtgui runtime trellis video-sdl\
		vocoder wavelet wxgui

OPTIONS_DEFINE=		USRP TESTING
# Unfortunately building docs on i386 fails
##OPTIONS_EXCLUDE_${i386}=	DOCS
# Yay. building docs is broken on 10 and HEAD too so turn them all off
OPTIONS_EXCLUDE=	DOCS
OPTIONS_DEFAULT=	USRP
OPTIONS_SUB=		yes
USRP_DESC=	Include USRP support (UHD) from Ettus
TESTING_DESC=	Include testing support

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			${LOCALBASE}/bin/sphinx-apidoc:textproc/py-sphinx \
			dot:graphics/graphviz \
			xmlto:textproc/xmlto \
			freefont-ttf>0:x11-fonts/freefont-ttf
DOCS_CMAKE_ON=	-DENABLE_DOXYGEN:STRING="ON" \
		-DENABLE_DOCS:STRING="ON" \
		-DENABLE_BAD_BOOST="ON"
DOCS_CMAKE_OFF=	-DENABLE_DOXYGEN:STRING="OFF" \
		-DENABLE_DOCS:STRING="OFF" \
		-DENABLE_BAD_BOOST="ON"
HAVE_PORTDOCS=	YES

USRP_CMAKE_ON=	-DENABLE_GR_UHD:STRING="ON"
USRP_CMAKE_OFF=	-DENABLE_GR_UHD:STRING="OFF"
USRP_BUILD_DEPENDS=	${LOCALBASE}/include/uhd/config.hpp:comms/usrp

TESTING_CMAKE_ON=	-DENABLE_TESTING:STRING="ON"
TESTING_CMAKE_OFF=	-DENABLE_TESTING:STRING="OFF"
TESTING_BUILD_DEPENDS=	cppunit-config:devel/cppunit

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MUSRP}
LIBSTRIP_FILES+=	uhd
.endif
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

post-patch:
	@${FIND} ${WRKSRC}/.. -name CMakeLists.txt | \
	    ${XARGS} ${REINPLACE_CMD} -e \
		 "s|{GR_LIBRARY_DIR}/pkgconfig|{GR_PKGCONFIG_DIR}/pkgconfig|g"

	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/docs/doxygen/Doxyfile.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/FindPortaudio.cmake

post-install:
.for a in ${LIBSTRIP_FILES}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnuradio-${a}.so.${MAJOR_SUB_VER}
.endfor

.include <bsd.port.post.mk>
