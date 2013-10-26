# $FreeBSD$

PORTNAME=	gnuradio
PORTVERSION=	3.6.5
PORTREVISION=	2
CATEGORIES=	comms astro hamradio
MASTER_SITES=	http://gnuradio.org/releases/gnuradio/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio Software defined radio

BUILD_DEPENDS=	sdl-config:${PORTSDIR}/devel/sdl12 \
		swig:${PORTSDIR}/devel/swig13 \
		cheetah:${PORTSDIR}/devel/py-cheetah \
		py*-lxml>=0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_SITELIBDIR}/pygtk.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/PyQt4/Qt.py:${PORTSDIR}/devel/py-qt4 \
		xdg-open:${PORTSDIR}/devel/xdg-utils \
		guile:${PORTSDIR}/lang/guile \
		git:${PORTSDIR}/devel/git
LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3 \
		fftw3f:${PORTSDIR}/math/fftw3-float \
		qwt:${PORTSDIR}/x11-toolkits/qwt5 \
		boost_python:${PORTSDIR}/devel/boost-python-libs \
		portaudio.2:${PORTSDIR}/audio/portaudio2 \
		jack:${PORTSDIR}/audio/jack \
		asound:${PORTSDIR}/audio/alsa-lib \
		gsl:${PORTSDIR}/math/gsl
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_SITELIBDIR}/ephem/__init__.py:${PORTSDIR}/astro/pyephem\
		${PYTHON_SITELIBDIR}/PyQt4/Qt.py:${PORTSDIR}/devel/py-qt4

USES=		cmake:outsource perl5
CMAKE_VERBOSE=	yes
DOCSDIR=	share/doc/${PORTNAME}-${PORTVERSION}
USE_PYTHON=	2.7+
USE_WX=		2.6+
USE_QT4=	gui xml qmake moc rcc uic
WX_COMPS=	wx wx:build wx:run python:build python:run
USE_LDCONFIG=	yes
PLIST_SUB+=	MAJOR_VERSION="3"

OPTIONS_DEFINE=		USRP TESTING
OPTIONS_DEFAULT=	USRP
USRP_DESC=	Include USRP support (UHD) from Ettus
TESTING_DESC=	Include testing support

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
		${LOCALBASE}/bin/sphinx-apidoc:${PORTSDIR}/textproc/py-sphinx \
		dot:${PORTSDIR}/graphics/graphviz \
		xmlto:${PORTSDIR}/textproc/xmlto \
		${LOCALBASE}/lib/X11/fonts/freefont-ttf/fonts.scale:${PORTSDIR}/x11-fonts/freefont-ttf \
		latex:${PORTSDIR}/print/teTeX
CMAKE_ARGS+=	-DENABLE_DOXYGEN:STRING="ON"
CMAKE_ARGS+=	-DENABLE_BAD_BOOST="ON"
CMAKE_ARGS+=	-DENABLE_DOCS:STRING="ON"
HAVE_PORTDOCS=	YES
.else
CMAKE_ARGS+=	-DENABLE_DOXYGEN:STRING="OFF"
CMAKE_ARGS+=	-DENABLE_DOCS:STRING="OFF"
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
	${FIND} ${WRKSRC}/.. -name CMakeLists.txt | \
	    ${XARGS} ${REINPLACE_CMD} -e \
		 "s|{GR_LIBRARY_DIR}/pkgconfig|{GR_PKGCONFIG_DIR}/pkgconfig|g"

	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/docs/doxygen/Doxyfile.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/FindPortaudio.cmake

PLISTMAIN=	pkg-plist.main
PLISTDIRS=	pkg-plist.dirs
PLIST=	${WRKDIR}/.pkg-plist

pre-install:
	@${RM} -f ${PLIST}
	@${CAT} ${PLISTMAIN} > ${PLIST}
	@cd ${WRKDIR}/.build/docs/doxygen && ${FIND} html -type f  | \
	    ${SED} -e 's|html|%%PORTDOCS%%%%DOCSDIR%%/html|' \
		| ${SORT} >> ${PLIST}
	@cd ${WRKDIR}/.build/gr-trellis && ${FIND} doc -name \*.html -type f  | \
	    ${SED} -e 's|doc|%%PORTDOCS%%%%DOCSDIR%%/html|' \
		| ${SORT} >> ${PLIST}
	@cd ${WRKDIR}/.build/docs/doxygen && ${FIND} xml -type f  | \
	    ${SED} -e 's|xml|%%PORTDOCS%%%%DOCSDIR%%/xml|' \
		| ${SORT} >> ${PLIST}
	@cd ${WRKDIR}/.build/gr-trellis && ${FIND} doc -name \*.xml -type f  | \
	    ${SED} -e 's|doc|%%PORTDOCS%%%%DOCSDIR%%/xml|' \
		| ${SORT} >> ${PLIST}
	@${CAT} ${PLISTDIRS} >> ${PLIST}
	@cd ${WRKDIR}/.build/docs/doxygen && ${FIND} html -type d | ${SORT} -r | \
	    ${SED} -e 's|html|%%PORTDOCS%%@dirrm %%DOCSDIR%%/html|' \
		 >> ${PLIST}
	@cd ${WRKDIR}/.build/docs/doxygen && ${FIND} xml -type d | ${SORT} -r | \
	    ${SED} -e 's|xml|%%PORTDOCS%%@dirrm %%DOCSDIR%%/xml|' \
		 >> ${PLIST}
	@${ECHO_CMD} "%%PORTDOCS%%@dirrm %%DOCSDIR%%" >> ${PLIST}

post-install:
.if	defined(HAVE_PORTDOCS)
	@${ECHO} gnuradio docs are in ${DOCSDIR}
.endif
	@${ECHO} sample conf files are in ${PREFIX}/etc/gnuradio/conf.d
	@${ECHO}

.include <bsd.port.post.mk>
