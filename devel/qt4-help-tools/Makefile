# New ports collection makefile for:	qt4-help-tools
# Date created:				Sun May 11 23:30:38 CEST 2008
# Whom:					danny@ricin.com
#
# $FreeBSD$
#

PORTNAME=	help
PORTVERSION=	${QT4_VERSION}
CATEGORIES?=	devel
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
PKGNAMESUFFIX=	-tools
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QtHelp tools to generate and convert documentation

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build corelib \
		gui sql xml doc help
QT_NONSTANDARD=	yes
QT_DIST=	yes
MAKE_JOBS_SAFE=	yes

HAS_CONFIGURE=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake translations \
		src/dbus src/network src/opengl src/phonon \
		src/qt3support src/script src/svg src/testlib \
		src/tools src/xmlpatterns src/3rdparty/clucene \
		src/3rdparty/kdebase src/3rdparty/kdelibs src/3rdparty/webkit
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

WRKSRC=${WRKDIR}/${DISTNAME}/tools/assistant/tools
CONFIGURE_WRKSRC=${WRKSRC}/../../../
PATCH_WRKSRC=${CONFIGURE_WRKSRC}

pre-configure:
	${CP} ${.CURDIR}/../../devel/qt4/files/configure ${CONFIGURE_WRKSRC}
	${REINPLACE_CMD} -e 's|assistant||' \
		${WRKSRC}/tools.pro
	${MKDIR} ${WRKSRC}/../../../mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/../../../bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/../../../bin/moc
	${LN} -sf ${LOCALBASE}/bin/uic-qt4 ${WRKSRC}/../../../bin/uic
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/../../../bin/rcc

.include <bsd.port.mk>
