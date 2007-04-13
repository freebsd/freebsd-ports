# New ports collection makefile for:	whysynth
# Date created:		2007-01-20
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	whysynth
PORTVERSION=	20060122
CATEGORIES=	audio
MASTER_SITES=	http://home.jps.net/~musound/

MAINTAINER=	trasz@freebsd.org
COMMENT=	Versatile softsynth implemented as a DSSI plugin

LIB_DEPENDS=	dssialsacompat.0:${PORTSDIR}/audio/libdssialsacompat \
		lo.6:${PORTSDIR}/audio/liblo \
		jack.0:${PORTSDIR}/audio/jack \
		fftw3f.4:${PORTSDIR}/math/fftw3-float
BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:${PORTSDIR}/audio/dssi

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20

.include <bsd.port.mk>
