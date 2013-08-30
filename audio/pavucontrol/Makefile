# Created by: Romain Tartière <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	pavucontrol
PORTVERSION=	0.9.10
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/${PORTNAME}/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	GTK mixer for PulseAudio

LIB_DEPENDS=	glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		pulse.0:${PORTSDIR}/audio/pulseaudio \
		canberra:${PORTSDIR}/audio/libcanberra

GNU_CONFIGURE=	yes
USES=		gmake
USE_GNOME=	intltool

CONFIGURE_ARGS=	--disable-lynx

.include <bsd.port.mk>
