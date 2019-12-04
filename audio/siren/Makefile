# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	siren
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.kariliq.nl/${PORTNAME}/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text-based audio player

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENCE

BROKEN_mips=		fails to configure: cannot find program /nxb-bin/usr/bin/cc
BROKEN_mips64=		fails to configure: cannot find program /nxb-bin/usr/bin/cc

USES=		localbase:ldflags ncurses pkgconfig
HAS_CONFIGURE=	yes
USE_CSTD=	c99

OPTIONS_DEFINE=		FAAD FFMPEG FLAC MAD MPG123 OPUS SNDFILE VORBIS WAVPACK
OPTIONS_MULTI=		SOUND
OPTIONS_MULTI_SOUND=	OSS PULSEAUDIO SNDIO
OPTIONS_DEFAULT=	FFMPEG OSS
OSS_CONFIGURE_ON=	oss=yes
OSS_CONFIGURE_OFF=	oss=no
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ON=	pulse=yes
PULSEAUDIO_CONFIGURE_OFF=	pulse=no
SNDIO_CONFIGURE_ON=	sndio=yes
SNDIO_CONFIGURE_OFF=	sndio=no
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_USES=		localbase:ldflags
FAAD_CONFIGURE_ON=	aac=yes
FAAD_CONFIGURE_OFF=	aac=no
FAAD_LIB_DEPENDS=	libfaad.so:audio/faad \
			libmp4v2.so:multimedia/mp4v2
FFMPEG_CONFIGURE_ON=	ffmpeg=yes
FFMPEG_CONFIGURE_OFF=	ffmpeg=no
FFMPEG_LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg
FLAC_CONFIGURE_ON=	flac=yes
FLAC_CONFIGURE_OFF=	flac=no
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
MAD_CONFIGURE_ON=	mad=yes
MAD_CONFIGURE_OFF=	mad=no
MAD_LIB_DEPENDS=	libmad.so:audio/libmad \
			libid3tag.so:audio/libid3tag
MPG123_CONFIGURE_ON=	mpg123=yes
MPG123_CONFIGURE_OFF=	mpg123=no
MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123
OPUS_CONFIGURE_ON=	opus=yes
OPUS_CONFIGURE_OFF=	opus=no
OPUS_LIB_DEPENDS=	libopusfile.so:audio/opusfile
SNDFILE_CONFIGURE_ON=	sndfile=yes
SNDFILE_CONFIGURE_OFF=	sndfile=no
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
VORBIS_CONFIGURE_ON=	vorbis=yes
VORBIS_CONFIGURE_OFF=	vorbis=no
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
WAVPACK_CONFIGURE_ON=	wavpack=yes
WAVPACK_CONFIGURE_OFF=	wavpack=no
WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
OPTIONS_SUB=	yes

CONFIGURE_ARGS=	alsa=no \
		ao=no \
		sun=no \
		portaudio=no

post-patch:
	@${REINPLACE_CMD} -e 's|-lcurses|-lncurses|' ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/siren
	@${FIND} ${STAGEDIR}${PREFIX}/lib/siren -path '*.so' \
		| ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
