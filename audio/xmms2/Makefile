# New ports collection makefile for:    xmms2
# Date created:				20 May 2005
# Whom:				  	Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME?=	xmms2
PORTVERSION=	0.8
PORTREVISION=	1
DISTVERSIONSUFFIX=DrO_o
CATEGORIES?=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20${DISTVERSIONSUFFIX}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT?=	Rewrite of xmms as a client/server system (developer release)

USE_BZIP2=	yes
USE_PYTHON_BUILD=	yes

.if !defined(XMMS2_SLAVE)
USE_GNOME=	glib20
USE_SQLITE=	3

USE_LDCONFIG=	yes

MAN1=		xmms2.1 xmms2d.1 xmms2-launcher.1
MANCOMPRESSED=	yes
PLIST_SUB+=	INCLUDEDIR="include/${PORTNAME}" LIBDIR="lib/${PORTNAME}"

CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	AIRPLAY AO APE AVCODEC CDDA CURL ET FAAD FAM FLAC \
		GME GVFS ICES JACK MAD MDNS MMS \
		MODPLUG MPG123 MUSEPACK OFA PULSEAUDIO SAMBA SID \
		SNDFILE SPEEX TREMOR VISUAL VOCODER VORBIS WAVPACK XML
OPTIONS_SINGLE=	MDNS
OPTIONS_SINGLE_MDNS=	MDNS_APPLE MDNS_AVAHI
OPTIONS_DEFAULT=	CURL FAAD FLAC MAD MDNS MDNS_APPLE VORBIS

AIRPLAY_DESC=	Support output via Airport Express
AVCODEC_DESC=	Avcodevc playback support
CDDA_DESC=	AudioCD support
ET_DESC=	Install usage feedback reporting client
FAM_DESC=	Support to update Media Library on file change
GME_DESC=	Video game music files support
GVFS_DESC=	Playback files via GVFS
ICES_DESC=	Playback files to an icecast server
MDNS_DESC=	Announce XMMS2d via mDNS (Choose implementation)
MDNS_APPLE_DESC=	Use Apple mDNS implementation
MDNS_AVAHI_DESC=	Use Avahi mDNS implementation
OFA_DESC=	Collect MusicDNS fingerprints
SAMBA_DESC=	Playback files via SMB
SID_DESC=	Playback SID files
VISUAL_DESC=	Visualization plugins support
VOCODER_DESC=	Phase Vocoder effect plugin
WAVPACK_DESC=	Playback WV files
XML_DESC=	Support XML based playlists (XSPF, RSS)

.endif # !XMMS_SLAVE

.include <bsd.port.options.mk>

.if ${OSVERSION} < 800030
BROKEN=		Does not compile on 7.x: Requires fstatat(2)
.endif

.if defined(XMMS2_SLAVE)
EXCLUDE+=	--without-xmms2d

.if   ${XMMS2_SLAVE} == "python"
EXCLUDE+=	--with-optionals="python"
.elif ${XMMS2_SLAVE} == "ruby"
EXCLUDE+=	--with-optionals="ruby"
.elif ${XMMS2_SLAVE} == "perl"
EXCLUDE+=	--with-optionals="perl"
.elif ${XMMS2_SLAVE} == "ruby-ecore"
EXCLUDE+=	--with-optionals="ruby" --with-optionals="xmmsclient-ecore"
.elif ${XMMS2_SLAVE} == "cpp"
EXCLUDE+=	--with-optionals="xmmsclient++" \
		--with-optionals="xmmsclient++-glib"
.endif

.else # XMMS2_SLAVE
EXCLUDE+=	--without-optionals="python" \
		--without-optionals="ruby" \
		--without-optionals="xmmsclient-ecore" \
		--without-optionals="xmmsclient++" \
		--without-optionals="xmmsclient++-glib" \
		--without-optionals="perl"
.endif # XMMS2_SLAVE

.if !defined(XMMS2_SLAVE)

.if ${PORT_OPTIONS:MAIRPLAY}
USE_OPENSSL=	yes
PLIST_SUB+=	AIRPLAY=""
.else
EXCLUDE+=	--without-plugins="airplay"
PLIST_SUB+=	AIRPLAY="@comment "
.endif

.if ${PORT_OPTIONS:MAO}
LIB_DEPENDS+=	ao:${PORTSDIR}/audio/libao
PLIST_SUB+=	AO=""
.else
EXCLUDE+=	--without-plugins="ao"
PLIST_SUB+=	AO="@comment "
.endif

.if ${PORT_OPTIONS:MAPE}
LIB_DEPENDS+=	mac:${PORTSDIR}/audio/mac
PLIST_SUB+=	MAC=""
.else
EXCLUDE+=	--without-plugins="mac"
PLIST_SUB+=	MAC="@comment "
.endif

.if ${PORT_OPTIONS:MAVCODEC}
LIB_DEPENDS+=	avutil:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=	AVCODEC=""
.else
EXCLUDE+=	--without-plugins="avcodec"
PLIST_SUB+=	AVCODEC="@comment "
.endif

.if ${PORT_OPTIONS:MCDDA}
LIB_DEPENDS+=	cdio:${PORTSDIR}/sysutils/libcdio \
		discid:${PORTSDIR}/audio/libdiscid
PLIST_SUB+=	CDDA=""
.else
EXCLUDE+=	--without-plugins="cdda"
PLIST_SUB+=	CDDA="@comment "
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
PLIST_SUB+=	CURL=""
.else
EXCLUDE+=	--without-plugins="curl" --without-plugins="icymetaint"
PLIST_SUB+=	CURL="@comment "
.endif

.if ${PORT_OPTIONS:MFAAD}
LIB_DEPENDS+=	faad:${PORTSDIR}/audio/faad
PLIST_SUB+=	FAAD=""
.else
EXCLUDE+=	--without-plugins="faad" --without-plugins="mp4"
PLIST_SUB+=	FAAD="@comment "
.endif

.if ${PORT_OPTIONS:MDAM}
USE_FAM=	yes
WANT_FAM_SYSTEM=gamin
PLIST_SUB+=	FAM=""
.else
EXCLUDE+=	--without-optionals="medialib-updater"
PLIST_SUB+=	FAM="@comment "
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
PLIST_SUB+=	FLAC=""
.else
EXCLUDE+=	--without-plugins="flac"
PLIST_SUB+=	FLAC="@comment "
.endif

.if ${PORT_OPTIONS:MGME}
LIB_DEPENDS+=	gme:${PORTSDIR}/audio/libgme
PLIST_SUB+=	GME=""
.else
EXCLUDE+=	--without-plugins="gme"
PLIST_SUB+=	GME="@comment "
.endif

.if ${PORT_OPTIONS:MGVFS}
USE_GNOME+=	gvfs
PLIST_SUB+=	GVFS=""
.else
EXCLUDE+=	--without-plugins="gvfs"
PLIST_SUB+=	GVFS="@comment "
.endif

.if ${PORT_OPTIONS:MICES}
LIB_DEPENDS+=	shout:${PORTSDIR}/audio/libshout2
PLIST_SUB+=	ICES=""
.else
EXCLUDE+=	--without-plugins="ices"
PLIST_SUB+=	ICES="@comment "
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
PLIST_SUB+=	JACK=""
.else
EXCLUDE+=	--without-plugins="jack"
PLIST_SUB+=	JACK="@comment "
.endif

.if ${PORT_OPTIONS:MMAD}
LIB_DEPENDS+=	mad:${PORTSDIR}/audio/libmad
PLIST_SUB+=	MAD=""
.else
EXCLUDE+=	--without-plugins="mad"
PLIST_SUB+=	MAD="@comment "
.endif

.if empty(PORT_OPTIONS:MMDNS)
EXCLUDE+=	--without-optionals="mdns"
.endif

.if ${PORT_OPTIONS:MMDNS_APPLE}
EXCLUDE+=	--with-mdns-backend="dns_sd"
LIB_DEPENDS+=	dns_sd:${PORTSDIR}/net/mDNSResponder
PLIST_SUB+=	MDNS_APPLE=""
.else
PLIST_SUB+=	MDNS_APPLE="@comment "
.endif

.if ${PORT_OPTIONS:MMDNS_AVAHI}
EXCLUDE+=	--with-mdns-backend="avahi"
LIB_DEPENDS+=	avahi-core:${PORTSDIR}/net/avahi-app
PLIST_SUB+=	MDNS_AVAHI=""
MAN1+=		xmms2-mdns-avahi.1
.else
PLIST_SUB+=	MDNS_AVAHI="@comment "
.endif

.if ${PORT_OPTIONS:MMMS}
LIB_DEPENDS+=	mms:${PORTSDIR}/net/libmms
PLIST_SUB+=	MMS=""
.else
EXCLUDE+=	--without-plugins="mms"
PLIST_SUB+=	MMS="@comment "
.endif

.if ${PORT_OPTIONS:MMODPLUG}
LIB_DEPENDS+=	modplug:${PORTSDIR}/audio/libmodplug
PLIST_SUB+=	MODPLUG=""
.else
EXCLUDE+=	--without-plugins="modplug"
PLIST_SUB+=	MODPLUG="@comment "
.endif

.if ${PORT_OPTIONS:MMPG123}
LIB_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123
PLIST_SUB+=	MPG123=""
.else
EXCLUDE+=	--without-plugins="mpg123"
PLIST_SUB+=	MPG123="@comment "
.endif

.if ${PORT_OPTIONS:MMUSEPACK}
LIB_DEPENDS+=	mpcdec:${PORTSDIR}/audio/musepack
PLIST_SUB+=	MUSEPACK=""
.else
EXCLUDE+=	--without-plugins="musepack"
PLIST_SUB+=	MUSEPACK="@comment "
.endif

.if ${PORT_OPTIONS:MOFA}
LIB_DEPENDS+=	ofa:${PORTSDIR}/audio/libofa
PLIST_SUB+=	OFA=""
.else
EXCLUDE+=	--without-plugins="ofa"
PLIST_SUB+=	OFA="@comment "
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=	PULSE=""
.else
EXCLUDE+=	--without-plugins="pulse"
PLIST_SUB+=	PULSE="@comment "
.endif

.if ${PORT_OPTIONS:MSAMBA}
LIB_DEPENDS+=	smbclient:${PORTSDIR}/net/samba-libsmbclient
PLIST_SUB+=	SAMBA=""
.else
EXCLUDE+=	--without-plugins="samba"
PLIST_SUB+=	SAMBA="@comment "
.endif

.if ${PORT_OPTIONS:MSID}
LIB_DEPENDS+=	sidplay2:${PORTSDIR}/audio/libsidplay2
PLIST_SUB+=	SID=""
.else
EXCLUDE+=	--without-plugins="sid"
PLIST_SUB+=	SID="@comment "
.endif

.if ${PORT_OPTIONS:MSNDFILE}
LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile
PLIST_SUB+=	SNDFILE=""
.else
EXCLUDE+=	--without-plugins="sndfile"
PLIST_SUB+=	SNDFILE="@comment "
.endif

.if ${PORT_OPTIONS:MSPEEX}
LIB_DEPENDS+=	speex:${PORTSDIR}/audio/speex
PLIST_SUB+=	SPEEX=""
.else
EXCLUDE+=	--without-plugins="speex"
PLIST_SUB+=	SPEEX="@comment "
.endif

.if ${PORT_OPTIONS:MTREMOR}
LIB_DEPENDS+=	vorbisidec:${PORTSDIR}/audio/libtremor
PLIST_SUB+=	TREMOR=""
.else
EXCLUDE+=	--without-plugins="tremor"
PLIST_SUB+=	TREMOR="@comment "
.endif

# xmms2-ripper
.if ${PORT_OPTIONS:MVISUAL} && ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbisenc:${PORTSDIR}/audio/libvorbis
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-clients-vistest-wscript
.endif

# XXX: shm support requires semtimedop(2)
.if ${PORT_OPTIONS:MVISUAL}
USE_SDL=	yes
LIB_DEPENDS+=	visual-0.4.0:${PORTSDIR}/graphics/libvisual04
.else
EXCLUDE+=	--without-optionals="vistest"
.endif

.if ${PORT_OPTIONS:MVISUAL} && ${EXCLUDE:M--with-vis-reference-clients}
PLIST_SUB+=	VISUAL=""
.else
PLIST_SUB+=	VISUAL="@comment "
.endif

.if ${PORT_OPTIONS:MVOCODER}
LIB_DEPENDS+=	fftw3f:${PORTSDIR}/math/fftw3-float
LIB_DEPENDS+=	samplerate:${PORTSDIR}/audio/libsamplerate
PLIST_SUB+=	VOCODER=""
.else
EXCLUDE+=	--without-plugins="vocoder"
PLIST_SUB+=	VOCODER="@comment "
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	VORBIS=""
.else
EXCLUDE+=	--without-plugins="vorbis"
PLIST_SUB+=	VORBIS="@comment "
.endif

.if ${PORT_OPTIONS:MWAVPACK}
LIB_DEPENDS+=	wavpack:${PORTSDIR}/audio/wavpack
PLIST_SUB+=	WAVPACK=""
.else
EXCLUDE+=	--without-plugins="wavpack"
PLIST_SUB+=	WAVPACK="@comment "
.endif

.if ${PORT_OPTIONS:MXML}
USE_GNOME+=	libxml2
PLIST_SUB+=	XML=""
.else
EXCLUDE+=	--without-plugins="xml" --without-plugins="rss" \
		--without-plugins="xspf"
PLIST_SUB+=	XML="@comment "
.endif

.if ${PORT_OPTIONS:MET}
PLIST_SUB+=	ET=""
MAN1+=		xmms2-et.1
.else
EXCLUDE+=	--without-optionals="et"
PLIST_SUB+=	ET="@comment "
.endif

.endif # !XMMS2_SLAVE

post-patch:
	@${REINPLACE_CMD} -e "s|%%WRKSRC%%|${WRKSRC}|" ${WRKSRC}/wscript

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf ${_MAKE_JOBS} configure \
		--conf-prefix=${LOCALBASE} --prefix=${PREFIX} \
		--mandir=${PREFIX}/man ${EXCLUDE}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf ${_MAKE_JOBS} build

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf install --without-ldconfig
	if [ ! -d ${DATADIR}/scripts/startup.d ]; then \
		${MKDIR} ${DATADIR}/scripts/startup.d;\
	fi

.include <bsd.port.mk>
