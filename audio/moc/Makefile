# Created by: Revis Zinkov <rzinkov@gmail.com>
# $FreeBSD$

PORTNAME=	moc
PORTVERSION=	2.4.4
PORTREVISION=	17
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.daper.net/pub/soft/moc/stable/

MAINTAINER=	rzinkov@gmail.com
COMMENT=	Console audio player designed to be powerful and easy to use

USES=		gmake libtool pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	JACK MP3 FFMPEG MUSEPACK VORBIS FLAC SNDFILE SPEEX SAMPLERATE CURL RCC
OPTIONS_DEFAULT=	MP3 VORBIS FLAC CURL
CURL_DESC=	curl support (Internet streams)
RCC_DESC=	RCC support

JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_OFF=	--without-jack

MP3_LIB_DEPENDS=	libmad.so:${PORTSDIR}/audio/libmad \
		libid3tag.so:${PORTSDIR}/audio/libid3tag
MP3_PLIST_FILES=	lib/moc/decoder_plugins/libmp3_decoder.a \
		lib/moc/decoder_plugins/libmp3_decoder.so
MP3_CONFIGURE_OFF=	--without-mp3

MUSEPACK_LIB_DEPENDS=	libmpcdec.so:${PORTSDIR}/audio/musepack \
		libtag_c.so:${PORTSDIR}/audio/taglib
MUSEPACK_PLIST_FILES=	lib/moc/decoder_plugins/libmusepack_decoder.a \
		lib/moc/decoder_plugins/libmusepack_decoder.so
MUSEPACK_CONFIGURE_OFF=	--without-musepack

VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis
VORBIS_PLIST_FILES=	lib/moc/decoder_plugins/libvorbis_decoder.a \
		lib/moc/decoder_plugins/libvorbis_decoder.so
VORBIS_CONFIGURE_OFF=	--without-ogg

FLAC_LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac
FLAC_PLIST_FILES=	lib/moc/decoder_plugins/libflac_decoder.a \
		lib/moc/decoder_plugins/libflac_decoder.so
FLAC_CONFIGURE_OFF=	--without-flac

FFMPEG_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
FFMPEG_PLIST_FILES=   lib/moc/decoder_plugins/libffmpeg_decoder.a \
		lib/moc/decoder_plugins/libffmpeg_decoder.so
FFMPEG_CONFIGURE_OFF=	--without-ffmpeg

SNDFILE_LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile
SNDFILE_PLIST_FILES=	lib/moc/decoder_plugins/libsndfile_formats_decoder.a \
		lib/moc/decoder_plugins/libsndfile_formats_decoder.so
SNDFILE_CONFIGURE_OFF=	--without-sndfile

SPEEX_LIB_DEPENDS=	libspeex.so:${PORTSDIR}/audio/speex
SPEEX_PLIST_FILES=	lib/moc/decoder_plugins/libspeex_decoder.a \
		lib/moc/decoder_plugins/libspeex_decoder.so
SPEEX_CONFIGURE_OFF=	--without-speex

SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate
SAMPLERATE_CONFIGURE_OFF=	--without-samplerate

CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
CURL_CONFIGURE_OFF=	--without-curl

RCC_LIB_DEPENDS=	librcc.so:${PORTSDIR}/devel/librcc \
		librcd.so:${PORTSDIR}/devel/librcd
RCC_CONFIGURE_OFF=	--without-rcc

.include <bsd.port.mk>
