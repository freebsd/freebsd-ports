# New ports collection makefile for:	sox - Sound Exchange
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	sox
PORTVERSION=	14.2.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	dnelson@allantgroup.com
COMMENT=	SOund eXchange - universal sound sample translator

CONFLICTS=	play-[0-9]*

MAN1=		sox.1 soxi.1
MAN3=		libsox.3
MAN7=		soxformat.7
MLINKS=		sox.1 play.1 sox.1 rec.1 sox.1 soxeffect.7
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libltdl
USE_GNOME=	pkgconfig

.if defined(PACKAGE_BUILDING)
_LAME=	off
.else
_LAME=	on
.endif

OPTIONS=	AO "Enable libao output" on \
		AMRNB "AMR Speech Codec (Narrowband)" off \
		AMRWB "AMR Speech Codec (Wideband)" off \
		FFMPEG "Enable ffmpeg en/decoding" on \
		FLAC "Enable flac en/decoding with libflac" on \
		GSM "Use libgsm from ports (else use bundled lib)" on \
		LADSPA "Audio plugin support" off \
		LAME "Enable mp3 encoding with LAME" ${_LAME} \
		MAD "Enable mp3 decoding with MAD" on \
		PNG "Enable PNG spectrogram creation" on \
		SAMPLERATE "Enable libsamplerate" on \
		SNDFILE "Enable libsndfile" on \
		VORBIS "Enable Ogg Vorbis support" on \
		WAVPACK "Enable Wavpack support" off

.include <bsd.port.pre.mk>

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	--with-pkgconfigdir="${PREFIX}/libdata/pkgconfig"

.if !defined(WITH_LAME) && !defined(WITH_MAD)
PLIST_SUB+=	PLIST_MP3="@comment "
.else
PLIST_SUB+=	PLIST_MP3=""
.endif

.if defined(WITH_AO)
CONFIGURE_ARGS+=	--enable-libao
LIB_DEPENDS+=		ao.3:${PORTSDIR}/audio/libao
PLIST_SUB+=		PLIST_AO=""
.else
CONFIGURE_ARGS+=	--disable-libao
PLIST_SUB+=		PLIST_AO="@comment "
.endif

.if defined(WITH_AMRNB)
CONFIGURE_ARGS+=	--with-amr-nb
LIB_DEPENDS+=		amrnb.3:${PORTSDIR}/audio/libamrnb
PLIST_SUB+=		PLIST_AMRNB=""
.else
CONFIGURE_ARGS+=	--without-amr-nb
PLIST_SUB+=		PLIST_AMRNB="@comment "
.endif

.if defined(WITH_AMRWB)
CONFIGURE_ARGS+=	--with-amr-wb
LIB_DEPENDS+=		amrwb.3:${PORTSDIR}/audio/libamrwb
PLIST_SUB+=		PLIST_AMRWB=""
.else
CONFIGURE_ARGS+=	--without-amr-wb
PLIST_SUB+=		PLIST_AMRWB="@comment "
.endif

.if defined(WITH_FFMPEG)
CONFIGURE_ARGS+=	--with-ffmpeg
LIB_DEPENDS+=		avformat:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=		PLIST_FFMPEG=""
.else
CONFIGURE_ARGS+=	--without-ffmpeg
PLIST_SUB+=		PLIST_FFMPEG="@comment "
.endif

.if defined(WITH_VORBIS)
CONFIGURE_ARGS+=	--with-ogg
LIB_DEPENDS+=		vorbis.4:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=		PLIST_VORBIS=""
.else
CONFIGURE_ARGS+=	--without-ogg
PLIST_SUB+=		PLIST_VORBIS="@comment "
.endif

.if defined(WITH_SNDFILE)
CONFIGURE_ARGS+=	--with-sndfile
LIB_DEPENDS+=		sndfile.1:${PORTSDIR}/audio/libsndfile
PLIST_SUB+=		PLIST_SNDFILE=""
.else
CONFIGURE_ARGS+=	--without-sndfile
PLIST_SUB+=		PLIST_SNDFILE="@comment "
.endif

.if defined(WITH_LADSPA)
CONFIGURE_ARGS+=	--with-ladspa
RUN_DEPENDS+=		${LOCALBASE}/lib/ladspa/filter.so:${PORTSDIR}/audio/ladspa
BUILD_DEPENDS+=		${LOCALBASE}/lib/ladspa/filter.so:${PORTSDIR}/audio/ladspa
.else
CONFIGURE_ARGS+=	--without-ladspa
.endif

.if defined(WITH_LAME)
CONFIGURE_ARGS+=	--with-lame
LIB_DEPENDS+=		mp3lame.0:${PORTSDIR}/audio/lame
.else
CONFIGURE_ARGS+=	--without-lame
.endif

.if defined(WITH_FLAC)
CONFIGURE_ARGS+=	--with-flac
LIB_DEPENDS+=		FLAC.10:${PORTSDIR}/audio/flac
PLIST_SUB+=		PLIST_FLAC=""
.else
CONFIGURE_ARGS+=	--without-flac
PLIST_SUB+=		PLIST_FLAC="@comment "
.endif

.if defined(WITH_MAD)
CONFIGURE_ARGS+=	--with-mad
LIB_DEPENDS+=		mad.2:${PORTSDIR}/audio/libmad
.else
CONFIGURE_ARGS+=	--without-mad
.endif

.if defined(WITH_PNG)
CONFIGURE_ARGS+=	--with-png
LIB_DEPENDS+=		png.5:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=	--without-png
.endif

.if defined(WITH_GSM)
CONFIGURE_ARGS+=	--with-external-gsm
LIB_DEPENDS+=		gsm.1:${PORTSDIR}/audio/gsm
PLIST_SUB+=		PLIST_GSM=""
.else
CONFIGURE_ARGS+=	--without-external-gsm
# Above configure flag does not exist, so workaround with the below line
CONFIGURE_ENV+=		ac_cv_header_gsm_h=no
PLIST_SUB+=		PLIST_GSM="@comment "
.endif

.if defined(WITH_SAMPLERATE)
CONFIGURE_ARGS+=	--with-samplerate
LIB_DEPENDS+=		samplerate.1:${PORTSDIR}/audio/libsamplerate
.else
CONFIGURE_ARGS+=	--without-samplerate
.endif

.if defined(WITH_WAVPACK)
CONFIGURE_ARGS+=	--with-wavpack
LIB_DEPENDS+=		wavpack.1:${PORTSDIR}/audio/wavpack
PLIST_SUB+=		PLIST_WAVPACK=""
.else
CONFIGURE_ARGS+=	--without-wavpack
PLIST_SUB+=		PLIST_WAVPACK="@comment "
.endif

# Tell configure that libgsm's headers are in $LOCALDIR/include
post-patch:
	@${REINPLACE_CMD} -Ee 's![[:<:]]gsm/gsm.h!gsm.h!' ${WRKSRC}/configure \
		${WRKSRC}/src/gsm.c ${WRKSRC}/src/wav.c
	@${REINPLACE_CMD} -Ee 's!ffmpeg/avformat.h!libavformat/avformat.h!' \
		${WRKSRC}/configure ${WRKSRC}/src/ffmpeg.c

.include <bsd.port.post.mk>
