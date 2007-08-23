# Ports collection Makefile for: pavumeter
# Date created:		July 21, 2007
# Whom:			Romain Tartière <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	pavumeter
PORTVERSION=	0.9.2
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/${PORTNAME}/

MAINTAINER=	romain@blogreen.org
COMMENT=	GTK volume meter for PulseAudio

LIB_DEPENDS=	glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		pulse-mainloop-glib.0:${PORTSDIR}/audio/pulseaudio

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--disable-lynx

.include <bsd.port.mk>
