# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quassel
PORTVERSION=	0.11.0
CATEGORIES=	irc
MASTER_SITES=	http://www.quassel-irc.org/pub/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt 4 based distributed IRC client

USES=		cmake:outsource compiler:c++11-lib execinfo tar:bzip2
USE_QT4=	corelib network script sql \
		qmake_build moc_build rcc_build uic_build
CMAKE_ARGS=	-DWITH_LIBINDICATE=off \
		-DEMBED_DATA=on

OPTIONS_DEFINE=	KDE NLS
OPTIONS_MULTI=	MODULE
MODULE_DESC=	Quassel components
OPTIONS_MULTI_MODULE=	MONO CORE CLIENT
OPTIONS_DEFAULT=	${OPTIONS_MULTI_MODULE}
OPTIONS_SUB=	yes

MONO_DESC=	Quassel standalone client
MONO_CMAKE_ON=	-DWANT_MONO=on
MONO_CMAKE_OFF=	-DWANT_MONO=off

CORE_DESC=	Quassel core (for use with client)
CORE_LIB_DEPENDS=	libqca.so:${PORTSDIR}/devel/qca
CORE_USE=	QT4=sql-sqlite3_run
CORE_CMAKE_ON=	-DWANT_CORE=on
CORE_CMAKE_OFF=	-DWANT_CORE=off

CLIENT_DESC=	Quassel client (for use with core)
CLIENT_CMAKE_ON=	-DWANT_QTCLIENT=on
CLIENT_CMAKE_OFF=	-DWANT_QTCLIENT=off

KDE_DESC=	KDE 4 integration (for clients only)

NLS_USE=	QT4=linguist_build

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMONO} || ${PORT_OPTIONS:MCLIENT}
. if ${PORT_OPTIONS:MKDE}
USE_KDE4=	automoc4 kdelibs kdeprefix
CMAKE_ARGS+=	-DWITH_KDE=ON
PLIST=		${PKGDIR}/pkg-plist.kde
. else
CMAKE_ARGS+=	-DWITH_KDE=OFF
. endif
USE_QT4+=	dbus gui phonon webkit xml xmlpatterns
LIB_DEPENDS+=	libdbusmenu-qt.so:${PORTSDIR}/devel/libdbusmenu-qt
PLIST_SUB+=	MONO_OR_CLIENT=""
.else
PLIST_SUB+=	MONO_OR_CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MCORE}
USE_RC_SUBR=	quasselcore
USERS=		quasselcore
GROUPS=		${USERS}
SUB_FILES=	pkg-message
.endif

pre-configure:
.if !${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e '/add_subdirectory(po)/d' \
		${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
