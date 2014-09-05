# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	soundkonverter
DISTVERSION=	2.1.1
PORTREVISION=	3
CATEGORIES=	audio kde
MASTER_SITES=	GH LOCAL/dbn/${PORTNAME}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Frontend to various audio converters (transcoder)

LICENSE=	GPLv3

LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib \
		libcdda_paranoia.so:${PORTSDIR}/audio/cdparanoia

GH_ACCOUNT=	HessiJames
GH_TAGNAME=	v${DISTVERSION}
GH_COMMIT=	b2c3436
USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs libkcddb
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
AFTEN_RUN_DEPENDS=	aften:${PORTSDIR}/audio/aften

AACGAIN_DESC=		AAC audio replaygain
AACGAIN_RUN_DEPENDS=	aacgain:${PORTSDIR}/audio/aacgain

CDPARANOIA_DESC=	CD ripping support (cdparanoia - implicit)

CDRKIT_DESC=		CD ripping support (cdrkit)
CDRKIT_RUN_DEPENDS=	icedax:${PORTSDIR}/sysutils/cdrkit

FAAC_RUN_DEPENDS=	faac:${PORTSDIR}/audio/faac \
			faad:${PORTSDIR}/audio/faad

FFMPEG_RUN_DEPENDS=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg

FLAC_RUN_DEPENDS=	flac:${PORTSDIR}/audio/flac

FLAKE_DESC=		FLAC audio codec
FLAKE_RUN_DEPENDS=	flake:${PORTSDIR}/audio/flake

FLUIDSYNTH_DESC=	SoundFont 2 audio codec
FLUIDSYNTH_RUN_DEPENDS=	fluidsynth:${PORTSDIR}/audio/fluidsynth

LAME_RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame

LIBAV_DESCR=		LibAV support (WMA, AIFF, AC3, APE...)
LIBAV_RUN_DEPENDS=	avconv:${PORTSDIR}/multimedia/libav

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

TTA_RUN_DEPENDS=	ttaenv:${PORTSDIR}/audio/tta

TWOLAME_RUN_DEPENDS=	twolame:${PORTSDIR}/audio/twolame

VORBISGAIN_DESC=	Ogg Vorbis audio replaygain
VORBISGAIN_RUN_DEPENDS=	vorbisgain:${PORTSDIR}/audio/vorbisgain

VORBIS_RUN_DEPENDS=	oggenc:${PORTSDIR}/audio/vorbis-tools

WAVPACK_RUN_DEPENDS=	wavpack:${PORTSDIR}/audio/wavpack

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DBUILD_po=FALSE

.include <bsd.port.mk>
