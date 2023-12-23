PORTNAME=	xfce4-mixer
PORTVERSION=	4.18.1
PORTREVISION=	3
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Volume control for the Xfce desktop
WWW=		https://docs.xfce.org/apps/xfce4-mixer/start

LICENSE=	GPLv2

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

FLAVORS=	lite full
FLAVOR?=	${FLAVORS:[1]}

lite_CONFLICTS_INSTALL=		xfce4-mixer-full

full_PKGNAMESUFFIX=		-full
full_CONFLICTS_INSTALL=		xfce4-mixer

USES=		compiler:c11 gettext-tools gmake gnome gstreamer libtool \
		pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_GSTREAMER=	good
USE_XFCE=	libmenu panel xfconf
USE_XORG=	x11

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		KEYBINDER NLS
OPTIONS_DEFAULT=	OSS
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA OSS PULSEAUDIO SNDIO
OPTIONS_SUB=		yes

.if ${FLAVOR} == full
OPTIONS_DEFAULT+=	ALSA KEYBINDER PULSEAUDIO SNDIO
.endif

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa

KEYBINDER_DESC=			Multimedia keyboard shortcuts
KEYBINDER_LIB_DEPENDS=		libkeybinder-3.0.so:x11/keybinder-gtk3
KEYBINDER_CONFIGURE_ENABLE=	keybinder

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

OSS_CONFIGURE_ENABLE=	oss

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_ENABLE=	sndio

.include <bsd.port.mk>
