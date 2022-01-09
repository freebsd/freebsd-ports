# Created by: trasz <trasz@pin.if.uz.zgora.pl>

PORTNAME=	qjackctl
DISTVERSIONPREFIX=	qjackctl_
DISTVERSION=	0_9_6
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt interface for JACK Audio Connection Kit

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjack.so:audio/jack

USES=		cmake compiler:c++11-lib gl localbase:ldflags pkgconfig qt:5
USE_QT=		core gui network widgets x11extras xml buildtools_build linguisttools_build qmake_build
USE_GL=		gl
USE_CXXSTD=	c++11

USE_GITHUB=	yes
GH_ACCOUNT=	rncbc

OPTIONS_DEFINE=		DBUS SYSTRAY XUNIQUE
OPTIONS_DEFAULT=	DBUS SYSTRAY XUNIQUE
OPTIONS_GROUP=		AIFACE
OPTIONS_GROUP_AIFACE=	ALSA PORTAUDIO

AIFACE_DESC=		Other audio interfaces
SYSTRAY_DESC=		System tray icon support
XUNIQUE_DESC=		X11 unique/single instance

ALSA_CMAKE_BOOL=	CONFIG_ALSA_SEQ
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

DBUS_CMAKE_BOOL=	CONFIG_DBUS
DBUS_USE=		QT=dbus

PORTAUDIO_CMAKE_BOOL=	CONFIG_PORTAUDIO
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio

SYSTRAY_CMAKE_BOOL=	CONFIG_SYSTEM_TRAY

XUNIQUE_CMAKE_BOOL=	CONFIG_XUNIQUE
XUNIQUE_USES=		xorg
XUNIQUE_USE=		XORG=x11

.include <bsd.port.mk>
