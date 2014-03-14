# Created by: Laurent Courty
# $FreeBSD$

PORTNAME=	qgis
PORTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	graphics geography

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	Geographical Information System (GIS) data viewer

LICENSE=	GPLv2

LIB_DEPENDS=	libgeos.so:${PORTSDIR}/graphics/geos \
		libproj.so:${PORTSDIR}/graphics/proj \
		libgsl.so:${PORTSDIR}/math/gsl \
		libqwt.so:${PORTSDIR}/x11-toolkits/qwt5 \
		libgdal.so:${PORTSDIR}/graphics/gdal \
		libspatialite.so:${PORTSDIR}/databases/spatialite \
		libspatialindex.so:${PORTSDIR}/devel/spatialindex \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo

BUILD_DEPENDS=	txt2tags:${PORTSDIR}/textproc/txt2tags

WRKSRC=	${WRKDIR}/${PORTNAME}-QGIS-${GH_COMMIT}

USE_GITHUB=
GH_ACCOUNT=	qgis
GH_COMMIT=	1c3699e
GH_TAGNAME=	${GH_COMMIT}

USES=		compiler:features bison cmake gmake
### GCC can not build src/crssync/CMakeFiles/synccrsdb
#USE_GCC=	4.8+
USE_PYTHON=	yes
USE_SQLITE=	yes
USE_QT4=	gui svg xml network sql designer testlib linguist_build \
		qmake_build moc_build rcc_build uic_build

USE_LDCONFIG=	yes

OPTIONS_DEFINE=		GRASS POSTGIS MAPSERVER PYTHON
OPTIONS_DEFAULT=	POSTGIS PYTHON

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGRASS}
CMAKE_ARGS+=	-DWITH_GRASS:BOOL=TRUE -DGRASS_PREFIX=${LOCALBASE}/grass-6.4.3
RUN_DEPENDS+=	${LOCALBASE}/lib/gdalplugins/gdal_GRASS.so:${PORTSDIR}/graphics/gdal-grass
FORCE_MAKE_JOBS=	NO
INFO=		qgis/grass/modules/qgis.g
PLIST_SUB+=	GRASS=""
.else
CMAKE_ARGS+=	-DWITH_GRASS:BOOL=FALSE
PLIST_SUB+=	GRASS="@comment "
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
LIB_DEPENDS+=	libfcgi.so:${PORTSDIR}/www/fcgi
.else
CMAKE_ARGS+=	-DWITH_MAPSERVER:BOOL=FALSE
PLIST_SUB+=	QGIS_FCGI="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
CMAKE_ARGS+=	-DWITH_BINDINGS:BOOL=TRUE
PLIST_SUB+=	QGIS_PYTHON=""
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sip>=4.14.6:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}qt4-xml>=4.5.4:${PORTSDIR}/textproc/py-qt4-xml \
		${PYTHON_SITELIBDIR}/PyQt4/Qsci.so:${PORTSDIR}/devel/py-qt4-qscintilla2 \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.8.5:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=4.8.5:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-svg>=4.8.5:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=4.8.5:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7.6:${PORTSDIR}/databases/py-sqlite3
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/osgeo/gdal.pyc:${PORTSDIR}/graphics/py-gdal
.else
CMAKE_ARGS+=	-DWITH_BINDINGS:BOOL=FALSE
PLIST_SUB+=	QGIS_PYTHON="@comment "
.endif

.include <bsd.port.mk>
