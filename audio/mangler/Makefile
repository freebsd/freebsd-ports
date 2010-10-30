# New ports collection makefile for:	mangler
# Date created:		2010-10-18
# Whom:			Janik Galasso <janik@hikarihq.com>
#
# $FreeBSD$
#

PORTNAME=	mangler
PORTVERSION=	1.2.1
CATEGORIES=	audio
MASTER_SITES=	http://www.mangler.org/downloads/

MAINTAINER=	janik@hikarihq.com
COMMENT=	A Ventrilo VOIP combatible client

LIB_DEPENDS=	celt.0:${PORTSDIR}/audio/celt \
		speex.1:${PORTSDIR}/audio/speex \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USE_GNOME=	librsvg2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gsm --without-pulseaudio --without-alsa
USE_LDCONFIG=	yes

.include <bsd.port.mk>
