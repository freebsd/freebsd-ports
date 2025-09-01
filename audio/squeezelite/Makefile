PORTNAME=	squeezelite
DISTVERSION=	2.0.0.1541
CATEGORIES=	audio

MAINTAINER=	jockl@pianojockl.org
COMMENT=	Lightweight headless squeezebox player for Logitech Media Server
WWW=		https://github.com/ralph-irving/squeezelite

LICENSE=	GPLv3

LIB_DEPENDS=	libfaad.so:audio/faad \
		libportaudio.so:audio/portaudio \
		libmpg123.so:audio/mpg123 \
		libasound.so:audio/alsa-lib \
		libFLAC.so:audio/flac \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg

USES=		gmake localbase:ldflags ssl
USE_GITHUB=	yes
GH_ACCOUNT=	ralph-irving
GH_TAGNAME=	72e1fd8

CPPFLAGS+=	-I${PREFIX}/include/portaudio2
LDFLAGS+=	-lportaudio -lm

OPTIONS_DEFINE=	SSL FFMPEG RESAMPLE DSD SELFPIPE OPUS LINKALL
OPTIONS_DEFAULT=SSL RESAMPLE FFMPEG DSD LINKALL

RESAMPLE_DESC=	Resampling
SELFPIPE_DESC=	Selfpipe
LINKALL_DESC=	Link all libraries at build time
DSD_DESC=	Direct Stream Digital
SSL_VARS=	MENV+=" -DUSE_SSL -DNO_SSL_SYM"
RESAMPLE_VARS=	MENV+=" -DRESAMPLE"
FFMPEG_VARS=	MENV+=" -DFFMPEG"
DSD_VARS=	MENV+=" -DDSD"
VISEXPORT_VARS=	MENV+=" -DVISEXPORT"
LINKALL_VARS=	MENV+=" -DLINKALL"
SELFPIPE_VARS=	MENV+=" -DSELFPIPE"
OPUS_VARS=	MENV+=" -DOPUS"

MAKE_ENV=	OPTS="-DGPIO -DNO_MAD ${MENV}"

OPUS_LIB_DEPENDS=	libopusfile.so:audio/opusfile \
			libopus.so:audio/opus
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
RESAMPLE_LIB_DEPENDS=	libsoxr.so:audio/libsoxr

PLIST_FILES=		bin/${PORTNAME} \
			share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
