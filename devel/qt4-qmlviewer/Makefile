# Created by: gahr
# $FreeBSD$

PORTNAME=	qmlviewer
DISTVERSION=	${QT4_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 4 utility for QML application testing

USE_QT4=	qmake_build moc_build rcc_build uic_build declarative script \
		svg xmlpatterns sql opengl network corelib
QT_DIST=	yes

HAS_CONFIGURE=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH

# qtlogo.png is installed by qt4-gui
DESKTOP_ENTRIES="Qt 4 QML viewer" "" \
		"${PREFIX}/share/pixmaps/qtlogo.png" \
		"${PREFIX}/${QT_BINDIR_REL}/qmlviewer" \
		"Development;Qt;" true

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake translations \
		src/activeqt src/multimedia src/openvg \
		src/phonon src/qt3support src/s60installs src/s60main \
		src/scripttools src/sql src/svg src/testlib \
		src/winmain src/xmlpatterns src/3rdparty/clucene \
		src/3rdparty/freetype src/3rdparty/libjpeg src/3rdparty/libmng \
		src/3rdparty/libpng src/3rdparty/libtiff src/3rdparty/phonon \
		src/3rdparty/webkit
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/tools/qml/
INSTALL_WRKSRC=	${BUILD_WRKSRC}

post-patch:
	${MKDIR} ${WRKSRC}/mkspecs
	${LN} -sf ${QMAKE} ${WRKSRC}/bin/qmake
	${LN} -sf ${MOC} ${WRKSRC}/bin/moc
	${LN} -sf ${RCC} ${WRKSRC}/bin/rcc
	${LN} -sf ${UIC} ${WRKSRC}/bin/uic

.include <bsd.port.mk>
