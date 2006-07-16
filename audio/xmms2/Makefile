# New ports collection makefile for:    xmms2
# Date created:				20 May 2005
# Whom:				  	Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME?=	xmms2
PORTVERSION=	0.2.d.6
CATEGORIES?=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-0.2DrFeelgood

MAINTAINER=	alex@foxybanana.com
COMMENT?=	Rewrite of xmms as a client/server system (developer release)

.if !defined(XMMS2_SLAVE)
LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		vorbis.3:${PORTSDIR}/audio/libvorbis
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_PYTHON_BUILD=	yes
USE_BZIP2=	yes
USE_SCONS=	yes
SCONS_ARGS=	EXCLUDE="${EXCLUDE}"

.if !defined(XMMS2_SLAVE)
USE_GNOME=	glib20
USE_SQLITE=	3

USE_LDCONFIG=	yes
.endif

.if !defined(XMMS2_SLAVE)
MAN1=		xmms2.1 xmms2-et.1
MAN8=		xmms2d.8
MANCOMPRESSED=	yes

OPTIONS=	FAAD "Support to playback AAC files" on \
		FLAC "Support to playback FLAC files" on \
		MODPLUG "Support to playback MOD files" off \
		MUSEPACK "Support to playback MPC files" off \
		SID "Support to playback SID files" off \
		WMA "Support to playback WMA files" off \
		CURL "Support to playback files via HTTP" on \
		GNOMEVFS "Support to playback files via GnomeVFS" off \
		MMS "Support to playback streams via MMS" off \
		SAMBA "Support to playback files via SMB" off \
		FAM "Support to update Media Library on file change" off \
		MDNS "Support to announce XMMS2d via mDNS" off #\
#		SDL "Support for visualization" on \
#		JACK "Support to output via the Jack output server" off
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
LIB_DEPENDS+=	curl.3:${PORTSDIR}/ftp/curl
PLIST_SUB+=	CURL=""
.else
EXCLUDE+=	curl
PLIST_SUB+=	CURL="@comment "
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
LIB_DEPENDS+=	mpcdec.4:${PORTSDIR}/audio/libmpcdec
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

.if defined(WITH_MDNS)
LIB_DEPENDS+=	avahi-core:${PORTSDIR}/net/avahi
PLIST_SUB+=	MDNS=""
.else
EXCLUDE+=	mdns
PLIST_SUB+=	MDNS="@comment "
.endif
.endif

.if defined(XMMS2_SLAVE) && ${XMMS2_SLAVE} != "java"
.if ${OSVERSION} < 500000
IGNORE=	broken on FreeBSD 4.x
.endif
.endif

.include <bsd.port.post.mk>
