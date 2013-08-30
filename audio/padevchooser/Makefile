# Created by: Romain Tartière <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	padevchooser
PORTVERSION=	0.9.3
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/${PORTNAME}/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	GTK icon tray for PulseAudio

LIB_DEPENDS=	glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		pulse.0:${PORTSDIR}/audio/pulseaudio \
		notify.4:${PORTSDIR}/devel/libnotify \
		avahi-core:${PORTSDIR}/net/avahi
RUN_DEPENDES=	dbus-daemon:${PORTSDIR}/devel/dbus

GNU_CONFIGURE=	yes
USES=		gmake

CONFIGURE_ARGS=	--disable-lynx

.include <bsd.port.mk>
