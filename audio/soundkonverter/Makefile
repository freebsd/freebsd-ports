# New ports collection makefile for:	soundkonverter
# Date created:				2011/01/01
# Whom:					David Naylor <naylor.b.david@gmail.com>
#
# $FreeBSD$

PORTNAME=	soundkonverter
DISTVERSION=	0.9.94rc2
PORTREVISION=	1
CATEGORIES=	audio kde
MASTER_SITES=	https://api.opensuse.org/public/source/home:HessiJames/soundkonverter/

MAINTAINER=	naylor.b.david@gmail.com
COMMENT=	Frontend to various audio converters (transcoder)

LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib \
		cdda_paranoia:${PORTSDIR}/audio/cdparanoia \
		kcddb:${PORTSDIR}/multimedia/kdemultimedia4

USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs
INSTALLS_ICONS=	yes

MAKE_JOBS_SAFE=	yes

OPTIONS=	LAME "Codec: mp3 (audio/lame)" OFF \
		TWOLAME "Codec: mp2 (audo/twolame)" OFF \
		VORBIS_TOOLS "Codec: ogg-vorbis (audio/vorbis-tools" ON \
		FFMPEG "Codec: various (multimedia/ffmpeg)" OFF \
		MAC "Codec: mac (audio/mac)" OFF \
		MPLAYER "Codec: various (multimedia/mplayer)" OFF \
		FAA "Codec: mpeg2 and mpeg4 AAC (audio/faa(cd))" OFF \
		SHORTEN "Codec: shorten (audio/shorten)" OFF \
		TIMIDITY "Decoder: midi (audio/timidity)" OFF \
		\
		FLAC "Codec/replaygain: flac (audio/flac)" ON \
		MUSEPACK "Codec/replaygain: musepack (audio/musepack)" OFF \
		WAVPACK "Codec/replaygain: wavpack (audio/wavpack)" OFF \
		\
		VORBISGAIN "Replaygain: ogg-vorbis (audio/vorbisgain)" ON \
		MP3GAIN "Replaygain: mp3 (audio/mp3gain)" OFF \
		AACGAIN "Replaygain: mp3 and AAC (audio/aacgain)" OFF

.include <bsd.port.options.mk>

.if defined(WITH_LAME)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
PLIST_SUB+=	LAME=""
.else
SK_CMAKE_RM+=	codec_lame
PLIST_SUB+=	LAME="@comment "
.endif

.if defined(WITH_TWOLAME)
RUN_DEPENDS+=	twolame:${PORTSDIR}/audio/twolame
PLIST_SUB+=	TWOLAME=""
.else
SK_CMAKE_RM+=	codec_twolame
PLIST_SUB+=	TWOLAME="@comment "
.endif

.if defined(WITH_VORBIS_TOOLS)
RUN_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
PLIST_SUB+=	VORBISTOOLS=""
.else
SK_CMAKE_RM+=	codec_vorbistools
PLIST_SUB+=	VORBISTOOLS="@comment "
.endif

# .if defined(WITH_FLAKE)
# RUN_DEPENDS+=	:${PORTSDIR}/
# PLIST_SUB+=	FLAKE=""
# .else
SK_CMAKE_RM+=	codec_flake
PLIST_SUB+=	FLAKE="@comment "
# .endif

.if defined(WITH_FFMPEG)
RUN_DEPENDS+=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=	FFMPEG=""
.else
SK_CMAKE_RM+=	codec_ffmpeg
PLIST_SUB+=	FFMPEG="@comment "
.endif

.if defined(WITH_MAC)
RUN_DEPENDS+=	mac:${PORTSDIR}/audio/mac
PLIST_SUB+=	MAC=""
.else
SK_CMAKE_RM+=	codec_mac
PLIST_SUB+=	MAC="@comment "
.endif

.if defined(WITH_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
PLIST_SUB+=	MPLAYER=""
.else
SK_CMAKE_RM+=	codec_mplayer
PLIST_SUB+=	MPLAYER="@comment "
.endif

.if defined(WITH_FAA)
RUN_DEPENDS+=	faac:${PORTSDIR}/audio/faac \
		faad:${PORTSDIR}/audio/faad
PLIST_SUB+=	FAAC=""
.else
SK_CMAKE_RM+=	codec_faac
PLIST_SUB+=	FAAC="@comment "
.endif

# .if defined(WITH_NEROAAC)
# RUN_DEPENDS+=	:${PORTSDIR}/
# PLIST_SUB+=	NEROAAC=""
# .else
SK_CMAKE_RM+=	codec_neroaac
PLIST_SUB+=	NEROAAC="@comment "
# .endif

.if defined(WITH_TIMIDITY)
RUN_DEPENDS+=	timidity:${PORTSDIR}/audio/timidity
PLIST_SUB+=	TIMIDITY=""
.else
SK_CMAKE_RM+=	codec_timidity
PLIST_SUB+=	TIMIDITY="@comment "
.endif

.if defined(WITH_SHORTEN)
RUN_DEPENDS+=	shorten:${PORTSDIR}/audio/shorten
PLIST_SUB+=	SHORTEN=""
.else
SK_CMAKE_RM+=	codec_shorten
PLIST_SUB+=	SHORTEN="@comment "
.endif

.if defined(WITH_FLAC)
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
PLIST_SUB+=	FLAC=""
.else
SK_CMAKE_RM+=	codec_flac replaygain_metaflac
PLIST_SUB+=	FLAC="@comment "
.endif

.if defined(WITH_MUSEPACK)
RUN_DEPENDS+=	mpcenc:${PORTSDIR}/audio/musepack
PLIST_SUB+=	MUSEPACK=""
.else
SK_CMAKE_RM+=	codec_musepack replaygain_musepack
PLIST_SUB+=	MUSEPACK="@comment "
.endif

.if defined(WITH_WAVPACK)
RUN_DEPENDS+=	wavpack:${PORTSDIR}/audio/wavpack
PLIST_SUB+=	WAVPACK=""
.else
SK_CMAKE_RM+=	codec_wavpack replaygain_wvgain
PLIST_SUB+=	WAVPACK="@comment "
.endif

.if defined(WITH_VORBISGAIN)
RUN_DEPENDS+=	vorbisgain:${PORTSDIR}/audio/vorbisgain
PLIST_SUB+=	VORBISGAIN=""
.else
SK_CMAKE_RM+=	replaygain_vorbisgain
PLIST_SUB+=	VORBISGAIN="@comment "
.endif

.if defined(WITH_MP3GAIN)
RUN_DEPENDS+=	mp3gain:${PORTSDIR}/audio/mp3gain
PLIST_SUB+=	MP3GAIN=""
.else
SK_CMAKE_RM+=	replaygain_mp3gain
PLIST_SUB+=	MP3GAIN="@comment "
.endif

.if defined(WITH_AACGAIN)
RUN_DEPENDS+=	aacgain:${PORTSDIR}/audio/aacgain
PLIST_SUB+=	AACGAIN=""
.else
SK_CMAKE_RM+=	replaygain_aacgain
PLIST_SUB+=	AACGAIN="@comment "
.endif

post-patch:
.for plugin in ${SK_CMAKE_RM}
	${REINPLACE_CMD} -i "" -e "s|\(.*${plugin}.*\)|#\1|g" ${WRKSRC}/CMakeLists.txt
.endfor

.include <bsd.port.mk>
