# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aubio
PORTVERSION=	0.4.1
CATEGORIES=	audio
MASTER_SITES=	http://aubio.org/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for audio labelling

LICENSE=	GPLv3

BUILD_DEPENDS=	txt2man:${PORTSDIR}/textproc/txt2man

USES=		pkgconfig tar:bzip2 waf
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man

OPTIONS_DEFINE=	COMPLEX DOXYGEN FFMPEG JACK SAMPLERATE SNDFILE
OPTIONS_DEFAULT=	FFTW JACK SAMPLERATE SNDFILE SINGLE

COMPLEX_DESC=	Compile with C99 complex.h
COMPLEX_CONFIGURE_ENABLE=	complex

DOXYGEN_CONFIGURE_OFF=	--disable-doxygen
DOXYGEN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen

FFMPEG_CONFIGURE_ENABLE=	avcodec
FFMPEG_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg

JACK_CONFIGURE_ENABLE=	jack
JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack

SAMPLERATE_CONFIGURE_ENABLE=	samplerate
SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate

SNDFILE_CONFIGURE_ENABLE=	sndfile
SNDFILE_LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile

OPTIONS_SINGLE=	FFT PRECISION
OPTIONS_SINGLE_FFT=	FFTW OOURA
OPTIONS_SINGLE_PRECISION=	DOUBLE SINGLE

FFT_DESC=	FFT implementation
FFTW_DESC=	FFTW3/FFTW3F (depending on precision)
OOURA_DESC=	Ooura (last resort)

PRECISION_DESC=	Precision
DOUBLE_DESC=	Double precision mode
SINGLE_DESC=	Single precision mode
DOUBLE_CONFIGURE_ENABLE=	double

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
PLIST_SUB+=	DOXYGEN=""
.else
PLIST_SUB+=	DOXYGEN="@comment "
.endif

.if ${PORT_OPTIONS:MFFTW}
.  if ${PORT_OPTIONS:MDOUBLE}
LIB_DEPENDS+=	libfftw3.so:${PORTSDIR}/math/fftw3
.  else
LIB_DEPENDS+=	libfftw3f.so:${PORTSDIR}/math/fftw3-float
.  endif
.endif

post-patch:
	@${REINPLACE_CMD} -e '/pkgconfig/s,$${LIBDIR},&data,' \
		${WRKSRC}/waflib/TaskGen.py

.if !defined(WITH_DEBUG) || defined(WITHOUT_DEBUG) || defined(INSTALL_STRIPPED)
post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so
.  for b in mfcc notes onset pitch quiet track
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}${b}
.  endfor
.endif

.include <bsd.port.mk>
