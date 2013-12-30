# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aubio
PORTVERSION=	0.3.2
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://aubio.org/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for audio labelling

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3
LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libjack.so:${PORTSDIR}/audio/jack \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		liblash.so:${PORTSDIR}/audio/lash

GNU_CONFIGURE=	yes
# --disable-complex: does not compile due to missing carg(3) et al.
CONFIGURE_ARGS=	--disable-complex
USES=		gmake pathfix pkgconfig
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
