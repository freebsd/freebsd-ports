# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	soundkonverter
DISTVERSION=	2.0.4
CATEGORIES=	audio kde
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
DISTNAME=	29024-${PORTNAME}-${DISTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Frontend to various audio converters (transcoder)

LICENSE=	GPLv3

LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib \
		libcdda_paranoia.so:${PORTSDIR}/audio/cdparanoia

USES=		cmake
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs libkcddb
INSTALLS_ICONS=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFAULT=	VORBISTOOLS FLAC NORMALIZE VORBISGAIN
OPTIONS_DEFINE=	NLS
OPTIONS_MULTI=	CODEC FILTER REPLAYGAIN
OPTIONS_MULTI_CODEC=	AFTEN FAAC FFMPEG FLAC FLAKE FLUIDSYNTH LAME MAC \
			MPLAYER MUSEPACK NEROAAC OPUSTOOLS SHORTEN SPEEX  \
			TIMIDITY TTA TWOLAME VORBIS WAVPACK #LIBAV
OPTIONS_MULTI_FILTER=	NORMALIZE SOX
OPTIONS_MULTI_REPLAYGAIN=	AACGAIN FLAC MP3GAIN MUSEPACK NORMALIZE \
			VORBISGAIN WAVPACK
OPTIONS_SUB=	yes

CODEC_DESC=		Audio codec formats
FILTER_DESC=		Audio filter tools
REPLAYGAIN_DESC=	Replaygain tools for codecs

AFTEN_DESC=		ATSC A/52 audio encoder
AFTEN_RUN_DEPENDS=	aften:${PORTSDIR}/audio/aften

AACGAIN_DESC=		AAC audio replaygain
AACGAIN_RUN_DEPENDS=	aacgain:${PORTSDIR}/audio/aacgain

FAAC_RUN_DEPENDS=	faac:${PORTSDIR}/audio/faac \
			faad:${PORTSDIR}/audio/faad

FFMPEG_RUN_DEPENDS=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg

FLAC_RUN_DEPENDS=	flac:${PORTSDIR}/audio/flac

FLAKE_DESC=		FLAC audio codec
FLAKE_RUN_DEPENDS=	flake:${PORTSDIR}/audio/flake

FLUIDSYNTH_DESC=	SoundFont 2 audio codec
FLUIDSYNTH_RUN_DEPENDS=	fluidsynth:${PORTSDIR}/audio/fluidsynth

LAME_RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame

.if defined(NOT_IMPLEMENTED)
LIBAV_DESCR=		LibAV support (WMA, AIFF, AC3, APE...)
LIBAV_RUN_DEPENDS=	avconv:${PORTSDIR}/audio/libav
.endif

MAC_DESC=		Monkey's Audio lossless codec
MAC_RUN_DEPENDS=	mac:${PORTSDIR}/audio/mac

MP3GAIN_DESC=		MP3 audio replaygain
MP3GAIN_RUN_DEPENDS=	mp3gain:${PORTSDIR}/audio/mp3gain

MPLAYER_RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

MUSEPACK_RUN_DEPENDS=	mpcenc:${PORTSDIR}/audio/musepack

NEROAAC_DESC=		Nero AAC MPEG-3 and 3GPP audio codec
NEROAAC_RUN_DEPENDS=	neroAacEnc:${PORTSDIR}/audio/linux-neroaaccodec

NORMALIZE_DESC=		MP3/Ogg Vorbis audio filter and replaygain
NORMALIZE_RUN_DEPENDS=	normalize:${PORTSDIR}/audio/normalize

OPUSTOOLS_DESC=		Opus audio codec
OPUSTOOLS_RUN_DEPENDS=	opusenc:${PORTSDIR}/audio/opus-tools

SHORTEN_DESC=		Shorten (lossless) audio codec
SHORTEN_RUN_DEPENDS=	shorten:${PORTSDIR}/audio/shorten

SOX_DESC=		Universal sound sample translator
SOX_RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox

SPEEX_RUN_DEPENDS=	speexenc:${PORTSDIR}/audio/speex

TIMIDITY_DESC=		MIDI audio decoder
TIMIDITY_RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

TTA_DESC=		True Audio lossless audio codec
TTA_RUN_DEPENDS=	ttaenv:${PORTSDIR}/audio/tta

TWOLAME_RUN_DEPENDS=	twolame:${PORTSDIR}/audio/twolame

VORBISGAIN_DESC=	Ogg Vorbis audio replaygain
VORBISGAIN_RUN_DEPENDS=	vorbisgain:${PORTSDIR}/audio/vorbisgain

VORBIS_RUN_DEPENDS=	oggenc:${PORTSDIR}/audio/vorbis-tools

WAVPACK_RUN_DEPENDS=	wavpack:${PORTSDIR}/audio/wavpack

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DBUILD_po=FALSE

.include <bsd.port.mk>
