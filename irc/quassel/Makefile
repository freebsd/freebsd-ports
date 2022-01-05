# Created by: Martin Wilke <miwi@FreeBSD.org>

PORTNAME=	quassel
DISTVERSION=	0.14.0
CATEGORIES=	irc
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${DISTVERSION}/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT?=	Qt 5 based distributed IRC client (client and monolithic binary)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/optional.hpp:devel/boost-libs

USES=		cmake compiler:c++11-lib cpe pkgconfig qca qt:5 tar:xz
USE_GITHUB=	nodefault
#GH_ACCOUNT=	${PORTNAME}
#GH_PROJECT=	${PORTNAME}
USE_OPENLDAP=	yes
USE_QT=		buildtools_build core network qmake_build

CPE_VENDOR=	quassel-irc
CPE_PRODUCT=	quassel_irc

OPTIONS_DEFINE=		NLS
OPTIONS_MULTI=		MODULE DB
OPTIONS_GROUP=		UI
MODULE_DESC=		Quassel components
UI_DESC=		Spellcheck and KDE integration for GUI app
DB_DESC=		Database for Quassel core / monolithic
OPTIONS_MULTI_MODULE=	CLIENT CORE MONO
OPTIONS_MULTI_DB=	PGSQL SQLITE3
OPTIONS_GROUP_UI=	KDE SPELL
OPTIONS_DEFAULT=	CLIENT MONO SQLITE3
OPTIONS_SUB=		yes

CLIENT_DESC=		Quassel client (for use with core)
CLIENT_CMAKE_BOOL=	WANT_QTCLIENT
CLIENT_USE=		qt=dbus,gui,multimedia,phonon4,webkit,widgets
CLIENT_LIB_DEPENDS=	libdbusmenu-qt5.so:devel/libdbusmenu-qt
CLIENT_PREVENTS=	CORE
CLIENT_PREVENTS_MSG=	Quassel core server should be installed via irc/quassel-core port

CORE_DESC=		Quassel core server (for use with client)
CORE_CMAKE_BOOL=	WANT_CORE
CORE_USE=		qt=script,sql
CORE_SUB_FILES=		pkg-message
CORE_VARS=		use_rc_subr=quasselcore \
			users=quasselcore \
			groups=quasselcore \
			plist=${NONEXISTENT} # allow core to override PLIST_FILES
CORE_PLIST_FILES=	bin/quasselcore
CORE_PREVENTS=		CLIENT MONO KDE SPELL

MONO_DESC=		Quassel standalone (monolithic binary: core+client combined)
MONO_CMAKE_BOOL=	WANT_MONO
MONO_USE=		qt=dbus,gui,multimedia,phonon4,script,sql,webkit,widgets
MONO_LIB_DEPENDS=	libdbusmenu-qt5.so:devel/libdbusmenu-qt
MONO_PREVENTS=		CORE
MONO_PREVENTS_MSG=	Quassel core server should be installed via irc/quassel-core port

KDE_DESC=		Enable KDE integration for client / monolitic
KDE_CMAKE_BOOL=		WITH_KDE
KDE_USE=		kde=configwidgets,coreaddons,notifications,notifyconfig,textwidgets,widgetsaddons,xmlgui,ecm_build
KDE_USES=		kde:5

SPELL_DESC=		Enable spellcheck in client / monolitic via KF5Sonnet
SPELL_USE=		kde=sonnet,ecm_build
SPELL_USES=		kde:5

NLS_USE=		QT=linguisttools_build

PGSQL_USE=		qt=sql-pgsql

SQLITE3_USE=		qt=sql-sqlite3_run

_LIBVERSION=		0.14.0
PLIST_SUB=		LIBVERSION=${_LIBVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT} || ${PORT_OPTIONS:MMONO}
PLIST_SUB+=	GUI=""
.else
PLIST_SUB+=	GUI="@comment "
.endif

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
