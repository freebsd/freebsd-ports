# New ports collection makefile for:	sox - Sound Exchange
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	sox
PORTVERSION=	14.3.0
PORTREVISION=	5
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

# Default LAME to off for packages so we don't end up RESTRICTED
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
		ID3TAG "Enable mp3 tagging with libid3tag" on \
		LADSPA "Audio plugin support" off \
		LAME "Enable mp3 encoding with LAME" ${_LAME} \
		MAD "Enable mp3 decoding with MAD" on \
		PNG "Enable PNG spectrogram creation" on \
		SNDFILE "Enable libsndfile" on \
		VORBIS "Enable Ogg Vorbis support" on \
		WAVPACK "Enable Wavpack support" off

.include <bsd.port.pre.mk>

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	--with-pkgconfigdir="${PREFIX}/libdata/pkgconfig"
CONFIGURE_ARGS+=	--with-distro="${CONFIGURE_TARGET} ${PKGNAME}"

.if defined(WITH_AO)
CONFIGURE_ARGS+=	--with-ao
LIB_DEPENDS+=		ao.4:${PORTSDIR}/audio/libao
.else
CONFIGURE_ARGS+=	--without-ao
.endif

.if defined(WITH_AMRNB)
CONFIGURE_ARGS+=	--with-amrnb
LIB_DEPENDS+=		amrnb.3:${PORTSDIR}/audio/libamrnb
.else
CONFIGURE_ARGS+=	--without-amrnb
.endif

.if defined(WITH_AMRWB)
CONFIGURE_ARGS+=	--with-amrwb
LIB_DEPENDS+=		amrwb.3:${PORTSDIR}/audio/libamrwb
.else
CONFIGURE_ARGS+=	--without-amrwb
.endif

.if defined(WITH_FFMPEG)
CONFIGURE_ARGS+=	--with-ffmpeg
LIB_DEPENDS+=		avformat:${PORTSDIR}/multimedia/ffmpeg
.else
CONFIGURE_ARGS+=	--without-ffmpeg
.endif

.if defined(WITH_VORBIS)
CONFIGURE_ARGS+=	--with-oggvorbis
LIB_DEPENDS+=		vorbis.4:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--without-oggvorbis
.endif

.if defined(WITH_SNDFILE)
CONFIGURE_ARGS+=	--with-sndfile
LIB_DEPENDS+=		sndfile.1:${PORTSDIR}/audio/libsndfile
.else
CONFIGURE_ARGS+=	--without-sndfile
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
.else
CONFIGURE_ARGS+=	--without-flac
.endif

.if defined(WITH_MAD)
CONFIGURE_ARGS+=	--with-mad
LIB_DEPENDS+=		mad.2:${PORTSDIR}/audio/libmad
.else
CONFIGURE_ARGS+=	--without-mad
.endif

.if defined(WITH_PNG)
CONFIGURE_ARGS+=	--with-png
LIB_DEPENDS+=		png.6:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=	--without-png
.endif

.if defined(WITH_GSM)
CONFIGURE_ARGS+=	--with-gsm
LIB_DEPENDS+=		gsm.1:${PORTSDIR}/audio/gsm
.else
CONFIGURE_ARGS+=	--with-gsm
# We cannot ask for gsm to be enabled without it trying to use external gsm,
# so workaround with the below line
CONFIGURE_ENV+=		ac_cv_header_gsm_h=no
.endif

.if defined(WITH_ID3TAG)
CONFIGURE_ARGS+=	--with-id3tag
LIB_DEPENDS+=		id3tag.0:${PORTSDIR}/audio/libid3tag
.else
CONFIGURE_ARGS+=	--without-id3tag
.endif

.if defined(WITH_WAVPACK)
CONFIGURE_ARGS+=	--with-wavpack
LIB_DEPENDS+=		wavpack.2:${PORTSDIR}/audio/wavpack
.else
CONFIGURE_ARGS+=	--without-wavpack
.endif

# Tell configure that libgsm's headers are in $LOCALDIR/include
post-patch:
	@${REINPLACE_CMD} -Ee 's![[:<:]]gsm/gsm.h!gsm.h!' ${WRKSRC}/configure \
		${WRKSRC}/src/gsm.c ${WRKSRC}/src/wav.c
	@${REINPLACE_CMD} -Ee 's!ffmpeg/avformat.h!libavformat/avformat.h!' \
		${WRKSRC}/configure ${WRKSRC}/src/ffmpeg.c

.include <bsd.port.post.mk>
