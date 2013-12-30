# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	worldofpadman
PORTVERSION=	1.2.20080621
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.snt.utwente.nl/pub/games/worldofpadman/linux/:full,update \
		${MASTER_SITE_LOCAL:S|$|alepulver/:source|}
DISTFILES=	worldofpadman.run:full \
		wop_patch_1_2.run:update \
		${SRC_FILE}.tar.bz2:source
EXTRACT_ONLY=	worldofpadman.run \
		wop_patch_1_2.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source FPS game inspired by the Padman comic strip

NO_PACKAGE=	package will be ~600MB; set FORCE_PACKAGE if you really want it

USES=		gmake
USE_MAKESELF=	yes
MAKE_ENV=	DEFAULT_BASEDIR="${DATADIR}" PTHREAD_LIBS="${PTHREAD_LIBS}"
ALL_TARGET=	release

SRC_FILE=	${PORTNAME}-${PORTVERSION}
VM_ARCHS=	amd64 i386 powerpc

OPTIONS_DEFINE=		CURL CURL_DLOPEN GAMELIBS MP3 OPENAL OPENAL_DLOPEN \
			OPTIMIZED_CFLAGS VORBIS
OPTIONS_MULTI=		FLAVOR
OPTIONS_MULTI_FLAVOR=	CLIENT SERVER SMP_CLIENT
OPTIONS_DEFAULT=	CLIENT CURL CURL_DLOPEN SERVER OPTIMIZED_CFLAGS \
			VORBIS SMP_CLIENT

FLAVOR_DESC=		Clients and servers
CLIENT_DESC=		Build client
CURL_DLOPEN_DESC=	Enable dynamic loading of cURL
SERVER_DESC=		Build dedicated server
GAMELIBS_DESC=		Force building game libraries
OPENAL_DLOPEN_DESC=	Enable dynamic loading of OpenAL
SMP_CLIENT_DESC=	Build SMP (threaded) client

NO_STAGE=	yes
.include <bsd.port.options.mk>

.for arch in ${ARCH}
.  if ${VM_ARCHS:M${arch}} != ""
HAVE_VM_COMPILED=	yes
.  endif
.endfor

.if defined(HAVE_VM_COMPILED)
MAKE_ENV+=	HAVE_VM_COMPILED=true
.endif

.if ${PORT_OPTIONS:MCLIENT} || ${PORT_OPTIONS:MSMP_CLIENT}
# cURL
.  if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl
MAKE_ENV+=	USE_CURL=1
.    if ${PORT_OPTIONS:MCURL_DLOPEN}
MAKE_ENV+=	USE_CURL_DLOPEN=1
.    endif
.  endif
# OpenAL
.  if ${PORT_OPTIONS:MOPENAL}
USES+=		openal:al
MAKE_ENV+=	USE_OPENAL=1
.    if ${PORT_OPTIONS:MOPENAL_DLOPEN}
MAKE_ENV+=	USE_OPENAL_DLOPEN=1
.    endif
.  endif
# SDL
USE_GL=		glu
USE_SDL=	sdl
# Vorbis
.  if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	libvorbis.so:${PORTSDIR}/audio/libvorbis
MAKE_ENV+=	USE_CODEC_VORBIS=1
.  endif
.endif

.if ${PORT_OPTIONS:MCLIENT}
MAKE_ENV+=	BUILD_CLIENT=1
PLIST_SUB+=	CLIENT=""
WOPBIN+=	wop
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MSERVER}
MAKE_ENV+=	BUILD_SERVER=1
PLIST_SUB+=	SERVER=""
WOPBIN+=	wopded
.else
PLIST_SUB+=	SERVER="@comment "
.endif

.if ${PORT_OPTIONS:MGAMELIBS} || !defined(HAVE_VM_COMPILED)
MAKE_ENV+=	BUILD_GAME_SO=1
PLIST_SUB+=	GAMELIBS=""
.else
PLIST_SUB+=	GAMELIBS="@comment "
.endif

.if ${PORT_OPTIONS:MMP3}
LIB_DEPENDS+=	libmad.so:${PORTSDIR}/audio/libmad
MAKE_ENV+=	USE_CODEC_MP3=1
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ENV+=	USE_OPTIMIZED_CFLAGS=1
.endif

.if ${PORT_OPTIONS:MSMP_CLIENT}
MAKE_ENV+=	BUILD_CLIENT_SMP=1
PLIST_SUB+=	SMPCLIENT=""
WOPBIN+=	wop-smp
.else
PLIST_SUB+=	SMPCLIENT="@comment "
.endif

post-extract:
	@${TAR} jxf ${DISTDIR}/${SRC_FILE}.tar.bz2 -C ${WRKDIR}
	@${MKDIR} ${WRKDIR}/wop
.for f in wop-data wop-data-1.2 extras
	@cd ${WRKDIR} && ${TAR} xf ${f}.tar -C wop
.endfor
	@cd ${WRKDIR} && ${TAR} xf readme.tar

post-patch:
# Do not log debug output of bots (can be enabled with "homedir"/"gamedir")
	@${REINPLACE_CMD} -e 's|"botlib\.log"|"/dev/null"|' \
		${WRKSRC}/code/botlib/be_interface.c

do-install:
	@${MKDIR} ${DATADIR}/wop
	${CP} -a ${WRKDIR}/wop/* ${DATADIR}/wop
	${INSTALL_DATA} ${WRKDIR}/wop.png \
		${PREFIX}/share/pixmaps/${PORTNAME}.png
.for bin in ${WOPBIN}
# Rename wop* -> worldofpadman* to avoid conflicts with `games/wop'
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/${bin} \
		${PREFIX}/bin/${bin:S/wop/${PORTNAME}/}
.endfor
.if ${PORT_OPTIONS:MGAMELIBS} || !defined(HAVE_VM_COMPILED)
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/baseq3/*.so ${DATADIR}/wop
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${CP} -a ${WRKDIR}/readme/* ${DOCSDIR}
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

generate-distfile:
	@if [ -f ${DISTDIR}/${SRC_FILE}.tar.bz2 ]; then \
		${ECHO_CMD} "ERROR: the distfile already exists."; \
		${FALSE}; \
	fi
	svn export https://wop-engine.svn.sourceforge.net/svnroot/wop-engine/trunk ${SRC_FILE}
	tar cjf ${DISTDIR}/${SRC_FILE}.tar.bz2 ${SRC_FILE}
	${RM} -rf ${SRC_FILE}

.include <bsd.port.mk>
