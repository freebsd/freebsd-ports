# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aubio
PORTVERSION=	0.4.6
PORTREVISION?=	1
CATEGORIES?=	audio
MASTER_SITES=	http://aubio.org/pub/

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=	5690daf759b4.patch:-p1

MAINTAINER?=	jhale@FreeBSD.org
COMMENT?=	Library for audio labelling

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES+=		pkgconfig tar:bzip2

.if !defined(SLAVEPORT)
BUILD_DEPENDS=	txt2man:textproc/txt2man

USES+=		waf
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		COMPLEX DOXYGEN FFMPEG FFTW JACK SAMPLERATE SNDFILE
OPTIONS_DEFAULT=	JACK SAMPLERATE SNDFILE FFTW
OPTIONS_SUB=		yes

COMPLEX_DESC=		Compile with C99 complex.h
COMPLEX_CONFIGURE_ENABLE=	complex
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_OFF=	--disable-doxygen
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ENABLE=	avcodec
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=	jack
SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
SAMPLERATE_CONFIGURE_ENABLE=	samplerate
FFTW_DESC=		Use single precision FFTW3 instead of built-in OOURA
FFTW_CONFIGURE_ENABLE=	fftw3f
FFTW_BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
FFTW_LIB_DEPENDS=	libfftw3f.so:math/fftw3-float
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CONFIGURE_ENABLE=	sndfile

post-patch:
	@${REINPLACE_CMD} -e \
		'/pkgconfig/s|$${LIBDIR}|&data|' ${WRKSRC}/waflib/TaskGen.py

post-install:
.for b in mfcc notes onset pitch quiet track
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/aubio${b}
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libaubio.so

.endif # !defined(SLAVEPORT)

.include <bsd.port.mk>
