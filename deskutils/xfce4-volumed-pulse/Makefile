# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	xfce4-volumed-pulse
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	deskutils xfce
MASTER_SITES=	https://launchpadlibrarian.net/133628016/ \
	https://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Volume management daemon for Xfce using PulseAudio

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpulse.so:audio/pulseaudio \
	libnotify.so:devel/libnotify \
	libkeybinder.so:x11/keybinder

USES=	pkgconfig gmake xfce tar:bz2
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk20
USE_XFCE=	xfconf
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=--enable-libnotify

.include <bsd.port.mk>
