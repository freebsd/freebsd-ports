### -*-mode: makefile-*-
# New ports collection makefile for:	qt40
# Date created:				Wed Jun 29 11:49:42 CEST 2005
# Whom:					lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	dbus
PORTVERSION=	${QT4_VERSION}
PORTREVISION=	0
CATEGORIES?=	devel
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 bindings for the D-BUS messaging system

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build corelib gui xml
QT_NONSTANDARD=	yes
QT_DIST=	yes
MAKE_JOBS_UNSAFE=	yes
HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/qt4

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake translations \
		src/network src/opengl src/phonon \
		src/qt3support src/script src/sql src/svg src/testlib \
		src/tools src/xmlpatterns src/3rdparty/clucene \
		src/3rdparty/kdebase src/3rdparty/kdelibs src/3rdparty/webkit
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

WRKSRC=		${WRKDIR}/${DISTNAME}/tools/qdbus
CONFIGURE_WRKSRC=${WRKSRC}/../../

pre-configure:
	${CP} ${.CURDIR}/../../devel/qt4/files/configure ${CONFIGURE_WRKSRC}
	${REINPLACE_CMD} -e 's|qdbusviewer||g' ${WRKSRC}/qdbus.pro
	${REINPLACE_CMD} -e 's|SUBDIRS = qdbus|SUBDIRS = ../../src/dbus qdbus|g' ${WRKSRC}/qdbus.pro
	${REINPLACE_CMD} -e 's|"/moc"|"/moc-qt4"|' \
		${WRKSRC}/../qdbus/qdbuscpp2xml/qdbuscpp2xml.cpp
	${MKDIR} ${WRKSRC}/../../mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/../../bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/../../bin/moc
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/../../bin/rcc

post-configure:
	${REINPLACE_CMD} -e 's|${PREFIX}/lib/qt4/pkgconfig|${PREFIX}/libdata/pkgconfig|g' ${WRKSRC}/../../src/dbus/Makefile
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/bin/moc-qt4|g' \
		${WRKSRC}/../../lib/pkgconfig/QtDBus.pc

.include <bsd.port.mk>
