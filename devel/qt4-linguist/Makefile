# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	linguist
DISTVERSION=	${QT4_VERSION}
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 4 localization tools

USE_QT4=	qmake_build designer_build moc_build rcc_build uic_build \
		assistant_run gui linguisttools_run network xml
QT_DIST=	yes

HAS_CONFIGURE=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH

DESKTOP_ENTRIES="Qt 4 Linguist" "" \
		"${PREFIX}/share/pixmaps/linguist-qt4.png" \
		"${PREFIX}/${QT_BINDIR_REL}/linguist${_QT_BINSUFX}" \
		"Development;Qt;" true

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake translations \
		src/activeqt src/dbus src/multimedia src/network src/opengl \
		src/openvg src/phonon src/qt3support src/s60installs \
		src/s60main src/script src/scripttools src/sql src/svg \
		src/testlib src/tools src/winmain src/xmlpatterns \
		src/3rdparty/clucene src/3rdparty/freetype \
		src/3rdparty/libjpeg src/3rdparty/libmng src/3rdparty/libpng \
		src/3rdparty/libtiff src/3rdparty/phonon src/3rdparty/webkit
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/tools/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

pre-configure:
	${REINPLACE_CMD} -E -e 's|^TARGET[[:blank:]]*=[[:blank:]]*([a-z]+)|TARGET=\1${_QT_BINSUFX}|g' \
		${BUILD_WRKSRC}/${PORTNAME}.pro ${BUILD_WRKSRC}/${PORTNAME}/${PORTNAME}.pro \
		${BUILD_WRKSRC}/lrelease/lrelease.pro ${BUILD_WRKSRC}/lupdate/lupdate.pro
	${MKDIR} ${WRKSRC}/mkspecs
	${LN} -sf ${QMAKE} ${WRKSRC}/bin/qmake
	${LN} -sf ${MOC} ${WRKSRC}/bin/moc
	${LN} -sf ${UIC} ${WRKSRC}/bin/uic
	${LN} -sf ${RCC} ${WRKSRC}/bin/rcc

post-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/linguist/images/icons/linguist-128-32.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/linguist-qt4.png

.include <bsd.port.mk>
