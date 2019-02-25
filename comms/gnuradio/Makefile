# $FreeBSD$

PORTNAME=	gnuradio
PORTVERSION=	3.7.13.4
PORTREVISION=	4
CATEGORIES=	comms astro hamradio
MASTER_SITES=	http://gnuradio.org/releases/gnuradio/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio Software defined radio

LICENSE=	GPLv3

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BROKEN_aarch64=		fails to compile: /usr/lib/clang/5.0.0/include/mmintrin.h:47:5: use of undeclared identifier '__builtin_ia32_emms'; did you mean '__builtin_isless'?
BROKEN_armv6=		fails to compile: /usr/lib/clang/5.0.0/include/mmintrin.h:47:5: use of undeclared identifier '__builtin_ia32_emms'; did you mean '__builtin_isless'?
BROKEN_armv7=		fails to compile: /usr/lib/clang/5.0.0/include/mmintrin.h:47:5: use of undeclared identifier '__builtin_ia32_emms'; did you mean '__builtin_isless'?

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_SITELIBDIR}/ephem/__init__.py:astro/pyephem@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/mako/__init__.py:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/six.py:devel/py-six@${PY_FLAVOR} \
		aconnect:audio/alsa-utils \
		cheetah:devel/py-cheetah@${PY_FLAVOR} \
		guile:lang/guile \
		minixmlto:textproc/minixmlto \
		sdl-config:devel/sdl12 \
		swig3.0:devel/swig30 \
		xdg-open:devel/xdg-utils
LIB_DEPENDS=	libcppunit.so:devel/cppunit \
		libcodec2.so:audio/codec2 \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libqwt.so:x11-toolkits/qwt5 \
		${PY_BOOST} \
		liblog4cpp.so:devel/log4cpp \
		libportaudio.so:audio/portaudio \
		libjack.so:audio/jack \
		libasound.so:audio/alsa-lib \
		libgsl.so:math/gsl \
		libgsm.so:audio/gsm \
		libboost_date_time.so:devel/boost-libs \
		liborc-0.4.so:devel/orc
RUN_DEPENDS:=	${BUILD_DEPENDS}

# USES=compiler:c11 is necessary because base GCC fails:
# volk/lib/volk_cpu.c: In function 'i_can_has_3dnow':
# volk/lib/volk_cpu.c:62: error: can't find a register in class 'BREG' while reloading 'asm'
# volk/lib/volk_cpu.c:62: error: 'asm' operand has impossible constraints
USES=		cmake compiler:c11 fortran iconv perl5 pkgconfig pyqt:4 python:2.7 qt:4 shebangfix
SHEBANG_FILES=	grc/scripts/freedesktop/grc_setup_freedesktop.in \
		gnuradio-runtime/python/gnuradio/ctrlport/gr-ctrlport-monitor \
		gnuradio-runtime/python/gnuradio/ctrlport/gr-perf-monitorx
CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH:STRING="${LOCALBASE}/lib/gcc${_GCC_VER}" \
		-DENABLE_GR_CTRLPORT="YES" \
		-DICONV_LIB:STRING="X${ICONV_LIB}" \
		-DICONV_PREFIX:STRING="${ICONV_PREFIX}" \
		-DLOCALBASE:STRING="${LOCALBASE}" \
		-DPYTHON_EXECUTABLE:STRING="${PYTHON_CMD}" \
		-DSWIG_EXECUTABLE:STRING="${LOCALBASE}/bin/swig3.0"\
		-DXMLTO_EXECUTABLE:STRING=minixmlto
# for detailed debugging uncomment the next line
#CMAKE_ARGS+=	--debug-output --trace
MAJOR_SUB_VER=	${PORTVERSION}
DOCSDIR=	share/doc/${PORTNAME}-${PORTVERSION}
USE_GNOME=	pygtk2
USE_PYQT=	core gui opengl
USE_WX=		3.0+
USE_QT=		corelib gui xml qmake moc_build rcc_build uic_build
WX_COMPS=	wx wx:build wx:run python:build python:run
USE_LDCONFIG=	yes
PLIST_SUB+=	MAJOR_VERSION="3"
PLIST_SUB+=	MAJOR_SUB_VER="${MAJOR_SUB_VER}"
LIBSTRIP_FILES=	analog atsc audio blocks channels digital dtv fcd fec fft\
		filter noaa pager pmt qtgui runtime trellis video-sdl\
		vocoder wavelet wxgui

OPTIONS_DEFINE=		DOCS UHD TESTING DOXYGEN
# Unfortunately building docs on i386 fails
##OPTIONS_EXCLUDE_${i386}=	DOXYGEN
# Yay. building docs is broken on 10 and HEAD too so turn them all off
OPTIONS_EXCLUDE=	DOXYGEN
OPTIONS_DEFAULT=	UHD
OPTIONS_SUB=		yes
UHD_DESC=	Include UHD support from Ettus
TESTING_DESC=	Include testing support

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-apidoc:textproc/py-sphinx@${PY_FLAVOR} \
			dot:graphics/graphviz \
			xmlto:textproc/xmlto \
			freefont-ttf>0:x11-fonts/freefont-ttf
DOXYGEN_CMAKE_ON=	-DENABLE_DOXYGEN:STRING="ON" \
		-DENABLE_DOCS:STRING="ON"
DOXYGEN_CMAKE_OFF=	-DENABLE_DOXYGEN:STRING="OFF" \
		-DENABLE_DOCS:STRING="OFF"
HAVE_PORTDOCS=	YES

UHD_CMAKE_ON=	-DENABLE_GR_UHD:STRING="ON"
UHD_CMAKE_OFF=	-DENABLE_GR_UHD:STRING="OFF"

TESTING_CMAKE_ON=	-DENABLE_TESTING:STRING="ON"
TESTING_CMAKE_OFF=	-DENABLE_TESTING:STRING="OFF"
TESTING_BUILD_DEPENDS=	cppunit-config:devel/cppunit

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MUHD}
LIBSTRIP_FILES+=	uhd
LIB_DEPENDS+=	libuhd.so:comms/uhd
PLIST_SUB+=	UHD=""
.else
PLIST_SUB+=	UHD="@comment "
.endif

PATCH_FILES=	docs/doxygen/Doxyfile.in \
		gr-fec/lib/CMakeLists.txt

post-patch:
	@${FIND} ${WRKSRC}/.. -name CMakeLists.txt | \
	    ${XARGS} ${REINPLACE_CMD} -e \
		 "s|{GR_LIBRARY_DIR}/pkgconfig|{GR_PKGCONFIG_DIR}/pkgconfig|g"

.for p in ${PATCH_FILES}
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/${p}
.endfor

post-install:
.for a in ${LIBSTRIP_FILES}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnuradio-${a}.so.${MAJOR_SUB_VER}
.endfor

.include <bsd.port.post.mk>
