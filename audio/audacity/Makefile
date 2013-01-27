# Created by: Marc van Woerkom <3d@freebsd.org>
# $FreeBSD$

PORTNAME=	audacity
PORTVERSION=	2.0.3
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE \
		SF/${PORTNAME}/${PORTNAME}-unstable/${PORTVERSION}
DISTNAME=	${PORTNAME}-minsrc-${PORTVERSION}

MAINTAINER=	xxjack12xx@gmail.com
COMMENT=	GUI editor for digital audio waveforms

LICENSE=	GPLv2

LIB_DEPENDS=	sndfile:${PORTSDIR}/audio/libsndfile

WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION}

USE_AUTOTOOLS=	aclocal autoconf
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_XZ=		yes
USE_WX=		2.8
WX_UNICODE=	yes
WX_COMPS=	wx
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes
MAN1=		audacity.1
MANCOMPRESSED=	yes
PORTDOCS=	README.txt

OPTIONS_DEFINE=	DOCS FFMPEG FLAC ID3TAG JACK LADSPA MAD NYQUIST PORTMIXER \
		SAMPLERATE SBSMS SSE TAGLIB TWOLAME VAMP VORBIS
OPTIONS_DEFAULT=	FFMPEG FLAC ID3TAG JACK LADSPA MAD NYQUIST \
			PORTMIXER SAMPLERATE SBSMS SSE TAGLIB \
			TWOLAME VAMP VORBIS

NYQUIST_DESC=	Nyquist plug-in support
PORTMIXER_DESC=	Compile with PortMixer support
SBSMS_DESC=	Use libsbsms for pitch and tempo changing
SSE=		Enable SSE optimizations
TAGLIB_DESC=	Use TagLib for metadata support
TWOLAME_DESC=	Use libtwolame for MP2 export support
VAMP_DESC=	Vamp plug-in support

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
SSE_CFLAGS=	-mno-sse -mno-sse2
.endif

ACLOCAL_ARGS+=	-I ${WRKSRC}/m4
AUTOCONF_ARGS+=	-I ${WRKSRC}/m4

CONFIGURE_ARG+	=--destdir=/
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CPPFLAGS+=	-I${WRKSRC}/lib-src/portsmf -I${WRKSRC}/lib-src/portaudio-v19/include -I${LOCALBASE}/include ${SSE_CFLAGS} ${PTHREAD_CFLAGS}
CXXFLAGS+=	-I${WRKSRC}/lib-src/portsmf -I${WRKSRC}/lib-src/portaudio-v19/include -I${LOCALBASE}/include ${SSE_CFLAGS} ${PTHREAD_CFLAGS}
CFLAGS+=	-I${WRKSRC}/lib-src/portsmf -I${WRKSRC}/lib-src/portaudio-v19/include -I${LOCALBASE}/include ${SSE_CFLAGS} ${PTHREAD_CFLAGS}

CONFIGURE_ENV+=	WX_CONFIG="${WX_CONFIG}"

CONFIGURE_ARGS+=	--with-lib-preference="local system"
CONFIGURE_ARGS+=	--with-portaudio
CONFIGURE_ARGS+=	--enable-unicode

.if ${PORT_OPTIONS:MFFMPEG}
RUN_DEPENDS+=		ffmpeg:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--with-ffmpeg
.else
CONFIGURE_ARGS+=	--without-ffmpeg
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=		FLAC:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=	--with-libflac
.else
CONFIGURE_ARGS+=	--without-libflac
.endif

.if ${PORT_OPTIONS:MID3TAG}
LIB_DEPENDS+=		id3tag:${PORTSDIR}/audio/libid3tag
CONFIGURE_ARGS+=	--with-libid3tag
.else
CONFIGURE_ARGS+=	--without-libid3tag
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=		jack:${PORTSDIR}/audio/jack
CONFIGURE_ARGS+=	--with-jack
.else
CONFIGURE_ARGS+=	--without-jack
.endif

.if ${PORT_OPTIONS:MLADSPA}
RUN_DEPENDS+=		listplugins:${PORTSDIR}/audio/ladspa
CONFIGURE_ARGS+=	--enable-ladspa
.else
CONFIGURE_ARGS+=	--disable-ladspa
.endif

.if ${PORT_OPTIONS:MMAD}
LIB_DEPENDS+=		mad:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=	--with-libmad
.else
CONFIGURE_ARGS+=	--without-libmad
.endif

.if ${PORT_OPTIONS:MNYQUIST}
CONFIGURE_ARGS+=	--enable-nyquist
.else
CONFIGURE_ARGS+=	--disable-nyquist
.endif

.if ${PORT_OPTIONS:MPORTMIXER}
CONFIGURE_ARGS+=	--with-portmixer
.else
CONFIGURE_ARGS+=	--without-portmixer
.endif

.if ${PORT_OPTIONS:MSAMPLERATE}
LIB_DEPENDS+=		samplerate:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=	--with-libsamplerate
.else
CONFIGURE_ARGS+=	--without-libsamplerate
.endif

.if ${PORT_OPTIONS:MSBSMS}
CONFIGURE_ARGS+=	--with-sbsms
.else
CONFIGURE_ARGS+=	--without-sbsms
.endif

.if ${PORT_OPTIONS:MSSE}
CONFIGURE_ARGS+=	--with-sse
.endif

.if ${PORT_OPTIONS:MTWOLAME}
LIB_DEPENDS+=		twolame:${PORTSDIR}/audio/twolame
CONFIGURE_ARGS+=	--with-libtwolame
.else
CONFIGURE_ARGS+=	--without-libtwolame
.endif

.if ${PORT_OPTIONS:MTAGLIB}
LIB_DEPENDS+=		tag:${PORTSDIR}/audio/taglib
CONFIGURE_ARGS+=	--with-taglib
.else
CONFIGURE_ARGS+=	--without-taglib
.endif

.if ${PORT_OPTIONS:MVAMP}
CONFIGURE_ARGS+=	--with-libvamp
.else
CONFIGURE_ARGS+=	--without-libvamp
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=		vorbis:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--with-libvorbis
.else
CONFIGURE_ARGS+=	--without-libvorbis
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

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
