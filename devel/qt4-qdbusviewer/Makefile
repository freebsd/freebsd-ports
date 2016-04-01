# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	qdbusviewer
DISTVERSION=	${QT4_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 4 graphical interface to D-Bus

LIB_DEPENDS=	libdbus-1.so:devel/dbus

USES=		pkgconfig
USE_QT4=	qmake_build moc_build rcc_build corelib dbus gui xml \
		clucene
QT_DIST=	yes

HAS_CONFIGURE=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH

DESKTOP_ENTRIES="Qt 4 D-Bus viewer" "" \
		"${PREFIX}/share/pixmaps/qdbusviewer-qt4.png" \
		"${PREFIX}/${QT_BINDIR_REL}/qdbusviewer" \
		"Development;Qt;" true

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake translations \
		src/activeqt src/multimedia src/network src/opengl src/openvg \
		src/phonon src/qt3support src/s60installs src/s60main \
		src/script src/scripttools src/sql src/svg src/testlib \
		src/tools src/winmain src/xmlpatterns src/3rdparty/clucene \
		src/3rdparty/freetype src/3rdparty/libjpeg src/3rdparty/libmng \
		src/3rdparty/libpng src/3rdparty/libtiff src/3rdparty/phonon \
		src/3rdparty/webkit
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/tools/qdbus/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

post-patch:
	${MKDIR} ${WRKSRC}/mkspecs
	${LN} -sf ${QMAKE} ${WRKSRC}/bin/qmake
	${LN} -sf ${MOC} ${WRKSRC}/bin/moc
	${LN} -sf ${RCC} ${WRKSRC}/bin/rcc

post-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/images/qdbusviewer-128.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/qdbusviewer-qt4.png

.include <bsd.port.mk>
