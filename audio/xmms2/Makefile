# New ports collection makefile for:    xmms2
# Date created:				20 May 2005
# Whom:				  	Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME?=	xmms2
DISTVERSION=	0.5.d.0
DISTVERSION=	0.5DrLecter
CATEGORIES?=	audio
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${DISTVERSION}
PORTREVISION?=	2

MAINTAINER=	alexbl@FreeBSD.org
COMMENT?=	Rewrite of xmms as a client/server system (developer release)

.if !defined(XMMS2_SLAVE)
LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		vorbis.4:${PORTSDIR}/audio/libvorbis
.endif

USE_BZIP2=	yes
USE_PYTHON_BUILD=	yes

.if !defined(XMMS2_SLAVE)
USE_GNOME=	glib20
USE_SQLITE=	3

USE_LDCONFIG=	yes
.endif

.if !defined(XMMS2_SLAVE)
MAN1=		xmms2.1 xmms2-et.1 xmms2d.1 xmms2-launcher.1
MANCOMPRESSED=	yes

OPTIONS=	FAAD "Support to playback AAC files" on \
		FLAC "Support to playback FLAC files" on \
		SPEEX "Support to playback SPEEX files" off \
		CDDA "Support to playback AudioCD" off \
		MODPLUG "Support to playback MOD files" off \
		MUSEPACK "Support to playback MPC files" off \
		SID "Support to playback SID files" off \
		AVCODEC "Support to playback files with avcodec" off \
		APE "Support to playback Monkey's Audio files" off \
		CURL "Support to playback files via HTTP" on \
		LASTFM "Support to playback audio via Last.fm radio" on \
		GVFS "Support to playback files via GVFS" off \
		MMS "Support to playback streams via MMS" off \
		SAMBA "Support to playback files via SMB" off \
		DAAP "Support to playback files via DAAP" on \
		GME "Support to playback files via GME (SPC/NSF/GBS)" on \
		OFA "Support to collect MusicDNS fingerprints" off \
		XML "Support for XML based playlists (XSPF, RSS)" off \
		FAM "Support to update Media Library on file change" off \
		MDNS_AVAHI "Support to announce XMMS2d via mDNS (Avahi)" off \
		MDNS_APPLE "Support to announce XMMS2d via mDNS (Apple)" on \
		ICES "Support to playback files to an icecast server" off \
		JACK "Support to output via the Jack output server" off \
		PULSE "Support to output via the PulseAudio" off \
		AO "Support to output via libao" off \
		KARAOKE "Karaoke plugin for voice removal from tracks" on \
		VOCODER "Phase Vocoder effect plugin" off #\
#		SDL "Support for visualization" on
.endif

.include <bsd.port.pre.mk>

.if defined(XMMS2_SLAVE)
EXCLUDE+=	--without-xmms2d=1
.endif

.if defined(XMMS2_SLAVE) && ${XMMS2_SLAVE} == "python"
EXCLUDE+=	--with-optionals="python"
.elif defined(XMMS2_SLAVE) && ${XMMS2_SLAVE} == "ruby"
EXCLUDE+=	--with-optionals="ruby"
.elif defined(XMMS2_SLAVE) && ${XMMS2_SLAVE} == "perl"
EXCLUDE+=	--with-optionals="perl"
.elif defined(XMMS2_SLAVE) && ${XMMS2_SLAVE} == "ruby-ecore"
EXCLUDE+=	--with-optionals="ruby" --with-optionals="xmmsclient-ecore"
.elif defined(XMMS2_SLAVE) && ${XMMS2_SLAVE} == "cpp"
EXCLUDE+=	--with-optionals="xmmsclient++" --with-optionals="xmmsclient++-glib"
.elif !defined(XMMS2_SLAVE)
EXCLUDE+=	--without-optionals="python" --without-optionals="ruby" --without-optionals="xmmsclient-ecore" --without-optionals="xmmsclient++" --without-optionals="xmmsclient++-glib" --without-optionals="perl"
.endif

.if !defined(XMMS2_SLAVE)

.if !defined(WITHOUT_CURL)
LIB_DEPENDS+=	curl.5:${PORTSDIR}/ftp/curl
PLIST_SUB+=	CURL=""
.else
EXCLUDE+=	--without-plugins="curl" --without-plugins="icymetaint"
PLIST_SUB+=	CURL="@comment "
.endif

.if !defined(WITHOUT_LASTFM)
.if defined(WITHOUT_CURL)
LIB_DEPENDS+=	curl.3:${PORTSDIR}/ftp/curl
.endif
PLIST_SUB+=	LASTFM=""
.else
EXCLUDE+=	--without-plugins="lastfm" --without-plugins="lastfmeta"
PLIST_SUB+=	LASTFM="@comment "
.endif

.if defined(WITH_SID)
LIB_DEPENDS+=	sidplay2.[0-9]:${PORTSDIR}/audio/libsidplay2
PLIST_SUB+=	SID=""
.else
EXCLUDE+=	--without-plugins="sid"
PLIST_SUB+=	SID="@comment "
.endif

.if !defined(WITHOUT_FLAC)
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
PLIST_SUB+=	FLAC=""
.else
EXCLUDE+=	--without-plugins="flac"
PLIST_SUB+=	FLAC="@comment "
.endif

.if defined(WITH_SPEEX)
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
PLIST_SUB+=	SPEEX=""
.else
EXCLUDE+=	--without-plugins="speex"
PLIST_SUB+=	SPEEX="@comment "
.endif

.if defined(WITH_CDDA)
LIB_DEPENDS+=	cdio.8:${PORTSDIR}/sysutils/libcdio \
		discid.2:${PORTSDIR}/audio/libdiscid
PLIST_SUB+=	CDDA=""
.else
EXCLUDE+=	--without-plugins="cdda"
PLIST_SUB+=	CDDA="@comment "
.endif

.if !defined(WITHOUT_FAAD)
LIB_DEPENDS+=	faad.2:${PORTSDIR}/audio/faad
PLIST_SUB+=	FAAD=""
.else
EXCLUDE+=	--without-plugins="faad" --without-plugins="mp4"
PLIST_SUB+=	FAAD="@comment "
.endif

.if defined(WITH_AVCODEC)
LIB_DEPENDS+=	avutil.1:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=	AVCODEC=""
.else
EXCLUDE+=	--without-plugins="avcodec"
PLIST_SUB+=	AVCODEC="@comment "
.endif

.if defined(WITH_APE)
LIB_DEPENDS+=	mac.2:${PORTSDIR}/audio/mac
PLIST_SUB+=	MAC=""
.else
EXCLUDE+=	--without-plugins="mac"
PLIST_SUB+=	MAC="@comment "
.endif

.if !defined(WITHOUT_SDL) && defined(UNDEFINED)
IGNORE=		visualization has not been updated to the Transforms API
USE_SDL=	sdl ttf
PLIST_SUB+=	SDL=""
#EXTRA_PATCHES+=	${FILESDIR}/extraPatch-src::clients::sdl-vis::Program
.else
PLIST_SUB+=	SDL="@comment "
.endif

.if defined(WITH_MUSEPACK)
LIB_DEPENDS+=	mpcdec.5:${PORTSDIR}/audio/libmpcdec
PLIST_SUB+=	MUSEPACK=""
.else
EXCLUDE+=	--without-plugins="musepack"
PLIST_SUB+=	MUSEPACK="@comment "
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
PLIST_SUB+=	JACK=""
.else
EXCLUDE+=	--without-plugins="jack"
PLIST_SUB+=	JACK="@comment "
.endif

.if defined(WITH_PULSE)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=	PULSE=""
.else
EXCLUDE+=	--without-plugins="pulse"
PLIST_SUB+=	PULSE="@comment "
.endif

.if defined(WITH_MODPLUG)
LIB_DEPENDS+=	modplug.0:${PORTSDIR}/audio/libmodplug
PLIST_SUB+=	MODPLUG=""
.else
EXCLUDE+=	--without-plugins="modplug"
PLIST_SUB+=	MODPLUG="@comment "
.endif

.if defined(WITH_OFA)
LIB_DEPENDS+=	ofa.0:${PORTSDIR}/audio/libofa
PLIST_SUB+=	OFA=""
.else
EXCLUDE+=	--without-plugins="ofa"
PLIST_SUB+=	OFA="@comment "
.endif

.if defined(WITH_XML)
USE_GNOME=	libxml2
PLIST_SUB+=	XML=""
.else
EXCLUDE+=	--without-plugins="xml" --without-plugins="rss" --without-plugins="xspf"
PLIST_SUB+=	XML="@comment "
.endif

.if defined(WITH_SAMBA)
LIB_DEPENDS+=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
PLIST_SUB+=	SAMBA=""
.else
EXCLUDE+=	--without-plugins="samba"
PLIST_SUB+=	SAMBA="@comment "
.endif

.if !defined(WITHOUT_DAAP)
PLIST_SUB+=	DAAP=""
.else
EXCLUDE+=	--without-plugins="daap"
PLIST_SUB+=	DAAP="@comment "
.endif

.if !defined(WITHOUT_GME)
PLIST_SUB+=	GME=""
.else
EXCLUDE+=	--without-plugins="gme"
PLIST_SUB+=	GME="@comment "
.endif

.if defined(WITH_GVFS)
USE_GNOME+=	gvfs
PLIST_SUB+=	GVFS=""
.else
EXCLUDE+=	--without-plugins="gvfs"
PLIST_SUB+=	GVFS="@comment "
.endif

.if defined(WITH_MMS)
LIB_DEPENDS+=	mms.0:${PORTSDIR}/net/libmms
PLIST_SUB+=	MMS=""
.else
EXCLUDE+=	--without-plugins="mms"
PLIST_SUB+=	MMS="@comment "
.endif

.if defined(WITH_FAM)
USE_FAM=	yes
WANT_FAM_SYSTEM=gamin
PLIST_SUB+=	FAM=""
.else
EXCLUDE+=	--without-optionals="medialib-updater"
PLIST_SUB+=	FAM="@comment "
.endif

.if defined(WITH_ICES)
LIB_DEPENDS+=	shout.5:${PORTSDIR}/audio/libshout2
PLIST_SUB+=	ICES=""
.else
EXCLUDE+=	--without-plugins="ices"
PLIST_SUB+=	ICES="@comment "
.endif

# FIXME: requires pkg-config data of openssl
.if defined(WITH_AIRPLAY)
PLIST_SUB+=	AIRPLAY=""
.else
EXCLUDE+=	--without-plugins="airplay"
PLIST_SUB+=	AIRPLAY="@comment "
.endif

.if defined(WITH_AO)
LIB_DEPENDS+=	ao.3:${PORTSDIR}/audio/libao
PLIST_SUB+=	AO=""
.else
EXCLUDE+=	--without-plugins="ao"
PLIST_SUB+=	AO="@comment "
.endif

.if defined(WITH_MDNS_AVAHI)
.if !defined(WITHOUT_MDNS_APPLE)
BROKEN=		You may choose either MDNS_APPLE or MDNS_AVAHI, but not both
.endif
EXCLUDE+=	--without-optionals="dns_sd"
LIB_DEPENDS+=	avahi-core:${PORTSDIR}/net/avahi-app
PLIST_SUB+=	MDNS_AVAHI=""
MAN1+=	xmms2-mdns-avahi.1
.else
EXCLUDE+=	--without-optionals="avahi"
PLIST_SUB+=	MDNS_AVAHI="@comment "
.endif

.if !defined (WITHOUT_MDNS_APPLE)
.if defined(WITH_MDNS_AVAHI)
BROKEN=		You may choose either MDNS_APPLE or MDNS_AVAHI, but not both
.endif
EXCLUDE+=	--without-optionals="avahi"
LIB_DEPENDS+=	dns_sd:${PORTSDIR}/net/mDNSResponder
PLIST_SUB+=	MDNS_APPLE=""
.else
EXCLUDE+=	--without-optionals="dns_sd"
PLIST_SUB+=	MDNS_APPLE="@comment "
.endif

.if !defined(WITHOUT_KARAOKE)
PLIST_SUB+=	KARAOKE=""
.else
EXCLUDE+=	--without-plugins="karaoke"
PLIST_SUB+=	KARAOKE="@comment "
.endif

.if defined(WITH_VOCODER)
LIB_DEPENDS+=	fftw3f.5:${PORTSDIR}/math/fftw3-float
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
PLIST_SUB+=	VOCODER=""
.else
EXCLUDE+=	--without-plugins="vocoder"
PLIST_SUB+=	VOCODER="@comment "
.endif
.endif

do-configure:
	cd ${WRKSRC} && ./waf configure --conf-prefix=${LOCALBASE} --prefix=${PREFIX} --with-mandir=${PREFIX}/man ${EXCLUDE}

do-build:
	cd ${WRKSRC} && ./waf build

do-install:
	cd ${WRKSRC} && ./waf install

.include <bsd.port.post.mk>
