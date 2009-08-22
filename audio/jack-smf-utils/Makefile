# New ports collection makefile for:	jack-smf-utils
# Date created:		2008-05-15
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jack-smf-utils
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Standard MIDI File file player and recorder for JACK MIDI

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		lash.2:${PORTSDIR}/audio/lash

GNU_CONFIGURE=	yes
USE_GNOME=	glib20

PLIST_FILES=	bin/smfsh bin/jack-smf-player bin/jack-smf-recorder
MAN1=		jack-smf-player.1 jack-smf-recorder.1

.include <bsd.port.mk>
