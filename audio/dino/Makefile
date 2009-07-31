# New ports collection makefile for:	dino
# Date created:		2007-01-13
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	dino
PORTVERSION=	0.2.2
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	dino

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	A pattern-based MIDI sequencer

LIB_DEPENDS=	glademm-2.4:${PORTSDIR}/devel/libglademm24 \
		jack.0:${PORTSDIR}/audio/jack \
		lash.2:${PORTSDIR}/audio/lash \
		xml++:${PORTSDIR}/textproc/libxml++26
BUILD_DEPENDS=	jackit>=0.109.2:${PORTSDIR}/audio/jack

# Between 0.109.0 and earlier versions there was an api change in JACK.
# However, the library version number was not changed.  The line above
# is supposed to work around that.

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

BROKEN=		does not compile

.include <bsd.port.mk>
