# $FreeBSD$

PORTNAME=	dxirc
PORTVERSION=	1.30.0
CATEGORIES=	irc ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	arch_dvx@users.sourceforge.net
COMMENT=	Simple IRC client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_XORG=	ice sm x11 xext
USES=		cmake pkgconfig
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		NLS LUA ENCHANT NOTIFY
OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	FOX16 QT4 QT5
OPTIONS_DEFAULT=	LUA QT5
OPTIONS_SUB=		yes

ENCHANT_DESC=		Spell checking support via Enchant
ENCHANT_LIB_DEPENDS=	libenchant.so:textproc/enchant
ENCHANT_CMAKE_ON=	-DHAVE_ENCHANT:BOOL=ON
ENCHANT_CMAKE_OFF=	-DHAVE_ENCHANT:BOOL=OFF

FOX16_DESC=		FOX 1.6 toolkit support
FOX16_LIB_DEPENDS=	libFOX-1.6.so:x11-toolkits/fox16
FOX16_USES=		ssl
FOX16_CMAKE_ON=		-DFOX_ENABLE_IPV6:BOOL=ON

LUA_USES=		lua
LUA_CMAKE_ON=		-DWITH_LUA:BOOL=ON
LUA_CMAKE_OFF=		-DWITH_LUA:BOOL=OFF

NLS_USES=		gettext
NLS_CMAKE_ON=		-DWITH_NLS:BOOL=ON
NLS_CMAKE_OFF=		-DWITH_NLS:BOOL=OFF

NOTIFY_RUN_DEPENDS=	notify-send:devel/libnotify

QT4_USE=		QT4=corelib,gui,network \
			QT4=moc_build,rcc_build,uic_build,qmake_build
QT4_CMAKE_ON=		-DQT5:BOOL=OFF

QT5_USE=		QT5=core,gui,multimedia,network,widgets \
			QT5=buildtools_build,qmake_build
QT5_CMAKE_ON=		-DQT5:BOOL=ON

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFOX16}
CMAKE_ARGS+=	-DBUILD_FOX:BOOL=ON -DBUILD_QT:BOOL=OFF
PLIST_SUB+=	FOX="" QT="@comment "
.else
CMAKE_ARGS+=	-DBUILD_FOX:BOOL=OFF -DBUILD_QT:BOOL=ON
PLIST_SUB+=	FOX="@comment " QT=""
.endif

.include <bsd.port.mk>
