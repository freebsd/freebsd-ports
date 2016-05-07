# Created by: torstenb
# $FreeBSD$

PORTNAME=	sox
PORTVERSION=	14.4.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF

PATCHFILES=	0001-Remove-pure-attribute-from-functions-with-side-effec.patch:-p1
PATCH_SITES=	https://sourceforge.net/p/sox/patches/104/attachment/

MAINTAINER=	dnelson@allantgroup.com
COMMENT=	SOund eXchange - universal sound sample translator

LICENSE=	LGPL21 GPLv2
LICENSE_COMB=	dual

LIB_DEPENDS=	libltdl.so:devel/libltdl

CONFLICTS=	play-[0-9]*

GNU_CONFIGURE=	yes
USES=		autoreconf pkgconfig libtool
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	ALSA AO AMRNB AMRWB FLAC GSM ID3TAG LADSPA LAME \
		MAD OPUS PNG PULSEAUDIO SNDFILE TWOLAME VORBIS WAVPACK
OPTIONS_DEFAULT=	AO FLAC GSM ID3TAG MAD OPUS PNG SNDFILE VORBIS
# Default LAME to off for packages so we don't end up RESTRICTED
.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	LAME
.endif

AMRNB_DESC=	AMR Speech Codec (Narrowband)
AMRWB_DESC=	AMR Speech Codec (Wideband)
GSM_DESC=	Use libgsm from ports (else use bundled lib)
PNG_DESC=	PNG spectrogram creation

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-pkgconfigdir="${PREFIX}/libdata/pkgconfig"
CONFIGURE_ARGS+=	--with-distro="${CONFIGURE_TARGET} ${PKGNAME}"
CONFIGURE_ARGS+=	--with-gsm
CONFIGURE_ARGS+=	--disable-stack-protector

ALSA_CONFIGURE_WITH=	alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins

AO_CONFIGURE_WITH=	ao
AO_LIB_DEPENDS=		libao.so:audio/libao

AMRNB_CONFIGURE_WITH=	amrnb
AMRNB_LIB_DEPENDS=	libamrnb.so:audio/libamrnb

AMRWB_CONFIGURE_WITH=	amrwb
AMRWB_LIB_DEPENDS=	libamrwb.so:audio/libamrwb

VORBIS_CONFIGURE_WITH=	oggvorbis
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis

SNDFILE_CONFIGURE_WITH=	sndfile
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile

LADSPA_CONFIGURE_WITH=	ladspa
LADSPA_RUN_DEPENDS=	${LOCALBASE}/lib/ladspa/filter.so:audio/ladspa
LADSPA_BUILD_DEPENDS=	${LOCALBASE}/lib/ladspa/filter.so:audio/ladspa

LAME_CONFIGURE_WITH=	lame
LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame

FLAC_CONFIGURE_WITH=	flac
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac

MAD_CONFIGURE_WITH=	mad
MAD_LIB_DEPENDS=	libmad.so:audio/libmad

PNG_CONFIGURE_WITH=	png
PNG_LIB_DEPENDS=	libpng.so:graphics/png

PULSEAUDIO_CONFIGURE_WITH=	pulseaudio
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

GSM_LIB_DEPENDS=	libgsm.so:audio/gsm

ID3TAG_CONFIGURE_WITH=	id3tag
ID3TAG_LIB_DEPENDS=	libid3tag.so:audio/libid3tag

WAVPACK_CONFIGURE_WITH=	wavpack
WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack

TWOLAME_CONFIGURE_WITH=	twolame
TWOLAME_LIB_DEPENDS=	libtwolame.so:audio/twolame

OPUS_CONFIGURE_WITH=	opus
OPUS_LIB_DEPENDS=	libopusfile.so:audio/opusfile

# We cannot ask for gsm to be enabled without it trying to use external gsm,
# so force the autoconf checks to fail
GSM_CONFIGURE_ENV_OFF=	ac_cv_header_gsm_h=no ac_cv_header_gsm_gsm_h=no \
		ac_cv_lib_gsm_gsm_create=no

INSTALL_TARGET=		install-strip

.include <bsd.port.mk>
