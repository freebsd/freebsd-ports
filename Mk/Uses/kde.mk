# $FreeBSD$
#
# Provides support for KDE and KF5-based ports.
#
# Feature:	kde
# Valid ARGS:	4 5
#
# 4:		Depend on KDE4 components and variables.
# 5:		Depend on KDE Frameworks 5 components and variables.
#
# Variables that can be set by a port:
#
# USE_KDE	List of KDE4/KF5/Plasma5 components (other ports) that this
#		port depends on.
#		* foo_build	Add a build-time dependency (BUILD_DEPENDS)
#		* foo_run	Add a run-time dependency (RUN_DEPENDS)
#		* foo (default)	Add both dependencies on component <foo>, or
#				a LIB_DEPENDS if applicable.
#
# To simplify the ports, also:
# CATEGORIES	If the port is part of one of the KDE Software distribution,
#		it can add, in addition to 'kde' one of the following:
#			kde-frameworks:		part of frameworks release
#			kde-kde4: 		part of kde4 release
#		this will then set default values for MASTER_SITES and DIST_SUBDIR
#		as well as CPE_VENDOR and LICENSE.
#
# MAINTAINER:	kde@FreeBSD.org

.if !defined(_INCLUDE_USES_KDE_MK)
_INCLUDE_USES_KDE_MK=	yes

_KDE_SUPPORTED=		4 5

.  if empty(kde_ARGS)
IGNORE=	kde needs a version (${_KDE_SUPPORTED})
.  endif

.  for ver in ${_KDE_SUPPORTED:O:u}
.    if ${kde_ARGS:M${ver}}
.      if !defined(_KDE_VERSION)
_KDE_VERSION=	${ver}
.      else
IGNORE?=	cannot be installed: different KDE versions specified via kde:[${_KDE_SUPPORTED:S/ //g}] #'
.      endif
.    endif
.  endfor

.  if empty(_KDE_VERSION)
IGNORE?=	kde:[${_KDE_SUPPORTED:S/ //g}] needs an argument  #'
.  endif

_KDE_RELNAME=		KDE${_KDE_VERSION}

# === VERSIONS OF THE DIFFERENT COMPONENTS =====================================
# Old KDE desktop.
KDE4_VERSION?=			4.14.3
KDE4_KDELIBS_VERSION=		4.14.30
KDE4_ACTIVITIES_VERSION=	4.13.3
KDE4_WORKSPACE_VERSION=		4.11.22
KDE4_KDEPIM_VERSION?=		4.14.10
# Applications version for the kde4-applications.
KDE4_APPLICATIONS_BRANCH?=	Attic
KDE4_APPLICATIONS_VERSION?=	15.04.3
KDE4_BRANCH?=			stable

# Current KDE desktop.
KDE_FRAMEWORKS_VERSION?=	5.37.0
KDE_FRAMEWORKS_BRANCH?= 	stable

# Current KDE applications.
KDE_APPLICATIONS_VERSION?=      16.12.3
KDE_APPLICATIONS_BRANCH?=       stable
# Upstream moves old software to Attic/. Specify the newest applications release there.
# Only the major version is used for the comparison.
_KDE_APPLICATIONS_ATTIC_VERSION=	16.12.3

# Extended KDE universe applications.
CALLIGRA_VERSION?=		2.9.11
CALLIGRA_BRANCH?=		stable

KDEVELOP_VERSION?=		4.7.4
KDEVELOP_BRANCH?=		stable

KTP_VERSION?=			0.9.0
KTP_BRANCH?=			stable
# ==============================================================================

# === INSTALLATION PREFIXES AND HEADER LOCATION ================================
# Define unversioned prefix variable.
KDE_PREFIX=	${LOCALBASE}
# ==============================================================================

# === CATEGORIES HANDLING -- SETTING DEFAULT VALUES ============================
# Doing MASTER_SITES magic based on the category of the port
_KDE_CATEGORIES_SUPPORTED=	kde-applications kde-frameworks kde-kde4
.  for cat in ${_KDE_CATEGORIES_SUPPORTED}
.    if ${CATEGORIES:M${cat}}
.      if !defined(_KDE_CATEGORY)
_KDE_CATEGORY=	${cat}
.      else
IGNORE?=	cannot be installed: multiple kde-<...> categories specified via CATEGORIES=${CATEGORIES} #'
.      endif
.    endif
.  endfor

.  if defined(_KDE_CATEGORY)
# KDE is normally licensed under the LGPL 2.0.
LICENSE?=		LGPL20

# Set CPE Vendor Information
#    As _KDE_CATEGORY is set we can assume it is port release by KDE and the
#    vendor is therefore kde.
CPE_VENDOR?=		kde

.    if ${_KDE_CATEGORY:Mkde-kde4}
PORTVERSION?=		${KDE4_VERSION}
MASTER_SITES?=		KDE/${KDE4_BRANCH}/${KDE4_VERSION}/src
DIST_SUBDIR?=		KDE/${KDE4_VERSION}
.    elif  ${_KDE_CATEGORY:Mkde-applications}
PORTVERSION?=           ${KDE_APPLICATIONS_VERSION}
.      if ${_KDE_VERSION:M4}
CONFLICTS_INSTALL?=     ${PORTNAME}-kf5-*
.      else
CONFLICTS_INSTALL?=     kde4-${PORTNAME}-* ${PORTNAME}-kde4-*
.      endif
# Decide where the file lies on KDE's servers: Check whether the file lies in  Attic
.      if ${KDE_APPLICATIONS_VERSION:R:R} <= ${_KDE_APPLICATIONS_ATTIC_VERSION:R:R}
MASTER_SITES?=          KDE/Attic/applications/${KDE_APPLICATIONS_VERSION}/src
.      else
MASTER_SITES?=          KDE/${KDE_APPLICATIONS_BRANCH}/applications/${KDE_APPLICATIONS_VERSION}/src
.      endif
DIST_SUBDIR?=           KDE/applications/${KDE_APPLICATIONS_VERSION}
.    elif ${_KDE_CATEGORY:Mkde-frameworks}
PORTVERSION?=		${KDE_FRAMEWORKS_VERSION}
PKGNAMEPREFIX?=		kf5-
# This is a slight duplication of _USE_FRAMEWORKS_PORTING -- it maybe would be
# better to rely on ${_USE_FRAMEWORKS_PORTING:S/^/k/g}
_PORTINGAIDS=		kjs kjsembed kdelibs4support khtml kmediaplayer kross
.      if ${_PORTINGAIDS:M*${PORTNAME}*}
MASTER_SITES?=		KDE/${KDE_FRAMEWORKS_BRANCH}/frameworks/${KDE_FRAMEWORKS_VERSION:R}/portingAids
.      else
MASTER_SITES?=		KDE/${KDE_FRAMEWORKS_BRANCH}/frameworks/${KDE_FRAMEWORKS_VERSION:R}
.      endif
DIST_SUBDIR?=		KDE/frameworks/${KDE_FRAMEWORKS_VERSION}
.    else
IGNORE?=		unknown CATEGORY value '${_KDE_CATEGORY}' #'
.    endif
.  endif #defined(_KDE_CATEGORY)

# ==============================================================================

# ==== SETUP CMAKE ENVIRONMENT =================================================
# Help cmake to find files when testing ports with non-default PREFIX.
CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH="${LOCALBASE}"

.  if ${_KDE_VERSION:M*4*}
CMAKE_ARGS+=	-DKDE4_BUILD_TESTS:BOOL=OFF
.  elif ${_KDE_VERSION:M*5*}
# We set KDE_INSTALL_USE_QT_SYS_PATHS to install mkspecs files, plugins and
# imports to the Qt 5 install directory.
CMAKE_ARGS+=   -DBUILD_TESTING:BOOL=OFF \
               -DCMAKE_MODULE_PATH="${LOCALBASE};${KDE_PREFIX}" \
               -DCMAKE_INSTALL_PREFIX="${KDE_PREFIX}" \
               -DKDE_INSTALL_USE_QT_SYS_PATHS:BOOL=TRUE
.  endif

# Set man-page installation prefix.
CMAKE_ARGS+=	-DKDE_INSTALL_MANDIR:PATH="${KDE_PREFIX}/man" \
		-DMAN_INSTALL_DIR:PATH="${KDE_PREFIX}/man"
# ==============================================================================

# === SET-UP PLIST_SUB =========================================================
# Prefix and include directory.
PLIST_SUB+=		KDE_PREFIX="${KDE_PREFIX}"
# KDE Applications version.
PLIST_SUB+=		KDE_APPLICATIONS_VERSION="${KDE_APPLICATIONS_VERSION}"
# For KDE4 applications provide KDE4 version numbers.
.  if ${_KDE_VERSION:M*4*}
PLIST_SUB+=		KDE4_VERSION="${KDE4_VERSION}" \
			KDE4_GENERIC_LIB_VERSION=${KDE4_KDELIBS_VERSION} \
			KDE4_NON_GENERIC_LIB_VERSION=${KDE4_KDELIBS_VERSION:S,^4,5,} \
			KDE4_KDELIBS_VERSION=${KDE4_KDELIBS_VERSION} \
			KDE4_NG_KDELIBS_VERSION=${KDE4_KDELIBS_VERSION:S,^4,5,}
.  elif ${_KDE_VERSION:M*5*}
PLIST_SUB+=		KDE_FRAMEWORKS_VERSION="${KDE_FRAMEWORKS_VERSION}"
.  endif
# ==============================================================================

# === HANDLE PYTHON ============================================================
# TODO: Keep in sync with cmake/modules/PythonMacros.cmake
_PYTHON_SHORT_VER=	${PYTHON_VERSION:S/^python//:S/.//}
.  if ${_PYTHON_SHORT_VER} > 31
PLIST_SUB+=		PYCACHE="__pycache__/" \
			PYC_SUFFIX=cpython-${_PYTHON_SHORT_VER}.pyc \
			PYO_SUFFIX=cpython-${_PYTHON_SHORT_VER}.pyo
.  else
PLIST_SUB+=		PYCACHE="" \
			PYC_SUFFIX=pyc \
			PYO_SUFFIX=pyo
.  endif
# ==============================================================================
_USE_KDE4_ALL=		baloo baloo-widgets baseapps kactivities kate kdelibs \
			kfilemetadata korundum libkcddb libkcompactdisc \
			libkdcraw libkdeedu libkdegames libkexiv2 libkipi \
			libkonq libksane marble nepomuk-core nepomuk-widgets \
			okular oxygen-icons5 perlkde perlqt pimlibs pykde4 \
			pykdeuic4 qtruby runtime smokegen smokekde smokeqt \
			workspace
# These components are not part of the Software Compilation.
_USE_KDE4_ALL+=		akonadi attica automoc4 ontologies qimageblitz soprano \
			strigi

# List of components of the KDE Frameworks distribution.
# The *_TIER<n> variables are internal, primarily for checking
# that our list of frameworks matches the structure offered upstream.
_USE_FRAMEWORKS_TIER1=	apidox archive attica5 breeze-icons codecs config \
			coreaddons dbusaddons dnssd i18n idletime itemmodels \
			itemviews kirigami2 oxygen-icons5 plotting prison solid \
			sonnet syntaxhighlighting threadweaver wayland \
			widgetsaddons windowsystem
# NOT LISTED TIER1: modemmanagerqt networkmanagerqt (not applicable)

_USE_FRAMEWORKS_TIER2=	auth completion crash doctools filemetadata5 \
			kimageformats jobwidgets notifications package \
			pty unitconversion
# NOT LISTED TIER2: activities-stats (runtime requires x11/plasma5-kactivitymanagerd)

_USE_FRAMEWORKS_TIER3=	activities baloo5 bookmarks configwidgets \
			designerplugin emoticons globalaccel guiaddons \
			iconthemes init kcmutils kdeclarative \
			kded kdesu kdewebkit kio newstuff notifyconfig parts \
			people plasma-framework runner service texteditor \
			textwidgets wallet xmlgui xmlrpcclient

_USE_FRAMEWORKS_TIER4= 	frameworkintegration

# Porting Aids frameworks provide code and utilities to ease the transition from
# kdelibs 4 to KDE Frameworks 5. Code should aim to port away from this framework,
# new projects should avoid using these libraries.
_USE_FRAMEWORKS_PORTING=js jsembed kdelibs4support khtml mediaplayer kross

_USE_FRAMEWORKS_ALL=	ecm \
			${_USE_FRAMEWORKS_TIER1} \
			${_USE_FRAMEWORKS_TIER2} \
			${_USE_FRAMEWORKS_TIER3} \
			${_USE_FRAMEWORKS_TIER4} \
			${_USE_FRAMEWORKS_PORTING} \
			${_USE_FRAMEWORKS_EXTRA}

_USE_KDE5_ALL=		${_USE_FRAMEWORKS_ALL}

# ====================== kde4 components =======================================
baloo_PORT=		sysutils/baloo
baloo_LIB=		libbaloocore.so

baloo-widgets_PORT=	sysutils/baloo-widgets
baloo-widgets_LIB=	libbaloowidgets.so

baseapps_PORT=		x11/kde4-baseapps
baseapps_PATH=		${KDE_PREFIX}/bin/kfmclient
baseapps_TYPE=		run

kactivities_PORT=	x11/kactivities
kactivities_LIB=	libkactivities.so

kate_PORT=		editors/kate
kate_LIB=		libkateinterfaces.so

kdelibs_PORT=		x11/kdelibs4
kdelibs_LIB=		libkdecore.so

kfilemetadata_PORT=	sysutils/kfilemetadata
kfilemetadata_LIB=	libkfilemetadata.so

korundum_PORT=		devel/ruby-korundum
korundum_PATH=		${KDE_PREFIX}/lib/kde4/krubypluginfactory.so
korundum_TYPE=		run

libkcddb_PORT=		audio/libkcddb
libkcddb_LIB=		libkcddb.so

libkcompactdisc_PORT=	audio/libkcompactdisc
libkcompactdisc_LIB=	libkcompactdisc.so

libkdcraw_PORT=		graphics/libkdcraw-kde4
libkdcraw_LIB=		libkdcraw.so

libkdeedu_PORT=		misc/libkdeedu
libkdeedu_LIB=		libkeduvocdocument.so

libkdegames_PORT=	games/libkdegames
libkdegames_LIB=	libkdegames.so

libkexiv2_PORT=		graphics/libkexiv2-kde4
libkexiv2_LIB=		libkexiv2.so

libkipi_PORT=		graphics/libkipi-kde4
libkipi_LIB=		libkipi.so

libkonq_PORT=		x11/libkonq
libkonq_LIB=		libkonq.so

libksane_PORT=		graphics/libksane
libksane_LIB=		libksane.so

marble_PORT=		astro/marble
marble_LIB=		libmarblewidget.so

nepomuk-core_PORT=	sysutils/nepomuk-core
nepomuk-core_LIB=	libnepomukcore.so

nepomuk-widgets_PORT=	sysutils/nepomuk-widgets
nepomuk-widgets_LIB=	libnepomukwidgets.so

okular_PORT=		graphics/okular
okular_LIB=		libokularcore.so

perlkde_PORT=		devel/p5-perlkde
perlkde_PATH=		${KDE_PREFIX}/lib/kde4/kperlpluginfactory.so
perlkde_TYPE=		run

perlqt_PORT=		devel/p5-perlqt
perlqt_PATH=		${KDE_PREFIX}/bin/puic4

pimlibs_PORT=		deskutils/kdepimlibs4
pimlibs_LIB=		libkpimutils.so

pykde4_PORT=		devel/py-pykde4
pykde4_PATH=		${KDE_PREFIX}/lib/kde4/kpythonpluginfactory.so
pykde4_TYPE=		run

pykdeuic4_PORT=		devel/py-pykdeuic4
pykdeuic4_PATH=		${LOCALBASE}/bin/pykdeuic4
pykdeuic4_TYPE=		run

qtruby_PORT=		devel/ruby-qtruby
qtruby_LIB=		libqtruby4shared.so

runtime_PORT=		x11/kde4-runtime
runtime_PATH=		${KDE_PREFIX}/bin/knotify4
runtime_TYPE=		run

smokegen_PORT=		devel/smokegen
smokegen_LIB=		libsmokebase.so

smokekde_PORT=		devel/smokekde
smokekde_LIB=		libsmokekdecore.so

smokeqt_PORT=		devel/smokeqt
smokeqt_LIB=		libsmokeqtcore.so

workspace_PORT=		x11/kde4-workspace
workspace_LIB=		libkworkspace.so

# Non-Software Compilation components
akonadi_PORT=		databases/akonadi
akonadi_LIB=		libakonadiprotocolinternals.so

attica_PORT=		x11-toolkits/attica
attica_LIB=		libattica.so

automoc4_PORT=		devel/automoc4
automoc4_PATH=		${LOCALBASE}/bin/automoc4
automoc4_TYPE=		build

ontologies_PORT=	x11-toolkits/shared-desktop-ontologies
ontologies_PATH=	${LOCALBASE}/share/ontology/core/rdf.ontology

qimageblitz_PORT=	x11/qimageblitz
qimageblitz_LIB=	libqimageblitz.so

soprano_PORT=		textproc/soprano
soprano_LIB=		libsoprano.so

strigi_PORT=		deskutils/libstreamanalyzer
strigi_LIB=		libstreamanalyzer.so.0
# ====================== end of kde4 components ================================

# ====================== frameworks components =================================
activities_PORT=	x11/kf5-kactivities
activities_LIB=		libKF5Activities.so

apidox_PORT=		devel/kf5-kapidox
apidox_PATH=		${KDE_PREFIX}/bin/kapidox_generate
apidox_TYPE=		run

archive_PORT=		archivers/kf5-karchive
archive_LIB=		libKF5Archive.so

attica5_PORT=		x11-toolkits/kf5-attica
attica5_LIB=		libKF5Attica.so

auth_PORT=		devel/kf5-kauth
auth_LIB=		libKF5Auth.so

baloo5_PORT=		sysutils/kf5-baloo
baloo5_LIB=		libKF5Baloo.so

bookmarks_PORT=		devel/kf5-kbookmarks
bookmarks_LIB=		libKF5Bookmarks.so

breeze-icons_PORT=	x11-themes/kf5-breeze-icons
breeze-icons_PATH=	${KDE_PREFIX}/share/icons/breeze/index.theme
breeze-icons_TYPE=	run

codecs_PORT=		textproc/kf5-kcodecs
codecs_LIB=		libKF5Codecs.so

completion_PORT=	x11-toolkits/kf5-kcompletion
completion_LIB=		libKF5Completion.so

config_PORT=		devel/kf5-kconfig
config_LIB=		libKF5ConfigCore.so

configwidgets_PORT=	x11-toolkits/kf5-kconfigwidgets
configwidgets_LIB=	libKF5ConfigWidgets.so

coreaddons_PORT=	devel/kf5-kcoreaddons
coreaddons_LIB=		libKF5CoreAddons.so

crash_PORT=		devel/kf5-kcrash
crash_LIB=		libKF5Crash.so

dbusaddons_PORT=	devel/kf5-kdbusaddons
dbusaddons_LIB=		libKF5DBusAddons.so

designerplugin_PORT=	x11-toolkits/kf5-kdesignerplugin
designerplugin_PATH=	${QT_PLUGINDIR}/designer/kf5widgets.so
designerplugin_TYPE=	run

dnssd_PORT=		dns/kf5-kdnssd
dnssd_LIB=		libKF5DNSSD.so

doctools_PORT=		devel/kf5-kdoctools
doctools_PATH=		${KDE_PREFIX}/bin/meinproc5

ecm_PORT=		devel/kf5-extra-cmake-modules
ecm_PATH=		${LOCALBASE}/share/ECM/cmake/ECMConfig.cmake

emoticons_PORT=		x11-themes/kf5-kemoticons
emoticons_LIB=		libKF5Emoticons.so

filemetadata5_PORT=	devel/kf5-kfilemetadata
filemetadata5_LIB=	libKF5FileMetaData.so

frameworkintegration_PORT=	x11/kf5-frameworkintegration
frameworkintegration_LIB=	libKF5Style.so

globalaccel_PORT=	x11/kf5-kglobalaccel
globalaccel_LIB=	libKF5GlobalAccel.so

guiaddons_PORT=		x11-toolkits/kf5-kguiaddons
guiaddons_LIB=		libKF5GuiAddons.so

i18n_PORT=		devel/kf5-ki18n
i18n_LIB=		libKF5I18n.so

iconthemes_PORT=	x11-themes/kf5-kiconthemes
iconthemes_LIB=		libKF5IconThemes.so

idletime_PORT=		devel/kf5-kidletime
idletime_LIB=		libKF5IdleTime.so

init_PORT=		x11/kf5-kinit
init_PATH=		${KDE_PREFIX}/bin/kdeinit5

itemmodels_PORT=	devel/kf5-kitemmodels
itemmodels_LIB=		libKF5ItemModels.so

itemviews_PORT=		x11-toolkits/kf5-kitemviews
itemviews_LIB=		libKF5ItemViews.so

jobwidgets_PORT=	x11-toolkits/kf5-kjobwidgets
jobwidgets_LIB=		libKF5JobWidgets.so

js_PORT=		www/kf5-kjs
js_LIB=			libKF5JS.so

jsembed_PORT=		www/kf5-kjsembed
jsembed_LIB=		libKF5JsEmbed.so

kcmutils_PORT=		devel/kf5-kcmutils
kcmutils_LIB=		libKF5KCMUtils.so

kdeclarative_PORT=	devel/kf5-kdeclarative
kdeclarative_LIB=	libKF5Declarative.so

kded_PORT=		x11/kf5-kded
kded_LIB=		libkdeinit5_kded5.so

kdelibs4support_PORT=	x11/kf5-kdelibs4support
kdelibs4support_LIB=	libKF5KDELibs4Support.so

kdesu_PORT=		security/kf5-kdesu
kdesu_LIB=		libKF5Su.so

kdewebkit_PORT=		www/kf5-kdewebkit
kdewebkit_LIB=		libKF5WebKit.so

khtml_PORT=		www/kf5-khtml
khtml_LIB=		libKF5KHtml.so

kimageformats_PORT=	graphics/kf5-kimageformats
kimageformats_PATH=	${QT_PLUGINDIR}/imageformats/kimg_xcf.so
kimageformats_TYPE=	run

kio_PORT=		devel/kf5-kio
kio_LIB=		libKF5KIOCore.so

kirigami2_PORT=		x11-toolkits/kf5-kirigami2
kirigami2_PATH=		${QT_QMLDIR}/org/kde/kirigami.2/libkirigamiplugin.so

kross_PORT=		lang/kf5-kross
kross_LIB=		libKF5KrossCore.so

mediaplayer_PORT=	multimedia/kf5-kmediaplayer
mediaplayer_LIB=	libKF5MediaPlayer.so.5

newstuff_PORT=		devel/kf5-knewstuff
newstuff_LIB=		libKF5NewStuff.so

notifications_PORT=	devel/kf5-knotifications
notifications_LIB=	libKF5Notifications.so

notifyconfig_PORT=	devel/kf5-knotifyconfig
notifyconfig_LIB=	libKF5NotifyConfig.so

# This is a KF5 port used by KDE4 as well, but it's architecture-independent
# and only contains icons.
oxygen-icons5_PORT=	x11-themes/kf5-oxygen-icons5
oxygen-icons5_PATH=	${KDE_PREFIX}/share/icons/oxygen/index.theme
oxygen-icons5_TYPE=	run

package_PORT=		devel/kf5-kpackage
package_LIB=		libKF5Package.so

parts_PORT=		devel/kf5-kparts
parts_LIB=		libKF5Parts.so

people_PORT=		devel/kf5-kpeople
people_LIB=		libKF5People.so

plasma-framework_PORT=	x11/kf5-plasma-framework
plasma-framework_LIB=	libKF5Plasma.so

plotting_PORT=		graphics/kf5-kplotting
plotting_LIB=		libKF5Plotting.so

prison_PORT=		graphics/kf5-prison
prison_LIB=		libKF5Prison.so

pty_PORT=		devel/kf5-kpty
pty_LIB=		libKF5Pty.so

runner_PORT=		x11/kf5-krunner
runner_LIB=		libKF5Runner.so

service_PORT=		devel/kf5-kservice
service_PATH=		${KDE_PREFIX}/bin/kbuildsycoca5

solid_PORT=		devel/kf5-solid
solid_LIB=		libKF5Solid.so

sonnet_PORT=		textproc/kf5-sonnet
sonnet_LIB=		libKF5SonnetCore.so

syntaxhighlighting_PORT=	textproc/kf5-syntax-highlighting
syntaxhighlighting_LIB=		libKF5SyntaxHighlighting.so

texteditor_PORT=	devel/kf5-ktexteditor
texteditor_LIB=		libKF5TextEditor.so

textwidgets_PORT=	x11-toolkits/kf5-ktextwidgets
textwidgets_LIB=	libKF5TextWidgets.so

threadweaver_PORT=	devel/kf5-threadweaver
threadweaver_LIB=	libKF5ThreadWeaver.so

unitconversion_PORT=	devel/kf5-kunitconversion
unitconversion_LIB=	libKF5UnitConversion.so

wallet_PORT=		sysutils/kf5-kwallet
wallet_LIB=		libKF5Wallet.so

wayland_PORT=		x11/kf5-kwayland
wayland_LIB=		libKF5WaylandClient.so

widgetsaddons_PORT=	x11-toolkits/kf5-kwidgetsaddons
widgetsaddons_LIB=	libKF5WidgetsAddons.so

windowsystem_PORT=	x11/kf5-kwindowsystem
windowsystem_LIB=	libKF5WindowSystem.so

xmlgui_PORT=		x11-toolkits/kf5-kxmlgui
xmlgui_LIB=		libKF5XmlGui.so

xmlrpcclient_PORT=	net/kf5-kxmlrpcclient
xmlrpcclient_LIB=	libKF5XmlRpcClient.so
# ====================== end of frameworks components ==========================

# end of component list ########################################################

_USE_KDE_ALL=	${_USE_${_KDE_RELNAME}_ALL}

# Iterate through components deprived of suffix.
.  for component in ${USE_KDE:O:u:C/_.+//}
  # Check that the component is valid.
.    if ${_USE_KDE_ALL:M${component}} != ""
   # Skip meta-components (currently none).
.      if defined(${component}_PORT) && (defined(${component}_PATH) || defined(${component}_LIB))
    # Check if a dependency type is explicitly requested.
.        if ${USE_KDE:M${component}_*} != "" && ${USE_KDE:M${component}} == ""
${component}_TYPE=	# empty
.          if ${USE_KDE:M${component}_build} != ""
${component}_TYPE+=	build
.          endif
.          if ${USE_KDE:M${component}_run} != ""
${component}_TYPE+=	run
.          endif
.        endif # ${USE_KDE:M${component}_*} != "" && ${USE_KDE:M${component}} == ""
    # If no dependency type is set, default to full dependency.
.        if !defined(${component}_TYPE)
${component}_TYPE=	build run
.        endif
    # Set real dependencies.
.        if defined(${component}_LIB) && ${${component}_TYPE:Mbuild} && ${${component}_TYPE:Mrun}
LIB_DEPENDS+=		${${component}_LIB}:${${component}_PORT}
.        else
${component}_PATH?=	${KDE_PREFIX}/lib/${${component}_LIB}
${component}_DEPENDS=	${${component}_PATH}:${${component}_PORT}
.          if ${${component}_TYPE:Mbuild} != ""
BUILD_DEPENDS+=		${${component}_DEPENDS}
.          endif
.          if ${${component}_TYPE:Mrun} != ""
RUN_DEPENDS+=		${${component}_DEPENDS}
.          endif
.        endif # ${${component}_LIB} && ${${component}_TYPE:Mbuild} && ${${component}_TYPE:Mrun}
.      endif # defined(${component}_PORT) && defined(${component}_PATH)
.    else # ! ${_USE_KDE_ALL:M${component}} != ""
IGNORE=				cannot be installed: unknown USE_KDE component '${component}'
.    endif # ${_USE_KDE_ALL:M${component}} != ""
.  endfor

.endif
