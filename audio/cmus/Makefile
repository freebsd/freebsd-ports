# Created by: Adam Weinberger

PORTNAME=	cmus
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.1
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console-based music player with really cool features

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gmake iconv ncurses pkgconfig
USE_GITHUB=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	prefix=${PREFIX} mandir=${MANPREFIX}/man \
		exampledir=${EXAMPLESDIR}
# So the build does not use gcc for compiling ttman
CONFIGURE_ARGS+=	HOSTCC=${CC}

# Verbose build makes it easier to spot problems
MAKE_ARGS=	ICONV_CFLAGS="-I${ICONV_INCLUDE_PATH}" \
		ICONV_LIBS="-L${ICONV_PREFIX}/lib ${ICONV_LIB}" \
		V=2

# Disable all configure options first.  These will be overwritten by
# enabled port options later.  The args to cmus' configure script
# follow shell value semantics i.e. later assignments overwrite
# previous assignments.  The options here appear in the same order as
# ${WRKSRC}/configure --help.  Please keep it that way.
_CMUS_CONFIGURE_OPTS=	AAC ALSA AO ARTS CDDB CDIO COREAUDIO CUE DISCID	\
	FFMPEG FLAC JACK MAD MIKMOD BASS MODPLUG MP4 MPC MPRIS OPUS OSS	\
	PULSE ROAR SAMPLERATE SNDIO SUN TREMOR VORBIS VTX WAVEOUT	\
	WAVPACK WAV
.for opt in ${_CMUS_CONFIGURE_OPTS}
CONFIGURE_ARGS+=	CONFIG_${opt}=n
.endfor

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_DEFAULT=	AAC FFMPEG FLAC MODPLUG MP4 OPUS OSS SNDIO VORBIS WAV
OPTIONS_SUB=	yes

OPTIONS_GROUP=	OUT IN
OPTIONS_GROUP_OUT=	AO JACK OSS PULSEAUDIO SNDIO
OPTIONS_GROUP_IN=	AAC CDDB CDIO CUE DISCID FFMPEG FLAC MAD MIKMOD	\
			MODPLUG MP4 MUSEPACK OPUS SAMPLERATE TREMOR	\
			VORBIS WAV WAVPACK

DISCID_DESC=	libdiscid CDDA identification support
IN_DESC=	Input plugins
OUT_DESC=	Output plugins

AAC_CONFIGURE_ON=	CONFIG_AAC=y
AAC_LIB_DEPENDS=	libfaad.so:audio/faad

AO_CONFIGURE_ON=	CONFIG_AO=y
AO_LIB_DEPENDS=	libao.so:audio/libao

CDDB_CONFIGURE_ON=	CONFIG_CDDB=y
CDDB_LIB_DEPENDS=	libcddb.so:audio/libcddb

CDIO_CONFIGURE_ON=	CONFIG_CDIO=y
CDIO_LIB_DEPENDS=	libcdio_cdda.so:sysutils/libcdio-paranoia \
			libcdio.so:sysutils/libcdio

CUE_CONFIGURE_ON=	CONFIG_CUE=y
CUE_LIB_DEPENDS=	libcue.so:textproc/libcue

DISCID_CONFIGURE_ON=	CONFIG_DISCID=y
DISCID_LIB_DEPENDS=	libdiscid.so:audio/libdiscid

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ON=	CONFIG_FFMPEG=y

FLAC_CONFIGURE_ON=	CONFIG_FLAC=y
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac

JACK_CONFIGURE_ON=	CONFIG_JACK=y
JACK_LIB_DEPENDS=	libjack.so:audio/jack

MAD_CONFIGURE_ON=	CONFIG_MAD=y
MAD_LIB_DEPENDS=	libmad.so:audio/libmad

MIKMOD_CONFIGURE_ON=	CONFIG_MIKMOD=y
MIKMOD_LIB_DEPENDS=	libmikmod.so:audio/libmikmod

MODPLUG_CONFIGURE_ON=	CONFIG_MODPLUG=y
MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug

MP4_CONFIGURE_ON=	CONFIG_MP4=y
MP4_LIB_DEPENDS=	libfaad.so:audio/faad \
			libmp4v2.so:multimedia/mp4v2

MUSEPACK_CONFIGURE_ON=	CONFIG_MPC=y
MUSEPACK_LIB_DEPENDS=	libmpcdec.so:audio/musepack

OPUS_CONFIGURE_ON=	CONFIG_OPUS=y
OPUS_LIB_DEPENDS=	libopusfile.so:audio/opusfile

OSS_CONFIGURE_ON=	CONFIG_OSS=y

PULSEAUDIO_CONFIGURE_ON=	CONFIG_PULSE=y
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

# Requires a port of RoarAudio
#ROAR_CONFIGURE_ON=	CONFIG_ROAR=y
#ROAR_LIB_DEPENDS=	????:????

SAMPLERATE_IMPLIES=	JACK
SAMPLERATE_CONFIGURE_ON=	CONFIG_SAMPLERATE=y
SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate

SNDIO_CONFIGURE_ON=	CONFIG_SNDIO=y
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio

TREMOR_IMPLIES=	VORBIS
TREMOR_CONFIGURE_ON=	CONFIG_TREMOR=y
TREMOR_LIB_DEPENDS=	libvorbisidec.so:audio/libtremor

VORBIS_CONFIGURE_ON=	CONFIG_VORBIS=y
VORBIS_LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis

# VTX requires libayemu which isn't ported yet
#VTX_CONFIGURE_ON=	CONFIG_VTX=y
#VTX_LIB_DEPENDS=	libayemu.so:?????

WAV_CONFIGURE_ON=	CONFIG_WAV=y

WAVPACK_CONFIGURE_ON=	CONFIG_WAVPACK=y
WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack

post-patch:
# Doc/cmus.txt is used to generate the man pages.  Fix paths to point
# to the correct directories.
	@${REINPLACE_CMD} \
		-e 's,/usr/share/doc/cmus/examples,${EXAMPLESDIR},g' \
		-e 's,/usr/share/cmus,${DATADIR},g' \
		${WRKSRC}/Doc/cmus.txt

post-configure:
# Prevent passing wrong flags from devel/ncurses' pkg-config file to the build
	@${REINPLACE_CMD} -e 's|-D_POSIX_C_SOURCE=200112L||g; s|-D_XOPEN_SOURCE=600||g' \
		${WRKSRC}/config.mk

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cmus*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/cmus/[io]p/*.so
# Install bash and zsh completion files
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/contrib/cmus.bash-completion \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/_cmus.bash
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/contrib/_cmus \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_cmus

.include <bsd.port.mk>
