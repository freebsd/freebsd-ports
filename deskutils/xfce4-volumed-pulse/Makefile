PORTNAME=	xfce4-volumed-pulse
PORTVERSION=	0.3.0
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Volume management daemon for Xfce using PulseAudio
WWW=		https://gitlab.xfce.org/apps/xfce4-volumed-pulse

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libkeybinder-3.0.so:x11/keybinder-gtk3 \
		libnotify.so:devel/libnotify \
		libpulse.so:audio/pulseaudio

USES=		gettext-tools gnome meson pkgconfig tar:xz xfce
USE_GNOME=	glib20 gtk30
USE_XFCE=	xfconf

MESON_ARGS=	-Dlibnotify=enabled

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
