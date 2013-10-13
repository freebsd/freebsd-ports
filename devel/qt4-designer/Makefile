# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	designer
DISTVERSION=	${QT4_VERSION}
CATEGORIES?=	devel
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt ui editor

USE_QT4=	qmake_build moc_build rcc_build uic_build assistant_run \
		qt3support corelib declarative gui network script sql xml \
		webkit phonon
QT_NONSTANDARD=	yes
QT_DIST=	yes

HAS_CONFIGURE=	yes
#Try to fix linking when previous version is installed
CONFIGURE_ARGS+=	-L${WRKSRC}/lib
USE_LDCONFIG=	${PREFIX}/lib/qt4

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH

DESKTOP_ENTRIES="Qt Designer" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/designer-qt4.png" \
		"${PREFIX}/bin/designer-qt4" "Development;Qt;" true

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

EXTRA_PATCHES+=	${.CURDIR}/../../devel/qt4/files/patch-configure

pre-configure:
	${REINPLACE_CMD} -e 's|^TARGET.*|TARGET=designer-qt4|g' \
		${BUILD_WRKSRC}/src/${PORTNAME}/${PORTNAME}.pro
# fix build when previous version is installed
	${REINPLACE_CMD} -e '/^CONFIG/s|depend_prl||' \
		${BUILD_WRKSRC}/src/components/lib/lib.pro
	${MKDIR} ${WRKSRC}/mkspecs/modules
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/bin/moc
	${LN} -sf ${LOCALBASE}/bin/uic-qt4 ${WRKSRC}/bin/uic
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/bin/rcc

pre-install:
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/bin/moc-qt4|g' \
			-E -e 's|(.*location=).*uic|\1${PREFIX}/bin/uic-qt4|g' \
		${WRKSRC}/lib/pkgconfig/QtUiTools.pc \
		${WRKSRC}/lib/pkgconfig/QtDesigner.pc \
		${WRKSRC}/lib/pkgconfig/QtDesignerComponents.pc
	${REINPLACE_CMD} -e 's|${PREFIX}/lib/qt4/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${BUILD_WRKSRC}/src/lib/Makefile \
		${BUILD_WRKSRC}/src/uitools/Makefile \
		${BUILD_WRKSRC}/src/components/lib/Makefile

post-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/src/designer/images/designer.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/designer-qt4.png

.include <bsd.port.mk>
