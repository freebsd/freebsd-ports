# New ports collection makefile for:	xsynth-dssi
# Date created:		2007-01-20
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	xsynth-dssi
PORTVERSION=	0.9.0
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dssi

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Classic analog style software synthesizer

LIB_DEPENDS=	dssialsacompat.0:${PORTSDIR}/audio/libdssialsacompat \
		lo.7:${PORTSDIR}/audio/liblo \
		jack.0:${PORTSDIR}/audio/jack
BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:${PORTSDIR}/audio/dssi

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
CFLAGS+=	-I${LOCALBASE}/include/dssi
USE_AUTOTOOLS=	libtool:15

.include <bsd.port.mk>
