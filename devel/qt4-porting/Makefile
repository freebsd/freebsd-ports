# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	porting
DISTVERSION=	${QT4_VERSION}
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt utility to assist with porting from Qt 3 to Qt 4

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake:no_env qt-dist:4
USE_QT=		moc_build rcc_build corelib xml

HAS_CONFIGURE=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake translations \
		src/activeqt src/dbus src/gui src/multimedia src/network \
		src/opengl src/openvg src/phonon src/qt3support \
		src/s60installs src/s60main src/script src/scripttools src/sql \
		src/svg src/testlib src/tools src/winmain src/xmlpatterns \
		src/3rdparty/clucene src/3rdparty/freetype \
		src/3rdparty/libjpeg src/3rdparty/libmng src/3rdparty/libpng \
		src/3rdparty/libtiff src/3rdparty/phonon src/3rdparty/webkit
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/tools/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

pre-configure:
	${MKDIR} ${WRKSRC}/mkspecs
	${LN} -sf ${QMAKE} ${WRKSRC}/bin/qmake
	${LN} -sf ${MOC} ${WRKSRC}/bin/moc
	${LN} -sf ${RCC} ${WRKSRC}/bin/rcc

.include <bsd.port.mk>
