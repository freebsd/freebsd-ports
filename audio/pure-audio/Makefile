# New ports collection makefile for:	pure-gtk
# Date created:		2011-03-18
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure-audio
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	lichray@gmail.com
COMMENT=	A digital audio interface for the Pure language

LIB_DEPENDS=	portaudio.2:${PORTSDIR}/audio/portaudio2 \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		fftw3:${PORTSDIR}/math/fftw3

USE_PURE=	yes

post-patch:
	${REINPLACE_CMD} \
		-e "s|-lportaudio|-I${LOCALBASE}/include/portaudio2 -L${LOCALBASE}/lib/portaudio2 -lportaudio|" \
		-e "s|portaudio.h|portaudio2/portaudio.h|g" \
	   	${WRKSRC}/Makefile

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/pure/bsd.pure.mk"
.include <bsd.port.post.mk>
