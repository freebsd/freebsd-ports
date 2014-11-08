# Created by: Laurent Courty
# $FreeBSD$

PORTNAME=	qgis
PORTVERSION=	2.4.0
PORTREVISION=	3
CATEGORIES=	graphics geography

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	Geographical Information System (GIS) data viewer

LICENSE=	GPLv2

BUILD_DEPENDS=	txt2tags:${PORTSDIR}/textproc/txt2tags
LIB_DEPENDS=	libgeos.so:${PORTSDIR}/graphics/geos \
		libproj.so:${PORTSDIR}/graphics/proj \
		libgsl.so:${PORTSDIR}/math/gsl \
		libqwt.so:${PORTSDIR}/x11-toolkits/qwt5 \
		libgdal.so:${PORTSDIR}/graphics/gdal \
		libspatialite.so:${PORTSDIR}/databases/spatialite \
		libspatialindex.so:${PORTSDIR}/devel/spatialindex \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo

WRKSRC=	${WRKDIR}/${PORTNAME}-QGIS-${GH_COMMIT}

USE_GITHUB=
GH_ACCOUNT=	qgis
GH_COMMIT=	00ab94f
GH_TAGNAME=	${GH_COMMIT}

USES=		bison cmake fortran gmake python
USE_SQLITE=	yes
USE_QT4=	gui svg xml network sql designer testlib linguist_build \
		qmake_build moc_build rcc_build uic_build

USE_LDCONFIG=	yes

OPTIONS_DEFINE=		GRASS POSTGIS PYTHON MAPSERVER
OPTIONS_DEFAULT=	POSTGIS PYTHON

.if !defined(MAINTAINER_MODE)
CMAKE_ARGS+=	-Wno-dev
.endif

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
USES+=		compiler:features
.else
USES+=		compiler:gcc-c++11-lib
.endif

.if ${PORT_OPTIONS:MGRASS}
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 900000
BROKEN=		GRASS plugin not supported on FreeBSD 8.x (does not have utempter.h)
.endif
BUILD_DEPENDS+=	grass64:${PORTSDIR}/databases/grass \
		${LOCALBASE}/lib/gdalplugins/gdal_GRASS.so:${PORTSDIR}/graphics/gdal-grass
RUN_DEPENDS+=	grass64:${PORTSDIR}/databases/grass \
		${LOCALBASE}/lib/gdalplugins/gdal_GRASS.so:${PORTSDIR}/graphics/gdal-grass
CMAKE_ARGS+=	-DWITH_GRASS:BOOL=TRUE -DGRASS_PREFIX=${LOCALBASE}/grass-6.4.4
FORCE_MAKE_JOBS=	NO
PLIST_SUB+=	GRASS=""
.else
CMAKE_ARGS+=	-DWITH_GRASS:BOOL=FALSE
PLIST_SUB+=	GRASS="@comment "
.endif

.if ${PORT_OPTIONS:MPOSTGIS}
USES+=		pgsql
CMAKE_ARGS+=	-DWITH_POSTGRESQL:BOOL=TRUE
PLIST_SUB+=	PGSQL=""
.else
CMAKE_ARGS+=	-DWITH_POSTGRESQL:BOOL=FALSE
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MMAPSERVER}
CMAKE_ARGS+=	-DWITH_MAPSERVER:BOOL=TRUE
PLIST_SUB+=	QGIS_MAPSERVER=""
LIB_DEPENDS+=	libfcgi.so:${PORTSDIR}/www/fcgi \
		libmapserver.so:${PORTSDIR}/graphics/mapserver
.else
CMAKE_ARGS+=	-DWITH_MAPSERVER:BOOL=FALSE
PLIST_SUB+=	QGIS_MAPSERVER="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
CMAKE_ARGS+=	-DWITH_BINDINGS:BOOL=TRUE
PLIST_SUB+=	QGIS_PYTHON=""
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sip>=4.14.6:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}qt4-xml>=4.5.4:${PORTSDIR}/textproc/py-qt4-xml \
		${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=2.8.3:${PORTSDIR}/devel/py-qt4-qscintilla2 \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.8.5:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=4.8.5:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-svg>=4.8.5:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=4.8.5:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7.6:${PORTSDIR}/databases/py-sqlite3
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gdal>=1.11.1:${PORTSDIR}/graphics/py-gdal \
		${PYTHON_PKGNAMEPREFIX}qt4-xml>=4.5.4:${PORTSDIR}/textproc/py-qt4-xml \
		${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=2.8.3:${PORTSDIR}/devel/py-qt4-qscintilla2 \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.8.5:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=4.8.5:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-svg>=4.8.5:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=4.8.5:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7.6:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}pyspatialite>=3.0.1:${PORTSDIR}/databases/pyspatialite
.else
CMAKE_ARGS+=	-DWITH_BINDINGS:BOOL=FALSE
PLIST_SUB+=	QGIS_PYTHON="@comment "
.endif

.include <bsd.port.mk>
