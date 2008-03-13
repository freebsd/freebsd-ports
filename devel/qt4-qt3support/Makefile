# -*-mode: makefile-*-
# New ports collection makefile for:	qt40
# Date created:				Wed Jun 29 11:49:42 CEST 2005
# Whom:					lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	qt3support
PORTVERSION=	${QT4_VERSION}
PORTREVISION=	0
CATEGORIES?=	devel x11-toolkits
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt3 compatibility library

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build corelib gui network sql xml
QT_NONSTANDARD=	yes
QT_DIST=	yes

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_XLIB=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH
EXTRACT_AFTER_ARGS=| ${TAR} -xf - \
	--exclude '${DISTNAME}/mkspecs' --exclude '${DISTNAME}/qmake' \
	--exclude '${DISTNAME}/demos' --exclude '${DISTNAME}/examples' \
	--exclude '${DISTNAME}/src/plugins' \
	--exclude '${DISTNAME}/src/3rdparty' --exclude '${DISTNAME}/src/tools/moc' \
	--exclude '${DISTNAME}/src/tools/rcc' \
	--exclude '${DISTNAME}/src/tools/uic' --exclude '${DISTNAME}/src/tools/uic3' \
	--exclude '${DISTNAME}/tools/assistant' \
	--exclude '${DISTNAME}/tools/linguist' --exclude '${DISTNAME}/tools/porting' \
	--exclude '${DISTNAME}/tools/qtconfig' --exclude '${DISTNAME}/tools/qvfb'
WRKSRC=		${WRKDIR}/${DISTNAME}/src/${PORTNAME}
CONFIGURE_WRKSRC=${WRKSRC}/../../
PATCH_WRKSRC=${CONFIGURE_WRKSRC}

pre-configure:
	${CP} ${.CURDIR}/../../devel/qt4/files/configure ${CONFIGURE_WRKSRC}	
	${REINPLACE_CMD} -e 's|target.path.*|target.path=${PREFIX}/lib|g' \
		-e 's|flat_headers.path.*|flat_headers.path=${PREFIX}/include/Qt|g' \
		-e 's|targ_headers.path.*|targ_headers.path=${PREFIX}/include/$$$$TARGET|g' \
		${WRKSRC}/${PORTNAME}.pro ${WRKSRC}/../qt_install.pri
	${MKDIR} ${WRKSRC}/../../mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/../../bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/../../bin/moc
post-configure:
	${REINPLACE_CMD} -e 's|${PREFIX}/lib/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		-e 's|.*$$(QMAKE).*||g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/bin/moc-qt4|g' \
			-E -e 's|(.*location=).*uic|\1${PREFIX}/bin/uic-qt4|g' \
			-E -e 's|(.*Cflags:.*)-I${LOCALBASE}/include |\1|g' \
		${WRKSRC}/../../lib/pkgconfig/*Qt*

.include <bsd.port.mk>
