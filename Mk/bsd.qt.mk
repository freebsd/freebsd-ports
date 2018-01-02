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
QT5_VERSION?=	5.7.1

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

MASTER_SITES=	${MASTER_SITE_QT}
DISTINFO_FILE?=	${.CURDIR:H:H}/devel/${_QT_RELNAME}/distinfo

LICENSE?=		LGPL21

. if !exists(${PKGDIR}/pkg-descr)
DESCR?=			${.CURDIR:H:H}/devel/${_QT_RELNAME}/pkg-descr
. endif

# Stage support.
DESTDIRNAME=	INSTALL_ROOT

. if ${_QT_VERSION:M4*}
MASTER_SITE_SUBDIR?=	official_releases/qt/${_QT_VERSION:R}/${_QT_VERSION}/
DISTNAME=		qt-everywhere-opensource-src-${_QT_VERSION}
DIST_SUBDIR=		KDE
. else
MASTER_SITE_SUBDIR?=	official_releases/qt/${_QT_VERSION:R}/${_QT_VERSION}/submodules/
DISTNAME=		${QT_DIST:S,^,qt,:S,$,-opensource-src-${DISTVERSION},}
DISTFILES=		${DISTNAME:S,$,${EXTRACT_SUFX},}
DIST_SUBDIR=		KDE/Qt/${_QT_VERSION}

USES+=			tar:xz

# Qt (at least when used with qmake) has a tendency to overlink: some libraries
# have dependencies on others in the mkspec configurations and the latter are
# always passed to the linker even if they are not actually used. By passing
# --as-needed to the linker by default when building the Qt ports we do not
# have to declare a lot of unnecessary dependencies in USE_QT5.
# This could arguably work for Qt4 too, but since it is maintenance mode it is
# better not to fix what is not explicitly broken there.
LDFLAGS+=		-Wl,--as-needed

.  if ${.TARGETS:Mmakesum} || ${.TARGETS:Mfetch} && \
	defined(DISABLE_SIZE) && defined(NO_CHECKSUM)
# Ensure that the "makesum" target (with its inner "fetch" one) uses
# devel/qt*/distinfo for every port.
.		if ${DISTINFO_FILE:H} == ${.CURDIR:H:H}/devel/${_QT_RELNAME}
QT_DIST=		3d base canvas3d charts connectivity datavis3d declarative \
				declarative-render2d gamepad graphicaleffects imageformats \
				location multimedia quickcontrols quickcontrols2 script scxml \
				sensors serialbus serialport svg tools translations \
				virtualkeyboard wayland webchannel webengine \
				websockets x11extras xmlpatterns
.		endif
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
# Work around a bug in current binutils, where the gold linker creates
# duplicate symbols. See pr 218187. Disable the gold-linker for Qt5 ports.
CONFIGURE_ARGS+=	-no-use-gold-linker
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
_EXTRA_PATCHES_QT4=	${.CURDIR:H:H}/devel/${_QT_RELNAME}/files/extrapatch-src-corelib-global-qglobal.h \
					${.CURDIR:H:H}/devel/${_QT_RELNAME}/files/extrapatch-libtool
# Patch in proper name for armv6 architecture: https://gcc.gnu.org/ml/gcc-patches/2015-06/msg01679.html
_EXTRA_PATCHES_QT4+=	${.CURDIR:H:H}/devel/${_QT_RELNAME}/files/extrapatch-armv6
.  else
_EXTRA_PATCHES_QT5=	${.CURDIR:H:H}/devel/${_QT_RELNAME}/files/extrapatch-mkspecs_features_create__cmake.prf \
					${.CURDIR:H:H}/devel/${_QT_RELNAME}/files/extrapatch-mkspecs_features_qt__module.prf \
					${.CURDIR:H:H}/devel/${_QT_RELNAME}/files/extrapatch-config.tests_unix_arch.test
.  endif
EXTRA_PATCHES?=	${.CURDIR:H:H}/devel/${_QT_RELNAME}/files/extrapatch-configure \
		${.CURDIR:H:H}/devel/${_QT_RELNAME}/files/extrapatch-config.tests-unix-compile.test \
		${_EXTRA_PATCHES_QT4} ${_EXTRA_PATCHES_QT5}
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

# Add a RUN_DEPENDS on misc/qtchooser to select the binaries.
# The binaries of both supported Qt versions are installed to
# ${LOCALBASE}/lib/qt[45]/bin. The port misc/qtchooser installs
# wrapper binaries into ${LOCALBASE}/bin, and chooses the correct
# one depending on the value of QT_SELECT (which we pass to both
# CONFIGURE_ENV and MAKE_ENV). Therefore make all QT_DIST ports
# RUN_DEPEND on it.
RUN_DEPENDS+=	qtchooser:misc/qtchooser

PLIST_SUB+=		SHORTVER=${DISTVERSION:R} \
				FULLVER=${DISTVERSION:C/-.*//}
.endif # defined(QT_DIST)

# A wrapper (qtchooser) is used to invoke binaries.
QT_BINDIR_REL?=	${QT_ARCHDIR_REL}/bin
QT_INCDIR_REL?=	include/${_QT_RELNAME}
QT_LIBDIR_REL?=	lib/${_QT_RELNAME}
QT_ARCHDIR_REL?=${QT_LIBDIR_REL}
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
QT_CMAKEDIR_REL?=	lib/cmake
QT_QTCHOOSERDIR_REL?=	${QT_ETCDIR_REL}/qtchooser

# Not customizable.
.if ${_QT_VERSION:M4*}
QT_MKSPECDIR_REL=	${QT_DATADIR_REL}/mkspecs

_QT_LIBVER=		# empty
.else
QT_MKSPECDIR_REL=	${QT_ARCHDIR_REL}/mkspecs

_QT_LIBVER=		${_QT_VERSION:R:R}
.endif

LRELEASE?=		${QT_BINDIR}/lrelease
LUPDATE?=		${QT_BINDIR}/lupdate
MOC?=			${QT_BINDIR}/moc
RCC?=			${QT_BINDIR}/rcc
UIC?=			${QT_BINDIR}/uic
QMAKE?=			${QT_BINDIR}/qmake
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

.for dir in BIN INC LIB ARCH PLUGIN LIBEXEC IMPORT \
	QML DATA DOC L10N ETC EXAMPLE TEST MKSPEC \
	CMAKE QTCHOOSER
QT_${dir}DIR=	${PREFIX}/${QT_${dir}DIR_REL}
# Export all directories to the plist substituion for QT_DIST ports.
# For the others, exclude QT_CMAKEDIR and QT_ETCDIR.
.  if (${dir:NCMAKE} && ${dir:NETC}) || defined(QT_DIST)
PLIST_SUB+=		QT_${dir}DIR="${QT_${dir}DIR_REL}"
.  endif
.endfor

# Pass the chosen Qt version to the environment for qtchooser.
CONFIGURE_ENV+=	QT_SELECT=${_QT_RELNAME}
MAKE_ENV+=	QT_SELECT=${_QT_RELNAME}

.endif # !defined(_POSTMKINCLUDED) && !defined(Qt_Pre_Include)

.if defined(_POSTMKINCLUDED) && !defined(Qt_Post_Include)

Qt_Post_Include=	bsd.qt.mk

.if !defined(QT_NONSTANDARD)
CONFIGURE_ENV+=	QTDIR="${QT_ARCHDIR}" QMAKE="${QMAKE}" \
				MOC="${MOC}" RCC="${RCC}" UIC="${UIC}" \
				QMAKESPEC="${QMAKESPEC}"
CONFIGURE_ARGS+=--with-qt-includes=${QT_INCDIR} \
				--with-qt-libraries=${QT_LIBDIR} \
				--with-extra-includes=${LOCALBASE}/include \
				--with-extra-libs=${LOCALBASE}/lib
.endif # !defined(QT_NONSTANDARD)

_USE_QT_ALL=	assistant dbus declarative designer doc gui help \
				imageformats l10n linguist linguisttools multimedia \
				network opengl pixeltool qdbusviewer qmake script \
				scripttools sql sql-mysql sql-odbc sql-pgsql \
				sql-sqlite2 sql-sqlite3 svg testlib webkit \
				xml xmlpatterns
.if ${ARCH} == amd64 || ${ARCH} == i386
_USE_QT_ALL+=	sql-ibase
.endif

_USE_QT4_ONLY=	accessible assistant-adp assistantclient clucene codecs-cn codecs-jp \
				codecs-kr codecs-tw corelib demo graphicssystems-opengl \
				help-tools iconengines inputmethods makeqpf moc phonon \
				phonon-gst porting qdoc3 qmlviewer qt3support qtconfig \
				qtestlib qvfb rcc uic uic3 xmlpatterns-tool

_USE_QT5_ONLY=	3d buildtools canvas3d charts concurrent connectivity \
				core datavis3d declarative-render2d diag examples gamepad \
				graphicaleffects location paths phonon4 plugininfo printsupport \
				qdbus qdoc qdoc-data qev qml quick quickcontrols \
				quickcontrols2 scxml sensors serialbus serialport \
				sql-tds uiplugin uitools virtualkeyboard wayland webchannel \
				webengine websockets websockets-qml widgets x11extras

3d_PORT=		graphics/${_QT_RELNAME}-3d
3d_LIB=		libQt${_QT_LIBVER}3DCore.so

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
concurrent_LIB=	libQt${_QT_LIBVER}Concurrent.so

connectivity_PORT=	comms/${_QT_RELNAME}-connectivity
connectivity_LIB=	libQt${_QT_LIBVER}Bluetooth.so

core_PORT=			devel/${_QT_RELNAME}-core
core_LIB=			libQt${_QT_LIBVER}Core.so

corelib_PORT=		devel/${_QT_RELNAME}-corelib
corelib_LIB=		${core_LIB}

datavis3d_PORT=		x11-toolkits/${_QT_RELNAME}-datavis3d
datavis3d_LIB=		libQt${_QT_LIBVER}DataVisualization.so

dbus_PORT=			devel/${_QT_RELNAME}-dbus
dbus_LIB=			libQt${_QT_LIBVER}DBus.so

declarative_PORT=	x11-toolkits/${_QT_RELNAME}-declarative
declarative_LIB=	libQt${_QT_LIBVER}Declarative.so

declarative-render2d_PORT=	x11-toolkits/${_QT_RELNAME}-declarative-render2d
declarative-render2d_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/scenegraph/libsoftwarecontext.so

demo_PORT=			misc/${_QT_RELNAME}-qtdemo
demo_PATH=			${LOCALBASE}/${QT_BINDIR_REL}/qtdemo

designer_PORT=		devel/${_QT_RELNAME}-designer
designer_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/designer

diag_PORT=		sysutils/${_QT_RELNAME}-qtdiag
diag_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qtdiag

doc_PORT=			misc/${_QT_RELNAME}-doc
doc_PATH=			${_QT_RELNAME}-doc>=${_QT_VERSION:R:R}

examples_PORT=		misc/${_QT_RELNAME}-examples
examples_PATH=		${_QT_RELNAME}-examples>=${_QT_VERSION:R:R}

gamepad_PORT=		x11-toolkits/${_QT_RELNAME}-gamepad
gamepad_LIB=		libQt${_QT_LIBVER}Gamepad.so

graphicaleffects_PORT=	graphics/${_QT_RELNAME}-graphicaleffects
graphicaleffects_PATH=	${LOCALBASE}/${QT_QMLDIR_REL}/QtGraphicalEffects/qmldir

graphicssystems-opengl_PORT=	x11/${_QT_RELNAME}-graphicssystems-opengl
graphicssystems-opengl_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/graphicssystems/libqglgraphicssystem.so

gui_PORT=			x11-toolkits/${_QT_RELNAME}-gui
gui_LIB=			libQt${_QT_LIBVER}Gui.so

help_PORT=			devel/${_QT_RELNAME}-help
help_LIB=			libQt${_QT_LIBVER}Help.so

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

l10n_PORT=			misc/${_QT_RELNAME}-l10n
l10n_PATH=			${_QT_RELNAME}-l10n>=${_QT_VERSION:R:R}

makeqpf_PORT=		devel/${_QT_RELNAME}-makeqpf
makeqpf_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/makeqpf

moc_PORT=			devel/${_QT_RELNAME}-moc
moc_PATH=			${LOCALBASE}/${QT_BINDIR_REL}/moc

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

phonon_PORT=		multimedia/phonon
phonon_LIB=		libphonon.so

phonon4_PORT=		multimedia/${_QT_RELNAME}-phonon4
phonon4_LIB=		libphonon4${_QT_RELNAME}.so

phonon-gst_PORT=	multimedia/phonon-gstreamer
phonon-gst_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/phonon_backend/libphonon_gstreamer.so

plugininfo_PORT=		sysutils/${_QT_RELNAME}-qtplugininfo
plugininfo_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qtplugininfo

porting_PORT=		devel/${_QT_RELNAME}-porting
porting_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qt3to4

printsupport_PORT=	print/${_QT_RELNAME}-printsupport
printsupport_LIB=	libQt${_QT_LIBVER}PrintSupport.so

qdbus_PORT=			devel/${_QT_RELNAME}-qdbus
qdbus_PATH=			${LOCALBASE}/${QT_BINDIR_REL}/qdbus

qdbusviewer_PORT=	devel/${_QT_RELNAME}-qdbusviewer
qdbusviewer_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/qdbusviewer

qdoc_PORT=			devel/${_QT_RELNAME}-qdoc
qdoc_PATH=			${LOCALBASE}/${QT_BINDIR_REL}/qdoc

qdoc-data_PORT=		devel/${_QT_RELNAME}-qdoc-data
qdoc-data_PATH=		${LOCALBASE}/${QT_DOCDIR_REL}/global/config.qdocconf

qdoc3_PORT=			devel/${_QT_RELNAME}-qdoc3
qdoc3_PATH=			${LOCALBASE}/${QT_BINDIR_REL}/qdoc3

qev_PORT=			x11/${_QT_RELNAME}-qev
qev_PATH=			${LOCALBASE}/${QT_BINDIR_REL}/qev

qmake_PORT=			devel/${_QT_RELNAME}-qmake
qmake_PATH=			${LOCALBASE}/${QT_BINDIR_REL}/qmake

qml_PORT=			lang/${_QT_RELNAME}-qml
qml_LIB=			libQt${_QT_LIBVER}Qml.so

qmlviewer_PORT=		devel/${_QT_RELNAME}-qmlviewer
qmlviewer_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qmlviewer

qt3support_PORT=	devel/${_QT_RELNAME}-qt3support
qt3support_LIB=		libQt${_QT_LIBVER}3Support.so

qtconfig_PORT=		misc/${_QT_RELNAME}-qtconfig
qtconfig_PATH=		${LOCALBASE}/${QT_BINDIR_REL}/qtconfig

qtestlib_PORT=		${testlib_PORT}
qtestlib_LIB=		${testlib_LIB}

quick_PORT=			x11-toolkits/${_QT_RELNAME}-quick
quick_LIB=			libQt${_QT_LIBVER}Quick.so

quickcontrols_PORT=	x11-toolkits/${_QT_RELNAME}-quickcontrols
quickcontrols_PATH=	${LOCALBASE}/${QT_QMLDIR_REL}/QtQuick/Controls/qmldir

quickcontrols2_PORT=	x11-toolkits/${_QT_RELNAME}-quickcontrols2
quickcontrols2_LIB=	libQt${_QT_LIBVER}QuickControls2.so

qvfb_PORT=			devel/${_QT_RELNAME}-qvfb
qvfb_PATH=			${LOCALBASE}/${QT_BINDIR_REL}/qvfb

rcc_PORT=			devel/${_QT_RELNAME}-rcc
rcc_PATH=			${LOCALBASE}/${QT_BINDIR_REL}/rcc

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
serialport_LIB=	libQt${_QT_LIBVER}SerialPort.so

sql_PORT=			databases/${_QT_RELNAME}-sql
sql_LIB=			libQt${_QT_LIBVER}Sql.so

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

svg_PORT=			graphics/${_QT_RELNAME}-svg
svg_LIB=			libQt${_QT_LIBVER}Svg.so

testlib_PORT=		devel/${_QT_RELNAME}-testlib
testlib_LIB=		libQt${_QT_LIBVER}Test.so

uic_PORT=			devel/${_QT_RELNAME}-uic
uic_PATH=			${LOCALBASE}/${QT_BINDIR_REL}/uic

uic3_PORT=			devel/${_QT_RELNAME}-uic3
uic3_PATH=			${LOCALBASE}/${QT_BINDIR_REL}/uic3

uiplugin_PORT=		x11-toolkits/${_QT_RELNAME}-uiplugin
uiplugin_PATH=		${LOCALBASE}/${QT_INCDIR_REL}/QtUiPlugin/QtUiPlugin

uitools_PORT=		devel/${_QT_RELNAME}-uitools
uitools_PATH=		${LOCALBASE}/${QT_LIBDIR_REL}/libQt${_QT_LIBVER}UiTools.a

virtualkeyboard_PORT=	x11-toolkits/${_QT_RELNAME}-virtualkeyboard
virtualkeyboard_PATH=	${LOCALBASE}/${QT_PLUGINDIR_REL}/platforminputcontexts/libqtvirtualkeyboardplugin.so

webchannel_PORT=	www/${_QT_RELNAME}-webchannel
webchannel_LIB=	libQt${_QT_LIBVER}WebChannel.so

webengine_PORT=		www/${_QT_RELNAME}-webengine
webengine_LIB=	libQt${_QT_LIBVER}WebEngine.so

websockets_PORT=	www/${_QT_RELNAME}-websockets
websockets_LIB=	libQt${_QT_LIBVER}WebSockets.so

websockets-qml_PORT=	www/${_QT_RELNAME}-websockets-qml
websockets-qml_PATH=	${LOCALBASE}/${QT_QMLDIR_REL}/QtWebSockets/qmldir

webkit_PORT=		www/${_QT_RELNAME}-webkit
webkit_LIB=	libQt${_QT_LIBVER}WebKit.so

widgets_PORT=		x11-toolkits/${_QT_RELNAME}-widgets
widgets_LIB=		libQt${_QT_LIBVER}Widgets.so

x11extras_PORT=		x11/${_QT_RELNAME}-x11extras
x11extras_LIB=		libQt${_QT_LIBVER}X11Extras.so

xml_PORT=			textproc/${_QT_RELNAME}-xml
xml_LIB=			libQt${_QT_LIBVER}Xml.so

xmlpatterns_PORT=	textproc/${_QT_RELNAME}-xmlpatterns
xmlpatterns_LIB=	libQt${_QT_LIBVER}XmlPatterns.so

xmlpatterns-tool_PORT=	textproc/${_QT_RELNAME}-xmlpatterns-tool
xmlpatterns-tool_PATH=	${LOCALBASE}/${QT_BINDIR_REL}/xmlpatterns

_USE_QT=		${USE_QT${_QT_VERSION:R:R}}
_USE_QT_ALL+=		${_USE_QT${_QT_VERSION:R:R}_ONLY}
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

# The list of QtBase components that need to be linked into WRKSRC/lib for
# other QtBase ports. See below.
_QT5_BASE=			core dbus gui network sql widgets

pre-configure: qtbase-pre-configure
qtbase-pre-configure:
.  for tool in ${_QT_TOOLS}
	@${TEST} -e ${QT_BINDIR}/${tool:T} && \
		${LN} -sf ${QT_BINDIR}/${tool:T} ${CONFIGURE_WRKSRC}/bin/${tool:T} || \
		${TRUE}
.  endfor

# The following is a fix for the inplace upgrade problem we faced (see
# QTBUG-40825 and ports bugs 194088, 195105 and 198720) previously,
# which previously was adressed by making sure, that ${LOCALBASE}/lib, which
# would often gets added by pkgconf for the dependencies, was passed after
# ${WRKSRC}/lib.
# * We fix the inplace upgrade problem by moving the Qt5 libraries into
#   ${LOCALBASE}/lib/qt5. Therefore a -L${LOCALBASE}/lib does no harm anymore.
# * However, this means, that the ports belonging to the split up QtBase package
#   now no longer can find their depending QtBase libraries. We fix this by
#   linking these into ${CONFIGURE_WRKSRC}/lib if the given QtBase port depends
#   on them.
.  if ${QT_DIST:Mbase}
.    for basedep in ${_QT5_BASE}
.      if ${USE_QT5:M${basedep}}
	${LN} -sf ${QT_LIBDIR}/${${basedep}_LIB} ${CONFIGURE_WRKSRC}/lib
.      endif
.    endfor
.  endif

#
# **** THIS PART IS OBSOLETE FOR THE NEXT QT UPGRADE ****
#
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

pre-configure: qt5-pre-configure
qt5-pre-configure:
# Qt 5.3.2 introduced a check in mkspecs/features/create_cmake.prf that
# requires tests/auto/cmake to be present, otherwise the configure stage will
# fail.
# Since we cannot extract tests/auto/cmake/ and exclude tests/ at the same
# time, we have to disable the check in a cache file (the only way to get this
# value through to the configure script in qtbase).
	${MKDIR} ${CONFIGURE_WRKSRC}
	${ECHO_CMD} 'CMAKE_MODULE_TESTS = -' > ${CONFIGURE_WRKSRC}/.qmake.cache
#
# **** THIS PART IS OBSOLETE FOR THE NEXT QT UPGRADE ****
#
# We piggyback on QMAKE_LIBDIR_FLAGS to make sure -L${WRKSRC}/lib is passed to
# the linker before -L/usr/local/lib. By default, the opposite happens, which
# is a problem when a Qt port is being upgraded, since an existing library
# would end up being picked up instead of those built in ${WRKSRC}/lib. Since
# qmake appends the value of QMAKE_LIBDIR to QMAKE_LIBDIR_FLAGS, we can use the
# latter to get the linker path order right. qmake is smart enough to strip
# occurrences of ${WRKSRC}/lib from .pc and .prl files when installing them.
# See QTBUG-40825 and ports bugs 194088, 195105 and 198720.
	${ECHO_CMD} 'QMAKE_LIBDIR_FLAGS = -L${CONFIGURE_WRKSRC}/lib' >> ${CONFIGURE_WRKSRC}/.qmake.cache

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
	@${ECHO_CMD} "${PREFIX}/${QT_INCDIR_REL}/QtCore/modules/qconfig-${QT_MODNAME}.h" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@exec echo '#include <QtCore/modules/qconfig-${QT_MODNAME}.h>' >> ${PREFIX}/${QT_INCDIR_REL}/QtCore/qconfig-modules.h" \
		>> ${TMPPLIST}
. endif # ${QT_DEFINES:N-*}
. if ${QT_CONFIG:N-*}
	@${MKDIR} ${STAGEDIR}${QT_MKSPECDIR}/modules
	${ECHO_CMD} "QT_CONFIG += ${QT_CONFIG:N-*:O:u}" \
		> ${STAGEDIR}${QT_MKSPECDIR}/modules/qt_config_${QT_MODNAME}.pri
	@${ECHO_CMD} "${PREFIX}/${QT_MKSPECDIR_REL}/modules/qt_config_${QT_MODNAME}.pri" \
		>> ${TMPPLIST}
. endif # ${QT_CONFIG:N-*}
.endif # defined(QT_DIST) && ! ${_QT_VERSION:M4*}

.endif # defined(_POSTMKINCLUDED) && !defined(Qt_Post_Include)
