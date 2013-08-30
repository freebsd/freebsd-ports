# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	paman
PORTVERSION=	0.9.4
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/${PORTNAME}/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Gtk frontend for PulseAudio

LIB_DEPENDS=	glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		pulse.0:${PORTSDIR}/audio/pulseaudio

GNU_CONFIGURE=	yes
USES=		gmake pathfix

CONFIGURE_ARGS=	--disable-lynx

.include <bsd.port.mk>
