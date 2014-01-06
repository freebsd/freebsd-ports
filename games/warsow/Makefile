# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	warsow
PORTVERSION=	0.6.2
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.zcdn.org/dl/
DISTNAME=	${PORTNAME}_${PORTVERSION:R}${PORTVERSION:E}_sdk
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Futuristic, fast-paced first person shooter

LICENSE=	GPLv2

DEPRECATED=	depends on expired games/warsow-data
EXPIRATION_DATE=2014-01-22

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	${DATADIR}/basewsw/data0_06.pk3:${PORTSDIR}/games/warsow-data

ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	yes
USE_ZIP=	yes

WRKSRC=		${WRKDIR}/source
ALL_TARGET=	game angelwrap
RELEASEDIR=	${WRKSRC}/release
AS_SDK_DIR=	${WRKSRC}/../libsrcs/angelscript/angelSVN/sdk

PLIST_FILES=	%%DATADIR%%/basewsw/game_${ARCH}.so \
		%%DATADIR%%/libs/angelwrap_${ARCH}.so
PLIST_DIRS=	%%DATADIR%%/libs

OPTIONS_DEFINE=	CLIENT SERVER QF OPENAL IRC TV_SRV
OPTIONS_DEFAULT=	CLIENT SERVER QF OPENAL IRC TV_SRV

CLIENT_DESC=	Build game client
SERVER_DESC=	Build dedicated server
QF_DESC=	Build Qf sound module
OPENAL_DESC=	Build OpenAL sound module
IRC_DESC=	Build IRC client module
TV_SRV_DESC=	Build Warsow TV server

# USES needs to be before bsd.port.pre.mk
OPENAL_USES=	openal:al

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MCLIENT}
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
USE_GL=		gl
USE_SDL=	sdl
USE_XORG=	xinerama xxf86dga
ALL_TARGET+=	cgame ui client
PLIST_FILES+=	bin/warsow %%DATADIR%%/basewsw/cgame_${ARCH}.so \
		%%DATADIR%%/basewsw/ui_${ARCH}.so

. if ${PORT_OPTIONS:MQF} || ${PORT_OPTIONS:MOPENAL}
LIB_DEPENDS+=	vorbisfile:${PORTSDIR}/audio/libvorbis
. endif

. if ${PORT_OPTIONS:MQF}
USE_SDL=	sdl
ALL_TARGET+=	qf
PLIST_FILES+=	%%DATADIR%%/libs/snd_qf_${ARCH}.so
. endif

. if ${PORT_OPTIONS:MOPENAL}
ALL_TARGET+=	openal
PLIST_FILES+=	%%DATADIR%%/libs/snd_openal_${ARCH}.so
. endif

. if ${PORT_OPTIONS:MIRC}
ALL_TARGET+=	irc
PLIST_FILES+=	%%DATADIR%%/libs/irc_${ARCH}.so
. endif
.endif

.if ${PORT_OPTIONS:MSERVER}
ALL_TARGET+=	ded
PLIST_FILES+=	bin/wsw_server
.endif

.if ${PORT_OPTIONS:MTV_SRV}
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
	${REINPLACE_CMD} -e 's|path", "\.|&:${DATADIR}|' \
		${WRKSRC}/qcommon/files.c
# Adjust architecture names, get rid of ``freebsd_'' prefix
	${REINPLACE_CMD} -e 's/x86_64/amd64/ ; s/freebsd_//' \
		${WRKSRC}/gameshared/q_arch.h
# Resolve name collision with jpeg-8
	${REINPLACE_CMD} -e 's|jpeg_mem_src|local_&|' \
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
	cd ${RELEASEDIR} && ${COPYTREE_SHARE} "basewsw libs" ${DATADIR}

.include <bsd.port.post.mk>
