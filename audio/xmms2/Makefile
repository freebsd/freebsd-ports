# New ports collection makefile for:    xmms2
# Date created:				20 May 2005
# Whom:				  	Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	xmms2
PORTVERSION=	0.2.d.4
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-0.2DrDolittle

MAINTAINER=	alex@foxybanana.com
.if !defined(XMMS2_SLAVE)
COMMENT=	Rewrite of xmms as a client/server system (developer release)
.endif

BUILD_DEPENDS+=	scons:${PORTSDIR}/devel/scons
.if !defined(XMMS2_SLAVE)
LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		vorbis.3:${PORTSDIR}/audio/libvorbis
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_PYTHON_BUILD=	yes
USE_BZIP2=	yes

.if !defined(XMMS2_SLAVE)
USE_GNOME=	glib20
USE_SQLITE=	3

INSTALLS_SHLIB=	yes
.endif

.if !defined(XMMS2_SLAVE)
MAN1=		xmms2.1
MAN8=		xmms2d.8
MANCOMPRESSED=	yes
.endif

SCONS_TARGET?=

.if defined(WITH_CURL)
LIB_DEPENDS+=	curl.3:${PORTSDIR}/ftp/curl
PLIST_SUB+=	CURL=""
.else
EXCLUDE+=	curl
PLIST_SUB+=	CURL="@comment "
.endif

.if defined(WITH_SID)
LIB_DEPENDS+=	resid.[0-9]:${PORTSDIR}/audio/resid \
		sidplay2.[0-9]:${PORTSDIR}/audio/libsidplay2
PLIST_SUB+=	SID=""
.else
EXCLUDE+=	sid
PLIST_SUB+=	SID="@comment "
.endif

.if defined(XMMS2_SLAVE) && ${XMMS2_SLAVE} == "python"
EXCLUDE+=	ruby java
.elif defined(XMMS2_SLAVE) && ${XMMS2_SLAVE} == "ruby"
EXCLUDE+=	python java
.elif defined(XMMS2_SLAVE) && ${XMMS2_SLAVE} == "java"
EXCLUDE+=	ruby python
.elif !defined(XMMS2_SLAVE)
EXCLUDE+=	python ruby java
.endif

.if defined(WITH_ECORE)
LIB_DEPENDS+=	lecore.1:${PORTSDIR}/x11/ecore
PLIST_SUB+=	ECORE=""
.else
EXCLUDE+=	xmmsclient-ecore
PLIST_SUB+=	ECORE="@comment "
.endif

.if defined(WITH_FLAC)
LIB_DEPENDS+=	FLAC.7:${PORTSDIR}/audio/flac
PLIST_SUB+=	FLAC=""
.else
EXCLUDE+=	flac
PLIST_SUB+=	FLAC="@comment "
.endif

.if defined(WITH_FAAD)
LIB_DEPENDS+=	faad.0:${PORTSDIR}/audio/faad
PLIST_SUB+=	FAAD=""
#EXTRA_PATCHES+=	${FILESDIR}/extraPatch-src::clients::faad::Plugin
.else
EXCLUDE+=	faad
PLIST_SUB+=	FAAD="@comment "
.endif

.if defined(WITH_SDL)
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

.include <bsd.port.pre.mk>

.if defined(XMMS2_SLAVE) && ${XMMS2_SLAVE} != "java"
.if ${OSVERSION} < 500000
BROKEN=	Broken on FreeBSD 4.x
.endif
.endif

pre-everything::
.if defined(WITH_SAMBA)
	@${ECHO_MSG} "WARNING: Samba plugin is experimental and not fully working"
	@${ECHO_MSG} ""
.endif
.if defined(WITH_GNOMEVFS)
	@${ECHO_MSG} "WARNING: Gnome VFS plugin is experimental and not fully working"
	@${ECHO_MSG} ""
.endif
.if defined(WITH_FAM)
	@${ECHO_MSG} "WARNING: Fam plugin is experimental and not fully working"
	@${ECHO_MSG} ""
.endif

# Nasty fulhack here to deal with java port. We're dealing with this issue
# in xmms2 upstream land, so it hopefully won't be a problem next release.

do-build:
	cd ${WRKSRC} && \
		${SETENV} JAVA_HOME=${JAVA_HOME} scons CC=${CC} LINKFLAGS="${LDFLAGS}" CCFLAGS="${CFLAGS}" \
		LIBPATH=${LOCALBASE}/lib CPPPATH=${LOCALBASE}/include \
		PKGCONFIGDIR=${PREFIX}/libdata/pkgconfig EXCLUDE="${EXCLUDE}" \
		PREFIX="${PREFIX}" ${SCONS_TARGET}

.if !defined(XMMS2_SLAVE)
do-install:
	@cd ${WRKSRC} && scons install
.endif

.include <bsd.port.post.mk>
