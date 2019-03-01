# $FreeBSD$
#
# Provides support for KDE and KF5-based ports.
#
# Feature:	kde
# Valid ARGS:	5
#
# 5:		Depend on KDE Frameworks 5 components and variables.
#
# Variables that can be set by a port:
#
# USE_KDE	List of KF5/Plasma5 components (other ports) that this
#		port depends on.
#		* foo_build	Add a build-time dependency (BUILD_DEPENDS)
#		* foo_run	Add a run-time dependency (RUN_DEPENDS)
#		* foo (default)	Add both dependencies on component <foo>, or
#				a LIB_DEPENDS if applicable.
#
# To simplify the ports, also:
# CATEGORIES	If the port is part of one of the KDE Software distribution,
#		it can add, in addition to 'kde' one of the following:
#			kde-application:	part of applications release
#			kde-frameworks:		part of frameworks release
#			kde-plasma:		part of plasma release
#		this will then set default values for MASTER_SITES and DIST_SUBDIR
#		as well as CPE_VENDOR and LICENSE.
#
# MAINTAINER:	kde@FreeBSD.org

.if !defined(_INCLUDE_USES_KDE_MK)
_INCLUDE_USES_KDE_MK=	yes

_KDE_SUPPORTED=		5

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
.  else

_KDE_RELNAME=		KDE${_KDE_VERSION}

# === VERSIONS OF THE DIFFERENT COMPONENTS =====================================
# Current KDE desktop.
KDE_PLASMA_VERSION?=		5.15.2
KDE_PLASMA_BRANCH?=		stable

# Current KDE frameworks.
KDE_FRAMEWORKS_VERSION?=	5.55.0
KDE_FRAMEWORKS_BRANCH?= 	stable

# Current KDE applications.
KDE_APPLICATIONS_VERSION?=	18.12.2
KDE_APPLICATIONS_SHLIB_VER?=	5.10.2
KDE_APPLICATIONS_BRANCH?=	stable
# Upstream moves old software to Attic/. Specify the newest applications release there.
# Only the major version is used for the comparison.
_KDE_APPLICATIONS_ATTIC_VERSION=	17.08.3

# Extended KDE universe applications.
CALLIGRA_VERSION?=		2.9.11
CALLIGRA_BRANCH?=		stable
# ==============================================================================

# === INSTALLATION PREFIXES AND HEADER LOCATION ================================
# Define unversioned prefix variable.
KDE_PREFIX=	${LOCALBASE}
# ==============================================================================

# === CATEGORIES HANDLING -- SETTING DEFAULT VALUES ============================
# Doing MASTER_SITES magic based on the category of the port
_KDE_CATEGORIES_SUPPORTED=	kde-applications kde-frameworks kde-plasma
.    for cat in ${_KDE_CATEGORIES_SUPPORTED}
.      if ${CATEGORIES:M${cat}}
.        if !defined(_KDE_CATEGORY)
_KDE_CATEGORY=	${cat}
.        else
IGNORE?=	cannot be installed: multiple kde-<...> categories specified via CATEGORIES=${CATEGORIES} #'
.        endif
.      endif
.    endfor

.    if defined(_KDE_CATEGORY)
# KDE is normally licensed under the LGPL 2.0.
LICENSE?=		LGPL20

# Set CPE Vendor Information
#    As _KDE_CATEGORY is set we can assume it is port release by KDE and the
#    vendor is therefore kde.
CPE_VENDOR?=		kde

.      if ${_KDE_CATEGORY:Mkde-applications}
PORTVERSION?=		${KDE_APPLICATIONS_VERSION}
# Decide where the file lies on KDE's servers: Check whether the file lies in Attic
.        if ${KDE_APPLICATIONS_VERSION:R:R} <= ${_KDE_APPLICATIONS_ATTIC_VERSION:R:R}
MASTER_SITES?=		KDE/Attic/applications/${KDE_APPLICATIONS_VERSION}/src
.        else
MASTER_SITES?=		KDE/${KDE_APPLICATIONS_BRANCH}/applications/${KDE_APPLICATIONS_VERSION}/src
# Let bsd.port.mk create the plist-entries for the documentation.
# KDE Applications ports install their documentation to
# ${PREFIX}/share/doc.
DOCSDIR=		${PREFIX}/share/doc
PORTDOCS?=		HTML/*
# Further pass along a SHLIB_VER PLIST_SUB
PLIST_SUB+=		KDE_APPLICATIONS_SHLIB_VER=${KDE_APPLICATIONS_SHLIB_VER} \
			KDE_APPLICATIONS_VERSION_SHORT="${KDE_APPLICATIONS_VERSION:R:R}"
.        endif
DIST_SUBDIR?=		KDE/applications/${KDE_APPLICATIONS_VERSION}
.      elif ${_KDE_CATEGORY:Mkde-plasma}
PORTVERSION?=		${KDE_PLASMA_VERSION}
PKGNAMEPREFIX?=		plasma5-
MASTER_SITES?=		KDE/${KDE_PLASMA_BRANCH}/plasma/${KDE_PLASMA_VERSION}
DIST_SUBDIR?=		KDE/plasma/${KDE_PLASMA_VERSION}
.      elif ${_KDE_CATEGORY:Mkde-frameworks}
PORTVERSION?=		${KDE_FRAMEWORKS_VERSION}
PKGNAMEPREFIX?=		kf5-
# This is a slight duplication of _USE_FRAMEWORKS_PORTING -- it maybe would be
# better to rely on ${_USE_FRAMEWORKS_PORTING:S/^/k/g}
_PORTINGAIDS=		kjs kjsembed kdelibs4support khtml kmediaplayer kross
.        if ${_PORTINGAIDS:M*${PORTNAME}*}
MASTER_SITES?=		KDE/${KDE_FRAMEWORKS_BRANCH}/frameworks/${KDE_FRAMEWORKS_VERSION:R}/portingAids
.        else
MASTER_SITES?=		KDE/${KDE_FRAMEWORKS_BRANCH}/frameworks/${KDE_FRAMEWORKS_VERSION:R}
.        endif
DIST_SUBDIR?=		KDE/frameworks/${KDE_FRAMEWORKS_VERSION}
.      else
IGNORE?=		unknown CATEGORY value '${_KDE_CATEGORY}' #'
.      endif
.    endif #defined(_KDE_CATEGORY)

# ==============================================================================

# ==== SETUP CMAKE ENVIRONMENT =================================================
# Help cmake to find files when testing ports with non-default PREFIX.
CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH="${LOCALBASE}"

.    if ${_KDE_VERSION:M*5*}
# We set KDE_INSTALL_USE_QT_SYS_PATHS to install mkspecs files, plugins and
# imports to the Qt 5 install directory.
CMAKE_ARGS+=   -DBUILD_TESTING:BOOL=OFF \
               -DCMAKE_MODULE_PATH="${LOCALBASE};${KDE_PREFIX}" \
               -DCMAKE_INSTALL_PREFIX="${KDE_PREFIX}" \
               -DKDE_INSTALL_USE_QT_SYS_PATHS:BOOL=TRUE
.    endif

# Set man-page installation prefix.
CMAKE_ARGS+=	-DKDE_INSTALL_MANDIR:PATH="${KDE_PREFIX}/man" \
		-DMAN_INSTALL_DIR:PATH="${KDE_PREFIX}/man"
# ==============================================================================

# === SET-UP PLIST_SUB =========================================================
# Prefix and include directory.
PLIST_SUB+=		KDE_PREFIX="${KDE_PREFIX}"
# KDE Applications version.
PLIST_SUB+=		KDE_APPLICATIONS_VERSION="${KDE_APPLICATIONS_VERSION}"
.    if ${_KDE_VERSION:M*5*}
PLIST_SUB+=		KDE_PLASMA_VERSION="${KDE_PLASMA_VERSION}" \
			KDE_FRAMEWORKS_VERSION="${KDE_FRAMEWORKS_VERSION}"
.    endif
# ==============================================================================

# === HANDLE PYTHON ============================================================
# TODO: Keep in sync with cmake/modules/PythonMacros.cmake
_PYTHON_SHORT_VER=	${PYTHON_VERSION:S/^python//:S/.//}
.    if ${_PYTHON_SHORT_VER} > 31
PLIST_SUB+=		PYCACHE="__pycache__/" \
			PYC_SUFFIX=cpython-${_PYTHON_SHORT_VER}.pyc \
			PYO_SUFFIX=cpython-${_PYTHON_SHORT_VER}.pyo
.    else
PLIST_SUB+=		PYCACHE="" \
			PYC_SUFFIX=pyc \
			PYO_SUFFIX=pyo
.    endif
# ==============================================================================

_USE_KDE_BOTH=		akonadi attica libkcddb libkcompactdisc libkdcraw libkdegames \
			libkeduvocdocument libkexiv2 libkipi libksane okular \
			baloo baloo-widgets kate marble

# List of components of the KDE Frameworks distribution.
# The *_TIER<n> variables are internal, primarily for checking
# that our list of frameworks matches the structure offered upstream.
_USE_FRAMEWORKS_TIER1=	apidox archive attica5 breeze-icons codecs config \
			coreaddons dbusaddons dnssd holidays i18n idletime itemmodels \
			itemviews kirigami2 oxygen-icons5 plotting prison \
			qqc2-desktop-style solid sonnet syntaxhighlighting \
			threadweaver wayland widgetsaddons windowsystem
# NOT LISTED TIER1: modemmanagerqt networkmanagerqt (not applicable)

_USE_FRAMEWORKS_TIER2=	auth completion crash doctools \
			filemetadata kimageformats jobwidgets notifications \
			package pty syndication unitconversion

_USE_FRAMEWORKS_TIER3=	activities activities-stats baloo5 bookmarks configwidgets \
			designerplugin emoticons globalaccel guiaddons \
			iconthemes init kcmutils kdeclarative \
			kded kdesu kdewebkit kio newstuff notifyconfig parts \
			people plasma-framework purpose runner service texteditor \
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

# List of components of the KDE Plasma distribution.
_USE_PLASMA_ALL=	activitymanagerd breeze breeze-gtk \
			decoration discover drkonqi hotkeys \
			infocenter kde-cli-tools kde-gtk-config \
			kdeplasma-addons kgamma5 kmenuedit kscreen \
			kscreenlocker ksshaskpass ksysguard kwallet-pam \
			kwayland-integration kwin kwrited libkscreen \
			libksysguard milou oxygen plasma-browser-integration \
			plasma-desktop plasma-integration plasma-pa \
			plasma-sdk plasma-workspace plasma-workspace-wallpapers \
			polkit-kde-agent-1 powerdevil systemsettings \
			user-manager

# List of components of the KDE PIM distribution (part of applications).
_USE_KDEPIM5_ALL=	akonadicontacts akonadiimportwizard akonadimime akonadinotes \
			akonadicalendar akonadisearch alarmcalendar \
			blog calendarcore calendarsupport calendarutils \
			contacts eventviews gapi grantleetheme \
			gravatar identitymanagement imap \
			incidenceeditor kdepim-addons kdepim-apps-libs \
			kdepim-runtime5 kitinerary kontactinterface kpimdav kpkpass \
			ksmtp ldap libkdepim libkleo libksieve mailcommon \
			mailimporter mailtransport mbox messagelib \
			mime pimcommon pimtextedit tnef \
			kalarm kontact kmail account-wizard mbox-importer \
			akonadiconsole akregator grantlee-editor kaddressbook \
			kalarm kmail-account-wizard kmail knotes kontact \
			korganizer mbox-importer pim-data-exporter

_USE_KDE5_ALL=		${_USE_FRAMEWORKS_ALL} \
			${_USE_PLASMA_ALL} \
			${_USE_KDEPIM5_ALL} \
			${_USE_KDE_BOTH}

# ====================== frameworks components =================================
activities_PORT=	x11/kf5-kactivities
activities_LIB=		libKF5Activities.so

activities-stats_PORT=	x11/kf5-kactivities-stats
activities-stats_LIB=	libKF5ActivitiesStats.so

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

filemetadata_PORT=	devel/kf5-kfilemetadata
filemetadata_LIB=	libKF5FileMetaData.so

frameworkintegration_PORT=	x11/kf5-frameworkintegration
frameworkintegration_LIB=	libKF5Style.so

globalaccel_PORT=	x11/kf5-kglobalaccel
globalaccel_LIB=	libKF5GlobalAccel.so

guiaddons_PORT=		x11-toolkits/kf5-kguiaddons
guiaddons_LIB=		libKF5GuiAddons.so

holidays_PORT=		net/kf5-kholidays
holidays_LIB=		libKF5Holidays.so

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

purpose_PORT=		misc/kf5-purpose
purpose_LIB=		libKF5Purpose.so

qqc2-desktop-style_PORT=	x11-themes/kf5-qqc2-desktop-style
qqc2-desktop-style_PATH=	${QT_PLUGINDIR}/kf5/kirigami/org.kde.desktop.so

runner_PORT=		x11/kf5-krunner
runner_LIB=		libKF5Runner.so

service_PORT=		devel/kf5-kservice
service_PATH=		${KDE_PREFIX}/bin/kbuildsycoca5

solid_PORT=		devel/kf5-solid
solid_LIB=		libKF5Solid.so

sonnet_PORT=		textproc/kf5-sonnet
sonnet_LIB=		libKF5SonnetCore.so

syndication_PORT=	net/kf5-syndication
syndication_LIB=	libKF5Syndication.so

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

# ====================== plasma components =====================================
activitymanagerd_PORT=	x11/plasma5-kactivitymanagerd
activitymanagerd_LIB=	libkactivitymanagerd_plugin.so

breeze_PORT=		x11-themes/plasma5-breeze
breeze_PATH=		${KDE_PREFIX}/share/QtCurve/Breeze.qtcurve

breeze-gtk_PORT=	x11-themes/plasma5-breeze-gtk
breeze-gtk_PATH=	${KDE_PREFIX}/lib/kconf_update_bin/gtkbreeze5.5

decoration_PORT=	x11-wm/plasma5-kdecoration
decoration_LIB=		libkdecorations2.so

discover_PORT=		sysutils/plasma5-discover
discover_PATH=		${KDE_PREFIX}/bin/plasma-discover

drkonqi_PORT=		sysutils/plasma5-drkonqi
drkonqi_PATH=		${KDE_PREFIX}/lib/libexec/drkonqi

hotkeys_PORT=		devel/plasma5-khotkeys
hotkeys_LIB=		libkhotkeysprivate.so.5

infocenter_PORT=	sysutils/plasma5-kinfocenter
infocenter_PATH=	${KDE_PREFIX}/bin/kinfocenter

kde-cli-tools_PORT=	sysutils/plasma5-kde-cli-tools
kde-cli-tools_PATH=	${KDE_PREFIX}/bin/kcmshell5

kde-gtk-config_PORT=	x11-themes/plasma5-kde-gtk-config
kde-gtk-config_PATH=	${QT_PLUGINDIR}/kcm_kdegtkconfig.so

kdeplasma-addons_PORT=	x11-toolkits/plasma5-kdeplasma-addons
kdeplasma-addons_PATH=	${QT_PLUGINDIR}/kcm_krunner_dictionary.so

kgamma5_PORT=		x11/plasma5-kgamma5
kgamma5_PATH=		${QT_PLUGINDIR}/kcm_kgamma.so

kmenuedit_PORT=		sysutils/plasma5-kmenuedit
kmenuedit_LIB=		libkdeinit5_kmenuedit.so

kscreen_PORT=		x11/plasma5-kscreen
kscreen_PATH=		${KDE_PREFIX}/bin/kscreen-console

kscreenlocker_PORT=	security/plasma5-kscreenlocker
kscreenlocker_LIB=	libKScreenLocker.so

ksshaskpass_PORT=	security/plasma5-ksshaskpass
ksshaskpass_PATH=	${KDE_PREFIX}/bin/ksshaskpass

ksysguard_PORT=		sysutils/plasma5-ksysguard
ksysguard_PATH=		${KDE_PREFIX}/bin/ksysguard

kwallet-pam_PORT=	security/plasma5-kwallet-pam
kwallet-pam_PATH=	${KDE_PREFIX}/lib/security/pam_kwallet5.so

kwayland-integration_PORT=	x11/plasma5-kwayland-integration
kwayland-integration_PATH=	${QT_PLUGINDIR}/kf5/org.kde.kidletime.platforms/KF5IdleTimeKWaylandPlugin.so

kwin_PORT=		x11-wm/plasma5-kwin
kwin_PATH=		${KDE_PREFIX}/bin/kwin_x11

kwrited_PORT=		devel/plasma5-kwrited
kwrited_PATH=		${QT_PLUGINDIR}/kf5/kded/kwrited.so

libkscreen_PORT=	x11/plasma5-libkscreen
libkscreen_LIB=		libKF5Screen.so

libksysguard_PORT=	sysutils/plasma5-libksysguard
libksysguard_LIB=	libksgrd.so

milou_PORT=		deskutils/plasma5-milou
milou_LIB=		libmilou.so.5

oxygen_PORT= 		x11-themes/plasma5-oxygen
oxygen_LIB=		liboxygenstyle5.so

plasma-browser-integration_PORT=	www/plasma5-plasma-browser-integration
plasma-browser-integration_PATH=	${KDE_PREFIX}/bin/plasma-browser-integration-host		

plasma-desktop_PORT=	x11/plasma5-plasma-desktop
plasma-desktop_PATH=	${KDE_PREFIX}/bin/krdb

plasma-integration_PORT=	x11/plasma5-plasma-integration
plasma-integration_PATH=	${QT_PLUGINDIR}/platformthemes/KDEPlasmaPlatformTheme.so

plasma-pa_PORT=		audio/plasma5-plasma-pa
plasma-pa_PATH=		${QT_PLUGINDIR}/kcms/kcm_pulseaudio.so

plasma-sdk_PORT=	devel/plasma5-plasma-sdk
plasma-sdk_PATH=	${KDE_PREFIX}/bin/plasmoidviewer

plasma-workspace_PORT=	x11/plasma5-plasma-workspace
plasma-workspace_LIB=	libkdeinit5_kcminit.so

plasma-workspace-wallpapers_PORT=	x11-themes/plasma5-plasma-workspace-wallpapers
plasma-workspace-wallpapers_PATH=	${KDE_PREFIX}/share/wallpapers/Autumn/contents/images/1280x1024.jpg

polkit-kde-agent-1_PORT=	sysutils/plasma5-polkit-kde-agent-1
polkit-kde-agent-1_PATH=	${KDE_PREFIX}/lib/libexec/polkit-kde-authentication-agent-1

powerdevil_PORT=	sysutils/plasma5-powerdevil
powerdevil_LIB=		libpowerdevilcore.so

systemsettings_PORT=	sysutils/plasma5-systemsettings
systemsettings_PATH=	${KDE_PREFIX}/bin/systemsettings5

user-manager_PORT=	sysutils/plasma5-user-manager
user-manager_PATH=	${QT_PLUGINDIR}/user_manager.so
# ====================== end of plasma components ==============================

# ====================== pim5 components =======================================
akonadicontacts_PORT=	net/akonadi-contacts
akonadicontacts_LIB=	libKF5AkonadiContact.so

akonadiimportwizard_PORT=	deskutils/akonadi-import-wizard
akonadiimportwizard_LIB=	libKPimImportWizard.so

akonadimime_PORT=	net/akonadi-mime
akonadimime_LIB=	libKF5AkonadiMime.so

akonadinotes_PORT=	net/akonadi-notes
akonadinotes_LIB=	libKF5AkonadiNotes.so

akonadicalendar_PORT=	net/akonadi-calendar
akonadicalendar_LIB=	libKF5AkonadiCalendar.so

akonadisearch_PORT=	net/akonadi-search
akonadisearch_LIB=	libKF5AkonadiSearchCore.so

alarmcalendar_PORT=	net/kalarmcal
alarmcalendar_LIB=	libKF5AlarmCalendar.so

blog_PORT=		net/kblog
blog_LIB=		libKF5Blog.so

calendarsupport_PORT=	net/calendarsupport
calendarsupport_LIB=	libKF5CalendarSupport.so

calendarcore_PORT=	net/kcalcore
calendarcore_LIB=	libKF5CalendarCore.so

calendarutils_PORT=	net/kcalutils
calendarutils_LIB=	libKF5CalendarUtils.so

contacts_PORT=		net/kcontacts
contacts_LIB=		libKF5Contacts.so

eventviews_PORT=	net/eventviews
eventviews_LIB=		libKF5EventViews.so

gapi_PORT=		net/libkgapi
gapi_LIB=		libKPimGAPICore.so

grantleetheme_PORT=	deskutils/grantleetheme
grantleetheme_LIB=	libKF5GrantleeTheme.so

gravatar_PORT=		net/libgravatar
gravatar_LIB=		libKF5Gravatar.so

identitymanagement_PORT=	net/kidentitymanagement
identitymanagement_LIB=		libKF5IdentityManagement.so

imap_PORT=		net/kimap
imap_LIB=		libKF5IMAP.so

incidenceeditor_PORT=	net/incidenceeditor
incidenceeditor_LIB=	libKF5IncidenceEditor.so

kdepim-addons_PORT=	deskutils/kdepim-addons
kdepim-addons_PATH=	${KDE_PREFIX}/lib/contacteditor/editorpageplugins/cryptopageplugin.so

kdepim-apps-libs_PORT=	deskutils/kdepim-apps-libs
kdepim-apps-libs_LIB=	libKF5SendLater.so

kdepim-runtime5_PORT=	deskutils/kdepim-runtime
kdepim-runtime5_PATH=	${KDE_PREFIX}/bin/gidmigrator

kitinerary_PORT=	net/kitinerary
kitinerary_LIB=		libKPimItinerary.so

kontactinterface_PORT=	net/kontactinterface
kontactinterface_LIB=	libKF5KontactInterface.so

kpimdav_PORT=		net/kdav
kpimdav_LIB=		libKPimKDAV.so

kpkpass_PORT=		security/kpkpass
kpkpass_LIB=		libKPimPkPass.so

ksmtp_PORT=		net/ksmtp
ksmtp_LIB=		libKPimSMTP.so

ldap_PORT=		net/kldap
ldap_LIB=		libKF5Ldap.so

libkdepim_PORT=		deskutils/libkdepim
libkdepim_LIB=		libKF5Libkdepim.so

libkleo_PORT=		security/libkleo
libkleo_LIB=		libKF5Libkleo.so

libksieve_PORT=		net/libksieve
libksieve_LIB=		libKF5KSieve.so

mailcommon_PORT=	net/mailcommon
mailcommon_LIB=		libKF5MailCommon.so

mailimporter_PORT=	net/mailimporter
mailimporter_LIB=	libKF5MailImporter.so

mailtransport_PORT=	net/kmailtransport
mailtransport_LIB=	libKF5MailTransport.so

mbox_PORT=		net/kmbox
mbox_LIB=		libKF5Mbox.so

messagelib_PORT=	net/messagelib
messagelib_LIB=		libKF5MessageList.so

mime_PORT=		net/kmime
mime_LIB=		libKF5Mime.so

pimcommon_PORT=		net/pimcommon
pimcommon_LIB=		libKF5PimCommon.so

pimtextedit_PORT=	net/kpimtextedit
pimtextedit_LIB=	libKF5PimTextEdit.so

tnef_PORT=		net/ktnef
tnef_LIB=		libKF5Tnef.so

# PIM Applications
akonadiconsole_PORT=	deskutils/akonadiconsole
akonadiconsole_PATH=	${KDE_PREFIX}/bin/akonadiconsole

akregator_PORT=		deskutils/akregator
akregator_PATH=		${KDE_PREFIX}/bin/akregator

grantlee-editor_PORT=	deskutils/grantlee-editor
grantlee-editor_PATH=	${KDE_PREFIX}/bin/contactthemeeditor

kaddressbook_PORT=	deskutils/kaddressbook
kaddressbook_PATH=	${KDE_PREFIX}/bin/kaddressbook

kalarm_PORT=		deskutils/kalarm
kalarm_PATH=		${KDE_PREFIX}/bin/kalarm

kmail_PORT=		deskutils/kmail
kmail_PATH=		${KDE_PREFIX}/bin/kmail

kmail-account-wizard_PORT=	deskutils/kmail-account-wizard
kmail-account-wizard_PATH=	${KDE_PREFIX}/bin/accountwizard

knotes_PORT=		deskutils/knotes
knotex_PATH=		${KDE_PREFIX}/bin/knotes

kontact_PORT=		deskutils/kontact
kontact_PATH=		${KDE_PREFIX}/bin/kontact

korganizer_PORT=	deskutils/korganizer
korganizer_PATH=	${KDE_PREFIX}/bin/korganizer

mbox-importer_PORT=	deskutils/mbox-importer
mbox-importer_PATH=	${KDE_PREFIX}/bin/mboximporter

pim-data-exporter_PORT=	deskutils/pim-data-exporter
pim-data-exporter_PATH=	${KDE_PREFIX}/bin/pimsettingexporter
# ====================== end of pim5 components ================================

# ====================== multiversion component ================================
akonadi5_PORT=		databases/akonadi
akonadi5_LIB=		libKF5AkonadiPrivate.so

baloo-widgets5_PORT=	sysutils/baloo-widgets
baloo-widgets5_LIB=	libKF5BalooWidgets.so

kate5_PORT=		editors/kate
kate5_PATH=		${QT_PLUGINDIR}/ktexteditor/katebacktracebrowserplugin.so

libkcddb5_PORT=		audio/libkcddb
libkcddb5_LIB=		libKF5Cddb.so

libkcompactdisc5_PORT=	audio/libkcompactdisc-kde5
libkcompactdisc5_LIB=	libKF5CompactDisc.so

libkdcraw5_PORT=	graphics/libkdcraw
libkdcraw5_LIB=		libKF5KDcraw.so

libkdegames5_PORT=	games/libkdegames
libkdegames5_LIB=	libKF5KDEGames.so

libkeduvocdocument5_PORT=	misc/libkeduvocdocument
libkeduvocdocument5_LIB=	libKEduVocDocument.so

libkexiv25_PORT=	graphics/libkexiv2
libkexiv25_LIB=		libKF5KExiv2.so

libkipi5_PORT=		graphics/libkipi
libkipi5_LIB=		libKF5Kipi.so

libksane5_PORT=		graphics/libksane
libksane5_LIB=		libKF5Sane.so

marble5_PORT=		astro/marble
marble5_LIB=		libmarblewidget-qt5.so

okular5_PORT=		graphics/okular
okular5_LIB=		libOkular5Core.so
# ====================== end of multiversion components ========================

# ====================== select the proper multiversion component ==============
.    for comp in ${_USE_KDE_BOTH}
${comp}_PORT=		${${comp}${_KDE_VERSION}_PORT}
.      if defined(${comp}${_KDE_VERSION}_LIB)
${comp}_LIB=		${${comp}${_KDE_VERSION}_LIB}
.      else
.        if defined(${comp}${_KDE_VERSION}_PATH})
${comp}_PATH=		${${comp}${_KDE_VERSION}_LIB}
.        endif
# If neither is defined, this gets caught below when checking components
.      endif
.    endfor
#===============================================================================

# end of component list ########################################################

_USE_KDE_ALL=	${_USE_${_KDE_RELNAME}_ALL}

# Iterate through components deprived of suffix.
.    for component in ${USE_KDE:O:u:C/_.+//}
  # Check that the component is valid.
.      if ${_USE_KDE_ALL:M${component}} != ""
   # Skip meta-components (currently none).
.        if defined(${component}_PORT) && (defined(${component}_PATH) || defined(${component}_LIB))
    # Check if a dependency type is explicitly requested.
.          if ${USE_KDE:M${component}_*} != "" && ${USE_KDE:M${component}} == ""
${component}_TYPE=	# empty
.            if ${USE_KDE:M${component}_build} != ""
${component}_TYPE+=	build
.            endif
.            if ${USE_KDE:M${component}_run} != ""
${component}_TYPE+=	run
.            endif
.          endif # ${USE_KDE:M${component}_*} != "" && ${USE_KDE:M${component}} == ""
    # If no dependency type is set, default to full dependency.
.          if !defined(${component}_TYPE)
${component}_TYPE=	build run
.          endif
    # Set real dependencies.
.          if defined(${component}_LIB) && ${${component}_TYPE:Mbuild} && ${${component}_TYPE:Mrun}
LIB_DEPENDS+=		${${component}_LIB}:${${component}_PORT}
.          else
${component}_PATH?=	${KDE_PREFIX}/lib/${${component}_LIB}
${component}_DEPENDS=	${${component}_PATH}:${${component}_PORT}
.            if ${${component}_TYPE:Mbuild} != ""
BUILD_DEPENDS+=		${${component}_DEPENDS}
.            endif
.            if ${${component}_TYPE:Mrun} != ""
RUN_DEPENDS+=		${${component}_DEPENDS}
.            endif
.          endif # ${${component}_LIB} && ${${component}_TYPE:Mbuild} && ${${component}_TYPE:Mrun}
.        endif # defined(${component}_PORT) && defined(${component}_PATH)
.      else # ! ${_USE_KDE_ALL:M${component}} != ""
IGNORE=				cannot be installed: unknown USE_KDE component '${component}'
.      endif # ${_USE_KDE_ALL:M${component}} != ""
.    endfor

.  endif
.endif
