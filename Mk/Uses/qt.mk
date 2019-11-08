# $FreeBSD$
#
# There are three Qt related USES files with different access to Qt.
#   - qmake: The port requires Qt's qmake to build -- creates the configure target
#            - auto includes qt.mk
#   - qt-dist: The port is a port for a part of Qt5
#            - auto includes qt.mk and qmake.mk
#   - qt.mk  - Dependency handling. USE_QT=foo bar
#
# Usage:
#   USES=qt:<version>[,no_env]
#
#   Versions:		5
#
# Port variables:
# USE_QT		- List of Qt modules to depend on, with optional '_build'
#			  and '_run' suffixes. Define it empty to include this file
#			  without depending on Qt ports.

.if !defined(_QT_MK_INCLUDED)
_QT_MK_INCLUDED=	qt.mk

# Qt versions currently supported by the framework.
_QT_SUPPORTED?=		5
QT5_VERSION?=		5.13.2

# We accept the Qt version to be passed by either or all of the three mk files.
.  if empty(qt_ARGS) && empty(qmake_ARGS) && empty(qt-dist_ARGS)
IGNORE=			qt needs a version (${_QT_SUPPORTED}) passed via qt, qmake or qt-dist.
.  endif

# Gather all the args together
_QT_GLOBAL_ARGS=	${qt_ARGS} ${qmake_ARGS} ${qt-dist_ARGS}

# Check fo the Qt version to be used
_QT_VER=		# empty
.  for ver in ${_QT_SUPPORTED:O:u}
.    if ${_QT_GLOBAL_ARGS:M${ver}}
.      if !defined(_QT_VERSION)
_QT_VER=		${ver}
.      else
.        if ${_QT_VERSION} != ${ver}
IGNORE?=		cannot be installed: different Qt versions specified via qt:[${_QT_SUPPORTED:S/ //g}], qmake:[${_QT_SUPPORTED:S/ //g}] a qt-dist:[${_QT_SUPPORTED:S/ //g}]
.        endif
.      endif
.    endif
.  endfor

.  if empty(_QT_VER)
IGNORE?=		cannot decide what Qt version to use: specify one via qt:[${_QT_SUPPORTED:S/ //g}], qmake:[${_QT_SUPPORTED:S/ //g}] or qt-dist:[${_QT_SUPPORTED:S/ //g}]
.  endif

# Set the shortcuts used from now on
_QT_RELNAME=		qt${_QT_VER}
_QT_VERSION=		${QT${_QT_VER}_VERSION}

# A wrapper (qtchooser) is used to invoke binaries.
QT_BINDIR_REL?=		${QT_ARCHDIR_REL}/bin
QT_INCDIR_REL?=		include/${_QT_RELNAME}
QT_LIBDIR_REL?=		lib/${_QT_RELNAME}
QT_ARCHDIR_REL?=	${QT_LIBDIR_REL}
QT_PLUGINDIR_REL?=	${QT_ARCHDIR_REL}/plugins
QT_LIBEXECDIR_REL?=	libexec/${_QT_RELNAME}
QT_IMPORTDIR_REL?=	${QT_ARCHDIR_REL}/imports
QT_QMLDIR_REL?=		${QT_ARCHDIR_REL}/qml
QT_DATADIR_REL?=	share/${_QT_RELNAME}
QT_DOCDIR_REL?=		share/doc/${_QT_RELNAME}
QT_L10NDIR_REL?=	${QT_DATADIR_REL}/translations
QT_ETCDIR_REL?=		etc/xdg
QT_EXAMPLEDIR_REL?=	share/examples/${_QT_RELNAME}
QT_TESTDIR_REL?=	${QT_DATADIR_REL}/tests
QT_CMAKEDIR_REL?=	lib/cmake
QT_QTCHOOSERDIR_REL?=	${QT_ETCDIR_REL}/qtchooser

# Not customizable.
QT_MKSPECDIR_REL=	${QT_ARCHDIR_REL}/mkspecs
_QT_LIBVER=		${_QT_VERSION:R:R}

LRELEASE?=		${QT_BINDIR}/lrelease
LUPDATE?=		${QT_BINDIR}/lupdate
MOC?=			${QT_BINDIR}/moc
RCC?=			${QT_BINDIR}/rcc
UIC?=			${QT_BINDIR}/uic
QMAKE?=			${QT_BINDIR}/qmake
# Needed to redefine the qmake target for internal Qt configuration.
_QMAKE?=		${QMAKE}
QMAKESPECNAME?=		freebsd-${QMAKE_COMPILER}
QMAKESPEC?=		${QT_MKSPECDIR}/${QMAKESPECNAME}

# The whole Qt distribution should be built with the same compiler, but it's
# better to support custom settings. Dereferencing the detection allows to
# avoid forking a shell on each inclusion of this file, and to catch any CXX
# customization (via USE_GCC, etc.).
QMAKE_COMPILER=	$$(ccver="$$(${CXX} --version)"; case "$$ccver" in *clang*) echo clang ;; *) echo g++ ;; esac)

.  for dir in BIN INC LIB ARCH PLUGIN LIBEXEC IMPORT \
	QML DATA DOC L10N ETC EXAMPLE TEST MKSPEC \
	CMAKE QTCHOOSER
QT_${dir}DIR=	${PREFIX}/${QT_${dir}DIR_REL}
# Export all directories to the plist substituion for QT_DIST ports.
# For the others, exclude QT_CMAKEDIR and QT_ETCDIR.
.    if ${dir:NCMAKE} && ${dir:NETC}
PLIST_SUB+=		QT_${dir}DIR="${QT_${dir}DIR_REL}"
.    endif
.  endfor

# Pass the chosen Qt version to the environment for qtchooser.
CONFIGURE_ENV+=		QT_SELECT=${_QT_RELNAME}
MAKE_ENV+=		QT_SELECT=${_QT_RELNAME}

# Make sure both the installed mkspecs as well as the ones being built are
# found, with the ones from the port being built having preference.
CONFIGURE_ENV+=		QMAKEMODULES="${WRKSRC}/mkspecs/modules:${LOCALBASE}/${QT_MKSPECDIR_REL}/modules"
MAKE_ENV+=		QMAKEMODULES="${WRKSRC}/mkspecs/modules:${LOCALBASE}/${QT_MKSPECDIR_REL}/modules"

_USES_POST+=		qt
.endif # _QT_MK_INCLUDED

# =============================================================================
#
# =============================================================================

.if defined(_POSTMKINCLUDED) && !defined(_QT_MK_POST_INCLUDED)
_QT_MK_POST_INCLUDED=	qt.mk

# The Qt components supported by qt.mk: list of shared, and version specific ones
_USE_QT_ALL=		assistant dbus declarative designer doc gui help \
			imageformats l10n linguist linguisttools multimedia \
			network opengl pixeltool qdbusviewer qmake script \
			scripttools sql sql-mysql sql-odbc sql-pgsql \
			sql-sqlite2 sql-sqlite3 svg testlib webkit \
			xml xmlpatterns
.if ${ARCH} == amd64 || ${ARCH} == i386
_USE_QT_ALL+=	sql-ibase
.endif

_USE_QT5_ONLY=		3d buildtools charts concurrent connectivity \
			core datavis3d diag examples gamepad \
			graphicaleffects location networkauth paths phonon4 plugininfo printsupport \
			qdbus qdoc qdoc-data qev quickcontrols \
			quickcontrols2 remoteobjects scxml sensors serialbus serialport speech \
			sql-tds uiplugin uitools virtualkeyboard wayland webchannel webglplugin \
			webengine websockets websockets-qml webview widgets x11extras

# Dependency tuples: _LIB should be preferred if possible.
qt-3d_PORT=		graphics/${_QT_RELNAME}-3d
qt-3d_LIB=		libQt${_QT_LIBVER}3DCore.so

qt-assistant_PORT=	devel/${_QT_RELNAME}-assistant
qt-assistant_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/assistant

qt-buildtools_PORT=	devel/${_QT_RELNAME}-buildtools
qt-buildtools_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/moc

qt-charts_PORT=		x11-toolkits/${_QT_RELNAME}-charts
qt-charts_LIB=		libQt${_QT_LIBVER}Charts.so

qt-concurrent_PORT=	devel/${_QT_RELNAME}-concurrent
qt-concurrent_LIB=	libQt${_QT_LIBVER}Concurrent.so

qt-connectivity_PORT=	comms/${_QT_RELNAME}-connectivity
qt-connectivity_LIB=	libQt${_QT_LIBVER}Bluetooth.so

qt-core_PORT=		devel/${_QT_RELNAME}-core
qt-core_LIB=		libQt${_QT_LIBVER}Core.so

qt-datavis3d_PORT=	x11-toolkits/${_QT_RELNAME}-datavis3d
qt-datavis3d_LIB=	libQt${_QT_LIBVER}DataVisualization.so

qt-dbus_PORT=		devel/${_QT_RELNAME}-dbus
qt-dbus_LIB=		libQt${_QT_LIBVER}DBus.so

qt-declarative_PORT=	x11-toolkits/${_QT_RELNAME}-declarative
qt-declarative_LIB=	libQt${_QT_LIBVER}Qml.so

qt-designer_PORT=	devel/${_QT_RELNAME}-designer
qt-designer_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/designer

qt-diag_PORT=		sysutils/${_QT_RELNAME}-qtdiag
qt-diag_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qtdiag

qt-doc_PORT=		misc/${_QT_RELNAME}-doc
qt-doc_PATH=		${_QT_RELNAME}-doc>=${_QT_VERSION:R:R}

qt-examples_PORT=	misc/${_QT_RELNAME}-examples
qt-examples_PATH=	${_QT_RELNAME}-examples>=${_QT_VERSION:R:R}

qt-gamepad_PORT=	x11-toolkits/${_QT_RELNAME}-gamepad
qt-gamepad_LIB=		libQt${_QT_LIBVER}Gamepad.so

qt-graphicaleffects_PORT=	graphics/${_QT_RELNAME}-graphicaleffects
qt-graphicaleffects_PATH=	${LOCALBASE}/${QT_QMLDIR_REL}/QtGraphicalEffects/qmldir

qt-gui_PORT=		x11-toolkits/${_QT_RELNAME}-gui
qt-gui_LIB=		libQt${_QT_LIBVER}Gui.so

qt-help_PORT=		devel/${_QT_RELNAME}-help
qt-help_LIB=		libQt${_QT_LIBVER}Help.so

qt-imageformats_PORT=	graphics/${_QT_RELNAME}-imageformats
qt-imageformats_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/imageformats/libqtiff.so

qt-linguist_PORT=	devel/${_QT_RELNAME}-linguist
qt-linguist_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/linguist

qt-linguisttools_PORT=	devel/${_QT_RELNAME}-linguisttools
qt-linguisttools_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/lrelease

qt-location_PORT=	devel/${_QT_RELNAME}-location
qt-location_LIB=	libQt${_QT_LIBVER}Location.so

qt-l10n_PORT=		misc/${_QT_RELNAME}-l10n
qt-l10n_PATH=		${_QT_RELNAME}-l10n>=${_QT_VERSION:R:R}

qt-multimedia_PORT=	multimedia/${_QT_RELNAME}-multimedia
qt-multimedia_LIB=	libQt${_QT_LIBVER}Multimedia.so

qt-network_PORT=	net/${_QT_RELNAME}-network
qt-network_LIB=		libQt${_QT_LIBVER}Network.so

qt-networkauth_PORT=	net/${_QT_RELNAME}-networkauth
qt-networkauth_LIB=	libQt${_QT_LIBVER}NetworkAuth.so

qt-opengl_PORT=		graphics/${_QT_RELNAME}-opengl
qt-opengl_LIB=		libQt${_QT_LIBVER}OpenGL.so

qt-paths_PORT=		sysutils/${_QT_RELNAME}-qtpaths
qt-paths_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qtpaths

qt-pixeltool_PORT=	graphics/${_QT_RELNAME}-pixeltool
qt-pixeltool_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/pixeltool

qt-phonon4_PORT=	multimedia/phonon
qt-phonon4_LIB=		libphonon4${_QT_RELNAME}.so

qt-plugininfo_PORT=	sysutils/${_QT_RELNAME}-qtplugininfo
qt-plugininfo_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/qtplugininfo

qt-printsupport_PORT=	print/${_QT_RELNAME}-printsupport
qt-printsupport_LIB=	libQt${_QT_LIBVER}PrintSupport.so

qt-qdbus_PORT=		devel/${_QT_RELNAME}-qdbus
qt-qdbus_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qdbus

qt-qdbusviewer_PORT=	devel/${_QT_RELNAME}-qdbusviewer
qt-qdbusviewer_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/qdbusviewer

qt-qdoc_PORT=		devel/${_QT_RELNAME}-qdoc
qt-qdoc_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qdoc

qt-qdoc-data_PORT=	devel/${_QT_RELNAME}-qdoc-data
qt-qdoc-data_PATH=	${LOCALBASE}/${QT_DOCDIR_REL}/global/config.qdocconf

qt-qev_PORT=		x11/${_QT_RELNAME}-qev
qt-qev_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qev

qt-qmake_PORT=		devel/${_QT_RELNAME}-qmake
qt-qmake_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qmake

qt-quickcontrols_PORT=	x11-toolkits/${_QT_RELNAME}-quickcontrols
qt-quickcontrols_PATH=	${LOCALBASE}/${QT_QMLDIR_REL}/QtQuick/Controls/qmldir

qt-quickcontrols2_PORT=	x11-toolkits/${_QT_RELNAME}-quickcontrols2
qt-quickcontrols2_LIB=	libQt${_QT_LIBVER}QuickControls2.so

qt-remoteobjects_PORT=	devel/${_QT_RELNAME}-remoteobjects
qt-remoteobjects_LIB=	libQt${_QT_LIBVER}RemoteObjects.so

qt-sensors_PORT=	comms/${_QT_RELNAME}-sensors
qt-sensors_LIB=		libQt${_QT_LIBVER}Sensors.so

qt-script_PORT=		devel/${_QT_RELNAME}-script
qt-script_LIB=		libQt${_QT_LIBVER}Script.so

qt-scripttools_PORT=	devel/${_QT_RELNAME}-scripttools
qt-scripttools_LIB=	libQt${_QT_LIBVER}ScriptTools.so

qt-scxml_PORT=		devel/${_QT_RELNAME}-scxml
qt-scxml_LIB=		libQt${_QT_LIBVER}Scxml.so

qt-serialbus_PORT=	comms/${_QT_RELNAME}-serialbus
qt-serialbus_LIB=	libQt${_QT_LIBVER}SerialBus.so

qt-serialport_PORT=	comms/${_QT_RELNAME}-serialport
qt-serialport_LIB=	libQt${_QT_LIBVER}SerialPort.so

qt-speech_PORT=		accessibility/${_QT_RELNAME}-speech
qt-speech_LIB=		libQt${_QT_LIBVER}TextToSpeech.so

qt-sql_PORT=		databases/${_QT_RELNAME}-sql
qt-sql_LIB=		libQt${_QT_LIBVER}Sql.so

qt-sql-pgsql_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/sqldrivers/libqsqlpsql.so

qt-sql-sqlite3_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/sqldrivers/libqsqlite.so

.  for db in ibase mysql odbc pgsql sqlite2 sqlite3 tds
qt-sql-${db}_PORT=	databases/${_QT_RELNAME}-sqldrivers-${db}
qt-sql-${db}_PATH?=	${LOCALBASE}/${QT_PLUGINDIR_REL}/sqldrivers/libqsql${db:C/^sql//}.so
.  endfor

qt-svg_PORT=		graphics/${_QT_RELNAME}-svg
qt-svg_LIB=		libQt${_QT_LIBVER}Svg.so

qt-testlib_PORT=	devel/${_QT_RELNAME}-testlib
qt-testlib_LIB=		libQt${_QT_LIBVER}Test.so

qt-uiplugin_PORT=	x11-toolkits/${_QT_RELNAME}-uiplugin
qt-uiplugin_PATH=	${LOCALBASE}/${QT_INCDIR_REL}/QtUiPlugin/QtUiPlugin

qt-uitools_PORT=	devel/${_QT_RELNAME}-uitools
qt-uitools_PATH=	${LOCALBASE}/${QT_LIBDIR_REL}/libQt${_QT_LIBVER}UiTools.a

qt-virtualkeyboard_PORT=	x11-toolkits/${_QT_RELNAME}-virtualkeyboard
qt-virtualkeyboard_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/platforminputcontexts/libqtvirtualkeyboardplugin.so

qt-wayland_PORT=	graphics/${_QT_RELNAME}-wayland
qt-wayland_LIB=		libQt${_QT_LIBVER}WaylandClient.so

qt-webchannel_PORT=	www/${_QT_RELNAME}-webchannel
qt-webchannel_LIB=	libQt${_QT_LIBVER}WebChannel.so

qt-webengine_PORT=	www/${_QT_RELNAME}-webengine
qt-webengine_LIB=	libQt${_QT_LIBVER}WebEngine.so

qt-webglplugin_PORT=     www/${_QT_RELNAME}-webglplugin
qt-webglplugin_PATH=     ${LOCALBASE}/${QT_PLUGINDIR_REL}/platforms/libqwebgl.so

qt-websockets_PORT=	www/${_QT_RELNAME}-websockets
qt-websockets_LIB=	libQt${_QT_LIBVER}WebSockets.so

qt-websockets-qml_PORT=	www/${_QT_RELNAME}-websockets-qml
qt-websockets-qml_PATH=	${LOCALBASE}/${QT_QMLDIR_REL}/QtWebSockets/qmldir

qt-webkit_PORT=		www/${_QT_RELNAME}-webkit
qt-webkit_LIB=		libQt${_QT_LIBVER}WebKit.so

qt-webview_PORT=	www/${_QT_RELNAME}-webview
qt-webview_LIB=		libQt${_QT_LIBVER}WebView.so

qt-widgets_PORT=	x11-toolkits/${_QT_RELNAME}-widgets
qt-widgets_LIB=		libQt${_QT_LIBVER}Widgets.so

qt-x11extras_PORT=	x11/${_QT_RELNAME}-x11extras
qt-x11extras_LIB=	libQt${_QT_LIBVER}X11Extras.so

qt-xml_PORT=		textproc/${_QT_RELNAME}-xml
qt-xml_LIB=		libQt${_QT_LIBVER}Xml.so

qt-xmlpatterns_PORT=	textproc/${_QT_RELNAME}-xmlpatterns
qt-xmlpatterns_LIB=	libQt${_QT_LIBVER}XmlPatterns.so

# Actually add the dependencies to the proper lists.
_USE_QT_ALL+=		${_USE_QT${_QT_VER}_ONLY}
_USE_QT=		${USE_QT}
# Iterate through components deprived of suffix.
.  for component in ${_USE_QT:O:u:C/_(build|run)$//}
# Check that the component is valid.
.    if ${_USE_QT_ALL:M${component}} != ""
# Skip meta-components (currently none).
.      if defined(qt-${component}_PORT) && (defined(qt-${component}_PATH) || defined(qt-${component}_LIB))
# Check if a dependency type is explicitly requested.
.        if ${_USE_QT:M${component}_*} != "" && ${_USE_QT:M${component}} == ""
qt-${component}_TYPE=		# empty
.          if ${_USE_QT:M${component}_build} != ""
qt-${component}_TYPE+=		build
.          endif
.          if ${_USE_QT:M${component}_run} != ""
qt-${component}_TYPE+=		run
.          endif
.        endif # ${_USE_QT:M${component}_*} != "" && ${_USE_QT:M${component}} == ""
# If no dependency type is set, default to full dependency.
.        if !defined(qt-${component}_TYPE)
qt-${component}_TYPE=		build run
.        endif
# Set real dependencies.
.        if defined(qt-${component}_LIB) && ${qt-${component}_TYPE:Mbuild} && ${qt-${component}_TYPE:Mrun}
LIB_DEPENDS+=			${qt-${component}_LIB}:${qt-${component}_PORT}
.        else
qt-${component}_PATH?=		${QT_LIBDIR}/${qt-${component}_LIB}
qt-${component}_DEPENDS=	${qt-${component}_PATH}:${qt-${component}_PORT}
.          if ${qt-${component}_TYPE:Mbuild} != ""
BUILD_DEPENDS+=			${qt-${component}_DEPENDS}
.          endif
.          if ${qt-${component}_TYPE:Mrun} != ""
RUN_DEPENDS+=			${qt-${component}_DEPENDS}
.          endif
.        endif # ${qt-${component}_LIB} && ${qt-${component}_TYPE:Mbuild} && ${qt-${component}_TYPE:Mrun}
.      endif # defined(qt-${component}_PORT) && defined(qt-${component}_PATH)
.    else # ! ${_USE_QT_ALL:M${component}} != ""
IGNORE=				cannot be installed: unknown USE_QT component '${component}'
.    endif # ${_USE_QT_ALL:M${component}} != ""
.  endfor

.endif # defined(_QT_MK_POST_INCLUDED)
