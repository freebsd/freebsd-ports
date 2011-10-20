# New ports collection makefile for:	qgis
# Date created:		Apr 2006
# Whom:			Laurent Courty
#
# $FreeBSD$
#

PORTNAME=	qgis
PORTVERSION=	1.7.1
CATEGORIES=	graphics geography
MASTER_SITES=	http://qgis.org/downloads/ \
		http://download.osgeo.org/qgis/src/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Geographical Information System (GIS) data viewer

LIB_DEPENDS=	geos:${PORTSDIR}/graphics/geos \
		proj:${PORTSDIR}/graphics/proj \
		gsl.16:${PORTSDIR}/math/gsl \
		qwt.5:${PORTSDIR}/x11-toolkits/qwt5 \
		gdal:${PORTSDIR}/graphics/gdal

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_BISON=	build
USE_CMAKE=	yes
USE_QT_VER=	4
USE_SQLITE=	yes
CMAKE_USE_PTHREAD=	yes
QT_COMPONENTS=	gui svg xml network sql designer linguist_build \
		qmake_build moc_build rcc_build uic_build

USE_LDCONFIG=	yes

MAN1=		qgis.1

OPTIONS=	GRASS "Enable GRASS support" Off \
		POSTGIS "Enable PostGIS support" Off \
		MAPSERVER "Enable MapServer support" off \
		PYTHON "Enable Python support" On

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not compile on 7.X
.endif

.if defined(WITH_GRASS)
CMAKE_ARGS+=	-DWITH_GRASS:BOOL=TRUE -DGRASS_PREFIX=${LOCALBASE}/grass-6.4.1
RUN_DEPENDS+=	${LOCALBASE}/lib/gdalplugins/gdal_GRASS.so:${PORTSDIR}/graphics/gdal-grass
.else
CMAKE_ARGS+=	-DWITH_GRASS:BOOL=FALSE
.endif

.if defined(WITH_POSTGIS)
CMAKE_ARGS+=	-DWITH_POSTGRESQL:BOOL=TRUE
BUILD_DEPENDS+=	${LOCALBASE}/share/postgis:${PORTSDIR}/databases/postgis
PLIST_SUB+=	PGSQL=""
.else
CMAKE_ARGS+=	-DWITH_POSTGRESQL:BOOL=FALSE
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_MAPSERVER)
CMAKE_ARGS+=	-DWITH_MAPSERVER:BOOL=TRUE
PLIST_SUB+=	QGIS_FCGI=""
LIB_DEPENDS+=	fcgi.0:${PORTSDIR}/www/fcgi
.else
CMAKE_ARGS+=	-DWITH_MAPSERVER:BOOL=FALSE
PLIST_SUB+=	QGIS_FCGI="@comment "
.endif

.if defined(WITHOUT_PYTHON)
CMAKE_ARGS+=	-DWITH_BINDINGS:BOOL=FALSE
PLIST_SUB+=	QGIS_PYTHON="@comment "
.else
CMAKE_ARGS+=	-DWITH_BINDINGS:BOOL=TRUE
PLIST_SUB+=	QGIS_PYTHON=""
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sip>=4.8.2:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.5.4:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=4.5.4:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-svg>=4.5.4:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_PKGNAMEPREFIX}qt4-xml>=4.5.4:${PORTSDIR}/textproc/py-qt4-xml \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=4.5.4:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=2.6.5:${PORTSDIR}/databases/py-sqlite3
.endif

.include <bsd.port.post.mk>
