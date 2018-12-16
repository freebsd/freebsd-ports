# $FreeBSD$
#
# Handle PyQt related ports
#
# Feature:	pyqt
# Usage:	USES=pyqt:ARGS
# Valid ARGS:	4,5
#
# MAINTAINER:	kde@FreeBSD.org
#
# Internal Port variables for PyQt ports:
# PYQT_DIST	- This port is part of PyQt4/5 itself. Variables and
#		targets are then set assuming a certain tarball and
#		port layout.
# USE_PYQT	- List of PyQt components to depend on
#		* foo_build    only build depend
#		* foo_run      only run depend
#		* foo          both (default)
# PYQT_SIPDIR	- where sip files will be installed to
# PYQT_APIDIR	- where api files will be installed to
# PYQT_DOCDIR	- where doc files will be installed to
# PYQT_EXAMPLESDIR	- where examples will be installed to

.if !defined(_INCLUDE_USES_PYQT_MK)
_INCLUDE_USES_PYQT_MK=	yes

# At the moment we support PyQt bindings versions 4 and 5, sip
# option is for internal use by the py-sip ports.
_PYQT_SUPPORTED=        4 5 sip

.if empty(pyqt_ARGS)
IGNORE=	pyqt needs a qt-version (${_PYQT_SUPPORTED})
.endif

# At the moment we support PyQt bindings versions 4 and 5
.for ver in ${_PYQT_SUPPORTED:O:u}
.  if ${pyqt_ARGS:M${ver}}
.    if empty(_PYQT_VERSION)
_PYQT_VERSION=  ${ver}
.    else
IGNORE?=        cannot be installed: different PYQT versions specified via pyqt:[${_PYQT_SUPPORTED:S/ //g}]
.    endif
.  endif
.endfor

.if empty(_PYQT_VERSION)
IGNORE?=        USES=pyqt needs a version number (valid values: ${_PYQT_SUPPORTED})
.endif

PYQT_MAINTAINER=	kde@FreeBSD.org

MASTER_SITE_RIVERBANK=	http://www.riverbankcomputing.com/static/Downloads/%SUBDIR%/

MASTER_SITES_SIP=	SF/pyqt/sip/sip-${PORTVERSION} \
			GENTOO
MASTER_SITES_PYQT4=	SF/pyqt/PyQt4/PyQt-${PORTVERSION} \
			GENTOO
MASTER_SITES_PYQT5=	SF/pyqt/PyQt5/PyQt-${PORTVERSION} \
			GENTOO
MASTER_SITES_QSCI2=	SF/pyqt/QScintilla2/QScintilla-${PORTVERSION} \
			GENTOO

SIP_VERSION=		4.19.13
QSCI2_VERSION=		2.10.8
PYQT4_VERSION=		4.12.1
PYQT5_VERSION=		5.11.3

SIP_DISTNAME=		sip-${SIP_VERSION}
PYQT4_DISTNAME=		PyQt4_gpl_x11-${PYQT4_VERSION}
PYQT4_DISTINFO_FILE=	${.CURDIR:H:H}/devel/${PYQT_RELNAME}/distinfo
PYQT5_DISTNAME=		PyQt5_gpl-${PYQT5_VERSION}
PYQT5_DISTINFO_FILE=	${.CURDIR:H:H}/devel/${PYQT_RELNAME}/distinfo
QSCI2_DISTNAME=		QScintilla_gpl-${QSCI2_VERSION}
PYQT4_LICENSE=		GPLv3
PYQT5_LICENSE=		GPLv3

# Keep these synchronized with OPTIONS_DEFINE in devel/py-qt4 and devel/py-qt5
# PyQt components split up into pyqt4/pyqt5/...
_USE_PYQT_ALL=		core dbus dbussupport demo designer designerplugin \
			gui multimedia network opengl qscintilla2 \
			sql svg test webkit xml xmlpatterns sip
# List of components only in pyqt4
_USE_PYQT4_ONLY=	assistant declarative doc \
			help phonon script scripttools
# List of components only in pyqt5
_USE_PYQT5_ONLY=	multimediawidgets printsupport qml quickwidgets \
			serialport webchannel webengine webkitwidgets widgets

# Unversioned variables for the rest of the file
PYQT_VERSION=		${PYQT${_PYQT_VERSION}_VERSION}
PYQT_RELNAME=		py-qt${_PYQT_VERSION}
PYQT_PY_RELNAME=	${PYTHON_PKGNAMEPREFIX}qt${_PYQT_VERSION}
PYQT_MASTERSITES=	${MASTER_SITES_PYQT${_PYQT_VERSION}}
PYQT_DISTNAME=		${PYQT${_PYQT_VERSION}_DISTNAME}
PYQT_DISTINFO_FILE=	${PYQT${_PYQT_VERSION}_DISTINFO_FILE}
PYQT_LICENSE=		${PYQT${_PYQT_VERSION}_LICENSE}

py-sip_PATH=		${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}

py-assistant_PATH=	${PYQT_PY_RELNAME}-assistant>=${PYQT_VERSION}
py-core_PATH=		${PYQT_PY_RELNAME}-core>=${PYQT_VERSION}
py-dbus_PATH=		${PYQT_PY_RELNAME}-dbus>=${PYQT_VERSION}
py-dbussupport_PATH=	${PYQT_PY_RELNAME}-dbussupport>=${PYQT_VERSION}
py-declarative_PATH=	${PYQT_PY_RELNAME}-declarative>=${PYQT_VERSION}
py-demo_PATH=		${PYQT_PY_RELNAME}-demo>=${PYQT_VERSION}
py-designer_PATH=	${PYQT_PY_RELNAME}-designer>=${PYQT_VERSION}
py-designerplugin_PATH=	${PYQT_PY_RELNAME}-designerplugin>=${PYQT_VERSION}
py-doc_PATH=		${PYQT_PY_RELNAME}-doc>=${PYQT_VERSION}
py-gui_PATH=		${PYQT_PY_RELNAME}-gui>=${PYQT_VERSION}
py-help_PATH=		${PYQT_PY_RELNAME}-help>=${PYQT_VERSION}
py-multimedia_PATH=	${PYQT_PY_RELNAME}-multimedia>=${PYQT_VERSION}
py-network_PATH=	${PYQT_PY_RELNAME}-network>=${PYQT_VERSION}
py-opengl_PATH=		${PYQT_PY_RELNAME}-opengl>=${PYQT_VERSION}
py-phonon_PATH=		${PYQT_PY_RELNAME}-phonon>=${PYQT_VERSION}
py-qscintilla2_PATH=	${PYQT_PY_RELNAME}-qscintilla2>=${QSCI2_VERSION}
py-script_PATH=		${PYQT_PY_RELNAME}-script>=${PYQT_VERSION}
py-scripttools_PATH=	${PYQT_PY_RELNAME}-scripttools>=${PYQT_VERSION}
py-sql_PATH=		${PYQT_PY_RELNAME}-sql>=${PYQT_VERSION}
py-svg_PATH=		${PYQT_PY_RELNAME}-svg>=${PYQT_VERSION}
py-test_PATH=		${PYQT_PY_RELNAME}-test>=${PYQT_VERSION}
py-webchannel_PATH=	${PYQT_PY_RELNAME}-webchannel>=${PYQT_VERSION}
py-webengine_PATH=	${PYQT_PY_RELNAME}-webengine>=${PYQT_VERSION}
py-webkit_PATH=		${PYQT_PY_RELNAME}-webkit>=${PYQT_VERSION}
py-xml_PATH=		${PYQT_PY_RELNAME}-xml>=${PYQT_VERSION}
py-xmlpatterns_PATH=	${PYQT_PY_RELNAME}-xmlpatterns>=${PYQT_VERSION}

py-multimediawidgets_PATH=	${PYQT_PY_RELNAME}-multimediawidgets>=${PYQT_VERSION}
py-qml_PATH=			${PYQT_PY_RELNAME}-qml>=${PYQT_VERSION}
py-quickwidgets_PATH=		${PYQT_PY_RELNAME}-quickwidgets>=${PYQT_VERSION}
py-printsupport_PATH=		${PYQT_PY_RELNAME}-printsupport>=${PYQT_VERSION}
py-serialport_PATH=		${PYQT_PY_RELNAME}-serialport>=${PYQT_VERSION}
py-webkitwidgets_PATH=		${PYQT_PY_RELNAME}-webkitwidgets>=${PYQT_VERSION}
py-widgets_PATH=		${PYQT_PY_RELNAME}-widgets>=${PYQT_VERSION}

py-sip_PORT=		devel/py-sip

py-assistant_PORT=	devel/${PYQT_RELNAME}-assistant
py-core_PORT=		devel/${PYQT_RELNAME}-core
py-dbus_PORT=		devel/${PYQT_RELNAME}-dbus
py-dbussupport_PORT=	devel/${PYQT_RELNAME}-dbussupport
py-declarative_PORT=	devel/${PYQT_RELNAME}-declarative
py-demo_PORT=		misc/${PYQT_RELNAME}-demo
py-designer_PORT=	devel/${PYQT_RELNAME}-designer
py-designerplugin_PORT=	devel/${PYQT_RELNAME}-designerplugin
py-doc_PORT=		misc/${PYQT_RELNAME}-doc
py-gui_PORT=		x11-toolkits/${PYQT_RELNAME}-gui
py-help_PORT=		devel/${PYQT_RELNAME}-help
py-multimedia_PORT=	multimedia/${PYQT_RELNAME}-multimedia
py-network_PORT=	net/${PYQT_RELNAME}-network
py-opengl_PORT=		x11/${PYQT_RELNAME}-opengl
py-phonon_PORT=		multimedia/${PYQT_RELNAME}-phonon
py-qscintilla2_PORT=	devel/${PYQT_RELNAME}-qscintilla2
py-script_PORT=		devel/${PYQT_RELNAME}-script
py-scripttools_PORT=	devel/${PYQT_RELNAME}-scripttools
py-sql_PORT=		databases/${PYQT_RELNAME}-sql
py-svg_PORT=		graphics/${PYQT_RELNAME}-svg
py-test_PORT=		devel/${PYQT_RELNAME}-test
py-webchannel_PORT=	www/${PYQT_RELNAME}-webchannel
py-webengine_PORT=	www/${PYQT_RELNAME}-webengine
py-webkit_PORT=		www/${PYQT_RELNAME}-webkit
py-xml_PORT=		textproc/${PYQT_RELNAME}-xml
py-xmlpatterns_PORT=	textproc/${PYQT_RELNAME}-xmlpatterns

py-multimediawidgets_PORT=	multimedia/py-qt5-multimediawidgets
py-qml_PORT=			lang/py-qt5-qml
py-quickwidgets_PORT=		x11-toolkits/py-qt5-quickwidgets
py-printsupport_PORT=		print/py-qt5-printsupport
py-serialport_PORT=		comms/py-qt5-serialport
py-webkitwidgets_PORT=		www/py-qt5-webkitwidgets
py-widgets_PORT=		x11-toolkits/py-qt5-widgets

py-assistant_DESC=	Python bindings for QtAssistant module
py-core_DESC=		Python bindings for QtCore module
py-dbus_DESC=		Python bindings for QtDBus module
py-dbussupport_DESC=	Qt event loop support for dbus-python
py-declarative_DESC=	Python bindings for QtDeclarative module
py-demo_DESC=		PyQt demo and examples
py-designer_DESC=	Python bindings for QtDesigner module
py-designerplugin_DESC=	Python bindings for QtDesigner plugin
py-doc_DESC=		PyQt documentation
py-gui_DESC=		Python bindings for QtGui module
py-help_DESC=		Python bindings for QtHelp module
py-multimedia_DESC=	Python bindings for Multimedia module
py-network_DESC=	Python bindings for QtNetwork module
py-opengl_DESC=		Python bindings for QtOpenGL module
py-phonon_DESC=		Python bindings for Phonon module
py-qscintilla2_DESC=	Python bindings for QScintilla2
py-script_DESC=		Python bindings for QtScript module
py-scripttools_DESC=	Python bindings for QtScriptTools module
py-sql_DESC=		Python bindings for QtSql module
py-svg_DESC=		Python bindings for QtSvg module
py-test_DESC=		Python bindings for QtTest module
py-webchannel_DESC=	Python bindings for QtWebChannel module
py-webengine_DESC=	Python bindings for QtWebEngine module
py-webkit_DESC=		Python bindings for QtWebKit module
py-xml_DESC=		Python bindings for QtXml module
py-xmlpatterns_DESC=	Python bindings for QtXmlPatterns module

py-multimediawidgets_DESC=	Python bindings for QtMultimediaWidgets module
py-qml_DESC=			Python bindings for Qml module
py-quickwidgets_DESC=		Python bindings for QtQuickWidgets module
py-printsupport_DESC=		Python bindings for Printsupport module
py-serialport_DESC=		Python bindings for QtSerialPort
py-webkitwidgets_DESC=		Python bindings for QtWebKitWidgets module
py-widgets_DESC=		Python bindings for QTWidgets module

# The versionned executable of sip
SIP=		${LOCALBASE}/bin/sip-${PYTHON_VER}

# Relative directories
_VERSION_SUBDIR_REL=	PyQt${_PYQT_VERSION}/${PYTHON_VER}
_APIDIR_REL=	share/${_VERSION_SUBDIR_REL}/qsci
_DOCDIR_REL=	share/doc/${_VERSION_SUBDIR_REL}
_EXAMPLEDIR_REL=	share/examples/${_VERSION_SUBDIR_REL}
_SIPDIR_REL=	share/${_VERSION_SUBDIR_REL}/sip
_DESIGNERDIR_REL=	${QT_PLUGINDIR_REL}/designer/${_VERSION_SUBDIR_REL}
_QMLDIR_REL=		${QT_QMLDIR_REL}/${_VERSION_SUBDIR_REL}

# Absolute direcotries
PYQT_APIDIR=		${PREFIX}/${_APIDIR_REL}
PYQT_DOCDIR=		${PREFIX}/${_DOCDIR_REL}
PYQT_EXAMPLEDIR=	${PREFIX}/${_EXAMPLEDIR_REL}
PYQT_SIPDIR=		${PREFIX}/${_SIPDIR_REL}
PYQT_DESIGNERDIR=	${PREFIX}/${_DESIGNERDIR_REL}
PYQT_QMLDIR=		${PREFIX}/${_QMLDIR_REL}

PLIST_SUB+=	PYQT_APIDIR=${_APIDIR_REL} \
		PYQT_DOCDIR=${_DOCDIR_REL} \
		PYQT_EXAMPLEDIR=${_EXAMPLEDIR_REL} \
		PYQT_SIPDIR=${_SIPDIR_REL} \
		PYQT_DESIGNERDIR=${_DESIGNERDIR_REL} \
		PYQT_QMLDIR=${_QMLDIR_REL}

.if defined(PYQT_DIST)
PORTVERSION=	${PYQT_VERSION}
MASTER_SITES=	${PYQT_MASTERSITES}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQT_DISTNAME}
DISTINFO_FILE=	${PYQT_DISTINFO_FILE}
LICENSE?=	${PYQT_LICENSE}
HAS_CONFIGURE=	yes

.if ${_PYQT_VERSION} > 4
# PyQt5's configure.py generates .pro files and calls qmake to generate the
# Makefiles. qmake's Makefiles use INSTALL_ROOT instead of DESTDIR.
DESTDIRNAME=	INSTALL_ROOT
# Limit PyQt5's version to the Qt5 version in ports
PORTSCOUT?=	limit:^${_QT_VERSION:R}
.endif

PATCHDIR=	${.CURDIR}/../../devel/${PYQT_RELNAME}-core/files
CONFIGURE_ARGS+=-b ${PREFIX}/bin \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-q ${QMAKE} \
		--confirm-license \
		--sip ${SIP} \
		--sipdir ${PYQT_SIPDIR}
.if ${_PYQT_VERSION:M5}
# Move the designer plugin and qml libraries to versioned folders.
CONFIGURE_ARGS+=--qml-plugindir ${PYQT_QMLDIR} \
		--designer-plugindir ${PYQT_DESIGNERDIR}
# Further do not gernate the dinstinfo files.
CONFIGURE_ARGS+=--no-dist-info
.endif
# One of the things PyQt looks for to determine whether to build the Qt DBus
# main loop module (${PYQT_RELNAME}-dbussupport) is whether the dbus/ directory is
# present. Only extract it for that port then.
.if ${PORTNAME} != "dbussupport"
EXTRACT_AFTER_ARGS+=	--exclude "${DISTNAME}/dbus"
.endif  # ${PORTNAME} != "dbussupport"

.if !target(do-configure)
do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${PYTHON_CMD} configure.py ${CONFIGURE_ARGS}
.endif  # !target(do-configure)
.endif  # defined(PYQT_DIST)

# Set build and run depends -- we need to prefix them internally with "py-"
# else we conflict with the ones defined in bsd.qt.mk with the same name
_USE_PYQT_ALL+=			${_USE_PYQT${_PYQT_VERSION}_ONLY}
.for comp in ${_USE_PYQT_ALL:O:u}
_USE_PYQT_ALL_SUFFIXED+=		py-${comp} py-${comp}_build py-${comp}_run
py-${comp}_BUILD_DEPENDS?=		${py-${comp}_PATH}:${py-${comp}_PORT}@${PY_FLAVOR}
py-${comp}_RUN_DEPENDS?=		${py-${comp}_PATH}:${py-${comp}_PORT}@${PY_FLAVOR}
py-${comp}_build_BUILD_DEPENDS?=	${py-${comp}_BUILD_DEPENDS}
py-${comp}_run_RUN_DEPENDS?=		${py-${comp}_RUN_DEPENDS}
.endfor

_USE_PYQT=      ${USE_PYQT:O:u}
.for comp in ${_USE_PYQT}
.  if ${_USE_PYQT_ALL_SUFFIXED:Mpy-${comp}}
BUILD_DEPENDS+=		${py-${comp}_BUILD_DEPENDS}
RUN_DEPENDS+=		${py-${comp}_RUN_DEPENDS}
.  else
IGNORE?=	cannot be installed: unknown USE_PYQT component ${comp} #'
.  endif
.endfor

.endif # defined(_INCLUDE_USES_PYQT_MK)
