# -*-mode: makefile-*-
# New ports collection makefile for:	qt40
# Date created:				Wed Jun 29 11:49:42 CEST 2005
# Whom:					lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	svg
PORTVERSION=	4.2.3
PORTREVISION=	0
CATEGORIES?=	graphics
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt SVG library

BUILD_DEPENDS=	moc4:${PORTSDIR}/devel/qt4-moc \
		qmake-qt4:${PORTSDIR}/devel/qmake4
LIB_DEPENDS?=	QtCore:${PORTSDIR}/devel/qt4-corelib \
		QtGui:${PORTSDIR}/x11-toolkits/qt4-gui \
		QtXml:${PORTSDIR}/textproc/qt4-xml

CONFLICTS=	linguist-0.* qt-2.* qt-3.0.* \
		qt-3.1.* qt-3.2.* qt-designer-2.* xfmail-1.5.[0-5] \
		xfmail-1.5.5_[1-2]

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	-fast -no-exceptions \
		-platform ${LOCALBASE}/share/qt4/mkspecs/freebsd-g++ \
		-qt-gif -release -system-libjpeg -system-libpng \
		-system-zlib -no-nas-sound -prefix ${PREFIX}  \
		-plugindir ${PREFIX}/lib/plugins -bindir ${PREFIX}/bin \
		-confirm-license

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH
EXTRACT_AFTER_ARGS=| ${TAR} -xf - \
	--exclude '${DISTNAME}/mkspecs' --exclude '${DISTNAME}/qmake' \
	--exclude '${DISTNAME}/demos' --exclude '${DISTNAME}/examples' \
	--exclude '${DISTNAME}/src/network' \
	--exclude '${DISTNAME}/src/opengl' --exclude '${DISTNAME}/src/qt3support' \
	--exclude '${DISTNAME}/src/sql'  \
	--exclude '${DISTNAME}/src/plugins' --exclude '${DISTNAME}/src/tools/rcc' \
	--exclude '${DISTNAME}/src/3rdparty' --exclude '${DISTNAME}/src/tools/moc' \
	--exclude '${DISTNAME}/src/tools/uic' --exclude '${DISTNAME}/src/tools/uic3' \
	--exclude '${DISTNAME}/tools/assistant' --exclude '${DISTNAME}/tools/designer' \
	--exclude '${DISTNAME}/tools/linguist' --exclude '${DISTNAME}/tools/porting' \
	--exclude '${DISTNAME}/tools/qtconfig' --exclude '${DISTNAME}/tools/qvfb'
WRKSRC=		${WRKDIR}/${DISTNAME}/src/${PORTNAME}
CONFIGURE_WRKSRC=${WRKSRC}/../../

.include <bsd.port.pre.mk>

.if defined(PKGNAMESUFFIX) && (${PKGNAMESUFFIX} == "-debug" || ${PKGNAMESUFFIX} == "-static-debug")
CONFIGURE_ARGS+=-debug
.endif
.if defined(PKGNAMESUFFIX) && (${PKGNAMESUFFIX} == "-static" || ${PKGNAMESUFFIX} == "-static-debug")
CONFIGURE_ARGS+=-static
.endif

pre-configure:
	${CP} ${.CURDIR}/../../devel/qt4/files/configure ${CONFIGURE_WRKSRC}
	${REINPLACE_CMD} -e 's|target.path.*|target.path=${PREFIX}/lib|g' \
		-e 's|flat_headers.path.*|flat_headers.path=${PREFIX}/include/Qt|g' \
		-e 's|targ_headers.path.*|targ_headers.path=${PREFIX}/include/$$$$TARGET|g' \
		${WRKSRC}/${PORTNAME}.pro ${WRKSRC}/../qt_install.pri
	${MKDIR} ${WRKSRC}/../../mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/../../bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc4 ${WRKSRC}/../../bin/moc

post-configure:
	${REINPLACE_CMD} -e 's|${PREFIX}/lib/QtSvg.pc|${PREFIX}/libdata/pkgconfig/QtSvg.pc|g' \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>
