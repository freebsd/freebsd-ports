# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	corelib
DISTVERSION=	${QT4_VERSION}
PORTREVISION=	6
CATEGORIES=	devel
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt core non-graphical module

LIB_DEPENDS=	libicui18n.so:devel/icu

USE_GNOME=	glib20
USE_QT4=	qmake_build moc_build
QT_DIST=	yes
USES=		iconv pkgconfig

HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake tools translations \
		src/activeqt src/dbus src/gui src/multimedia src/network \
		src/opengl src/openvg src/phonon src/qt3support \
		src/s60installs src/s60main src/script src/scripttools src/sql \
		src/svg src/testlib src/tools src/winmain src/xml \
		src/xmlpatterns src/3rdparty/clucene src/3rdparty/freetype \
		src/3rdparty/libjpeg src/3rdparty/libmng src/3rdparty/libpng \
		src/3rdparty/libtiff src/3rdparty/phonon src/3rdparty/webkit
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include "${.CURDIR:H:H}/devel/qt4/files/Makefile.options"

.if empty(QT4_OPTIONS:MCUPS)
CONFIGURE_ARGS+=	-no-cups
.endif

.if empty(QT4_OPTIONS:MNAS)
CONFIGURE_ARGS+=	-no-nas-sound
.endif

.if empty(QT4_OPTIONS:MQGTKSTYLE)
CONFIGURE_ARGS+=	-no-gtkstyle
.endif

pre-everything::
	@${CAT} ${PKGMESSAGE}

post-patch:
	${REINPLACE_CMD} -e '${QT4_OPTIONS_REPLACE}' ${WRKSRC}/configure

pre-configure:
	${MKDIR} ${WRKSRC}/mkspecs
	${LN} -sf ${QMAKE} ${WRKSRC}/bin/qmake
	${LN} -sf ${MOC} ${WRKSRC}/bin/moc

post-configure:
	${REINPLACE_CMD} -e 's|${PREFIX}/${QT_LIBDIR_REL}/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		-e 's|.*$$(QMAKE).*||g' \
		${BUILD_WRKSRC}/Makefile
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
		-E -e 's|(.*location=).*moc|\1${PREFIX}/${QT_BINDIR_REL}/${MOC:T}|g' \
		-E -e 's|(.*location=).*uic|\1${PREFIX}/${QT_BINDIR_REL}/${UIC:T}|g' \
		${WRKSRC}/lib/pkgconfig/QtCore.pc

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${QT_PLUGINDIR_REL}
	${TOUCH} ${STAGEDIR}${PREFIX}/${QT_PLUGINDIR_REL}/.keep_me
	${MKDIR} ${STAGEDIR}${PREFIX}/${QT_MKSPECDIR_REL}
	${INSTALL_DATA} ${WRKSRC}/mkspecs/qconfig.pri ${STAGEDIR}${PREFIX}/${QT_MKSPECDIR_REL}/

.include <bsd.port.mk>
