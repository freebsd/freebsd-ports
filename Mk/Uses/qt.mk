# $FreeBSD$
#
# There are three Qt related USES files with different access to Qt.
#   - qmake: The port requires Qt's qmake to build -- creates the configure target
#            - auto includes qt.mk
#   - qt-dist: The port is a port for an part of Qt4 or Qt5
#            - auto includes qt.mk and qmake.mk
#   - qt.mk  - Dependency handling. USE_QT=foo bar
#
# Usage:
#   USES=qt:<version>[,no_env]
#
#   Versions:		4 5
#
# Port variables:
# USE_QT		- List of Qt modules to depend on, with optional '_build'
#			  and '_run' suffixes. Define it empty to include this file
#			  without depending on Qt ports.
# Global switches (for inclusion into /etc/make.conf):
# QT4_OPTIONS		- A list of (Qt 4-only) global options; can be CUPS, NAS
#					  and/or QGTKSTYLE. If set, Qt will be built with support
#					  for:
#					   * Common UNIX Printing System (CUPS);
#					   * Network Audio System (NAS);
#					   * GTK+-based Qt theme (QGTKSTYLE).

.if !defined(_QT_MK_INCLUDED)
_QT_MK_INCLUDED=	qt.mk

# Qt versions currently supported by the framework.
_QT_SUPPORTED?=		4 5
QT4_VERSION?=		4.8.7
QT5_VERSION?=		5.12.0

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
.  if ${_QT_VERSION:M4*}
QT_MKSPECDIR_REL=	${QT_DATADIR_REL}/mkspecs
_QT_LIBVER=		# empty
.  else
QT_MKSPECDIR_REL=	${QT_ARCHDIR_REL}/mkspecs
_QT_LIBVER=		${_QT_VERSION:R:R}
.  endif

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
			scripttools sql sql-ibase sql-mysql sql-odbc sql-pgsql \
			sql-sqlite2 sql-sqlite3 svg testlib webkit \
			xml xmlpatterns

_USE_QT4_ONLY=		accessible assistant-adp assistantclient clucene codecs-cn codecs-jp \
			codecs-kr codecs-tw corelib demo graphicssystems-opengl \
			help-tools iconengines inputmethods makeqpf moc phonon \
			phonon-gst porting qdoc3 qmlviewer qt3support qtconfig \
			qtestlib qvfb rcc uic uic3 xmlpatterns-tool

_USE_QT5_ONLY=		3d buildtools canvas3d charts concurrent connectivity \
			core datavis3d diag examples gamepad \
			graphicaleffects location paths phonon4 plugininfo printsupport \
			qdbus qdoc qdoc-data qev quickcontrols \
			quickcontrols2 scxml sensors serialbus serialport speech \
			sql-tds uiplugin uitools virtualkeyboard wayland webchannel \
			webengine websockets websockets-qml widgets x11extras

# Dependency tuples: _LIB should be preferred if possible.
3d_PORT=		graphics/${_QT_RELNAME}-3d
3d_LIB=			libQt${_QT_LIBVER}3DCore.so

accessible_PORT=	accessibility/${_QT_RELNAME}-accessible
accessible_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/accessible/libqtaccessiblewidgets.so

assistant_PORT=		devel/${_QT_RELNAME}-assistant
assistant_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/assistant

assistant-adp_PORT=	devel/${_QT_RELNAME}-assistant-adp
assistant-adp_PATH=	assistant_adp

assistantclient_PORT=	devel/${_QT_RELNAME}-libqtassistantclient
assistantclient_LIB=	libQt${_QT_LIBVER}AssistantClient.so

buildtools_PORT=	devel/${_QT_RELNAME}-buildtools
buildtools_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/moc

canvas3d_PORT=		x11-toolkits/${_QT_RELNAME}-canvas3d
canvas3d_PATH=		${LOCALBASE}/${QT_QMLDIR_REL}/QtCanvas3D/qmldir

charts_PORT=		x11-toolkits/${_QT_RELNAME}-charts
charts_LIB=		libQt${_QT_LIBVER}Charts.so

clucene_PORT=		textproc/${_QT_RELNAME}-clucene
clucene_LIB=		libQt${_QT_LIBVER}CLucene.so

codecs-cn_PORT=		chinese/${_QT_RELNAME}-codecs-cn
codecs-cn_PATH=		${LOCALBASE}/${QT_PLUGINDIR_REL}/codecs/libqcncodecs.so

codecs-jp_PORT=		japanese/${_QT_RELNAME}-codecs-jp
codecs-jp_PATH=		${LOCALBASE}/${QT_PLUGINDIR_REL}/codecs/libqjpcodecs.so

codecs-kr_PORT=		korean/${_QT_RELNAME}-codecs-kr
codecs-kr_PATH=		${LOCALBASE}/${QT_PLUGINDIR_REL}/codecs/libqkrcodecs.so

codecs-tw_PORT=		chinese/${_QT_RELNAME}-codecs-tw
codecs-tw_PATH=		${LOCALBASE}/${QT_PLUGINDIR_REL}/codecs/libqtwcodecs.so

concurrent_PORT=	devel/${_QT_RELNAME}-concurrent
concurrent_LIB=		libQt${_QT_LIBVER}Concurrent.so

connectivity_PORT=	comms/${_QT_RELNAME}-connectivity
connectivity_LIB=	libQt${_QT_LIBVER}Bluetooth.so

core_PORT=		devel/${_QT_RELNAME}-core
core_LIB=		libQt${_QT_LIBVER}Core.so

corelib_PORT=		devel/${_QT_RELNAME}-corelib
corelib_LIB=		${core_LIB}

datavis3d_PORT=		x11-toolkits/${_QT_RELNAME}-datavis3d
datavis3d_LIB=		libQt${_QT_LIBVER}DataVisualization.so

dbus_PORT=		devel/${_QT_RELNAME}-dbus
dbus_LIB=		libQt${_QT_LIBVER}DBus.so

declarative_PORT=	x11-toolkits/${_QT_RELNAME}-declarative
.  if ${_QT_VER:M4}
declarative_LIB=	libQt${_QT_LIBVER}Declarative.so
.  else
declarative_LIB=	libQt${_QT_LIBVER}Qml.so
.  endif

demo_PORT=		misc/${_QT_RELNAME}-qtdemo
demo_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qtdemo

designer_PORT=		devel/${_QT_RELNAME}-designer
designer_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/designer

diag_PORT=		sysutils/${_QT_RELNAME}-qtdiag
diag_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qtdiag

doc_PORT=		misc/${_QT_RELNAME}-doc
doc_PATH=		${_QT_RELNAME}-doc>=${_QT_VERSION:R:R}

examples_PORT=		misc/${_QT_RELNAME}-examples
examples_PATH=		${_QT_RELNAME}-examples>=${_QT_VERSION:R:R}

gamepad_PORT=		x11-toolkits/${_QT_RELNAME}-gamepad
gamepad_LIB=		libQt${_QT_LIBVER}Gamepad.so

graphicaleffects_PORT=	graphics/${_QT_RELNAME}-graphicaleffects
graphicaleffects_PATH=	${LOCALBASE}/${QT_QMLDIR_REL}/QtGraphicalEffects/qmldir

graphicssystems-opengl_PORT=	x11/${_QT_RELNAME}-graphicssystems-opengl
graphicssystems-opengl_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/graphicssystems/libqglgraphicssystem.so

gui_PORT=		x11-toolkits/${_QT_RELNAME}-gui
gui_LIB=		libQt${_QT_LIBVER}Gui.so

help_PORT=		devel/${_QT_RELNAME}-help
help_LIB=		libQt${_QT_LIBVER}Help.so

help-tools_PORT=	devel/${_QT_RELNAME}-help-tools
help-tools_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/qhelpgenerator

iconengines_PORT=	graphics/${_QT_RELNAME}-iconengines
iconengines_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/iconengines/libqsvgicon.so

imageformats_PORT=	graphics/${_QT_RELNAME}-imageformats
imageformats_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/imageformats/libqtiff.so

inputmethods_PORT=	x11/${_QT_RELNAME}-inputmethods
inputmethods_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/inputmethods/libqimsw-multi.so

linguist_PORT=		devel/${_QT_RELNAME}-linguist
linguist_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/linguist

linguisttools_PORT=	devel/${_QT_RELNAME}-linguisttools
linguisttools_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/lrelease

location_PORT=		devel/${_QT_RELNAME}-location
location_LIB=		libQt${_QT_LIBVER}Location.so

l10n_PORT=		misc/${_QT_RELNAME}-l10n
l10n_PATH=		${_QT_RELNAME}-l10n>=${_QT_VERSION:R:R}

makeqpf_PORT=		devel/${_QT_RELNAME}-makeqpf
makeqpf_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/makeqpf

moc_PORT=		devel/${_QT_RELNAME}-moc
moc_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/moc

multimedia_PORT=	multimedia/${_QT_RELNAME}-multimedia
multimedia_LIB=		libQt${_QT_LIBVER}Multimedia.so

network_PORT=		net/${_QT_RELNAME}-network
network_LIB=		libQt${_QT_LIBVER}Network.so

opengl_PORT=		graphics/${_QT_RELNAME}-opengl
opengl_LIB=		libQt${_QT_LIBVER}OpenGL.so

paths_PORT=		sysutils/${_QT_RELNAME}-qtpaths
paths_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qtpaths

pixeltool_PORT=		graphics/${_QT_RELNAME}-pixeltool
pixeltool_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/pixeltool

phonon_PORT=		multimedia/phonon@${_QT_RELNAME}
phonon_LIB=		libphonon.so

phonon4_PORT=		multimedia/phonon@${_QT_RELNAME}
phonon4_LIB=		libphonon4${_QT_RELNAME}.so

phonon-gst_PORT=	multimedia/phonon-gstreamer@${_QT_RELNAME}
phonon-gst_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/phonon_backend/libphonon_gstreamer.so

plugininfo_PORT=	sysutils/${_QT_RELNAME}-qtplugininfo
plugininfo_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/qtplugininfo

porting_PORT=		devel/${_QT_RELNAME}-porting
porting_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qt3to4

printsupport_PORT=	print/${_QT_RELNAME}-printsupport
printsupport_LIB=	libQt${_QT_LIBVER}PrintSupport.so

qdbus_PORT=		devel/${_QT_RELNAME}-qdbus
qdbus_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qdbus

qdbusviewer_PORT=	devel/${_QT_RELNAME}-qdbusviewer
qdbusviewer_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/qdbusviewer

qdoc_PORT=		devel/${_QT_RELNAME}-qdoc
qdoc_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qdoc

qdoc-data_PORT=		devel/${_QT_RELNAME}-qdoc-data
qdoc-data_PATH=		${LOCALBASE}/${QT_DOCDIR_REL}/global/config.qdocconf

qdoc3_PORT=		devel/${_QT_RELNAME}-qdoc3
qdoc3_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qdoc3

qev_PORT=		x11/${_QT_RELNAME}-qev
qev_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qev

qmake_PORT=		devel/${_QT_RELNAME}-qmake
qmake_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qmake

qmlviewer_PORT=		devel/${_QT_RELNAME}-qmlviewer
qmlviewer_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qmlviewer

qt3support_PORT=	devel/${_QT_RELNAME}-qt3support
qt3support_LIB=		libQt${_QT_LIBVER}3Support.so

qtconfig_PORT=		misc/${_QT_RELNAME}-qtconfig
qtconfig_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qtconfig

qtestlib_PORT=		${testlib_PORT}
qtestlib_LIB=		${testlib_LIB}

quickcontrols_PORT=	x11-toolkits/${_QT_RELNAME}-quickcontrols
quickcontrols_PATH=	${LOCALBASE}/${QT_QMLDIR_REL}/QtQuick/Controls/qmldir

quickcontrols2_PORT=	x11-toolkits/${_QT_RELNAME}-quickcontrols2
quickcontrols2_LIB=	libQt${_QT_LIBVER}QuickControls2.so

qvfb_PORT=		devel/${_QT_RELNAME}-qvfb
qvfb_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qvfb

rcc_PORT=		devel/${_QT_RELNAME}-rcc
rcc_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/rcc

sensors_PORT=		comms/${_QT_RELNAME}-sensors
sensors_LIB=		libQt${_QT_LIBVER}Sensors.so

script_PORT=		devel/${_QT_RELNAME}-script
script_LIB=		libQt${_QT_LIBVER}Script.so

scripttools_PORT=	devel/${_QT_RELNAME}-scripttools
scripttools_LIB=	libQt${_QT_LIBVER}ScriptTools.so

scxml_PORT=		devel/${_QT_RELNAME}-scxml
scxml_LIB=		libQt${_QT_LIBVER}Scxml.so

serialbus_PORT=		comms/${_QT_RELNAME}-serialbus
serialbus_LIB=		libQt${_QT_LIBVER}SerialBus.so

serialport_PORT=	comms/${_QT_RELNAME}-serialport
serialport_LIB=		libQt${_QT_LIBVER}SerialPort.so

speech_PORT=		accessibility/${_QT_RELNAME}-speech
speech_LIB=		libQt${_QT_LIBVER}TextToSpeech.so

sql_PORT=		databases/${_QT_RELNAME}-sql
sql_LIB=		libQt${_QT_LIBVER}Sql.so

sql-pgsql_PATH=		${LOCALBASE}/${QT_PLUGINDIR_REL}/sqldrivers/libqsqlpsql.so

.  if ${_QT_VERSION:M4*}
sql-sqlite2_PORT=	databases/${_QT_RELNAME}-sqlite-plugin
.  endif

sql-sqlite3_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/sqldrivers/libqsqlite.so

.  for db in ibase mysql odbc pgsql sqlite2 sqlite3 tds
.    if ${_QT_VERSION:M4*}
sql-${db}_PORT?=	databases/${_QT_RELNAME}-${db}-plugin
.    else
sql-${db}_PORT?=	databases/${_QT_RELNAME}-sqldrivers-${db}
.    endif
sql-${db}_PATH?=	${LOCALBASE}/${QT_PLUGINDIR_REL}/sqldrivers/libqsql${db:C/^sql//}.so
.  endfor

svg_PORT=		graphics/${_QT_RELNAME}-svg
svg_LIB=		libQt${_QT_LIBVER}Svg.so

testlib_PORT=		devel/${_QT_RELNAME}-testlib
testlib_LIB=		libQt${_QT_LIBVER}Test.so

uic_PORT=		devel/${_QT_RELNAME}-uic
uic_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/uic

uic3_PORT=		devel/${_QT_RELNAME}-uic3
uic3_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/uic3

uiplugin_PORT=		x11-toolkits/${_QT_RELNAME}-uiplugin
uiplugin_PATH=		${LOCALBASE}/${QT_INCDIR_REL}/QtUiPlugin/QtUiPlugin

uitools_PORT=		devel/${_QT_RELNAME}-uitools
uitools_PATH=		${LOCALBASE}/${QT_LIBDIR_REL}/libQt${_QT_LIBVER}UiTools.a

virtualkeyboard_PORT=	x11-toolkits/${_QT_RELNAME}-virtualkeyboard
virtualkeyboard_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/platforminputcontexts/libqtvirtualkeyboardplugin.so

webchannel_PORT=	www/${_QT_RELNAME}-webchannel
webchannel_LIB=		libQt${_QT_LIBVER}WebChannel.so

webengine_PORT=		www/${_QT_RELNAME}-webengine
webengine_LIB=		libQt${_QT_LIBVER}WebEngine.so

websockets_PORT=	www/${_QT_RELNAME}-websockets
websockets_LIB=		libQt${_QT_LIBVER}WebSockets.so

websockets-qml_PORT=	www/${_QT_RELNAME}-websockets-qml
websockets-qml_PATH=	${LOCALBASE}/${QT_QMLDIR_REL}/QtWebSockets/qmldir

webkit_PORT=		www/${_QT_RELNAME}-webkit
webkit_LIB=		libQt${_QT_LIBVER}WebKit.so

widgets_PORT=		x11-toolkits/${_QT_RELNAME}-widgets
widgets_LIB=		libQt${_QT_LIBVER}Widgets.so

x11extras_PORT=		x11/${_QT_RELNAME}-x11extras
x11extras_LIB=		libQt${_QT_LIBVER}X11Extras.so

xml_PORT=		textproc/${_QT_RELNAME}-xml
xml_LIB=		libQt${_QT_LIBVER}Xml.so

xmlpatterns_PORT=	textproc/${_QT_RELNAME}-xmlpatterns
xmlpatterns_LIB=	libQt${_QT_LIBVER}XmlPatterns.so

xmlpatterns-tool_PORT=	textproc/${_QT_RELNAME}-xmlpatterns-tool
xmlpatterns-tool_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/xmlpatterns

# Actually add the dependencies to the proper lists.
_USE_QT_ALL+=		${_USE_QT${_QT_VER}_ONLY}
_USE_QT=		${USE_QT}
# Iterate through components deprived of suffix.
.  for component in ${_USE_QT:O:u:C/_.+//}
# Check that the component is valid.
.    if ${_USE_QT_ALL:M${component}} != ""
# Skip meta-components (currently none).
.      if defined(${component}_PORT) && (defined(${component}_PATH) || defined(${component}_LIB))
# Check if a dependency type is explicitly requested.
.        if ${_USE_QT:M${component}_*} != "" && ${_USE_QT:M${component}} == ""
${component}_TYPE=		# empty
.          if ${_USE_QT:M${component}_build} != ""
${component}_TYPE+=		build
.          endif
.          if ${_USE_QT:M${component}_run} != ""
${component}_TYPE+=		run
.          endif
.        endif # ${_USE_QT:M${component}_*} != "" && ${_USE_QT:M${component}} == ""
# If no dependency type is set, default to full dependency.
.        if !defined(${component}_TYPE)
${component}_TYPE=		build run
.        endif
# Set real dependencies.
.        if defined(${component}_LIB) && ${${component}_TYPE:Mbuild} && ${${component}_TYPE:Mrun}
LIB_DEPENDS+=			${${component}_LIB}:${${component}_PORT}
.        else
${component}_PATH?=		${QT_LIBDIR}/${${component}_LIB}
${component}_DEPENDS=		${${component}_PATH}:${${component}_PORT}
.          if ${${component}_TYPE:Mbuild} != ""
BUILD_DEPENDS+=			${${component}_DEPENDS}
.          endif
.          if ${${component}_TYPE:Mrun} != ""
RUN_DEPENDS+=			${${component}_DEPENDS}
.          endif
.        endif # ${${component}_LIB} && ${${component}_TYPE:Mbuild} && ${${component}_TYPE:Mrun}
.      endif # defined(${component}_PORT) && defined(${component}_PATH)
.    else # ! ${_USE_QT_ALL:M${component}} != ""
IGNORE=				cannot be installed: unknown USE_QT component '${component}'
.    endif # ${_USE_QT_ALL:M${component}} != ""
.  endfor

.endif # defined(_QT_MK_POST_INCLUDED)
