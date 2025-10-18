# Handle PyQt related ports
#
# Feature:	pyqt
# Usage:	USES=pyqt:<version>[,dist]
# Versions:	5, 6
# Internal use ARGS:	dist
#    This port is part of PyQt5/6 itself. Variables and
#    targets are then set assuming a certain tarball and
#    port layout.
#
# MAINTAINER:	kde@FreeBSD.org
#
# Port variables for PyQt ports:
# USE_PYQT	- List of PyQt components to depend on
#		* foo:build    only build depend
#		* foo:run      only run depend
#		* foo:test     only test depend
#		* foo          build and run depend (default)
# PYQT_SIPDIR	- where sip files will be installed to
# PYQT_APIDIR	- where api files will be installed to
# PYQT_DOCDIR	- where doc files will be installed to
# PYQT_EXAMPLESDIR	- where examples will be installed to

.if !defined(_INCLUDE_USES_PYQT_MK)
_INCLUDE_USES_PYQT_MK=	yes

# At the moment we support PyQt bindings versions 5 and 6.
# The sip argument is for internal use by devel/py-sip.
_PYQT_SUPPORTED=	5 6 sip

.  if empty(pyqt_ARGS)
IGNORE=		pyqt needs a qt-version (${_PYQT_SUPPORTED})
.  endif

.  for ver in ${_PYQT_SUPPORTED:O:u}
.    if ${pyqt_ARGS:M${ver}}
.      if empty(_PYQT_VERSION)
_PYQT_VERSION=	${ver}
.      else
IGNORE?=	cannot be installed: different PYQT versions specified via pyqt:[${_PYQT_SUPPORTED:S/ //g}]
.      endif
.    endif
.  endfor

.  if empty(_PYQT_VERSION)
IGNORE?=	USES=pyqt needs a version number (valid values: ${_PYQT_SUPPORTED})
_PYQT_VERSION=	0
.  endif

.  if ${pyqt_ARGS:Mdist}
_PYQT_DIST=	yes
.  endif

PYQT_MAINTAINER=	kde@FreeBSD.org

MASTER_SITE_RIVERBANK=	https://www.riverbankcomputing.com/static/Downloads/%SUBDIR%/
MASTER_SITE_RBDEV=	https://www.riverbankcomputing.com/pypi/packages/%SUBDIR%/

# Qt version-agnostic components
MASTER_SITES_PYQTBUILDER=	PYPI/source/P/PyQt-builder
MASTER_SITES_QSCI2=		RIVERBANK/QScintilla/${PORTVERSION} \
				SF/pyqt/QScintilla2/QScintilla-${PORTVERSION}
MASTER_SITES_SIP=		PYPI/source/s/sip

# Qt 5 components
MASTER_SITES_PYQT5SIP=		PYPI/source/P/PyQt5-sip
MASTER_SITES_PYQT5=		PYPI/source/P/PyQt5
MASTER_SITES_PYQT53D=		PYPI/source/P/PyQt3D
MASTER_SITES_PYQT5CHARTS=	PYPI/source/P/PyQtChart
MASTER_SITES_PYQT5DATAVIS3D=	PYPI/source/P/PyQtDataVisualization
MASTER_SITES_PYQT5NETWORKAUTH=	PYPI/source/P/PyQtNetworkAuth
MASTER_SITES_PYQT5WEBENGINE=	PYPI/source/P/PyQtWebEngine

# Qt 6 components
MASTER_SITES_PYQT6SIP=		PYPI/source/P/PyQt6-sip
MASTER_SITES_PYQT6=		PYPI/source/P/PyQt6 \
				RBDEV/PyQt6
MASTER_SITES_PYQT63D=		PYPI/source/P/PyQt6-3D \
				RBDEV/PyQt6-3D
MASTER_SITES_PYQT6CHARTS=	PYPI/source/P/PyQt6-Charts \
				RBDEV/PyQt6-Charts
MASTER_SITES_PYQT6DATAVIS3D=	PYPI/source/P/PyQt6-DataVisualization \
				RBDEV/PyQt6-DataVisualization
MASTER_SITES_PYQT6GRAPHS=	PYPI/source/P/PyQt6-Graphs \
				RBDEV/PyQt6-Graphs
MASTER_SITES_PYQT6NETWORKAUTH=	PYPI/source/P/PyQt6-NetworkAuth \
				RBDEV/PyQt6-NetworkAuth
MASTER_SITES_PYQT6WEBENGINE=	PYPI/source/P/PyQt6-WebEngine \
				RBDEV/PyQt6-WebEngine

# Unversioned MASTER_SITES
MASTER_SITES_PYQT=		${MASTER_SITES_PYQT${_PYQT_VERSION}}
MASTER_SITES_PYQTSIP=		${MASTER_SITES_PYQT${_PYQT_VERSION}SIP}
MASTER_SITES_PYQT3D=		${MASTER_SITES_PYQT${_PYQT_VERSION}3D}
MASTER_SITES_PYQTCHARTS=	${MASTER_SITES_PYQT${_PYQT_VERSION}CHARTS}
MASTER_SITES_PYQTDATAVIS3D=	${MASTER_SITES_PYQT${_PYQT_VERSION}DATAVIS3D}
MASTER_SITES_PYQTGRAPHS=	${MASTER_SITES_PYQT${_PYQT_VERSION}GRAPHS}
MASTER_SITES_PYQTNETWORKAUTH=	${MASTER_SITES_PYQT${_PYQT_VERSION}NETWORKAUTH}
MASTER_SITES_PYQTWEBENGINE=	${MASTER_SITES_PYQT${_PYQT_VERSION}WEBENGINE}

# PORTEPOCH is important here, because version-comparisons in *_DEPENDS
# take it into account (visually, 6.5.1 >= 5.5.3,1, but it isn't).
# Adding the epoch directly into the version here cannot be done,
# because the DISTVERSION of each of these ports is obtained from the
# *_VERSION variable (and PORTEPOCH is set in each individual port).
#
# Where noted, the ports are epoched and the py-${comp}-PATH variables,
# below, should have a suitable epoch appended to the version.

# Qt version-agnostic components
PYQTBUILDER_VERSION=		1.19.0
QSCI2_VERSION=			2.14.1
SIP_VERSION=			6.13.1	# ,1

# Qt 5 components
PYQT5SIP_VERSION=		12.17.0
PYQT5_VERSION=			5.15.11
PYQT53D_VERSION=		5.15.7
PYQT5CHARTS_VERSION=		5.15.7
PYQT5DATAVIS3D_VERSION=		5.15.6
PYQT5NETWORKAUTH_VERSION=	5.15.6
PYQT5WEBENGINE_VERSION=		5.15.7

# Qt 6 components
PYQT6SIP_VERSION=		13.10.2
PYQT6_VERSION=			6.9.1
PYQT63D_VERSION=		6.9.0
PYQT6CHARTS_VERSION=		6.9.0
PYQT6DATAVIS3D_VERSION=		6.9.0
PYQT6GRAPHS_VERSION=		6.9.0
PYQT6NETWORKAUTH_VERSION=	6.9.0
PYQT6WEBENGINE_VERSION=		6.9.0

# Qt version-agnostic components
PYQTBUILDER_DISTNAME=		pyqt_builder-${PYQTBUILDER_VERSION}
QSCI2_DISTNAME=			QScintilla_src-${QSCI2_VERSION}

# Qt 5 components
PYQT5SIP_DISTNAME=		pyqt5_sip-${PYQT5SIP_VERSION}
PYQT5_DISTNAME=			PyQt5-${PYQT5_VERSION}
PYQT53D_DISTNAME=		PyQt3D-${PYQT53D_VERSION}
PYQT5CHARTS_DISTNAME=		PyQtChart-${PYQT5CHARTS_VERSION}
PYQT5DATAVIS3D_DISTNAME=	PyQtDataVisualization-${PYQT5DATAVIS3D_VERSION}
PYQT5NETWORKAUTH_DISTNAME=	PyQtNetworkAuth-${PYQT5NETWORKAUTH_VERSION}
PYQT5WEBENGINE_DISTNAME=	PyQtWebEngine-${PYQT5WEBENGINE_VERSION}

# Qt 6 components
PYQT6SIP_DISTNAME=		pyqt6_sip-${PYQT6SIP_VERSION}
PYQT6_DISTNAME=			pyqt6-${PYQT6_VERSION}
PYQT63D_DISTNAME=		pyqt6_3d-${PYQT63D_VERSION}
PYQT6CHARTS_DISTNAME=		pyqt6_charts-${PYQT6CHARTS_VERSION}
PYQT6DATAVIS3D_DISTNAME=	pyqt6_datavisualization-${PYQT6DATAVIS3D_VERSION}
PYQT6GRAPHS_DISTNAME=		pyqt6_graphs-${PYQT6GRAPHS_VERSION}
PYQT6NETWORKAUTH_DISTNAME=	pyqt6_networkauth-${PYQT6NETWORKAUTH_VERSION}
PYQT6WEBENGINE_DISTNAME=	pyqt6_webengine-${PYQT6WEBENGINE_VERSION}

PYQT5_DISTINFO_FILE=	${.CURDIR:H:H}/devel/${PYQT_RELNAME}/distinfo
PYQT6_DISTINFO_FILE=	${.CURDIR:H:H}/devel/${PYQT_RELNAME}/distinfo

PYQT5_LICENSE=		GPLv3
PYQT6_LICENSE=		GPLv3

_USE_PYQT_ALL=		pyqt5 pyqt6 3d charts graphs datavis3d networkauth webengine
_USE_SIP_ALL=		pysip sip
_USE_QSCINTILLA=	qscintilla2
_USE_PYQTBUILDER=	qtbuilder

# Unversioned variables for the rest of the file
PYQTSIP_VERSION=		${PYQT${_PYQT_VERSION}SIP_VERSION}
PYQT_VERSION=			${PYQT${_PYQT_VERSION}_VERSION}
PYQT3D_VERSION=			${PYQT${_PYQT_VERSION}3D_VERSION}
PYQTCHARTS_VERSION=		${PYQT${_PYQT_VERSION}CHARTS_VERSION}
PYQTDATAVIS3D_VERSION=		${PYQT${_PYQT_VERSION}DATAVIS3D_VERSION}
PYQTGRAPHS_VERSION=		${PYQT${_PYQT_VERSION}GRAPHS_VERSION}
PYQTNETWORKAUTH_VERSION=	${PYQT${_PYQT_VERSION}NETWORKAUTH_VERSION}
PYQTWEBENGINE_VERSION=		${PYQT${_PYQT_VERSION}WEBENGINE_VERSION}

PYQTSIP_DISTNAME=		${PYQT${_PYQT_VERSION}SIP_DISTNAME}
PYQT_DISTNAME=			${PYQT${_PYQT_VERSION}_DISTNAME}
PYQT3D_DISTNAME=		${PYQT${_PYQT_VERSION}3D_DISTNAME}
PYQTCHARTS_DISTNAME=		${PYQT${_PYQT_VERSION}CHARTS_DISTNAME}
PYQTDATAVIS3D_DISTNAME=		${PYQT${_PYQT_VERSION}DATAVIS3D_DISTNAME}
PYQTGRAPHS_DISTNAME=		${PYQT${_PYQT_VERSION}GRAPHS_DISTNAME}
PYQTNETWORKAUTH_DISTNAME=	${PYQT${_PYQT_VERSION}NETWORKAUTH_DISTNAME}
PYQTWEBENGINE_DISTNAME=		${PYQT${_PYQT_VERSION}WEBENGINE_DISTNAME}

PYQT_DISTINFO_FILE=		${PYQT${_PYQT_VERSION}_DISTINFO_FILE}
PYQT_LICENSE=			${PYQT${_PYQT_VERSION}_LICENSE}

PYQT_RELNAME=			py-qt${_PYQT_VERSION}
PYQT_PY_RELNAME=		${PYTHON_PKGNAMEPREFIX}qt${_PYQT_VERSION}

# PATH (see note about epochs, above)
py-sip_PATH=			${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION},1
py-pysip_PATH=			${PYTHON_PKGNAMEPREFIX}PyQt${_PYQT_VERSION}-sip>=${PYQTSIP_VERSION}
py-qscintilla2_PATH=		${PYQT_PY_RELNAME}-qscintilla2>=${QSCI2_VERSION}
py-qtbuilder_PATH=		${PYTHON_PKGNAMEPREFIX}PyQt-builder>=${PYQTBUILDER_VERSION}
py-pyqt5_PATH=			${PYQT_PY_RELNAME}-pyqt>=${PYQT_VERSION}
py-pyqt6_PATH=			${PYQT_PY_RELNAME}-pyqt>=${PYQT_VERSION}
py-3d_PATH=			${PYQT_PY_RELNAME}-3d>=${PYQT3D_VERSION}
py-charts_PATH=			${PYQT_PY_RELNAME}-charts>=${PYQTCHARTS_VERSION}
py-datavis3d_PATH=		${PYQT_PY_RELNAME}-datavis3d>=${PYQTDATAVIS3D_VERSION}
py-graphs_PATH=			${PYQT_PY_RELNAME}-graphs>=${PYQTCHART_VERSION}
py-networkauth_PATH=		${PYQT_PY_RELNAME}-networkauth>=${PYQTNETWORKAUTH_VERSION}
py-webengine_PATH=		${PYQT_PY_RELNAME}-webengine>=${PYQTWEBENGINE_VERSION}

# PORT
py-sip_PORT=			devel/py-sip
py-pysip_PORT=			devel/${PYQT_RELNAME}-sip
py-qscintilla2_PORT=		devel/${PYQT_RELNAME}-qscintilla2
py-qtbuilder_PORT=		devel/py-qtbuilder
py-pyqt5_PORT=			devel/${PYQT_RELNAME}-pyqt
py-pyqt6_PORT=			devel/${PYQT_RELNAME}-pyqt
py-3d_PORT=			graphics/${PYQT_RELNAME}-3d
py-charts_PORT=			x11-toolkits/${PYQT_RELNAME}-charts
py-datavis3d_PORT=		x11-toolkits/${PYQT_RELNAME}-datavis3d
py-graphs_PORT=			x11-toolkits/${PYQT_RELNAME}-graphs
py-networkauth_PORT=		net/${PYQT_RELNAME}-networkauth
py-webengine_PORT=		www/${PYQT_RELNAME}-webengine

# The versioned executable of sip
SIP=		${LOCALBASE}/bin/sip-build-${PYTHON_VER}

# Relative directories
_VERSION_SUBDIR_REL=	PyQt${_PYQT_VERSION}/${PYTHON_VER}
_APIDIR_REL=		share/${_VERSION_SUBDIR_REL}/qsci
_DOCDIR_REL=		share/doc/${_VERSION_SUBDIR_REL}
_EXAMPLEDIR_REL=	share/examples/${_VERSION_SUBDIR_REL}
_SIPDIR_REL=		PyQt${_PYQT_VERSION}/bindings
_DESIGNERDIR_REL=	${QT_PLUGINDIR_REL}/designer/${_VERSION_SUBDIR_REL}
_QMLDIR_REL=		${QT_QMLDIR_REL}/${_VERSION_SUBDIR_REL}

# Absolute directories
PYQT_APIDIR=		${PREFIX}/${_APIDIR_REL}
PYQT_DOCDIR=		${PREFIX}/${_DOCDIR_REL}
PYQT_EXAMPLEDIR=	${PREFIX}/${_EXAMPLEDIR_REL}
PYQT_SIPDIR?=		${PYTHON_SITELIBDIR}/${_SIPDIR_REL}
PYQT_DESIGNERDIR=	${PREFIX}/${_DESIGNERDIR_REL}
PYQT_QMLDIR=		${PREFIX}/${_QMLDIR_REL}

PLIST_SUB+=	PYQT_APIDIR=${_APIDIR_REL} \
		PYQT_DOCDIR=${_DOCDIR_REL} \
		PYQT_EXAMPLEDIR=${_EXAMPLEDIR_REL} \
		PYQT_SIPDIR=${PYQT_SIPDIR} \
		PYQT_DESIGNERDIR=${_DESIGNERDIR_REL} \
		PYQT_QMLDIR=${_QMLDIR_REL} \
		PYQT_SIPVERSION=${SIP_VERSION} \
		PYQT_QSCIVERSION=${QSCI2_VERSION} \
		PYQT_PYQTVERSION=${PYQT_VERSION}

.  if defined(_PYQT_DIST)

LICENSE?=	${PYQT_LICENSE}

PLIST_SUB+=	PYTHON_MAJOR_VER="${PYTHON_MAJOR_VER}"

SIP_ARGS+=	--qmake ${QMAKE} \
		--verbose \
		--build-dir build \
		--protected-is-public \
		--api-dir ${PYQT_APIDIR} \
		--jobs ${MAKE_JOBS_NUMBER}
.    if ${PORTNAME} == "pyqt"
SIP_ARGS+=	--confirm-license
.    endif

.    if ${PORTNAME} == "pyqt"
.      if !target(post-patch)
post-patch:
	${REINPLACE_CMD} -e "s#%%PYQT_DESIGNERDIR%%#${PYQT_DESIGNERDIR}#" ${WRKSRC}/project.py
	${REINPLACE_CMD} -e "s#%%PYQT_QMLDIR%%#${PYQT_QMLDIR}#" ${WRKSRC}/project.py
.      endif  # !target(post-patch)
.    endif

.    if !target(do-build)
do-build:
	(cd ${WRKSRC}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${SIP} ${SIP_ARGS}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} -C ./build)

.    endif  # !target(do-build)

.    if !target(do-install)
do-install:
	(cd ${WRKSRC} ; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE} -C ./build install INSTALL_ROOT=${STAGEDIR} )
.    endif  # !target(do-install)

.  endif  # defined(_PYQT_DIST)

# Set build, run and test depends -- we need to prefix them internally with "py-"
# else we conflict with the ones defined in bsd.qt.mk with the same name
_USE_PYQT_ALL+=				${_USE_SIP_ALL} \
					${_USE_QSCINTILLA} \
					${_USE_PYQTBUILDER}
.  for comp in ${_USE_PYQT_ALL:O:u}
_USE_PYQT_ALL_PREFIXED+=		py-${comp} py-${comp}:build py-${comp}:run py-${comp}:test
py-${comp}_BUILD_DEPENDS?=		${py-${comp}_PATH}:${py-${comp}_PORT}@${PY_FLAVOR}
py-${comp}_RUN_DEPENDS?=		${py-${comp}_PATH}:${py-${comp}_PORT}@${PY_FLAVOR}
py-${comp}_TEST_DEPENDS?=		${py-${comp}_PATH}:${py-${comp}_PORT}@${PY_FLAVOR}
py-${comp}_build_BUILD_DEPENDS?=	${py-${comp}_BUILD_DEPENDS}
py-${comp}_run_RUN_DEPENDS?=		${py-${comp}_RUN_DEPENDS}
py-${comp}_test_TEST_DEPENDS?=		${py-${comp}_TEST_DEPENDS}
.  endfor

_USE_PYQT=	${USE_PYQT:O:u}
.  for comp in ${_USE_PYQT}
.    if ${_USE_PYQT_ALL_PREFIXED:Mpy-${comp}}
BUILD_DEPENDS+=		${py-${comp:S/:/_/}_BUILD_DEPENDS}
RUN_DEPENDS+=		${py-${comp:S/:/_/}_RUN_DEPENDS}
TEST_DEPENDS+=		${py-${comp:S/:/_/}_TEST_DEPENDS}
.    else
IGNORE?=	cannot be installed: unknown USE_PYQT component ${comp} #'
.    endif
.  endfor

.endif # defined(_INCLUDE_USES_PYQT_MK)
