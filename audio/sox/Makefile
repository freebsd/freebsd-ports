PORTNAME=	sox
DISTVERSION=	14.4.2.20210509
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://dev.gentoo.org/~fordfrog/distfiles/
DISTNAME=	sox-code-42b3557e13e0fe01a83465b672d89faddbe65f49

MAINTAINER=	dnelson@allantgroup.com
COMMENT=	SOund eXchange - universal sound sample translator
WWW=		http://sox.sourceforge.net/

LICENSE=	LGPL21 GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive
LIB_DEPENDS=	libltdl.so:devel/libltdl

CONFLICTS=	play

USES=		autoreconf cpe libtool localbase:ldflags pkgconfig zip
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_DEFINE=	AMRNB AMRWB FLAC GSM ID3TAG LADSPA LAME MAD OPUS PNG \
		SNDFILE TWOLAME VORBIS WAVPACK
OPTIONS_DEFAULT=	AO FLAC GSM ID3TAG LAME MAD OPUS OSS PNG SNDFILE VORBIS
OPTIONS_GROUP=	SOUND
OPTIONS_GROUP_SOUND=	ALSA AO OSS PULSEAUDIO SNDIO

AMRNB_DESC=	AMR Speech Codec (Narrowband)
AMRWB_DESC=	AMR Speech Codec (Wideband)
PNG_DESC=	PNG spectrogram creation

CONFIGURE_ARGS=	--with-pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		--with-distro="${CONFIGURE_TARGET} ${PKGNAME}" \
		--disable-stack-protector --disable-static

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

OSS_CONFIGURE_WITH=	oss

PNG_CONFIGURE_WITH=	png
PNG_LIB_DEPENDS=	libpng.so:graphics/png

PULSEAUDIO_CONFIGURE_WITH=	pulseaudio
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

SNDIO_CONFIGURE_WITH=	sndio
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio

GSM_CONFIGURE_WITH=	gsm libgsm
GSM_LIB_DEPENDS=	libgsm.so:audio/gsm

ID3TAG_CONFIGURE_WITH=	id3tag
ID3TAG_LIB_DEPENDS=	libid3tag.so:audio/libid3tag

WAVPACK_CONFIGURE_WITH=	wavpack
WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack

TWOLAME_CONFIGURE_WITH=	twolame
TWOLAME_LIB_DEPENDS=	libtwolame.so:audio/twolame

OPUS_CONFIGURE_WITH=	opus
OPUS_LIB_DEPENDS=	libopusfile.so:audio/opusfile

INSTALL_TARGET=		install-strip

post-patch:
	# rename sox's custom EX/EE macros so they don't get overridden by
	# the default ones
	${REINPLACE_CMD} \
		-e 's/EX$$/soxEX/' \
		-e 's/EE$$/soxEE/' \
		${WRKSRC}/*.[0-9]

.include <bsd.port.mk>
