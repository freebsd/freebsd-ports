# New ports collection makefile for:	evq3
# Date created:				8 Aug 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	evq3
PORTVERSION=	1.3.20080810
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL:S|$|alepulver/|}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		pak-evq3.pk3 \
		pak-5evq3.pk3
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	The Marriage of XreaL and Icculus.org Q3 w/ Improvements

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
ALL_TARGET=	release
WRKSRC=		${WRKDIR}/${PORTNAME}
CFLAGS+=	-DMAP_ANONYMOUS=MAP_ANON

OPTIONS=	CLIENT "Build client" on \
		CURL "Enable curl support" on \
		CURL_DLOPEN "Enable dynamic loading of curl" on \
		GAMELIBS "Build game libraries (when not mandatory)" off \
		DEDICATED "Build dedicated server" on \
		OPENAL "Enable OpenAL (3D sound) support" off \
		OPENAL_DLOPEN "Enable dynamic loading of OpenAL" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SMP "Build SMP (threaded) client" on \
		VOIP "Enable Voice Over IP" off \
		VORBIS "Enable Ogg Vorbis codec support" on

MAKE_ENV=	DEFAULT_BASEDIR="${Q3DIR}" LIBDIR="${LIBDIR}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

LIBDIR=		${PREFIX}/lib/${PORTNAME}
VM_ARCHS=	amd64 i386 powerpc

.include "${.CURDIR}/../quake3-data/Makefile.include"

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
# curl
.   if defined(WITH_CURL)
LIB_DEPENDS+=	curl.5:${PORTSDIR}/ftp/curl
MAKE_ENV+=	USE_CURL=1
.       if defined(WITH_CURL_DLOPEN)
MAKE_ENV+=	USE_CURL_DLOPEN=1
.       endif
.   endif
# OpenAL
.   if defined(WITH_OPENAL)
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal
MAKE_ENV+=	USE_OPENAL=1
.       if defined(WITH_OPENAL_DLOPEN)
MAKE_ENV+=	USE_OPENAL_DLOPEN=1
.       endif
.   endif
# SDL
USE_SDL=	sdl
# VOIP
.   if defined(WITH_VOIP)
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
MAKE_ENV+=	USE_VOIP=1
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
Q3BIN+=		evq3
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_DEDICATED)
MAKE_ENV+=	BUILD_SERVER=1
PLIST_SUB+=	DEDICATED=""
Q3BIN+=		evq3ded
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
Q3BIN+=		evq3-smp
.else
PLIST_SUB+=	SMP="@comment "
.endif

post-patch:
# Do not log debug output of bots (can be enabled with "homedir"/"gamedir").
	@${REINPLACE_CMD} -e 's|"botlib\.log"|"/dev/null"|' \
		${WRKSRC}/code/botlib/be_interface.c
# Enable mmap on i386.
	@${REINPLACE_CMD} -e 's|__linux__|__unix__|' \
		${WRKSRC}/code/qcommon/vm_x86.c

do-install:
	${MKDIR} ${LIBDIR}/baseq3
	${INSTALL_DATA} ${DISTDIR}/pak-evq3.pk3 ${DISTDIR}/pak-5evq3.pk3 \
		${LIBDIR}/baseq3
.for bin in ${Q3BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/${bin} ${PREFIX}/bin
.endfor
.if defined(WITH_GAMELIBS) || !defined(HAVE_VM_COMPILED)
. for dir in baseq3 missionpack
	${MKDIR} ${LIBDIR}/${dir}
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/${dir}/*.so ${LIBDIR}/${dir}
. endfor
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

maint-gen-distfile:
	@if [ -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO_CMD} "ERROR: the distfile already exists."; \
		${FALSE}; \
	fi
	svn export svn://70.86.44.154/evolution/trunk/evq3 ${PORTNAME}
	tar cjf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}
	${RM} -rf ${PORTNAME}

.include <bsd.port.post.mk>
