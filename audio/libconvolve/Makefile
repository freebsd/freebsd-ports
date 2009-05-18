# New ports collection makefile for:	libconvolve
# Date created:		2007-04-02
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	libconvolve
PORTVERSION=	0.0.8
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://tapas.affenbande.org/jack_convolve/
EXTRACT_SUFX=	.tgz

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Simple C library for partitioned convolution

LIB_DEPENDS=	fftw3f.5:${PORTSDIR}/math/fftw3-float \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		sndfile.1:${PORTSDIR}/audio/libsndfile

USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
