# $FreeBSD$

PORTNAME=	musicpd
PORTVERSION=	0.17.3
PORTREVISION=	3
CATEGORIES=	audio ipv6
MASTER_SITES=	SF/${PORTNAME}/mpd/${PORTVERSION}
DISTNAME=	mpd-${PORTVERSION}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Remote-controllable music daemon

LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad \
		curl:${PORTSDIR}/ftp/curl

LICENSE=	GPLv2

USE_STAGE=	yes
NO_STAGE=	yes
USES=		gmake pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20

USE_RC_SUBR=	${PORTNAME}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CFLAGS+=	-I${PREFIX}/include

MAN1=		${PORTNAME}.1
MAN5=		${PORTNAME}.conf.5

DOCSDIR?=	${PREFIX}/share/doc/musicpd
PORTDOCS=	AUTHORS README COPYING NEWS UPGRADING

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	ID3TAG IPV6 FLAC VORBIS WAV FFMPEG TREMOR AAC \
		MUSEPACK MIKMOD MODPLUG ARCHIVE MMS LASTFM AO PULSEAUDIO \
		JACK SHOUTCAST SNDFILE LAME HTTPD SAMPLERATE SQLITE3
OPTIONS_RADIO=	ZEROCONF
OPTIONS_RADIO_ZEROCONF=	AVAHI MDNSRESPONDER

TREMOR_DESC=	Tremor decoder (not with SHOUTCAST; use VORBIS)

OPTIONS_DEFAULT=ID3TAG IPV6 FLAC VORBIS WAV FFMPEG SNDFILE
LAME_DESC=	Support for MP3 Icecast Streams

MPDDIR?=	/var/mpd
MPDUSER?=	mpd
MPDGROUP?=	mpd

USERS=	${MPDUSER}
GROUPS=	${MPDGROUP}

PLIST_SUB=	MPDUSER=${MPDUSER} \
		MPDDIR=${MPDDIR}   \
		MPDGROUP=${MPDGROUP}
SUB_LIST+=	MPDDIR=${MPDDIR}

.include <bsd.port.options.mk>

.ifdef MPDCONF
.error Please remove the MPDCONF line from make.conf, then rename ${PREFIX}/etc/${MPDCONF} to musicpd.conf, if it exists
.endif

.include <bsd.port.pre.mk>

.if exists(${PREFIX}/etc/mpd.conf)
MSG=You still have ${PREFIX}/etc/mpd.conf in existence-- this file is no longer used by musicpd.
.if !exists(${PREFIX}/etc/musicpd.conf)
.error ${MSG}  Move it to ${PREFIX}/etc/musicpd.conf.
.else
.error ${MSG}  You also have musicpd.conf-- check carefully to see which one you want, and remove mpd.conf.
.endif
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
.else
CONFIGURE_ARGS+=--disable-flac \
		--disable-oggflac
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if ${PORT_OPTIONS:MTREMOR}
CONFIGURE_ARGS+=--with-tremor
LIB_DEPENDS+=	vorbisidec.1:${PORTSDIR}/audio/libtremor
.endif

.if ${PORT_OPTIONS:MAAC}
LIB_DEPENDS+=	faad.2:${PORTSDIR}/audio/faad
.else
CONFIGURE_ARGS+=--disable-aac
.endif

.if ${PORT_OPTIONS:MLAME}
CONFIGURE_ARGS+=--enable-lame-encoder
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
.else
CONFIGURE_ARGS+=--disable-lame-encoder
.endif

.if ${PORT_OPTIONS:MHTTPD}
CONFIGURE_ARGS+=--enable-httpd-output
.else
CONFIGURE_ARGS+=--disable-httpd-output
.endif

.if ${PORT_OPTIONS:MWAV}
LIB_DEPENDS+=	libaudiofile.so:${PORTSDIR}/audio/libaudiofile
.else
CONFIGURE_ARGS+=--disable-audiofile
.endif

.if ${PORT_OPTIONS:MMUSEPACK}
LIB_DEPENDS+=	mpcdec.7:${PORTSDIR}/audio/musepack
.else
CONFIGURE_ARGS+=--disable-mpc
.endif

.if ${PORT_OPTIONS:MMIKMOD}
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
CONFIGURE_ARGS+=--enable-mikmod
.else
CONFIGURE_ARGS+=--disable-mikmod
.endif

.if ${PORT_OPTIONS:MMODPLUG}
LIB_DEPENDS+=	modplug.1:${PORTSDIR}/audio/libmodplug
CONFIGURE_ARGS+=--enable-modplug
.else
CONFIGURE_ARGS+=--disable-modplug
.endif

.if ${PORT_OPTIONS:MARCHIVE}
CONFIGURE_ARGS+=--enable-bzip2 \
		--enable-zip \
		--enable-iso9660
LIB_DEPENDS+=	zzip.13:${PORTSDIR}/devel/zziplib \
		iso9660.8:${PORTSDIR}/sysutils/libcdio
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libavformat.so:${PORTSDIR}/multimedia/ffmpeg \
		libavutil.so:${PORTSDIR}/multimedia/ffmpeg
.else
CONFIGURE_ARGS+=--disable-ffmpeg
.endif

.if ${PORT_OPTIONS:MLASTFM}
CONFIGURE_ARGS+=--enable-lastfm
.else
CONFIGURE_ARGS+=--disable-lastfm
.endif

.if ${PORT_OPTIONS:MMMS}
CONFIGURE_ARGS+=--enable-mms
LIB_DEPENDS+=	mms.0:${PORTSDIR}/net/libmms
.else
CONFIGURE_ARGS+=--disable-mms
.endif

.if ${PORT_OPTIONS:MID3TAG}
LIB_DEPENDS+=	id3tag.0:${PORTSDIR}/audio/libid3tag
.else
CONFIGURE_ARGS+=--disable-id3
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if ${PORT_OPTIONS:MAVAHI}
CONFIGURE_ARGS+=--with-zeroconf=avahi
LIB_DEPENDS+=	avahi-client.3:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=--with-zeroconf=no
.endif

.if ${PORT_OPTIONS:MMDNSRESPONDER}
CONFIGURE_ARGS+=--with-zeroconf=bonjour
LIB_DEPENDS+=	dns_sd:${PORTSDIR}/net/mDNSResponder
.else
CONFIGURE_ARGS+=--with-zeroconf=no
.endif

.if ${PORT_OPTIONS:MAO}
CONFIGURE_ARGS+=--enable-ao
LIB_DEPENDS+=	ao.4:${PORTSDIR}/audio/libao
.else
CONFIGURE_ARGS+=--disable-ao
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=--disable-pulse
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=--disable-jack
.endif

# libshout streaming support will be disabled by configure script when built
# also with tremor since the latter does not support vorbis encoding
.if ${PORT_OPTIONS:MSHOUTCAST}
.  if ${PORT_OPTIONS:MTREMOR}
IGNORE=		shoutcast and tremor do not coexist; use vorbis instead
.  endif
LIB_DEPENDS+=	shout.5:${PORTSDIR}/audio/libshout2
CONFIGURE_ARGS+=--enable-vorbis-encoder \
		--enable-shout
.else
CONFIGURE_ARGS+=--disable-shout
.endif

.if ${PORT_OPTIONS:MSNDFILE}
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
CONFIGURE_ARGS+=	--enable-sndfile
.else
CONFIGURE_ARGS+=	--disable-sndfile
.endif

.if ${PORT_OPTIONS:MSAMPLERATE}
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=--enable-lsr
.else
CONFIGURE_ARGS+=--disable-lsr
.endif

.if ${PORT_OPTIONS:MSQLITE3}
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=--enable-sqlite
.else
CONFIGURE_ARGS+=--disable-sqlite
.endif

post-patch:
# Replace ~/ with MPDDIR and make musicpd run as mpd by default
	@${REINPLACE_CMD} -e 's,^#\([^"]*"\)~/,\1${MPDDIR}/,g' \
		-e 's,^#\(user[^"]*"\)nobody,\1${MPDUSER},g' \
		${WRKSRC}/doc/mpdconf.example
# Uncomment OSS audio output part from MPDCONF; dragons!
	start=$$(expr $$(${SED} -n '/^#	type	*"oss"/=' \
		${WRKSRC}/doc/mpdconf.example) - 1); \
	 finish=$$(for n in $$(${JOT} 10 $$start); do \
	 	     [ "$$(${SED} -n $${n}p ${WRKSRC}/doc/mpdconf.example)" = \
				"#}" ] && echo $$n || true; done); \
	 ${REINPLACE_CMD} -e "$${start},$${finish}s,^#,," \
		${WRKSRC}/doc/mpdconf.example
# Fix man pages for executable names
	@${REINPLACE_CMD} -e 's/^\(\.B m\)pd/\1usicpd/' \
		-e 's#^\(\.BI \)/etc/mpd.conf#\1${PREFIX}/etc/${PORTNAME}.conf#' \
		-e 's#^mpd.conf#${PORTNAME}.conf#' \
		-e 's#^mpd(1)#musicpd(1)#' \
		${WRKSRC}/doc/mpd.1 ${WRKSRC}/doc/mpd.conf.5
.if (${OSVERSION} < 800000)
	${REINPLACE_CMD} -e 's/nan[f]*(\"\")/NAN/g' \
		${WRKSRC}/src/crossfade.c \
		${WRKSRC}/src/player_thread.c \
		${WRKSRC}/src/player_control.c
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/mpd ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/doc/mpd.1 ${MAN1PREFIX}/man/man1/${PORTNAME}.1
	@${INSTALL_MAN} ${WRKSRC}/doc/mpd.conf.5 \
		${MAN5PREFIX}/man/man5/${PORTNAME}.conf.5
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.   for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}/
.   endfor
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/doc/mpdconf.example ${PREFIX}/etc/${PORTNAME}.conf.sample
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}.conf ]; then \
		${CP} -p ${PREFIX}/etc/${PORTNAME}.conf.sample \
			${PREFIX}/etc/${PORTNAME}.conf ; \
	fi
	@${INSTALL} -d -o ${MPDUSER} -g ${MPDGROUP} ${MPDDIR} ${MPDDIR}/.mpd
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
