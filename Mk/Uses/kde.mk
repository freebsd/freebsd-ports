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

KDE_APPLICATIONS_BRANCH?=	${KDE_APPLICATIONS6_BRANCH}
KDE_APPLICATIONS_VERSION?=	${KDE_APPLICATIONS6_VERSION}
KDE_APPLICATIONS_SHLIB_VER?=	${KDE_APPLICATIONS6_SHLIB_VER}
KDE_APPLICATIONS_SHLIB_G_VER?=	${KDE_APPLICATIONS6_SHLIB_G_VER}

# Legacy KDE Plasma.
KDE_PLASMA5_VERSION?=		5.27.12
KDE_PLASMA5_BRANCH?=		stable

# Current KDE Plasma desktop.
KDE_PLASMA6_VERSION?=		6.4.1
KDE_PLASMA6_BRANCH?=		stable

# Legacy KDE frameworks (Qt5 based).
KDE_FRAMEWORKS5_VERSION?=	5.116.0
KDE_FRAMEWORKS5_BRANCH?=	stable

# Current KDE Frameworks (Qt6 based).
KDE_FRAMEWORKS6_VERSION?=	6.15.0
KDE_FRAMEWORKS6_BRANCH?=	stable

# Current KDE applications. Update _${PORTNAME}_PROJECT_VERSION for the following ports:
# devel/kdevelop, games/libkdegames, games/libkmahjongg, graphics/kgraphviewer
KDE_APPLICATIONS6_VERSION?=	25.04.2
KDE_APPLICATIONS6_SHLIB_VER?=	6.4.2
# G as in KDE Gear, and as in "don't make the variable name longer than required".
KDE_APPLICATIONS6_SHLIB_G_VER?=	${KDE_APPLICATIONS6_VERSION}
KDE_APPLICATIONS6_BRANCH?=	stable

# Some projects despite being a part of Gear distribution continue to use
# their own versioning with mangled KDE_APPLICATIONS_VERSION as a patchlevel.
# Provide more variables to ease their maintenance.
KDE_APPS_MAJOR=		${KDE_APPLICATIONS_VERSION:R:R}
KDE_APPS_MINOR=		${KDE_APPLICATIONS_VERSION:R:E}
.    if ${KDE_APPLICATIONS_BRANCH:Mstable}
KDE_APPS_MICRO=			0${KDE_APPLICATIONS_VERSION:E}
.    else
KDE_APPS_MICRO=			${KDE_APPLICATIONS_VERSION:E}
.    endif
KDE_APPS_BASED_PATCHLEVEL?=	${KDE_APPS_MAJOR}${KDE_APPS_MINOR}${KDE_APPS_MICRO}

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
.        if defined(_${PORTNAME}_PROJECT_VERSION)
PLIST_SUB+=		SHLIB_VER_LONG=${_${PORTNAME}_PROJECT_VERSION}.${KDE_APPS_BASED_PATCHLEVEL}
.        endif
DIST_SUBDIR?=		KDE/release-service/${KDE_APPLICATIONS_VERSION}
.      elif ${_KDE_CATEGORY:Mkde-plasma}
PORTVERSION?=		${KDE_PLASMA_VERSION}
PKGNAMEPREFIX?=		plasma${_KDE_VERSION}-
MASTER_SITES?=		KDE/${KDE_PLASMA_BRANCH}/plasma/${KDE_PLASMA_VERSION}
DIST_SUBDIR?=		KDE/plasma/${KDE_PLASMA_VERSION}
WWW?=			https://kde.org/plasma-desktop/
.        if ${_KDE_VERSION:M6}
DESCR=			${.CURDIR:H:H}/x11/plasma6-plasma/pkg-descr
.        endif
.      elif ${_KDE_CATEGORY:Mkde-frameworks}
PORTVERSION?=		${KDE_FRAMEWORKS_VERSION}
PKGNAMEPREFIX?=		kf${_KDE_VERSION}-
WWW?=			https://api.kde.org/frameworks/${PORTNAME}/html/index.html
# This is a slight duplication of _USE_PORTINGAIDS_ALL
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
DIST_SUBDIR=		KDE/frameworks/${KDE_FRAMEWORKS_VERSION:R}
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

# Enforce the chosen Qt Version
CMAKE_ARGS+=	-DQT_MAJOR_VERSION=${_QT_VER}

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

# List of all USE_KDE components.
# TODO for KDE 7: do not mangle upstream naming: use the same name
# for port directory, PORTNAME, and USE_KDE component.

# Porting Aids frameworks provide code and utilities to ease the transition from
# kdelibs 4 to KDE Frameworks 5.
_USE_PORTINGAIDS_ALL=	js jsembed kdelibs4support khtml mediaplayer kross

# List of components of the KDE Frameworks distribution.
# Not ported to FreeBSD: bluez-qt modemmanagerqt
_USE_FRAMEWORKS5_ALL=	activities activities-stats apidox archive attica \
			auth baloo bookmarks breeze-icons calendarcore \
			codecs completion config configwidgets contacts \
			coreaddons crash dbusaddons designerplugin dnssd \
			doctools ecm emoticons filemetadata frameworkintegration \
			globalaccel guiaddons holidays i18n iconthemes \
			idletime init itemmodels itemviews jobwidgets \
			kcmutils kdav kdeclarative kded kdesu kimageformats \
			kio kirigami2 kquickcharts newstuff notifications \
			notifyconfig package parts people plasma-framework \
			plotting prison pty purpose qqc2-desktop-style \
			runner service solid sonnet syndication \
			syntaxhighlighting texteditor textwidgets \
			threadweaver unitconversion wallet wayland \
			widgetsaddons windowsystem xmlgui xmlrpcclient \
			${_USE_PORTINGAIDS_ALL}

_USE_FRAMEWORKS6_ALL=	apidox archive attica auth baloo bookmarks \
			breeze-icons calendarcore codecs colorscheme \
			completion config configwidgets contacts coreaddons \
			crash dbusaddons dnssd doctools ecm filemetadata \
			frameworkintegration globalaccel guiaddons holidays \
			i18n iconthemes idletime itemmodels itemviews \
			jobwidgets kcmutils kdav kdeclarative kded kdesu \
			kimageformats kio kirigami2 kquickcharts newstuff \
			networkmanagerqt notifications notifyconfig package parts \
			people plasma-wayland-protocols plotting prison pty purpose \
			qqc2-desktop-style runner service solid sonnet \
			statusnotifieritem svg syndication \
			syntaxhighlighting texteditor texttemplate \
			textwidgets threadweaver unitconversion userfeedback \
			wallet widgetsaddons windowsystem xmlgui
_USE_FRAMEWORKS_ALL=	${_USE_FRAMEWORKS${_KDE_VERSION}_ALL}

# List of components of the KDE Plasma distribution.
_USE_PLASMA5_ALL=	libksysguard oxygen-sounds

_USE_PLASMA6_ALL=	activities activities-stats activitymanagerd \
			aurorae breeze breeze-gtk decoration discover \
			globalacceld infocenter kde-cli-tools \
			kde-gtk-config kdeplasma-addons kgamma kmenuedit \
			kpipewire kscreen kscreenlocker ksshaskpass \
			ksystemstats kwallet-pam kwin kwin-x11 kwrited \
			layer-shell-qt libkscreen libksysguard libplasma \
			milou ocean-sound-theme oxygen oxygen-sounds \
			plasma-browser-integration plasma-desktop \
			plasma-disks plasma-integration plasma-pa \
			plasma-sdk plasma-workspace \
			plasma-workspace-wallpapers plasma5support \
			polkit-kde-agent-1 powerdevil print-manager \
			qqc2-breeze-style sddm-kcm spectacle systemmonitor \
			systemsettings wayland xdg-desktop-portal-kde
_USE_PLASMA_ALL=	${_USE_PLASMA${_KDE_VERSION}_ALL}

# List of frequently used components of the KDE Gears distribution.
_USE_GEAR5_ALL=		libkdcraw libkexiv2
_USE_GEAR6_ALL=		baloo-widgets kate kosm kpublictransport \
			libkcddb libkcompactdisc libkdcraw \
			libkdegames libkeduvocdocument libkexiv2 \
			libksane marble okular
_USE_GEAR_ALL=		${_USE_GEAR${_KDE_VERSION}_ALL}

# List of components of the KDE PIM distribution (part of KDE Gears).
_USE_KDEPIM_ALL=	akonadi akonadicalendar akonadiconsole \
			akonadicontacts akonadiimportwizard akonadimime \
			akonadisearch akregator calendarsupport \
			calendarutils eventviews gapi grantlee-editor \
			grantleetheme gravatar identitymanagement imap \
			incidenceeditor kaddressbook kalarm kdepim-addons \
			kdepim-runtime kitinerary kmail kmail-account-wizard \
			kontact kontactinterface korganizer kpkpass ksmtp \
			ldap libkdepim libkleo libksieve mailcommon \
			mailimporter mailtransport mbox mbox-importer \
			messagelib mime mimetreeparser pim-data-exporter \
			pimcommon pimtextedit tnef

# List of frequently used KDE releated software for any KDE/Qt version.
_USE_KDE_EXTRA5_ALL=	kirigami-addons phonon phonon-vlc \
			plasma-wayland-protocols
_USE_KDE_EXTRA6_ALL=	kirigami-addons phonon phonon-mpv phonon-vlc \
			plasma-wayland-protocols ktextaddons
_USE_KDE_EXTRA_ALL=	${_USE_KDE_EXTRA${_KDE_VERSION}_ALL}

_USE_KDE5_ALL=		${_USE_FRAMEWORKS_ALL} \
			${_USE_PLASMA_ALL} \
			${_USE_GEAR_ALL} \
			${_USE_KDE_EXTRA_ALL}

_USE_KDE6_ALL=		${_USE_FRAMEWORKS_ALL}  \
			${_USE_PLASMA_ALL} \
			${_USE_KDEPIM_ALL} \
			${_USE_GEAR_ALL} \
			${_USE_KDE_EXTRA_ALL}

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

# Use KApiDox tools from KDE Frameworks 6
kde-apidox_PORT=		devel/kf6-kapidox
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

# Use the latest icons from KDE Frameworks 6
kde-breeze-icons_PORT=		x11-themes/kf6-breeze-icons
kde-breeze-icons_PATH=		${KDE_PREFIX}/share/icons/breeze/index.theme

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

# Use ECM from KDE Frameworks 6 for everything
kde-ecm_PORT=			devel/kf6-extra-cmake-modules
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

kde-networkmanagerqt_PORT=	net-mgmt/kf${_KDE_VERSION}-networkmanager-qt
kde-networkmanagerqt_LIB=	libKF${_KDE_VERSION}NetworkManagerQt.so

kde-newstuff_PORT=		devel/kf${_KDE_VERSION}-knewstuff
kde-newstuff_LIB=		libKF${_KDE_VERSION}NewStuffCore.so

kde-notifications_PORT=		devel/kf${_KDE_VERSION}-knotifications
kde-notifications_LIB=		libKF${_KDE_VERSION}Notifications.so

kde-notifyconfig_PORT=		devel/kf${_KDE_VERSION}-knotifyconfig
kde-notifyconfig_LIB=		libKF${_KDE_VERSION}NotifyConfig.so

# Use the latest sounds from Plasma 6
kde-oxygen-sounds_PORT=		audio/plasma6-oxygen-sounds
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

kde-texttemplate_PORT=		devel/kf${_KDE_VERSION}-ktexttemplate
kde-texttemplate_LIB=		libKF${_KDE_VERSION}TextTemplate.so

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

kde-aurorae_PORT=		x11-themes/plasma${_KDE_VERSION}-aurorae
kde-aurorae_PATH=		${KDE_PREFIX}/lib/libexec/plasma-apply-aurorae

kde-breeze_PORT=		x11-themes/plasma${_KDE_VERSION}-breeze
kde-breeze_PATH=		${KDE_PREFIX}/share/QtCurve/Breeze.qtcurve

kde-breeze-gtk_PORT=		x11-themes/plasma${_KDE_VERSION}-breeze-gtk
kde-breeze-gtk_PATH=		${KDE_PREFIX}/share/themes/Breeze/gtk-2.0/gtkrc

kde-decoration_PORT=		x11-wm/plasma${_KDE_VERSION}-kdecoration
kde-decoration_LIB=		libkdecorations3.so

kde-discover_PORT=		sysutils/plasma${_KDE_VERSION}-discover
kde-discover_PATH=		${KDE_PREFIX}/bin/plasma-discover

kde-infocenter_PORT=		sysutils/plasma${_KDE_VERSION}-kinfocenter
kde-infocenter_PATH=		${KDE_PREFIX}/bin/kinfocenter

kde-kde-cli-tools_PORT=		sysutils/plasma${_KDE_VERSION}-kde-cli-tools
kde-kde-cli-tools_PATH=		${KDE_PREFIX}/bin/kde-open

kde-kde-gtk-config_PORT=	x11-themes/plasma${_KDE_VERSION}-kde-gtk-config
kde-kde-gtk-config_PATH=	${KDE_PREFIX}/lib/kconf_update_bin/gtk_theme

kde-kdeplasma-addons_PORT=	x11-toolkits/plasma${_KDE_VERSION}-kdeplasma-addons
kde-kdeplasma-addons_LIB=	libplasmapotdprovidercore.so

kde-kgamma_PORT=		x11/plasma${_KDE_VERSION}-kgamma
kde-kgamma_PATH=		${QT_PLUGINDIR}/plasma/kcms/systemsettings_qwidgets/kcm_kgamma.so

kde-kmenuedit_PORT=		sysutils/plasma${_KDE_VERSION}-kmenuedit
kde-kmenuedit_PATH=		${KDE_PREFIX}/bin/kmenuedit

kde-kscreen_PORT=		x11/plasma${_KDE_VERSION}-kscreen
kde-kscreen_PATH=		${KDE_PREFIX}/bin/kscreen-console

kde-kscreenlocker_PORT=		security/plasma${_KDE_VERSION}-kscreenlocker
kde-kscreenlocker_LIB=		libKScreenLocker.so

kde-ksshaskpass_PORT=		security/plasma${_KDE_VERSION}-ksshaskpass
kde-ksshaskpass_PATH=		${KDE_PREFIX}/bin/ksshaskpass

kde-ksystemstats_PORT=		sysutils/plasma${_KDE_VERSION}-ksystemstats
kde-ksystemstats_PATH=		${KDE_PREFIX}/bin/ksystemstats

kde-kwallet-pam_PORT=		security/plasma${_KDE_VERSION}-kwallet-pam
kde-kwallet-pam_PATH=		${KDE_PREFIX}/lib/pam_kwallet5.so

kde-kwin_PORT=			x11-wm/plasma${_KDE_VERSION}-kwin
kde-kwin_PATH=			${KDE_PREFIX}/bin/kwin_wayland

kde-kwin-x11_PORT=		x11-wm/plasma${_KDE_VERSION}-kwin-x11
kde-kwin-x11_PATH=		${KDE_PREFIX}/bin/kwin_x11

kde-kwrited_PORT=		devel/plasma${_KDE_VERSION}-kwrited
kde-kwrited_PATH=		${QT_PLUGINDIR}/kf${_KDE_VERSION}/kded/kwrited.so

kde-libkscreen_PORT=		x11/plasma${_KDE_VERSION}-libkscreen
kde-libkscreen_LIB=		libKF${_KDE_VERSION}Screen.so

kde-libksysguard_PORT=		sysutils/plasma${_KDE_VERSION}-libksysguard
kde-libksysguard_LIB5=		libksgrd.so
kde-libksysguard_LIB6=		libKSysGuardSystemStats.so
kde-libksysguard_LIB=		${kde-libksysguard_LIB${_KDE_VERSION}}

kde-milou_PORT=			deskutils/plasma${_KDE_VERSION}-milou
kde-milou_PATH=		${QT_QMLDIR}/org/kde/milou/libmilouqmlplugin.so

kde-ocean-sound-theme_PORT=	audio/plasma${_KDE_VERSION}-ocean-sound-theme
kde-ocean-sound-theme_PATH=	${KDE_PREFIX}/share/sounds/ocean/index.theme
kde-ocean-sound-theme_TYPE=	run

kde-oxygen_PORT=		x11-themes/plasma${_KDE_VERSION}-oxygen
kde-oxygen_PATH=		${QT_PLUGINDIR}/kstyle_config/kstyle_oxygen_config.so

kde-plasma-browser-integration_PORT=	www/plasma${_KDE_VERSION}-plasma-browser-integration
kde-plasma-browser-integration_PATH=	${KDE_PREFIX}/bin/plasma-browser-integration-host

kde-plasma-desktop_PORT=	x11/plasma${_KDE_VERSION}-plasma-desktop
kde-plasma-desktop_PATH=	${KDE_PREFIX}/bin/kaccess

kde-plasma-disks_PORT=		sysutils/plasma${_KDE_VERSION}-plasma-disks
kde-plasma-disks_PATH=		${KDE_PREFIX}/lib/libexec/kf6/kauth/kded-smart-helper

kde-plasma-integration_PORT=	x11/plasma${_KDE_VERSION}-plasma-integration
kde-plasma-integration_PATH=	${QT_PLUGINDIR}/platformthemes/KDEPlasmaPlatformTheme6.so

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

kde-print-manager_PORT=		print/plasma${_KDE_VERSION}-print-manager
kde-print-manager_PATH=		${KDE_PREFIX}/bin/kde-print-queue
kde-print-manager_TYPE=		run

kde-spectacle_PORT=		graphics/plasma${_KDE_VERSION}-spectacle
kde-spectacle_PATH=		${KDE_PREFIX}/bin/spectacle
kde-spectacle_TYPE=		run

kde-systemmonitor_PORT=		sysutils/plasma${_KDE_VERSION}-plasma-systemmonitor
kde-systemmonitor_PATH=		${KDE_PREFIX}/bin/plasma-systemmonitor
kde-systemmonitor_TYPE=		run

kde-systemsettings_PORT=	sysutils/plasma${_KDE_VERSION}-systemsettings
kde-systemsettings_PATH=	${KDE_PREFIX}/bin/systemsettings

kde-xdg-desktop-portal-kde_PORT=	deskutils/plasma${_KDE_VERSION}-xdg-desktop-portal-kde
kde-xdg-desktop-portal-kde_PATH=	${KDE_PREFIX}/lib/libexec/xdg-desktop-portal-kde

kde-plasma5support_PORT=	devel/plasma${_KDE_VERSION}-plasma5support
kde-plasma5support_LIB=		libPlasma5Support.so

kde-qqc2-breeze-style_PORT=	x11-themes/plasma${_KDE_VERSION}-qqc2-breeze-style
kde-qqc2-breeze-style_PATH=	${QT_PLUGINDIR}/kf${_KDE_VERSION}/kirigami/platform/org.kde.breeze.so

kde-sddm-kcm_PORT=		deskutils/plasma${_KDE_VERSION}-sddm-kcm
kde-sddm-kcm_PATH=		${QT_PLUGINDIR}/plasma/kcms/systemsettings/kcm_sddm.so
kde-sddm-kcm_TYPE=		run

kde-kirigami-addons_PORT=	x11-toolkits/kirigami-addons-qt${_KDE_VERSION}
kde-kirigami-addons_PATH=	${QT_QMLDIR}/org/kde/kirigamiaddons/components/libcomponentsplugin.so

kde-globalacceld_PORT=		x11/plasma${_KDE_VERSION}-kglobalacceld
kde-globalacceld_PATH=		${QT_PLUGINDIR}/org.kde.kglobalacceld.platforms/KGlobalAccelDXcb.so

kde-libplasma_PORT=		x11/plasma${_KDE_VERSION}-libplasma
kde-libplasma_LIB=		libPlasma.so
# ====================== end of plasma components ==============================

# ====================== pim5 components =======================================
kde-akonadicontacts_PORT=	net/akonadi-contacts
kde-akonadicontacts_LIB=	libKPim${_KDE_VERSION}AkonadiContactCore.so

kde-akonadiimportwizard_PORT=	deskutils/akonadi-import-wizard
kde-akonadiimportwizard_LIB=	libKPim${_KDE_VERSION}ImportWizard.so

kde-akonadimime_PORT=		net/akonadi-mime
kde-akonadimime_LIB=		libKPim${_KDE_VERSION}AkonadiMime.so

kde-akonadicalendar_PORT=	net/akonadi-calendar
kde-akonadicalendar_LIB=	libKPim${_KDE_VERSION}AkonadiCalendar.so

kde-akonadisearch_PORT=		net/akonadi-search
kde-akonadisearch_LIB=		libKPim${_KDE_VERSION}AkonadiSearchCore.so

kde-calendarsupport_PORT=	net/calendarsupport
kde-calendarsupport_LIB=	libKPim${_KDE_VERSION}CalendarSupport.so

kde-calendarutils_PORT=		net/kcalutils
kde-calendarutils_LIB=		libKPim${_KDE_VERSION}CalendarUtils.so

kde-eventviews_PORT=		net/eventviews
kde-eventviews_LIB=		libKPim${_KDE_VERSION}EventViews.so

kde-gapi_PORT=			net/libkgapi
kde-gapi_LIB=			libKPim${_KDE_VERSION}GAPIBlogger.so

kde-grantleetheme_PORT=		deskutils/grantleetheme
kde-grantleetheme_LIB=		libKPim${_KDE_VERSION}GrantleeTheme.so

kde-gravatar_PORT=		net/libgravatar
kde-gravatar_LIB=		libKPim${_KDE_VERSION}Gravatar.so

kde-identitymanagement_PORT=	net/kidentitymanagement
kde-identitymanagement_LIB=	libKPim${_KDE_VERSION}IdentityManagementCore.so

kde-imap_PORT=			net/kimap
kde-imap_LIB=			libKPim${_KDE_VERSION}IMAP.so

kde-incidenceeditor_PORT=	net/incidenceeditor
kde-incidenceeditor_LIB=	libKPim${_KDE_VERSION}IncidenceEditor.so

kde-kdepim-addons_PORT=	deskutils/kdepim-addons
kde-kdepim-addons_PATH=	${QT_PLUGINDIR}/pim${_KDE_VERSION}/contacteditor/editorpageplugins/cryptopageplugin.so

kde-kdepim-runtime_PORT=	deskutils/kdepim-runtime
kde-kdepim-runtime_PATH=	${KDE_PREFIX}/bin/gidmigrator

kde-kitinerary_PORT=		net/kitinerary
kde-kitinerary_LIB=		libKPim${_KDE_VERSION}Itinerary.so

kde-kontactinterface_PORT=	net/kontactinterface
kde-kontactinterface_LIB=	libKPim${_KDE_VERSION}KontactInterface.so

kde-kpkpass_PORT=		security/kpkpass
kde-kpkpass_LIB=		libKPim${_KDE_VERSION}PkPass.so

kde-ksmtp_PORT=			net/ksmtp
kde-ksmtp_LIB=			libKPim${_KDE_VERSION}SMTP.so

kde-ldap_PORT=			net/kldap
kde-ldap_LIB=			libKPim${_KDE_VERSION}LdapCore.so

kde-libkdepim_PORT=		deskutils/libkdepim
kde-libkdepim_LIB=		libKPim${_KDE_VERSION}Libkdepim.so

kde-libkleo_PORT=		security/libkleo
kde-libkleo_LIB=		libKPim${_KDE_VERSION}Libkleo.so

kde-libksieve_PORT=		net/libksieve
kde-libksieve_LIB=		libKPim${_KDE_VERSION}KSieve.so

kde-mailcommon_PORT=		net/mailcommon
kde-mailcommon_LIB=		libKPim${_KDE_VERSION}MailCommon.so

kde-mailimporter_PORT=		net/mailimporter
kde-mailimporter_LIB=		libKPim${_KDE_VERSION}MailImporter.so

kde-mailtransport_PORT=		net/kmailtransport
kde-mailtransport_LIB=		libKPim${_KDE_VERSION}MailTransport.so

kde-mbox_PORT=			net/kmbox
kde-mbox_LIB=			libKPim${_KDE_VERSION}Mbox.so

kde-messagelib_PORT=		net/messagelib
kde-messagelib_LIB=		libKPim${_KDE_VERSION}MessageList.so

kde-mime_PORT=			net/kmime
kde-mime_LIB=			libKPim${_KDE_VERSION}Mime.so

kde-pimcommon_PORT=		net/pimcommon
kde-pimcommon_LIB=		libKPim${_KDE_VERSION}PimCommon.so

kde-pimtextedit_PORT=		net/kpimtextedit
kde-pimtextedit_LIB=		libKPim${_KDE_VERSION}TextEdit.so

kde-tnef_PORT=			net/ktnef
kde-tnef_LIB=			libKPim${_KDE_VERSION}Tnef.so

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

kde-kontact_PORT=		deskutils/kontact
kde-kontact_PATH=		${KDE_PREFIX}/bin/kontact

kde-korganizer_PORT=		deskutils/korganizer
kde-korganizer_PATH=		${KDE_PREFIX}/bin/korganizer

kde-mbox-importer_PORT=		deskutils/mbox-importer
kde-mbox-importer_PATH=		${KDE_PREFIX}/bin/mboximporter

kde-mimetreeparser_PORT=	net/mimetreeparser
kde-mimetreeparser_LIB=		libKPim${_KDE_VERSION}MimeTreeParserCore.so

kde-pim-data-exporter_PORT=	deskutils/pim-data-exporter
kde-pim-data-exporter_PATH=	${KDE_PREFIX}/bin/pimdataexporter
# ====================== end of pim5 components ================================

# ====================== multiversion component ================================
kde-akonadi_PORT=		databases/akonadi
kde-akonadi_LIB=		libKPim${_KDE_VERSION}AkonadiPrivate.so

kde-baloo-widgets_PORT=		sysutils/baloo-widgets
kde-baloo-widgets_LIB=		libKF${_KDE_VERSION}BalooWidgets.so

kde-kate_PORT=			editors/kate
kde-kate_PATH=			${QT_PLUGINDIR}/ktexteditor/katebacktracebrowserplugin.so

kde-libkcddb_PORT=		audio/libkcddb
kde-libkcddb_LIB=		libKCddb${_KDE_VERSION}.so

kde-libkcompactdisc_PORT=	audio/libkcompactdisc
kde-libkcompactdisc_LIB=	libKF${_KDE_VERSION}CompactDisc.so

kde-libkdcraw_PORT=		graphics/libkdcraw@qt${_KDE_VERSION}
kde-libkdcraw_LIB5=		libKF${_KDE_VERSION}KDcraw.so
kde-libkdcraw_LIB6=		libKDcrawQt${_KDE_VERSION}.so
kde-libkdcraw_LIB=		${kde-libkdcraw_LIB${_KDE_VERSION}}

kde-libkdegames_PORT=		games/libkdegames
kde-libkdegames_LIB=		libKDEGames${_KDE_VERSION}.so

kde-libkeduvocdocument_PORT=	misc/libkeduvocdocument
kde-libkeduvocdocument_LIB=	libKEduVocDocument.so

kde-libkexiv2_PORT=		graphics/libkexiv2@qt${_KDE_VERSION}
kde-libkexiv2_LIB5=		libKF${_KDE_VERSION}KExiv2.so
kde-libkexiv2_LIB6=		libKExiv2Qt${_KDE_VERSION}.so
kde-libkexiv2_LIB=		${kde-libkexiv2_LIB${_KDE_VERSION}}

kde-libksane_PORT=		graphics/libksane
kde-libksane_LIB=		libKSaneWidgets${_KDE_VERSION}.so

kde-marble_PORT=		astro/marble
kde-marble_LIB=			libmarblewidget-qt6.so

kde-kpublictransport_PORT=	devel/kpublictransport
kde-kpublictransport_LIB=	libKPublicTransport.so

kde-kosm_PORT=			astro/kosmindoormap
kde-kosm_LIB=			libKOSM.so

kde-okular_PORT=		graphics/okular
kde-okular_LIB=			libOkular${_KDE_VERSION}Core.so

kde-phonon_PORT=		multimedia/phonon@${_QT_RELNAME}
kde-phonon_LIB=			libphonon4${_QT_RELNAME}.so

kde-phonon-mpv_PORT=	multimedia/phonon-mpv
kde-phonon-mpv_PATH=	${QT_PLUGINDIR}/phonon4${_QT_RELNAME}_backend/phonon_mpv_${_QT_RELNAME}.so
kde-phonon-mpv_TYPE=	run

kde-phonon-vlc_PORT=	multimedia/phonon-vlc@${_QT_RELNAME}
kde-phonon-vlc_PATH=	${QT_PLUGINDIR}/phonon4${_QT_RELNAME}_backend/phonon_vlc_${_QT_RELNAME}.so
kde-phonon-vlc_TYPE=	run

# ====================== end of multiversion components ========================

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
