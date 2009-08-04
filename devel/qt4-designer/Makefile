### -*-mode: makefile-*-
# New ports collection makefile for:	qt40
# Date created:				Wed Jun 29 11:49:42 CEST 2005
# Whom:					lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	designer
PORTVERSION=	${QT4_VERSION}
PORTREVISION=	0
CATEGORIES?=	devel
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt ui editor

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build assistant_run \
		qt3support corelib gui network script sql xml webkit
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
		src/dbus src/opengl \
		src/sql src/svg src/testlib \
		src/xmlpatterns src/3rdparty/clucene \
		src/3rdparty/kdebase src/3rdparty/kdelibs
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

WRKSRC=		${WRKDIR}/${DISTNAME}/tools/${PORTNAME}
CONFIGURE_WRKSRC=${WRKSRC}/../../
PATCH_WRKSRC=${CONFIGURE_WRKSRC}

pre-configure:
	${CP} ${.CURDIR}/../../devel/qt4/files/configure ${CONFIGURE_WRKSRC}
	${REINPLACE_CMD} -e 's|^TARGET.*|TARGET=designer-qt4|g' \
		${WRKSRC}/src/designer/${PORTNAME}.pro
# fix build when previous version is installed
	${REINPLACE_CMD} -e '/^CONFIG/s|depend_prl||' \
		${WRKSRC}/src/components/lib/lib.pro
	${MKDIR} ${WRKSRC}/../../mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/../../bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/../../bin/moc
	${LN} -sf ${LOCALBASE}/bin/uic-qt4 ${WRKSRC}/../../bin/uic
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/../../bin/rcc

pre-install:
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/bin/moc-qt4|g' \
			-E -e 's|(.*location=).*uic|\1${PREFIX}/bin/uic-qt4|g' \
		${WRKSRC}/../../lib/pkgconfig/QtUiTools.pc \
		${WRKSRC}/../../lib/pkgconfig/QtDesigner.pc \
		${WRKSRC}/../../lib/pkgconfig/QtDesignerComponents.pc
	${REINPLACE_CMD} -e 's|${PREFIX}/lib/qt4/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/src/lib/Makefile \
		${WRKSRC}/src/uitools/Makefile \
		${WRKSRC}/src/components/lib/Makefile

.include <bsd.port.mk>
