# New ports collection makefile for:    xmms2
# Date created:				20 May 2005
# Whom:				  	Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME?=	xmms2
PORTVERSION=	0.2.d.8
PORTREVISION=	1
DISTVERSION=	0.2DrHouse
CATEGORIES?=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	alexbl@FreeBSD.org
COMMENT?=	Rewrite of xmms as a client/server system (developer release)

.if !defined(XMMS2_SLAVE)
LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		vorbis.3:${PORTSDIR}/audio/libvorbis
.endif

USE_BZIP2=	yes
USE_SCONS=	yes
SCONS_ARGS=	INSTALLDIR=${DESTDIR} SHAREDIR=${DATADIR} EXCLUDE="${EXCLUDE}"

.if !defined(XMMS2_SLAVE)
USE_GNOME=	glib20
USE_SQLITE=	3

USE_LDCONFIG=	yes
.endif

.if !defined(XMMS2_SLAVE)
MAN1=		xmms2.1 xmms2-et.1 xmms2d.1 xmms2-launcher.1 xmms2-mdns-avahi.1
MANCOMPRESSED=	yes

OPTIONS=	FAAD "Support to playback AAC files" on \
		FLAC "Support to playback FLAC files" on \
		MODPLUG "Support to playback MOD files" off \
		MUSEPACK "Support to playback MPC files" off \
		SID "Support to playback SID files" off \
		WMA "Support to playback WMA files" off \
		APE "Support to playback Monkey's Audio files" off \
		CURL "Support to playback files via HTTP" on \
		LASTFM "Support to playback audio via Last.fm radio" on \
		GNOMEVFS "Support to playback files via GnomeVFS" off \
		MMS "Support to playback streams via MMS" off \
		SAMBA "Support to playback files via SMB" off \
		DAAP "Support to playback files via DAAP" on \
		FAM "Support to update Media Library on file change" off \
		MDNS_AVAHI "Support to announce XMMS2d via mDNS (Avahi)" off \
		MDNS_APPLE "Support to announce XMMS2d via mDNS (Apple)" on \
		ICES "Support to playback files to an icecast server" off \
		JACK "Support to output via the Jack output server" off \
		AO "Support to output via libao" off \
		VOCODER "Phase Vocoder effect plugin" off #\
#		SDL "Support for visualization" on
.endif

.include <bsd.port.pre.mk>

.if defined(XMMS2_SLAVE) && ${XMMS2_SLAVE} == "python"
EXCLUDE+=	ruby java xmmsclient-ecore xmmsclient++ xmmsclient++-glib
.elif defined(XMMS2_SLAVE) && ${XMMS2_SLAVE} == "ruby"
EXCLUDE+=	python java xmmsclient-ecore xmmsclient++ xmmsclient++-glib
.elif defined(XMMS2_SLAVE) && ${XMMS2_SLAVE} == "ruby-ecore"
EXCLUDE+=	python java xmmsclient++ xmmsclient++-glib
.elif defined(XMMS2_SLAVE) && ${XMMS2_SLAVE} == "java"
EXCLUDE+=	ruby python xmmsclient-ecore xmmsclient++ xmmsclient++-glib
.elif defined(XMMS2_SLAVE) && ${XMMS2_SLAVE} == "cpp"
EXCLUDE+=	ruby python java xmmsclient-ecore
.elif !defined(XMMS2_SLAVE)
EXCLUDE+=	python ruby java xmmsclient-ecore xmmsclient++ xmmsclient++-glib
.endif

.if !defined(XMMS2_SLAVE)
.if !defined(WITHOUT_CURL)
LIB_DEPENDS+=	curl.4:${PORTSDIR}/ftp/curl
PLIST_SUB+=	CURL=""
.else
EXCLUDE+=	curl
PLIST_SUB+=	CURL="@comment "
.endif

.if !defined(WITHOUT_LASTFM)
.if defined(WITHOUT_CURL)
LIB_DEPENDS+=	curl.3:${PORTSDIR}/ftp/curl
.endif
PLIST_SUB+=	LASTFM=""
.else
EXCLUDE+=	lastfm lastfmeta
PLIST_SUB+=	LASTFM="@comment "
.endif

.if defined(WITH_SID)
LIB_DEPENDS+=	sidplay2.[0-9]:${PORTSDIR}/audio/libsidplay2
PLIST_SUB+=	SID=""
.else
EXCLUDE+=	sid
PLIST_SUB+=	SID="@comment "
.endif

.if !defined(WITHOUT_FLAC)
LIB_DEPENDS+=	FLAC.7:${PORTSDIR}/audio/flac
PLIST_SUB+=	FLAC=""
.else
EXCLUDE+=	flac
PLIST_SUB+=	FLAC="@comment "
.endif

.if !defined(WITHOUT_FAAD)
LIB_DEPENDS+=	faad.0:${PORTSDIR}/audio/faad
PLIST_SUB+=	FAAD=""
.else
EXCLUDE+=	faad
PLIST_SUB+=	FAAD="@comment "
.endif

.if defined(WITH_WMA)
LIB_DEPENDS+=	avutil.1:${PORTSDIR}/multimedia/ffmpeg-devel
PLIST_SUB+=	WMA=""
.else
EXCLUDE+=	wma
PLIST_SUB+=	WMA="@comment "
.endif

.if defined(WITH_APE)
LIB_DEPENDS+=	mac.2:${PORTSDIR}/audio/mac
PLIST_SUB+=	MAC=""
.else
EXCLUDE+=	mac
PLIST_SUB+=	MAC="@comment "
.endif

.if !defined(WITHOUT_SDL) && defined(UNDEFINED)
IGNORE=		visualization has not been updated to the Transforms API
USE_SDL=	sdl ttf
PLIST_SUB+=	SDL=""
#EXTRA_PATCHES+=	${FILESDIR}/extraPatch-src::clients::sdl-vis::Program
.else
EXCLUDE+=	sdl-vis
PLIST_SUB+=	SDL="@comment "
.endif

.if defined(WITH_MUSEPACK)
LIB_DEPENDS+=	mpcdec.5:${PORTSDIR}/audio/libmpcdec
PLIST_SUB+=	MUSEPACK=""
.else
EXCLUDE+=	musepack
PLIST_SUB+=	MUSEPACK="@comment "
.endif

.if defined(WITH_JACK)
IGNORE=		the Jack plugin has not been updated to the Transforms API
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
PLIST_SUB+=	JACK=""
.else
EXCLUDE+=	jack
PLIST_SUB+=	JACK="@comment "
.endif

.if defined(WITH_MODPLUG)
LIB_DEPENDS+=	modplug.0:${PORTSDIR}/audio/libmodplug
PLIST_SUB+=	MODPLUG=""
.else
EXCLUDE+=	modplug
PLIST_SUB+=	MODPLUG="@comment "
.endif

.if defined(WITH_SAMBA)
LIB_DEPENDS+=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
PLIST_SUB+=	SAMBA=""
.else
EXCLUDE+=	samba
PLIST_SUB+=	SAMBA="@comment "
.endif

.if !defined(WITHOUT_DAAP)
PLIST_SUB+=	DAAP=""
.else
EXCLUDE+=	daap
PLIST_SUB+=	DAAP="@comment "
.endif

.if defined(WITH_GNOMEVFS)
USE_GNOME+=	gnomevfs2
PLIST_SUB+=	GNOMEVFS=""
.else
EXCLUDE+=	gnomevfs
PLIST_SUB+=	GNOMEVFS="@comment "
.endif

.if defined(WITH_MMS)
LIB_DEPENDS+=	mms.0:${PORTSDIR}/net/libmms
PLIST_SUB+=	MMS=""
.else
EXCLUDE+=	mms
PLIST_SUB+=	MMS="@comment "
.endif

.if defined(WITH_FAM)
USE_FAM=	yes
WANT_FAM_SYSTEM=gamin
PLIST_SUB+=	FAM=""
.else
EXCLUDE+=	medialib-updater
PLIST_SUB+=	FAM="@comment "
.endif

.if defined(WITH_ICES)
LIB_DEPENDS+=	shout.5:${PORTSDIR}/audio/libshout2
PLIST_SUB+=	ICES=""
.else
EXCLUDE+=	ices
PLIST_SUB+=	ICES="@comment "
.endif

.if defined(WITH_AO)
LIB_DEPENDS+=	ao.3:${PORTSDIR}/audio/libao
PLIST_SUB+=	AO=""
.else
EXCLUDE+=	ao
PLIST_SUB+=	AO="@comment "
.endif

.if defined(WITH_MDNS_AVAHI)
.if !defined(WITHOUT_MDNS_APPLE)
BROKEN=		You may choose either MDNS_APPLE or MDNS_AVAHI, but not both
.endif
EXCLUDE+=	dnssd dns_sd
LIB_DEPENDS+=	avahi-core:${PORTSDIR}/net/avahi
PLIST_SUB+=	MDNS_AVAHI=""
.else
EXCLUDE+=	avahi
PLIST_SUB+=	MDNS_AVAHI="@comment "
.endif

.if !defined (WITHOUT_MDNS_APPLE)
.if defined(WITH_MDNS_AVAHI)
BROKEN=		You may choose either MDNS_APPLE or MDNS_AVAHI, but not both
.endif
EXCLUDE+=	avahi
LIB_DEPENDS+=	dns_sd:${PORTSDIR}/net/mDNSResponder
PLIST_SUB+=	MDNS_APPLE=""
.else
EXCLUDE+=	dnssd dns_sd
PLIST_SUB+=	MDNS_APPLE="@comment "
.endif
.endif

.if defined(WITH_VOCODER)
LIB_DEPENDS+=	fftw3f.4:${PORTSDIR}/math/fftw3-float
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
PLIST_SUB+=	VOCODER=""
.else
EXCLUDE+=	vocoder
PLIST_SUB+=	VOCODER="@comment "
.endif

.include <bsd.port.post.mk>
