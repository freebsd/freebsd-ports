# Created by: Janik Galasso <janik@hikarihq.com>
# $FreeBSD$

PORTNAME=	mangler
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.mangler.org/downloads/ \
		http://ultimeordi.com/pub/mangler/

MAINTAINER=	janik@hikarihq.com
COMMENT=	A Ventrilo VOIP compatible client

LIB_DEPENDS=	libcelt0.so:${PORTSDIR}/audio/celt \
		libspeex..so:${PORTSDIR}/audio/speex \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libgtkmm-2.4..so:${PORTSDIR}/x11-toolkits/gtkmm24 \
		libgsm.so:${PORTSDIR}/audio/gsm

USES=		gmake pkgconfig
NO_STAGE=	yes
USE_GNOME=	librsvg2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-alsa
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	PULSEAUDIO

MAN1=   mangler.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	libpulse.so:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=--with-pulseaudio
.else
CONFIGURE_ARGS+=--without-pulseaudio
.endif

.include <bsd.port.mk>
