# New ports collection makefile for:	Warsow
# Date created:				31 May 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	warsow
PORTVERSION=	0.5
CATEGORIES=	games
MASTER_SITES=	http://woe.crying-wolves.net/ \
		http://www.derchris.eu/warsow/ \
		http://warsow.hangy.de/ \
		http://static.warsow.net/release/ \
		http://rewq.de/scratch/wsw05/ \
		http://weseo.de/downloads/
DISTNAME=	${PORTNAME}_${PORTVERSION}_sdk
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A fast paced first person shooter game

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	${DATADIR}/basewsw/data0_05.pk3:${PORTSDIR}/games/warsow-data

ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	yes
USE_ZIP=	yes

WRKSRC=		${WRKDIR}/source
ALL_TARGET=	game
MAKE_ARGS=	PTHREAD_LIBS="${PTHREAD_LIBS}"
RELEASEDIR=	${WRKSRC}/release
WSWSUBDIR=	basewsw

OPTIONS=	CLIENT	"Build client executable"		on \
		SERVER	"Build dedicated server executable"	on \
		QF	"Build Qf sound module"			on \
		OPENAL	"Build OpenAL sound module"		on \
		IRC	"Build IRC client module"		on \
		TV_SRV	"Build Warsow TV server"		on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_SERVER)
IGNORE=		requires at least one of CLIENT or SERVER options
.endif

.if !defined(WITHOUT_CLIENT)
LIB_DEPENDS+=	jpeg.10:${PORTSDIR}/graphics/jpeg
USE_GL=		yes
USE_SDL=	yes
USE_XORG=	xinerama xxf86dga
ALL_TARGET+=	cgame ui client
WSWBIN+=	warsow
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_SERVER)
ALL_TARGET+=	ded
WSWBIN+=	wsw_server
PLIST_SUB+=	SERVER=""
.else
PLIST_SUB+=	SERVER="@comment "
.endif

.if !(defined(WITHOUT_QF) && defined(WITHOUT_OPENAL))
LIB_DEPENDS+=	vorbisfile.6:${PORTSDIR}/audio/libvorbis
.endif

.if !(defined(WITHOUT_QF) && defined(WITHOUT_OPENAL) && defined(WITHOUT_IRC))
WSWSUBDIR+=	libs
.endif

.if !defined(WITHOUT_QF)
USE_SDL=	yes
ALL_TARGET+=	qf
PLIST_SUB+=	QF=""
.else
PLIST_SUB+=	QF="@comment "
.endif

.if !defined(WITHOUT_OPENAL)
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal
ALL_TARGET+=	openal
PLIST_SUB+=	OPENAL=""
.else
PLIST_SUB+=	OPENAL="@comment "
.endif

.if !defined(WITHOUT_IRC)
ALL_TARGET+=	irc
PLIST_SUB+=	IRC=""
.else
PLIST_SUB+=	IRC="@comment "
.endif

.if !defined(WITHOUT_TV_SRV)
ALL_TARGET+=	tv_server
WSWBIN+=	wswtv_server
PLIST_SUB+=	TVSERVER=""
.else
PLIST_SUB+=	TVSERVER="@comment "
.endif

PLIST_SUB+=	ARCH=${ARCH}

post-patch: .SILENT
# Unmute build and link commands, respect CFLAGS
	${REINPLACE_CMD} -e 's|@$$(DO_CC|$$(DO_CC| ; /> Linking $$@/d ; \
		s|-O2 -fno-strict-aliasing -ffast-math -funroll-loops ||' \
			${WRKSRC}/Makefile
# Search directory provided by warsow-data port instead of current.  Doing
# so allows us not to install any wrapper scripts.
	${REINPLACE_CMD} -e 's|path", "\.|path", "${DATADIR}|' \
		${WRKSRC}/qcommon/files.c
# FreeBSD does not use stupid `64' suffix for 64-bit readdir(3)
	${REINPLACE_CMD} -e 's/FILE64_SOURCE)/& || defined(__FreeBSD__)/' \
		${WRKSRC}/unix/unix_fs.c
# Adjust architecture names, get rid of ``freebsd_'' prefix
	${REINPLACE_CMD} -e 's/x86_64/amd64/ ; s/freebsd_//' \
		${WRKSRC}/gameshared/q_arch.h

do-install:
.for b in ${WSWBIN}
	${INSTALL_PROGRAM} ${RELEASEDIR}/${b}.${ARCH} ${PREFIX}/bin/${b}
.endfor
	cd ${RELEASEDIR} && ${COPYTREE_SHARE} "${WSWSUBDIR}" ${DATADIR}

.include <bsd.port.post.mk>
