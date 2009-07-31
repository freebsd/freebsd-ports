# New ports collection makefile for:	specimen
# Date created:		2007-03-06
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	specimen
DISTVERSION=	0.5.2-rc3
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://zhevny.com/specimen/files/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	MIDI controllable audio sampler

LIB_DEPENDS=	phat.0:${PORTSDIR}/x11-toolkits/phat \
		jack.0:${PORTSDIR}/audio/jack \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		lash.2:${PORTSDIR}/audio/lash
BUILD_DEPENDS=	jackit>=0.109.2:${PORTSDIR}/audio/jack

# Between 0.109.0 and earlier versions there was an api change in JACK.
# However, the library version number was not changed.  The line above
# is supposed to work around that.

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	libxml2 libgnomecanvas

.include <bsd.port.mk>
