# Created by: Romain Tartière <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	padevchooser
PORTVERSION=	0.9.3
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/${PORTNAME}/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	GTK icon tray for PulseAudio

LIB_DEPENDS=	libglademm-2.4.so:${PORTSDIR}/devel/libglademm24 \
		libpulse.so:${PORTSDIR}/audio/pulseaudio \
		libnotify.so:${PORTSDIR}/devel/libnotify
RUN_DEPENDES=	dbus-daemon:${PORTSDIR}/devel/dbus

GNU_CONFIGURE=	yes
LIBS+=		-L${LOCALBASE}/lib -lX11
USES=		gmake pkgconfig
USE_XORG=	x11

CONFIGURE_ARGS=	--disable-lynx

.include <bsd.port.mk>
