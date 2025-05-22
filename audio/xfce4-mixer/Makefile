PORTNAME=	xfce4-mixer
PORTVERSION=	4.20.0
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Volume control for the Xfce desktop
WWW=		https://docs.xfce.org/apps/xfce4-mixer/start

LICENSE=	GPLv2

FLAVORS=	lite full
FLAVOR?=	${FLAVORS:[1]}

full_PKGNAMESUFFIX=	-full
full_CONFLICTS_INSTALL=	xfce4-mixer

lite_CONFLICTS_INSTALL=	xfce4-mixer-full

USES=		compiler:c11 gettext-tools gnome gstreamer meson pkgconfig \
		tar:xz xfce xorg
USE_GNOME=	glib20 gtk30
USE_GSTREAMER=	good
USE_XFCE=	libmenu panel xfconf
USE_XORG=	x11

OPTIONS_DEFINE=		KEYBINDER NLS
OPTIONS_DEFAULT=	OSS
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA OSS PULSEAUDIO SNDIO
OPTIONS_SUB=		yes

.if ${FLAVOR} == full
OPTIONS_DEFAULT+=	ALSA KEYBINDER PULSEAUDIO SNDIO
.endif

KEYBINDER_DESC=	Multimedia keyboard shortcuts

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_MESON_ENABLED=	alsa

KEYBINDER_LIB_DEPENDS=		libkeybinder-3.0.so:x11/keybinder-gtk3
KEYBINDER_MESON_ENABLED=	keybinder

NLS_USES=	gettext-runtime

OSS_MESON_ENABLED=	oss

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_MESON_ENABLED=	pulse

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_MESON_ENABLED=	sndio

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
