PORTNAME=	qgis
DISTVERSION=	3.44.3
CATEGORIES=	graphics geography
MASTER_SITES=	https://qgis.org/downloads/

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Free and Open Source Geographic Information System
WWW=		https://qgis.org/en/site/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

BUILD_DEPENDS=	gpsbabel>=1.7.0:astro/gpsbabel \
		opencl>=0:devel/opencl \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}cycler>=0.11.0:devel/py-cycler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.2:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.18.2:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.20.2:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jedi>=0.18.1:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.2:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=2.1.1:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.4.3:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=4.0.3:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}OWSLib>=0.27.2:graphics/py-OWSLib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=5.10.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=22.2.2:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plotly>=4.14.3:graphics/py-plotly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.13.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproj>=3.4.0:graphics/py-pyproj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2020.5:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.28.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.16.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=3.7.16:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.4.1:devel/py-pyyaml@${PY_FLAVOR}
LIB_DEPENDS=	libabsl_log_internal_check_op.so:devel/abseil \
		libdraco.so:archivers/draco \
		libexiv2.so:graphics/exiv2 \
		libexpat.so:textproc/expat2 \
		libfreexl.so:textproc/freexl \
		libgdal.so:graphics/gdal \
		libgeos.so:graphics/geos \
		libgsl.so:math/gsl \
		libhdf5.so:science/hdf5 \
		libminizip.so:archivers/minizip \
		libnetcdf.so:science/netcdf \
		libOpenCL.so:devel/ocl-icd \
		libpdalcpp.so:math/pdal \
		libproj.so:graphics/proj \
		libprotobuf-lite.so:devel/protobuf \
		libqca-qt5.so:devel/qca@qt5 \
		libqjson-qt5.so:devel/qjson \
		libqscintilla2_qt5.so:devel/qscintilla2@qt5 \
		libqt5keychain.so:security/qtkeychain@qt5 \
		libqwt.so:x11-toolkits/qwt6@qt5 \
		librttopo.so:devel/librttopo \
		libspatialindex.so:devel/spatialindex \
		libspatialite.so:databases/spatialite \
		libsz.so:science/libaec \
		libxerces-c.so:textproc/xerces-c3 \
		libzip.so:archivers/libzip \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	astyle:devel/astyle \
		opencl>=0:devel/opencl \
		${PYTHON_PKGNAMEPREFIX}black>=22.10:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cycler>=0.11.0:devel/py-cycler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.2:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fiona>=1.8.21:graphics/py-fiona@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.18.2:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gdal>=3.5.2:graphics/py-gdal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}geojson>=2.3.0:devel/py-geojson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}geopandas>=0.11.1:graphics/py-geopandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.20.2:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jedi>=0.18.1:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.2:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}laspy>=2.5.1:misc/py-laspy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=2.1.1:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.4.3:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=4.0.3:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>=5.7.0:devel/py-nbformat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netCDF4>=1.6.2:science/py-netCDF4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.8.8:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nltk>=3.7:textproc/py-nltk@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}OWSLib>=0.27.2:graphics/py-OWSLib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.5.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=5.10.0:devel/py-pbr@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}pip>=22.2.2:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plotly>=4.14.3:graphics/py-plotly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.9.2:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.9.4:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.13.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproj>=3.4.0:graphics/py-pyproj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyrsgis>=0.4.1:graphics/py-pyrsgis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2020.5:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rasterio>=1.3.2:graphics/py-rasterio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.28.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>=0.19.3:graphics/py-scikit-image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.1.3:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>=1.8.5:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.16.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=3.7.16:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=2.1.0:devel/py-termcolor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xcffib>=0.11.1:x11/py-xcffib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>=2.0.1:textproc/py-xlrd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.4.1:devel/py-pyyaml@${PY_FLAVOR}

### Fortran is needed by numpy, GRASS, etc.
USES=		bison cmake compiler:features desktop-file-utils \
		fortran gl gmake gnome iconv pgsql pyqt:5 python qt:5 \
		shebangfix sqlite:3 tar:bz2
USE_GL=		gl
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_PYQT=	pyqt5 pysip qscintilla2 qtbuilder:build sip:build webengine
USE_QT=		3d buildtools:build core concurrent dbus declarative \
		designer:build qdoc:build gamepad gui linguist:build location \
		multimedia network printsupport qmake:build script serialport \
		sql sql-pgsql sql-sqlite3 svg testlib uitools:build \
		webchannel webengine widgets xml

SHEBANG_FILES=	src/plugins/grass/scripts/*.py

# Python_EXECUTABLE: Use the default version if multiple Pythons are available
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING=Release \
		-DHAVE_PGCONFIG=1 \
		-DPYRCC_PROGRAM:FILEPATH=${LOCALBASE}/bin/pyrcc5-${PYTHON_VER} \
		-DPYUIC_PROGRAM:FILEPATH=${LOCALBASE}/bin/pyuic5-${PYTHON_VER} \
		-DPython_EXECUTABLE=${PYTHON_CMD} \
		-DQSCI_SIP_DIR:PATH=${PYQT_SIPDIR}/Qsci \
		-DQWT_INCLUDE_DIR:PATH=${LOCALBASE}/include/qt5/qwt6 \
		-DQWT_LIBRARY:FILEPATH=${LOCALBASE}/lib/qt5/libqwt.so \
		-DQGIS_MANUAL_SUBDIR:PATH=share/man
CMAKE_ON=	USE_OPENCL WITH_ASTYLE WITH_BINDINGS WITH_COPC \
		WITH_CUSTOM_WIDGETS WITH_DRACO WITH_EPT \
		WITH_INTERNAL_LAZPERF WITH_INTERNAL_MDAL \
		WITH_POSTGRESQL WITH_QTWEBENGINE
CMAKE_OFF=	BUILD_WITH_QT6 ENABLE_TESTS USE_CCACHE WITH_QTWEBKIT \
		WITH_QWTPOLAR

CONFLICTS_INSTALL=	qgis-ltr

PLIST_SUB=	DISTVERSION=${PORTVERSION}

.if !defined(MAINTAINER_MODE)
CMAKE_ARGS+=	-Wno-dev
CMAKE_OFF+=	SUPPRESS_QT_WARNINGS
.endif

OPTIONS_DEFINE=		SERVER GRASS
OPTIONS_DEFAULT=	SERVER GRASS
NO_OPTIONS_SORT=	yes
OPTIONS_SUB=		yes

GRASS_DESC=		Add GRASS GIS to processing tools
SERVER_DESC=		Enable QGIS server

GRASS_BUILD_DEPENDS=	grass8:databases/grass8
GRASS_RUN_DEPENDS=	${GRASS_BUILD_DEPENDS}
GRASS_CMAKE_BOOL=	WITH_GRASS8
SERVER_LIB_DEPENDS=	libfcgi.so:www/fcgi
SERVER_CMAKE_BOOL=	WITH_SERVER WITH_SERVER_PLUGINS WITH_QSPATIALITE

.include <bsd.port.pre.mk>

pre-patch:
	# Only PostgreSQL Client headers, not Server
	@${REINPLACE_CMD} -e 's|set(POSTGRES_INCLUDE_DIR \$${PostgreSQL_INCLUDE_DIRS})|set(POSTGRES_INCLUDE ${LOCALBASE}/include)|g' \
		${WRKSRC}/cmake/FindPostgres.cmake

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/cmake/FindGRASS.cmake
# On i386, '-mllvm -inline-threshold=128' does not build under all circumstances
# See bugs 242557 and 241687.
.if ${OPSYS} == FreeBSD && ${ARCH} == "i386"
	@${REINPLACE_CMD} -e 's|"-mllvm -inline-threshold=128"|"-O1"|g' \
		${WRKSRC}/src/core/CMakeLists.txt
.endif

pre-configure:
	${MKDIR} ${CONFIGURE_WRKSRC}/bin && ${LN} -s ${PYTHON_CMD} ${CONFIGURE_WRKSRC}/bin/python3

post-install:
	@${RM} ${STAGEDIR}${DATADIR}/python/pytz/tzfile.py.bak
	@${FIND} ${STAGEDIR}${LOCALBASE} -name "__pycache__" -delete
	@${RM} /tmp/srs.db

check:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.post.mk>
