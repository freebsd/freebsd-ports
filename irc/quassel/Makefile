PORTNAME=	quassel
DISTVERSION=	0.14.50
PORTREVISION?=	0
CATEGORIES=	irc
#MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${DISTVERSION}/
DIST_SUBDIR=	${PORTNAME}

PATCH_SITES+=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/pull/
PATCHFILES+=	631.patch:-p1

MAINTAINER=	fluffy@FreeBSD.org
COMMENT?=	Qt 6 based distributed IRC client (client and monolithic binary)
WWW=		https://www.quassel-irc.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/optional.hpp:devel/boost-libs

LIB_DEPENDS=	libqca-qt6.so:devel/qca@qt6

USES=		cmake compiler:c++11-lib cpe ldap pkgconfig qt:6 tar:xz
USE_GITHUB=	yes
GH_TAGNAME=	c63fc1e
# translations comes bundled only with release tarball
GH_TUPLE=	${PORTNAME}:${PORTNAME}-i18n:abed52e:${PORTNAME}_${PORTNAME}_i18n/po

USE_QT=		tools:build 5compat base

CPE_VENDOR=	quassel-irc
CPE_PRODUCT=	quassel_irc

OPTIONS_DEFINE=		NLS
OPTIONS_MULTI=		MODULE DB
OPTIONS_GROUP=		UI
MODULE_DESC=		Quassel components
UI_DESC=		Spellcheck and KDE integration for GUI (client/mono)
DB_DESC=		Database for Quassel core / monolithic
OPTIONS_MULTI_MODULE=	CLIENT CORE MONO
OPTIONS_MULTI_DB=	PGSQL SQLITE3
OPTIONS_GROUP_UI=	KDE SPELL
OPTIONS_DEFAULT=	CLIENT MONO SQLITE3
OPTIONS_SUB=		yes

CLIENT_DESC=		Quassel client (for use with core)
CLIENT_CMAKE_BOOL=	WANT_QTCLIENT
CLIENT_USES=		desktop-file-utils kde:6
CLIENT_USE=		qt=declarative,multimedia,webengine kde=phonon
CLIENT_LIB_DEPENDS=	libdbusmenu-qt6.so:devel/libdbusmenu-qt@qt6
CLIENT_PREVENTS=	CORE
CLIENT_PREVENTS_MSG=	Quassel core server should be installed via irc/quassel-core port

CORE_DESC=		Quassel core server (for use with client)
CORE_CMAKE_BOOL=	WANT_CORE
CORE_CMAKE_BOOL_OFF=	ENABLE_SHARED
CORE_SUB_FILES=		pkg-message
CORE_VARS=		use_rc_subr=quasselcore \
			users=quasselcore \
			groups=quasselcore \
			plist=${NONEXISTENT} # allow core to override PLIST_FILES
CORE_PLIST_FILES=	bin/quasselcore
CORE_PREVENTS=		CLIENT MONO KDE SPELL NLS

MONO_DESC=		Quassel standalone (monolithic binary: core+client combined)
MONO_CMAKE_BOOL=	WANT_MONO
MONO_USES=		desktop-file-utils kde:6
MONO_USE=		qt=declarative,multimedia,webengine kde=phonon
MONO_LIB_DEPENDS=	libdbusmenu-qt6.so:devel/libdbusmenu-qt@qt6
MONO_PREVENTS=		CORE
MONO_PREVENTS_MSG=	Quassel core server should be installed via irc/quassel-core port

KDE_DESC=		Enable KDE integration for client / monolitic
KDE_CMAKE_BOOL=		WITH_KDE
KDE_USE=		kde=configwidgets,coreaddons,notifications,notifyconfig,textwidgets,widgetsaddons,xmlgui,ecm:build
KDE_USES=		kde:6

SPELL_DESC=		Enable spellcheck in client / monolitic via KF6Sonnet
SPELL_USE=		kde=sonnet,ecm:build
SPELL_USES=		kde:6

NLS_USE=		QT=translations:build
NLS_USES=		gettext

PGSQL_USE=		qt=sqldriver-psql:run

SQLITE3_USE=		qt=sqldriver-sqlite:run

PLIST_SUB=		LIBVERSION=${DISTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT} || ${PORT_OPTIONS:MMONO}
PLIST_SUB+=	GUI=""
.else
PLIST_SUB+=	GUI="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's/Qt5/Qt6/g' \
		${WRKSRC}/po/CMakeLists.txt

post-patch-NLS-off:
	${REINPLACE_CMD} -e '/add_subdirectory(po)/d' \
		${WRKSRC}/CMakeLists.txt

post-install-CLIENT-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/quasselclient
post-install-CORE-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/quasselcore
post-install-MONO-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/quassel

.include <bsd.port.mk>
