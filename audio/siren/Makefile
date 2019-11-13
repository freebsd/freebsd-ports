# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	siren
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.kariliq.nl/${PORTNAME}/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text-based audio player

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENCE

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libid3tag.so:audio/libid3tag \
		libmad.so:audio/libmad \
		libvorbis.so:audio/libvorbis \
		libwavpack.so:audio/wavpack \
		libopusfile.so:audio/opusfile

BROKEN_mips=		fails to configure: cannot find program /nxb-bin/usr/bin/cc
BROKEN_mips64=		fails to configure: cannot find program /nxb-bin/usr/bin/cc

USES=		ncurses pkgconfig
HAS_CONFIGURE=	yes
USE_CSTD=	c99

OPTIONS_DEFINE=		FFMPEG MPG123
OPTIONS_MULTI=		SOUND
OPTIONS_MULTI_SOUND=	OSS PULSEAUDIO SNDIO
OPTIONS_DEFAULT=	OSS
OSS_CONFIGURE_ON=	oss=yes
OSS_CONFIGURE_OFF=	oss=no
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ON=	pulse=yes
PULSEAUDIO_CONFIGURE_OFF=	pulse=no
SNDIO_CONFIGURE_ON=	sndio=yes
SNDIO_CONFIGURE_OFF=	sndio=no
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_USES=		localbase:ldflags
FFMPEG_CONFIGURE_ON=	ffmpeg=yes
FFMPEG_CONFIGURE_OFF=	ffmpeg=no
FFMPEG_LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg
MPG123_CONFIGURE_ON=	mpg123=yes
MPG123_CONFIGURE_OFF=	mpg123=no
MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123
OPTIONS_SUB=	yes

CONFIGURE_ARGS=	sndfile=no \
		alsa=no \
		ao=no \
		sun=no \
		portaudio=no \
		aac=no

post-patch:
	@${REINPLACE_CMD} -e 's|-lcurses|-lncurses|' ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/siren
	@${FIND} ${STAGEDIR}${PREFIX}/lib/siren -path '*.so' \
		| ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
