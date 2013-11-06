# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quassel
PORTVERSION=	0.9.1
CATEGORIES=	irc
MASTER_SITES=	http://www.quassel-irc.org/pub/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt 4 based distributed IRC client

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo

USE_BZIP2=	yes
USES=		cmake:outsource
USE_QT4=	corelib network script sql \
		qmake_build moc_build rcc_build uic_build

OPTIONS_DEFINE=	KDE NLS
OPTIONS_MULTI=	MODULE
OPTIONS_MULTI_MODULE=	MONO CORE CLIENT
OPTIONS_DEFAULT=	${OPTIONS_MULTI_MODULE}

MONO_DESC=	Quassel standalone client
CORE_DESC=	Quassel core (for use with client)
CLIENT_DESC=	Quassel client (for use with core)
KDE_DESC=	KDE 4 integration (for clients only)

CMAKE_ARGS+=	-DWANT_MONO=${QUASSEL_MONO} \
		-DWANT_CORE=${QUASSEL_CORE} \
		-DWANT_QTCLIENT=${QUASSEL_CLIENT} \
		-DWITH_LIBINDICATE=OFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_QT4+=	linguist_build
.endif

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

.if ${PORT_OPTIONS:MMONO}
QUASSEL_MONO=	ON
PLIST_SUB+=	MONO=""
.else
QUASSEL_MONO=	OFF
PLIST_SUB+=	MONO="@comment "
.endif

.if ${PORT_OPTIONS:MCORE}
LIB_DEPENDS+=	libqca.so:${PORTSDIR}/devel/qca
USE_QT4+=	sql-sqlite3_run
QUASSEL_CORE=	ON
PLIST_SUB+=	CORE=""

USE_RC_SUBR=	quasselcore
USERS=		quasselcore
GROUPS=		${USERS}
SUB_FILES=	pkg-message
.else
QUASSEL_CORE=	OFF
PLIST_SUB+=	CORE="@comment "
.endif

.if ${PORT_OPTIONS:MCLIENT}
QUASSEL_CLIENT=	ON
PLIST_SUB+=	CLIENT=""
.else
QUASSEL_CLIENT=	OFF
PLIST_SUB+=	CLIENT="@comment "
.endif

pre-configure:
.if !${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e '/add_subdirectory(i18n)/d' \
		${WRKSRC}/CMakeLists.txt
.endif
	${REINPLACE_CMD} -e 's,knotifyconfig,$${KDE4_KNOTIFYCONFIG_LIBRARY},' \
		${WRKSRC}/CMakeLists.txt

.if ${PORT_OPTIONS:MKDE}
pre-su-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rc.d
.endif

.include <bsd.port.mk>
