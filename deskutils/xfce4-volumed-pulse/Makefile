# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	xfce4-volumed-pulse
PORTVERSION=	0.2.3
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Volume management daemon for Xfce using PulseAudio

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpulse.so:audio/pulseaudio \
		libnotify.so:devel/libnotify \
		libkeybinder-3.0.so:x11/keybinder-gtk3

USES=		gmake libtool pkgconfig tar:bz2 xfce:gtk3
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk30
USE_XFCE=	xfconf
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--enable-libnotify

PLIST_FILES=	bin/xfce4-volumed-pulse \
		etc/xdg/autostart/xfce4-volumed-pulse.desktop

.include <bsd.port.mk>
