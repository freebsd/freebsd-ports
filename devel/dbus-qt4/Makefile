### -*-mode: makefile-*-
# New ports collection makefile for:	qt40
# Date created:				Wed Jun 29 11:49:42 CEST 2005
# Whom:					lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	dbus
PORTVERSION=	4.2.3
PORTREVISION=	0
CATEGORIES?=	devel
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMESUFFIX=	-qt4
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 bindings for the D-BUS messaging system

BUILD_DEPENDS=	moc4:${PORTSDIR}/devel/qt4-moc \
		qmake-qt4:${PORTSDIR}/devel/qmake4
LIB_DEPENDS=	QtCore:${PORTSDIR}/devel/qt4-corelib \
		QtXml:${PORTSDIR}/textproc/qt4-xml \
		dbus-1.3:${PORTSDIR}/devel/dbus

CONFLICTS=	linguist-0.* qt-2.* qt-3.0.* \
		qt-3.1.* qt-3.2.* qt-designer-2.* xfmail-1.5.[0-5] \
		xfmail-1.5.5_[1-2]

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	-fast -no-exceptions \
		-platform ${LOCALBASE}/share/qt4/mkspecs/freebsd-g++ \
		-qt-gif -release -system-libjpeg -system-libpng \
		-system-zlib -system-nas-sound -prefix ${PREFIX}  \
		-plugindir ${PREFIX}/lib/plugins -bindir ${PREFIX}/bin -v \
		-no-nas-sound -confirm-license

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

.include <bsd.port.pre.mk>

pre-configure:
	${CP} ${.CURDIR}/../../devel/qt4/files/configure ${CONFIGURE_WRKSRC}	
	${REINPLACE_CMD} -e 's|target.path.*|target.path=${PREFIX}/bin|g' \
		${WRKSRC}/tools/qdbus/qdbus.pro \
		${WRKSRC}/tools/qdbuscpp2xml/qdbuscpp2xml.pro \
		${WRKSRC}/tools/qdbusxml2cpp/qdbusxml2cpp.pro
	${REINPLACE_CMD} -e 's|target.path.*|target.path=${PREFIX}/lib|g' \
		-e 's|targ_headers.path.*|targ_headers.path=${PREFIX}/include/$$$$TARGET|g' \
		${WRKSRC}/src/src.pro
	${MKDIR} ${WRKSRC}/../../mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/../../bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc4 ${WRKSRC}/../../bin/moc

post-configure:
	${REINPLACE_CMD} -e 's|${PREFIX}/lib/QtDBus.pc|${PREFIX}/libdata/pkgconfig/QtDBus.pc|g' \
		${WRKSRC}/src/Makefile

.include <bsd.port.post.mk>
