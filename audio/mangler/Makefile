# Created by: Janik Galasso <janik@hikarihq.com>
# $FreeBSD$

PORTNAME=	mangler
PORTVERSION=	1.2.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.mangler.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ventrilo VOIP compatible client

BROKEN=		unfetchable

LIB_DEPENDS=	libcelt0.so:${PORTSDIR}/audio/celt \
		libspeex.so:${PORTSDIR}/audio/speex \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libgsm.so:${PORTSDIR}/audio/gsm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-alsa
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USES=		libtool pkgconfig
USE_GNOME=	gtkmm24 librsvg2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	PULSEAUDIO
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:${PORTSDIR}/audio/pulseaudio

.include <bsd.port.mk>
