# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quassel
PORTVERSION=	0.12.3
CATEGORIES=	irc
MASTER_SITES=	http://www.quassel-irc.org/pub/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt 5 based distributed IRC client

USES=		cmake:outsource compiler:c++11-lib cpe execinfo pkgconfig tar:bzip2
USE_QT5=	core network buildtools_build qmake_build
CMAKE_ARGS=	-DWITH_KDE=off \
		-DUSE_QT5=on

CPE_VENDOR=	quassel-irc
CPE_PRODUCT=	quassel_irc

OPTIONS_DEFINE=	NLS
OPTIONS_MULTI=	MODULE
MODULE_DESC=	Quassel components
OPTIONS_MULTI_MODULE=	MONO CORE CLIENT
OPTIONS_DEFAULT=	${OPTIONS_MULTI_MODULE}
OPTIONS_SUB=	yes

MONO_DESC=	Quassel standalone client
MONO_CMAKE_ON=	-DWANT_MONO=on
MONO_CMAKE_OFF=	-DWANT_MONO=off

CORE_DESC=	Quassel core (for use with client)
CORE_LIB_DEPENDS=	libqca-qt5.so:devel/qca-qt5
CORE_USE=	QT5=script,sql,sql-sqlite3_run
CORE_CMAKE_ON=	-DWANT_CORE=on
CORE_CMAKE_OFF=	-DWANT_CORE=off

CLIENT_DESC=	Quassel client (for use with core)
CLIENT_CMAKE_ON=	-DWANT_QTCLIENT=on
CLIENT_CMAKE_OFF=	-DWANT_QTCLIENT=off

NLS_USE=	QT5=linguisttools_build

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMONO} || ${PORT_OPTIONS:MCLIENT}
USE_QT5+=	dbus gui widgets phonon4 webkit
LIB_DEPENDS+=	libdbusmenu-qt5.so:devel/libdbusmenu-qt5
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

post-patch-NLS-off:
	${REINPLACE_CMD} -e '/add_subdirectory(po)/d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
