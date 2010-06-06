# New ports collection makefile for:	moc
# Date created:				24 July 2005
# Whom:					Revis Zinkov <rzinkov@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	moc
PORTVERSION=	2.4.4
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.daper.net/pub/soft/moc/stable/

MAINTAINER=	rzinkov@gmail.com
COMMENT=	A console audio player designed to be powerful and easy to use

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		mocp.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

OPTIONS=	JACK "JACK support" off \
		MP3 "MP3 support" on \
		FFMPEG "FFMPEG support" off \
		MUSEPACK "Musepack (mpc) support" off \
		VORBIS "Ogg Vorbis support" on \
		FLAC "FLAC support" off \
		SNDFILE "libsndfile support" off \
		SPEEX "Speex support" off \
		SAMPLERATE "libsamplerate support" off \
		CURL "curl support (Internet streams)" on \
		RCC "RCC support" off

.include <bsd.port.pre.mk>

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--without-jack
.endif

.if defined(WITH_MP3)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad \
		id3tag.0:${PORTSDIR}/audio/libid3tag
PLIST_FILES+=	lib/moc/decoder_plugins/libmp3_decoder.a \
		lib/moc/decoder_plugins/libmp3_decoder.la \
		lib/moc/decoder_plugins/libmp3_decoder.so
.else
CONFIGURE_ARGS+=	--without-mp3
.endif

.if defined(WITH_MUSEPACK)
LIB_DEPENDS+=	mpcdec.5:${PORTSDIR}/audio/libmpcdec \
		tag_c.0:${PORTSDIR}/audio/taglib
PLIST_FILES+=	lib/moc/decoder_plugins/libmusepack_decoder.a \
		lib/moc/decoder_plugins/libmusepack_decoder.la \
		lib/moc/decoder_plugins/libmusepack_decoder.so
.else
CONFIGURE_ARGS+=	--without-musepack
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
PLIST_FILES+=	lib/moc/decoder_plugins/libvorbis_decoder.a \
		lib/moc/decoder_plugins/libvorbis_decoder.la \
		lib/moc/decoder_plugins/libvorbis_decoder.so
.else
CONFIGURE_ARGS+=	--without-ogg
.endif

.if defined(WITH_FLAC)
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
PLIST_FILES+=	lib/moc/decoder_plugins/libflac_decoder.a \
		lib/moc/decoder_plugins/libflac_decoder.la \
		lib/moc/decoder_plugins/libflac_decoder.so
.else
CONFIGURE_ARGS+=	--without-flac
.endif

.if defined(WITH_FFMPEG)
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
PLIST_FILES+=   lib/moc/decoder_plugins/libffmpeg_decoder.a \
		lib/moc/decoder_plugins/libffmpeg_decoder.la \
		lib/moc/decoder_plugins/libffmpeg_decoder.so
.else
CONFIGURE_ARGS+=	--without-ffmpeg
.endif

.if defined(WITH_SNDFILE)
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
PLIST_FILES+=	lib/moc/decoder_plugins/libsndfile_formats_decoder.a \
		lib/moc/decoder_plugins/libsndfile_formats_decoder.la \
		lib/moc/decoder_plugins/libsndfile_formats_decoder.so
.else
CONFIGURE_ARGS+=	--without-sndfile
.endif

.if defined(WITH_SPEEX)
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
PLIST_FILES+=	lib/moc/decoder_plugins/libspeex_decoder.a \
		lib/moc/decoder_plugins/libspeex_decoder.la \
		lib/moc/decoder_plugins/libspeex_decoder.so
.else
CONFIGURE_ARGS+=	--without-speex
.endif

.if defined(WITH_SAMPLERATE)
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
.else
CONFIGURE_ARGS+=	--without-samplerate
.endif

.if defined(WITH_CURL)
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--without-curl
.endif

.if defined(WITH_RCC)
LIB_DEPENDS+=	rcc.2:${PORTSDIR}/devel/librcc \
		rcd.1:${PORTSDIR}/devel/librcd
.else
CONFIGURE_ARGS+=	--without-rcc
.endif

.include <bsd.port.post.mk>
