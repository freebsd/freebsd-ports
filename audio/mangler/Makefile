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

LIB_DEPENDS=	celt0.2:${PORTSDIR}/audio/celt \
		speex.1:${PORTSDIR}/audio/speex \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gsm.1:${PORTSDIR}/audio/gsm

USES=		gmake
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
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=--with-pulseaudio
.else
CONFIGURE_ARGS+=--without-pulseaudio
.endif

.include <bsd.port.mk>
