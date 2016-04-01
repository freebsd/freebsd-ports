# Created by: Romain Tartière <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	pavumeter
PORTVERSION=	0.9.3
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/${PORTNAME}/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	GTK volume meter for PulseAudio

BUILD_DEPENDS=	pulseaudio>=0.9.7:audio/pulseaudio
RUN_DEPENDS=	pulseaudio>=0.9.7:audio/pulseaudio
LIB_DEPENDS=	libglademm-2.4.so:devel/libglademm24 \
		libpulse.so:audio/pulseaudio

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig

CONFIGURE_ARGS=	--disable-lynx

.include <bsd.port.mk>
