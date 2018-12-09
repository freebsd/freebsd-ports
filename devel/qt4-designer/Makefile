# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	designer
DISTVERSION=	${QT4_VERSION}
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 4 graphical user interface designer

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		compiler:c++11-lang qmake:no_env qt-dist:4
USE_QT=		moc_build rcc_build uic_build assistant_run \
		qt3support corelib declarative gui network script sql xml \
		webkit

HAS_CONFIGURE=	yes
# Try to fix linking when previous version is installed
CONFIGURE_ARGS=	-L${WRKSRC}/lib -no-phonon
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH

DESKTOP_ENTRIES="Qt 4 Designer" "" \
		"${PREFIX}/share/pixmaps/designer-qt4.png" \
		"${PREFIX}/${QT_BINDIR_REL}/designer${_QT_BINSUFX}" \
		"Development;Qt;" true

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake translations \
		src/activeqt src/dbus src/multimedia src/opengl src/openvg \
		src/s60installs src/s60main src/scripttools src/sql src/svg \
		src/testlib src/winmain src/xmlpatterns src/3rdparty/clucene \
		src/3rdparty/freetype src/3rdparty/libjpeg src/3rdparty/libmng \
		src/3rdparty/libpng src/3rdparty/libtiff
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/tools/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

pre-configure:
	${REINPLACE_CMD} -e 's|^TARGET.*|TARGET=designer${_QT_BINSUFX}|g' \
		${BUILD_WRKSRC}/src/${PORTNAME}/${PORTNAME}.pro
	${REINPLACE_CMD} -e '/QLatin1String/ s|("assistant")|("assistant${_QT_BINSUFX}")|' \
		${BUILD_WRKSRC}/src/${PORTNAME}/assistantclient.cpp
# fix build when previous version is installed
	${REINPLACE_CMD} -e '/^CONFIG/s|depend_prl||' \
		${BUILD_WRKSRC}/src/components/lib/lib.pro
	${MKDIR} ${WRKSRC}/mkspecs/modules
	${LN} -sf ${QMAKE} ${WRKSRC}/bin/qmake
	${LN} -sf ${MOC} ${WRKSRC}/bin/moc
	${LN} -sf ${UIC} ${WRKSRC}/bin/uic
	${LN} -sf ${RCC} ${WRKSRC}/bin/rcc

pre-install:
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-everywhere-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/${QT_BINDIR_REL}/${MOC:T}|g' \
			-E -e 's|(.*location=).*uic|\1${PREFIX}/${QT_BINDIR_REL}/${UIC:T}|g' \
		${WRKSRC}/lib/pkgconfig/QtUiTools.pc \
		${WRKSRC}/lib/pkgconfig/QtDesigner.pc \
		${WRKSRC}/lib/pkgconfig/QtDesignerComponents.pc
	${REINPLACE_CMD} -e 's|${PREFIX}/${QT_LIBDIR_REL}/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${BUILD_WRKSRC}/src/lib/Makefile \
		${BUILD_WRKSRC}/src/uitools/Makefile \
		${BUILD_WRKSRC}/src/components/lib/Makefile

post-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/src/designer/images/designer.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/designer-qt4.png

.include <bsd.port.mk>
