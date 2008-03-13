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

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH
EXTRACT_AFTER_ARGS=| ${TAR} -xf - \
	--exclude '${DISTNAME}/mkspecs' --exclude '${DISTNAME}/qmake' \
	--exclude '${DISTNAME}/demos' --exclude '${DISTNAME}/examples' \
	--exclude '${DISTNAME}/src/opengl' --exclude '${DISTNAME}/src/sql' \
	--exclude '${DISTNAME}/src/tools/moc' --exclude '${DISTNAME}/src/tools/rcc' \
	--exclude '${DISTNAME}/src/tools/uic3' --exclude '${DISTNAME}/tools/designer' \
	--exclude '${DISTNAME}/tools/linguist' --exclude '${DISTNAME}/tools/porting' \
	--exclude '${DISTNAME}/tools/qtconfig' --exclude '${DISTNAME}/tools/qvfb'
WRKSRC=		${WRKDIR}/${DISTNAME}/tools/qdbus
CONFIGURE_WRKSRC=${WRKSRC}/../../

pre-configure:
	${CP} ${.CURDIR}/../../devel/qt4/files/configure ${CONFIGURE_WRKSRC}
	${REINPLACE_CMD} -e 's|qdbusviewer||g' ${WRKSRC}/tools/tools.pro
	${REINPLACE_CMD} -e 's|target.path.*|target.path=${PREFIX}/bin|g' \
		${WRKSRC}/tools/qdbus/qdbus.pro \
		${WRKSRC}/tools/qdbuscpp2xml/qdbuscpp2xml.pro \
		${WRKSRC}/tools/qdbusxml2cpp/qdbusxml2cpp.pro
	${REINPLACE_CMD} -e 's|"/moc"|"/moc-qt4"|' \
		${WRKSRC}/tools/qdbuscpp2xml/qdbuscpp2xml.cpp
	${REINPLACE_CMD} -e 's|target.path.*|target.path=${PREFIX}/lib|g' \
		-e 's|targ_headers.path.*|targ_headers.path=${PREFIX}/include/$$$$TARGET|g' \
		${WRKSRC}/src/src.pro
	${MKDIR} ${WRKSRC}/../../mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/../../bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/../../bin/moc
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/../../bin/rcc

post-configure:
	${REINPLACE_CMD} -e 's|${PREFIX}/lib/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
			-e 's|.*$$(QMAKE).*||g' ${WRKSRC}/src/Makefile
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/bin/moc-qt4|g' \
			-E -e 's|(.*location=).*uic|\1${PREFIX}/bin/uic-qt4|g' \
			-E -e 's|(.*Cflags:.*)-I${LOCALBASE}/include |\1|g' \
		${WRKSRC}/../../lib/pkgconfig/*Qt*

.include <bsd.port.mk>
