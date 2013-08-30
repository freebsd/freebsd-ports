# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	whysynth
PORTVERSION=	20120903
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://smbolton.com/whysynth/

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Versatile softsynth implemented as a DSSI plugin

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:${PORTSDIR}/audio/dssi \
		${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	dssialsacompat:${PORTSDIR}/audio/libdssialsacompat \
		lo:${PORTSDIR}/audio/liblo \
		jack:${PORTSDIR}/audio/jack \
		fftw3:${PORTSDIR}/math/fftw3 \
		fftw3f:${PORTSDIR}/math/fftw3-float

USES=		gmake
USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_AUTOTOOLS=	libtool

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
