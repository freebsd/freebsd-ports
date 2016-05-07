# Created by: alepulver
# $FreeBSD$

PORTNAME=	evq3
PORTVERSION=	1.3.20080810
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	LOCAL/alepulver
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		pak-evq3.pk3 \
		pak-5evq3.pk3
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Marriage of XreaL and Icculus.org Q3 w/ Improvements

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		gmake dos2unix tar:bzip2
ALL_TARGET=	release
WRKSRC=		${WRKDIR}/${PORTNAME}
CFLAGS+=	-DMAP_ANONYMOUS=MAP_ANON

OPTIONS_DEFINE=	CURL CURL_DLOPEN GAMELIBS OPENAL OPENAL_DLOPEN VOIP VORBIS OPTIMIZED_CFLAGS DOCS
OPTIONS_DEFAULT=	CLIENT CURL CURL_DLOPEN DEDICATED OPTIMIZED_CFLAGS SMP VORBIS
OPTIONS_MULTI=	TYPE
OPTIONS_MULTI_TYPE=	CLIENT DEDICATED SMP
CLIENT_DESC=	Build client
CURL_DLOPEN_DESC=	Enable dynamic loading of curl
GAMELIBS_DESC=	Build game libraries (when not mandatory)
DEDICATED_DESC=	Build dedicated server
OPENAL_DESC=	Enable OpenAL (3D sound) support
OPENAL_DLOPEN_DESC=	Enable dynamic loading of OpenAL
SMP_DESC=	Build SMP (threaded) client
VOIP_DESC=	Enable Voice Over IP

# USES must be before bsd.port.pre.mk
OPENAL_USES=	openal:al

MAKE_ENV=	DEFAULT_BASEDIR="${Q3DIR}" LIBDIR="${LIBDIR}" \
		PTHREAD_LIBS="-lpthread"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

LIBDIR=		${PREFIX}/lib/${PORTNAME}
VM_ARCHS=	amd64 i386

.include "${.CURDIR}/../quake3-data/Makefile.include"

.include <bsd.port.pre.mk>

.for i in ${ARCH}
.   if ${VM_ARCHS:M${i}} != ""
HAVE_VM_COMPILED=	yes
.   endif
.endfor

.if defined(HAVE_VM_COMPILED)
MAKE_ENV+=	HAVE_VM_COMPILED=true
.endif

.if ${PORT_OPTIONS:MCLIENT} || !empty(PORT_OPTIONS:MSMP)
# curl
.   if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	libcurl.so:ftp/curl
MAKE_ENV+=	USE_CURL=1
.       if ${PORT_OPTIONS:MCURL_DLOPEN}
MAKE_ENV+=	USE_CURL_DLOPEN=1
.       endif
.   endif
# OpenAL
.   if ${PORT_OPTIONS:MOPENAL}
MAKE_ENV+=	USE_OPENAL=1
.       if ${PORT_OPTIONS:MOPENAL_DLOPEN}
MAKE_ENV+=	USE_OPENAL_DLOPEN=1
.       endif
.   endif
# SDL
USE_SDL=	sdl
# VOIP
.   if ${PORT_OPTIONS:MVOIP}
LIB_DEPENDS+=	libspeex.so:audio/speex
MAKE_ENV+=	USE_VOIP=1
.   endif
# Vorbis
.   if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	libvorbis.so:audio/libvorbis
MAKE_ENV+=	USE_CODEC_VORBIS=1
.   endif
.endif

.if ${PORT_OPTIONS:MCLIENT}
MAKE_ENV+=	BUILD_CLIENT=1
PLIST_SUB+=	CLIENT=""
Q3BIN+=		evq3
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MDEDICATED}
MAKE_ENV+=	BUILD_SERVER=1
PLIST_SUB+=	DEDICATED=""
Q3BIN+=		evq3ded
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if ${PORT_OPTIONS:MGAMELIBS} || !defined(HAVE_VM_COMPILED)
MAKE_ENV+=	BUILD_GAME_SO=1
PLIST_SUB+=	GAMELIBS=""
.else
PLIST_SUB+=	GAMELIBS="@comment "
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ENV+=	USE_OPTIMIZED_CFLAGS=1
.endif

.if ${PORT_OPTIONS:MSMP}
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
	@${MKDIR} ${STAGEDIR}${LIBDIR}/baseq3
	${INSTALL_DATA} ${DISTDIR}/pak-evq3.pk3 ${DISTDIR}/pak-5evq3.pk3 \
		${STAGEDIR}${LIBDIR}/baseq3
.for bin in ${Q3BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/${bin} ${STAGEDIR}${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MGAMELIBS} || !defined(HAVE_VM_COMPILED)
. for dir in baseq3 missionpack
	@${MKDIR} ${STAGEDIR}${LIBDIR}/${dir}
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/${dir}/*.so ${STAGEDIR}${LIBDIR}/${dir}
. endfor
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

maint-gen-distfile:
	@if [ -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO_CMD} "ERROR: the distfile already exists."; \
		${FALSE}; \
	fi
	svn export svn://70.86.44.154/evolution/trunk/evq3 ${PORTNAME}
	tar cjf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}
	${RM} -rf ${PORTNAME}

.include <bsd.port.post.mk>
