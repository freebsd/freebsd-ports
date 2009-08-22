# New ports collection makefile for:	jack-keyboard
# Date created:		2007-01-23
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	jack-keyboard
DISTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Virtual keyboard for JACK MIDI

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		lash.2:${PORTSDIR}/audio/lash

MAN1=		jack-keyboard.1

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
