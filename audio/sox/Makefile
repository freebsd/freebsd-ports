# Created by: torstenb
# $FreeBSD$

PORTNAME=	sox
PORTVERSION=	14.4.1
PORTREVISION=	1
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
		MAD PNG PULSEAUDIO SNDFILE VORBIS WAVPACK
OPTIONS_DEFAULT=	AO FFMPEG FLAC GSM ID3TAG MAD PNG SNDFILE VORBIS
# Default LAME to off for packages so we don't end up RESTRICTED
.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	LAME
.endif

AMRNB_DESC=	AMR Speech Codec (Narrowband)
AMRWB_DESC=	AMR Speech Codec (Wideband)
GSM_DESC=	Use libgsm from ports (else use bundled lib)
PNG_DESC=	PNG spectrogram creation

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS+=	--with-pkgconfigdir="${PREFIX}/libdata/pkgconfig"
CONFIGURE_ARGS+=	--with-distro="${CONFIGURE_TARGET} ${PKGNAME}" \
			--with-gsm

ALSA_CONFIGURE_WITH=	alsa
ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins

AO_CONFIGURE_WITH=	ao
AO_LIB_DEPENDS=		libao.so:${PORTSDIR}/audio/libao

AMRNB_CONFIGURE_WITH=	amrnb
AMRNB_LIB_DEPENDS=	libamrnb.so:${PORTSDIR}/audio/libamrnb

AMRWB_CONFIGURE_WITH=	amrwb
AMRWB_LIB_DEPENDS=	libamrwb.so:${PORTSDIR}/audio/libamrwb

FFMPEG_CONFIGURE_WITH=	ffmpeg
FFMPEG_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg

VORBIS_CONFIGURE_WITH=	oggvorbis
VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis

SNDFILE_CONFIGURE_WITH=	sndfile
SNDFILE_LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile

LADSPA_CONFIGURE_WITH=	ladspa
LADSPA_RUN_DEPENDS=	${LOCALBASE}/lib/ladspa/filter.so:${PORTSDIR}/audio/ladspa
LADSPA_BUILD_DEPENDS=	${LOCALBASE}/lib/ladspa/filter.so:${PORTSDIR}/audio/ladspa

LAME_CONFIGURE_WITH=	lame
LAME_LIB_DEPENDS=	libmp3lame.so:${PORTSDIR}/audio/lame

FLAC_CONFIGURE_WITH=	flac
FLAC_LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac

MAD_CONFIGURE_WITH=	mad
MAD_LIB_DEPENDS=	libmad.so:${PORTSDIR}/audio/libmad

PNG_CONFIGURE_WITH=	png
PNG_LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

PULSEAUDIO_CONFIGURE_WITH=	pulseaudio
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio

GSM_LIB_DEPENDS=	libgsm.so:${PORTSDIR}/audio/gsm

ID3TAG_CONFIGURE_WITH=	id3tag
ID3TAG_LIB_DEPENDS=	libid3tag.so:${PORTSDIR}/audio/libid3tag

WAVPACK_CONFIGURE_WITH=	wavpack
WAVPACK_LIB_DEPENDS=	libwavpack.so:${PORTSDIR}/audio/wavpack

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MGSM}
# We cannot ask for gsm to be enabled without it trying to use external gsm,
# so force the autoconf checks to fail
CONFIGURE_ENV+=	ac_cv_header_gsm_h=no ac_cv_header_gsm_gsm_h=no \
		ac_cv_lib_gsm_gsm_create=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/ CODEC_ID/ AV_CODEC_ID/g' \
		-e 's/ CodecID/ AVCodecID/g' \
		${WRKSRC}/src/ffmpeg.c

.include <bsd.port.mk>
