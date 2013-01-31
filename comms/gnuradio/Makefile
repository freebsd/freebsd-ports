# $FreeBSD$

PORTNAME=	gnuradio
PORTVERSION=	3.6.2
PORTREVISION=	1
CATEGORIES=	comms astro hamradio
MASTER_SITES=	http://gnuradio.org/releases/gnuradio/

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio Software defined radio

BUILD_DEPENDS=	sdl-config:${PORTSDIR}/devel/sdl12\
		swig:${PORTSDIR}/devel/swig13\
		cheetah:${PORTSDIR}/devel/py-cheetah\
		${LOCALBASE}/lib/portaudio2/libportaudio.so:${PORTSDIR}/audio/portaudio2 \
		py*-lxml>=0:${PORTSDIR}/devel/py-lxml\
		${PYTHON_SITELIBDIR}/pygtk.py:${PORTSDIR}/x11-toolkits/py-gtk2\
		${PYTHON_SITELIBDIR}/PyQt4/Qt.py:${PORTSDIR}/devel/py-qt4\
		xdg-open:${PORTSDIR}/devel/xdg-utils\
		guile:${PORTSDIR}/lang/guile\
		git:${PORTSDIR}/devel/git\
		jackd:${PORTSDIR}/audio/jack\
		aserver:${PORTSDIR}/audio/alsa-lib
LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3\
		fftw3f:${PORTSDIR}/math/fftw3-float\
		qwt:${PORTSDIR}/x11-toolkits/qwt5 \
		boost_python:${PORTSDIR}/devel/boost-python-libs \
		gsl:${PORTSDIR}/math/gsl
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_SITELIBDIR}/ephem/__init__.py:${PORTSDIR}/astro/pyephem\
		${PYTHON_SITELIBDIR}/PyQt4/Qt.py:${PORTSDIR}/devel/py-qt4

USE_CMAKE=	yes
CMAKE_VERBOSE=	yes
CMAKE_OUTSOURCE=	yes
DOCSDIR=	share/doc/${PORTNAME}-${PORTVERSION}
#CMAKE_ARGS=	--debug-output --trace
CMAKE_ARGS=+	--debug-output
USE_PYTHON=	2.7+
USE_WX=		2.6+
USE_QT4=	gui xml qmake moc rcc uic
WX_COMPS=	wx wx:build wx:run python:build python:run
USE_PERL5=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
.endif

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		USRP TESTING
OPTIONS_DEFAULT=	USRP
USRP_DESC=	Include USRP support (UHD) from Ettus
TESTING_DESC=	Include testing support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
		${LOCALBASE}/bin/sphinx-apidoc:${PORTSDIR}/textproc/py-sphinx \
		dot:${PORTSDIR}/graphics/graphviz \
		xmlto:${PORTSDIR}/textproc/xmlto \
		${LOCALBASE}/lib/X11/fonts/freefont-ttf/fonts.scale:${PORTSDIR}/x11-fonts/freefont-ttf \
		latex:${PORTSDIR}/print/teTeX
CMAKE_ARGS+=	-DENABLE_DOXYGEN:STRING="ON"
HAVE_PORTDOCS=	YES
.else
CMAKE_ARGS+=	-DENABLE_DOXYGEN:STRING="OFF"
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
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/docs/doxygen/Doxyfile.in

pre-install:
	${MKDIR}		${PREFIX}/include/gruel
	${INSTALL_DATA}		${WRKSRC}/gruel/src/include/gruel/*.h \
		${PREFIX}/include/gruel

post-install:
.if	defined(HAVE_PORTDOCS)
	@${ECHO} gnuradio docs are in ${DOCSDIR}
.endif
	@${ECHO} conf files are in ${PREFIX}/etc/gnuradio/conf.d
	@${ECHO}

.include <bsd.port.post.mk>
