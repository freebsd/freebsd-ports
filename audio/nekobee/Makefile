# New ports collection makefile for:	nekobee
# Date created:		2007-01-20
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	nekobee
PORTVERSION=	0.1.7
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.nekosynth.co.uk/releases/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	DSSI plugin that emulates the sound of the TB-303 Bassline

LIB_DEPENDS=	dssialsacompat.0:${PORTSDIR}/audio/libdssialsacompat \
		lo.7:${PORTSDIR}/audio/liblo \
		jack.0:${PORTSDIR}/audio/jack
BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:${PORTSDIR}/audio/dssi

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
CFLAGS+=	-I${LOCALBASE}/include/dssi

.include <bsd.port.mk>
