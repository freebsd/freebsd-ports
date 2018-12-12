# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	assistant
DISTVERSION=	${QT4_VERSION}
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 4 documentation browser

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		compiler:c++11-lang qmake:no_env qt-dist:4
USE_QT=		moc_build rcc_build uic_build \
		corelib gui help network sql webkit xml \
		doc_run sql-sqlite3_run

HAS_CONFIGURE=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH

DESKTOP_ENTRIES="Qt 4 Assistant" "" \
		"${PREFIX}/share/pixmaps/assistant-qt4.png" \
		"${PREFIX}/${QT_BINDIR_REL}/assistant${_QT_BINSUFX}" \
		"Development;Qt;" true

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake translations \
		src/activeqt src/dbus src/multimedia src/opengl src/openvg \
		src/phonon src/qt3support src/s60installs src/s60main \
		src/script src/scripttools src/svg src/testlib src/tools \
		src/winmain src/xmlpatterns src/3rdparty/clucene \
		src/3rdparty/freetype src/3rdparty/libjpeg src/3rdparty/libmng \
		src/3rdparty/libpng src/3rdparty/libtiff src/3rdparty/phonon
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/tools/${PORTNAME}/tools/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

pre-configure:
	${REINPLACE_CMD} \
		-e 's|^TARGET.*|TARGET=assistant${_QT_BINSUFX}|g' \
		${BUILD_WRKSRC}/${PORTNAME}.pro
	${MKDIR} ${WRKSRC}/mkspecs/modules
	${LN} -sf ${QMAKE} ${WRKSRC}/bin/qmake
	${LN} -sf ${MOC} ${WRKSRC}/bin/moc
	${LN} -sf ${UIC} ${WRKSRC}/bin/uic
	${LN} -sf ${RCC} ${WRKSRC}/bin/rcc

post-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/images/assistant-128.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/assistant-qt4.png

.include <bsd.port.mk>
