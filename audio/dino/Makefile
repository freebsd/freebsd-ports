# New ports collection makefile for:	dino
# Date created:		2007-01-13
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	dino
PORTVERSION=	0.2.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	dino

MAINTAINER=	trasz@freebsd.org
COMMENT=	A pattern-based MIDI sequencer

LIB_DEPENDS=	glademm-2.4:${PORTSDIR}/devel/libglademm24 \
		jack.0:${PORTSDIR}/audio/jack \
		lash.2:${PORTSDIR}/audio/lash \
		xml++:${PORTSDIR}/textproc/libxml++26

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
