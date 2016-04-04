# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	soundkonverter
PORTVERSION=	2.1.90
DISTVERSIONPREFIX=	v
CATEGORIES=	audio kde

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Frontend to various audio converters (transcoder)

LICENSE=	GPLv2

LIB_DEPENDS=	libtag.so:audio/taglib \
		libcdda_paranoia.so:audio/cdparanoia

GH_ACCOUNT=	HessiJames
USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdeprefix kdelibs libkcddb
INSTALLS_ICONS=	yes
WRKSRC_SUBDIR=	src

OPTIONS_DEFAULT=	VORBISTOOLS FLAC NORMALIZE VORBISGAIN CDPARANOIA
OPTIONS_DEFINE=	NLS
OPTIONS_GROUP=	RIPPER
OPTIONS_MULTI=	CODEC FILTER REPLAYGAIN
OPTIONS_GROUP_RIPPER=	CDRKIT CDPARANOIA
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
RIPPER_DESC=		CD ripping tools

AFTEN_DESC=		ATSC A/52 audio encoder
AFTEN_RUN_DEPENDS=	aften:audio/aften

AACGAIN_DESC=		AAC audio replaygain
AACGAIN_RUN_DEPENDS=	aacgain:audio/aacgain

CDPARANOIA_DESC=	CD ripping support (cdparanoia - implicit)

CDRKIT_DESC=		CD ripping support (cdrkit)
CDRKIT_RUN_DEPENDS=	icedax:sysutils/cdrkit

FAAC_RUN_DEPENDS=	faac:audio/faac \
			faad:audio/faad

FFMPEG_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

FLAC_RUN_DEPENDS=	flac:audio/flac

FLAKE_DESC=		FLAC audio codec
FLAKE_RUN_DEPENDS=	flake:audio/flake

FLUIDSYNTH_DESC=	SoundFont 2 audio codec
FLUIDSYNTH_RUN_DEPENDS=	fluidsynth:audio/fluidsynth

LAME_RUN_DEPENDS=	lame:audio/lame

LIBAV_DESCR=		LibAV support (WMA, AIFF, AC3, APE...)
LIBAV_RUN_DEPENDS=	avconv:multimedia/libav

MAC_DESC=		Monkey's Audio lossless codec
MAC_RUN_DEPENDS=	mac:audio/mac

MP3GAIN_DESC=		MP3 audio replaygain
MP3GAIN_RUN_DEPENDS=	mp3gain:audio/mp3gain

MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer

MUSEPACK_RUN_DEPENDS=	mpcenc:audio/musepack

NEROAAC_DESC=		Nero AAC MPEG-3 and 3GPP audio codec
NEROAAC_RUN_DEPENDS=	neroAacEnc:audio/linux-neroaaccodec

NORMALIZE_DESC=		MP3/Ogg Vorbis audio filter and replaygain
NORMALIZE_RUN_DEPENDS=	normalize:audio/normalize

OPUSTOOLS_DESC=		Opus audio codec
OPUSTOOLS_RUN_DEPENDS=	opusenc:audio/opus-tools

SHORTEN_DESC=		Shorten (lossless) audio codec
SHORTEN_RUN_DEPENDS=	shorten:audio/shorten

SOX_DESC=		Universal sound sample translator
SOX_RUN_DEPENDS=	sox:audio/sox

SPEEX_RUN_DEPENDS=	speexenc:audio/speex

TIMIDITY_DESC=		MIDI audio decoder
TIMIDITY_RUN_DEPENDS=	timidity:audio/timidity

TTA_RUN_DEPENDS=	ttaenc:audio/tta

TWOLAME_RUN_DEPENDS=	twolame:audio/twolame

VORBISGAIN_DESC=	Ogg Vorbis audio replaygain
VORBISGAIN_RUN_DEPENDS=	vorbisgain:audio/vorbisgain

VORBIS_RUN_DEPENDS=	oggenc:audio/vorbis-tools

WAVPACK_RUN_DEPENDS=	wavpack:audio/wavpack

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DBUILD_po=FALSE

.include <bsd.port.mk>
