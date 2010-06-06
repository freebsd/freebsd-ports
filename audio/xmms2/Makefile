# New ports collection makefile for:    xmms2
# Date created:				20 May 2005
# Whom:				  	Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME?=	xmms2
PORTVERSION=	0.6
PORTREVISION=	6
DISTVERSIONSUFFIX=DrMattDestruction
CATEGORIES?=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20DrMattDestruction

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Rewrite of xmms as a client/server system (developer release)

USE_BZIP2=	yes
USE_PYTHON_BUILD=	yes

.if !defined(XMMS2_SLAVE)
USE_GNOME=	glib20
USE_SQLITE=	3

USE_LDCONFIG=	yes

MAN1=		nyxmms2.1 xmms2.1 xmms2-et.1 xmms2d.1 xmms2-launcher.1
MANCOMPRESSED=	yes
PLIST_SUB+=	INCLUDEDIR="include/${PORTNAME}" LIBDIR="lib/${PORTNAME}"

OPTIONS=	AIRPLAY	"Support output via Airport Express" off \
		AO	"Support to output via libao" off \
		APE	"Support to playback Monkey's Audio files" off \
		AVCODEC	"Support to playback files with avcodec" off \
		CDDA	"Support to playback AudioCD" off \
		CURL	"Support to playback files via HTTP" on \
		FAAD	"Support to playback AAC files" on \
		FAM	"Support to update Media Library on file change" off \
		FLAC	"Support to playback FLAC files" on \
		GVFS	"Support to playback files via GVFS" off \
		ICES	"Support to playback files to an icecast server" off \
		JACK	"Support to output via the Jack output server" off \
		MAD	"Support to playback MP3 files" on \
		MDNS_APPLE "Support to announce XMMS2d via mDNS (Apple)" on \
		MDNS_AVAHI "Support to announce XMMS2d via mDNS (Avahi)" off \
		MMS	"Support to playback streams via MMS" off \
		MODPLUG	"Support to playback MOD files" off \
		MPG123	"Support to playback MP3 files" off \
		MUSEPACK "Support to playback MPC files" off \
		OFA	"Support to collect MusicDNS fingerprints" off \
		PULSE	"Support to output via the PulseAudio" off \
		SAMBA	"Support to playback files via SMB" off \
		SID	"Support to playback SID files" off \
		SPEEX	"Support to playback SPEEX files" off \
		VISUAL	"Support for visualization plugins" off \
		VOCODER	"Phase Vocoder effect plugin" off \
		VORBIS	"Support to playback OGG files" on \
		WAVPACK	"Support to playback WV files" off \
		XML	"Support for XML based playlists (XSPF, RSS)" off
.endif # !XMMS_SLAVE

.include <bsd.port.pre.mk>

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

.if !defined(WITHOUT_AIRPLAY)
USE_OPENSSL=	yes
PLIST_SUB+=	AIRPLAY=""
.else
EXCLUDE+=	--without-plugins="airplay"
PLIST_SUB+=	AIRPLAY="@comment "
.endif

.if !defined(WITHOUT_AO)
LIB_DEPENDS+=	ao.4:${PORTSDIR}/audio/libao
PLIST_SUB+=	AO=""
.else
EXCLUDE+=	--without-plugins="ao"
PLIST_SUB+=	AO="@comment "
.endif

.if !defined(WITHOUT_APE)
LIB_DEPENDS+=	mac.2:${PORTSDIR}/audio/mac
PLIST_SUB+=	MAC=""
.else
EXCLUDE+=	--without-plugins="mac"
PLIST_SUB+=	MAC="@comment "
.endif

.if !defined(WITHOUT_AVCODEC)
LIB_DEPENDS+=	avutil.1:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=	AVCODEC=""
.else
EXCLUDE+=	--without-plugins="avcodec"
PLIST_SUB+=	AVCODEC="@comment "
.endif

.if !defined(WITHOUT_CDDA)
LIB_DEPENDS+=	cdio.12:${PORTSDIR}/sysutils/libcdio \
		discid.2:${PORTSDIR}/audio/libdiscid
PLIST_SUB+=	CDDA=""
.else
EXCLUDE+=	--without-plugins="cdda"
PLIST_SUB+=	CDDA="@comment "
.endif

.if !defined(WITHOUT_CURL)
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
PLIST_SUB+=	CURL=""
.else
EXCLUDE+=	--without-plugins="curl" --without-plugins="icymetaint"
PLIST_SUB+=	CURL="@comment "
.endif

.if !defined(WITHOUT_FAAD)
LIB_DEPENDS+=	faad.2:${PORTSDIR}/audio/faad
PLIST_SUB+=	FAAD=""
.else
EXCLUDE+=	--without-plugins="faad" --without-plugins="mp4"
PLIST_SUB+=	FAAD="@comment "
.endif

.if !defined(WITHOUT_FAM)
USE_FAM=	yes
WANT_FAM_SYSTEM=gamin
PLIST_SUB+=	FAM=""
.else
EXCLUDE+=	--without-optionals="medialib-updater"
PLIST_SUB+=	FAM="@comment "
.endif

.if !defined(WITHOUT_FLAC)
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
PLIST_SUB+=	FLAC=""
.else
EXCLUDE+=	--without-plugins="flac"
PLIST_SUB+=	FLAC="@comment "
.endif

.if !defined(WITHOUT_GVFS)
USE_GNOME+=	gvfs
PLIST_SUB+=	GVFS=""
.else
EXCLUDE+=	--without-plugins="gvfs"
PLIST_SUB+=	GVFS="@comment "
.endif

.if !defined(WITHOUT_ICES)
LIB_DEPENDS+=	shout.5:${PORTSDIR}/audio/libshout2
PLIST_SUB+=	ICES=""
.else
EXCLUDE+=	--without-plugins="ices"
PLIST_SUB+=	ICES="@comment "
.endif

.if !defined(WITHOUT_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
PLIST_SUB+=	JACK=""
.else
EXCLUDE+=	--without-plugins="jack"
PLIST_SUB+=	JACK="@comment "
.endif

.if !defined(WITHOUT_MAD)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad
PLIST_SUB+=	MAD=""
.else
EXCLUDE+=	--without-plugins="mad"
PLIST_SUB+=	MAD="@comment "
.endif

.if !defined(WITHOUT_MDNS_APPLE) && !defined(WITHOUT_MDNS_AVAHI)
BROKEN=		You may choose either MDNS_APPLE or MDNS_AVAHI, but not both
.endif

.if !defined(WITHOUT_MDNS_APPLE)
EXCLUDE+=	--without-optionals="avahi"
LIB_DEPENDS+=	dns_sd:${PORTSDIR}/net/mDNSResponder
PLIST_SUB+=	MDNS_APPLE=""
.else
EXCLUDE+=	--without-optionals="dns_sd"
PLIST_SUB+=	MDNS_APPLE="@comment "
.endif

.if !defined(WITHOUT_MDNS_AVAHI)
EXCLUDE+=	--without-optionals="dns_sd"
LIB_DEPENDS+=	avahi-core:${PORTSDIR}/net/avahi-app
PLIST_SUB+=	MDNS_AVAHI=""
MAN1+=		xmms2-mdns-avahi.1
.else
EXCLUDE+=	--without-optionals="avahi"
PLIST_SUB+=	MDNS_AVAHI="@comment "
.endif

.if !defined(WITHOUT_MMS)
LIB_DEPENDS+=	mms.0:${PORTSDIR}/net/libmms
PLIST_SUB+=	MMS=""
.else
EXCLUDE+=	--without-plugins="mms"
PLIST_SUB+=	MMS="@comment "
.endif

.if !defined(WITHOUT_MODPLUG)
LIB_DEPENDS+=	modplug.1:${PORTSDIR}/audio/libmodplug
PLIST_SUB+=	MODPLUG=""
.else
EXCLUDE+=	--without-plugins="modplug"
PLIST_SUB+=	MODPLUG="@comment "
.endif

.if !defined(WITHOUT_MPG123)
LIB_DEPENDS+=	mpg123.25:${PORTSDIR}/audio/mpg123
PLIST_SUB+=	MPG123=""
.else
EXCLUDE+=	--without-plugins="mpg123"
PLIST_SUB+=	MPG123="@comment "
.endif

.if !defined(WITHOUT_MUSEPACK)
LIB_DEPENDS+=	mpcdec.5:${PORTSDIR}/audio/libmpcdec
PLIST_SUB+=	MUSEPACK=""
.else
EXCLUDE+=	--without-plugins="musepack"
PLIST_SUB+=	MUSEPACK="@comment "
.endif

.if !defined(WITHOUT_OFA)
LIB_DEPENDS+=	ofa.0:${PORTSDIR}/audio/libofa
PLIST_SUB+=	OFA=""
.else
EXCLUDE+=	--without-plugins="ofa"
PLIST_SUB+=	OFA="@comment "
.endif

.if !defined(WITHOUT_PULSE)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=	PULSE=""
.else
EXCLUDE+=	--without-plugins="pulse"
PLIST_SUB+=	PULSE="@comment "
.endif

.if !defined(WITHOUT_SAMBA)
LIB_DEPENDS+=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
PLIST_SUB+=	SAMBA=""
.else
EXCLUDE+=	--without-plugins="samba"
PLIST_SUB+=	SAMBA="@comment "
.endif

.if !defined(WITHOUT_SID)
LIB_DEPENDS+=	sidplay2.[0-9]:${PORTSDIR}/audio/libsidplay2
PLIST_SUB+=	SID=""
.else
EXCLUDE+=	--without-plugins="sid"
PLIST_SUB+=	SID="@comment "
.endif

.if !defined(WITHOUT_SPEEX)
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
PLIST_SUB+=	SPEEX=""
.else
EXCLUDE+=	--without-plugins="speex"
PLIST_SUB+=	SPEEX="@comment "
.endif

# xmms2-ripper
.if !defined(WITHOUT_VISUAL) && !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbisenc.2:${PORTSDIR}/audio/libvorbis
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-clients-vistest-wscript
.endif

# XXX: shm support requires semtimedop(2)
.if !defined(WITHOUT_VISUAL)
USE_SDL=	yes
LIB_DEPENDS+=	visual-0.4.0:${PORTSDIR}/graphics/libvisual04
PLIST_SUB+=	VISUAL=""
.else
EXCLUDE+=	--without-optionals="vistest"
PLIST_SUB+=	VISUAL="@comment "
.endif

.if !defined(WITHOUT_VOCODER)
LIB_DEPENDS+=	fftw3f.5:${PORTSDIR}/math/fftw3-float
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
PLIST_SUB+=	VOCODER=""
.else
EXCLUDE+=	--without-plugins="vocoder"
PLIST_SUB+=	VOCODER="@comment "
.endif

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	VORBIS=""
.else
EXCLUDE+=	--without-plugins="vorbis"
PLIST_SUB+=	VORBIS="@comment "
.endif

.if !defined(WITHOUT_WAVPACK)
LIB_DEPENDS+=	wavpack.2:${PORTSDIR}/audio/wavpack
PLIST_SUB+=	WAVPACK=""
.else
EXCLUDE+=	--without-plugins="wavpack"
PLIST_SUB+=	WAVPACK="@comment "
.endif

.if !defined(WITHOUT_XML)
USE_GNOME+=	libxml2
PLIST_SUB+=	XML=""
.else
EXCLUDE+=	--without-plugins="xml" --without-plugins="rss" \
		--without-plugins="xspf"
PLIST_SUB+=	XML="@comment "
.endif

.endif # !XMMS2_SLAVE

do-configure:
	cd ${WRKSRC} && ./waf configure --conf-prefix=${LOCALBASE} \
		--prefix=${PREFIX} --with-mandir=${PREFIX}/man ${EXCLUDE}

do-build:
	cd ${WRKSRC} && ./waf build

do-install:
	cd ${WRKSRC} && ./waf install

.include <bsd.port.post.mk>
