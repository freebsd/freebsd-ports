# Provides support for KDE and KF5-based ports.
#
# Feature:	kde
# Valid ARGS:	5 6
#
# 5:		Depend on KDE Frameworks 5 components and variables.
# 6:		Depend on KDE Frameworks 6 components and variables.
#
# Variables that can be set by a port:
#
# USE_KDE	List of KF[56]/Plasma[56] components (other ports) that this
#		port depends on.
#		* foo:build	Add a build-time dependency (BUILD_DEPENDS)
#		* foo:run	Add a run-time dependency (RUN_DEPENDS)
#		* foo (default)	Add both dependencies on component <foo>, or
#				a LIB_DEPENDS if applicable.
#
# To simplify the ports, also:
# CATEGORIES	If the port is part of one of the KDE Software distribution,
#		it can add, in addition to 'kde' one of the following:
#			kde-applications:	part of applications release
#			kde-frameworks:		part of frameworks release
#			kde-plasma:		part of plasma release
#		this will then set default values for MASTER_SITES and DIST_SUBDIR
#		as well as CPE_VENDOR and LICENSE.
#
# option DOCS	If the port is part of kde-applications (see CATEGORIES,
#		above) and has an option defined for DOCS then a dependency
#		for doctools:build is added. The option itself doesn't
#		have to do anything -- the dependency is always there.
#
# KDE_INVENT	If the port does not have a regular release, and should
#		be fetched from KDE Invent (a GitLab instance) it can set
#		KDE_INVENT to 3 space-separated values:
#		* a full 40-character commit hash
#		* a category name inside KDE Invent
#		* a repository name inside KDE Invent
#		Default values for category and name are:
#		* the first item in CATEGORIES that is not "kde"; this
#		  is useful when the FreeBSD ports category and the KDE
#		  category are the same (which happens sometimes)
#		* PORTNAME, often the FreeBSD port name is the same
#		  as the upstream name and it will not need to be specified.
#		Sometimes `KDE_INVENT=<hash>` will do and often
#		`KDE_INVENT=<hash> <category>` is enough.
#
#		Setting KDE_INVENT is the equivalent of a handful of USE_GITLAB
#		and related settings.
#
# MAINTAINER:	kde@FreeBSD.org

.if !defined(_INCLUDE_USES_KDE_MK)
_INCLUDE_USES_KDE_MK=	yes

_KDE_SUPPORTED=		5 6

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
KDE_PLASMA_VERSION?=		${KDE_PLASMA${_KDE_VERSION}_VERSION}
KDE_PLASMA_BRANCH?=		${KDE_PLASMA${_KDE_VERSION}_BRANCH}

KDE_FRAMEWORKS_VERSION?=	${KDE_FRAMEWORKS${_KDE_VERSION}_VERSION}
KDE_FRAMEWORKS_BRANCH?=		${KDE_FRAMEWORKS${_KDE_VERSION}_BRANCH}

.    if ${CATEGORIES:Mkde-devel}
KDE_APPLICATIONS_BRANCH?=	${KDE_APPLICATIONS6_BRANCH}
KDE_APPLICATIONS_VERSION?=	${KDE_APPLICATIONS6_VERSION}
KDE_APPLICATIONS_SHLIB_VER?=	${KDE_APPLICATIONS6_SHLIB_VER}
KDE_APPLICATIONS_SHLIB_G_VER?=	${KDE_APPLICATIONS6_SHLIB_G_VER}
PKGNAMESUFFIX?=			-devel
.    else
KDE_APPLICATIONS_BRANCH?=	${KDE_APPLICATIONS5_BRANCH}
KDE_APPLICATIONS_VERSION?=	${KDE_APPLICATIONS5_VERSION}
KDE_APPLICATIONS_SHLIB_VER?=	${KDE_APPLICATIONS5_SHLIB_VER}
KDE_APPLICATIONS_SHLIB_G_VER?=	${KDE_APPLICATIONS5_SHLIB_G_VER}
.    endif


# Current KDE desktop.
KDE_PLASMA5_VERSION?=		5.27.11
KDE_PLASMA5_BRANCH?=		stable

# Next KDE Plasma desktop
KDE_PLASMA6_VERSION?=		6.0.4
KDE_PLASMA6_BRANCH?=		stable

# Current KDE frameworks.
KDE_FRAMEWORKS5_VERSION?=	5.115.0
KDE_FRAMEWORKS5_BRANCH?=	stable

# Next KDE Frameworks (Qt6 based)
KDE_FRAMEWORKS6_VERSION?=	6.1.0
KDE_FRAMEWORKS6_BRANCH?=	stable

# Current KDE applications.
KDE_APPLICATIONS5_VERSION?=	23.08.5
KDE_APPLICATIONS5_SHLIB_VER?=	5.24.5
# G as in KDE Gear, and as in "don't make the variable name longer than required"
KDE_APPLICATIONS5_SHLIB_G_VER?=	23.8.5
KDE_APPLICATIONS5_BRANCH?=	stable

# Next KDE applications.
KDE_APPLICATIONS6_VERSION?=	24.01.90
KDE_APPLICATIONS6_SHLIB_VER?=	5.24.3
# G as in KDE Gear, and as in "don't make the variable name longer than required"
KDE_APPLICATIONS6_SHLIB_G_VER?=	24.01.90
KDE_APPLICATIONS6_BRANCH?=	unstable

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
_KDE_CATEGORIES_SUPPORTED=	kde-applications kde-frameworks kde-plasma kde-devel
.    for cat in ${_KDE_CATEGORIES_SUPPORTED:Nkde-devel}
.      if ${CATEGORIES:M${cat}}
.        if !defined(_KDE_CATEGORY)
_KDE_CATEGORY=	${cat}
.        else
IGNORE?=	cannot be installed: multiple kde-<...> categories specified via CATEGORIES=${CATEGORIES} #'
.        endif
.      endif
.    endfor

# Doing source-selection if the sources are on KDE invent
.    if defined(KDE_INVENT)
_invent_hash=		${KDE_INVENT:[1]}
_invent_category=	${KDE_INVENT:[2]}
_invent_name=		${KDE_INVENT:[3]}

# Fill in default values if bits are missing
.      if empty(_invent_category)
_invent_category=	${CATEGORIES:Nkde:[1]}
.      endif
.      if empty(_invent_name)
_invent_name=		${PORTNAME}
.      endif

# If valid, use it for GitLab
.      if empty(_invent_hash) || empty(_invent_category) || empty(_invent_name)
IGNORE?=		invalid KDE_INVENT value '${KDE_INVENT}'
.      else
USE_GITLAB=		yes
GL_SITE=		https://invent.kde.org
GL_ACCOUNT=		${_invent_category}
GL_PROJECT=		${_invent_name}
GL_TAGNAME=		${_invent_hash}
.      endif
.    endif

.    if defined(_KDE_CATEGORY)
# KDE is normally licensed under the LGPL 2.0.
LICENSE?=		LGPL20

# Set CPE Vendor Information
#    As _KDE_CATEGORY is set we can assume it is port release by KDE and the
#    vendor is therefore kde.
CPE_VENDOR?=		kde

.      if ${_KDE_CATEGORY:Mkde-applications}
PORTVERSION?=		${KDE_APPLICATIONS_VERSION}
MASTER_SITES?=		KDE/${KDE_APPLICATIONS_BRANCH}/release-service/${KDE_APPLICATIONS_VERSION}/src
# Let bsd.port.mk create the plist-entries for the documentation.
# KDE Applications ports install their documentation to
# ${PREFIX}/share/doc. This is only done if the port
# defines OPTION DOCS -- the _KDE_OPTIONS here is to
# avoid make errors when there are no options defined at all.
_KDE_OPTIONS=		bogus ${OPTIONS_DEFINE}
.        if ${_KDE_OPTIONS:MDOCS}
DOCSDIR=		${PREFIX}/share/doc
PORTDOCS?=		HTML/*
USE_KDE+=		doctools:build
.        endif
# Further pass along a SHLIB_VER PLIST_SUB
PLIST_SUB+=		KDE_APPLICATIONS_SHLIB_VER=${KDE_APPLICATIONS_SHLIB_VER} \
			KDE_APPLICATIONS_VERSION_SHORT="${KDE_APPLICATIONS_VERSION:R:R}"
DIST_SUBDIR?=		KDE/release-service/${KDE_APPLICATIONS_VERSION}
.      elif ${_KDE_CATEGORY:Mkde-plasma}
PORTVERSION?=		${KDE_PLASMA_VERSION}
PKGNAMEPREFIX?=		plasma${_KDE_VERSION}-
MASTER_SITES?=		KDE/${KDE_PLASMA_BRANCH}/plasma/${KDE_PLASMA_VERSION}
DIST_SUBDIR?=		KDE/plasma/${KDE_PLASMA_VERSION}
.        if ${_KDE_VERSION:M6}
DESCR=			${.CURDIR:H:H}/x11/plasma6-plasma/pkg-descr
.        endif
.      elif ${_KDE_CATEGORY:Mkde-frameworks}
PORTVERSION?=		${KDE_FRAMEWORKS_VERSION}
PKGNAMEPREFIX?=		kf${_KDE_VERSION}-
WWW?=			https://api.kde.org/frameworks/${PORTNAME}/html/index.html
# This is a slight duplication of _USE_FRAMEWORKS_PORTING -- it maybe would be
# better to rely on ${_USE_FRAMEWORKS_PORTING:S/^/k/g}
_PORTINGAIDS=		kjs kjsembed kdelibs4support kdesignerplugin khtml kmediaplayer kross kxmlrpcclient
.        if ${_KDE_VERSION:M5}
.          if ${_PORTINGAIDS:M*${PORTNAME}*}
MASTER_SITES?=		KDE/${KDE_FRAMEWORKS_BRANCH}/frameworks/${KDE_FRAMEWORKS_VERSION:R}/portingAids
.          else
MASTER_SITES?=		KDE/${KDE_FRAMEWORKS_BRANCH}/frameworks/${KDE_FRAMEWORKS_VERSION:R}
.          endif
.        else
MASTER_SITES?=		KDE/${KDE_FRAMEWORKS_BRANCH}/frameworks/${KDE_FRAMEWORKS_VERSION:R}
.        endif
DIST_SUBDIR?=		KDE/frameworks/${KDE_FRAMEWORKS_VERSION}
.        if ${_KDE_VERSION:M6}
DESCR=			${.CURDIR:H:H}/x11/kf6-frameworks/pkg-descr
.        endif
.      else
IGNORE?=		unknown CATEGORY value '${_KDE_CATEGORY}' #'
.      endif
.    endif #defined(_KDE_CATEGORY)

# ==============================================================================
# === SET UP LOCALE ENVIRONMENT =================================================
USE_LOCALE?=	en_US.UTF-8

# === SET UP CMAKE ENVIRONMENT =================================================
# Help cmake to find files when testing ports with non-default PREFIX.
CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH="${LOCALBASE}"

# We set KDE_INSTALL_USE_QT_SYS_PATHS to install mkspecs files, plugins and
# imports to the Qt 5 install directory.
CMAKE_ARGS+=	-DCMAKE_MODULE_PATH="${LOCALBASE};${KDE_PREFIX}" \
		-DCMAKE_INSTALL_PREFIX="${KDE_PREFIX}" \
		-DKDE_INSTALL_USE_QT_SYS_PATHS:BOOL=true

KDE_MAN_PREFIX?=	${KDE_PREFIX}/share/man

# Disable autotests unless TEST_TARGET is defined.
.    if !defined(TEST_TARGET)
CMAKE_ARGS+=	-DBUILD_TESTING:BOOL=false
.    endif
# ==============================================================================

# === SET UP PLIST_SUB =========================================================
# Prefix and include directory.
PLIST_SUB+=		KDE_PREFIX="${KDE_PREFIX}"
# KDE Applications version.
PLIST_SUB+=		KDE_APPLICATIONS_VERSION="${KDE_APPLICATIONS_VERSION}" \
			KDE_FRAMEWORKS_VERSION="${KDE_FRAMEWORKS_VERSION}" \
			KDE_PLASMA_VERSION="${KDE_PLASMA_VERSION}"
# ==============================================================================

_USE_KDE_BOTH=		akonadi libkcddb libkcompactdisc libkdcraw libkdegames \
			libkeduvocdocument libkipi libksane okular \
			baloo-widgets kate marble

# List of components of the KDE Frameworks distribution.
# The *_TIER<n> variables are internal, primarily for checking
# that our list of frameworks matches the structure offered upstream.
_USE_FRAMEWORKS_TIER1=	apidox archive attica breeze-icons codecs config \
			coreaddons dbusaddons dnssd holidays i18n idletime itemmodels \
			itemviews kirigami2 kquickcharts oxygen-icons5 plotting prison \
			qqc2-desktop-style solid sonnet syntaxhighlighting \
			threadweaver wayland widgetsaddons windowsystem
# NOT LISTED TIER1: modemmanagerqt networkmanagerqt (not applicable)

_USE_FRAMEWORKS_TIER2=	auth completion crash doctools \
			filemetadata kimageformats jobwidgets notifications \
			package pty syndication unitconversion

_USE_FRAMEWORKS_TIER3=	activities activities-stats baloo bookmarks configwidgets \
			designerplugin emoticons globalaccel guiaddons \
			iconthemes init kcmutils kdav kdeclarative \
			kded kdesu kio kpipewire newstuff notifyconfig parts \
			people plasma-framework purpose runner service texteditor \
			textwidgets wallet xmlgui xmlrpcclient

_USE_FRAMEWORKS_TIER4=	frameworkintegration calendarcore contacts

# Porting Aids frameworks provide code and utilities to ease the transition from
# kdelibs 4 to KDE Frameworks 5. Code should aim to port away from this framework,
# new projects should avoid using these libraries.
_USE_FRAMEWORKS_PORTING=js jsembed kdelibs4support khtml mediaplayer kross

_USE_FRAMEWORKS5_ALL=	ecm \
			${_USE_FRAMEWORKS_TIER1} \
			${_USE_FRAMEWORKS_TIER2} \
			${_USE_FRAMEWORKS_TIER3} \
			${_USE_FRAMEWORKS_TIER4} \
			${_USE_FRAMEWORKS_PORTING} \
			${_USE_FRAMEWORKS_EXTRA} \
			kpublictransport kosm \
			plasma-wayland-protocols
# TODO: fix
_USE_FRAMEWORKS6_ALL=	ecm colorscheme \
			svg \
			statusnotifieritem \
			plasma-wayland-protocols \
			userfeedback \
			${_USE_FRAMEWORKS_TIER1:Noxygen-icons5:Nwayland} \
			${_USE_FRAMEWORKS_TIER2} \
			${_USE_FRAMEWORKS_TIER3:Nemoticons:Ndesignerplugin:Nactivities:Nactivities-stats:Ninit:Nplasma-framework:Nxmlrpcclient:Nkpipewire} \
			${_USE_FRAMEWORKS_TIER4} \
			${_USE_FRAMEWORKS_EXTRA}
_USE_FRAMEWORKS_ALL=	${_USE_FRAMEWORKS${_KDE_VERSION}_ALL}

# List of components of the KDE Plasma distribution.
_USE_PLASMA_ALL=	activitymanagerd breeze breeze-gtk \
			decoration discover drkonqi hotkeys \
			infocenter kde-cli-tools kde-gtk-config \
			kdeplasma-addons kgamma5 kmenuedit kscreen \
			kscreenlocker ksshaskpass ksysguard ksystemstats kwallet-pam \
			kwayland-integration kwin kwrited layer-shell-qt libkscreen \
			libksysguard milou oxygen oxygen-sounds plasma-browser-integration \
			plasma-desktop plasma-disks plasma-integration plasma-pa \
			plasma-sdk plasma-workspace plasma-workspace-wallpapers \
			polkit-kde-agent-1 powerdevil systemsettings xdg-desktop-portal-kde \
			kirigami-addons

# List of components of the KDE PIM distribution (part of applications).
_USE_KDEPIM5_ALL=	akonadicontacts akonadiimportwizard akonadimime akonadinotes \
			akonadicalendar akonadisearch \
			calendarcore calendarsupport calendarutils \
			contacts eventviews gapi grantleetheme \
			gravatar identitymanagement imap \
			incidenceeditor kdepim-addons \
			kdepim-runtime5 kitinerary kontactinterface kpkpass \
			ksmtp ldap libkdepim libkleo libksieve mailcommon \
			mailimporter mailtransport mbox messagelib \
			mime pimcommon pimtextedit tnef \
			kalarm kontact kmail mbox-importer \
			akonadiconsole akregator grantlee-editor kaddressbook \
			kalarm kmail-account-wizard kmail knotes kontact \
			korganizer pim-data-exporter ktextaddons

_USE_PHONON_ALL=	phonon phonon-backend

_USE_KDE5_ALL=		${_USE_FRAMEWORKS_ALL} \
			${_USE_PLASMA_ALL} \
			${_USE_KDEPIM5_ALL} \
			${_USE_KDE_BOTH} \
			${_USE_PHONON_ALL} \
			libkexiv2
# TODO: fix
_USE_KDE6_ALL=		ecm colorscheme \
			svg \
			plasma-wayland-protocols \
			mediaplayer \
			${_USE_FRAMEWORKS_ALL}  \
			${_USE_PLASMA_ALL} \
			plasma5support activities activities-stats kpipewire wayland globalacceld libplasma \
			${_USE_PHONON_ALL} \
			libkexiv2

# ====================== frameworks components =================================
kde-activities_PORT5=		x11/kf${_KDE_VERSION}-kactivities
kde-activities_PORT6=		x11/plasma${_KDE_VERSION}-plasma-activities
kde-activities_PORT=		${kde-activities_PORT${_KDE_VERSION}}
kde-activities_LIB5=		libKF${_KDE_VERSION}Activities.so
kde-activities_LIB6=		libPlasmaActivities.so
kde-activities_LIB=		${kde-activities_LIB${_KDE_VERSION}}

kde-activities-stats_PORT5=	x11/kf${_KDE_VERSION}-kactivities-stats
kde-activities-stats_PORT6=	x11/plasma${_KDE_VERSION}-plasma-activities-stats
kde-activities-stats_PORT=	${kde-activities-stats_PORT${_KDE_VERSION}}
kde-activities-stats_LIB5=	libKF${_KDE_VERSION}ActivitiesStats.so
kde-activities-stats_LIB6=	libPlasmaActivitiesStats.so
kde-activities-stats_LIB=	${kde-activities-stats_LIB${_KDE_VERSION}}

kde-apidox_PORT=		devel/kf${_KDE_VERSION}-kapidox
kde-apidox_PATH=		${KDE_PREFIX}/bin/kapidox-generate
kde-apidox_TYPE=		run

kde-archive_PORT=		archivers/kf${_KDE_VERSION}-karchive
kde-archive_LIB=		libKF${_KDE_VERSION}Archive.so

kde-attica_PORT=		x11-toolkits/kf${_KDE_VERSION}-attica
kde-attica_LIB=			libKF${_KDE_VERSION}Attica.so

kde-auth_PORT=			devel/kf${_KDE_VERSION}-kauth
kde-auth_LIB=			libKF${_KDE_VERSION}AuthCore.so

kde-baloo_PORT=			sysutils/kf${_KDE_VERSION}-baloo
kde-baloo_LIB=			libKF${_KDE_VERSION}Baloo.so

kde-bookmarks_PORT=		devel/kf${_KDE_VERSION}-kbookmarks
kde-bookmarks_LIB=		libKF${_KDE_VERSION}Bookmarks.so

kde-breeze-icons_PORT=		x11-themes/kf${_KDE_VERSION}-breeze-icons
kde-breeze-icons_PATH=		${KDE_PREFIX}/share/icons/breeze/index.theme
kde-breeze-icons_TYPE=		run

kde-codecs_PORT=		textproc/kf${_KDE_VERSION}-kcodecs
kde-codecs_LIB=			libKF${_KDE_VERSION}Codecs.so

kde-completion_PORT=		x11-toolkits/kf${_KDE_VERSION}-kcompletion
kde-completion_LIB=		libKF${_KDE_VERSION}Completion.so

kde-config_PORT=		devel/kf${_KDE_VERSION}-kconfig
kde-config_LIB=			libKF${_KDE_VERSION}ConfigCore.so

kde-configwidgets_PORT=		x11-toolkits/kf${_KDE_VERSION}-kconfigwidgets
kde-configwidgets_LIB=		libKF${_KDE_VERSION}ConfigWidgets.so

kde-coreaddons_PORT=		devel/kf${_KDE_VERSION}-kcoreaddons
kde-coreaddons_LIB=		libKF${_KDE_VERSION}CoreAddons.so

kde-crash_PORT=			devel/kf${_KDE_VERSION}-kcrash
kde-crash_LIB=			libKF${_KDE_VERSION}Crash.so

kde-dbusaddons_PORT=		devel/kf${_KDE_VERSION}-kdbusaddons
kde-dbusaddons_LIB=		libKF${_KDE_VERSION}DBusAddons.so

kde-designerplugin_PORT=	x11-toolkits/kf${_KDE_VERSION}-kdesignerplugin
kde-designerplugin_PATH=	${KDE_PREFIX}/bin/kgendesignerplugin
kde-designerplugin_TYPE=	run

kde-dnssd_PORT=			dns/kf${_KDE_VERSION}-kdnssd
kde-dnssd_LIB=			libKF${_KDE_VERSION}DNSSD.so

kde-doctools_PORT=		devel/kf${_KDE_VERSION}-kdoctools
kde-doctools_PATH=		${KDE_PREFIX}/bin/meinproc${_KDE_VERSION}

kde-ecm_PORT=			devel/kf${_KDE_VERSION}-extra-cmake-modules
kde-ecm_PATH=			${LOCALBASE}/share/ECM/cmake/ECMConfig.cmake

kde-emoticons_PORT=		x11-themes/kf${_KDE_VERSION}-kemoticons
kde-emoticons_LIB=		libKF${_KDE_VERSION}Emoticons.so

kde-filemetadata_PORT=		devel/kf${_KDE_VERSION}-kfilemetadata
kde-filemetadata_LIB=		libKF${_KDE_VERSION}FileMetaData.so

kde-frameworkintegration_PORT=	x11/kf${_KDE_VERSION}-frameworkintegration
kde-frameworkintegration_LIB=	libKF${_KDE_VERSION}Style.so

kde-globalaccel_PORT=		x11/kf${_KDE_VERSION}-kglobalaccel
kde-globalaccel_LIB=		libKF${_KDE_VERSION}GlobalAccel.so

kde-guiaddons_PORT=		x11-toolkits/kf${_KDE_VERSION}-kguiaddons
kde-guiaddons_LIB=		libKF${_KDE_VERSION}GuiAddons.so

kde-holidays_PORT=		net/kf${_KDE_VERSION}-kholidays
kde-holidays_LIB=		libKF${_KDE_VERSION}Holidays.so

kde-i18n_PORT=			devel/kf${_KDE_VERSION}-ki18n
kde-i18n_LIB=			libKF${_KDE_VERSION}I18n.so

kde-iconthemes_PORT=		x11-themes/kf${_KDE_VERSION}-kiconthemes
kde-iconthemes_LIB=		libKF${_KDE_VERSION}IconThemes.so

kde-idletime_PORT=		devel/kf${_KDE_VERSION}-kidletime
kde-idletime_LIB=		libKF${_KDE_VERSION}IdleTime.so

kde-init_PORT=			x11/kf${_KDE_VERSION}-kinit
kde-init_PATH=			${KDE_PREFIX}/bin/kdeinit5

kde-itemmodels_PORT=		devel/kf${_KDE_VERSION}-kitemmodels
kde-itemmodels_LIB=		libKF${_KDE_VERSION}ItemModels.so

kde-itemviews_PORT=		x11-toolkits/kf${_KDE_VERSION}-kitemviews
kde-itemviews_LIB=		libKF${_KDE_VERSION}ItemViews.so

kde-jobwidgets_PORT=		x11-toolkits/kf${_KDE_VERSION}-kjobwidgets
kde-jobwidgets_LIB=		libKF${_KDE_VERSION}JobWidgets.so

kde-js_PORT=			www/kf${_KDE_VERSION}-kjs
kde-js_LIB=			libKF${_KDE_VERSION}JS.so

kde-jsembed_PORT=		www/kf${_KDE_VERSION}-kjsembed
kde-jsembed_LIB=		libKF${_KDE_VERSION}JsEmbed.so

kde-kcmutils_PORT=		devel/kf${_KDE_VERSION}-kcmutils
kde-kcmutils_LIB=		libKF${_KDE_VERSION}KCMUtils.so

kde-kdeclarative_PORT=		devel/kf${_KDE_VERSION}-kdeclarative
kde-kdeclarative_LIB5=		libKF${_KDE_VERSION}Declarative.so
kde-kdeclarative_LIB6=		libKF${_KDE_VERSION}CalendarEvents.so
kde-kdeclarative_LIB=		${kde-kdeclarative_LIB${_KDE_VERSION}}

kde-kded_PORT=			x11/kf${_KDE_VERSION}-kded
kde-kded_PATH=			${KDE_PREFIX}/bin/kded${_KDE_VERSION}

kde-kdelibs4support_PORT=	x11/kf${_KDE_VERSION}-kdelibs4support
kde-kdelibs4support_LIB=	libKF${_KDE_VERSION}KDELibs4Support.so

kde-kdesu_PORT=			security/kf${_KDE_VERSION}-kdesu
kde-kdesu_LIB=			libKF${_KDE_VERSION}Su.so

kde-khtml_PORT=			www/kf${_KDE_VERSION}-khtml
kde-khtml_LIB=			libKF${_KDE_VERSION}KHtml.so

kde-kimageformats_PORT=		graphics/kf${_KDE_VERSION}-kimageformats
kde-kimageformats_PATH=		${QT_PLUGINDIR}/imageformats/kimg_xcf.so
kde-kimageformats_TYPE=		run

kde-kio_PORT=			devel/kf${_KDE_VERSION}-kio
kde-kio_LIB=			libKF${_KDE_VERSION}KIOCore.so

kde-kirigami2_PORT5=		x11-toolkits/kf${_KDE_VERSION}-kirigami2
kde-kirigami2_PORT6=		x11-toolkits/kf${_KDE_VERSION}-kirigami
kde-kirigami2_PATH5=		${QT_QMLDIR}/org/kde/kirigami.2/libKirigamiPlugin.so
kde-kirigami2_PATH6=		${QT_QMLDIR}/org/kde/kirigami/libKirigamiplugin.so
kde-kirigami2_PORT=		${kde-kirigami2_PORT${_KDE_VERSION}}
kde-kirigami2_PATH=		${kde-kirigami2_PATH${_KDE_VERSION}}

kde-kquickcharts_PORT=		graphics/kf${_KDE_VERSION}-kquickcharts
kde-kquickcharts_PATH5=		${QT_QMLDIR}/org/kde/quickcharts/libQuickCharts.so
kde-kquickcharts_PATH6=		${QT_QMLDIR}/org/kde/quickcharts/libQuickChartsplugin.so
kde-kquickcharts_PATH=		${kde-kquickcharts_PATH${_KDE_VERSION}}

kde-kross_PORT=			lang/kf${_KDE_VERSION}-kross
kde-kross_LIB=			libKF${_KDE_VERSION}KrossCore.so

kde-layer-shell-qt_PORT=	x11/plasma${_KDE_VERSION}-layer-shell-qt
kde-layer-shell-qt_LIB=		libLayerShellQtInterface.so

kde-mediaplayer_PORT=		multimedia/kf${_KDE_VERSION}-kmediaplayer
kde-mediaplayer_LIB=		libKF${_KDE_VERSION}MediaPlayer.so.5

kde-newstuff_PORT=		devel/kf${_KDE_VERSION}-knewstuff
kde-newstuff_LIB=		libKF${_KDE_VERSION}NewStuffCore.so

kde-notifications_PORT=		devel/kf${_KDE_VERSION}-knotifications
kde-notifications_LIB=		libKF${_KDE_VERSION}Notifications.so

kde-notifyconfig_PORT=		devel/kf${_KDE_VERSION}-knotifyconfig
kde-notifyconfig_LIB=		libKF${_KDE_VERSION}NotifyConfig.so

kde-oxygen-icons5_PORT=		x11-themes/kf${_KDE_VERSION}-oxygen-icons5
kde-oxygen-icons5_PATH=		${KDE_PREFIX}/share/icons/oxygen/index.theme
kde-oxygen-icons5_TYPE=		run

kde-oxygen-sounds_PORT=		audio/plasma${_KDE_VERSION}-oxygen-sounds
kde-oxygen-sounds_PATH=		${KDE_PREFIX}/share/sounds/Oxygen-Sys-Log-In.ogg
kde-oxygen-sounds_TYPE=		run

kde-package_PORT=		devel/kf${_KDE_VERSION}-kpackage
kde-package_LIB=		libKF${_KDE_VERSION}Package.so

kde-parts_PORT=			devel/kf${_KDE_VERSION}-kparts
kde-parts_LIB=			libKF${_KDE_VERSION}Parts.so

kde-people_PORT=		devel/kf${_KDE_VERSION}-kpeople
kde-people_LIB=			libKF${_KDE_VERSION}People.so

kde-plasma-framework_PORT=	x11/kf${_KDE_VERSION}-plasma-framework
kde-plasma-framework_LIB=	libKF${_KDE_VERSION}Plasma.so

kde-plasma-wayland-protocols_PORT=	x11/plasma-wayland-protocols
kde-plasma-wayland-protocols_PATH=	${KDE_PREFIX}/lib/cmake/PlasmaWaylandProtocols/PlasmaWaylandProtocolsConfig.cmake

kde-plotting_PORT=		graphics/kf${_KDE_VERSION}-kplotting
kde-plotting_LIB=		libKF${_KDE_VERSION}Plotting.so

kde-prison_PORT=		graphics/kf${_KDE_VERSION}-prison
kde-prison_LIB=			libKF${_KDE_VERSION}Prison.so

kde-pty_PORT=			devel/kf${_KDE_VERSION}-kpty
kde-pty_LIB=			libKF${_KDE_VERSION}Pty.so

kde-purpose_PORT=		misc/kf${_KDE_VERSION}-purpose
kde-purpose_LIB=		libKF${_KDE_VERSION}Purpose.so

kde-qqc2-desktop-style_PORT=	x11-themes/kf${_KDE_VERSION}-qqc2-desktop-style
kde-qqc2-desktop-style_PATH5=	${QT_PLUGINDIR}/kf${_KDE_VERSION}/kirigami/org.kde.desktop.so
kde-qqc2-desktop-style_PATH6=	${QT_QMLDIR}/org/kde/desktop/liborg_kde_desktop.so
kde-qqc2-desktop-style_PATH=	${kde-qqc2-desktop-style_PATH${_KDE_VERSION}}

kde-runner_PORT=		x11/kf${_KDE_VERSION}-krunner
kde-runner_LIB=			libKF${_KDE_VERSION}Runner.so

kde-service_PORT=		devel/kf${_KDE_VERSION}-kservice
kde-service_LIB=		libKF${_KDE_VERSION}Service.so

kde-solid_PORT=			devel/kf${_KDE_VERSION}-solid
kde-solid_LIB=			libKF${_KDE_VERSION}Solid.so

kde-sonnet_PORT=		textproc/kf${_KDE_VERSION}-sonnet
kde-sonnet_LIB=			libKF${_KDE_VERSION}SonnetCore.so

kde-syndication_PORT=		net/kf${_KDE_VERSION}-syndication
kde-syndication_LIB=		libKF${_KDE_VERSION}Syndication.so

kde-syntaxhighlighting_PORT=	textproc/kf${_KDE_VERSION}-syntax-highlighting
kde-syntaxhighlighting_LIB=	libKF${_KDE_VERSION}SyntaxHighlighting.so

kde-texteditor_PORT=		devel/kf${_KDE_VERSION}-ktexteditor
kde-texteditor_LIB=		libKF${_KDE_VERSION}TextEditor.so

kde-textwidgets_PORT=		x11-toolkits/kf${_KDE_VERSION}-ktextwidgets
kde-textwidgets_LIB=		libKF${_KDE_VERSION}TextWidgets.so

kde-threadweaver_PORT=		devel/kf${_KDE_VERSION}-threadweaver
kde-threadweaver_LIB=		libKF${_KDE_VERSION}ThreadWeaver.so

kde-unitconversion_PORT=	devel/kf${_KDE_VERSION}-kunitconversion
kde-unitconversion_LIB=		libKF${_KDE_VERSION}UnitConversion.so

kde-wallet_PORT=		sysutils/kf${_KDE_VERSION}-kwallet
kde-wallet_LIB=			libKF${_KDE_VERSION}Wallet.so

kde-wayland_PORT5=		x11/kf${_KDE_VERSION}-kwayland
kde-wayland_PORT6=		x11/plasma${_KDE_VERSION}-kwayland
kde-wayland_PORT=		${kde-wayland_PORT${_KDE_VERSION}}
kde-wayland_LIB5=		libKF${_KDE_VERSION}WaylandClient.so
kde-wayland_LIB6=		libKWaylandClient.so
kde-wayland_LIB=		${kde-wayland_LIB${_KDE_VERSION}}

kde-widgetsaddons_PORT=		x11-toolkits/kf${_KDE_VERSION}-kwidgetsaddons
kde-widgetsaddons_LIB=		libKF${_KDE_VERSION}WidgetsAddons.so

kde-windowsystem_PORT=		x11/kf${_KDE_VERSION}-kwindowsystem
kde-windowsystem_LIB=		libKF${_KDE_VERSION}WindowSystem.so

kde-xmlgui_PORT=		x11-toolkits/kf${_KDE_VERSION}-kxmlgui
kde-xmlgui_LIB=			libKF${_KDE_VERSION}XmlGui.so

kde-xmlrpcclient_PORT=		net/kf${_KDE_VERSION}-kxmlrpcclient
kde-xmlrpcclient_LIB=		libKF${_KDE_VERSION}XmlRpcClient.so

kde-calendarcore_PORT=		net/kf${_KDE_VERSION}-kcalendarcore
kde-calendarcore_LIB=		libKF${_KDE_VERSION}CalendarCore.so

kde-contacts_PORT=		net/kf${_KDE_VERSION}-kcontacts
kde-contacts_LIB=		libKF${_KDE_VERSION}Contacts.so

kde-kdav_PORT=			net/kf${_KDE_VERSION}-kdav
kde-kdav_LIB=			libKF${_KDE_VERSION}DAV.so

kde-colorscheme_PORT=		x11-themes/kf${_KDE_VERSION}-kcolorscheme
kde-colorscheme_LIB=		libKF${_KDE_VERSION}ColorScheme.so

kde-svg_PORT=			graphics/kf${_KDE_VERSION}-ksvg
kde-svg_LIB=			libKF${_KDE_VERSION}Svg.so

kde-statusnotifieritem_PORT=	deskutils/kf6-kstatusnotifieritem
kde-statusnotifieritem_LIB=	libKF${_KDE_VERSION}StatusNotifierItem.so

kde-userfeedback_PORT=		sysutils/kf6-kuserfeedback
kde-userfeedback_LIB=		libKF${_KDE_VERSION}UserFeedbackCore.so

# ====================== end of frameworks components ==========================

# ====================== plasma components =====================================
kde-kpipewire_PORT=		audio/plasma${_KDE_VERSION}-kpipewire
kde-kpipewire_LIB=		libKPipeWire.so

kde-activitymanagerd_PORT=	x11/plasma${_KDE_VERSION}-kactivitymanagerd
kde-activitymanagerd_LIB=	libkactivitymanagerd_plugin.so

kde-breeze_PORT=		x11-themes/plasma${_KDE_VERSION}-breeze
kde-breeze_PATH=		${KDE_PREFIX}/share/QtCurve/Breeze.qtcurve

kde-breeze-gtk_PORT=		x11-themes/plasma${_KDE_VERSION}-breeze-gtk
kde-breeze-gtk_PATH=		${KDE_PREFIX}/share/themes/Breeze/gtk-2.0/gtkrc

kde-decoration_PORT=		x11-wm/plasma${_KDE_VERSION}-kdecoration
kde-decoration_LIB=		libkdecorations2.so

kde-discover_PORT=		sysutils/plasma${_KDE_VERSION}-discover
kde-discover_PATH=		${KDE_PREFIX}/bin/plasma-discover

kde-drkonqi_PORT=		sysutils/plasma${_KDE_VERSION}-drkonqi
kde-drkonqi_PATH=		${KDE_PREFIX}/lib/libexec/drkonqi

kde-hotkeys_PORT=		devel/plasma${_KDE_VERSION}-khotkeys
kde-hotkeys_LIB=		libkhotkeysprivate.so.5

kde-infocenter_PORT=		sysutils/plasma${_KDE_VERSION}-kinfocenter
kde-infocenter_PATH=		${KDE_PREFIX}/bin/kinfocenter

kde-kde-cli-tools_PORT=		sysutils/plasma${_KDE_VERSION}-kde-cli-tools
kde-kde-cli-tools_PATH=		${KDE_PREFIX}/bin/kde-open

kde-kde-gtk-config_PORT=	x11-themes/plasma${_KDE_VERSION}-kde-gtk-config
kde-kde-gtk-config_PATH=	${KDE_PREFIX}/lib/kconf_update_bin/gtk_theme

kde-kdeplasma-addons_PORT=	x11-toolkits/plasma${_KDE_VERSION}-kdeplasma-addons
kde-kdeplasma-addons_LIB=	libplasmapotdprovidercore.so

kde-kgamma5_PORT5=		x11/plasma${_KDE_VERSION}-kgamma5
kde-kgamma5_PORT6=		x11/plasma${_KDE_VERSION}-kgamma
kde-kgamma5_PORT=		${kde-kgamma5_PORT${_KDE_VERSION}}
kde-kgamma5_PATH5=		${QT_PLUGINDIR}/plasma/kcms/systemsettings/kcm_kgamma.so
kde-kgamma5_PATH6=		${QT_PLUGINDIR}/plasma/kcms/systemsettings_qwidgets/kcm_kgamma.so
kde-kgamma5_PATH=		${kde-kgamma5_PATH${_KDE_VERSION}}

kde-kmenuedit_PORT=		sysutils/plasma${_KDE_VERSION}-kmenuedit
kde-kmenuedit_PATH=		${KDE_PREFIX}/bin/kmenuedit

kde-kscreen_PORT=		x11/plasma${_KDE_VERSION}-kscreen
kde-kscreen_PATH=		${KDE_PREFIX}/bin/kscreen-console

kde-kscreenlocker_PORT=		security/plasma${_KDE_VERSION}-kscreenlocker
kde-kscreenlocker_LIB=		libKScreenLocker.so

kde-ksshaskpass_PORT=		security/plasma${_KDE_VERSION}-ksshaskpass
kde-ksshaskpass_PATH=		${KDE_PREFIX}/bin/ksshaskpass

kde-ksysguard_PORT=		sysutils/plasma${_KDE_VERSION}-ksysguard
kde-ksysguard_PATH=		${KDE_PREFIX}/bin/ksysguard

kde-ksystemstats_PORT=		sysutils/plasma${_KDE_VERSION}-ksystemstats
kde-ksystemstats_PATH=		${KDE_PREFIX}/bin/ksystemstats

kde-kwallet-pam_PORT=		security/plasma${_KDE_VERSION}-kwallet-pam
kde-kwallet-pam_PATH5=		${KDE_PREFIX}/lib/pam_kwallet5.so
kde-kwallet-pam_PATH6=		${KDE_PREFIX}/lib/security/pam_kwallet5.so
kde-kwallet-pam_PATH=		${kde-kwallet-pam_PATH${_KDE_VERSION}}

kde-kwayland-integration_PORT=	x11/plasma${_KDE_VERSION}-kwayland-integration
kde-kwayland-integration_PATH=	${QT_PLUGINDIR}/kf${_KDE_VERSION}/kwindowsystem/KF5WindowSystemKWaylandPlugin.so

kde-kwin_PORT=			x11-wm/plasma${_KDE_VERSION}-kwin
kde-kwin_PATH=			${KDE_PREFIX}/bin/kwin_x11

kde-kwrited_PORT=		devel/plasma${_KDE_VERSION}-kwrited
kde-kwrited_PATH=		${QT_PLUGINDIR}/kf${_KDE_VERSION}/kded/kwrited.so

kde-libkscreen_PORT=		x11/plasma${_KDE_VERSION}-libkscreen
kde-libkscreen_LIB=		libKF${_KDE_VERSION}Screen.so

kde-libksysguard_PORT=		sysutils/plasma${_KDE_VERSION}-libksysguard
kde-libksysguard_LIB5=		libksgrd.so
kde-libksysguard_LIB6=		libKSysGuardSystemStats.so
kde-libksysguard_LIB=		${kde-libksysguard_LIB${_KDE_VERSION}}

kde-milou_PORT=			deskutils/plasma${_KDE_VERSION}-milou
kde-milou_PATH5=			${KDE_PREFIX}/lib/libmilou.so.5
kde-milou_PATH6=		${QT_QMLDIR}/org/kde/milou/libmilouqmlplugin.so
kde-milou_PATH=			${kde-milou_PATH${_KDE_VERSION}}

kde-oxygen_PORT=		x11-themes/plasma${_KDE_VERSION}-oxygen
kde-oxygen_PATH5=		${QT_PLUGINDIR}/styles/oxygen.so
kde-oxygen_PATH6=		${QT_PLUGINDIR}/kstyle_config/kstyle_oxygen_config.so
kde-oxygen_PATH=		${kde-oxygen_PATH${_KDE_VERSION}}

kde-plasma-browser-integration_PORT=	www/plasma${_KDE_VERSION}-plasma-browser-integration
kde-plasma-browser-integration_PATH=	${KDE_PREFIX}/bin/plasma-browser-integration-host

kde-plasma-desktop_PORT=	x11/plasma${_KDE_VERSION}-plasma-desktop
kde-plasma-desktop_PATH=	${KDE_PREFIX}/bin/kaccess

kde-plasma-disks_PORT=		sysutils/plasma${_KDE_VERSION}-plasma-disks
kde-plasma-disks_PATH5=		${KDE_PREFIX}/lib/libexec/kauth/kded-smart-helper
kde-plasma-disks_PATH6=		${KDE_PREFIX}/lib/libexec/kf6/kauth/kded-smart-helper
kde-plasma-disks_PATH=		${kde-plasma-disks_PATH${_KDE_VERSION}}

kde-plasma-integration_PORT=	x11/plasma${_KDE_VERSION}-plasma-integration
kde-plasma-integration_PATH5=	${QT_PLUGINDIR}/platformthemes/KDEPlasmaPlatformTheme.so
kde-plasma-integration_PATH6=	${QT_PLUGINDIR}/platformthemes/KDEPlasmaPlatformTheme6.so
kde-plasma-integration_PATH=	${kde-plasma-integration_PATH${_KDE_VERSION}}

kde-plasma-pa_PORT=		audio/plasma${_KDE_VERSION}-plasma-pa
kde-plasma-pa_PATH=		${QT_PLUGINDIR}/plasma/kcms/systemsettings/kcm_pulseaudio.so

kde-plasma-sdk_PORT=		devel/plasma${_KDE_VERSION}-plasma-sdk
kde-plasma-sdk_PATH=		${KDE_PREFIX}/bin/plasmoidviewer

kde-plasma-workspace_PORT=	x11/plasma${_KDE_VERSION}-plasma-workspace
kde-plasma-workspace_LIB=	libkworkspace${_KDE_VERSION}.so

kde-plasma-workspace-wallpapers_PORT=	x11-themes/plasma${_KDE_VERSION}-plasma-workspace-wallpapers
kde-plasma-workspace-wallpapers_PATH=	${KDE_PREFIX}/share/wallpapers/Autumn/contents/images/1280x1024.jpg

kde-polkit-kde-agent-1_PORT=	sysutils/plasma${_KDE_VERSION}-polkit-kde-agent-1
kde-polkit-kde-agent-1_PATH=	${KDE_PREFIX}/lib/libexec/polkit-kde-authentication-agent-1

kde-powerdevil_PORT=		sysutils/plasma${_KDE_VERSION}-powerdevil
kde-powerdevil_LIB=		libpowerdevilcore.so

kde-systemsettings_PORT=	sysutils/plasma${_KDE_VERSION}-systemsettings
kde-systemsettings_PATH5=	${KDE_PREFIX}/bin/systemsettings5
kde-systemsettings_PATH6=	${KDE_PREFIX}/bin/systemsettings
kde-systemsettings_PATH=	${kde-systemsettings_PATH${_KDE_VERSION}}



kde-xdg-desktop-portal-kde_PORT=	deskutils/plasma${_KDE_VERSION}-xdg-desktop-portal-kde
kde-xdg-desktop-portal-kde_PATH=	${KDE_PREFIX}/lib/libexec/xdg-desktop-portal-kde

kde-plasma5support_PORT=	devel/plasma${_KDE_VERSION}-plasma5support
kde-plasma5support_LIB=		libPlasma5Support.so

kde-kirigami-addons_PORT5=	x11-toolkits/kirigami-addons
kde-kirigami-addons_PORT6=	x11-toolkits/kirigami-addons-devel
kde-kirigami-addons_PORT=	${kde-kirigami-addons_PORT${_KDE_VERSION}}
kde-kirigami-addons_PATH=	${QT_QMLDIR}/org/kde/kirigamiaddons/components/libcomponentsplugin.so

kde-globalacceld_PORT=		x11/plasma${_KDE_VERSION}-kglobalacceld
kde-globalacceld_PATH=		${QT_PLUGINDIR}/org.kde.kglobalacceld.platforms/KGlobalAccelDXcb.so

kde-libplasma_PORT=		x11/plasma${_KDE_VERSION}-libplasma
kde-libplasma_LIB=		libPlasma.so
# ====================== end of plasma components ==============================

# ====================== pim5 components =======================================
kde-akonadicontacts_PORT=	net/akonadi-contacts
kde-akonadicontacts_LIB=	libKPim5AkonadiContact.so

kde-akonadiimportwizard_PORT=	deskutils/akonadi-import-wizard
kde-akonadiimportwizard_LIB=	libKPim5ImportWizard.so

kde-akonadimime_PORT=		net/akonadi-mime
kde-akonadimime_LIB=		libKPim5AkonadiMime.so

kde-akonadinotes_PORT=		net/akonadi-notes
kde-akonadinotes_LIB=		libKPim5AkonadiNotes.so

kde-akonadicalendar_PORT=	net/akonadi-calendar
kde-akonadicalendar_LIB=	libKPim5AkonadiCalendar.so

kde-akonadisearch_PORT=		net/akonadi-search
kde-akonadisearch_LIB=		libKPim5AkonadiSearchCore.so

kde-calendarsupport_PORT=	net/calendarsupport
kde-calendarsupport_LIB=	libKPim5CalendarSupport.so

kde-calendarutils_PORT=		net/kcalutils
kde-calendarutils_LIB=		libKPim5CalendarUtils.so

kde-eventviews_PORT=		net/eventviews
kde-eventviews_LIB=		libKPim5EventViews.so

kde-gapi_PORT=			net/libkgapi
kde-gapi_LIB=			libKPim5GAPIBlogger.so

kde-grantleetheme_PORT=		deskutils/grantleetheme
kde-grantleetheme_LIB=		libKPim5GrantleeTheme.so

kde-gravatar_PORT=		net/libgravatar
kde-gravatar_LIB=		libKPim5Gravatar.so

kde-identitymanagement_PORT=	net/kidentitymanagement
kde-identitymanagement_LIB=	libKPim5IdentityManagement.so

kde-imap_PORT=			net/kimap
kde-imap_LIB=			libKPim5IMAP.so

kde-incidenceeditor_PORT=	net/incidenceeditor
kde-incidenceeditor_LIB=	libKPim5IncidenceEditor.so

kde-kdepim-addons_PORT=	deskutils/kdepim-addons
kde-kdepim-addons_PATH=	${QT_PLUGINDIR}/pim5/contacteditor/editorpageplugins/cryptopageplugin.so

kde-kdepim-runtime5_PORT=	deskutils/kdepim-runtime
kde-kdepim-runtime5_PATH=	${KDE_PREFIX}/bin/gidmigrator

kde-kitinerary_PORT=		net/kitinerary
kde-kitinerary_LIB=		libKPim5Itinerary.so

kde-kontactinterface_PORT=	net/kontactinterface
kde-kontactinterface_LIB=	libKPim5KontactInterface.so

kde-kpkpass_PORT=		security/kpkpass
kde-kpkpass_LIB=		libKPim5PkPass.so

kde-ksmtp_PORT=			net/ksmtp
kde-ksmtp_LIB=			libKPim5SMTP.so

kde-ldap_PORT=			net/kldap
kde-ldap_LIB=			libKPim5Ldap.so

kde-libkdepim_PORT=		deskutils/libkdepim
kde-libkdepim_LIB=		libKPim5Libkdepim.so

kde-libkleo_PORT=		security/libkleo
kde-libkleo_LIB=		libKPim5Libkleo.so

kde-libksieve_PORT=		net/libksieve
kde-libksieve_LIB=		libKPim5KSieve.so

kde-mailcommon_PORT=		net/mailcommon
kde-mailcommon_LIB=		libKPim5MailCommon.so

kde-mailimporter_PORT=		net/mailimporter
kde-mailimporter_LIB=		libKPim5MailImporter.so

kde-mailtransport_PORT=		net/kmailtransport
kde-mailtransport_LIB=		libKPim5MailTransport.so

kde-mbox_PORT=			net/kmbox
kde-mbox_LIB=			libKPim5Mbox.so

kde-messagelib_PORT=		net/messagelib
kde-messagelib_LIB=		libKPim5MessageList.so

kde-mime_PORT=			net/kmime
kde-mime_LIB=			libKPim5Mime.so

kde-pimcommon_PORT=		net/pimcommon
kde-pimcommon_LIB=		libKPim5PimCommon.so

kde-pimtextedit_PORT=		net/kpimtextedit
kde-pimtextedit_LIB=		libKPim5TextEdit.so

kde-tnef_PORT=			net/ktnef
kde-tnef_LIB=			libKPim5Tnef.so

kde-ktextaddons_PORT=		devel/ktextaddons
kde-ktextaddons_LIB=		libKF${_KDE_VERSION}TextAutoCorrectionCore.so

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
kde-akonadi5_LIB=		libKPim5AkonadiPrivate.so

kde-baloo-widgets5_PORT=	sysutils/baloo-widgets
kde-baloo-widgets5_LIB=		libKF${_KDE_VERSION}BalooWidgets.so

kde-kate5_PORT=			editors/kate
kde-kate5_PATH=			${QT_PLUGINDIR}/ktexteditor/katebacktracebrowserplugin.so

kde-libkcddb5_PORT=		audio/libkcddb
kde-libkcddb5_LIB=		libKF${_KDE_VERSION}Cddb.so

kde-libkcompactdisc5_PORT=	audio/libkcompactdisc
kde-libkcompactdisc5_LIB=	libKF${_KDE_VERSION}CompactDisc.so

kde-libkdcraw5_PORT=		graphics/libkdcraw@qt${_KDE_VERSION}
kde-libkdcraw5_LIB=		libKF${_KDE_VERSION}KDcraw.so

kde-libkdegames5_PORT=		games/libkdegames
kde-libkdegames5_LIB=		libKF${_KDE_VERSION}KDEGames.so

kde-libkeduvocdocument5_PORT=	misc/libkeduvocdocument
kde-libkeduvocdocument5_LIB=	libKEduVocDocument.so

kde-libkexiv2_PORT5=		graphics/libkexiv2
kde-libkexiv2_PORT6=		graphics/libkexiv2-devel
kde-libkexiv2_PORT=		${kde-libkexiv2_PORT${_KDE_VERSION}}
kde-libkexiv2_LIB5=		libKF${_KDE_VERSION}KExiv2.so
kde-libkexiv2_LIB6=		libKExiv2Qt${_KDE_VERSION}.so
kde-libkexiv2_LIB=		${kde-libkexiv2_LIB${_KDE_VERSION}}

kde-libkipi5_PORT=		graphics/libkipi
kde-libkipi5_LIB=		libKF${_KDE_VERSION}Kipi.so

kde-libksane5_PORT=		graphics/libksane
kde-libksane5_LIB=		libKF${_KDE_VERSION}Sane.so

kde-marble5_PORT=		astro/marble
kde-marble5_LIB=		libmarblewidget-qt5.so

kde-kpublictransport_PORT=	devel/kpublictransport
kde-kpublictransport_LIB=	libKPublicTransport.so

kde-kosm_PORT=			astro/kosmindoormap
kde-kosm_LIB=			libKOSM.so

kde-okular5_PORT=		graphics/okular
kde-okular5_LIB=		libOkular5Core.so

kde-phonon_PORT=		multimedia/phonon@${_QT_RELNAME}
kde-phonon_LIB=			libphonon4${_QT_RELNAME}.so

kde-phonon-backend_PORT=	multimedia/phonon-vlc@${_QT_RELNAME}
kde-phonon-backend_PATH=	${QT_PLUGINDIR}/phonon4${_QT_RELNAME}_backend/phonon_vlc_${_QT_RELNAME}.so
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
.    for component in ${USE_KDE:O:u:C/:.+//}
  # Check that the component is valid.
.      if ${_USE_KDE_ALL:M${component}} != ""
   # Skip meta-components (currently none).
.        if defined(kde-${component}_PORT) && (defined(kde-${component}_PATH) || defined(kde-${component}_LIB))
    # Check if a dependency type is explicitly requested.
.          if ${USE_KDE:M${component}\:*} != "" && ${USE_KDE:M${component}} == ""
kde-${component}_TYPE=	# empty
.            if ${USE_KDE:M${component}\:build} != ""
kde-${component}_TYPE+=	build
.            endif
.            if ${USE_KDE:M${component}\:run} != ""
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
