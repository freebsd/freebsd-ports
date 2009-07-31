# Ports collection Makefile for: pavumeter
# Date created:		July 21, 2007
# Whom:			Romain Tartière <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	pavucontrol
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/${PORTNAME}/

MAINTAINER=	romain@blogreen.org
COMMENT=	GTK mixer for PulseAudio

LIB_DEPENDS=	glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		pulse.0:${PORTSDIR}/audio/pulseaudio \
		canberra-gtk.0:${PORTSDIR}/audio/libcanberra

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	intltool

CONFIGURE_ARGS=	--disable-lynx

.include <bsd.port.mk>
