# New ports collection makefile for:	whysynth
# Date created:		2007-01-20
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	whysynth
PORTVERSION=	20100922
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://smbolton.com/whysynth/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Versatile softsynth implemented as a DSSI plugin

BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:${PORTSDIR}/audio/dssi \
		${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	dssialsacompat.0:${PORTSDIR}/audio/libdssialsacompat \
		lo.7:${PORTSDIR}/audio/liblo \
		jack.0:${PORTSDIR}/audio/jack \
		fftw3f:${PORTSDIR}/math/fftw3-float

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
