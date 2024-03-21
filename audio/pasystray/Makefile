PORTNAME=	pasystray
PORTVERSION=	0.8.2
CATEGORIES=	audio

MAINTAINER=	julien+freebsdports@delhaye.me
COMMENT=	System tray applet to control PulseAudio
WWW=		https://github.com/christophgysin/pasystray

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpulse.so:audio/pulseaudio

USES=		autoreconf gnome pkgconfig
USE_GNOME=	cairo gdkpixbuf2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_GITHUB=	yes
GH_ACCOUNT=	christophgysin

OPTIONS_DEFINE=	APPINDICATOR AVAHI GTK2 NOTIFY
OPTIONS_DEFAULT=	APPINDICATOR AVAHI NOTIFY

APPINDICATOR_DESC=	AppIndicator support
APPINDICATOR_LIB_DEPENDS=	libappindicator3.so:devel/libappindicator
APPINDICATOR_CONFIGURE_OFF=	--disable-appindicator

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_CONFIGURE_OFF=	--disable-avahi

GTK2_DESC=		Use GTK 2 instead of GTK 3
GTK2_CONFIGURE_ON=	--with-gtk=2
GTK2_USE=		GNOME=gtk20
GTK2_USE_OFF=		GNOME=gtk30
GTK2_PLIST_FILES=	${DATADIR_REL}/${PORTNAME}.gtk2.glade
GTK2_PLIST_FILES_OFF=	${DATADIR_REL}/${PORTNAME}.gtk3.glade
GTK2_PREVENTS=		APPINDICATOR

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_OFF=	--disable-notify

.include <bsd.port.mk>
