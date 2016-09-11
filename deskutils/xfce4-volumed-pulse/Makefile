# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	xfce4-volumed-pulse
PORTVERSION=	0.2.1
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Volume management daemon for Xfce using PulseAudio

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpulse.so:audio/pulseaudio \
	libnotify.so:devel/libnotify \
	libkeybinder.so:x11/keybinder

USES=	gmake libtool pkgconfig tar:bz2 xfce
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk20
USE_XFCE=	xfconf
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=--enable-libnotify

.include <bsd.port.mk>
