# Created by: torstenb
# $FreeBSD$

PORTNAME=	sox
PORTVERSION=	14.4.1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	dnelson@allantgroup.com
COMMENT=	SOund eXchange - universal sound sample translator

LICENSE=	LGPL21 GPLv2
LICENSE_COMB=	dual

CONFLICTS=	play-[0-9]*

GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal autoconf automake libltdl

OPTIONS_DEFINE=	ALSA AO AMRNB AMRWB FFMPEG FLAC GSM ID3TAG LADSPA LAME \
		MAD PNG SNDFILE VORBIS WAVPACK
OPTIONS_DEFAULT=	AO FFMPEG FLAC GSM ID3TAG MAD PNG SNDFILE VORBIS
# Default LAME to off for packages so we don't end up RESTRICTED
.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT=	LAME
.endif

AMRNB_DESC=	AMR Speech Codec (Narrowband)
AMRWB_DESC=	AMR Speech Codec (Wideband)
GSM_DESC=	Use libgsm from ports (else use bundled lib)
PNG_DESC=	PNG spectrogram creation

.include <bsd.port.options.mk>

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS+=	--with-pkgconfigdir="${PREFIX}/libdata/pkgconfig"
CONFIGURE_ARGS+=	--with-distro="${CONFIGURE_TARGET} ${PKGNAME}"

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=		asound.2:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=		${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
CONFIGURE_ARGS+=	--with-alsa
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.if ${PORT_OPTIONS:MAO}
CONFIGURE_ARGS+=	--with-ao
LIB_DEPENDS+=		ao.4:${PORTSDIR}/audio/libao
.else
CONFIGURE_ARGS+=	--without-ao
.endif

.if ${PORT_OPTIONS:MAMRNB}
CONFIGURE_ARGS+=	--with-amrnb
LIB_DEPENDS+=		amrnb.3:${PORTSDIR}/audio/libamrnb
.else
CONFIGURE_ARGS+=	--without-amrnb
.endif

.if ${PORT_OPTIONS:MAMRWB}
CONFIGURE_ARGS+=	--with-amrwb
LIB_DEPENDS+=		amrwb.3:${PORTSDIR}/audio/libamrwb
.else
CONFIGURE_ARGS+=	--without-amrwb
.endif

.if ${PORT_OPTIONS:MFFMPEG}
CONFIGURE_ARGS+=	--with-ffmpeg
LIB_DEPENDS+=		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
.else
CONFIGURE_ARGS+=	--without-ffmpeg
.endif

.if ${PORT_OPTIONS:MVORBIS}
CONFIGURE_ARGS+=	--with-oggvorbis
LIB_DEPENDS+=		vorbis.4:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--without-oggvorbis
.endif

.if ${PORT_OPTIONS:MSNDFILE}
CONFIGURE_ARGS+=	--with-sndfile
LIB_DEPENDS+=		sndfile.1:${PORTSDIR}/audio/libsndfile
.else
CONFIGURE_ARGS+=	--without-sndfile
.endif

.if ${PORT_OPTIONS:MLADSPA}
CONFIGURE_ARGS+=	--with-ladspa
RUN_DEPENDS+=		${LOCALBASE}/lib/ladspa/filter.so:${PORTSDIR}/audio/ladspa
BUILD_DEPENDS+=		${LOCALBASE}/lib/ladspa/filter.so:${PORTSDIR}/audio/ladspa
.else
CONFIGURE_ARGS+=	--without-ladspa
.endif

.if ${PORT_OPTIONS:MLAME}
CONFIGURE_ARGS+=	--with-lame
LIB_DEPENDS+=		mp3lame.0:${PORTSDIR}/audio/lame
.else
CONFIGURE_ARGS+=	--without-lame
.endif

.if ${PORT_OPTIONS:MFLAC}
CONFIGURE_ARGS+=	--with-flac
LIB_DEPENDS+=		FLAC:${PORTSDIR}/audio/flac
.else
CONFIGURE_ARGS+=	--without-flac
.endif

.if ${PORT_OPTIONS:MMAD}
CONFIGURE_ARGS+=	--with-mad
LIB_DEPENDS+=		mad.2:${PORTSDIR}/audio/libmad
.else
CONFIGURE_ARGS+=	--without-mad
.endif

.if ${PORT_OPTIONS:MPNG}
CONFIGURE_ARGS+=	--with-png
LIB_DEPENDS+=		png15:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=	--without-png
.endif

.if ${PORT_OPTIONS:MGSM}
CONFIGURE_ARGS+=	--with-gsm
LIB_DEPENDS+=		gsm.1:${PORTSDIR}/audio/gsm
.else
CONFIGURE_ARGS+=	--with-gsm
# We cannot ask for gsm to be enabled without it trying to use external gsm,
# so force the autoconf checks to fail
CONFIGURE_ENV+=	ac_cv_header_gsm_h=no ac_cv_header_gsm_gsm_h=no \
		ac_cv_lib_gsm_gsm_create=no
.endif

.if ${PORT_OPTIONS:MID3TAG}
CONFIGURE_ARGS+=	--with-id3tag
LIB_DEPENDS+=		id3tag.0:${PORTSDIR}/audio/libid3tag
.else
CONFIGURE_ARGS+=	--without-id3tag
.endif

.if ${PORT_OPTIONS:MWAVPACK}
CONFIGURE_ARGS+=	--with-wavpack
LIB_DEPENDS+=		wavpack.2:${PORTSDIR}/audio/wavpack
.else
CONFIGURE_ARGS+=	--without-wavpack
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/ CODEC_ID/ AV_CODEC_ID/g' \
		-e 's/ CodecID/ AVCodecID/g' \
		${WRKSRC}/src/ffmpeg.c

.include <bsd.port.mk>
