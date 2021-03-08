# $FreeBSD$
#
# Handle PyQt related ports
#
# Feature:	pyqt
# Usage:	USES=pyqt:ARGS
# Valid ARGS:	5
#
# MAINTAINER:	kde@FreeBSD.org
#
# Internal Port variables for PyQt ports:
# PYQT_DIST	- This port is part of PyQt5 itself. Variables and
#		targets are then set assuming a certain tarball and
#		port layout.
# USE_PYQT	- List of PyQt components to depend on
#		* foo_build    only build depend
#		* foo_run      only run depend
#		* foo_test     only test depend
#		* foo          both (default)
# PYQT_SIPDIR	- where sip files will be installed to
# PYQT_APIDIR	- where api files will be installed to
# PYQT_DOCDIR	- where doc files will be installed to
# PYQT_EXAMPLESDIR	- where examples will be installed to

.if !defined(_INCLUDE_USES_PYQT_MK)
_INCLUDE_USES_PYQT_MK=	yes

# At the moment we support PyQt bindings versions 5, sip
# option is for internal use by the py-sip ports.
_PYQT_SUPPORTED=        5 sip

.  if empty(pyqt_ARGS)
IGNORE=	pyqt needs a qt-version (${_PYQT_SUPPORTED})
.  endif

# At the moment we support PyQt bindings versions 5
.  for ver in ${_PYQT_SUPPORTED:O:u}
.    if ${pyqt_ARGS:M${ver}}
.      if empty(_PYQT_VERSION)
_PYQT_VERSION=  ${ver}
.      else
IGNORE?=        cannot be installed: different PYQT versions specified via pyqt:[${_PYQT_SUPPORTED:S/ //g}]
.      endif
.    endif
.  endfor

.  if empty(_PYQT_VERSION)
IGNORE?=        USES=pyqt needs a version number (valid values: ${_PYQT_SUPPORTED})
_PYQT_VERSION=	0
.  endif

PYQT_MAINTAINER=	kde@FreeBSD.org

MASTER_SITE_RIVERBANK=	https://www.riverbankcomputing.com/static/Downloads/%SUBDIR%/

MASTER_SITES_SIP=	https://pypi.python.org/packages/source/s/sip/
MASTER_SITES_PYQT5=	https://pypi.python.org/packages/source/P/PyQt5/
MASTER_SITES_PYQTSIP=	https://pypi.python.org/packages/source/P/PyQt5-sip/
MASTER_SITES_PYQTCHART=	https://pypi.python.org/packages/source/P/PyQtChart/
MASTER_SITES_PYQTNETWORKAUTH=	https://pypi.python.org/packages/source/P/PyQtNetworkAuth/
MASTER_SITES_PYQTBUILDER=	https://pypi.io/packages/source/P/PyQt-builder/
#https://www.riverbankcomputing.com/static/Downloads/QScintilla/2.12.0/QScintilla_src-2.12.0.tar.gz
MASTER_SITES_QSCI2=	RIVERBANK/QScintilla/${PORTVERSION} \
			SF/pyqt/QScintilla2/QScintilla-${PORTVERSION} \
			GENTOO

SIP_VERSION=		5.5.0
QSCI2_VERSION=		2.12.0
PYQT5_VERSION=		5.15.3
PYQTSIP_VERSION=	12.8.1
PYQTBUILDER_VERSION=	1.9.0

SIP_DISTNAME=		sip-${SIP_VERSION}
PYQT5_DISTNAME=		PyQt5-${PYQT5_VERSION}
PYQTSIP_DISTNAME=	PyQt5_sip-${PYQTSIP_VERSION}
PYQTCHART_DISTNAME=	PyQtChart-${PYQT_VERSION}
PYQTNETWORKAUTH_DISTNAME=	PyQtNetworkAuth-${PYQT_VERSION}
PYQTBUILDER_DISTNAME=	PyQt-builder-${PYQTBUILDER_VERSION}
PYQT5_DISTINFO_FILE=	${.CURDIR:H:H}/devel/${PYQT_RELNAME}/distinfo
QSCI2_DISTNAME=		QScintilla_src-${QSCI2_VERSION}
PYQT5_LICENSE=		GPLv3

_USE_PYQT_COMMS=	sensors serialport
_USE_PYQT_DATABASES=	sql
_USE_PYQT_DEVEL=	core dbus dbussupport help location \
			designer designerplugin remoteobjects test 
_USE_PYQT_GRAPHICS=	svg
_USE_PYQT_LANG=		qml
_USE_PYQT_MISC=		demo
_USE_PYQT_MULTIMEDIA=	multimedia multimediawidgets
_USE_PYQT_NET=		network networkauth
_USE_PYQT_PRINT=	printsupport
_USE_PYQT_TEXTPROC=	xml xmlpatterns
_USE_PYQT_WWW=		webchannel webengine webkit webkitwidgets websockets
_USE_PYQT_X11=		opengl
_USE_PYQT_X11-TOOLKITS=	chart gui widgets quick quick3d quickwidgets

# Keep these synchronized with OPTIONS_DEFINE in devel/py-qt5
# PyQt components split up into pyqt5/...
_USE_PYQT_ALL=		${_USE_PYQT_COMMS} \
			${_USE_PYQT_DATABASES} \
			${_USE_PYQT_DEVEL} \
			${_USE_PYQT_GRAPHICS} \
			${_USE_PYQT_LANG} \
			${_USE_PYQT_MISC} \
			${_USE_PYQT_MULTIMEDIA} \
			${_USE_PYQT_NET} \
			${_USE_PYQT_PRINT} \
			${_USE_PYQT_TEXTPROC} \
			${_USE_PYQT_WWW} \
			${_USE_PYQT_X11} \
			${_USE_PYQT_X11-TOOLKITS}
_USE_SIP_ALL=		sip pysip
_USE_QSCINTILLA=	qscintilla2
_USE_PYQTBUILDER=	qtbuilder

# Unversioned variables for the rest of the file
PYQT_VERSION=		${PYQT${_PYQT_VERSION}_VERSION}
PYQT_RELNAME=		py-qt${_PYQT_VERSION}
PYQT_PY_RELNAME=	${PYTHON_PKGNAMEPREFIX}qt${_PYQT_VERSION}
PYQT_MASTERSITES=	${MASTER_SITES_PYQT${_PYQT_VERSION}}
PYQT_DISTNAME=		${PYQT${_PYQT_VERSION}_DISTNAME}
PYQT_DISTINFO_FILE=	${PYQT${_PYQT_VERSION}_DISTINFO_FILE}
PYQT_LICENSE=		${PYQT${_PYQT_VERSION}_LICENSE}

# PATH
py-sip_PATH=			${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}
py-pysip_PATH=			${PYQT_PY_RELNAME}-sip>=${PYQTSIP_VERSION}
py-qscintilla2_PATH=		${PYQT_PY_RELNAME}-qscintilla2>=${QSCI2_VERSION}
py-qtbuilder_PATH=		${PYTHON_PKGNAMEPREFIX}qtbuilder>=${PYQTBUILDER_VERSION}

.  for _component in ${_USE_PYQT_ALL}
py-${_component}_PATH?=${PYQT_PY_RELNAME}-${_component}>=${PYQT_VERSION}
.  endfor

# PORT
py-sip_PORT=			devel/py-sip
py-qtbuilder_PORT=		devel/py-qtbuilder
py-pysip_PORT=			devel/${PYQT_RELNAME}-sip
py-qscintilla2_PORT=		devel/${PYQT_RELNAME}-qscintilla2

.  for _categorie in comms databases devel graphics lang misc multimedia net print textproc www x11 x11-toolkits
_PYQT_CATEGORIE=	_USE_PYQT_${_categorie:tu}
.    for _component in ${${_PYQT_CATEGORIE}}
py-${_component}_PORT?=${_categorie}/${PYQT_RELNAME}-${_component}
.    endfor
.  endfor

py-core_DESC=			Python bindings for QtCore module
py-chart_DESC=			Python bindings for QtChart module
py-dbus_DESC=			Python bindings for QtDBus module
py-dbussupport_DESC=		Qt event loop support for dbus-python
py-demo_DESC=			PyQt demo and examples
py-designer_DESC=		Python bindings for QtDesigner module
py-designerplugin_DESC=		Python bindings for QtDesigner plugin
py-gui_DESC=			Python bindings for QtGui module
py-help_DESC=			Python bindings for QtHelp module
py-location_DESC=		Python bindings for Location module
py-multimedia_DESC=		Python bindings for Multimedia module
py-multimediawidgets_DESC=	Python bindings for QtMultimediaWidgets module
py-network_DESC=		Python bindings for QtNetwork module
py-networkauth_DESC=		Python bindings for QtNetworkAuth module
py-opengl_DESC=			Python bindings for QtOpenGL module
py-printsupport_DESC=		Python bindings for Printsupport module
py-qml_DESC=			Python bindings for Qml module
py-qscintilla2_DESC=		Python bindings for QScintilla2
py-quick_DESC=			Python bindings for QtQuick module
py-quick3d_DESC=		Python bindings for QtQuick3D module
py-quickwidgets_DESC=		Python bindings for QtQuickWidgets module
py-remoteobjects_DESC=		Python bindings for QtRemoteObjects module
py-sip_DESC=			Python bindings generator for C and C++ libraries
py-sensors_DESC=		Python bindings for QtSensors
py-serialport_DESC=		Python bindings for QtSerialPort
py-sql_DESC=			Python bindings for QtSql module
py-svg_DESC=			Python bindings for QtSvg module
py-test_DESC=			Python bindings for QtTest module
py-webchannel_DESC=		Python bindings for QtWebChannel module
py-webengine_DESC=		Python bindings for QtWebEngine module
py-webkit_DESC=			Python bindings for QtWebKit module
py-webkitwidgets_DESC=		Python bindings for QtWebKitWidgets module
py-widgets_DESC=		Python bindings for QTWidgets module
py-xml_DESC=			Python bindings for QtXml module
py-xmlpatterns_DESC=		Python bindings for QtXmlPatterns module

# The versionned executable of sip
SIP=		${LOCALBASE}/bin/sip5-${PYTHON_VER}

# Relative directories
_VERSION_SUBDIR_REL=	PyQt${_PYQT_VERSION}/${PYTHON_VER}
_APIDIR_REL=	share/${_VERSION_SUBDIR_REL}/qsci
_DOCDIR_REL=	share/doc/${_VERSION_SUBDIR_REL}
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

.  if defined(PYQT_DIST)
PORTVERSION=	${PYQT_VERSION}
MASTER_SITES=	${PYQT_MASTERSITES}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQT_DISTNAME}
DISTINFO_FILE=	${PYQT_DISTINFO_FILE}
LICENSE?=	${PYQT_LICENSE}
HAS_CONFIGURE=	yes

.    if ${_PYQT_VERSION} > 4
# PyQt5's configure.py generates .pro files and calls qmake to generate the
# Makefiles. qmake's Makefiles use INSTALL_ROOT instead of DESTDIR.
DESTDIRNAME=	INSTALL_ROOT
# Limit PyQt5's version to the Qt5 version in ports
PORTSCOUT?=	limit:^${_QT_VERSION:R}
.    endif

PATCHDIR=	${.CURDIR}/../../devel/${PYQT_RELNAME}-core/files
CONFIGURE_ARGS+=-b ${PREFIX}/bin \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-q ${QMAKE} \
		--confirm-license \
		--sip ${SIP} \
		--sipdir ${PYQT_SIPDIR}
.    if ${_PYQT_VERSION:M5}
# Move the designer plugin and qml libraries to versioned folders.
CONFIGURE_ARGS+=--qml-plugindir ${PYQT_QMLDIR} \
		--designer-plugindir ${PYQT_DESIGNERDIR}
# Further do not gernate the dinstinfo files.
CONFIGURE_ARGS+=--no-dist-info
.    endif
# One of the things PyQt looks for to determine whether to build the Qt DBus
# main loop module (${PYQT_RELNAME}-dbussupport) is whether the dbus/ directory is
# present. Only extract it for that port then.
.    if ${PORTNAME} != "dbussupport"
EXTRACT_AFTER_ARGS+=	--exclude "${DISTNAME}/dbus"
.    endif  # ${PORTNAME} != "dbussupport"

.    if !target(do-configure)
do-configure:
	${REINPLACE_CMD} -e "s/sip-module/sip-module-${PYTHON_VER}/" ${WRKSRC}/configure.py
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${PYTHON_CMD} configure.py ${CONFIGURE_ARGS}
.    endif  # !target(do-configure)
.  endif  # defined(PYQT_DIST)

# Set build, run and test depends -- we need to prefix them internally with "py-"
# else we conflict with the ones defined in bsd.qt.mk with the same name
_USE_PYQT_ALL+=				${_USE_SIP_ALL} \
					${_USE_QSCINTILLA} \
					${_USE_PYQTBUILDER}
.  for comp in ${_USE_PYQT_ALL:O:u}
_USE_PYQT_ALL_SUFFIXED+=		py-${comp} py-${comp}_build py-${comp}_run py-${comp}_test
py-${comp}_BUILD_DEPENDS?=		${py-${comp}_PATH}:${py-${comp}_PORT}@${PY_FLAVOR}
py-${comp}_RUN_DEPENDS?=		${py-${comp}_PATH}:${py-${comp}_PORT}@${PY_FLAVOR}
py-${comp}_TEST_DEPENDS?=		${py-${comp}_PATH}:${py-${comp}_PORT}@${PY_FLAVOR}
py-${comp}_build_BUILD_DEPENDS?=	${py-${comp}_BUILD_DEPENDS}
py-${comp}_run_RUN_DEPENDS?=		${py-${comp}_RUN_DEPENDS}
py-${comp}_test_TEST_DEPENDS?=		${py-${comp}_TEST_DEPENDS}
.  endfor

_USE_PYQT=      ${USE_PYQT:O:u}
.  for comp in ${_USE_PYQT}
.    if ${_USE_PYQT_ALL_SUFFIXED:Mpy-${comp}}
BUILD_DEPENDS+=		${py-${comp}_BUILD_DEPENDS}
RUN_DEPENDS+=		${py-${comp}_RUN_DEPENDS}
TEST_DEPENDS+=		${py-${comp}_TEST_DEPENDS}
.    else
IGNORE?=	cannot be installed: unknown USE_PYQT component ${comp} #'
.    endif
.  endfor

.endif # defined(_INCLUDE_USES_PYQT_MK)
