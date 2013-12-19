# Created by: Romain Tartière <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	padevchooser
PORTVERSION=	0.9.3
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/${PORTNAME}/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	GTK icon tray for PulseAudio

LIB_DEPENDS=	libglademm-2.4.so:${PORTSDIR}/devel/libglademm24 \
		libpulse.so:${PORTSDIR}/audio/pulseaudio \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libavahi-core.so:${PORTSDIR}/net/avahi
RUN_DEPENDES=	dbus-daemon:${PORTSDIR}/devel/dbus

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
NO_STAGE=	yes

CONFIGURE_ARGS=	--disable-lynx

.include <bsd.port.mk>
