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
# SIPDIR	- Absolute path where sip files will be installed
# SIPDIR_REL	- Relative version of SIPDIR
#
# Also PYQT_SIPDIR=${SIPDIR_REL} will be added to PLIST_SUB.
#

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

SIP_VERSION=		4.17
QSCI2_VERSION=		2.9.1
PYQT4_VERSION=		4.11.4
PYQT5_VERSION=		5.5.1

SIP_DISTNAME=		sip-${SIP_VERSION}
PYQT4_DISTNAME=		PyQt-x11-gpl-${PYQT4_VERSION}
PYQT4_DISTINFO_FILE=	${.CURDIR}/../../devel/${PYQT_RELNAME}/distinfo
PYQT5_DISTNAME=		PyQt-gpl-${PYQT5_VERSION}
PYQT5_DISTINFO_FILE=	${.CURDIR}/../../devel/py-qt5/distinfo
QSCI2_DISTNAME=		QScintilla-gpl-${QSCI2_VERSION}

# PyQt components split up into pyqt4/pyqt5/...
_USE_PYQT_ALL=		core dbus dbussupport demo designer designerplugin \
			doc gui multimedia network opengl qscintilla2 \
			sql svg test webkit xml xmlpatterns sip
# List of components only in pyqt4
_USE_PYQT4_ONLY=	assistant declarative \
			help phonon script scripttools
# List of components only in pyqt5
_USE_PYQT5_ONLY=	multimediawidgets printsupport qml serialport \
			webkitwidgets widgets

# Unversioned variables for the rest of the file
PYQT_VERSION=		${PYQT${_PYQT_VERSION}_VERSION}
PYQT_RELNAME=		py-qt${_PYQT_VERSION}
PYQT_PY_RELNAME=	${PYTHON_PKGNAMEPREFIX}qt${_PYQT_VERSION}
PYQT_MASTERSITES=	${MASTER_SITES_PYQT${_PYQT_VERSION}}
PYQT_DISTNAME=		${PYQT${_PYQT_VERSION}_DISTNAME}
PYQT_DISTINFO_FILE=	${PYQT${_PYQT_VERSION}_DISTINFO_FILE}

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
py-webkit_PATH=		${PYQT_PY_RELNAME}-webkit>=${PYQT_VERSION}
py-xml_PATH=		${PYQT_PY_RELNAME}-xml>=${PYQT_VERSION}
py-xmlpatterns_PATH=	${PYQT_PY_RELNAME}-xmlpatterns>=${PYQT_VERSION}

py-multimediawidgets_PATH=	${PYQT_PY_RELNAME}-multimediawidgets>=${PYQT_VERSION}
py-qml_PATH=			${PYQT_PY_RELNAME}-qml>=${PYQT_VERSION}
py-printsupport_PATH=		${PYQT_PY_RELNAME}-printsupport>=${PYQT_VERSION}
py-serialport_PATH=		${PYQT_PY_RELNAME}-serialport>=${PYQT_VERSION}
py-webkitwidgets_PATH= 		${PYQT_PY_RELNAME}-webkitwidgets>=${PYQT_VERSION}
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
py-webkit_PORT=		www/${PYQT_RELNAME}-webkit
py-xml_PORT=		textproc/${PYQT_RELNAME}-xml
py-xmlpatterns_PORT=	textproc/${PYQT_RELNAME}-xmlpatterns

py-multimediawidgets_PORT=	multimedia/py-qt5-multimediawidgets
py-qml_PORT=			lang/py-qt5-qml
py-printsupport_PORT=		print/py-qt5-printsupport
py-serialport_PORT=		comms/py-qt5-serialport
py-webkitwidgets_PORT= 		www/py-qt5-webkitwidgets
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
py-webkit_DESC=		Python bindings for QtWebKit module
py-xml_DESC=		Python bindings for QtXml module
py-xmlpatterns_DESC=	Python bindings for QtXmlPatterns module

py-multimediawidgets_DESC=	Python bindings for QtMultimediaWidgets module
py-qml_DESC=			Python bindings for Qml module
py-printsupport_DESC=		Python bindings for Printsupport module
py-serialport_DESC=		Python bindings for QtSerialPort
py-webkitwidgets_DESC= 		Python bindings for QtWebKitWidgets module
py-widgets_DESC=		Python bindings for QTWidgets module

SIPDIR_REL=	share/py-sip/PyQt${_PYQT_VERSION}
SIPDIR=		${PREFIX}/${SIPDIR_REL}
PLIST_SUB+=	PYQT_SIPDIR=${SIPDIR_REL}

.if defined(PYQT_DIST)
PORTVERSION=	${PYQT_VERSION}
MASTER_SITES=	${PYQT_MASTERSITES}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQT_DISTNAME}
DISTINFO_FILE=	${PYQT_DISTINFO_FILE}
HAS_CONFIGURE=	yes
QT_NONSTANDARD=	yes  # Do not add unknown arguments to CONFIGURE_ARGS.

.if ${_PYQT_VERSION} > 4
# PyQt5's configure.py generates .pro files and calls qmake to generate the
# Makefiles. qmake's Makefiles use INSTALL_ROOT instead of DESTDIR.
DESTDIRNAME=	INSTALL_ROOT
.endif

PATCHDIR=	${.CURDIR}/../../devel/${PYQT_RELNAME}-core/files
QSCIDIR=	${PREFIX}/share/qt${_PYQT_VERSION}/qsci
CONFIGURE_ARGS+=-b ${PREFIX}/bin \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-q ${QMAKE} \
		--confirm-license \
		--sipdir ${SIPDIR}

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
py-${comp}_BUILD_DEPENDS?=		${py-${comp}_PATH}:${py-${comp}_PORT}
py-${comp}_RUN_DEPENDS?=		${py-${comp}_PATH}:${py-${comp}_PORT}
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
