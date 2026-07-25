PORTNAME=	sox
DISTVERSION=	14.4.2.20210509
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	https://dev.gentoo.org/~fordfrog/distfiles/
DISTNAME=	sox-code-42b3557e13e0fe01a83465b672d89faddbe65f49

MAINTAINER=	dnelson@allantgroup.com
COMMENT=	SOund eXchange - universal sound sample translator
WWW=		https://sox.sourceforge.net/

LICENSE=	LGPL21 GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive
LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		autoreconf cpe libtool localbase:ldflags pkgconfig zip
USE_LDCONFIG=	yes

CONFLICTS=	play
WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--with-pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		--with-distro="${CONFIGURE_TARGET} ${PKGNAME}" \
		--disable-static --disable-mp3 --without-vo-amrwbenc

OPTIONS_DEFINE=	AMR FLAC GSM ID3TAG LADSPA OPUS PNG \
		SNDFILE SYMLINK VORBIS WAVPACK
OPTIONS_DEFAULT=	AO FLAC GSM ID3TAG LAME MAD OPUS OSS PNG \
			SNDFILE SYMLINK VORBIS
OPTIONS_GROUP=	MP3 SOUND
OPTIONS_GROUP_MP3=	LAME MAD TWOLAME
OPTIONS_GROUP_SOUND=	ALSA AO OSS PULSEAUDIO SNDIO
OPTIONS_SUB=	yes

PNG_DESC=	PNG spectrogram creation
SYMLINK_DESC=	Create soxi/play/rec links

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
ALSA_CONFIGURE_ENABLE=	alsa

AMR_LIB_DEPENDS=	libopencore-amrnb.so:audio/opencore-amr
AMR_CONFIGURE_ENABLE=	amrnb amrwb
AMR_CONFIGURE_WITH=	opencore-amrnb opencore-amrwb

AO_LIB_DEPENDS=		libao.so:audio/libao
AO_CONFIGURE_ENABLE=	ao

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_ENABLE=	flac

GSM_LIB_DEPENDS=	libgsm.so:audio/gsm
GSM_CONFIGURE_ENABLE=	gsm
GSM_CONFIGURE_WITH=	libgsm

ID3TAG_LIB_DEPENDS=	libid3tag.so:audio/libid3tag
ID3TAG_CONFIGURE_WITH=	id3tag

LADSPA_BUILD_DEPENDS=	${LOCALBASE}/lib/ladspa/filter.so:audio/ladspa
LADSPA_RUN_DEPENDS=	${LOCALBASE}/lib/ladspa/filter.so:audio/ladspa
LADSPA_CONFIGURE_WITH=	ladspa

LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
LAME_CONFIGURE_ON=	--enable-mp3
LAME_CONFIGURE_WITH=	lame

MAD_LIB_DEPENDS=	libmad.so:audio/libmad
MAD_CONFIGURE_ON=	--enable-mp3
MAD_CONFIGURE_WITH=	mad

OPUS_LIB_DEPENDS=	libopusfile.so:audio/opusfile
OPUS_CONFIGURE_ENABLE=	opus

OSS_CONFIGURE_ENABLE=	oss

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_WITH=	png

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulseaudio

SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CONFIGURE_ENABLE=	sndfile
SNDFILE_CONFIGURE_WITH=	libsndfile

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_ENABLE=	sndio

SYMLINK_CONFIGURE_ENABLE=	symlinks

TWOLAME_LIB_DEPENDS=	libtwolame.so:audio/twolame
TWOLAME_CONFIGURE_ON=	--enable-mp3
TWOLAME_CONFIGURE_WITH=	twolame

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_CONFIGURE_ENABLE=	oggvorbis

WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_CONFIGURE_ENABLE=	wavpack

post-patch:
	# rename sox's custom EX/EE macros so they don't get overridden by
	# the default ones
	${REINPLACE_CMD} \
		-e 's/EX$$/soxEX/' \
		-e 's/EE$$/soxEE/' \
		${WRKSRC}/*.[0-9]

.include <bsd.port.mk>
