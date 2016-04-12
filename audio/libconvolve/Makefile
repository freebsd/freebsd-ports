# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	libconvolve
PORTVERSION=	0.0.8
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF/heaven/Audio%20Applications/Jack%20Related/jack_convolve/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple C library for partitioned convolution

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile

USES=		gmake pkgconfig tar:tgz
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/cp / s|PREFIX|DESTDIR)$$(&|g' \
		-e '/ln / s|PREFIX|DESTDIR)$$(&|2' \
		${WRKSRC}/Makefile
post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so.0.0.8

.include <bsd.port.mk>
