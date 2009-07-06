# New ports collection makefile for:	openarena
# Date created:				2007-08-01
# Whom:					Josh Tolbert <hemi@puresimplicity.net>
#
# $FreeBSD$
#

PORTNAME=	openarena
PORTVERSION=	0.7.1
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://openarena.ws/rel/070/:src \
		http://download.tuxfamily.net/cooker/openarena/rel070/:data \
		ftp://ftp.alepulver.com.ar/distfiles/:patch
DISTNAME=	ioq3-src-oa
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		${OA_DATA}:data \
		${OA_PATCH}:patch
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hemi@puresimplicity.net
COMMENT=	GPL-licensed total conversion of Quake 3

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on \
		OPENAL "Enable OpenAL (3D sound) support" off \
		OPENAL_DLOPEN "Enable dynamic loading of OpenAL" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL_AUDIO "Use SDL for audio" off \
		SDL_VIDEO "Use SDL for video" off \
		SMP "Build SMP (threaded) client" on \

MAKE_ENV=	DEFAULT_BASEDIR="${DATADIR}" LIBDIR="${LIBDIR}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" USE_CODEC_VORBIS=1
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

LIBDIR=		${PREFIX}/lib/${PORTNAME}
VM_ARCHS=	amd64 i386 powerpc
OA_DATA=	oa070.zip
OA_PATCH=	oa071-patch.zip

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED) && \
    defined(WITHOUT_SMP)
IGNORE=		needs at least one of CLIENT, DEDICATED and SMP options
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
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal
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
USE_GL=		yes
USE_XORG=	x11 xxf86dga
.   endif
.endif

.if !defined(WITHOUT_CLIENT)
MAKE_ENV+=	BUILD_CLIENT=1
PLIST_SUB+=	CLIENT=""
OABIN+=		ioquake3
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_DEDICATED)
MAKE_ENV+=	BUILD_SERVER=1
PLIST_SUB+=	DEDICATED=""
OABIN+=		ioq3ded
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if defined(WITH_GAMELIBS) || !defined(HAVE_VM_COMPILED)
MAKE_ENV+=	BUILD_GAME_SO=1
PLIST_SUB+=	GAMELIBS=""
.else
PLIST_SUB+=	GAMELIBS="@comment "
.endif

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	USE_OPTIMIZED_CFLAGS=1
.endif

.if !defined(WITHOUT_SMP)
MAKE_ENV+=	BUILD_CLIENT_SMP=1
PLIST_SUB+=	SMP=""
OABIN+=		ioquake3-smp
.else
PLIST_SUB+=	SMP="@comment "
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

post-extract:
.for f in ${OA_DATA} ${OA_PATCH}
	@${UNZIP_CMD} -qo ${DISTDIR}/${f} -d ${WRKDIR}
.endfor

do-install:
.for bin in ${OABIN}
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/${bin} \
		${PREFIX}/bin/${bin:C/(ioquake3|ioq3)/${PORTNAME}/}
.endfor
.if defined(WITH_GAMELIBS) || !defined(HAVE_VM_COMPILED)
.for dir in baseq3 missionpack
	${MKDIR} ${LIBDIR}/${dir}
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/${dir}/*.so ${LIBDIR}/${dir}
.endfor
.endif
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKDIR}/${PORTNAME}-0.7.0/baseoa ${DATADIR}

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
