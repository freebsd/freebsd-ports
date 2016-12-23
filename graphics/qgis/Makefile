# Created by: Laurent Courty
# $FreeBSD$

PORTNAME=	qgis
DISTVERSIONPREFIX=	final-
DISTVERSION=	2_18_2
CATEGORIES=	graphics geography

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	Geographical Information System (GIS) data viewer

LICENSE=	GPLv2

BUILD_DEPENDS=	txt2tags:textproc/txt2tags \
		python:lang/python
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libgdal.so:graphics/gdal \
		libgeos.so:graphics/geos \
		libgsl.so:math/gsl \
		libproj.so:graphics/proj \
		libqca.so:devel/qca \
		libqjson.so:devel/qjson \
		libqscintilla2.so:devel/qscintilla2 \
		libqwt.so:x11-toolkits/qwt5 \
		libspatialindex.so:devel/spatialindex \
		libspatialite.so:databases/spatialite

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME:tu}

USES=		bison cmake cpe desktop-file-utils execinfo fortran \
		gmake python:2 sqlite
USE_QT4=	corelib designer doc gui linguist_build moc_build \
		network qmake_build rcc_build script sql svg testlib \
		uic_build webkit xml

USE_LDCONFIG=	yes
ICON_SIZES=	8 16 22 24 32 36 42 48 64 72 80 96 128 192 256 512

OPTIONS_DEFINE=		PYTHON POSTGIS GRASS SERVER
OPTIONS_GROUP=		DEVELOPER
OPTIONS_GROUP_DEVELOPER=	CUSTOMWIDGETS ASTYLE TESTS DEBUG
OPTIONS_DEFAULT=	PYTHON POSTGIS
NO_OPTIONS_SORT=	yes
OPTIONS_SUB=		yes
ASTYLE_DESC=		Enable AStyle for QGis
CUSTOMWIDGETS_DESC=	Enable QT4/QGis Custom Widgets
DEBUG_DESC=		Write Debugging Output to Console
SERVER_DESC=		Enable QGIS server
TESTS_DESC=		Run the test suite after build process

CMAKE_ARGS+=	-DWITH_ORACLE:BOOL=FALSE \
		-DWITH_GLOBE:BOOL=FALSE

.if !defined(MAINTAINER_MODE)
CMAKE_ARGS+=	-Wno-dev
CMAKE_ARGS+=	-DSUPPRESS_SIP_WARNINGS=OFF -DSUPPRESS_QT_WARNINGS=OFF
CMAKE_ARGS+=	-DWITH_INTERNAL_DATEUTIL=FALSE
CMAKE_ARGS+=	-DWITH_INTERNAL_FUTURE=FALSE
CMAKE_ARGS+=	-DWITH_INTERNAL_HTTPLIB2=FALSE
CMAKE_ARGS+=	-DWITH_INTERNAL_JINJA2=FALSE
CMAKE_ARGS+=	-DWITH_INTERNAL_MARKUPSAFE=FALSE
CMAKE_ARGS+=	-DWITH_INTERNAL_NOSE2=FALSE
CMAKE_ARGS+=	-DWITH_INTERNAL_PYGMENTS=FALSE
CMAKE_ARGS+=	-DWITH_INTERNAL_PYTZ=FALSE
CMAKE_ARGS+=	-DWITH_INTERNAL_REQUESTS=FALSE
CMAKE_ARGS+=	-DWITH_INTERNAL_SIX=FALSE
CMAKE_ARGS+=	-DWITH_INTERNAL_YAML=FALSE
.endif

ASTYLE_RUN_DEPENDS=	astyle:devel/astyle
ASTYLE_CMAKE_ON=	-DWITH_ASTYLE:BOOL=TRUE
ASTYLE_CMAKE_OFF=	-DWITH_ASTYLE:BOOL=FALSE

CUSTOMWIDGETS_CMAKE_ON=	-DWITH_CUSTOM_WIDGETS:BOOL=TRUE
CUSTOMWIDGETS_CMAKE_OFF=	-DWITH_CUSTOM_WIDGETS:BOOL=FALSE

DEBUG_CMAKE_ON=		-DCMAKE_BUILD_TYPE=Debug
DEBUG_CMAKE_OFF=	-DCMAKE_BUILD_TYPE=Release

GRASS_BUILD_DEPENDS=	grass64:databases/grass
GRASS_RUN_DEPENDS=	grass64:databases/grass
GRASS_CMAKE_ON=		-DWITH_GRASS:BOOL=TRUE -DGRASS_PREFIX=${LOCALBASE}/grass-6.4.6
GRASS_FORCE_MAKE_JOBS=	NO
GRASS_CMAKE_OFF=	-DWITH_GRASS:BOOL=FALSE

POSTGIS_USES=		pgsql
POSTGIS_LIB_DEPENDS=	liblwgeom.so:databases/postgis22
POSTGIS_CMAKE_ON=	-DWITH_POSTGRESQL:BOOL=TRUE
POSTGIS_CMAKE_OFF=	-DWITH_POSTGRESQL:BOOL=FALSE

PYTHON_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>=0.14.3:devel/py-future \
			${PYTHON_PKGNAMEPREFIX}httplib2>=2-0.9.2:www/py-httplib2 \
			${PYTHON_PKGNAMEPREFIX}Jinja>=1.2:devel/py-Jinja \
			${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.23:textproc/py-MarkupSafe \
			${PYTHON_PKGNAMEPREFIX}matplotlib>=1.4.3:math/py-matplotlib \
			${PYTHON_PKGNAMEPREFIX}mock>=1.3.0:devel/py-mock \
			${PYTHON_PKGNAMEPREFIX}pip>=8.0.2:devel/py-pip \
			${PYTHON_PKGNAMEPREFIX}pyspatialite>=3.0.1:databases/pyspatialite \
			${PYTHON_PKGNAMEPREFIX}pytz>=2016.6.1,1:devel/py-pytz \
			${PYTHON_PKGNAMEPREFIX}qt4-core>=4.8.5:devel/py-qt4-core \
			${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.8.5:x11-toolkits/py-qt4-gui \
			${PYTHON_PKGNAMEPREFIX}qt4-network>=4.8.5:net/py-qt4-network \
			${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=2.8.3:devel/py-qt4-qscintilla2 \
			${PYTHON_PKGNAMEPREFIX}qt4-sql>=4.11.3:databases/py-qt4-sql \
			${PYTHON_PKGNAMEPREFIX}qt4-svg>=4.8.5:graphics/py-qt4-svg \
			${PYTHON_PKGNAMEPREFIX}qt4-xml>=4.5.4:textproc/py-qt4-xml \
			${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py-requests \
			${PYTHON_PKGNAMEPREFIX}sip>=4.14.6:devel/py-sip \
			${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six \
			${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7.6:databases/py-sqlite3 \
			${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>=0.14.3:devel/py-future \
			${PYTHON_PKGNAMEPREFIX}gdal>=2.0.1:graphics/py-gdal \
			${PYTHON_PKGNAMEPREFIX}httplib2>=2-0.9.2:www/py-httplib2 \
			${PYTHON_PKGNAMEPREFIX}Jinja>=1.2:devel/py-Jinja \
			${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.23:textproc/py-MarkupSafe \
			${PYTHON_PKGNAMEPREFIX}matplotlib>=1.4.3:math/py-matplotlib \
			${PYTHON_PKGNAMEPREFIX}mock>=1.3.0:devel/py-mock \
			${PYTHON_PKGNAMEPREFIX}numpy>=1.11.2,1:math/py-numpy \
			${PYTHON_PKGNAMEPREFIX}pip>=8.0.2:devel/py-pip \
			${PYTHON_PKGNAMEPREFIX}psycopg2>=2.5.3:databases/py-psycopg2 \
			${PYTHON_PKGNAMEPREFIX}pyspatialite>=3.0.1:databases/pyspatialite \
			${PYTHON_PKGNAMEPREFIX}pytz>=2016.6.1,1:devel/py-pytz \
			${PYTHON_PKGNAMEPREFIX}qt4-core>=4.8.5:devel/py-qt4-core \
			${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.8.5:x11-toolkits/py-qt4-gui \
			${PYTHON_PKGNAMEPREFIX}qt4-network>=4.8.5:net/py-qt4-network \
			${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=2.8.3:devel/py-qt4-qscintilla2 \
			${PYTHON_PKGNAMEPREFIX}qt4-sql>=4.11.3:databases/py-qt4-sql \
			${PYTHON_PKGNAMEPREFIX}qt4-svg>=4.8.5:graphics/py-qt4-svg \
			${PYTHON_PKGNAMEPREFIX}qt4-webkit>=4.11.1:www/py-qt4-webkit \
			${PYTHON_PKGNAMEPREFIX}qt4-xml>=4.5.4:textproc/py-qt4-xml \
			${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py-requests \
			${PYTHON_PKGNAMEPREFIX}sip>=4.14.6:devel/py-sip \
			${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six \
			${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7.6:databases/py-sqlite3 \
			${PYTHON_PKGNAMEPREFIX}termcolor>=1.1.0:devel/py-termcolor \
			${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml
PYTHON_CMAKE_ON=	-DWITH_BINDINGS:BOOL=TRUE
PYTHON_CMAKE_OFF=	-DWITH_BINDINGS:BOOL=FALSE

SERVER_LIB_DEPENDS=	libfcgi.so:www/fcgi
SERVER_CMAKE_ON=	-DWITH_SERVER:BOOL=TRUE
SERVER_CMAKE_OFF=	-DWITH_SERVER:BOOL=FALSE

TESTS_CMAKE_ON=		-DENABLE_TESTS=TRUE
TESTS_CMAKE_OFF=	-DENABLE_TESTS=FALSE

INSTALLS_ICONS=		yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000033
USES+=		compiler:features
.else
USES+=		compiler:gcc-c++11-lib
BUILD_DEPENDS+=	flex>=2.5.39:textproc/flex
CMAKE_ARGS+=	-DFLEX_EXECUTABLE:STRING=${LOCALBASE}/bin/flex
CXXFLAGS+=	-I${LOCALBASE}/include/flex
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|tr( "QGIS code revision" ) + QString( "</td><td><a href=\\"https://github.com/qgis/QGIS/commit/%1\\">%1</a></td>" ).arg( QGis::QGIS_DEV_VERSION )|tr( "QGIS code revision" ) + "</td><td>" + tr( "${GH_TAGNAME}" ) + "</td>"|g' \
		${WRKSRC}/src/app/qgisapp.cpp
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000033
# [Ugly workaround!] Because of GitHub #76aa035 from 2015-05-23
# 'Hide shared library symbols by default on GCC and Clang',
# some layer properties are not visible on FreeBSD > 9.x
	@${REINPLACE_CMD} -e 's|SET(CMAKE_CXX_VISIBILITY_PRESET hidden)|#SET(CMAKE_CXX_VISIBILITY_PRESET hidden)|' \
		${WRKSRC}/CMakeLists.txt
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/qgis|${LOCALBASE}/bin/qgis|g' \
		${WRKSRC}/debian/${PORTNAME}.desktop
	@${REINPLACE_CMD} -e 's|Icon=qgis|Icon=qgis-icon|' \
		${WRKSRC}/debian/${PORTNAME}.desktop
	@${REINPLACE_CMD} -e 's|env python|env ${PYTHON_VERSION}|g' \
		${WRKSRC}/python/ext-libs/pygments/util.py \
		${WRKSRC}/python/ext-libs/pytz/tzfile.py \
		${WRKSRC}/scripts/generate_test_mask_image.py \
		${WRKSRC}/scripts/random_vector.py \
		${WRKSRC}/scripts/widgets_tree.py \
		${WRKSRC}/src/plugins/grass/qgis_grass_test.py \
		${WRKSRC}/src/plugins/grass/scripts/qgis.v.kernel.rast.py \
		${WRKSRC}/src/plugins/grass/scripts/v.out.ogr.pg.py \
		${WRKSRC}/src/plugins/grass/scripts/qgis.v.upgrade.py \
		${WRKSRC}/src/plugins/grass/scripts/r.external.all.py \
		${WRKSRC}/src/plugins/grass/scripts/db.connect-login.pg.py
	@${REINPLACE_CMD} -e 's|markupsafe ||g' \
		${WRKSRC}/python/ext-libs/CMakeLists.txt

post-install:
	${RM} ${STAGEDIR}${DATADIR}/python/pygments/util.py.bak
	${RM} ${STAGEDIR}${DATADIR}/python/pytz/tzfile.py.bak
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/debian/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor
.for SZ in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/apps
	${INSTALL_DATA} ${WRKSRC}/debian/${PORTNAME}-icon${SZ}x${SZ}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/apps/${PORTNAME}.png
.endfor

check:
	(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check)

.include <bsd.port.mk>
