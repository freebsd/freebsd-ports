# $FreeBSD$

PORTNAME=	musicpd
PORTVERSION=	0.17.2
PORTREVISION=	2
CATEGORIES=	audio ipv6
MASTER_SITES=	SF/${PORTNAME}/mpd/${PORTVERSION}
DISTNAME=	mpd-${PORTVERSION}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	A remote-controllable music daemon

LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad \
		curl.6:${PORTSDIR}/ftp/curl

LICENSE=	GPLv2

USE_STAGE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20

USE_RC_SUBR=	${PORTNAME}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CFLAGS+=	-I${PREFIX}/include

MAN1=		${PORTNAME}.1
MAN5=		${MPDCONF}.5

DOCSDIR?=	${PREFIX}/share/doc/musicpd
PORTDOCS=	AUTHORS README COPYING NEWS UPGRADING

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	ID3TAG IPV6 AVAHI FLAC VORBIS WAV FFMPEG TREMOR AAC \
		MUSEPACK MIKMOD MODPLUG ARCHIVE MMS LASTFM AO PULSEAUDIO \
		JACK SHOUTCAST SNDFILE LAME HTTPD SAMPLERATE CUE

OPTIONS_DEFAULT=ID3TAG IPV6 FLAC VORBIS WAV FFMPEG SNDFILE 
LAME_DESC=	Support for MP3 Icecast Streams

MPDDIR?=	/var/mpd
MPDUSER?=	mpd
MPDGROUP?=	mpd
MPDCONF?=	musicpd.conf

USERS=	${MPDUSER}
GROUPS=	${MPDGROUP}

PLIST_SUB=	MPDCONF=${MPDCONF} \
		MPDUSER=${MPDUSER} \
		MPDDIR=${MPDDIR}   \
		MPDGROUP=${MPDGROUP}
SUB_LIST+=	MPDDIR=${MPDDIR} \
		MPDCONF=${MPDCONF}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
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
LIB_DEPENDS+=	audiofile.0:${PORTSDIR}/audio/libaudiofile
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
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		avformat:${PORTSDIR}/multimedia/ffmpeg \
		avutil.1:${PORTSDIR}/multimedia/ffmpeg
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

.if empty(PORT_OPTIONS:MIPV6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if ${PORT_OPTIONS:MAVAHI}
CONFIGURE_ARGS+=--with-zeroconf=avahi
LIB_DEPENDS+=	avahi-client.3:${PORTSDIR}/net/avahi-app
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

.if ${PORT_OPTIONS:MCUE}
CONFIGURE_ARGS+=--enable-cue
LIB_DEPENDS+=	cue:${PORTSDIR}/textproc/libcue
.else
CONFIGURE_ARGS+=--disable-cue
.endif

.if ${MPDCONF} != musicpd.conf
pre-everything::
	@${ECHO_MSG} "Looks as though you're using a non-default value for MPDCONF."
	@${ECHO_MSG} "This is deprecated, and some time in the near future the only value permissible"
	@${ECHO_MSG} "for MPDCONF will be the default; musicpd.conf."
	@${ECHO_MSG} -n "Continuing in "
	@for s in 5 4 3 2 1 ; do ${ECHO_MSG} -n "$$s... " && sleep 1 ; done
	@${ECHO_MSG} ""
.endif

post-patch:
# Replace ~/ with MPDDIR and make musicpd run as mpd by default
	@${REINPLACE_CMD} -e 's,^#\([^"]*"\)~/,\1${MPDDIR}/,g' \
		-e 's,^#\(user[^"]*"\)nobody,\1${MPDUSER},g' \
		${WRKSRC}/doc/mpdconf.example
# Fix man pages for executable names
	@${REINPLACE_CMD} -e 's/^\(\.B m\)pd/\1usicpd/' \
		-e 's#^\(\.BI \)/etc/mpd.conf#\1${PREFIX}/etc/${MPDCONF}#' \
		-e 's#^mpd.conf#${MPDCONF}#' \
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
		${MAN5PREFIX}/man/man5/${MPDCONF}.5
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.   for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}/
.   endfor
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/doc/mpdconf.example ${PREFIX}/etc/${MPDCONF}.sample
	@if [ ! -f ${PREFIX}/etc/${MPDCONF} ]; then \
		${CP} -p ${PREFIX}/etc/${MPDCONF}.sample \
			${PREFIX}/etc/${MPDCONF} ; \
	fi
	@${INSTALL} -d -o ${MPDUSER} -g ${MPDGROUP} ${MPDDIR} ${MPDDIR}/.mpd
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
