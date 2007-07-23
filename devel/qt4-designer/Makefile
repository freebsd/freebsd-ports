### -*-mode: makefile-*-
# New ports collection makefile for:	qt40
# Date created:				Wed Jun 29 11:49:42 CEST 2005
# Whom:					lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	designer
PORTVERSION=	${QT4_VERSION}
PORTREVISION=0
CATEGORIES?=	devel
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt ui editor

USE_QT_VER=	4
QT_COMPONENTS=	qmake moc rcc uic assistantclient qt3support corelib gui network\
		script sql xml
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
	--exclude '${DISTNAME}/src/tools/uic3' \
	--exclude '${DISTNAME}/tools/linguist' --exclude '${DISTNAME}/tools/porting' \
	--exclude '${DISTNAME}/tools/qtconfig' --exclude '${DISTNAME}/tools/qvfb'
WRKSRC=		${WRKDIR}/${DISTNAME}/tools/${PORTNAME}
CONFIGURE_WRKSRC=${WRKSRC}/../../

.include <bsd.port.pre.mk>

pre-configure:
	${CP} ${.CURDIR}/../../devel/qt4/files/configure ${CONFIGURE_WRKSRC}
	${REINPLACE_CMD} -e 's|target.path.*|target.path=${PREFIX}/bin|g' \
			-e 's|^TARGET.*|TARGET=designer-qt4|g' \
		${WRKSRC}/src/designer/${PORTNAME}.pro
	${REINPLACE_CMD} -e 's|target.path.*|target.path=${PREFIX}/lib/plugins|g' \
		${WRKSRC}/src/plugins/plugins.pri
	${REINPLACE_CMD} -e \
	's|designer_headers.path.*|designer_headers.path=${PREFIX}/include/QtDesigner|g' \
	-e 's|target.path.*|target.path=${PREFIX}/lib|g' \
		${WRKSRC}/src/lib/lib.pro ${WRKSRC}/src/components/lib/lib.pro
	${MKDIR} ${WRKSRC}/../../mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/../../bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/../../bin/moc
	${LN} -sf ${LOCALBASE}/bin/uic-qt4 ${WRKSRC}/../../bin/uic
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/../../bin/rcc

post-configure:
.if ${OSVERSION} < 700042 && ${ARCH} == "amd64"
	${REINPLACE_CMD} -E -e 's|CXXFLAGS[[:space:]]*=(.*)|CXXFLAGS=-fno-gcse\1|g' \
		${WRKSRC}/../../src/gui/Makefile
.endif
	${REINPLACE_CMD} -e 's|${PREFIX}/lib/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
			-e 's|.*$$(QMAKE).*||g' ${WRKSRC}/src/uitools/Makefile
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/bin/moc-qt4|g' \
			-E -e 's|(.*location=).*uic|\1${PREFIX}/bin/uic-qt4|g' \
		${WRKSRC}/../../lib/pkgconfig/*Qt*

.include <bsd.port.post.mk>
