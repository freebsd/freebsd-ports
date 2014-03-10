# $FreeBSD$

PORTNAME=	gnuradio
PORTVERSION=	3.7.2
PORTREVISION=	1
CATEGORIES=	comms astro hamradio
MASTER_SITES=	http://gnuradio.org/releases/gnuradio/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio Software defined radio

BUILD_DEPENDS=	sdl-config:${PORTSDIR}/devel/sdl12 \
		swig2.0:${PORTSDIR}/devel/swig20 \
		cheetah:${PORTSDIR}/devel/py-cheetah \
		py*-lxml>=0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_SITELIBDIR}/pygtk.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/PyQt4/Qt.py:${PORTSDIR}/devel/py-qt4 \
		xdg-open:${PORTSDIR}/devel/xdg-utils \
		guile:${PORTSDIR}/lang/guile \
		git:${PORTSDIR}/devel/git
LIB_DEPENDS=	libcppunit.so:${PORTSDIR}/devel/cppunit \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libqwt.so:${PORTSDIR}/x11-toolkits/qwt5 \
		libboost_python.so:${PORTSDIR}/devel/boost-python-libs \
		libportaudio.so.2:${PORTSDIR}/audio/portaudio2 \
		libjack.so:${PORTSDIR}/audio/jack \
		libasound.so:${PORTSDIR}/audio/alsa-lib \
		libgsl.so:${PORTSDIR}/math/gsl
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_SITELIBDIR}/ephem/__init__.py:${PORTSDIR}/astro/pyephem\
		${PYTHON_SITELIBDIR}/PyQt4/Qt.py:${PORTSDIR}/devel/py-qt4

USES=		iconv cmake:outsource perl5
CMAKE_ARGS+=	-DSWIG_EXECUTABLE:STRING="${LOCALBASE}/bin/swig2.0"
CMAKE_ARGS+=	-DICONV_PREFIX:STRING="${ICONV_PREFIX}" \
		-DICONV_LIB:STRING="X${ICONV_LIB}"
# for detailed debugging uncomment the next line
#CMAKE_ARGS+=	--debug-output --trace
DOCSDIR=	share/doc/${PORTNAME}-${PORTVERSION}
USE_PYTHON=	2.7+
USE_WX=		2.6+
USE_QT4=	gui xml qmake moc rcc uic
WX_COMPS=	wx wx:build wx:run python:build python:run
USE_LDCONFIG=	yes
PLIST_SUB+=	MAJOR_VERSION="3"

OPTIONS_DEFINE=		USRP TESTING
# Unfortunately building docs on i386 fails
OPTIONS_EXCLUDE_${i386}=	DOCS
# turn this off until usrp port is fixed on -10 and HEAD
#OPTIONS_DEFAULT=	USRP
USRP_DESC=	Include USRP support (UHD) from Ettus
TESTING_DESC=	Include testing support

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
		${LOCALBASE}/bin/sphinx-apidoc:${PORTSDIR}/textproc/py-sphinx \
		dot:${PORTSDIR}/graphics/graphviz \
		xmlto:${PORTSDIR}/textproc/xmlto \
		${LOCALBASE}/lib/X11/fonts/freefont-ttf/fonts.scale:${PORTSDIR}/x11-fonts/freefont-ttf \
		latex:${PORTSDIR}/print/teTeX
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
.if ${PORT_OPTIONS:MDOCS}
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
.endif

.include <bsd.port.post.mk>
