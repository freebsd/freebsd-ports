# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	soundkonverter
DISTVERSION=	2.0.2
CATEGORIES=	audio kde
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
DISTNAME=	29024-${PORTNAME}-${DISTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Frontend to various audio converters (transcoder)

LICENSE=	GPLv3

LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib \
		cdda_paranoia:${PORTSDIR}/audio/cdparanoia

USES=		cmake
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs libkcddb
INSTALLS_ICONS=	yes

MAKE_JOBS_SAFE=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	NLS
OPTIONS_MULTI=	CODEC FILTER REPLAYGAIN
OPTIONS_MULTI_CODEC=	AFTEN FAAC FFMPEG FLAC FLAKE FLUIDSYNTH LAME MAC MPLAYER \
		MUSEPACK NEROAAC OPUSTOOLS SHORTEN SPEEX TIMIDITY TTA \
		TWOLAME VORBIS WAVPACK
OPTIONS_MULTI_FILTER=	NORMALIZE SOX
OPTIONS_MULTI_REPLAYGAIN=	AACGAIN FLAC MP3GAIN MUSEPACK NORMALIZE \
		VORBISGAIN WAVPACK
OPTIONS_DEFAULT=	VORBISTOOLS FLAC NORMALIZE VORBISGAIN
CODEC_DESC=	Audio codec formats
FILTER_DESC=	Audio filter tools
REPLAYGAIN_DESC=	Replaygain tools for codecs
AFTEN_DESC=	ATSC A/52 audio encoder
AACGAIN_DESC=	AAC audio replaygain
FLAKE_DESC=	FLAC audio codec
FLUIDSYNTH_DESC=	SoundFont 2 audio codec
MAC_DESC=	Monkey's Audio lossless codec
MP3GAIN_DESC=	MP3 audio replaygain
NEROAAC_DESC=	Nero AAC MPEG-3 and 3GPP audio codec
NORMALIZE_DESC=	MP3/Ogg Vorbis audio filter and replaygain
OPUSTOOLS_DESC=	Opus audio codec
SHORTEN_DESC=	Shorten (lossless) audio codec
SOX_DESC=	Universal sound sample translator
TIMIDITY_DESC=	MIDI audio decoder
TTA_DESC=	True Audio lossless audio codec
# TWOLAME_DESC
VORBISGAIN_DESC=	Ogg Vorbis audio replaygain

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAFTEN}
RUN_DEPENDS+=	aften:${PORTSDIR}/audio/aften
PLIST_SUB+=	AFTEN=""
.else
SK_CMAKE_RM+=	codec_aften
PLIST_SUB+=	AFTEN="@comment "
.endif

.if ${PORT_OPTIONS:MAACGAIN}
RUN_DEPENDS+=	aacgain:${PORTSDIR}/audio/aacgain
PLIST_SUB+=	AACGAIN=""
.else
SK_CMAKE_RM+=	replaygain_aacgain
PLIST_SUB+=	AACGAIN="@comment "
.endif

.if ${PORT_OPTIONS:MFAAC}
RUN_DEPENDS+=	faac:${PORTSDIR}/audio/faac \
		faad:${PORTSDIR}/audio/faad
PLIST_SUB+=	FAAC=""
.else
SK_CMAKE_RM+=	codec_faac
PLIST_SUB+=	FAAC="@comment "
.endif

.if ${PORT_OPTIONS:MFFMPEG}
RUN_DEPENDS+=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=	FFMPEG=""
.else
SK_CMAKE_RM+=	codec_ffmpeg
PLIST_SUB+=	FFMPEG="@comment "
.endif

.if ${PORT_OPTIONS:MFLAC}
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
PLIST_SUB+=	FLAC=""
.else
SK_CMAKE_RM+=	codec_flac replaygain_metaflac
PLIST_SUB+=	FLAC="@comment "
.endif

.if ${PORT_OPTIONS:MFLAKE}
RUN_DEPENDS+=	flake:${PORTSDIR}/audio/flake
PLIST_SUB+=	FLAKE=""
.else
SK_CMAKE_RM+=	codec_flake
PLIST_SUB+=	FLAKE="@comment "
.endif

.if ${PORT_OPTIONS:MFLUIDSYNTH}
RUN_DEPENDS+=	fluidsynth:${PORTSDIR}/audio/fluidsynth
PLIST_SUB+=	FLUIDSYNTH=""
.else
SK_CMAKE_RM+=	codec_fluidsynth
PLIST_SUB+=	FLUIDSYNTH="@comment "
.endif

.if ${PORT_OPTIONS:MLAME}
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
PLIST_SUB+=	LAME=""
.else
SK_CMAKE_RM+=	codec_lame
PLIST_SUB+=	LAME="@comment "
.endif

.if ${PORT_OPTIONS:MLIBAV} && defined(NOT_IMPLEMENTED)
RUN_DEPENDS+=	avconv:${PORTSDIR}/audio/libav
PLIST_SUB+=	LIBAV=""
.else
SK_CMAKE_RM+=	codec_libav
PLIST_SUB+=	LIBAV="@comment "
.endif

.if ${PORT_OPTIONS:MMAC}
RUN_DEPENDS+=	mac:${PORTSDIR}/audio/mac
PLIST_SUB+=	MAC=""
.else
SK_CMAKE_RM+=	codec_mac
PLIST_SUB+=	MAC="@comment "
.endif

.if ${PORT_OPTIONS:MMP3GAIN}
RUN_DEPENDS+=	mp3gain:${PORTSDIR}/audio/mp3gain
PLIST_SUB+=	MP3GAIN=""
.else
SK_CMAKE_RM+=	replaygain_mp3gain
PLIST_SUB+=	MP3GAIN="@comment "
.endif

.if ${PORT_OPTIONS:MMPLAYER}
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
PLIST_SUB+=	MPLAYER=""
.else
SK_CMAKE_RM+=	codec_mplayer
PLIST_SUB+=	MPLAYER="@comment "
.endif

.if ${PORT_OPTIONS:MMUSEPACK}
RUN_DEPENDS+=	mpcenc:${PORTSDIR}/audio/musepack
PLIST_SUB+=	MUSEPACK=""
.else
SK_CMAKE_RM+=	codec_musepack replaygain_musepack
PLIST_SUB+=	MUSEPACK="@comment "
.endif

.if ${PORT_OPTIONS:MNEROAAC}
RUN_DEPENDS+=	neroAacEnc:${PORTSDIR}/audio/linux-neroaaccodec
PLIST_SUB+=	NEROAAC=""
.else
SK_CMAKE_RM+=	codec_neroaac
PLIST_SUB+=	NEROAAC="@comment "
.endif

.if ${PORT_OPTIONS:MNORMALIZE}
RUN_DEPENDS+=	normalize:${PORTSDIR}/audio/normalize
PLIST_SUB+=	NORMALIZE=""
.else
SK_CMAKE_RM+=	filter_normalize
PLIST_SUB+=	NORMALIZE="@comment "
.endif

.if ${PORT_OPTIONS:MOPUSTOOLS}
RUN_DEPENDS+=	opusenc:${PORTSDIR}/audio/opus-tools
PLIST_SUB+=	OPUSTOOLS=""
.else
SK_CMAKE_RM+=	codec_opustools
PLIST_SUB+=	OPUSTOOLS="@comment "
.endif

.if ${PORT_OPTIONS:MSHORTEN}
RUN_DEPENDS+=	shorten:${PORTSDIR}/audio/shorten
PLIST_SUB+=	SHORTEN=""
.else
SK_CMAKE_RM+=	codec_shorten
PLIST_SUB+=	SHORTEN="@comment "
.endif

.if ${PORT_OPTIONS:MSOX}
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox
PLIST_SUB+=	SOX=""
.else
SK_CMAKE_RM+=	filter_sox
PLIST_SUB+=	SOX="@comment "
.endif

.if ${PORT_OPTIONS:MSPEEX}
RUN_DEPENDS+=	speexenc:${PORTSDIR}/audio/speex
PLIST_SUB+=	SPEEX=""
.else
SK_CMAKE_RM+=	codec_speex
PLIST_SUB+=	SPEEX="@comment "
.endif

.if ${PORT_OPTIONS:MTIMIDITY}
RUN_DEPENDS+=	timidity:${PORTSDIR}/audio/timidity
PLIST_SUB+=	TIMIDITY=""
.else
SK_CMAKE_RM+=	codec_timidity
PLIST_SUB+=	TIMIDITY="@comment "
.endif

.if ${PORT_OPTIONS:MTTA}
RUN_DEPENDS+=	ttaenv:${PORTSDIR}/audio/tta
PLIST_SUB+=	TTA=""
.else
SK_CMAKE_RM+=	codec_ttaenc
PLIST_SUB+=	TTA="@comment "
.endif

.if ${PORT_OPTIONS:MTWOLAME}
RUN_DEPENDS+=	twolame:${PORTSDIR}/audio/twolame
PLIST_SUB+=	TWOLAME=""
.else
SK_CMAKE_RM+=	codec_twolame
PLIST_SUB+=	TWOLAME="@comment "
.endif

.if ${PORT_OPTIONS:MVORBISGAIN}
RUN_DEPENDS+=	vorbisgain:${PORTSDIR}/audio/vorbisgain
PLIST_SUB+=	VORBISGAIN=""
.else
SK_CMAKE_RM+=	replaygain_vorbisgain
PLIST_SUB+=	VORBISGAIN="@comment "
.endif

.if ${PORT_OPTIONS:MVORBIS}
RUN_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
PLIST_SUB+=	VORBIS=""
.else
SK_CMAKE_RM+=	codec_vorbistools
PLIST_SUB+=	VORBIS="@comment "
.endif

.if ${PORT_OPTIONS:MWAVPACK}
RUN_DEPENDS+=	wavpack:${PORTSDIR}/audio/wavpack
PLIST_SUB+=	WAVPACK=""
.else
SK_CMAKE_RM+=	codec_wavpack replaygain_wvgain
PLIST_SUB+=	WAVPACK="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
CMAKE_ARGS+=	-DBUILD_po=FALSE
.endif

post-patch:
	${MKDIR} ${WRKSRC}/plugins_nobuild
.for plugin in ${SK_CMAKE_RM}
	${MV} ${WRKSRC}/plugins/soundkonverter_${plugin} \
		${WRKSRC}/plugins_nobuild/
.endfor

.include <bsd.port.mk>
