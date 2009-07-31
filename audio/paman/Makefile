# Ports collection Makefile for: paman
# Date created:		2008-01-15
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	paman
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/${PORTNAME}/

MAINTAINER=	romain@blogreen.org
COMMENT=	Gtk frontend for PulseAudio

LIB_DEPENDS=	glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		pulse.0:${PORTSDIR}/audio/pulseaudio

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack

CONFIGURE_ARGS=	--disable-lynx

.include <bsd.port.mk>
