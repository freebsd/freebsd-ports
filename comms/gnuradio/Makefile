# $FreeBSD$

PORTNAME=	gnuradio
PORTVERSION=	3.7.7.1
PORTREVISION=	1
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

USES=		cmake:outsource iconv perl5 python:2.7 shebangfix
SHEBANG_FILES=	grc/freedesktop/grc_setup_freedesktop.in
CMAKE_ARGS+=	-DSWIG_EXECUTABLE:STRING="${LOCALBASE}/bin/swig2.0"
CMAKE_ARGS+=	-DICONV_PREFIX:STRING="${ICONV_PREFIX}" \
		-DICONV_LIB:STRING="X${ICONV_LIB}" \
		-DENABLE_GR_CTRLPORT="YES"
# for detailed debugging uncomment the next two lines as needed
#CMAKE_ARGS+=	--debug-output --trace
MAJOR_SUB_VER=	3.7.7
DOCSDIR=	share/doc/${PORTNAME}-${MAJOR_SUB_VER}
USE_GNOME=	pygtk2
USE_WX=		3.0+
USE_QT4=	gui xml qmake moc rcc uic
WX_COMPS=	wx wx:build wx:run python:build python:run
USE_LDCONFIG=	yes
PLIST_SUB+=	MAJOR_VERSION="3"
PLIST_SUB+=	MAJOR_SUB_VER="${MAJOR_SUB_VER}"

OPTIONS_DEFINE=		USRP TESTING
# Unfortunately building docs on i386 fails
##OPTIONS_EXCLUDE_${i386}=	DOCS
# Yay. building docs is broken on 10 and HEAD too so turn them all off
OPTIONS_EXCLUDE=	DOCS
OPTIONS_DEFAULT=	USRP
USRP_DESC=	Include USRP support (UHD) from Ettus
TESTING_DESC=	Include testing support

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

DOCS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen \
			${LOCALBASE}/bin/sphinx-apidoc:${PORTSDIR}/textproc/py-sphinx \
			dot:${PORTSDIR}/graphics/graphviz \
			xmlto:${PORTSDIR}/textproc/xmlto \
			freefont-ttf>0:${PORTSDIR}/x11-fonts/freefont-ttf
DOCS_CMAKE_ON=	-DENABLE_DOXYGEN:STRING="ON" \
		-DENABLE_DOCS:STRING="ON" \
		-DENABLE_BAD_BOOST="ON"
DOCS_CMAKE_OFF=	-DENABLE_DOXYGEN:STRING="OFF" \
		-DENABLE_DOCS:STRING="OFF" \
		-DENABLE_BAD_BOOST="ON"
HAVE_PORTDOCS=	YES

USRP_CMAKE_ON=	-DENABLE_GR_UHD:STRING="ON"
USRP_CMAKE_OFF=	-DENABLE_GR_UHD:STRING="OFF"
USRP_BUILD_DEPENDS=	${LOCALBASE}/include/uhd/config.hpp:${PORTSDIR}/comms/usrp

TESTING_CMAKE_ON=	-DENABLE_TESTING:STRING="ON"
TESTING_CMAKE_OFF=	-DENABLE_TESTING:STRING="OFF"
TESTING_BUILD_DEPENDS=	cppunit-config:${PORTSDIR}/devel/cppunit

.include <bsd.port.options.mk>

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

.include <bsd.port.mk>
