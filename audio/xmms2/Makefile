# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME?=	xmms2
PORTVERSION=	0.8
DISTVERSIONSUFFIX=	DrO_o
PORTREVISION?=	34
CATEGORIES?=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20${DISTVERSIONSUFFIX}

MAINTAINER?=	madpilot@FreeBSD.org
COMMENT?=	Rewrite of xmms as a client/server system (developer release)

USES+=		pkgconfig tar:bzip2 waf

CONFIGURE_ARGS+=	--conf-prefix=${LOCALBASE} \
		--mandir=${MANPREFIX}/man \
		--without-plugins="ofa"
INSTALL_TARGET=	install --without-ldconfig

.if !defined(XMMS2_SLAVE)
USE_GNOME=	glib20
USES+=		gnome python:2.7,build readline sqlite

USE_LDCONFIG=	yes

PLIST_SUB+=	INCLUDEDIR="include/${PORTNAME}" LIBDIR="lib/${PORTNAME}"

CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	AIRPLAY AO APE AVCODEC CDDA CURL ET FAAD FAM FLAC \
		GME GVFS ICES JACK MAD MDNS MMS \
		MODPLUG MPG123 MUSEPACK PULSEAUDIO SAMBA SID \
		SNDFILE SPEEX TREMOR VISUAL VOCODER VORBIS WAVPACK XML
OPTIONS_SINGLE=	MDNS
OPTIONS_SINGLE_MDNS=	MDNS_APPLE MDNS_AVAHI
OPTIONS_DEFAULT=	CURL FAAD FLAC MPG123 MDNS MDNS_AVAHI VORBIS

AIRPLAY_DESC=	Support output via Airport Express
AVCODEC_DESC=	Avcodevc playback support
ET_DESC=	Install usage feedback reporting client
FAM_DESC=	Support to update Media Library on file change
GME_DESC=	Video game music files support
GVFS_DESC=	Playback files via GVFS
ICES_DESC=	Playback files to an icecast server
MDNS_DESC=	Announce XMMS2d via mDNS (Choose implementation)
MDNS_APPLE_DESC=	Use Apple mDNS implementation
MDNS_AVAHI_DESC=	Use Avahi mDNS implementation
SAMBA_DESC=	Playback files via SMB
SID_DESC=	Playback SID files
VISUAL_DESC=	Visualization plugins support
VOCODER_DESC=	Phase Vocoder effect plugin
XML_DESC=	Support XML based playlists (XSPF, RSS)

OPTIONS_SUB=	yes

AIRPLAY_USES=		ssl
AIRPLAY_CONFIGURE_OFF=	--without-plugins="airplay"

AO_LIB_DEPENDS=		libao.so:audio/libao
AO_CONFIGURE_OFF=	--without-plugins="ao"

APE_LIB_DEPENDS=	libmac.so:audio/mac
APE_CONFIGURE_OFF=	--without-plugins="mac"

AVCODEC_LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg
AVCODEC_CONFIGURE_OFF=	--without-plugins="avcodec"

CDDA_LIB_DEPENDS=	libcdio.so:sysutils/libcdio \
			libcdio_cdda.so:sysutils/libcdio-paranoia \
			libdiscid.so:audio/libdiscid
CDDA_CONFIGURE_OFF=	--without-plugins="cdda"

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_OFF=	--without-plugins="curl" --without-plugins="icymetaint"

FAAD_LIB_DEPENDS=	libfaad.so:audio/faad
FAAD_CONFIGURE_OFF=	--without-plugins="faad" --without-plugins="mp4"

FAM_USES=		fam:gamin
FAM_CONFIGURE_OFF=	--without-optionals="medialib-updater"

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac

GME_LIB_DEPENDS=	libgme.so:audio/libgme
GME_CONFIGURE_OFF=	--without-plugins="gme"

GVFS_USE=		GNOME=gvfs
GVFS_CONFIGURE_OFF=	--without-plugins="gvfs"

ICES_LIB_DEPENDS=	libshout.so:audio/libshout
ICES_CONFIGURE_OFF=	--without-plugins="ices"

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_OFF=	--without-plugins="jack"

MAD_LIB_DEPENDS=	libmad.so:audio/libmad
MAD_CONFIGURE_OFF=	--without-plugins="mad"

MDNS_CONFIGURE_OFF=	--without-optionals="mdns"

MDNS_APPLE_CONFIGURE_ON=	--with-mdns-backend="dns_sd"
MDNS_APPLE_LIB_DEPENDS=		libdns_sd.so:net/mDNSResponder

MDNS_AVAHI_CONFIGURE_ON=	--with-mdns-backend="avahi"
MDNS_AVAHI_LIB_DEPENDS=		libavahi-core.so:net/avahi-app

MMS_LIB_DEPENDS=	libmms.so:net/libmms
MMS_CONFIGURE_OFF=	--without-plugins="mms"

MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug
MODPLUG_CONFIGURE_OFF=	--without-plugins="modplug"

MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123
MPG123_CONFIGURE_OFF=	--without-plugins="mpg123"

MUSEPACK_LIB_DEPENDS=	libmpcdec.so:audio/musepack
MUSEPACK_CONFIGURE_OFF=	--without-plugins="musepack"

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=	--without-plugins="pulse"

SAMBA_USES=	samba:lib
SAMBA_CPPFLAGS=	-I${SAMBAINCLUDES}
SAMBA_LDFLAGS=	-L${SAMBALIBS}
SAMBA_CONFIGURE_OFF=	--without-plugins="samba"

SID_LIB_DEPENDS=	libsidplay2.so:audio/libsidplay2
SID_CONFIGURE_OFF=	--without-plugins="sid"

SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CONFIGURE_OFF=	--without-plugins="sndfile"

SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex
SPEEX_CONFIGURE_OFF=	--without-plugins="speex"

TREMOR_LIB_DEPENDS=	libvorbisidec.so:audio/libtremor
TREMOR_CONFIGURE_OFF=	--without-plugins="tremor"

VISUAL_USES=		sdl
VISUAL_USE=		SDL=sdl
VISUAL_LIB_DEPENDS=	libvisual-0.4.so:graphics/libvisual04
VISUAL_CONFIGURE_OFF=	--without-optionals="vistest"
VISUAL_CONFIGURE_ON=	--with-vis-reference-clients

VOCODER_LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
			libsamplerate.so:audio/libsamplerate
VOCODER_CONFIGURE_OFF=	--without-plugins="vocoder"

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_CONFIGURE_OFF=	--without-plugins="vorbis"

WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_CONFIGURE_OFF=	--without-plugins="wavpack"

XML_USE=		GNOME=libxml2
XML_CONFIGURE_OFF=	--without-plugins="xml" --without-plugins="rss" \
			--without-plugins="xspf"

ET_CONFIGURE_OFF=	--without-optionals="et"

.endif # !XMMS2_SLAVE

.include <bsd.port.options.mk>

.if defined(XMMS2_SLAVE)
CONFIGURE_ARGS+=	--without-xmms2d

.if   ${XMMS2_SLAVE} == "python"
CONFIGURE_ARGS+=	--with-optionals="python"
.elif ${XMMS2_SLAVE} == "ruby"
CONFIGURE_ARGS+=	--with-optionals="ruby"
.elif ${XMMS2_SLAVE} == "perl"
CONFIGURE_ARGS+=	--with-optionals="perl"
.elif ${XMMS2_SLAVE} == "ruby-ecore"
CONFIGURE_ARGS+=	--with-optionals="ruby" --with-optionals="xmmsclient-ecore"
.elif ${XMMS2_SLAVE} == "cpp"
CONFIGURE_ARGS+=	--with-optionals="xmmsclient++" \
		--with-optionals="xmmsclient++-glib"
.endif

.else # XMMS2_SLAVE
CONFIGURE_ARGS+=	--without-optionals="python" \
		--without-optionals="ruby" \
		--without-optionals="xmmsclient-ecore" \
		--without-optionals="xmmsclient++" \
		--without-optionals="xmmsclient++-glib" \
		--without-optionals="perl"
.endif # XMMS2_SLAVE

.if !defined(XMMS2_SLAVE)

# xmms2-ripper
.if ${PORT_OPTIONS:MVISUAL} && ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	libvorbisenc.so:audio/libvorbis
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-clients-vistest-wscript
.endif

.endif # !XMMS2_SLAVE

.include <bsd.port.pre.mk>

.if defined(XMMS2_SLAVE) && ${XMMS2_SLAVE} == perl && ${PERL_LEVEL} >= 503100
BUILD_DEPENDS+=  p5-Pod-Parser>=0:textproc/p5-Pod-Parser
.endif

# Force to nothing to avoid bsd.openssl.mk adding definitions
# to it when AIRPLAY option is active, waf does not understand it anyway.
MAKE_ARGS=

post-patch:
	@${REINPLACE_CMD} -e "s|%%WRKSRC%%|${WRKSRC}|" ${WRKSRC}/wscript
.if ${PORT_OPTIONS:MVISUAL} && ${PORT_OPTIONS:MVORBIS}
	@${REINPLACE_CMD} -e "s|'vorbisenc',|'vorbisenc vorbis ogg',|" \
		${WRKSRC}/src/clients/vistest/wscript
.endif

post-install:
.if !defined(XMMS2_SLAVE)
	${MKDIR} ${STAGEDIR}${DATADIR}/scripts/startup.d
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxmmsclient*
.else
	${RM} -R ${STAGEDIR}${PREFIX}/lib/xmms2
	${FIND} ${STAGEDIR}${PREFIX}/lib -name '*.so*' | ${XARGS} ${STRIP_CMD} 
.endif

.include <bsd.port.post.mk>
