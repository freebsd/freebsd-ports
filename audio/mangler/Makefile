# Created by: Janik Galasso <janik@hikarihq.com>
# $FreeBSD$

PORTNAME=	mangler
PORTVERSION=	1.2.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.mangler.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ventrilo VOIP compatible client

LIB_DEPENDS=	libcelt0.so:${PORTSDIR}/audio/celt \
		libspeex.so:${PORTSDIR}/audio/speex \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24 \
		libgsm.so:${PORTSDIR}/audio/gsm

USES=		pkgconfig
USE_GNOME=	librsvg2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-alsa
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	PULSEAUDIO
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:${PORTSDIR}/audio/pulseaudio

.include <bsd.port.mk>
