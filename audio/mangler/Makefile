# New ports collection makefile for:	mangler
# Date created:		2010-10-18
# Whom:			Janik Galasso <janik@hikarihq.com>
#
# $FreeBSD$
#

PORTNAME=	mangler
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.mangler.org/downloads/

MAINTAINER=	janik@hikarihq.com
COMMENT=	A Ventrilo VOIP combatible client

LIB_DEPENDS=	celt.0:${PORTSDIR}/audio/celt \
		speex.1:${PORTSDIR}/audio/speex \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gsm.1:${PORTSDIR}/audio/gsm

USE_GNOME=	librsvg2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-alsa
USE_LDCONFIG=	yes

CONFIGURE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	PULSEAUDIO "Adds support for the PulseAudio sound server" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not build
.endif

.if !defined(WITHOUT_PULSEAUDIO)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=--with-pulseaudio
.else
CONFIGURE_ARGS+=--without-pulseaudio
.endif

.include <bsd.port.post.mk>
