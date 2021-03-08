# $FreeBSD$

PORTNAME=	gnuradio
DISTVERSIONPREFIX=	v
DISTVERSION=	3.8.1.0
PORTREVISION=	5
CATEGORIES=	comms astro hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio Software defined radio

LICENSE=	GPLv3

BUILD_DEPENDS=	volk>0:devel/volk \
		doxygen>0:devel/doxygen \
		${PYTHON_PKGNAMEPREFIX}sphinx>=1.2.2,1:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_SITELIBDIR}/mako/__init__.py:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/yaml/__init__.py:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/gi/__init__.py:devel/py-gobject3@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/cairo/__init__.py:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/six.py:devel/py-six@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/click/__init__.py:devel/py-click@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/click_plugins/__init__.py:devel/py-click-plugins@${PY_FLAVOR} \
		aconnect:audio/alsa-utils \
		cheetah:devel/py-cheetah3@${PY_FLAVOR} \
		cppzmq>0:net/cppzmq \
		guile:lang/guile \
		minixmlto:textproc/minixmlto \
		sdl-config:devel/sdl12 \
		swig:devel/swig \
		mpir>0:math/mpir \
		xdg-open:devel/xdg-utils
LIB_DEPENDS=	libcodec2.so:audio/codec2 \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libgmpxx.so:math/gmp \
		libqwt6.so:x11-toolkits/qwt6 \
		${PY_BOOST} \
		liblog4cpp.so:devel/log4cpp \
		libportaudio.so:audio/portaudio \
		libjack.so:audio/jack \
		libasound.so:audio/alsa-lib \
		libgsl.so:math/gsl \
		libgsm.so:audio/gsm \
		libboost_date_time.so:devel/boost-libs \
		liborc-0.4.so:devel/orc \
		libzmq.so:net/libzmq4
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cmake compiler:c++11-lang desktop-file-utils fortran gnome \
		iconv perl5 pkgconfig pyqt:5 python:3.5+ qt:5 shared-mime-info \
		shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	gnuradio
GH_PROJECT=	gnuradio

SHEBANG_FILES=	grc/scripts/freedesktop/grc_setup_freedesktop.in \
		gnuradio-runtime/python/gnuradio/ctrlport/gr-ctrlport-monitor \
		gnuradio-runtime/python/gnuradio/ctrlport/gr-perf-monitorx

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH:STRING="${LOCALBASE}/lib/gcc${_GCC_VER}" \
		-DENABLE_GR_CTRLPORT="YES" \
		-DICONV_LIB:STRING="X${ICONV_LIB}" \
		-DICONV_PREFIX:STRING="${ICONV_PREFIX}" \
		-DLOCALBASE:STRING="${LOCALBASE}" \
		-DGR_PKG_DOC_DIR:STRING="${DOCSDIR}" \
		-DPYTHON_EXECUTABLE:STRING="${PYTHON_CMD}" \
		-DSWIG_EXECUTABLE:STRING="${LOCALBASE}/bin/swig"\
		-DXMLTO_EXECUTABLE:STRING=minixmlto \
		-DENABLE_INTERNAL_VOLK:STRING="OFF"
# for detailed debugging uncomment the next line
#CMAKE_ARGS+=	--debug-output --trace
USE_CXXSTD=	c++11
USE_PYQT=	core gui opengl
USE_WX=		3.0
USE_QT=		buildtools core gui xml qmake widgets
WX_COMPS=	wx wx:build wx:run python:build python:run
USE_LDCONFIG=	yes
LIBSTRIP_FILES=	analog audio blocks channels digital dtv fec fft\
		filter pmt qtgui runtime trellis video-sdl\
		vocoder wavelet

OPTIONS_DEFINE=		DOCS UHD TESTING DOXYGEN
# Unfortunately building docs on i386 fails
##OPTIONS_EXCLUDE_${i386}=	DOXYGEN
# Yay. building docs is broken on 10 and HEAD too so turn them all off
OPTIONS_EXCLUDE=	DOXYGEN
OPTIONS_SUB=		yes
UHD_DESC=	Include UHD support from Ettus
TESTING_DESC=	Include testing support
INSTALLS_ICONS=		yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			${PYTHON_PKGNAMEPREFIX}sphinx>=1.2.2,1:textproc/py-sphinx@${PY_FLAVOR} \
			dot:graphics/graphviz \
			xmlto:textproc/xmlto \
			freefont-ttf>0:x11-fonts/freefont-ttf
DOXYGEN_CMAKE_ON=	-DENABLE_DOXYGEN:STRING="ON" \
		-DENABLE_DOCS:STRING="ON"
DOXYGEN_CMAKE_OFF=	-DENABLE_DOXYGEN:STRING="OFF" \
		-DENABLE_DOCS:STRING="OFF"

UHD_CMAKE_ON=	-DENABLE_GR_UHD:STRING="ON"
UHD_CMAKE_OFF=	-DENABLE_GR_UHD:STRING="OFF"

TESTING_CMAKE_ON=	-DENABLE_TESTING:STRING="ON"
TESTING_CMAKE_OFF=	-DENABLE_TESTING:STRING="OFF"

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MUHD}
LIBSTRIP_FILES+=	uhd
LIB_DEPENDS+=	libuhd.so:comms/uhd
PLIST_SUB+=	UHD=""
.else
PLIST_SUB+=	UHD="@comment "
.endif

.include <bsd.port.post.mk>
