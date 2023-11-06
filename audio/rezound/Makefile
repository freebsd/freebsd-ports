PORTNAME=	rezound
DISTVERSION=	0.13.1beta
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/ReZound/${DISTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical audio file editor
WWW=		https://rezound.sourceforge.net/

LICENSE=	GPLv2

LIB_DEPENDS=	libFOX-1.6.so:x11-toolkits/fox16

USES=		bison compiler:c++11-lang pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa

OPTIONS_DEFINE=	LARGEFILE JACK AUDIOFILE PORTAUDIO OGG VORBIS FLAC FFTW \
		SOUNDTOUCH PULSEAUDIO LADSPA LAME CDRDAO DOCS NLS
OPTIONS_DEFAULT=	AUDIOFILE PORTAUDIO OGG VORBIS FLAC SOUNDTOUCH \
		LADSPA LAME

LARGEFILE_DESC=	Use 64-bit file I/O
FFTW_DESC=	Use fast Fourier transform routines
CDRDAO_DESC=	Burning audio files to CD support

LARGEFILE_CONFIGURE_ON=	--enable-largefile
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_OFF=	--disable-jack
AUDIOFILE_LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CONFIGURE_OFF=--disable-portaudio
OGG_LIB_DEPENDS=	libogg.so:audio/libogg
VORBIS_IMPLIES=		OGG
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
FLAC_IMPLIES=		OGG
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3
FFTW_CONFIGURE_OFF=	--disable-fftw3
SOUNDTOUCH_LIB_DEPENDS=	libSoundTouch.so:audio/soundtouch
PULSEAUDIO_IMPLIES=	FLAC VORBIS
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=--disable-pulse
LADSPA_RUN_DEPENDS=	${LOCALBASE}/lib/ladspa/amp.so:audio/ladspa
LADSPA_CONFIGURE_OFF=	--disable-ladspa
LAME_RUN_DEPENDS=	lame:audio/lame
CDRDAO_RUN_DEPENDS=	cdrdao:sysutils/cdrdao

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CPPFLAGS+=	-I${LOCALBASE}/include
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch: .SILENT
	${REINPLACE_CMD} -E '/atoll|round|nearbyint/d' \
		${WRKSRC}/config/platform/bsd.h
	${REINPLACE_CMD} -E 's,(_nl_expand_alias \()\),\1...), ; \
		/^C(XX)?FLAGS=/d ; /CXXFLAGS="\$$CXXFLAGS -[gsW]/d ; \
		/^return /s,\(int\)( n?gettext),(long)\1, ; \
		/boost header not found/d' \
			${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,$$(prefix)/doc,$$(datadir)/doc,' \
		${WRKSRC}/config/am_include.mk ${WRKSRC}/Makefile.in \
		${WRKSRC}/src/Makefile.in ${WRKSRC}/src/misc/Makefile.in \
		${WRKSRC}/src/misc/CNestedDataFile/Makefile.in \
		${WRKSRC}/src/PoolFile/Makefile.in \
		${WRKSRC}/src/backend/DSP/Makefile.in \
		${WRKSRC}/src/backend/File/Makefile.in \
		${WRKSRC}/src/backend/Edits/Makefile.in \
		${WRKSRC}/src/backend/Looping/Makefile.in \
		${WRKSRC}/src/backend/Generate/Makefile.in \
		${WRKSRC}/src/backend/Remaster/Makefile.in \
		${WRKSRC}/src/backend/LADSPA/Makefile.in
	${REINPLACE_CMD} -e '/^#include/s,soundtouch/,,' \
		${WRKSRC}/src/backend/DSP/T*Changer.h
	${REINPLACE_CMD} -e 's,auto_ptr,unique_ptr,' \
		${WRKSRC}/src/backend/AAction.* \
		${WRKSRC}/src/backend/Effects/CFlangeEffect.cpp \
		${WRKSRC}/src/backend/Effects/CVariedRepeatEffect.cpp
	${REINPLACE_CMD} -e '/unsigned/s,register ,,' \
		${WRKSRC}/src/backend/CSound.h
	${REINPLACE_CMD} -e '/size_t/s,register ,,' \
		${WRKSRC}/src/backend/CSoundPlayerChannel.cpp
	${REINPLACE_CMD} -e '/const/s,register ,,' \
		${WRKSRC}/src/backend/CSound_defs.h \
		${WRKSRC}/src/backend/Filters/CBiquadResFilter.cpp \
		${WRKSRC}/src/backend/Filters/CSinglePoleFilter.cpp
	${REINPLACE_CMD} -e '/int/s,register ,,' \
		${WRKSRC}/src/misc/endian_util.h
.if ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/AUTHORS/d; /COPYING/d' ${WRKSRC}/Makefile.in
.else
	${REINPLACE_CMD} -e 's/ install-pkgdocDATA$$//' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
