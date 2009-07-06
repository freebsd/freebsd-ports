# New ports collection makefile for:	ioquake3
# Date created:				3 Jun 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	ioquake3
DISTVERSION=	1.34-rc3
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://ioquake3.org/files/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Cleaned-up and enhaced version of Quake 3

USE_BZIP2=	yes
USE_GMAKE=	yes

OPTIONS=	CLIENT "Build client" on \
		CELLSHADING "Enable Cell Shading effect" off \
		GAMELIBS "Build game libraries (when not mandatory)" off \
		DEDICATED "Build dedicated server" on \
		MP3 "Enable MP3 support" off \
		OPENAL "Enable OpenAL (3D sound) support" off \
		OPENAL_DLOPEN "Enable dynamic loading of OpenAL" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL_AUDIO "Use SDL for audio" off \
		SDL_VIDEO "Use SDL for video" off \
		SMP "Build SMP (threaded) client" on \
		VORBIS "Enable Ogg Vorbis codec support" off

MAKE_ENV=	DEFAULT_BASEDIR="${Q3DIR}" LIBDIR="${LIBDIR}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

LIBDIR=		${PREFIX}/lib/${PORTNAME}
VM_ARCHS=	amd64 i386 powerpc

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

.if defined(WITH_CELLSHADING)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-cellshading
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
USE_XORG=	xxf86dga
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
Q3BIN+=		ioquake3
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_DEDICATED)
MAKE_ENV+=	BUILD_SERVER=1
PLIST_SUB+=	DEDICATED=""
Q3BIN+=		ioq3ded
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if defined(WITH_GAMELIBS) || !defined(HAVE_VM_COMPILED)
MAKE_ENV+=	BUILD_GAME_SO=1
PLIST_SUB+=	GAMELIBS=""
.else
PLIST_SUB+=	GAMELIBS="@comment "
.endif

.if defined(WITH_MP3)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-mp3
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad
MAKE_ENV+=	USE_CODEC_MP3=1
.endif

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	USE_OPTIMIZED_CFLAGS=1
.endif

.if !defined(WITHOUT_SMP)
MAKE_ENV+=	BUILD_CLIENT_SMP=1
PLIST_SUB+=	SMP=""
Q3BIN+=		ioquake3-smp
.else
PLIST_SUB+=	SMP="@comment "
.endif

post-patch:
# There are new variables in the config files, so keep them in another dir.
	@${REINPLACE_CMD} -E 's|/\.q3a|/.${PORTNAME}|' \
		${WRKSRC}/code/unix/unix_shared.c

do-install:
.for bin in ${Q3BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/${bin} ${PREFIX}/bin
.endfor
.if defined(WITH_GAMELIBS) || !defined(HAVE_VM_COMPILED)
.for dir in baseq3 missionpack
	${MKDIR} ${LIBDIR}/${dir}
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/${dir}/*.so ${LIBDIR}/${dir}
.endfor
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include "${.CURDIR}/../quake3-data/Makefile.include"
.include <bsd.port.post.mk>
