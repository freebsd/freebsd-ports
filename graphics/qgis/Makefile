# New ports collection makefile for:	qgis
# Date created:		Apr 2006
# Whom:			Laurent Courty
#
# $FreeBSD$
#

PORTNAME=	qgis
PORTVERSION=	0.7.4
PORTREVISION=	3
CATEGORIES=	graphics geography
MASTER_SITES=	SF

MAINTAINER=	dyeske@gmail.com
COMMENT=	Geographical Information System (GIS) data viewer

LIB_DEPENDS=	geos:${PORTSDIR}/graphics/geos \
		proj:${PORTSDIR}/graphics/proj \
		gsl.10:${PORTSDIR}/math/gsl \
		gdal:${PORTSDIR}/graphics/gdal
BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_FREETYPE=	yes
USE_QT_VER=	3
USE_SQLITE=	yes
MAN1=		qgis.1

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
RUN_DEPENDS+=${LOCALBASE}/lib/gdalplugins/gdal_GRASS.so:${PORTSDIR}/graphics/gdal-grass
PLIST_SUB+=	GRASS=""
.else
PLIST_SUB+=	GRASS="@comment "
.endif

.if defined(WITH_POSTGIS)
CONFIGURE_ARGS+=--with-postgresql
BUILD_DEPENDS+=${LOCALBASE}/share/postgis:${PORTSDIR}/databases/postgis
PLIST_SUB+=	PGSQL=""
.else
CONFIGURE_ARGS+=--without-postgresql
PLIST_SUB+=	PGSQL="@comment "
.endif

.include <bsd.port.post.mk>
