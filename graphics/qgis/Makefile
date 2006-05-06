# New ports collection makefile for:	qgis
# Date created:		Apr 2006
# Whom:			Laurent Courty
#
# $FreeBSD$
#

PORTNAME=	qgis
PORTVERSION=	0.7.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	lrntct@gmail.com
COMMENT=	A Geographical Information System (GIS) data viewer

LIB_DEPENDS=	geos:${PORTSDIR}/graphics/geos \
		proj:${PORTSDIR}/graphics/proj \
		gsl.9:${PORTSDIR}/math/gsl \
		gdal:${PORTSDIR}/graphics/gdal
BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_GMAKE=	yes
USE_FREETYPE=	yes
USE_QT_VER=	3
USE_SQLITE=	yes
MAN1=		qgis.1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qtdir=${QTDIR}
INSTALLS_SHLIB=	yes

OPTIONS=	GRASS "Enable GRASS support" Off \
		POSTGIS "Enable PostGIS support" Off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not build on FreeBSD versions prior to 5
.endif

.if !defined (QTDIR)
QTDIR=		${X11BASE}
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
