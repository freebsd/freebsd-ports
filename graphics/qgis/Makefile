# New ports collection makefile for:	qgis
# Date created:		Apr 2006
# Whom:			Laurent Courty
#
# $FreeBSD$
#

PORTNAME=	qgis
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	graphics geography
MASTER_SITES=	http://download.osgeo.org/qgis/src/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Geographical Information System (GIS) data viewer

LIB_DEPENDS=	geos:${PORTSDIR}/graphics/geos \
		proj:${PORTSDIR}/graphics/proj \
		gsl.13:${PORTSDIR}/math/gsl \
		gdal:${PORTSDIR}/graphics/gdal

USE_BISON=	build
USE_CMAKE=	yes
USE_QT_VER=	4
USE_SQLITE=	yes
CMAKE_USE_PTHREAD=	yes
CMAKE_ENV+=	QMAKESPEC=${QMAKESPEC}
QT_COMPONENTS=	gui svg xml network sql linguist_build \
		qmake_build moc_build rcc_build uic_build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qtdir=${QTDIR}
USE_LDCONFIG=	yes

OPTIONS=	GRASS "Enable GRASS support" Off \
		POSTGIS "Enable PostGIS support" Off

.include <bsd.port.pre.mk>

.if !defined (QTDIR)
QTDIR=		${QT_PREFIX}
.endif

.if !defined (GRASS_INST_DIR)
GRASS_INST_DIR=	grass
.endif

.if defined(WITH_GRASS)
CONFIGURE_ARGS+=--with-grass=${LOCALBASE}/${GRASS_INST_DIR}
RUN_DEPENDS+=	${LOCALBASE}/lib/gdalplugins/gdal_GRASS.so:${PORTSDIR}/graphics/gdal-grass
.endif

.if defined(WITH_POSTGIS)
CONFIGURE_ARGS+=--with-postgresql
BUILD_DEPENDS+=	${LOCALBASE}/share/postgis:${PORTSDIR}/databases/postgis
PLIST_SUB+=	PGSQL=""
.else
CONFIGURE_ARGS+=--without-postgresql
PLIST_SUB+=	PGSQL="@comment "
.endif

.include <bsd.port.post.mk>
