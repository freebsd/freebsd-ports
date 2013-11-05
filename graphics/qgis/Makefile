# Created by: Laurent Courty
# $FreeBSD$

PORTNAME=	qgis
PORTVERSION=	1.8.0
PORTREVISION=	5
CATEGORIES=	graphics geography
MASTER_SITES=	http://qgis.org/downloads/ \
		http://download.osgeo.org/qgis/src/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Geographical Information System (GIS) data viewer

LIB_DEPENDS=	geos:${PORTSDIR}/graphics/geos \
		proj:${PORTSDIR}/graphics/proj \
		gsl:${PORTSDIR}/math/gsl \
		qwt:${PORTSDIR}/x11-toolkits/qwt5 \
		gdal:${PORTSDIR}/graphics/gdal \
		spatialite:${PORTSDIR}/databases/spatialite \
		spatialindex:${PORTSDIR}/devel/spatialindex

USE_BZIP2=	yes
USE_PYTHON=	yes
USES=		bison cmake
USE_SQLITE=	yes
USE_QT4=	gui svg xml network sql designer linguist_build \
		qmake_build moc_build rcc_build uic_build

USE_LDCONFIG=	yes

MAN1=		qgis.1

OPTIONS_DEFINE=		GRASS POSTGIS MAPSERVER PYTHON

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not compile on 7.X
.endif

.if ${PORT_OPTIONS:MGRASS}
CMAKE_ARGS+=	-DWITH_GRASS:BOOL=TRUE -DGRASS_PREFIX=${LOCALBASE}/grass-6.4.2
RUN_DEPENDS+=	${LOCALBASE}/lib/gdalplugins/gdal_GRASS.so:${PORTSDIR}/graphics/gdal-grass
.else
CMAKE_ARGS+=	-DWITH_GRASS:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MPOSTGIS}
USE_PGSQL=	YES
CMAKE_ARGS+=	-DWITH_POSTGRESQL:BOOL=TRUE
PLIST_SUB+=	PGSQL=""
.else
CMAKE_ARGS+=	-DWITH_POSTGRESQL:BOOL=FALSE
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MMAPSERVER}
CMAKE_ARGS+=	-DWITH_MAPSERVER:BOOL=TRUE
PLIST_SUB+=	QGIS_FCGI=""
LIB_DEPENDS+=	fcgi.0:${PORTSDIR}/www/fcgi
.else
CMAKE_ARGS+=	-DWITH_MAPSERVER:BOOL=FALSE
PLIST_SUB+=	QGIS_FCGI="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
CMAKE_ARGS+=	-DWITH_BINDINGS:BOOL=TRUE
PLIST_SUB+=	QGIS_PYTHON=""
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sip>=4.8.2:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.5.4:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=4.5.4:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-svg>=4.5.4:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_PKGNAMEPREFIX}qt4-xml>=4.5.4:${PORTSDIR}/textproc/py-qt4-xml \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=4.5.4:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=2.6.5:${PORTSDIR}/databases/py-sqlite3
.else
CMAKE_ARGS+=	-DWITH_BINDINGS:BOOL=FALSE
PLIST_SUB+=	QGIS_PYTHON="@comment "
.endif

.include <bsd.port.mk>
