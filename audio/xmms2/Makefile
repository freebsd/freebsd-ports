# New ports collection makefile for:    xmms2
# Date created:				20 May 2005
# Whom:				  	Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	xmms2
PORTVERSION=	0.2.d.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-0.2DrCox

MAINTAINER=	alex@foxybanana.com
COMMENT=	Rewrite of xmms as a client/server system (developer release)

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons
LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		vorbis.3:${PORTSDIR}/audio/libvorbis

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_PYTHON_BUILD=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20
USE_SQLITE=	3
INSTALLS_SHLIB=	yes

MAN1=		xmms2.1
MAN8=		xmms2d.8
MANCOMPRESSED=	yes

DATADIR=	share/xmms2

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

.if defined(WITH_PYTHON_BINDINGS)
BUILD_DEPENDS+=	pyrex:${PORTSDIR}/devel/pyrex
USE_PYTHON_RUN=	yes
PLIST_SUB+=	PYTHON=""
.else
EXCLUDE+=	python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(WITH_RUBY_BINDINGS)
USE_RUBY=	yes
PLIST_SUB+=	RUBY=""
.else
EXCLUDE+=	ruby
PLIST_SUB+=	RUBY="@comment "
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
LIB_DEPENDS+=	mpcdec.3:${PORTSDIR}/audio/libmpcdec
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

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not build on FreeBSD < 5.x
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

do-build:
	cd ${WRKSRC} && \
		scons CC=${CC} LINKFLAGS="${LDFLAGS}" CCFLAGS="${CFLAGS}" \
		LIBPATH=${LOCALBASE}/lib CPPPATH=${LOCALBASE}/include \
		PKGCONFIGDIR=${PREFIX}/libdata/pkgconfig EXCLUDE="${EXCLUDE}" \
		PREFIX="${PREFIX}"

do-install:
	@cd ${WRKSRC} && scons install

.include <bsd.port.post.mk>
