# New ports collection makefile for:	moc
# Date created:				24 July 2005
# Whom:					Revis Zinkov <rzinkov@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	moc
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.daper.net/pub/soft/moc/stable/

MAINTAINER=	rzinkov@gmail.com
COMMENT=	A console audio player designed to be powerful and easy to use

USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN8=		mocp.8

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

OPTIONS=	JACK "JACK support" off \
		MP3 "MP3 support" on \
		MUSEPACK "Musepack (mpc) support" off \
		VORBIS "Ogg Vorbis support" on \
		FLAC "FLAC support" off \
		SNDFILE "libsndfile support" off \
		SPEEX "Speex support" off \
		SAMPLERATE "libsamplerate support" off \
		CURL "curl support (Internet streams)" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--without-jack
.endif

.if defined(WITH_MP3)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/mad \
		id3tag.2:${PORTSDIR}/audio/libid3tag
PLIST_FILES+=	lib/moc/decoder_plugins/libmp3_decoder.so
.else
CONFIGURE_ARGS+=	--without-mp3
.endif

.if defined(WITH_MUSEPACK)
LIB_DEPENDS+=	mpcdec.3:${PORTSDIR}/audio/libmpcdec \
		tag_c.0:${PORTSDIR}/audio/taglib
PLIST_FILES+=	lib/moc/decoder_plugins/libmusepack_decoder.so
.else
CONFIGURE_ARGS+=	--without-musepack
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
PLIST_FILES+=	lib/moc/decoder_plugins/libogg_decoder.so
.else
CONFIGURE_ARGS+=	--without-ogg
.endif

.if defined(WITH_FLAC)
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
PLIST_FILES+=	lib/moc/decoder_plugins/libflac_decoder.so
.else
CONFIGURE_ARGS+=	--without-flac
.endif

.if defined(WITH_SNDFILE)
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
PLIST_FILES+=	lib/moc/decoder_plugins/libsndfile_formats_decoder.so
.else
CONFIGURE_ARGS+=	--without-sndfile
.endif

.if defined(WITH_SPEEX)
LIB_DEPENDS+=	speex.3:${PORTSDIR}/audio/speex
PLIST_FILES+=	lib/moc/decoder_plugins/libspeex_decoder.so
.else
CONFIGURE_ARGS+=	--without-speex
.endif

.if defined(WITH_SAMPLERATE)
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
.else
CONFIGURE_ARGS+=	--without-samplerate
.endif

.if defined(WITH_CURL)
LIB_DEPENDS+=	curl.3:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--without-curl
.endif

.include <bsd.port.post.mk>
