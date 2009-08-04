# -*-mode: makefile-*-
# New ports collection makefile for:	qt40
# Date created:				Wed Jun 29 11:49:42 CEST 2005
# Whom:					lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	codecs
PORTVERSION=	${QT4_VERSION}
CATEGORIES?=	chinese
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
PKGNAMESUFFIX=	-tw
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Big-5 codec plugin

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build corelib
QT_NONSTANDARD=	yes
QT_DIST=	yes

HAS_CONFIGURE=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH

DO_NOT_EXTRACT=	demos doc examples qmake tools translations \
		src/dbus src/gui src/network src/opengl src/phonon \
		src/qt3support src/script src/sql src/svg src/testlib \
		src/tools src/xml src/xmlpatterns src/3rdparty/clucene \
		src/3rdparty/kdebase src/3rdparty/kdelibs src/3rdparty/webkit
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

WRKSRC=		${WRKDIR}/${DISTNAME}/src/plugins/${PORTNAME}/tw
CONFIGURE_WRKSRC=${WRKSRC}/../../../..

pre-configure:
	${CP} ${.CURDIR}/../../devel/qt4/files/configure ${CONFIGURE_WRKSRC}
	${MKDIR} ${WRKSRC}/../../../mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/../../../../bin/qmake

post-configure:
	${REINPLACE_CMD} -e 's|(test -z.*||g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
