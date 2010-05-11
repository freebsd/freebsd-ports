# New ports collection makefile for:	qt4-help
# Date created:				Sun May 11 14:43:54 CEST 2008
# Whom:					danny@ricin.com
#
# $FreeBSD$
#

PORTNAME=	help
PORTVERSION=	${QT4_VERSION}
CATEGORIES?=	devel
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QtHelp module provides QHelpEngine API and is used by Assistant

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build corelib clucene \
		gui sql sql-sqlite3_run xml network
QT_NONSTANDARD=	yes
QT_DIST=	yes
MAKE_JOBS_SAFE=	yes

HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/qt4

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake translations \
		src/activeqt src/dbus src/multimedia src/opengl src/openvg \
		src/phonon src/qt3support src/s60installs src/s60main \
		src/script src/scripttools src/svg src/testlib src/tools \
		src/winmain src/xmlpatterns src/3rdparty/clucene \
		src/3rdparty/freetype src/3rdparty/libjpeg src/3rdparty/libmng \
		src/3rdparty/libpng src/3rdparty/libtiff src/3rdparty/phonon \
		src/3rdparty/webkit
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/tools/assistant/lib
INSTALL_WRKSRC=	${BUILD_WRKSRC}

EXTRA_PATCHES=	${.CURDIR}/../../devel/qt4/files/patch-configure

pre-configure:
	${MKDIR} ${WRKSRC}/mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/bin/moc
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/bin/rcc

post-configure:
	${REINPLACE_CMD} \
		-e 's|${PREFIX}/lib/qt4/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		-e 's|.*$$(QMAKE).*||g' \
		${BUILD_WRKSRC}/Makefile
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/bin/moc-qt4|g' \
			-E -e 's|(.*location=).*rcc|\1${PREFIX}/bin/rcc|g' \
		${WRKSRC}/lib/pkgconfig/QtHelp.pc

.include <bsd.port.mk>
