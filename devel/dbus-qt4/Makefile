# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	dbus
DISTVERSION=	${QT4_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt D-Bus inter-process communication module

LIB_DEPENDS=	libdbus-1.so:devel/dbus

BROKEN_sparc64=	fails to compile: invalid conversion

USES=		pkgconfig
USE_QT4=	qmake_build moc_build rcc_build corelib xml
QT_DIST=	yes
MAKE_JOBS_UNSAFE=	yes

HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake translations \
		src/activeqt src/gui src/multimedia src/network src/opengl \
		src/openvg src/phonon src/qt3support src/s60installs \
		src/s60main src/script src/scripttools src/sql src/svg \
		src/testlib src/tools src/winmain src/xmlpatterns \
		src/3rdparty/clucene src/3rdparty/freetype \
		src/3rdparty/libjpeg src/3rdparty/libmng src/3rdparty/libpng \
		src/3rdparty/libtiff src/3rdparty/phonon src/3rdparty/webkit
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/tools/qdbus
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include <bsd.port.pre.mk>

# Without this workaround, qdbus crashes.
.if ${OPSYS} == FreeBSD && ${OSVERSION} > 1000000
CXXFLAGS+=	-fno-use-cxa-atexit
.endif

CONFIGURE_ARGS+=	--no-gui \
			--no-phonon

pre-configure:
	${REINPLACE_CMD} -e 's|SUBDIRS = qdbus|SUBDIRS = ../../src/${PORTNAME} qdbus|g' \
		${BUILD_WRKSRC}/qdbus.pro
	${REINPLACE_CMD} -e 's|"/moc"|"/${MOC:T}"|' \
		${BUILD_WRKSRC}/qdbuscpp2xml/qdbuscpp2xml.cpp
	${MKDIR} ${WRKSRC}/mkspecs
	${LN} -sf ${QMAKE} ${WRKSRC}/bin/qmake
	${LN} -sf ${MOC} ${WRKSRC}/bin/moc
	${LN} -sf ${RCC} ${WRKSRC}/bin/rcc

post-configure:
	${REINPLACE_CMD} -e 's|${PREFIX}/${QT_LIBDIR_REL}/pkgconfig|${PREFIX}/libdata/pkgconfig|g' ${WRKSRC}/src/${PORTNAME}/Makefile
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/${QT_BINDIR_REL}/${MOC:T}|g' \
		${WRKSRC}/lib/pkgconfig/QtDBus.pc

.include <bsd.port.post.mk>
