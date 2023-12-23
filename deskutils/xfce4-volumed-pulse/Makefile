PORTNAME=	xfce4-volumed-pulse
PORTVERSION=	0.2.4
PORTREVISION=	3
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Volume management daemon for Xfce using PulseAudio
WWW=		https://git.xfce.org/apps/xfce4-volumed-pulse/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libkeybinder-3.0.so:x11/keybinder-gtk3 \
		libnotify.so:devel/libnotify \
		libpulse.so:audio/pulseaudio

USES=		gmake gnome libtool pkgconfig tar:bz2 xfce
USE_GNOME=	glib20 gtk30
USE_XFCE=	xfconf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-libnotify
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/xfce4-volumed-pulse \
		etc/xdg/autostart/xfce4-volumed-pulse.desktop

.include <bsd.port.mk>
