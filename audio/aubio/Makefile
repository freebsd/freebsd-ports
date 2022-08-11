PORTNAME=	aubio
PORTVERSION=	0.4.9
PORTREVISION?=	1
CATEGORIES?=	audio
MASTER_SITES=	https://aubio.org/pub/

MAINTAINER?=	jhale@FreeBSD.org
COMMENT?=	Library for audio labelling

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES+=		cpe pkgconfig tar:bzip2

BINARY_ALIAS=	python=${PYTHON_CMD}

.if !defined(SLAVEPORT)
USES+=		python:build,3.6+ waf
USE_LDCONFIG=	yes

OPTIONS_GROUP=		DOCS
OPTIONS_GROUP_DOCS=	DOCS DOXYGEN MANPAGES
OPTIONS_DEFINE=		COMPLEX FFMPEG FFTW JACK SAMPLERATE SNDFILE TEST
OPTIONS_DEFAULT=	FFMPEG FFTW JACK MANPAGES SAMPLERATE SNDFILE
OPTIONS_SUB=		yes

COMPLEX_DESC=			Compile with C99 complex.h
COMPLEX_CONFIGURE_ENABLE=	complex

DOCS_BUILD_DEPENDS=		${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_CONFIGURE_ENABLE=		sphinx
DOCS_BINARY_ALIAS=		sphinx-build=sphinx-build-${PYTHON_VER}

DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENABLE=	doxygen

FFMPEG_LIB_DEPENDS=		libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ENABLE=	avcodec

JACK_LIB_DEPENDS=		libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=		jack

SAMPLERATE_LIB_DEPENDS=		libsamplerate.so:audio/libsamplerate
SAMPLERATE_CONFIGURE_ENABLE=	samplerate

FFTW_DESC=			Use single precision FFTW3 instead of built-in OOURA
FFTW_CONFIGURE_ENABLE=		fftw3f
FFTW_BUILD_DEPENDS=		${LOCALBASE}/include/fftw3.h:math/fftw3
FFTW_LIB_DEPENDS=		libfftw3f.so:math/fftw3-float

MANPAGES_BUILD_DEPENDS=		txt2man:textproc/txt2man
MANPAGES_CONFIGURE_ENABLE=	manpages
MANPAGES_CONFIGURE_ON=		--mandir=${MANPREFIX}/man

SNDFILE_LIB_DEPENDS=		libsndfile.so:audio/libsndfile
SNDFILE_CONFIGURE_ENABLE=	sndfile

TEST_MAKE_ARGS=			--enable-tests
TEST_MAKE_ARGS_OFF=		--disable-tests

PORTDOCS=	*

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
