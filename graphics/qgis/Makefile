# Created by: Laurent Courty
# $FreeBSD$

PORTNAME=	qgis
DISTVERSIONPREFIX=	final-
DISTVERSION=	2_18_15
PORTREVISION=	1
CATEGORIES=	graphics geography

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	Geographical Information System (GIS) data viewer

LICENSE=	GPLv2

BUILD_DEPENDS=	txt2tags:textproc/txt2tags
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libgdal.so:graphics/gdal \
		libgeos.so:graphics/geos \
		libgsl.so:math/gsl \
		libproj.so:graphics/proj \
		libqca.so:devel/qca \
		libqjson.so:devel/qjson \
		libqscintilla2_qt4.so:devel/qscintilla2 \
		libqwt.so:x11-toolkits/qwt5 \
		libspatialindex.so:devel/spatialindex \
		libspatialite.so:databases/spatialite \
		libxerces-c.so:textproc/xerces-c3

USES=		bison cmake compiler:features cpe desktop-file-utils \
		fortran gmake pyqt:4 python:2.7 sqlite:3

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME:tu}

USE_PYQT=	core gui network qscintilla2 sip sql svg xml webkit_run

USE_QT4=	corelib designer doc gui linguist_build moc_build \
		network qmake_build rcc_build script sql sql-pgsql \
		sql-sqlite3 svg testlib uic_build webkit xml

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

CMAKE_ARGS+=	-DENABLE_QT5=OFF -DENABLE_PYTHON3=OFF \
		-DWITH_ORACLE:BOOL=FALSE \
		-DWITH_GLOBE:BOOL=FALSE

.if !defined(MAINTAINER_MODE)
CMAKE_ARGS+=	-Wno-dev
CMAKE_ARGS+=	-DSUPPRESS_SIP_WARNINGS=OFF -DSUPPRESS_QT_WARNINGS=OFF
CMAKE_ARGS+=	-DWITH_INTERNAL_DATEUTIL=FALSE
CMAKE_ARGS+=	-DWITH_INTERNAL_FUTURE=FALSE
CMAKE_ARGS+=	-DWITH_INTERNAL_NOSE2=FALSE
CMAKE_ARGS+=	-DWITH_INTERNAL_PYTZ=FALSE
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

GRASS_BUILD_DEPENDS=	grass72:databases/grass7
GRASS_RUN_DEPENDS=	grass72:databases/grass7
GRASS_CMAKE_ON=		-DWITH_GRASS7:BOOL=TRUE -DGRASS_PREFIX7=${LOCALBASE}/grass-7.2.2
GRASS_FORCE_MAKE_JOBS=	NO
GRASS_CMAKE_OFF=	-DWITH_GRASS7:BOOL=FALSE

POSTGIS_USES=		pgsql
#POSTGIS_LIB_DEPENDS=	liblwgeom.so:databases/postgis22
POSTGIS_CMAKE_ON=	-DWITH_POSTGRESQL:BOOL=TRUE
POSTGIS_CMAKE_OFF=	-DWITH_POSTGRESQL:BOOL=FALSE

PYTHON_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cycler>=0.10.0:devel/py-cycler@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}dateutil>=2.6.0:devel/py-dateutil@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}functools32>=3.2.3:devel/py-functools32@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}future>=0.16.0:devel/py-future@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}httplib2>=2-0.9.2:www/py-httplib2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}Jinja2>=2.8:devel/py-Jinja2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}MarkupSafe>=1.0:textproc/py-MarkupSafe@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}matplotlib>=1.5.3:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mock>=1.3.0:devel/py-mock@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pbr>=1.8.1:devel/py-pbr@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pip>=9.0.1:devel/py-pip@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pygments>=2.1.3:textproc/py-pygments@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyproj>=1.9.5.1:graphics/py-pyproj@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyspatialite>=3.0.1:databases/pyspatialite \
			${PYTHON_PKGNAMEPREFIX}pytz>=2016.10:devel/py-pytz@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>=2.11.1:www/py-requests@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7.13:databases/py-sqlite3@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}wxPython-common>=3.0.2.0:x11-toolkits/py-wxPython-common@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR}
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cycler>=0.10.0:devel/py-cycler@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}dateutil>=2.6.0:devel/py-dateutil@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}functools32>=3.2.3:devel/py-functools32@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}future>=0.16.0:devel/py-future@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}gdal>=2.0.1:graphics/py-gdal@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}httplib2>=2-0.9.2:www/py-httplib2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}Jinja2>=2.8:devel/py-Jinja2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}MarkupSafe>=1.0:textproc/py-MarkupSafe@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}matplotlib>=1.5.3:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mock>=1.3.0:devel/py-mock@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numpy>=1.11.2,1:math/py-numpy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pbr>=1.8.1:devel/py-pbr@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pip>=9.0.1:devel/py-pip@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}psycopg2>=2.5.3:databases/py-psycopg2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pygments>=2.1.3:textproc/py-pygments@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyproj>=1.9.5.1:graphics/py-pyproj@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyspatialite>=3.0.1:databases/pyspatialite \
			${PYTHON_PKGNAMEPREFIX}pytz>=2016.10:devel/py-pytz@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>=2.11.1:www/py-requests@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7.13:databases/py-sqlite3@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}termcolor>=1.1.0:devel/py-termcolor@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}wxPython-common>=3.0.2.0:x11-toolkits/py-wxPython-common@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR}
PYTHON_CMAKE_ON=	-DWITH_BINDINGS:BOOL=TRUE
PYTHON_CMAKE_OFF=	-DWITH_BINDINGS:BOOL=FALSE

SERVER_LIB_DEPENDS=	libfcgi.so:www/fcgi
SERVER_CMAKE_ON=	-DWITH_SERVER:BOOL=TRUE
SERVER_CMAKE_OFF=	-DWITH_SERVER:BOOL=FALSE

TESTS_CMAKE_ON=		-DENABLE_TESTS=TRUE
TESTS_CMAKE_OFF=	-DENABLE_TESTS=FALSE

INSTALLS_ICONS=		yes

pre-patch:
	@${REINPLACE_CMD} -e 's|tr( "QGIS code revision" ) + QString( "</td><td><a href=\\"https://github.com/qgis/QGIS/commit/%1\\">%1</a></td>" ).arg( QGis::QGIS_DEV_VERSION )|tr( "QGIS code revision" ) + "</td><td>" + tr( "${GH_TAGNAME}" ) + "</td>"|g' \
		${WRKSRC}/src/app/qgisapp.cpp
# [Ugly workaround!] Because of GitHub #76aa035 from 2015-05-23
# 'Hide shared library symbols by default on GCC and Clang',
# some layer properties are not visible on FreeBSD > 9.x
	@${REINPLACE_CMD} -e 's|SET(CMAKE_CXX_VISIBILITY_PRESET hidden)|#SET(CMAKE_CXX_VISIBILITY_PRESET hidden)|' \
		${WRKSRC}/CMakeLists.txt

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/qgis|${LOCALBASE}/bin/qgis|g' \
		${WRKSRC}/debian/${PORTNAME}.desktop
	@${REINPLACE_CMD} -e 's|Icon=qgis|Icon=qgis-icon|' \
		${WRKSRC}/debian/${PORTNAME}.desktop
	@${REINPLACE_CMD} -e 's|env python|env ${PYTHON_VERSION}|g' \
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

post-install-TESTS-on:
	${RM} /tmp/srs.db

check:
	(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check)

.include <bsd.port.mk>
