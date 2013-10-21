# Created by: Marc van Woerkom <3d@FreeBSD.org>
# $FreeBSD$

PORTNAME=	audacity
PORTVERSION=	2.0.4
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE \
		SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-minsrc-${PORTVERSION}

MAINTAINER=	xxjack12xx@gmail.com
COMMENT=	GUI editor for digital audio waveforms

LICENSE=	GPLv2

LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile

WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION}

USE_AUTOTOOLS=	aclocal autoconf
GNU_CONFIGURE=	yes
USES=		gmake gettext pkgconfig
USE_XZ=		yes
USE_WX=		2.8
WX_UNICODE=	yes
WX_COMPS=	wx
INSTALLS_ICONS=	yes
PORTDOCS=	README.txt

OPTIONS_DEFINE=	DOCS FFMPEG FLAC ID3TAG JACK LADSPA MAD NYQUIST PORTMIXER \
		SAMPLERATE SBSMS SOXR SSE TAGLIB TWOLAME VAMP VORBIS
OPTIONS_DEFAULT=	FFMPEG FLAC ID3TAG JACK LADSPA MAD NYQUIST \
			PORTMIXER SAMPLERATE SBSMS SOXR SSE TAGLIB \
			TWOLAME VAMP VORBIS

NYQUIST_DESC=	Nyquist plug-in support
PORTMIXER_DESC=	Compile with PortMixer support
SBSMS_DESC=	Use libsbsms for pitch and tempo changing
SOXR_DESC=	Use libsoxr for sample rate conversion
SSE=		Enable SSE optimizations
TAGLIB_DESC=	Use TagLib for metadata support
TWOLAME_DESC=	Use libtwolame for MP2 export support
VAMP_DESC=	Vamp plug-in support

ACLOCAL_ARGS+=	-I ${WRKSRC}/m4
AUTOCONF_ARGS+=	-I ${WRKSRC}/m4

CONFIGURE_ARG+=	--destdir=/

CONFIGURE_ENV+=	WX_CONFIG="${WX_CONFIG}"

CONFIGURE_ARGS+=	--with-lib-preference="local system" \
			--with-portaudio --enable-unicode

FFMPEG_CONFIGURE_WITH=	ffmpeg
FFMPEG_RUN_DEPENDS=	ffmpeg0:${PORTSDIR}/multimedia/ffmpeg0
FFMPEG_BUILD_DEPENDS=	ffmpeg0>=0:${PORTSDIR}/multimedia/ffmpeg0
FFMPEG_CFLAGS=		-I${LOCALBASE}/include/ffmpeg0
FFMPEG_CPPFLAGS=	-I${LOCALBASE}/include/ffmpeg0
FFMPEG_CXXFLAGS=	-I${LOCALBASE}/include/ffmpeg0

FLAC_CONFIGURE_WITH=	libflac
FLAC_LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac

ID3TAG_CONFIGURE_WITH=	libid3tag
ID3TAG_LIB_DEPENDS=	libid3tag.so:${PORTSDIR}/audio/libid3tag

JACK_CONFIGURE_WITH=	jack
JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack

LADSPA_CONFIGURE_ENABLE=	ladspa
LADSPA_RUN_DEPENDS=	listplugins:${PORTSDIR}/audio/ladspa

MAD_CONFIGURE_WITH=	libmad
MAD_LIB_DEPENDS=	libmad.so:${PORTSDIR}/audio/libmad

NYQUIST_CONFIGURE_ENABLE=	nyquist

PORTMIXER_CONFIGURE_WITH=	portmixer

SAMPLERATE_CONFIGURE_WITH=	libsamplerate
SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate

SBSMS_CONFIGURE_WITH=	sbsms

SSE_CONFIGURE_WITH=	sse

SOXR_CONFIGURE_WITH=	libsoxr
SOXR_BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

TWOLAME_CONFIGURE_WITH=	libtwolame
TWOLAME_LIB_DEPENDS=	libtwolame.so:${PORTSDIR}/audio/twolame

TAGLIB_CONFIGURE_WITH=	taglib
TAGLIB_LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib

VAMP_CONFIGURE_WITH=	libvamp

VORBIS_CONFIGURE_WITH=	libvorbis
VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis

.include <bsd.port.pre.mk>

LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CPPFLAGS+=	-I${WRKSRC}/lib-src/portsmf -I${WRKSRC}/lib-src/portaudio-v19/include -I${LOCALBASE}/include ${SSE_CFLAGS} ${PTHREAD_CFLAGS}
CXXFLAGS+=	-I${WRKSRC}/lib-src/portsmf -I${WRKSRC}/lib-src/portaudio-v19/include -I${LOCALBASE}/include ${SSE_CFLAGS} ${PTHREAD_CFLAGS}
CFLAGS+=	-I${WRKSRC}/lib-src/portsmf -I${WRKSRC}/lib-src/portaudio-v19/include -I${LOCALBASE}/include ${SSE_CFLAGS} ${PTHREAD_CFLAGS}

.if ${ARCH} != "amd64"
SSE_CFLAGS=	-mno-sse -mno-sse2
.endif

post-patch:
#audacity links to some dependencies if present, even if explicitly disabled.
#these must be patched out for the case when they are installed but
#option-disabled to avoid unrecorded dependencies.

.if empty(PORT_OPTIONS:MJACK)
	@${REINPLACE_CMD} -e 's|PKG_CHECK_MODULES(JACK, jack, have_jack=yes, have_jack=no)|have_jack=no|' ${WRKSRC}/configure.in
.endif

.if empty(PORT_OPTIONS:MSAMPLERATE)
	@${REINPLACE_CMD} -e 's|libresample.a -lsamplerate $(LIBS)|libresample.a $(LIBS)|' ${WRKSRC}/lib-src/libresample/Makefile.in
.endif

	@${REINPLACE_CMD} -e 's|inline void|static inline void|' ${WRKSRC}/lib-src/libnyquist/nyquist/ffts/src/fftlib.c
	@${REINPLACE_CMD} \
		-e 's|libavcodec |libavcodec0 |g' \
		-e 's|libavformat |libavformat0 |g' \
		-e 's|libavutil,|libavutil0,|g' \
		${WRKSRC}/m4/audacity_checklib_ffmpeg.m4

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
