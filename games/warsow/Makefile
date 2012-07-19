# New ports collection makefile for:	Warsow
# Date created:				31 May 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	warsow
PORTVERSION=	0.6.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.zcdn.org/dl/
DISTNAME=	${PORTNAME}_${PORTVERSION:R}${PORTVERSION:E}_sdk
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A futuristic, fast-paced first person shooter

LICENSE=	GPLv2

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	${DATADIR}/basewsw/data0_06.pk3:${PORTSDIR}/games/warsow-data

ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	yes
USE_ZIP=	yes

WRKSRC=		${WRKDIR}/source
ALL_TARGET=	game angelwrap
RELEASEDIR=	${WRKSRC}/release
AS_SDK_DIR=	${WRKSRC}/../libsrcs/angelscript/angelSVN/sdk
WSWSUBDIR=	basewsw libs

PLIST_FILES=	%%DATADIR%%/basewsw/game_${ARCH}.so \
		%%DATADIR%%/libs/angelwrap_${ARCH}.so
PLIST_DIRS=	%%DATADIR%%/libs

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
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
USE_GL=		yes
USE_SDL=	yes
USE_XORG=	xinerama xxf86dga
ALL_TARGET+=	cgame ui client
PLIST_FILES+=	bin/warsow %%DATADIR%%/basewsw/cgame_${ARCH}.so \
		%%DATADIR%%/basewsw/ui_${ARCH}.so
.endif

.if !defined(WITHOUT_SERVER)
ALL_TARGET+=	ded
PLIST_FILES+=	bin/wsw_server
.endif

.if !(defined(WITHOUT_QF) && defined(WITHOUT_OPENAL))
LIB_DEPENDS+=	vorbisfile.6:${PORTSDIR}/audio/libvorbis
.endif

.if !defined(WITHOUT_QF)
USE_SDL=	yes
ALL_TARGET+=	qf
PLIST_FILES+=	%%DATADIR%%/libs/snd_qf_${ARCH}.so
.endif

.if !defined(WITHOUT_OPENAL)
USE_OPENAL=	al
ALL_TARGET+=	openal
PLIST_FILES+=	%%DATADIR%%/libs/snd_openal_${ARCH}.so
.endif

.if !defined(WITHOUT_IRC)
ALL_TARGET+=	irc
PLIST_FILES+=	%%DATADIR%%/libs/irc_${ARCH}.so
.endif

.if !defined(WITHOUT_TV_SRV)
ALL_TARGET+=	tv_server
PLIST_FILES+=	bin/wswtv_server
.endif

post-extract:
	${CP} ${FILESDIR}/keysym2ucs.* ${WRKSRC}/unix

post-patch: .SILENT
# Unmute build and link commands, respect CFLAGS, fix hardcoded make(1)
	${REINPLACE_CMD} -e 's|@$$(DO_CC|$$(DO_CC| ; /> Linking $$@/d ; \
		s|-O2 -fno-strict-aliasing -ffast-math -funroll-loops || ; \
		s|make -C|$$(MAKE) -C|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|-g ||' \
		${AS_SDK_DIR}/angelscript/projects/gnuc/makefile
# Search directory provided by warsow-data port instead of current (doing
# so allows us not to install any wrapper scripts)
	${REINPLACE_CMD} -e 's|path", "\.|path", "${DATADIR}|' \
		${WRKSRC}/qcommon/files.c
# Adjust architecture names, get rid of ``freebsd_'' prefix
	${REINPLACE_CMD} -e 's/x86_64/amd64/ ; s/freebsd_//' \
		${WRKSRC}/gameshared/q_arch.h
# Resolve name collision with jpeg-8
	${REINPLACE_CMD} -e 's|jpeg_mem_src|local_jpeg_mem_src|' \
		${WRKSRC}/ref_gl/r_image.c
# Add missing #include's
	${REINPLACE_CMD} -e '24s|^|#include <sys/socket.h>|' \
		${WRKSRC}/qcommon/net.c
	${REINPLACE_CMD} -e '19s|^|#include <stdint.h>|' \
		${WRKSRC}/unix/unix_xpm.c
# Fix AngelScript build on 64-bit arches
	${REINPLACE_CMD} -e '/GetCurrentThreadId/!s|asDWORD|pthread_t| ; \
		s|(asDWORD)||' ${AS_SDK_DIR}/angelscript/source/as_thread.*

do-install:
.for b in ${PLIST_FILES:Mbin/*:T}
	${INSTALL_PROGRAM} ${RELEASEDIR}/${b}.${ARCH} ${PREFIX}/bin/${b}
.endfor
	cd ${RELEASEDIR} && ${COPYTREE_SHARE} "${WSWSUBDIR}" ${DATADIR}

.include <bsd.port.post.mk>
