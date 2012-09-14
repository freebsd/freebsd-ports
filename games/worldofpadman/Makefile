# New ports collection makefile for:	worldofpadman
# Date created:				2008-01-12
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	worldofpadman
PORTVERSION=	1.2.20080621
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://thilo.kickchat.com/download/:full \
		http://btc3x6.che.uni-bayreuth.de/~tl/wop_final/:full \
		ftp://ftp.snt.utwente.nl/pub/games/worldofpadman/linux/:full,update \
		ftp://ftp.kickchat.com/wop/:update \
		http://www.hessenfragger.de/uploads/:update \
		${MASTER_SITE_LOCAL:S|$|alepulver/:source|}
DISTFILES=	worldofpadman.run:full \
		wop_patch_1_2.run:update \
		${SRC_FILE}.tar.bz2:source
EXTRACT_ONLY=	worldofpadman.run \
		wop_patch_1_2.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	World of Padman (WoP) is an open source FPS game

USE_MAKESELF=	yes
USE_GMAKE=	yes
ALL_TARGET=	release
NO_PACKAGE=	package will be ~600MB; set FORCE_PACKAGE if you really want it

OPTIONS_DEFINE=	CURL CURL_DLOPEN GAMELIBS MP3 OPENAL OPENAL_DLOPEN OPTIMIZED_CFLAGS VORBIS
OPTIONS_DEFAULT=	CLIENT CURL CURL_DLOPEN DEDICATED OPTIMIZED_CFLAGS VORBIS SMP
OPTIONS_MULTI=	MODE
OPTIONS_MULTI_MODE=	CLIENT DEDICATED SMP

CLIENT_DESC=	Build client
CURL_DLOPEN_DESC=	Enable dynamic loading of curl
DEDICATED_DESC=	Build dedicated server
GAMELIBS_DESC=	Build game libraries (when not mandatory)
OPENAL_DLOPEN_DESC=	Enable dynamic loading of OpenAL
SMP_DESC=	Build SMP (threaded) client

MAKE_ENV=	DEFAULT_BASEDIR="${DATADIR}" PTHREAD_LIBS="${PTHREAD_LIBS}"

VM_ARCHS=	amd64 i386 powerpc
SRC_FILE=	${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.for i in ${ARCH}
.   if ${VM_ARCHS:M${i}} != ""
HAVE_VM_COMPILED=	yes
.   endif
.endfor

.if defined(HAVE_VM_COMPILED)
MAKE_ENV+=	HAVE_VM_COMPILED=true
.endif

.if empty(${PORT_OPTIONS:MCLIENT}) || !${PORT_OPTIONS:MSMP}
# curl
.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
MAKE_ENV+=	USE_CURL=1
.	if ${PORT_OPTIONS:MCURL_DLOPEN}
MAKE_ENV+=	USE_CURL_DLOPEN=1
.       endif
.   endif
# OpenAL
.    if ${PORT_OPTIONS:MOPENAL}
USE_OPENAL=	al
MAKE_ENV+=	USE_OPENAL=1
.       if ${PORT_OPTIONS:MOPENAL_DLOPEN}
MAKE_ENV+=	USE_OPENAL_DLOPEN=1
.       endif
.   endif
# SDL
USE_SDL=	sdl
# Vorbis
.   if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
MAKE_ENV+=	USE_CODEC_VORBIS=1
.   endif
.endif

.if ${PORT_OPTIONS:MCLIENT}
MAKE_ENV+=	BUILD_CLIENT=1
PLIST_SUB+=	CLIENT=""
Q3BIN+=		wop
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MDEDICATED}
MAKE_ENV+=	BUILD_SERVER=1
PLIST_SUB+=	DEDICATED=""
Q3BIN+=		wopded
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if ${PORT_OPTIONS:MGAMELIBSA} || !defined(HAVE_VM_COMPILED)
MAKE_ENV+=	BUILD_GAME_SO=1
PLIST_SUB+=	GAMELIBS=""
.else
PLIST_SUB+=	GAMELIBS="@comment "
.endif

.if ${PORT_OPTIONS:MMP3}
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad
MAKE_ENV+=	USE_CODEC_MP3=1
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ENV+=	USE_OPTIMIZED_CFLAGS=1
.endif

.if ${PORT_OPTIONS:MSMP}
MAKE_ENV+=	BUILD_CLIENT_SMP=1
PLIST_SUB+=	SMP=""
Q3BIN+=		wop-smp
.else
PLIST_SUB+=	SMP="@comment "
.endif

post-extract:
	@${TAR} jxf ${DISTDIR}/${SRC_FILE}.tar.bz2 -C ${WRKDIR}
	@${MKDIR} ${WRKDIR}/wop
.for f in wop-data wop-data-1.2 extras
	@cd ${WRKDIR} && ${TAR} xf ${f}.tar -C wop
.endfor
	@cd ${WRKDIR} && ${TAR} xf readme.tar

post-patch:
# Do not log debug output of bots (can be enabled with "homedir"/"gamedir").
	@${REINPLACE_CMD} -e 's|"botlib\.log"|"/dev/null"|' \
		${WRKSRC}/code/botlib/be_interface.c

do-install:
	${MKDIR} ${DATADIR}/wop
	${CP} -r ${WRKDIR}/wop/* ${DATADIR}/wop
	${INSTALL_DATA} ${WRKDIR}/wop.png \
		${PREFIX}/share/pixmaps/${PORTNAME}.png
.for bin in ${Q3BIN}
# Rename wop* -> worldofpadman* to avoid conflicts with games/wop.
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/${bin} \
		${PREFIX}/bin/${bin:S/wop/${PORTNAME}/}
.endfor
.if ${PORT_OPTIONS:MGAMELIBS} || !defined(HAVE_VM_COMPILED)
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/baseq3/*.so ${DATADIR}/wop
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${CP} -r ${WRKDIR}/readme/* ${DOCSDIR}
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

maint-gen-distfile:
	@if [ -f ${DISTDIR}/${SRC_FILE}.tar.bz2 ]; then \
		${ECHO_CMD} "ERROR: the distfile already exists."; \
		${FALSE}; \
	fi
	svn export https://wop-engine.svn.sourceforge.net/svnroot/wop-engine/trunk ${SRC_FILE}
	tar cjf ${DISTDIR}/${SRC_FILE}.tar.bz2 ${SRC_FILE}
	${RM} -rf ${SRC_FILE}

.include <bsd.port.post.mk>
