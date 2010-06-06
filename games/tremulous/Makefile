# New ports collection makefile for:	Tremulous
# Date created:				3 Jun 2006
# Whom:				Alejandro Pulver <alepulver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tremulous
PORTVERSION=	1.1.0
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.1 \
		http://0day.icculus.org/mirrors/tremulous/ \
		ftp://ftp.wireplay.co.uk/pub/quake3arena/mods/tremulous/ \
		http://www.planetgloom.com/trem/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Free FPS game featuring two opposing teams, humans and aliens

USE_ZIP=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/${DISTNAME}-src

OPTIONS=	CLIENT		"Build client" on \
		GAMELIBS	"Build game libraries (when not mandatory)" off \
		DEDICATED	"Build dedicated server" on \
		MASTER_SERVER	"Build master server" off \
		OPENAL		"Enable OpenAL (3D sound) support" off \
		OPENAL_DLOPEN	"Enable dynamic loading of OpenAL" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL_AUDIO	"Use SDL for audio" off \
		SDL_VIDEO	"Use SDL for video" off \
		SMP		"Build SMP (threaded) client" on \
		VORBIS		"Enable Ogg Vorbis codec support" off

MAKE_ENV+=	DEFAULT_BASEDIR="${DATADIR}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

VM_ARCHS=	amd64 i386 powerpc

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED) && \
    defined(WITHOUT_SMP)
IGNORE=		needs at least one of CLIENT, DEDICATED, or SMP options
.endif

.for i in ${ARCH}
.   if ${VM_ARCHS:M${i}} != ""
HAVE_VM_COMPILED=	yes
.   endif
.endfor

.if defined(HAVE_VM_COMPILED)
MAKE_ENV+=	HAVE_VM_COMPILED=true
.endif

.if !defined(WITHOUT_CLIENT) || !defined(WITHOUT_SMP)
# OpenAL
.   if defined(WITH_OPENAL)
USE_OPENAL=	al
MAKE_ENV+=	USE_OPENAL=1
.       if defined(WITH_OPENAL_DLOPEN)
MAKE_ENV+=	USE_OPENAL_DLOPEN=1
.       endif
.   endif
# SDL
.   if defined(WITH_SDL_AUDIO)
USE_SDL=	sdl
MAKE_ENV+=	USE_SDL_AUDIO=1
.   endif
.   if defined(WITH_SDL_VIDEO)
USE_SDL=	sdl
MAKE_ENV+=	USE_SDL_VIDEO=1
.   else
USE_GL=		gl
USE_XORG=	x11 xxf86dga
.   endif
# Vorbis
.   if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
MAKE_ENV+=	USE_CODEC_VORBIS=1
.   endif
.endif

.if !defined(WITHOUT_CLIENT)
MAKE_ENV+=	BUILD_CLIENT=1
PLIST_SUB+=	CLIENT=""
TRBIN+=		tremulous
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_DEDICATED)
MAKE_ENV+=	BUILD_SERVER=1
PLIST_SUB+=	DEDICATED=""
TRBIN+=		tremded
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if defined(WITH_GAMELIBS) || !defined(HAVE_VM_COMPILED)
MAKE_ENV+=	BUILD_GAME_SO=1
PLIST_SUB+=	GAMELIBS=""
.else
PLIST_SUB+=	GAMELIBS="@comment "
.endif

.if defined(WITH_MASTER_SERVER)
LIB_DEPENDS+=	tdb.1:${PORTSDIR}/databases/tdb
MAKE_ENV+=	BUILD_MASTER_SERVER=1
PLIST_SUB+=	MASTER_SERVER=""
.else
PLIST_SUB+=	MASTER_SERVER="@comment "
.endif

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	USE_OPTIMIZED_CFLAGS=1
.endif

.if !defined(WITHOUT_SMP)
MAKE_ENV+=	BUILD_CLIENT_SMP=1
PLIST_SUB+=	SMP=""
TRBIN+=		tremulous-smp
.else
PLIST_SUB+=	SMP="@comment "
.endif

post-extract:
	@cd ${WRKSRC} && ${TAR} zxf ${DISTNAME}-src.tar.gz

post-patch:
	@${REINPLACE_CMD} -e 's|botlib\.log|/dev/null|' \
		${BUILD_WRKSRC}/src/botlib/be_interface.c

do-install:
.for bin in ${TRBIN}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/build/release/${bin} ${PREFIX}/bin
.endfor
.if defined(WITH_MASTER_SERVER)
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/src/master/release/tremmaster \
		${PREFIX}/bin
.endif
	${MKDIR} ${DATADIR}/base
	${INSTALL_DATA} ${WRKSRC}/base/* ${DATADIR}/base
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/tremulous.xpm ${PREFIX}/share/pixmaps

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
