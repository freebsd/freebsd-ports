#-*- tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
# Port variables:
# USE_QT*			- List of Qt modules to depend on, with optional '_build'
#					  and '_run' suffixes. Define it empty to include this file
#					  without depending on Qt ports.
# QT_DIST			- The port belongs to the Qt distribution. Set to 'yes' for
#					  Qt 4, or to the distribution name(s) for newer versions.
# QT_NONSTANDARD	- Suppress modification of configure and make environment.
#
# Global switches (for inclusion into /etc/make.conf):
# QT4_OPTIONS		- A list of (Qt 4-only) global options; can be CUPS, NAS
#					  and/or QGTKSTYLE. If set, Qt will be built with support
#					  for:
#					   * Common UNIX Printing System (CUPS);
#					   * Network Audio System (NAS);
#					   * GTK+-based Qt theme (QGTKSTYLE).

.if !defined(_POSTMKINCLUDED) && !defined(Qt_Pre_Include)

Qt_Include_MAINTAINER=	kde@FreeBSD.org
Qt_Pre_Include=	bsd.qt.mk

# Qt versions currently supported by the framework.
_QT_SUPPORTED?=	4 5
QT4_VERSION?=	4.8.7
QT5_VERSION?=	5.4.1

QT_PREFIX?=		${LOCALBASE}

_QT_RELNAME=	qt${_QT_VERSION:R:R}
_QT_VERSION=	# empty
.for ver in ${_QT_SUPPORTED}
. if defined(USE_QT${ver})
.  if empty(_QT_VERSION)
_QT_VERSION=	${QT${ver}_VERSION}
.  else
# Reject different USE_QT*.
IGNORE?=		can't be installed: different Qt versions specified via USE_QT[${_QT_SUPPORTED:S/ //g}] #'
.  endif
. endif
.endfor

.if empty(_QT_VERSION)
# The file was included without USE_QT*.
IGNORE?=		can't be installed: bsd.qt.mk may only be included via USE_QT[${_QT_SUPPORTED:S/ //g}] #'
.endif

.if defined(QT_DIST)
QT_NONSTANDARD=	yes

. if ! ${.MAKEFLAGS:MPREFIX=*}
PREFIX=			${QT_PREFIX}
. endif

MASTER_SITES=	${MASTER_SITE_QT}
# Useless, as it must be defined before including bsd.port.pre.mk (at least
# because of bsd.options.mk).
#PKGNAMEPREFIX?=	${_QT_RELNAME}-
DISTINFO_FILE=	${.CURDIR:H:H}/devel/${_QT_RELNAME}/distinfo

# Can go after a while.
CONFLICTS_BUILD=qt-3.* qt-copy-3.*

LICENSE?=		LGPL21

. if !exists(${PKGDIR}/pkg-descr)
DESCR?=			${.CURDIR:H:H}/devel/${_QT_RELNAME}/pkg-descr
. endif

# Stage support.
DESTDIRNAME=	INSTALL_ROOT

. if ${_QT_VERSION:M4*}
MASTER_SITE_SUBDIR=	official_releases/qt/${_QT_VERSION:R}/${_QT_VERSION}/
DISTNAME=		qt-everywhere-opensource-src-${_QT_VERSION}
DIST_SUBDIR=		KDE
. else
.  if ${_QT_VERSION:M*-*}
# Pre-releases.
MASTER_SITE_SUBDIR=	development_releases/qt/${_QT_VERSION:R}/${_QT_VERSION}/submodules/
.  else
MASTER_SITE_SUBDIR=	official_releases/qt/${_QT_VERSION:R}/${_QT_VERSION}/submodules/
.  endif
DISTNAME=		${QT_DIST:S,^,qt,:S,$,-opensource-src-${_QT_VERSION},}
DISTFILES=		${DISTNAME:S,$,${EXTRACT_SUFX},}
DIST_SUBDIR=		KDE/Qt/${_QT_VERSION}
USES+=			tar:xz

.  if ${.TARGETS:Mmakesum} || ${.TARGETS:Mfetch} && \
	defined(DISABLE_SIZE) && defined(NO_CHECKSUM)
# Ensure that the "makesum" target (with its inner "fetch" one) uses
# devel/qt*/distinfo for every port.
QT_DIST=		base declarative doc graphicaleffects imageformats \
				multimedia quick1 quickcontrols script serialport svg tools \
				translations webchannel webkit webkit-examples websockets x11extras xmlpatterns
.  endif

.  if ${QT_DIST} == "base" && ${PORTNAME} != "qmake"
# Qt configure requires pkg-config to detect dependencies.
USES+=			pkgconfig

# Set QMAKESPEC when building qtbase so that qmake (called by the configure
# script) can find the mkspecs we create ourselves in devel/qmake5.
CONFIGURE_ENV+=	QMAKESPEC="${QMAKESPEC}"
MAKE_ENV+=		QMAKESPEC="${QMAKESPEC}"
.  endif

# -nomake is only used by qtbase's configure script.
# Other ports from other Qt modules will automatically build examples and
# tests if the directories exist because of mkspecs/features/qt_parts.prf.
EXTRACT_AFTER_ARGS?=	${DISTNAME:S,$,/examples,:S,^,--exclude ,} \
				${DISTNAME:S,$,/tests,:S,^,--exclude ,}
. endif # ! ${_QT_VERSION:M4*}

CONFIGURE_ENV+=	MAKE="${MAKE:T}"

CONFIGURE_ARGS+=-opensource -confirm-license \
				-platform ${QMAKESPEC} \
				-no-pch \
				-prefix ${PREFIX} \
				-bindir ${PREFIX}/${QT_BINDIR_REL} \
				-headerdir ${PREFIX}/${QT_INCDIR_REL} \
				-libdir ${PREFIX}/${QT_LIBDIR_REL} \
				-plugindir ${PREFIX}/${QT_PLUGINDIR_REL} \
				-importdir ${PREFIX}/${QT_IMPORTDIR_REL} \
				-datadir ${PREFIX}/${QT_DATADIR_REL} \
				-docdir ${PREFIX}/${QT_DOCDIR_REL} \
				-translationdir ${PREFIX}/${QT_L10NDIR_REL} \
				-sysconfdir ${PREFIX}/${QT_ETCDIR_REL}

. if ${_QT_VERSION:M4*}
CONFIGURE_ARGS+=-fast \
				-system-libjpeg -system-libpng \
				-system-libmng -system-libtiff -system-zlib \
				-no-phonon-backend \
				-examplesdir ${PREFIX}/${QT_EXAMPLEDIR_REL}/examples \
				-demosdir ${PREFIX}/${QT_EXAMPLEDIR_REL}/demos
. else
CONFIGURE_ARGS+=-nomake examples -nomake tests \
				-archdatadir ${PREFIX}/${QT_ARCHDIR_REL} \
				-libexecdir ${PREFIX}/${QT_LIBEXECDIR_REL} \
				-qmldir ${PREFIX}/${QT_QMLDIR_REL} \
				-examplesdir ${PREFIX}/${QT_EXAMPLEDIR_REL} \
				-testsdir ${PREFIX}/${QT_TESTDIR_REL}
.  if ${ARCH} == i386 && empty(MACHINE_CPU:Msse2)
CONFIGURE_ARGS+=-no-sse2
.  endif
. endif

. if defined(WANT_QT_DEBUG) || defined(WITH_DEBUG)
WITH_DEBUG=		yes
STRIP=			# It's done prior to bsd.qt.mk inclusion.
CONFIGURE_ARGS+=-debug -separate-debug-info
# Override configuration in global qconfig.pri.
QMAKE_ARGS+=	QT_CONFIG+="debug separate_debug_info" \
				QT_CONFIG-="release"
PLIST_SUB+=		DEBUG=""
. else
CONFIGURE_ARGS+=-release -no-separate-debug-info
QMAKE_ARGS+=	QT_CONFIG+="release" \
				QT_CONFIG-="debug separate_debug_info"
PLIST_SUB+=		DEBUG="@comment "
. endif

. if defined(WANT_QT_VERBOSE_CONFIGURE)
CONFIGURE_ARGS+=-verbose
. endif

. if ${QT_DIST} == "base" || ${_QT_VERSION:M4*}
.  if ${_QT_VERSION:M4*}
_EXTRA_PATCHES_QT4=	${.CURDIR:H:H}/devel/${_QT_RELNAME}/files/extrapatch-src-corelib-global-qglobal.h
.  endif
EXTRA_PATCHES?=	${.CURDIR:H:H}/devel/${_QT_RELNAME}/files/extrapatch-configure \
		${.CURDIR:H:H}/devel/${_QT_RELNAME}/files/extrapatch-config.tests-unix-compile.test \
		${.CURDIR:H:H}/devel/${_QT_RELNAME}/files/extrapatch-libtool \
		${_EXTRA_PATCHES_QT4}
. endif

# Override settings installed in qconfig.h and *.pri files. The flags will be
# installed along with the port, but have to be passed as arguments while
# building the port itself. Flags prefixed with "-" (e.g., "-CUPS" and "-cups")
# are needed to disable some features.
. if !defined(${QT_MODNAME}) || empty(${QT_MODNAME})
# Used for both qconfig-*.h and qt_config_*.pri; it can't be empty.
QT_MODNAME=		${PORTNAME}
. endif
QT_DEFINES?=	# For qconfig.h flags (without "QT_" prefix).
QT_CONFIG?=		# For *.pri files QT_CONFIG flags.
. if ${QT_DEFINES}
QMAKE_ARGS+=	DEFINES+="${QT_DEFINES:O:u:C/^([^-])/QT_\1/:C/^-/QT_NO_/:O}"
.  if ${QT_DEFINES:N-*}
# Use a script to cleanup qconfig-modules.h (see qt-post-install).
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
.  endif
. endif
. if ${QT_CONFIG:N-*}
QMAKE_ARGS+=	QT_CONFIG+="${QT_CONFIG:N-*:O:u}"
. endif
. if ${QT_CONFIG:M-*}
QMAKE_ARGS+=	QT_CONFIG-="${QT_CONFIG:M-*:O:u:C/^-//}"
. endif

PLIST_SUB+=		SHORTVER=${_QT_VERSION:R} \
				FULLVER=${_QT_VERSION:C/-.*//}
.endif # defined(QT_DIST)

.if !defined(QT_NONSTANDARD)
CONFIGURE_ENV+=	QTDIR="${QT_PREFIX}" QMAKE="${QMAKE}" \
				MOC="${MOC}" RCC="${RCC}" UIC="${UIC}" \
				QMAKESPEC="${QMAKESPEC}"
CONFIGURE_ARGS+=--with-qt-includes=${QT_INCDIR} \
				--with-qt-libraries=${QT_LIBDIR} \
				--with-extra-includes=${LOCALBASE}/include \
				--with-extra-libs=${LOCALBASE}/lib
.endif # !defined(QT_NONSTANDARD)

.if ${_QT_VERSION:M4*}
QT_BINDIR_REL?=	bin
QT_LIBDIR_REL?=	lib/${_QT_RELNAME}
QT_PLUGINDIR_REL?=	${QT_LIBDIR_REL}/plugins
QT_IMPORTDIR_REL?=	${QT_LIBDIR_REL}/imports
.endif

# A wrapper (qtchooser) is used to invoke binaries.
QT_BINDIR_REL?=	${QT_ARCHDIR_REL}/bin
QT_INCDIR_REL?=	include/${_QT_RELNAME}
QT_LIBDIR_REL?=	lib
QT_ARCHDIR_REL?=${QT_LIBDIR_REL}/${_QT_RELNAME}
QT_PLUGINDIR_REL?=	${QT_ARCHDIR_REL}/plugins
QT_LIBEXECDIR_REL?=	libexec/${_QT_RELNAME}
QT_IMPORTDIR_REL?=	${QT_ARCHDIR_REL}/imports
QT_QMLDIR_REL?=	${QT_ARCHDIR_REL}/qml
QT_DATADIR_REL?=share/${_QT_RELNAME}
QT_DOCDIR_REL?=	share/doc/${_QT_RELNAME}
QT_L10NDIR_REL?=${QT_DATADIR_REL}/translations
QT_ETCDIR_REL?=	etc/xdg
QT_EXAMPLEDIR_REL?=	share/examples/${_QT_RELNAME}
QT_TESTDIR_REL?=${QT_DATADIR_REL}/tests

# Not customizable.
.if ${_QT_VERSION:M4*}
QT_MKSPECDIR_REL=	${QT_DATADIR_REL}/mkspecs

_QT_LIBVER=		# empty
_QT_BINSUFX=	-${_QT_RELNAME}
.else
QT_MKSPECDIR_REL=	${QT_ARCHDIR_REL}/mkspecs

_QT_LIBVER=		${_QT_VERSION:R:R}
_QT_BINSUFX=	# empty
.endif

LRELEASE?=		${QT_BINDIR}/lrelease${_QT_BINSUFX}
LUPDATE?=		${QT_BINDIR}/lupdate${_QT_BINSUFX}
MOC?=			${QT_BINDIR}/moc${_QT_BINSUFX}
RCC?=			${QT_BINDIR}/rcc
UIC?=			${QT_BINDIR}/uic${_QT_BINSUFX}
QMAKE?=			${QT_BINDIR}/qmake${_QT_BINSUFX}
# Needed to redefine the qmake target for internal Qt configuration.
_QMAKE?=		${QMAKE}
QMAKESPEC?=		${QT_MKSPECDIR}/freebsd-${QMAKE_COMPILER}

# The whole Qt distribution should be built with the same compiler, but it's
# better to support custom settings. Dereferencing the detection allows to
# avoid forking a shell on each inclusion of this file, and to catch any CXX
# customization (via USE_GCC, etc.).
QMAKE_COMPILER=	$$(ccver="$$(${CXX} --version)"; case "$$ccver" in *clang*) echo clang ;; *) echo g++ ;; esac)

# Import QMAKE_ENV and QMAKE_ARGS definitions.
USES+=			qmake:_env

PLIST_SUB+=		QT_PREFIX="${QT_PREFIX}"

.for dir in BIN INC LIB ARCH PLUGIN LIBEXEC IMPORT \
	QML DATA DOC L10N ETC EXAMPLE TEST MKSPEC
QT_${dir}DIR=	${QT_PREFIX}/${QT_${dir}DIR_REL}
PLIST_SUB+=		QT_${dir}DIR="${QT_${dir}DIR_REL}"
.endfor

.endif # !defined(_POSTMKINCLUDED) && !defined(Qt_Pre_Include)

.if defined(_POSTMKINCLUDED) && !defined(Qt_Post_Include)

Qt_Post_Include=	bsd.qt.mk

_USE_QT_ALL=	assistant clucene dbus declarative designer gui help \
				imageformats linguist linguisttools multimedia network opengl pixeltool \
				qdbusviewer qmake script scripttools sql sql-ibase sql-mysql \
				sql-odbc sql-pgsql sql-sqlite2 sql-sqlite3 svg testlib webkit \
				xml xmlpatterns

_USE_QT4_ONLY=	accessible assistant-adp assistantclient codecs-cn codecs-jp \
				codecs-kr codecs-tw corelib demo doc graphicssystems-opengl \
				help-tools iconengines inputmethods l10n makeqpf moc phonon \
				phonon-gst porting qdoc3 qmlviewer qt3support qtconfig \
				qtestlib qvfb rcc uic uic3 xmlpatterns-tool

_USE_QT5_ONLY=	buildtools concurrent core graphicaleffects \
				paths phonon4 printsupport qdbus qdoc qev qml quick \
				quickcontrols serialport uitools webchannel websockets \
				widgets x11extras

accessible_PORT=	accessibility/${_QT_RELNAME}-accessible
accessible_PATH=	${QT_PLUGINDIR}/accessible/libqtaccessiblewidgets.so

assistant_PORT=		devel/${_QT_RELNAME}-assistant
assistant_PATH=		${QT_BINDIR}/assistant${_QT_BINSUFX}

assistant-adp_PORT=	devel/${_QT_RELNAME}-assistant-adp
assistant-adp_PATH=	${QT_BINDIR}/assistant_adp

assistantclient_PORT=	devel/${_QT_RELNAME}-libqtassistantclient
assistantclient_PATH=	${QT_LIBDIR}/libQt${_QT_LIBVER}AssistantClient.so

buildtools_PORT=	devel/${_QT_RELNAME}-buildtools
buildtools_PATH=	${MOC}

clucene_PORT=		textproc/clucene-${_QT_RELNAME}
clucene_PATH=		${QT_LIBDIR}/libQt${_QT_LIBVER}CLucene.so

codecs-cn_PORT=		chinese/${_QT_RELNAME}-codecs-cn
codecs-cn_PATH=		${QT_PLUGINDIR}/codecs/libqcncodecs.so

codecs-jp_PORT=		japanese/${_QT_RELNAME}-codecs-jp
codecs-jp_PATH=		${QT_PLUGINDIR}/codecs/libqjpcodecs.so

codecs-kr_PORT=		korean/${_QT_RELNAME}-codecs-kr
codecs-kr_PATH=		${QT_PLUGINDIR}/codecs/libqkrcodecs.so

codecs-tw_PORT=		chinese/${_QT_RELNAME}-codecs-tw
codecs-tw_PATH=		${QT_PLUGINDIR}/codecs/libqtwcodecs.so

concurrent_PORT=	devel/${_QT_RELNAME}-concurrent
concurrent_PATH=	${QT_LIBDIR}/libQt${_QT_LIBVER}Concurrent.so

core_PORT=			devel/${_QT_RELNAME}-core
core_PATH=			${QT_LIBDIR}/libQt${_QT_LIBVER}Core.so

corelib_PORT=		devel/${_QT_RELNAME}-corelib
corelib_PATH=		${core_PATH}

dbus_PORT=			devel/dbus-${_QT_RELNAME}
dbus_PATH=			${QT_LIBDIR}/libQt${_QT_LIBVER}DBus.so

declarative_PORT=	x11-toolkits/${_QT_RELNAME}-declarative
declarative_PATH=	${QT_LIBDIR}/libQt${_QT_LIBVER}Declarative.so

demo_PORT=			misc/${_QT_RELNAME}-qtdemo
demo_PATH=			${QT_BINDIR}/qtdemo

designer_PORT=		devel/${_QT_RELNAME}-designer
designer_PATH=		${QT_BINDIR}/designer${_QT_BINSUFX}

doc_PORT=			misc/${_QT_RELNAME}-doc
doc_PATH=			${_QT_RELNAME}-doc>=${_QT_VERSION:R:R}

graphicaleffects_PORT=	graphics/${_QT_RELNAME}-graphicaleffects
graphicaleffects_PATH=	${QT_QMLDIR}/QtGraphicalEffects/qmldir

graphicssystems-opengl_PORT=	x11/${_QT_RELNAME}-graphicssystems-opengl
graphicssystems-opengl_PATH=	${QT_PLUGINDIR}/graphicssystems/libqglgraphicssystem.so

gui_PORT=			x11-toolkits/${_QT_RELNAME}-gui
gui_PATH=			${QT_LIBDIR}/libQt${_QT_LIBVER}Gui.so

help_PORT=			devel/${_QT_RELNAME}-help
help_PATH=			${QT_LIBDIR}/libQt${_QT_LIBVER}Help.so

help-tools_PORT=	devel/${_QT_RELNAME}-help-tools
help-tools_PATH=	${QT_BINDIR}/qhelpgenerator

iconengines_PORT=	graphics/${_QT_RELNAME}-iconengines
iconengines_PATH=	${QT_PLUGINDIR}/iconengines/libqsvgicon.so

imageformats_PORT=	graphics/${_QT_RELNAME}-imageformats
imageformats_PATH=	${QT_PLUGINDIR}/imageformats/libqtiff.so

inputmethods_PORT=	x11/${_QT_RELNAME}-inputmethods
inputmethods_PATH=	${QT_PLUGINDIR}/inputmethods/libqimsw-multi.so

linguist_PORT=		devel/${_QT_RELNAME}-linguist
linguist_PATH=		${QT_BINDIR}/linguist${_QT_BINSUFX}

linguisttools_PORT=	devel/${_QT_RELNAME}-linguisttools
linguisttools_PATH=	${LRELEASE}

l10n_PORT=			misc/${_QT_RELNAME}-l10n
l10n_PATH=			${_QT_RELNAME}-l10n>=${_QT_VERSION:R:R}

makeqpf_PORT=		devel/${_QT_RELNAME}-makeqpf
makeqpf_PATH=		${QT_BINDIR}/makeqpf${_QT_BINSUFX}

moc_PORT=			devel/${_QT_RELNAME}-moc
moc_PATH=			${MOC}

multimedia_PORT=	multimedia/${_QT_RELNAME}-multimedia
multimedia_PATH=	${QT_LIBDIR}/libQt${_QT_LIBVER}Multimedia.so

network_PORT=		net/${_QT_RELNAME}-network
network_PATH=		${QT_LIBDIR}/libQt${_QT_LIBVER}Network.so

opengl_PORT=		graphics/${_QT_RELNAME}-opengl
opengl_PATH=		${QT_LIBDIR}/libQt${_QT_LIBVER}OpenGL.so

paths_PORT=		sysutils/${_QT_RELNAME}-qtpaths
paths_PATH=		${QT_BINDIR}/qtpaths

pixeltool_PORT=		graphics/${_QT_RELNAME}-pixeltool
pixeltool_PATH=		${QT_BINDIR}/pixeltool

phonon_PORT=		multimedia/phonon
phonon_PATH=		${QT_LIBDIR}/libphonon.so

phonon4_PORT=		multimedia/${_QT_RELNAME}-phonon4
phonon4_PATH=		${QT_LIBDIR}/libphonon4${_QT_RELNAME}.so

phonon-gst_PORT=	multimedia/phonon-gstreamer
phonon-gst_PATH=	${QT_PLUGINDIR}/phonon_backend/libphonon_gstreamer.so

porting_PORT=		devel/${_QT_RELNAME}-porting
porting_PATH=		${QT_BINDIR}/qt3to4

printsupport_PORT=	print/${_QT_RELNAME}-printsupport
printsupport_PATH=	${QT_LIBDIR}/libQt${_QT_LIBVER}PrintSupport.so

qdbus_PORT=			devel/${_QT_RELNAME}-qdbus
qdbus_PATH=			${QT_BINDIR}/qdbus

qdbusviewer_PORT=	devel/${_QT_RELNAME}-qdbusviewer
qdbusviewer_PATH=	${QT_BINDIR}/qdbusviewer

qdoc_PORT=			devel/${_QT_RELNAME}-qdoc
qdoc_PATH=			${QT_BINDIR}/qdoc

qdoc3_PORT=			devel/${_QT_RELNAME}-qdoc3
qdoc3_PATH=			${QT_BINDIR}/qdoc3

qev_PORT=			x11/${_QT_RELNAME}-qev
qev_PATH=			${QT_BINDIR}/qev

qmake_PORT=			devel/qmake${_QT_VERSION:R:R}
qmake_PATH=			${QMAKE}

qml_PORT=			lang/${_QT_RELNAME}-qml
qml_PATH=			${QT_LIBDIR}/libQt${_QT_LIBVER}Qml.so

qmlviewer_PORT=		devel/${_QT_RELNAME}-qmlviewer
qmlviewer_PATH=		${QT_BINDIR}/qmlviewer

qt3support_PORT=	devel/${_QT_RELNAME}-qt3support
qt3support_PATH=	${QT_LIBDIR}/libQt${_QT_LIBVER}3Support.so

qtconfig_PORT=		misc/${_QT_RELNAME}-qtconfig
qtconfig_PATH=		${QT_BINDIR}/qtconfig${_QT_BINSUFX}

qtestlib_PORT=		${testlib_PORT}
qtestlib_PATH=		${testlib_PATH}

quick_PORT=			x11-toolkits/${_QT_RELNAME}-quick
quick_PATH=			${QT_LIBDIR}/libQt${_QT_LIBVER}Quick.so

quickcontrols_PORT=	x11-toolkits/${_QT_RELNAME}-quickcontrols
quickcontrols_PATH=	${QT_QMLDIR}/QtQuick/Controls/qmldir

qvfb_PORT=			devel/${_QT_RELNAME}-qvfb
qvfb_PATH=			${QT_BINDIR}/qvfb${_QT_BINSUFX}

rcc_PORT=			devel/${_QT_RELNAME}-rcc
rcc_PATH=			${RCC}

script_PORT=		devel/${_QT_RELNAME}-script
script_PATH=		${QT_LIBDIR}/libQt${_QT_LIBVER}Script.so

scripttools_PORT=	devel/${_QT_RELNAME}-scripttools
scripttools_PATH=	${QT_LIBDIR}/libQt${_QT_LIBVER}ScriptTools.so

serialport_PORT=	comms/${_QT_RELNAME}-serialport
serialport_PATH=	${QT_LIBDIR}/libQt${_QT_LIBVER}SerialPort.so

sql_PORT=			databases/${_QT_RELNAME}-sql
sql_PATH=			${QT_LIBDIR}/libQt${_QT_LIBVER}Sql.so

sql-pgsql_PATH=		${QT_PLUGINDIR}/sqldrivers/libqsqlpsql.so

.if ${_QT_VERSION:M4*}
sql-sqlite2_PORT=	databases/${_QT_RELNAME}-sqlite-plugin
.endif

sql-sqlite3_PATH=	${QT_PLUGINDIR}/sqldrivers/libqsqlite.so

.for db in ibase mysql odbc pgsql sqlite2 sqlite3
.if ${_QT_VERSION:M4*}
sql-${db}_PORT?=	databases/${_QT_RELNAME}-${db}-plugin
.else
sql-${db}_PORT?=	databases/${_QT_RELNAME}-sqldrivers-${db}
.endif
sql-${db}_PATH?=	${QT_PLUGINDIR}/sqldrivers/libqsql${db:C/^sql//}.so
.endfor

svg_PORT=			graphics/${_QT_RELNAME}-svg
svg_PATH=			${QT_LIBDIR}/libQt${_QT_LIBVER}Svg.so

testlib_PORT=		devel/${_QT_RELNAME}-testlib
testlib_PATH=		${QT_LIBDIR}/libQt${_QT_LIBVER}Test.so

uic_PORT=			devel/${_QT_RELNAME}-uic
uic_PATH=			${UIC}

uic3_PORT=			devel/${_QT_RELNAME}-uic3
uic3_PATH=			${QT_BINDIR}/uic3

uitools_PORT=		devel/${_QT_RELNAME}-uitools
uitools_PATH=		${QT_LIBDIR}/libQt${_QT_LIBVER}UiTools.a

webchannel_PORT=	www/${_QT_RELNAME}-webchannel
webchannel_PATH=	${QT_LIBDIR}/libQt${_QT_LIBVER}WebChannel.so

websockets_PORT=	www/${_QT_RELNAME}-websockets
websockets_PATH=	${QT_LIBDIR}/libQt${_QT_LIBVER}WebSockets.so

webkit_PORT=		www/webkit-${_QT_RELNAME}
webkit_PATH=		${QT_LIBDIR}/libQt${_QT_LIBVER}WebKit.so

widgets_PORT=		x11-toolkits/${_QT_RELNAME}-widgets
widgets_PATH=		${QT_LIBDIR}/libQt${_QT_LIBVER}Widgets.so

x11extras_PORT=		x11/${_QT_RELNAME}-x11extras
x11extras_PATH=		${QT_LIBDIR}/libQt${_QT_LIBVER}X11Extras.so

xml_PORT=			textproc/${_QT_RELNAME}-xml
xml_PATH=			${QT_LIBDIR}/libQt${_QT_LIBVER}Xml.so

xmlpatterns_PORT=	textproc/${_QT_RELNAME}-xmlpatterns
xmlpatterns_PATH=	${QT_LIBDIR}/libQt${_QT_LIBVER}XmlPatterns.so

xmlpatterns-tool_PORT=	textproc/${_QT_RELNAME}-xmlpatterns-tool
xmlpatterns-tool_PATH=	${QT_BINDIR}/xmlpatterns

_USE_QT_ALL+=	${_USE_QT${_QT_VERSION:R:R}_ONLY}
.for comp in ${_USE_QT_ALL}
${comp}_BUILD_DEPENDS?=	${${comp}_PATH}:${${comp}_PORT}
${comp}_RUN_DEPENDS?=	${${comp}_PATH}:${${comp}_PORT}
${comp}_build_BUILD_DEPENDS?=	${${comp}_BUILD_DEPENDS}
${comp}_run_RUN_DEPENDS?=	${${comp}_RUN_DEPENDS}
_USE_QT_ALL_SUFFIXED+=	${comp} ${comp}_build ${comp}_run
.endfor

_USE_QT=		${USE_QT${_QT_VERSION:R:R}}
.for comp in ${_USE_QT:O:u}
. if ${_USE_QT_ALL_SUFFIXED:M${comp}}
BUILD_DEPENDS+=	${${comp}_BUILD_DEPENDS}
RUN_DEPENDS+=	${${comp}_RUN_DEPENDS}
. else
IGNORE?=		can't be installed: unknown USE_QT${_QT_VERSION:R:R} component '${comp}' #'
. endif
.endfor

.if defined(QT_DIST) && ! ${_QT_VERSION:M4*}
. if ${QT_DIST} == "base"
# qtbase requires some tools to be symlinked to the build directory.
_QT_TOOLS=		# empty
.  if ${PORTNAME} != "qmake"
_QT_TOOLS+=		${QMAKE}
.  endif
.  if ${PORTNAME} != "buildtools"
_QT_TOOLS+=		${MOC} ${RCC}
.  endif
.  if ${PORTNAME} != "qdoc"
_QT_TOOLS+=		qdoc
.  endif
.  if ${PORTNAME} != "dbus"
_QT_TOOLS+=		qdbuscpp2xml qdbusxml2cpp
.  endif
.  if ${PORTNAME} != "widgets"
_QT_TOOLS+=		${UIC}
.  endif

pre-configure: qtbase-pre-configure
qtbase-pre-configure:
.  for tool in ${_QT_TOOLS}
	@${TEST} -e ${QT_BINDIR}/${tool:T} && \
		${LN} -sf ${QT_BINDIR}/${tool:T} ${CONFIGURE_WRKSRC}/bin/${tool:T} || \
		${TRUE}
.  endfor

# Add ${LOCALBASE}/lib to DEFAULT_LIBDIRS, which we use to filter out
# certain paths from pkg-config calls (see the explanation in
# devel/qt5/files/patch-configure) as well as for setting
# QMAKE_DEFAULT_LIBDIR in mkspecs/qconfig.pri. Part of the solution for
# ports/194088.
post-patch: qtbase-post-patch
qtbase-post-patch:
	${REINPLACE_CMD} -e "/DEFAULT_LIBDIRS=/ s,\\\\\"\\\\n,\\\\n${LOCALBASE}/lib&," \
		${WRKSRC}/configure

.  if ${PORTNAME} != "qmake"
_QMAKE=			${CONFIGURE_WRKSRC}/bin/qmake

post-configure: qmake-configure
.  endif
. endif # ${QT_DIST} == "base"

# Qt 5.3.2 introduced a check in mkspecs/features/create_cmake.prf that
# requires tests/auto/cmake to be present, otherwise the configure stage will
# fail.
# Since we cannot extract tests/auto/cmake/ and exclude tests/ at the same
# time, we have to disable the check in a cache file (the only way to get this
# value through to the configure script in qtbase).
pre-configure: qt5-pre-configure
qt5-pre-configure:
	${ECHO_CMD} 'CMAKE_MODULE_TESTS = -' > ${WRKSRC}/.qmake.cache

pre-install: qt-pre-install
qt-pre-install:
# Search both in CONFIGURE_WRKSRC and WRKSRC, as the former is not
# a subdirectory of the latter for out-of-source builds.
	@${FIND} ${WRKSRC} ${CONFIGURE_WRKSRC} -name "Makefile*" -type f | \
		${XARGS} ${REINPLACE_CMD} -e 's,${PREFIX}/${QT_LIBDIR_REL}/pkgconfig,${PREFIX}/libdata/pkgconfig,g'

post-install: qt-post-install
qt-post-install:
. if ${QT_DEFINES:N-*}
# We can't use SUB_FILES with a shared pkg-deinstall.in.
# We need it to be a script instead of a group of @unexecs, otherwise
# qconfig-modules.h cleanup will be run in pre-deinstall stage, which is
# useless. This will probably be replaced by a Keywords/ script in the future.
	@${SED} -e 's,%%QT_MODNAME%%,${QT_MODNAME},g' \
		-e 's,%%QT_INCDIR%%,${QT_INCDIR},g' \
		${.CURDIR:H:H}/devel/${_QT_RELNAME}/${FILESDIR:T}/${PKGDEINSTALL:T}.in > \
		${PKGDEINSTALL}
	@${MKDIR} ${STAGEDIR}${QT_INCDIR}/QtCore/modules
	@${ECHO_CMD} -n \
		> ${STAGEDIR}${QT_INCDIR}/QtCore/modules/qconfig-${QT_MODNAME}.h
.  for def in ${QT_DEFINES:N-*:O:u:C/=.*$//}
	@${ECHO_CMD} "#if !defined(QT_${def}) && !defined(QT_NO_${def})" \
		>> ${STAGEDIR}${QT_INCDIR}/QtCore/modules/qconfig-${QT_MODNAME}.h
	${ECHO_CMD} "# define QT_${def}" \
		>> ${STAGEDIR}${QT_INCDIR}/QtCore/modules/qconfig-${QT_MODNAME}.h
	@${ECHO_CMD} "#endif" \
		>> ${STAGEDIR}${QT_INCDIR}/QtCore/modules/qconfig-${QT_MODNAME}.h
	@${ECHO_CMD} \
		>> ${STAGEDIR}${QT_INCDIR}/QtCore/modules/qconfig-${QT_MODNAME}.h
.  endfor
	@${ECHO_CMD} "${QT_PREFIX}/${QT_INCDIR_REL}/QtCore/modules/qconfig-${QT_MODNAME}.h" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@exec echo '#include <QtCore/modules/qconfig-${QT_MODNAME}.h>' >> ${QT_PREFIX}/${QT_INCDIR_REL}/QtCore/qconfig-modules.h" \
		>> ${TMPPLIST}
. endif # ${QT_DEFINES:N-*}
. if ${QT_CONFIG:N-*}
	@${MKDIR} ${STAGEDIR}${QT_MKSPECDIR}/modules
	${ECHO_CMD} "QT_CONFIG += ${QT_CONFIG:N-*:O:u}" \
		> ${STAGEDIR}${QT_MKSPECDIR}/modules/qt_config_${QT_MODNAME}.pri
	@${ECHO_CMD} "${QT_PREFIX}/${QT_MKSPECDIR_REL}/modules/qt_config_${QT_MODNAME}.pri" \
		>> ${TMPPLIST}
. endif # ${QT_CONFIG:N-*}
.endif # defined(QT_DIST) && ! ${_QT_VERSION:M4*}

.endif # defined(_POSTMKINCLUDED) && !defined(Qt_Post_Include)
