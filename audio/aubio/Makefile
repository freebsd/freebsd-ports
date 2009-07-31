# New ports collection makefile for:	aubio
# Date created:		2008-07-21
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aubio
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://aubio.org/pub/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Library for audio labelling

LIB_DEPENDS=	samplerate.1:${PORTSDIR}/audio/libsamplerate \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		jack.0:${PORTSDIR}/audio/jack \
		fftw3f:${PORTSDIR}/math/fftw3-float \
		lash.2:${PORTSDIR}/audio/lash

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
# --disable-complex, because it won't compile otherwise
# due to missing carg(3) et al.
CONFIGURE_ARGS=	"CFLAGS=${CFLAGS} -I${LOCALBASE}/include" --disable-complex

.include <bsd.port.mk>
