# There are three Qt related USES files with different access to Qt.
#   - qmake: The port requires Qt's qmake to build -- creates the configure target
#            - auto includes qt.mk
#   - qt-dist: The port is a port for a part of Qt
#            - auto includes qt.mk and qmake.mk
#   - qt.mk  - Dependency handling. USE_QT=foo bar
#
# Usage:
#   USES=qt:<version>[,no_env]
#
#   Versions:		5, 6
#
# Port variables:
# USE_QT		- List of Qt modules to depend on, with optional ':build',
#			  ':run', and ':test' suffixes. Define it empty to include
#			  this file without depending on Qt ports.
#
# MAINTAINER:	kde@FreeBSD.org

.if !defined(_QT_MK_INCLUDED)
_QT_MK_INCLUDED=	qt.mk

# Qt versions currently supported by the framework.
_QT_SUPPORTED?=		5 6
QT5_VERSION?=		5.15.17
QT6_VERSION?=		6.9.2
PYSIDE6_VERSION?=	6.9.2

# Support for intermediate Qt6 releases. This partially defines
# _QT6_MASTER_SITE_SUBDIR and would probably be better in qt-dist.mk,
# but misc/qt6-examples needs this too.
.  if ${QT6_VERSION:M*beta*} || ${QT6_VERSION:M*rc*}
_QT6_RELEASE_TYPE=		development
.  else
_QT6_RELEASE_TYPE=		official
.  endif

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

QT_BINDIR_REL?=		${QT_ARCHDIR_REL}/bin
QT_INCDIR_REL?=		include/${_QT_RELNAME}
QT_LIBDIR_REL?=		lib/${_QT_RELNAME}
QT_ARCHDIR_REL?=	${QT_LIBDIR_REL}
QT_PLUGINDIR_REL?=	${QT_ARCHDIR_REL}/plugins
QT_DESCRIPTIONSDIR_REL?=${QT_DATADIR_REL}/modules
QT_LIBEXECDIR_REL?=	libexec/${_QT_RELNAME}
QT_IMPORTDIR_REL?=	${QT_ARCHDIR_REL}/imports
QT_QMLDIR_REL?=		${QT_ARCHDIR_REL}/qml
QT_SBOMDIR_REL?=	${QT_ARCHDIR_REL}/sbom
QT_DATADIR_REL?=	share/${_QT_RELNAME}
QT_DOCDIR_REL?=		share/doc/${_QT_RELNAME}
QT_L10NDIR_REL?=	${QT_DATADIR_REL}/translations
QT_ETCDIR_REL?=		etc/xdg
QT_EXAMPLEDIR_REL?=	share/examples/${_QT_RELNAME}
QT_TESTDIR_REL?=	${QT_DATADIR_REL}/tests
QT_CMAKEDIR_REL?=	lib/cmake
_QT5_TOOLDIR_REL=	${QT_BINDIR_REL}
_QT6_TOOLDIR_REL=	${QT_LIBEXECDIR_REL}
QT_TOOLDIR_REL=		${_QT${_QT_VER}_TOOLDIR_REL}

# Not customizable.
QT_MKSPECDIR_REL=	${QT_ARCHDIR_REL}/mkspecs
_QT_LIBVER=		${_QT_VERSION:R:R}

LCONVERT?=		${QT_BINDIR}/lconvert
LRELEASE?=		${QT_BINDIR}/lrelease
LUPDATE?=		${QT_BINDIR}/lupdate
MOC?=			${QT_TOOLDIR}/moc
RCC?=			${QT_TOOLDIR}/rcc
UIC?=			${QT_TOOLDIR}/uic
QMAKE?=			${QT_BINDIR}/qmake
QCOLLECTIONGENERATOR?=	${QT_TOOLDIR}/qcollectiongenerator
QHELPGENERATOR?=	${QT_TOOLDIR}/qhelpgenerator

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
	QML SBOM DATA DOC L10N ETC EXAMPLE TEST MKSPEC \
	CMAKE TOOL
QT_${dir}DIR=	${PREFIX}/${QT_${dir}DIR_REL}
# Export all directories to the plist substituion for QT_DIST ports.
# For the others, exclude QT_CMAKEDIR and QT_ETCDIR.
.    if ${dir:NCMAKE} && ${dir:NETC}
PLIST_SUB+=		QT_${dir}DIR="${QT_${dir}DIR_REL}"
.    endif
.  endfor

# Suppress warnings from rcc about not using a UTF-8 locale.
.  if ${_QT_VER:M6}
USE_LOCALE?=		C.UTF-8
.  endif

CONFIGURE_ENV+=		QT_SELECT=${_QT_RELNAME}
MAKE_ENV+=		QT_SELECT=${_QT_RELNAME}

# Make sure both the installed mkspecs as well as the ones being built are
# found, with the ones from the port being built having preference.
CONFIGURE_ENV+=		QMAKEMODULES="${WRKSRC}/mkspecs/modules:${LOCALBASE}/${QT_MKSPECDIR_REL}/modules"
MAKE_ENV+=		QMAKEMODULES="${WRKSRC}/mkspecs/modules:${LOCALBASE}/${QT_MKSPECDIR_REL}/modules"

# Qt uses generated linker version scripts which always have a qt_version_tag
# symbol, but that symbol is only defined in the main Qt shared library. For
# other Qt components, this leads to lld >= 17 erroring out due to the symbol
# being undefined. Supress these errors.
LDFLAGS+=		-Wl,--undefined-version

_USES_POST+=		qt
.endif # _QT_MK_INCLUDED

# =============================================================================
#
# =============================================================================

.if defined(_POSTMKINCLUDED) && !defined(_QT_MK_POST_INCLUDED)
_QT_MK_POST_INCLUDED=	qt.mk

# The Qt components supported by qt.mk: list of shared, and version specific ones
_USE_QT_COMMON=		3d charts connectivity datavis3d declarative doc \
			examples imageformats location multimedia networkauth \
			quick3d quicktimeline remoteobjects scxml sensors \
			serialbus serialport speech svg virtualkeyboard wayland \
			webchannel webengine websockets webview

_USE_QT5_ONLY=		assistant buildtools concurrent core dbus \
			declarative-test designer diag gamepad \
			graphicaleffects gui help l10n linguist linguisttools \
			network opengl paths pixeltool plugininfo printsupport \
			qdbus qdbusviewer qdoc qdoc-data qev qmake quickcontrols \
			quickcontrols2 script scripttools sql sql-mysql sql-odbc \
			sql-pgsql sql-sqlite2 sql-sqlite3 sql-tds testlib uiplugin \
			uitools webglplugin websockets-qml \
			widgets x11extras xml xmlpatterns

_USE_QT6_ONLY=		5compat base coap graphs grpc httpserver languageserver \
			lottie mqtt pdf positioning quick3dphysics quickeffectmaker \
			shadertools tools translations sqldriver-sqlite \
			sqldriver-mysql sqldriver-psql sqldriver-odbc

# Dependency tuples: _LIB should be preferred if possible.
qt-3d_PORT=		graphics/${_QT_RELNAME}-3d
qt-3d_LIB=		libQt${_QT_LIBVER}3DCore.so

qt-5compat_PORT=	devel/${_QT_RELNAME}-5compat
qt-5compat_LIB=		libQt${_QT_LIBVER}Core5Compat.so

qt-assistant_PORT=	devel/${_QT_RELNAME}-assistant
qt-assistant_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/assistant

# Always build with *this* version's buildtools
qt-buildtools_PORT=	devel/${_QT_RELNAME}-buildtools
qt-buildtools_PATH=	${_QT_RELNAME}-buildtools>=${_QT_VERSION:R}

qt-base_PORT=		devel/${_QT_RELNAME}-base
qt-base_LIB=		libQt${_QT_LIBVER}Core.so

qt-charts_PORT=		x11-toolkits/${_QT_RELNAME}-charts
qt-charts_LIB=		libQt${_QT_LIBVER}Charts.so

qt-coap_PORT=		net/${_QT_RELNAME}-coap
qt-coap_LIB=		libQt${_QT_LIBVER}Coap.so

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

qt-declarative-test_PORT=	x11-toolkits/${_QT_RELNAME}-declarative-test
qt-declarative-test_LIB=	libQt${_QT_LIBVER}QuickTest.so

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

qt-graphs_PORT=		x11-toolkits/${_QT_RELNAME}-graphs
qt-graphs_LIB=		libQt${_QT_LIBVER}Graphs.so

qt-grpc_PORT=		devel/${_QT_RELNAME}-grpc
qt-grpc_LIB=		libQt${_QT_LIBVER}Grpc.so

qt-gui_PORT=		x11-toolkits/${_QT_RELNAME}-gui
qt-gui_LIB=		libQt${_QT_LIBVER}Gui.so

qt-help_PORT=		devel/${_QT_RELNAME}-help
qt-help_LIB=		libQt${_QT_LIBVER}Help.so

qt-httpserver_PORT=	www/${_QT_RELNAME}-httpserver
qt-httpserver_LIB=	libQt${_QT_LIBVER}HttpServer.so

qt-imageformats_PORT=	graphics/${_QT_RELNAME}-imageformats
qt-imageformats_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/imageformats/libqtiff.so

qt-languageserver_PORT=	devel/${_QT_RELNAME}-languageserver
qt-languageserver_PATH=	${LOCALBASE}/${QT_LIBDIR_REL}/libQt6LanguageServer.a

qt-lottie_PORT=		graphics/${_QT_RELNAME}-lottie
qt-lottie_LIB=		libQt${_QT_LIBVER}Bodymovin.so

qt-linguist_PORT=	devel/${_QT_RELNAME}-linguist
qt-linguist_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/linguist

qt-linguisttools_PORT=	devel/${_QT_RELNAME}-linguisttools
qt-linguisttools_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/lrelease

qt-location_PORT=	devel/${_QT_RELNAME}-location
qt-location_LIB=	libQt${_QT_LIBVER}Location.so

qt-l10n_PORT=		misc/${_QT_RELNAME}-l10n
qt-l10n_PATH=		${_QT_RELNAME}-l10n>=${_QT_VERSION:R:R}

qt-mqtt_PORT=		net/${_QT_RELNAME}-mqtt
qt-mqtt_LIB=		libQt${_QT_LIBVER}Mqtt.so

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

qt-pdf_PORT=		print/${_QT_RELNAME}-pdf
qt-pdf_LIB=		libQt${_QT_LIBVER}Pdf.so

qt-pixeltool_PORT=	graphics/${_QT_RELNAME}-pixeltool
qt-pixeltool_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/pixeltool

qt-positioning_PORT=	devel/${_QT_RELNAME}-positioning
qt-positioning_LIB=	libQt${_QT_LIBVER}Positioning.so

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

# Always build with *this* version's qmake
qt-qmake_PORT=		devel/${_QT_RELNAME}-qmake
qt-qmake_PATH=		${_QT_RELNAME}-qmake>=${_QT_VERSION:R}

qt-quick3d_PORT=	x11-toolkits/${_QT_RELNAME}-quick3d
qt-quick3d_LIB=		libQt${_QT_LIBVER}Quick3D.so

qt-quick3dphysics_PORT=	science/${_QT_RELNAME}-quick3dphysics
qt-quick3dphysics_LIB=	libQt${_QT_LIBVER}Quick3DPhysics.so

qt-quickcontrols_PORT=	x11-toolkits/${_QT_RELNAME}-quickcontrols
qt-quickcontrols_PATH=	${LOCALBASE}/${QT_QMLDIR_REL}/QtQuick/Controls/qmldir

qt-quickcontrols2_PORT=	x11-toolkits/${_QT_RELNAME}-quickcontrols2
qt-quickcontrols2_LIB=	libQt${_QT_LIBVER}QuickControls2.so

qt-quickeffectmaker_PORT=	graphics/${_QT_RELNAME}-quickeffectmaker
qt-quickeffectmaker_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/qqem

qt-quicktimeline_PORT=	x11-toolkits/${_QT_RELNAME}-quicktimeline
qt-quicktimeline_PATH=	${LOCALBASE}/${QT_QMLDIR_REL}/QtQuick/Timeline/libqtquicktimelineplugin.so

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

qt-shadertools_PORT=	x11-toolkits/${_QT_RELNAME}-shadertools
qt-shadertools_LIB=	libQt${_QT_LIBVER}ShaderTools.so

qt-speech_PORT=		accessibility/${_QT_RELNAME}-speech
qt-speech_LIB=		libQt${_QT_LIBVER}TextToSpeech.so

qt-sql_PORT=		databases/${_QT_RELNAME}-sql
qt-sql_LIB=		libQt${_QT_LIBVER}Sql.so

qt-sql-pgsql_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/sqldrivers/libqsqlpsql.so

qt-sql-sqlite3_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/sqldrivers/libqsqlite.so

.  for db in mysql odbc pgsql sqlite2 sqlite3 tds
qt-sql-${db}_PORT=	databases/${_QT_RELNAME}-sqldrivers-${db}
qt-sql-${db}_PATH?=	${LOCALBASE}/${QT_PLUGINDIR_REL}/sqldrivers/libqsql${db:C/^sql//}.so
.  endfor

.  for db in sqlite mysql psql odbc
qt-sqldriver-${db}_PORT=	databases/${_QT_RELNAME}-base_sqldriver@${db}
qt-sqldriver-${db}_PATH?=	${LOCALBASE}/${QT_PLUGINDIR_REL}/sqldrivers/libqsql${db:C/^sql//}.so
.  endfor

qt-svg_PORT=		graphics/${_QT_RELNAME}-svg
qt-svg_LIB=		libQt${_QT_LIBVER}Svg.so

qt-testlib_PORT=	devel/${_QT_RELNAME}-testlib
qt-testlib_LIB=		libQt${_QT_LIBVER}Test.so

qt-tools_PORT=		devel/${_QT_RELNAME}-tools
qt-tools_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/lupdate

qt-translations_PORT=	devel/${_QT_RELNAME}-translations
qt-translations_PATH=	${LOCALBASE}/${QT_DATADIR_REL}/translations/qt_en.qm

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
qt-webengine_LIB=	libQt${_QT_LIBVER}WebEngineCore.so

qt-webglplugin_PORT=     www/${_QT_RELNAME}-webglplugin
qt-webglplugin_PATH=     ${LOCALBASE}/${QT_PLUGINDIR_REL}/platforms/libqwebgl.so

qt-websockets_PORT=	www/${_QT_RELNAME}-websockets
qt-websockets_LIB=	libQt${_QT_LIBVER}WebSockets.so

qt-websockets-qml_PORT=	www/${_QT_RELNAME}-websockets-qml
qt-websockets-qml_PATH=	${LOCALBASE}/${QT_QMLDIR_REL}/QtWebSockets/qmldir

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
_USE_QT_ALL=		${_USE_QT_COMMON} \
			${_USE_QT${_QT_VER}_ONLY}
_USE_QT=		${USE_QT}
# Iterate through components deprived of suffix.
.  for component in ${_USE_QT:O:u:C/:(build|run|test)$//}
# Check that the component is valid.
.    if ${_USE_QT_ALL:M${component}} != ""
# Skip meta-components (currently none).
.      if defined(qt-${component}_PORT) && (defined(qt-${component}_PATH) || defined(qt-${component}_LIB))
# Check if a dependency type is explicitly requested.
.        if ${_USE_QT:M${component}\:*} != "" && ${_USE_QT:M${component}} == ""
qt-${component}_TYPE=		# empty
.          if ${_USE_QT:M${component}\:build} != ""
qt-${component}_TYPE+=		build
.          endif
.          if ${_USE_QT:M${component}\:run} != ""
qt-${component}_TYPE+=		run
.          endif
.          if ${_USE_QT:M${component}\:test} != ""
qt-${component}_TYPE+=		test
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
.          if ${qt-${component}_TYPE:Mtest} != ""
TEST_DEPENDS+=			${qt-${component}_DEPENDS}
.          endif
.        endif # ${qt-${component}_LIB} && ${qt-${component}_TYPE:Mbuild} && ${qt-${component}_TYPE:Mrun}
.      endif # defined(qt-${component}_PORT) && defined(qt-${component}_PATH)
.    else # ! ${_USE_QT_ALL:M${component}} != ""
IGNORE=				cannot be installed: unknown USE_QT component '${component}'
.    endif # ${_USE_QT_ALL:M${component}} != ""
.  endfor

.endif # defined(_QT_MK_POST_INCLUDED)
