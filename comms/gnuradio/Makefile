PORTNAME=	gnuradio
DISTVERSIONPREFIX=	v
DISTVERSION=	3.10.12.0
PORTREVISION=	5
CATEGORIES=	comms astro hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio Software defined radio
WWW=		https://www.gnuradio.org/

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyqtgraph>0:graphics/py-pyqtgraph@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=1.2.2,1:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/click/__init__.py:devel/py-click@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/click_plugins/__init__.py:devel/py-click-plugins@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/gi/__init__.py:devel/py-pygobject@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/mako/__init__.py:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/pygccxml/__init__.py:textproc/py-pygccxml@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/pytest/__init__.py:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/yaml/__init__.py:devel/py-pyyaml@${PY_FLAVOR} \
		${SCIPY} \
		aconnect:audio/alsa-utils \
		cheetah:devel/py-cheetah3@${PY_FLAVOR} \
		cppzmq>0:net/cppzmq \
		minixmlto:textproc/minixmlto \
		mpir>0:math/mpir \
		pybind11>0:devel/pybind11 \
		pygobject-common>0:devel/pygobject-common \
		sdl-config:devel/sdl12 \
		volk>0:devel/volk \
		xdg-open:devel/xdg-utils
LIB_DEPENDS=	libad9361.so:misc/libad9361-iio \
		libasound.so:audio/alsa-lib \
		libboost_system.so:devel/boost-libs \
		libcodec2.so:audio/codec2 \
		libfftw3f.so:math/fftw3-float \
		libfmt.so:devel/libfmt \
		libgmpxx.so:math/gmp \
		libgsl.so:math/gsl \
		libgsm.so:audio/gsm \
		libiio.so:misc/libiio \
		libjack.so:audio/jack \
		libportaudio.so:audio/portaudio \
		libsndfile.so:audio/libsndfile \
		libSoapySDR.so:misc/soapysdr \
		libspdlog.so:devel/spdlog \
		libunwind.so:devel/libunwind \
		libqwt.so:x11-toolkits/qwt6@qt5 \
		libzmq.so:net/libzmq4
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cmake compiler:c++14-lang desktop-file-utils fortran gnome \
		iconv localbase:ldflags perl5 pkgconfig pyqt:5 python \
		qt:5 shared-mime-info shebangfix

SHEBANG_FILES=	gnuradio-runtime/python/gnuradio/ctrlport/gr-ctrlport-monitor \
		gnuradio-runtime/python/gnuradio/ctrlport/gr-perf-monitorx \
		grc/scripts/freedesktop/grc_setup_freedesktop.in

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH:STRING="${LOCALBASE}/lib/gcc${_GCC_VER}" \
		-DENABLE_GR_CTRLPORT="YES" \
		-DENABLE_GR_QTGUI="YES" \
		-DENABLE_INTERNAL_VOLK:STRING="OFF" \
		-DGR_PKG_DOC_DIR:STRING="${DOCSDIR}" \
		-DICONV_LIB:STRING="X${ICONV_LIB}" \
		-DICONV_PREFIX:STRING="${ICONV_PREFIX}" \
		-DLOCALBASE:STRING="${LOCALBASE}" \
		-DPYTHON_EXECUTABLE:STRING="${PYTHON_CMD}" \
		-DXMLTO_EXECUTABLE:STRING=minixmlto
# for detailed debugging uncomment the next line
#CMAKE_ARGS+=	--debug-output --trace
CFLAGS+=	-Wno-deprecated
CXXFLAGS+=	-Wno-deprecated
USE_CXXSTD=	c++14
USE_GNOME=	gtk30
USE_GITHUB=	yes
USE_PYQT=	pyqt5
USE_QT=		buildtools core gui qmake widgets
USE_LDCONFIG=	yes
LIBSTRIP_FILES=	analog audio blocks channels digital dtv fec fft filter pmt \
		qtgui runtime trellis video-sdl vocoder wavelet

OPTIONS_DEFINE=	DOCS UHD
OPTIONS_SUB=	yes
UHD_DESC=	Include UHD support from Ettus

PLIST_SUB+=	PORTMAINVER=${PORTVERSION:C|^([1-9]+)\.([0-9]+)\.([0-9]+).*|\1.\2.\3|} \
		PORTVERSION=${PORTVERSION}

DOCS_RUN_DEPEND=	freefont-ttf>0:x11-fonts/freefont-ttf

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.2.2,1:textproc/py-sphinx@${PY_FLAVOR} \
			dot:graphics/graphviz \
			doxygen:devel/doxygen \
			MathJax>0:www/mathjax \
			xmlto:textproc/xmlto
DOCS_CMAKE_ON=		-DENABLE_DOCS:STRING="ON" \
			-DENABLE_DOXYGEN:STRING="ON" \
			-DMATHJAX2_USE_ROOT="${LOCALBASE}/www/MathJax"
DOCS_CMAKE_OFF=		-DENABLE_DOCS:STRING="OFF" \
			-DENABLE_DOXYGEN:STRING="OFF"

UHD_CMAKE_ON=	-DENABLE_GR_UHD:STRING="ON"
UHD_CMAKE_OFF=	-DENABLE_GR_UHD:STRING="OFF"

ICONDIR=	${PREFIX}/share/icons
MIME=		${PREFIX}/share/mime/packages
post-install:
.for size in 16 24 32 48 64 128 256
	${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${MKDIR} ${STAGEDIR}${ICONDIR}/gnome/${size}x${size}/apps
	${MKDIR} ${STAGEDIR}${ICONDIR}/hicolor/${size}x${size}/apps
	${MKDIR} ${STAGEDIR}/share/applications
	${INSTALL_DATA} ${WRKSRC}/grc/scripts/freedesktop/grc-icon-${size}.png \
		${STAGEDIR}${ICONDIR}/gnome/${size}x${size}/apps/gnuradio-grc.png
	${INSTALL_DATA} ${WRKSRC}/grc/scripts/freedesktop/grc-icon-${size}.png \
		${STAGEDIR}${ICONDIR}/hicolor/${size}x${size}/apps/gnuradio-grc.png
	${INSTALL_DATA} ${WRKSRC}/grc/scripts/freedesktop/gnuradio-grc.xml \
		${STAGEDIR}${MIME}/gnuradio-grc.xml
	${INSTALL_DATA} ${WRKSRC}/grc/scripts/freedesktop/gnuradio-grc.desktop \
		${STAGEDIR}${PREFIX}/share/applications/gnuradio-grc.desktop
.endfor

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MUHD}
LIBSTRIP_FILES+=	uhd
LIB_DEPENDS+=		libuhd.so:comms/uhd
PLIST_SUB+=		UHD=""
.else
PLIST_SUB+=		UHD="@comment "
.endif

.include <bsd.port.post.mk>
