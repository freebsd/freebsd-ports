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
KDE_PLASMA_VERSION?=		5.17.5
KDE_PLASMA_BRANCH?=		stable

# Current KDE frameworks.
KDE_FRAMEWORKS_VERSION?=	5.65.0
KDE_FRAMEWORKS_BRANCH?= 	stable

# Current KDE applications.
KDE_APPLICATIONS_VERSION?=	19.12.1
KDE_APPLICATIONS_SHLIB_VER?=	5.13.1
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
.        elseif ${KDE_APPLICATIONS_VERSION:R} < 19.12
MASTER_SITES?=		KDE/${KDE_APPLICATIONS_BRANCH}/applications/${KDE_APPLICATIONS_VERSION}/src
.        else
MASTER_SITES?=		KDE/${KDE_APPLICATIONS_BRANCH}/release-service/${KDE_APPLICATIONS_VERSION}/src
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
_PORTINGAIDS=		kjs kjsembed kdelibs4support kdesignerplugin kdewebkit khtml kmediaplayer kross
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

_USE_KDE_BOTH=		akonadi attica libkcddb libkcompactdisc libkdcraw libkdegames \
			libkeduvocdocument libkexiv2 libkipi libksane okular \
			baloo baloo-widgets kate marble

# List of components of the KDE Frameworks distribution.
# The *_TIER<n> variables are internal, primarily for checking
# that our list of frameworks matches the structure offered upstream.
_USE_FRAMEWORKS_TIER1=	apidox archive attica5 breeze-icons codecs config \
			coreaddons dbusaddons dnssd holidays i18n idletime itemmodels \
			itemviews kirigami2 kquickcharts oxygen-icons5 plotting prison \
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

_USE_FRAMEWORKS_TIER4= 	frameworkintegration calendarcore contacts

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
			kalarm kontact kmail mbox-importer \
			akonadiconsole akregator grantlee-editor kaddressbook \
			kalarm kmail-account-wizard kmail knotes kontact \
			korganizer pim-data-exporter

_USE_KDE5_ALL=		${_USE_FRAMEWORKS_ALL} \
			${_USE_PLASMA_ALL} \
			${_USE_KDEPIM5_ALL} \
			${_USE_KDE_BOTH}

# ====================== frameworks components =================================
kde-activities_PORT=	x11/kf5-kactivities
kde-activities_LIB=		libKF5Activities.so

kde-activities-stats_PORT=	x11/kf5-kactivities-stats
kde-activities-stats_LIB=	libKF5ActivitiesStats.so

kde-apidox_PORT=		devel/kf5-kapidox
kde-apidox_PATH=		${KDE_PREFIX}/bin/kapidox_generate
kde-apidox_TYPE=		run

kde-archive_PORT=		archivers/kf5-karchive
kde-archive_LIB=		libKF5Archive.so

kde-attica5_PORT=		x11-toolkits/kf5-attica
kde-attica5_LIB=		libKF5Attica.so

kde-auth_PORT=			devel/kf5-kauth
kde-auth_LIB=			libKF5Auth.so

kde-baloo5_PORT=		sysutils/kf5-baloo
kde-baloo5_LIB=			libKF5Baloo.so

kde-bookmarks_PORT=		devel/kf5-kbookmarks
kde-bookmarks_LIB=		libKF5Bookmarks.so

kde-breeze-icons_PORT=		x11-themes/kf5-breeze-icons
kde-breeze-icons_PATH=		${KDE_PREFIX}/share/icons/breeze/index.theme
kde-breeze-icons_TYPE=		run

kde-codecs_PORT=		textproc/kf5-kcodecs
kde-codecs_LIB=			libKF5Codecs.so

kde-completion_PORT=		x11-toolkits/kf5-kcompletion
kde-completion_LIB=		libKF5Completion.so

kde-config_PORT=		devel/kf5-kconfig
kde-config_LIB=			libKF5ConfigCore.so

kde-configwidgets_PORT=		x11-toolkits/kf5-kconfigwidgets
kde-configwidgets_LIB=		libKF5ConfigWidgets.so

kde-coreaddons_PORT=		devel/kf5-kcoreaddons
kde-coreaddons_LIB=		libKF5CoreAddons.so

kde-crash_PORT=			devel/kf5-kcrash
kde-crash_LIB=			libKF5Crash.so

kde-dbusaddons_PORT=		devel/kf5-kdbusaddons
kde-dbusaddons_LIB=		libKF5DBusAddons.so

kde-designerplugin_PORT=	x11-toolkits/kf5-kdesignerplugin
kde-designerplugin_PATH=	${KDE_PREFIX}/bin/kgendesignerplugin
kde-designerplugin_TYPE=	run

kde-dnssd_PORT=			dns/kf5-kdnssd
kde-dnssd_LIB=			libKF5DNSSD.so

kde-doctools_PORT=		devel/kf5-kdoctools
kde-doctools_PATH=		${KDE_PREFIX}/bin/meinproc5

kde-ecm_PORT=			devel/kf5-extra-cmake-modules
kde-ecm_PATH=			${LOCALBASE}/share/ECM/cmake/ECMConfig.cmake

kde-emoticons_PORT=		x11-themes/kf5-kemoticons
kde-emoticons_LIB=		libKF5Emoticons.so

kde-filemetadata_PORT=		devel/kf5-kfilemetadata
kde-filemetadata_LIB=		libKF5FileMetaData.so

kde-frameworkintegration_PORT=	x11/kf5-frameworkintegration
kde-frameworkintegration_LIB=	libKF5Style.so

kde-globalaccel_PORT=		x11/kf5-kglobalaccel
kde-globalaccel_LIB=		libKF5GlobalAccel.so

kde-guiaddons_PORT=		x11-toolkits/kf5-kguiaddons
kde-guiaddons_LIB=		libKF5GuiAddons.so

kde-holidays_PORT=		net/kf5-kholidays
kde-holidays_LIB=		libKF5Holidays.so

kde-i18n_PORT=			devel/kf5-ki18n
kde-i18n_LIB=			libKF5I18n.so

kde-iconthemes_PORT=		x11-themes/kf5-kiconthemes
kde-iconthemes_LIB=		libKF5IconThemes.so

kde-idletime_PORT=		devel/kf5-kidletime
kde-idletime_LIB=		libKF5IdleTime.so

kde-init_PORT=			x11/kf5-kinit
kde-init_PATH=			${KDE_PREFIX}/bin/kdeinit5

kde-itemmodels_PORT=		devel/kf5-kitemmodels
kde-itemmodels_LIB=		libKF5ItemModels.so

kde-itemviews_PORT=		x11-toolkits/kf5-kitemviews
kde-itemviews_LIB=		libKF5ItemViews.so

kde-jobwidgets_PORT=		x11-toolkits/kf5-kjobwidgets
kde-jobwidgets_LIB=		libKF5JobWidgets.so

kde-js_PORT=			www/kf5-kjs
kde-js_LIB=			libKF5JS.so

kde-jsembed_PORT=		www/kf5-kjsembed
kde-jsembed_LIB=		libKF5JsEmbed.so

kde-kcmutils_PORT=		devel/kf5-kcmutils
kde-kcmutils_LIB=		libKF5KCMUtils.so

kde-kdeclarative_PORT=		devel/kf5-kdeclarative
kde-kdeclarative_LIB=		libKF5Declarative.so

kde-kded_PORT=			x11/kf5-kded
kde-kded_PATH=			${KDE_PREFIX}/bin/kded5

kde-kdelibs4support_PORT=	x11/kf5-kdelibs4support
kde-kdelibs4support_LIB=	libKF5KDELibs4Support.so

kde-kdesu_PORT=			security/kf5-kdesu
kde-kdesu_LIB=			libKF5Su.so

kde-kdewebkit_PORT=		www/kf5-kdewebkit
kde-kdewebkit_LIB=		libKF5WebKit.so

kde-khtml_PORT=			www/kf5-khtml
kde-khtml_LIB=			libKF5KHtml.so

kde-kimageformats_PORT=		graphics/kf5-kimageformats
kde-kimageformats_PATH=		${QT_PLUGINDIR}/imageformats/kimg_xcf.so
kde-kimageformats_TYPE=		run

kde-kio_PORT=			devel/kf5-kio
kde-kio_LIB=			libKF5KIOCore.so

kde-kirigami2_PORT=		x11-toolkits/kf5-kirigami2
kde-kirigami2_PATH=		${QT_QMLDIR}/org/kde/kirigami.2/libkirigamiplugin.so

kde-kquickcharts_PORT=		graphics/kf5-kquickcharts
kde-kquickcharts_PATH=		${QT_QMLDIR}/org/kde/quickcharts/controls/libchartscontrolsplugin.so

kde-kross_PORT=			lang/kf5-kross
kde-kross_LIB=			libKF5KrossCore.so

kde-mediaplayer_PORT=		multimedia/kf5-kmediaplayer
kde-mediaplayer_LIB=		libKF5MediaPlayer.so.5

kde-newstuff_PORT=		devel/kf5-knewstuff
kde-newstuff_LIB=		libKF5NewStuff.so

kde-notifications_PORT=		devel/kf5-knotifications
kde-notifications_LIB=		libKF5Notifications.so

kde-notifyconfig_PORT=		devel/kf5-knotifyconfig
kde-notifyconfig_LIB=		libKF5NotifyConfig.so

kde-oxygen-icons5_PORT=		x11-themes/kf5-oxygen-icons5
kde-oxygen-icons5_PATH=		${KDE_PREFIX}/share/icons/oxygen/index.theme
kde-oxygen-icons5_TYPE=		run

kde-package_PORT=		devel/kf5-kpackage
kde-package_LIB=		libKF5Package.so

kde-parts_PORT=			devel/kf5-kparts
kde-parts_LIB=			libKF5Parts.so

kde-people_PORT=		devel/kf5-kpeople
kde-people_LIB=			libKF5People.so

kde-plasma-framework_PORT=	x11/kf5-plasma-framework
kde-plasma-framework_LIB=	libKF5Plasma.so

kde-plotting_PORT=		graphics/kf5-kplotting
kde-plotting_LIB=		libKF5Plotting.so

kde-prison_PORT=		graphics/kf5-prison
kde-prison_LIB=			libKF5Prison.so

kde-pty_PORT=			devel/kf5-kpty
kde-pty_LIB=			libKF5Pty.so

kde-purpose_PORT=		misc/kf5-purpose
kde-purpose_LIB=		libKF5Purpose.so

kde-qqc2-desktop-style_PORT=	x11-themes/kf5-qqc2-desktop-style
kde-qqc2-desktop-style_PATH=	${QT_PLUGINDIR}/kf5/kirigami/org.kde.desktop.so

kde-runner_PORT=		x11/kf5-krunner
kde-runner_LIB=			libKF5Runner.so

kde-service_PORT=		devel/kf5-kservice
kde-service_PATH=		${KDE_PREFIX}/bin/kbuildsycoca5

kde-solid_PORT=			devel/kf5-solid
kde-solid_LIB=			libKF5Solid.so

kde-sonnet_PORT=		textproc/kf5-sonnet
kde-sonnet_LIB=			libKF5SonnetCore.so

kde-syndication_PORT=		net/kf5-syndication
kde-syndication_LIB=		libKF5Syndication.so

kde-syntaxhighlighting_PORT=	textproc/kf5-syntax-highlighting
kde-syntaxhighlighting_LIB=	libKF5SyntaxHighlighting.so

kde-texteditor_PORT=		devel/kf5-ktexteditor
kde-texteditor_LIB=		libKF5TextEditor.so

kde-textwidgets_PORT=		x11-toolkits/kf5-ktextwidgets
kde-textwidgets_LIB=		libKF5TextWidgets.so

kde-threadweaver_PORT=		devel/kf5-threadweaver
kde-threadweaver_LIB=		libKF5ThreadWeaver.so

kde-unitconversion_PORT=	devel/kf5-kunitconversion
kde-unitconversion_LIB=		libKF5UnitConversion.so

kde-wallet_PORT=		sysutils/kf5-kwallet
kde-wallet_LIB=			libKF5Wallet.so

kde-wayland_PORT=		x11/kf5-kwayland
kde-wayland_LIB=		libKF5WaylandClient.so

kde-widgetsaddons_PORT=		x11-toolkits/kf5-kwidgetsaddons
kde-widgetsaddons_LIB=		libKF5WidgetsAddons.so

kde-windowsystem_PORT=		x11/kf5-kwindowsystem
kde-windowsystem_LIB=		libKF5WindowSystem.so

kde-xmlgui_PORT=		x11-toolkits/kf5-kxmlgui
kde-xmlgui_LIB=			libKF5XmlGui.so

kde-xmlrpcclient_PORT=		net/kf5-kxmlrpcclient
kde-xmlrpcclient_LIB=		libKF5XmlRpcClient.so
# ====================== end of frameworks components ==========================

# ====================== plasma components =====================================
kde-activitymanagerd_PORT=	x11/plasma5-kactivitymanagerd
kde-activitymanagerd_LIB=	libkactivitymanagerd_plugin.so

kde-breeze_PORT=		x11-themes/plasma5-breeze
kde-breeze_PATH=		${KDE_PREFIX}/share/QtCurve/Breeze.qtcurve

kde-breeze-gtk_PORT=		x11-themes/plasma5-breeze-gtk
kde-breeze-gtk_PATH=		${KDE_PREFIX}/lib/kconf_update_bin/gtkbreeze5.5

kde-decoration_PORT=		x11-wm/plasma5-kdecoration
kde-decoration_LIB=		libkdecorations2.so

kde-discover_PORT=		sysutils/plasma5-discover
kde-discover_PATH=		${KDE_PREFIX}/bin/plasma-discover

kde-drkonqi_PORT=		sysutils/plasma5-drkonqi
kde-drkonqi_PATH=		${KDE_PREFIX}/lib/libexec/drkonqi

kde-hotkeys_PORT=		devel/plasma5-khotkeys
kde-hotkeys_LIB=		libkhotkeysprivate.so.5

kde-infocenter_PORT=		sysutils/plasma5-kinfocenter
kde-infocenter_PATH=		${KDE_PREFIX}/bin/kinfocenter

kde-kde-cli-tools_PORT=		sysutils/plasma5-kde-cli-tools
kde-kde-cli-tools_PATH=		${KDE_PREFIX}/bin/kcmshell5

kde-kde-gtk-config_PORT=	x11-themes/plasma5-kde-gtk-config
kde-kde-gtk-config_PATH=	${QT_PLUGINDIR}/kcm_kdegtkconfig.so

kde-kdeplasma-addons_PORT=	x11-toolkits/plasma5-kdeplasma-addons
kde-kdeplasma-addons_PATH=	${QT_PLUGINDIR}/kcm_krunner_dictionary.so

kde-kgamma5_PORT=		x11/plasma5-kgamma5
kde-kgamma5_PATH=		${QT_PLUGINDIR}/kcm_kgamma.so

kde-kmenuedit_PORT=		sysutils/plasma5-kmenuedit
kde-kmenuedit_LIB=		libkdeinit5_kmenuedit.so

kde-kscreen_PORT=		x11/plasma5-kscreen
kde-kscreen_PATH=		${KDE_PREFIX}/bin/kscreen-console

kde-kscreenlocker_PORT=		security/plasma5-kscreenlocker
kde-kscreenlocker_LIB=		libKScreenLocker.so

kde-ksshaskpass_PORT=		security/plasma5-ksshaskpass
kde-ksshaskpass_PATH=		${KDE_PREFIX}/bin/ksshaskpass

kde-ksysguard_PORT=		sysutils/plasma5-ksysguard
kde-ksysguard_PATH=		${KDE_PREFIX}/bin/ksysguard

kde-kwallet-pam_PORT=		security/plasma5-kwallet-pam
kde-kwallet-pam_PATH=		${KDE_PREFIX}/lib/pam_kwallet5.so

kde-kwayland-integration_PORT=	x11/plasma5-kwayland-integration
kde-kwayland-integration_PATH=	${QT_PLUGINDIR}/kf5/org.kde.kidletime.platforms/KF5IdleTimeKWaylandPlugin.so

kde-kwin_PORT=			x11-wm/plasma5-kwin
kde-kwin_PATH=			${KDE_PREFIX}/bin/kwin_x11

kde-kwrited_PORT=		devel/plasma5-kwrited
kde-kwrited_PATH=		${QT_PLUGINDIR}/kf5/kded/kwrited.so

kde-libkscreen_PORT=		x11/plasma5-libkscreen
kde-libkscreen_LIB=		libKF5Screen.so

kde-libksysguard_PORT=		sysutils/plasma5-libksysguard
kde-libksysguard_LIB=		libksgrd.so

kde-milou_PORT=			deskutils/plasma5-milou
kde-milou_LIB=			libmilou.so.5

kde-oxygen_PORT= 		x11-themes/plasma5-oxygen
kde-oxygen_PATH=			${QT_PLUGINDIR}/styles/oxygen.so

kde-plasma-browser-integration_PORT=	www/plasma5-plasma-browser-integration
kde-plasma-browser-integration_PATH=	${KDE_PREFIX}/bin/plasma-browser-integration-host

kde-plasma-desktop_PORT=	x11/plasma5-plasma-desktop
kde-plasma-desktop_PATH=	${KDE_PREFIX}/bin/krdb

kde-plasma-integration_PORT=	x11/plasma5-plasma-integration
kde-plasma-integration_PATH=	${QT_PLUGINDIR}/platformthemes/KDEPlasmaPlatformTheme.so

kde-plasma-pa_PORT=		audio/plasma5-plasma-pa
kde-plasma-pa_PATH=		${QT_PLUGINDIR}/kcms/kcm_pulseaudio.so

kde-plasma-sdk_PORT=		devel/plasma5-plasma-sdk
kde-plasma-sdk_PATH=		${KDE_PREFIX}/bin/plasmoidviewer

kde-plasma-workspace_PORT=	x11/plasma5-plasma-workspace
kde-plasma-workspace_LIB=	libkdeinit5_kcminit.so

kde-plasma-workspace-wallpapers_PORT=	x11-themes/plasma5-plasma-workspace-wallpapers
kde-plasma-workspace-wallpapers_PATH=	${KDE_PREFIX}/share/wallpapers/Autumn/contents/images/1280x1024.jpg

kde-polkit-kde-agent-1_PORT=	sysutils/plasma5-polkit-kde-agent-1
kde-polkit-kde-agent-1_PATH=	${KDE_PREFIX}/lib/libexec/polkit-kde-authentication-agent-1

kde-powerdevil_PORT=		sysutils/plasma5-powerdevil
kde-powerdevil_LIB=		libpowerdevilcore.so

kde-systemsettings_PORT=	sysutils/plasma5-systemsettings
kde-systemsettings_PATH=	${KDE_PREFIX}/bin/systemsettings5

kde-user-manager_PORT=	sysutils/plasma5-user-manager
kde-user-manager_PATH=	${QT_PLUGINDIR}/user_manager.so
# ====================== end of plasma components ==============================

# ====================== pim5 components =======================================
kde-akonadicontacts_PORT=	net/akonadi-contacts
kde-akonadicontacts_LIB=	libKF5AkonadiContact.so

kde-akonadiimportwizard_PORT=	deskutils/akonadi-import-wizard
kde-akonadiimportwizard_LIB=	libKPimImportWizard.so

kde-akonadimime_PORT=		net/akonadi-mime
kde-akonadimime_LIB=		libKF5AkonadiMime.so

kde-akonadinotes_PORT=		net/akonadi-notes
kde-akonadinotes_LIB=		libKF5AkonadiNotes.so

kde-akonadicalendar_PORT=	net/akonadi-calendar
kde-akonadicalendar_LIB=	libKF5AkonadiCalendar.so

kde-akonadisearch_PORT=		net/akonadi-search
kde-akonadisearch_LIB=		libKF5AkonadiSearchCore.so

kde-alarmcalendar_PORT=		net/kalarmcal
kde-alarmcalendar_LIB=		libKF5AlarmCalendar.so

kde-blog_PORT=			net/kblog
kde-blog_LIB=			libKF5Blog.so

kde-calendarsupport_PORT=	net/calendarsupport
kde-calendarsupport_LIB=	libKF5CalendarSupport.so

kde-calendarcore_PORT=		net/kf5-kcalendarcore
kde-calendarcore_LIB=		libKF5CalendarCore.so

kde-calendarutils_PORT=		net/kcalutils
kde-calendarutils_LIB=		libKF5CalendarUtils.so

kde-contacts_PORT=		net/kf5-kcontacts
kde-contacts_LIB=		libKF5Contacts.so

kde-eventviews_PORT=		net/eventviews
kde-eventviews_LIB=		libKF5EventViews.so

kde-gapi_PORT=			net/libkgapi
kde-gapi_LIB=			libKPimGAPICore.so

kde-grantleetheme_PORT=		deskutils/grantleetheme
kde-grantleetheme_LIB=		libKF5GrantleeTheme.so

kde-gravatar_PORT=		net/libgravatar
kde-gravatar_LIB=		libKF5Gravatar.so

kde-identitymanagement_PORT=	net/kidentitymanagement
kde-identitymanagement_LIB=	libKF5IdentityManagement.so

kde-imap_PORT=			net/kimap
kde-imap_LIB=			libKF5IMAP.so

kde-incidenceeditor_PORT=	net/incidenceeditor
kde-incidenceeditor_LIB=	libKF5IncidenceEditor.so

kde-kdepim-addons_PORT=	deskutils/kdepim-addons
kde-kdepim-addons_PATH=	${KDE_PREFIX}/lib/contacteditor/editorpageplugins/cryptopageplugin.so

kde-kdepim-apps-libs_PORT=	deskutils/kdepim-apps-libs
kde-kdepim-apps-libs_LIB=	libKF5SendLater.so

kde-kdepim-runtime5_PORT=	deskutils/kdepim-runtime
kde-kdepim-runtime5_PATH=	${KDE_PREFIX}/bin/gidmigrator

kde-kitinerary_PORT=		net/kitinerary
kde-kitinerary_LIB=		libKPimItinerary.so

kde-kontactinterface_PORT=	net/kontactinterface
kde-kontactinterface_LIB=	libKF5KontactInterface.so

kde-kpimdav_PORT=		net/kdav
kde-kpimdav_LIB=		libKPimKDAV.so

kde-kpkpass_PORT=		security/kpkpass
kde-kpkpass_LIB=		libKPimPkPass.so

kde-ksmtp_PORT=			net/ksmtp
kde-ksmtp_LIB=			libKPimSMTP.so

kde-ldap_PORT=			net/kldap
kde-ldap_LIB=			libKF5Ldap.so

kde-libkdepim_PORT=		deskutils/libkdepim
kde-libkdepim_LIB=		libKF5Libkdepim.so

kde-libkleo_PORT=		security/libkleo
kde-libkleo_LIB=		libKF5Libkleo.so

kde-libksieve_PORT=		net/libksieve
kde-libksieve_LIB=		libKF5KSieve.so

kde-mailcommon_PORT=		net/mailcommon
kde-mailcommon_LIB=		libKF5MailCommon.so

kde-mailimporter_PORT=		net/mailimporter
kde-mailimporter_LIB=		libKF5MailImporter.so

kde-mailtransport_PORT=		net/kmailtransport
kde-mailtransport_LIB=		libKF5MailTransport.so

kde-mbox_PORT=			net/kmbox
kde-mbox_LIB=			libKF5Mbox.so

kde-messagelib_PORT=		net/messagelib
kde-messagelib_LIB=		libKF5MessageList.so

kde-mime_PORT=			net/kmime
kde-mime_LIB=			libKF5Mime.so

kde-pimcommon_PORT=		net/pimcommon
kde-pimcommon_LIB=		libKF5PimCommon.so

kde-pimtextedit_PORT=		net/kpimtextedit
kde-pimtextedit_LIB=		libKF5PimTextEdit.so

kde-tnef_PORT=			net/ktnef
kde-tnef_LIB=			libKF5Tnef.so

# PIM Applications
kde-akonadiconsole_PORT=	deskutils/akonadiconsole
kde-akonadiconsole_PATH=	${KDE_PREFIX}/bin/akonadiconsole

kde-akregator_PORT=		deskutils/akregator
kde-akregator_PATH=		${KDE_PREFIX}/bin/akregator

kde-grantlee-editor_PORT=	deskutils/grantlee-editor
kde-grantlee-editor_PATH=	${KDE_PREFIX}/bin/contactthemeeditor

kde-kaddressbook_PORT=		deskutils/kaddressbook
kde-kaddressbook_PATH=		${KDE_PREFIX}/bin/kaddressbook

kde-kalarm_PORT=		deskutils/kalarm
kde-kalarm_PATH=		${KDE_PREFIX}/bin/kalarm

kde-kmail_PORT=			deskutils/kmail
kde-kmail_PATH=			${KDE_PREFIX}/bin/kmail

kde-kmail-account-wizard_PORT=	deskutils/kmail-account-wizard
kde-kmail-account-wizard_PATH=	${KDE_PREFIX}/bin/accountwizard

kde-knotes_PORT=		deskutils/knotes
kde-knotex_PATH=		${KDE_PREFIX}/bin/knotes

kde-kontact_PORT=		deskutils/kontact
kde-kontact_PATH=		${KDE_PREFIX}/bin/kontact

kde-korganizer_PORT=		deskutils/korganizer
kde-korganizer_PATH=		${KDE_PREFIX}/bin/korganizer

kde-mbox-importer_PORT=		deskutils/mbox-importer
kde-mbox-importer_PATH=		${KDE_PREFIX}/bin/mboximporter

kde-pim-data-exporter_PORT=	deskutils/pim-data-exporter
kde-pim-data-exporter_PATH=	${KDE_PREFIX}/bin/pimdataexporter
# ====================== end of pim5 components ================================

# ====================== multiversion component ================================
kde-akonadi5_PORT=		databases/akonadi
kde-akonadi5_LIB=		libKF5AkonadiPrivate.so

kde-baloo-widgets5_PORT=	sysutils/baloo-widgets
kde-baloo-widgets5_LIB=		libKF5BalooWidgets.so

kde-kate5_PORT=			editors/kate
kde-kate5_PATH=			${QT_PLUGINDIR}/ktexteditor/katebacktracebrowserplugin.so

kde-libkcddb5_PORT=		audio/libkcddb
kde-libkcddb5_LIB=		libKF5Cddb.so

kde-libkcompactdisc5_PORT=	audio/libkcompactdisc
kde-libkcompactdisc5_LIB=	libKF5CompactDisc.so

kde-libkdcraw5_PORT=		graphics/libkdcraw
kde-libkdcraw5_LIB=		libKF5KDcraw.so

kde-libkdegames5_PORT=		games/libkdegames
kde-libkdegames5_LIB=		libKF5KDEGames.so

kde-libkeduvocdocument5_PORT=	misc/libkeduvocdocument
kde-libkeduvocdocument5_LIB=	libKEduVocDocument.so

kde-libkexiv25_PORT=		graphics/libkexiv2
kde-libkexiv25_LIB=		libKF5KExiv2.so

kde-libkipi5_PORT=		graphics/libkipi
kde-libkipi5_LIB=		libKF5Kipi.so

kde-libksane5_PORT=		graphics/libksane
kde-libksane5_LIB=		libKF5Sane.so

kde-marble5_PORT=		astro/marble
kde-marble5_LIB=		libmarblewidget-qt5.so

kde-okular5_PORT=		graphics/okular
kde-okular5_LIB=		libOkular5Core.so
# ====================== end of multiversion components ========================

# ====================== select the proper multiversion component ==============
.    for comp in ${_USE_KDE_BOTH}
kde-${comp}_PORT=		${kde-${comp}${_KDE_VERSION}_PORT}
.      if defined(kde-${comp}${_KDE_VERSION}_LIB)
kde-${comp}_LIB=		${kde-${comp}${_KDE_VERSION}_LIB}
.      else
.        if defined(kde-${comp}${_KDE_VERSION}_PATH})
kde-${comp}_PATH=		${kde-${comp}${_KDE_VERSION}_LIB}
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
.        if defined(kde-${component}_PORT) && (defined(kde-${component}_PATH) || defined(kde-${component}_LIB))
    # Check if a dependency type is explicitly requested.
.          if ${USE_KDE:M${component}_*} != "" && ${USE_KDE:M${component}} == ""
kde-${component}_TYPE=	# empty
.            if ${USE_KDE:M${component}_build} != ""
kde-${component}_TYPE+=	build
.            endif
.            if ${USE_KDE:M${component}_run} != ""
kde-${component}_TYPE+=	run
.            endif
.          endif # ${USE_KDE:M${component}_*} != "" && ${USE_KDE:M${component}} == ""
    # If no dependency type is set, default to full dependency.
.          if !defined(kde-${component}_TYPE)
kde-${component}_TYPE=	build run
.          endif
    # Set real dependencies.
.          if defined(kde-${component}_LIB) && ${kde-${component}_TYPE:Mbuild} && ${kde-${component}_TYPE:Mrun}
LIB_DEPENDS+=			${kde-${component}_LIB}:${kde-${component}_PORT}
.          else
kde-${component}_PATH?=		${KDE_PREFIX}/lib/${kde-${component}_LIB}
kde-${component}_DEPENDS=	${kde-${component}_PATH}:${kde-${component}_PORT}
.            if ${kde-${component}_TYPE:Mbuild} != ""
BUILD_DEPENDS+=			${kde-${component}_DEPENDS}
.            endif
.            if ${kde-${component}_TYPE:Mrun} != ""
RUN_DEPENDS+=			${kde-${component}_DEPENDS}
.            endif
.          endif # ${kde-${component}_LIB} && ${kde-${component}_TYPE:Mbuild} && ${kde-${component}_TYPE:Mrun}
.        endif # defined(kde-${component}_PORT) && defined(kde-${component}_PATH)
.      else # ! ${_USE_KDE_ALL:M${component}} != ""
IGNORE=				cannot be installed: unknown USE_KDE component '${component}'
.      endif # ${_USE_KDE_ALL:M${component}} != ""
.    endfor

.  endif
.endif
