# $FreeBSD$

PORTNAME=	dxirc
PORTVERSION=	1.30.0
CATEGORIES=	irc ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	arch_dvx@users.sourceforge.net
COMMENT=	Simple IRC client

LICENSE=	GPLv3+
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
ENCHANT_CMAKE_BOOL=	HAVE_ENCHANT

FOX16_DESC=		FOX 1.6 toolkit support
FOX16_LIB_DEPENDS=	libFOX-1.6.so:x11-toolkits/fox16
FOX16_USES=		ssl
FOX16_CMAKE_ON=		-DFOX_ENABLE_IPV6:BOOL=ON \
			-DBUILD_FOX:BOOL=ON -DBUILD_QT:BOOL=OFF
FOX16_CMAKE_OFF=	-DBUILD_FOX:BOOL=OFF -DBUILD_QT:BOOL=ON

LUA_USES=		lua
LUA_CMAKE_BOOL=		WITH_LUA

NLS_USES=		gettext
NLS_CMAKE_BOOL=		WITH_NLS

NOTIFY_RUN_DEPENDS=	notify-send:devel/libnotify

QT4_USE=		QT4=corelib,gui,network \
			QT4=moc_build,rcc_build,uic_build,qmake_build
QT4_CMAKE_ON=		-DQT5:BOOL=OFF

QT5_USE=		QT5=core,gui,multimedia,network,widgets \
			QT5=buildtools_build,qmake_build
QT5_CMAKE_ON=		-DQT5:BOOL=ON

.include <bsd.port.mk>
