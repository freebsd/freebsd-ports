# -*-mode: makefile-*-
# New ports collection makefile for:	qt40
# Date created:				Wed Jun 29 11:49:42 CEST 2005
# Whom:					lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	qvfb
PORTVERSION=	4.2.2
PORTREVISION=	1
CATEGORIES?=	x11-toolkits ipv6
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt virtual framebuffer utility

BUILD_DEPENDS=	moc4:${PORTSDIR}/devel/qt4-moc \
		qmake-qt4:${PORTSDIR}/devel/qmake4 \
		rcc:${PORTSDIR}/devel/qt4-rcc \
		uic4:${PORTSDIR}/devel/qt4-uic
LIB_DEPENDS=	QtCore:${PORTSDIR}/devel/qt4-corelib \
		QtGui:${PORTSDIR}/x11-toolkits/qt4-gui \
		QtOpenGL:${PORTSDIR}/x11/qt4-opengl

CONFLICTS=	linguist-0.* qt-2.* qt-3.0.* \
		qt-3.1.* qt-3.2.* qt-designer-2.* xfmail-1.5.[0-5] \
		xfmail-1.5.5_[1-2]

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	-fast -no-exceptions \
		-platform ${LOCALBASE}/share/qt4/mkspecs/freebsd-g++ \
		-qt-gif -release -system-libjpeg -system-libpng \
		-system-zlib -no-nas-sound -prefix ${PREFIX} -no-sm \
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
	--exclude '${DISTNAME}/src/opengl' \
	--exclude '${DISTNAME}/src/sql' --exclude '${DISTNAME}/src/plugins' \
	--exclude '${DISTNAME}/src/3rdparty' --exclude '${DISTNAME}/src/xml' \
	--exclude '${DISTNAME}/src/tools/moc' --exclude '${DISTNAME}/src/tools/rcc' \
	--exclude '${DISTNAME}/src/tools/uic' --exclude '${DISTNAME}/src/tools/uic3' \
	--exclude '${DISTNAME}/tools/assistant' --exclude '${DISTNAME}/tools/designer' \
	--exclude '${DISTNAME}/tools/linguist' --exclude '${DISTNAME}/tools/porting' \
	--exclude '${DISTNAME}/tools/qtconfig' 
WRKSRC=		${WRKDIR}/${DISTNAME}/tools/${PORTNAME}
CONFIGURE_WRKSRC=${WRKSRC}/../../

pre-configure:
	${CP} ${.CURDIR}/../../devel/qt4/files/configure ${CONFIGURE_WRKSRC}
	${MKDIR} ${WRKSRC}/../../mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/../../bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc4 ${WRKSRC}/../../bin/moc
	${LN} -sf ${LOCALBASE}/bin/uic4 ${WRKSRC}/../../bin/uic
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/../../bin/rcc

post-install:
	${MKDIR} ${DATADIR}
	${CP} -Rf ${WRKSRC}/*.skin ${WRKSRC}/pda* ${DATADIR}

.include <bsd.port.mk>
