# Created by: Laurent Courty
# $FreeBSD$

PORTNAME=	qgis
PORTVERSION=	2.12.2
CATEGORIES=	graphics geography

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	Geographical Information System (GIS) data viewer

LICENSE=	GPLv2

BUILD_DEPENDS=	txt2tags:${PORTSDIR}/textproc/txt2tags
LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal \
		libgeos.so:${PORTSDIR}/graphics/geos \
		libgsl.so:${PORTSDIR}/math/gsl \
		libproj.so:${PORTSDIR}/graphics/proj \
		libqca.so:${PORTSDIR}/devel/qca \
		libqscintilla2.so:${PORTSDIR}/devel/qscintilla2 \
		libqwt.so:${PORTSDIR}/x11-toolkits/qwt5 \
		libspatialindex.so:${PORTSDIR}/devel/spatialindex \
		libspatialite.so:${PORTSDIR}/databases/spatialite

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME:tu}
GH_TAGNAME=	B403532

USES=		cpe bison cmake execinfo fortran gmake sqlite python
USE_QT4=	gui svg xml network sql designer testlib linguist_build \
		qmake_build moc_build rcc_build uic_build

USE_LDCONFIG=	yes

OPTIONS_DEFINE=		POSTGIS PYTHON GRASS SERVER DEBUG
OPTIONS_DEFAULT=	POSTGIS PYTHON
OPTIONS_SUB=		yes
NO_OPTIONS_SORT=	yes
SERVER_DESC=	Enable QGIS server

CMAKE_ARGS+=	-DWITH_ORACLE:BOOL=FALSE

.if !defined(MAINTAINER_MODE)
CMAKE_ARGS+=	-Wno-dev
.endif

GRASS_BUILD_DEPENDS=	grass64:${PORTSDIR}/databases/grass
GRASS_RUN_DEPENDS=	grass64:${PORTSDIR}/databases/grass
GRASS_CMAKE_ON=		-DWITH_GRASS:BOOL=TRUE -DGRASS_PREFIX=${LOCALBASE}/grass-6.4.5
GRASS_CMAKE_OFF=	-DWITH_GRASS:BOOL=FALSE
GRASS_FORCE_MAKE_JOBS=	NO

POSTGIS_LIB_DEPENDS=	liblwgeom.so:${PORTSDIR}/databases/postgis21
POSTGIS_CMAKE_ON=	-DWITH_POSTGRESQL:BOOL=TRUE
POSTGIS_CMAKE_OFF=	-DWITH_POSTGRESQL:BOOL=FALSE

SERVER_LIB_DEPENDS=	libfcgi.so:${PORTSDIR}/www/fcgi
SERVER_CMAKE_ON=	-DWITH_SERVER:BOOL=TRUE
SERVER_CMAKE_OFF=	-DWITH_SERVER:BOOL=FALSE

PYTHON_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-core>=4.8.5:${PORTSDIR}/devel/py-qt4-core \
			${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.8.5:${PORTSDIR}/x11-toolkits/py-qt4-gui \
			${PYTHON_PKGNAMEPREFIX}qt4-network>=4.8.5:${PORTSDIR}/net/py-qt4-network \
			${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=2.8.3:${PORTSDIR}/devel/py-qt4-qscintilla2 \
			${PYTHON_PKGNAMEPREFIX}qt4-sql>=4.11.3:${PORTSDIR}/databases/py-qt4-sql \
			${PYTHON_PKGNAMEPREFIX}qt4-svg>=4.8.5:${PORTSDIR}/graphics/py-qt4-svg \
			${PYTHON_PKGNAMEPREFIX}qt4-xml>=4.5.4:${PORTSDIR}/textproc/py-qt4-xml \
			${PYTHON_PKGNAMEPREFIX}sip>=4.14.6:${PORTSDIR}/devel/py-sip \
			${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7.6:${PORTSDIR}/databases/py-sqlite3
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdal>=2.0.1:${PORTSDIR}/graphics/py-gdal \
			${PYTHON_PKGNAMEPREFIX}numpy>=1.9.1:${PORTSDIR}/math/py-numpy \
			${PYTHON_PKGNAMEPREFIX}psycopg2>=2.5.3:${PORTSDIR}/databases/py-psycopg2 \
			${PYTHON_PKGNAMEPREFIX}pyspatialite>=3.0.1:${PORTSDIR}/databases/pyspatialite \
			${PYTHON_PKGNAMEPREFIX}qt4-core>=4.8.5:${PORTSDIR}/devel/py-qt4-core \
			${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.8.5:${PORTSDIR}/x11-toolkits/py-qt4-gui \
			${PYTHON_PKGNAMEPREFIX}qt4-network>=4.8.5:${PORTSDIR}/net/py-qt4-network \
			${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=2.8.3:${PORTSDIR}/devel/py-qt4-qscintilla2 \
			${PYTHON_PKGNAMEPREFIX}qt4-sql>=4.11.3:${PORTSDIR}/databases/py-qt4-sql \
			${PYTHON_PKGNAMEPREFIX}qt4-svg>=4.8.5:${PORTSDIR}/graphics/py-qt4-svg \
			${PYTHON_PKGNAMEPREFIX}qt4-webkit>=4.11.1:${PORTSDIR}/www/py-qt4-webkit \
			${PYTHON_PKGNAMEPREFIX}qt4-xml>=4.5.4:${PORTSDIR}/textproc/py-qt4-xml \
			${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7.6:${PORTSDIR}/databases/py-sqlite3
PYTHON_CMAKE_ON=	-DWITH_BINDINGS:BOOL=TRUE
PYTHON_CMAKE_OFF=	-DWITH_BINDINGS:BOOL=FALSE

DEBUG_CMAKE_ON=		-DCMAKE_BUILD_TYPE=Debug
DEBUG_CMAKE_OFF=	-DCMAKE_BUILD_TYPE=Release

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000033
USES+=		compiler:features
.else
USES+=		compiler:gcc-c++11-lib
BUILD_DEPENDS+=	flex>=2.5.39:${PORTSDIR}/textproc/flex
CMAKE_ARGS+=	-DFLEX_EXECUTABLE:STRING=${LOCALBASE}/bin/flex
CXXFLAGS+=	-I${LOCALBASE}/include/flex
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|tr( "QGIS code revision" ) + QString( "</td><td><a href=\\"https://github.com/qgis/QGIS/commit/%1\\">%1</a></td>" ).arg( QGis::QGIS_DEV_VERSION )|tr( "QGIS code revision" ) + "</td><td>" + tr( "${GH_TAGNAME}" ) + "</td>"|g' \
		${WRKSRC}/src/app/qgisapp.cpp

.include <bsd.port.mk>
