# Created by: Laurent Courty
# $FreeBSD$

PORTNAME=	qgis
DISTVERSIONPREFIX=	final-
DISTVERSION=	3_10_14
PORTREVISION=	4
CATEGORIES=	graphics geography
PKGNAMESUFFIX=	-ltr

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	33192f38bc7d.patch:-p1 \
		12203f0ce527.patch:-p1 \
		6e9d42d70099.patch:-p1

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Free and Open Source Geographic Information System

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

BUILD_DEPENDS=	gpsbabel>=1.5.4:astro/gpsbabel \
		opencl>=0:devel/opencl \
		${PYTHON_PKGNAMEPREFIX}cycler>=0.10.0:devel/py-cycler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.8.1:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.18.2:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.17.3:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=1.1.1:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.2.4:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=3.0.5:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}OWSLib>=0.20.0:graphics/py-OWSLib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=3.1.1:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=19.1.1:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plotly>=3.0.2:graphics/py-plotly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.5.2:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproj>=2.1.3:graphics/py-pyproj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2020.1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.22.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.14.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=3.7.7:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.3.1:devel/py-yaml@${PY_FLAVOR}
LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		libexpat.so:textproc/expat2 \
		libgdal.so:graphics/gdal \
		libgeos.so:graphics/geos \
		libgsl.so:math/gsl \
		libhdf5.so:science/hdf5 \
		libnetcdf.so:science/netcdf \
		libOpenCL.so:devel/ocl-icd \
		libproj.so:graphics/proj \
		libprotobuf-lite.so:devel/protobuf \
		libqjson-qt5.so:devel/qjson \
		libqscintilla2_qt5.so:devel/qscintilla2-qt5 \
		libqt5keychain.so:security/qtkeychain \
		libqwt6.so:x11-toolkits/qwt6 \
		libspatialindex.so:devel/spatialindex \
		libspatialite.so:databases/spatialite \
		libsz.so:science/szip \
		libxerces-c.so:textproc/xerces-c3 \
		libzip.so:archivers/libzip \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	astyle:devel/astyle \
		opencl>=0:devel/opencl \
		${PYTHON_PKGNAMEPREFIX}black>=19.10:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cycler>=0.10.0:devel/py-cycler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.8.1:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.18.2:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gdal>=3.1.0:graphics/py-gdal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}geojson>=2.3.0:devel/py-geojson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}geopandas>=0.7.0:graphics/py-geopandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.17.3:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jedi>=0.12.1:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=1.1.1:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.2.4:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=3.0.5:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>=5.0.7:devel/py-nbformat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.1:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nltk>=3.4.1:textproc/py-nltk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16.6:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}OWSLib>=0.18.0:graphics/py-OWSLib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.24.2:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=3.1.1:devel/py-pbr@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}pip>=19.1.1:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plotly>=3.0.2:graphics/py-plotly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.7.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.8.5:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.5.2:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproj>=2.1.3:graphics/py-pyproj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyrsgis>=0.2.6:graphics/py-pyrsgis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2020.1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.22.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>=0.14.3:graphics/py-scikit-image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Shapely>=1.6.4:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.14.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=3.7.7:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=1.1.0:devel/py-termcolor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.3.1:devel/py-yaml@${PY_FLAVOR}

### Fortran is needed by numpy, GRASS, etc.
USES=		bison cmake compiler:features cpe desktop-file-utils \
		fortran gl gmake gnome pgsql pyqt:5 python:3.7+ qca qt:5 \
		shebangfix sqlite:3
USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME:tu}
USE_GL=		gl
USE_GNOME=	libxml2
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USE_PYQT=	core gui network qml quick quickwidgets qscintilla2 \
		sip sql svg webkit_run webkitwidgets_run xml
USE_QT=		3d buildtools_build core concurrent dbus declarative \
		designer doc gamepad gui linguist_build location \
		network printsupport qmake_build script serialport \
		sql sql-pgsql sql-sqlite3 svg testlib uitools \
		webengine widgets webkit xml

SHEBANG_FILES=	src/plugins/grass/scripts/*.py

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING=Release \
		-DPYRCC_PROGRAM:FILEPATH=${LOCALBASE}/bin/pyrcc5-${PYTHON_VER} \
		-DPYUIC_PROGRAM:FILEPATH=${LOCALBASE}/bin/pyuic5-${PYTHON_VER} \
		-DQSCI_SIP_DIR:PATH=${PYQT_SIPDIR}/Qsci \
		-DQWT_INCLUDE_DIR:PATH=${LOCALBASE}/include/qt5/qwt6 \
		-DQWT_LIBRARY:FILEPATH=${LOCALBASE}/lib/qt5/libqwt6.so \
		-DCMAKE_POLICY_DEFAULT_CMP0056:STRING=NEW
CMAKE_ON=	BUILD_TESTING ENABLE_TESTS USE_OPENCL WITH_3D WITH_ASTYLE \
		WITH_BINDINGS WITH_CUSTOM_WIDGETS WITH_INTERNAL_MDAL \
		WITH_POSTGRESQL
CMAKE_OFF=	WITH_GLOBE WITH_QWTPOLAR

.if !defined(MAINTAINER_MODE)
CMAKE_ARGS+=	-Wno-dev
CMAKE_OFF+=	SUPPRESS_QT_WARNINGS
.endif

CONFLICTS_INSTALL=	qgis

PLIST_SUB=	DISTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		GRASS SERVER
OPTIONS_DEFAULT=	GRASS SERVER
NO_OPTIONS_SORT=	yes

OPTIONS_SUB=		yes
SERVER_DESC=		Enable QGIS server

GRASS_BUILD_DEPENDS=	grass7:databases/grass7
GRASS_RUN_DEPENDS=	${GRASS_BUILD_DEPENDS}
GRASS_CMAKE_BOOL=	WITH_GRASS7
SERVER_LIB_DEPENDS=	libfcgi.so:www/fcgi
SERVER_CMAKE_BOOL=	WITH_SERVER WITH_SERVER_PLUGINS WITH_QSPATIALITE

.include <bsd.port.pre.mk>

post-patch:
# On i386, '-mllvm -inline-threshold=128' does not build under all circumstances
# See bugs 242557 and 241687.
.if ${OPSYS} == FreeBSD && ${ARCH} == "i386"
	@${REINPLACE_CMD} -e 's|"-mllvm -inline-threshold=128"|"-O1"|g' \
		${WRKSRC}/src/core/CMakeLists.txt
.endif
	@${REINPLACE_CMD} -e 's|%%PYQT_SIPDIR%%|${PYQT_SIPDIR}|' \
		${WRKSRC}/cmake/FindPyQt5.py \
		${WRKSRC}/cmake/FindSIP.py

pre-configure:
	${MKDIR} ${CONFIGURE_WRKSRC}/bin && ${LN} -s ${PYTHON_CMD} ${CONFIGURE_WRKSRC}/bin/python3

post-install:
	@${RM} ${STAGEDIR}${DATADIR}/python/pytz/tzfile.py.bak
	@${FIND} ${STAGEDIR}${LOCALBASE} -name "__pycache__" -delete
	@${RM} /tmp/srs.db

check:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.post.mk>
