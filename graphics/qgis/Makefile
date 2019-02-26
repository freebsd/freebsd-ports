# Created by: Laurent Courty
# $FreeBSD$

PORTNAME=	qgis
DISTVERSIONPREFIX=	final-
DISTVERSION=	3_6_0
CATEGORIES=	graphics geography

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	Free and Open Source Geographic Information System

LICENSE=	GPLv2

BUILD_DEPENDS=	gpsbabel>=1.5.4:astro/gpsbabel \
		txt2tags:textproc/txt2tags \
		${PYTHON_PKGNAMEPREFIX}cycler>=0.10.0:devel/py-cycler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.7.3:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.17.1:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.11.3:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>=1.0:textproc/py-MarkupSafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.1.2:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=2.0.0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}OWSLib>=0.17.0:graphics/py-OWSLib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=3.1.1:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=9.0.3:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plotly>=3.0.2:graphics/py-plotly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.2.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproj>=1.9.5.1:graphics/py-pyproj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2018.7:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18.4:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7.15:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.13:devel/py-yaml@${PY_FLAVOR}
RUN_DEPENDS=	astyle:devel/astyle \
		${PYTHON_PKGNAMEPREFIX}cycler>=0.10.0:devel/py-cycler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.7.3:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.17.1:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gdal>=2.2.4:graphics/py-gdal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.11.3:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>=1.0:textproc/py-MarkupSafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.1.2:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=2.0.0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.11.2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}OWSLib>=0.17.0:graphics/py-OWSLib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=3.1.1:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=9.0.3:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plotly>=3.0.2:graphics/py-plotly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.7.6.1:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.2.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproj>=1.9.5.1:graphics/py-pyproj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2018.7:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18.4:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7.15:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=1.1.0:devel/py-termcolor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.13:devel/py-yaml@${PY_FLAVOR}
LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		libexpat.so:textproc/expat2 \
		libgdal.so:graphics/gdal \
		libgeos.so:graphics/geos \
		libgsl.so:math/gsl \
		libhdf5.so:science/hdf5 \
		libnetcdf.so:science/netcdf \
		libproj.so:graphics/proj \
		libqca-qt5.so:devel/qca@qt5 \
		libqjson-qt5.so:devel/qjson@qt5 \
		libqscintilla2_qt5.so:devel/qscintilla2-qt5 \
		libqt5keychain.so:security/qtkeychain@qt5 \
		libqwt6.so:x11-toolkits/qwt6@qt5 \
		libspatialindex.so:devel/spatialindex \
		libspatialite.so:databases/spatialite \
		libxerces-c.so:textproc/xerces-c3 \
		libzip.so:archivers/libzip

### Fortran is needed by numpy, GRASS, etc.
USES=		bison cmake compiler:features cpe desktop-file-utils \
		fortran gmake pgsql pyqt:5 python:3.6+ qt:5 shebangfix \
		sqlite:3
USE_QT=		3d buildtools_build core concurrent dbus declarative \
		designer doc gui linguist_build location network \
		printsupport qmake_build script serialport \
		sql sql-pgsql sql-sqlite3 svg testlib uitools \
		webengine widgets webkit xml
USE_PYQT=	core gui network qml qscintilla2 sip sql svg xml webkit_run
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME:tu}

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING=Release \
		-DPYRCC_PROGRAM:FILEPATH=${LOCALBASE}/bin/pyrcc5-${PYTHON_VER} \
		-DPYUIC_PROGRAM:FILEPATH=${LOCALBASE}/bin/pyuic5-${PYTHON_VER} \
		-DQSCI_SIP_DIR:PATH=${PYQT_SIPDIR}/Qsci \
		-DQWT_INCLUDE_DIR:PATH=${LOCALBASE}/include/qt5/qwt6 \
		-DQWT_LIBRARY:FILEPATH=${LOCALBASE}/lib/qt5/libqwt6.so
CMAKE_ON=	BUILD_TESTING ENABLE_TESTS WITH_3D WITH_ASTYLE \
		WITH_BINDINGS WITH_CUSTOM_WIDGETS WITH_POSTGRESQL
CMAKE_OFF=	WITH_GLOBE WITH_QWTPOLAR

.if !defined(MAINTAINER_MODE)
CMAKE_ARGS+=	-Wno-dev
CMAKE_OFF+=	SUPPRESS_QT_WARNINGS
.endif

SHEBANG_FILES=	src/plugins/grass/scripts/*.py

OPTIONS_DEFINE=		GRASS SERVER
OPTIONS_DEFAULT=	GRASS
NO_OPTIONS_SORT=	yes

OPTIONS_SUB=		yes
SERVER_DESC=		Enable QGIS server

GRASS_BUILD_DEPENDS=	grass7:databases/grass7
GRASS_RUN_DEPENDS=	${GRASS_BUILD_DEPENDS}
GRASS_CMAKE_BOOL=	WITH_GRASS7
GRASS_FORCE_MAKE_JOBS=	NO

SERVER_LIB_DEPENDS=	libfcgi.so:www/fcgi
SERVER_CMAKE_BOOL=	WITH_SERVER

PLIST_SUB=	DISTVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|markupsafe ||g' \
		${WRKSRC}/python/ext-libs/CMakeLists.txt

pre-configure:
	${MKDIR} ${CONFIGURE_WRKSRC}/bin && ${LN} -s ${PYTHON_CMD} ${CONFIGURE_WRKSRC}/bin/python3

post-install:
	@${RM} ${STAGEDIR}${DATADIR}/python/pytz/tzfile.py.bak
	@${RM} /tmp/srs.db

check:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
