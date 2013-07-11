# Created by: alepulver
# $FreeBSD$

PORTNAME?=	ioquake3
DISTVERSION?=	1.36
PORTREVISION?=	13
CATEGORIES=	games
MASTER_SITES?=	http://ioquake3.org/files/${DISTVERSION}/
# Using zip this way enables slaves to override it.
EXTRACT_SUFX?=	.zip

MAINTAINER?=	kamikaze@bsdforen.de
COMMENT?=	Cleaned-up and enhanced version of Quake 3

USES=		pkgconfig
USE_GMAKE=	yes

.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX:M*-server}
# Server config
WITH_DEDICATED=	yes
WITHOUT_CLIENT=	yes
WITHOUT_SERVER=	yes
WITHOUT_CURL=	yes
WITHOUT_OPENAL=	yes
WITHOUT_MUMBLE=	yes
WITHOUT_VORBIS=	yes
WITHOUT_TOOLS=	yes
WITHOUT_DLRENDERER=	yes
.else
# Client config
WITH_CLIENT=	yes
WITHOUT_DEDICATED=	yes
OPTIONS_DEFINE=	SERVER CURL OPENAL MUMBLE VORBIS DEBUG
OPTIONS_DEFAULT=	SERVER CURL OPENAL MUMBLE VORBIS
SERVER_DESC=	Install dedicated server
MUMBLE_DESC=	Enable Mumble support (no dependencies)
. if defined(NO_TOOLS)
WITHOUT_TOOLS=	yes
. else
OPTIONS_DEFINE+=	TOOLS
OPTIONS_DEFAULT+=	TOOLS
TOOLS_DESC=	Enable modding tools
. endif
. if defined(HAS_DLRENDERER)
OPTIONS_DEFINE+=	DLRENDERER
OPTIONS_DEFAULT+=	DLRENDERER
DLRENDERER_DESC=	Build dynamically loaded renderer
. endif
.endif
# Common config
.if !defined(NO_GAMELIBS)
OPTIONS_DEFINE+=	GAMELIBS
OPTIONS_DEFAULT+=	GAMELIBS
GAMELIBS_DESC=	Build game libraries
.endif

MAKE_ARGS+=	DEFAULT_BASEDIR="${Q3DIR}" \
		DEFAULT_LIBDIR="${LIBDIR}" \
		HOMEPATH="${HOMEPATH}" \
		VERSION="${Q3ENGINEVER}" \
		ARCH="${ARCH}" \
		USE_LOCAL_HEADERS=0
PLIST_SUB+=	LIBDIR="${LIBDIR:S/${PREFIX}\///}" \
		ARCH="${ARCH}" \
		BINSUFFIX="${BINSUFFIX}"
ALL_TARGET=	release
MAKE_JOBS_SAFE=	yes

LIBDIR=		${PREFIX}/lib/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
BUILDDIR=	${WRKSRC}/build/${ALL_TARGET}-${OPSYS:L}-${ARCH}
BINSUFFIX?=
HOMEPATH?=	/.${PORTNAME}
Q3CLIENT?=	ioquake3
Q3SERVER?=	ioq3ded
Q3TOOLS?=	q3asm \
		q3cpp \
		q3lcc \
		q3rcc
Q3BASE?=	baseq3 \
		missionpack
Q3ICON?=	${PREFIX}/share/pixmaps/quake3.xpm
Q3RENDERER?=	renderer_opengl1_${ARCH}
Q3INSTALL?=
Q3ENGINEVER?=	${DISTVERSION}

ONLY_FOR_ARCHS=	amd64 i386

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
ALL_TARGET=	debug
.endif

.if ${PORT_OPTIONS:MSERVER}
RUN_DEPENDS+=	${Q3SERVER}${BINSUFFIX}:${PORTSDIR}/games/${PORTNAME}-server
.endif

.if !defined(DESKTOP_ENTRIES)
. if ${PORT_OPTIONS:MCLIENT}
DESKTOP_ENTRIES+=	"${Q3CLIENT} ${Q3ENGINEVER}" "${COMMENT}"  \
		"${Q3ICON}" \
		"${Q3CLIENT}${BINSUFFIX}" "Game;" false
. endif
. if ${PORT_OPTIONS:MSMP}
DESKTOP_ENTRIES+=	"${Q3CLIENT} ${Q3ENGINEVER} SMP" "${COMMENT}" \
		"${Q3ICON}" \
		"${Q3CLIENT}-smp${BINSUFFIX}" "Game;" false
. endif
.endif

.if ! ${PORT_OPTIONS:MCLIENT} && ! ${PORT_OPTIONS:MDEDICATED} && \
    ! ${PORT_OPTIONS:MSMP}
IGNORE=		needs at least one of CLIENT, DEDICATED and SMP options
.endif

.if ${PORT_OPTIONS:MCLIENT} || ${PORT_OPTIONS:MSMP}
# cURL
.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
MAKE_ARGS+=	USE_CURL=1 USE_CURL_DLOPEN=0
.else
MAKE_ARGS+=	USE_CURL=0
.endif
# OpenAL
.if ${PORT_OPTIONS:MOPENAL}
USE_OPENAL=	al
MAKE_ARGS+=	USE_OPENAL=1 USE_OPENAL_DLOPEN=0
.else
MAKE_ARGS+=	USE_OPENAL=0
.endif
# SDL
USE_SDL=	sdl
# Vorbis
.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
MAKE_ARGS+=	USE_CODEC_VORBIS=1
.else
MAKE_ARGS+=	USE_CODEC_VORBIS=0
.endif
# Mumble
.if ${PORT_OPTIONS:MMUMBLE}
MAKE_ARGS+=	USE_MUMBLE=1
.else
MAKE_ARGS+=	USE_MUMBLE=0
.endif
.else
# Features that aren't installed without a client
WITHOUT_DLRENDERER=	yes
.endif

# SMP is only built with CLIENT.
.if ${PORT_OPTIONS:MCLIENT} || ${PORT_OPTIONS:MSMP}
MAKE_ARGS+=	BUILD_CLIENT=1
PLIST_SUB+=	CLIENT=""
Q3BIN+=		${Q3CLIENT}
.else
MAKE_ARGS+=	BUILD_CLIENT=0
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MDEDICATED}
MAKE_ARGS+=	BUILD_SERVER=1
PLIST_SUB+=	DEDICATED=""
Q3BIN+=		${Q3SERVER}
.else
MAKE_ARGS+=	BUILD_SERVER=0
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if ${PORT_OPTIONS:MGAMELIBS}
MAKE_ARGS+=	BUILD_GAME_SO=1
PLIST_SUB+=	GAMELIBS=""
.else
PLIST_SUB+=	GAMELIBS="@comment "
.endif

# Note that SMP is only supported on OS-X, hence the option has been removed.
.if ${PORT_OPTIONS:MSMP}
MAKE_ARGS+=	BUILD_CLIENT_SMP=1
PLIST_SUB+=	SMP=""
Q3BIN+=		${Q3CLIENT}-smp
.else
MAKE_ARGS+=	BUILD_CLIENT_SMP=0
PLIST_SUB+=	SMP="@comment "
.endif

.if ${PORT_OPTIONS:MDLRENDERER}
PLIST_SUB+=	DLRENDERER=""
MAKE_ARGS+=	USE_RENDERER_DLOPEN=1
.else
MAKE_ARGS+=	USE_RENDERER_DLOPEN=0
PLIST_SUB+=	DLRENDERER="@comment "
.endif

.if ${PORT_OPTIONS:MTOOLS}
PLIST_SUB+=	TOOLS=""
.else
PLIST_SUB+=	TOOLS="@comment "
.endif

do-install: ${Q3INSTALL}
.for bin in ${Q3BIN}
	${INSTALL_PROGRAM} ${BUILDDIR}/${bin}.${ARCH} \
		${PREFIX}/bin/${bin}${BINSUFFIX}
.endfor
.if ${PORT_OPTIONS:MTOOLS}
.for bin in ${Q3TOOLS}
	${INSTALL_PROGRAM} ${BUILDDIR}/tools/${bin} \
		${PREFIX}/bin/${bin}${BINSUFFIX}
.endfor
.endif
.if ${PORT_OPTIONS:MDLRENDERER}
.for renderer in ${Q3RENDERER}
	${MKDIR} ${LIBDIR}
	${INSTALL_LIB} ${BUILDDIR}/${renderer}.so ${LIBDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MGAMELIBS}
.for dir in ${Q3BASE}
	${MKDIR} ${LIBDIR}/${dir}
	${INSTALL_LIB} ${BUILDDIR}/${dir}/*.so ${LIBDIR}/${dir}
.endfor
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.if !defined(Q3TOTALCONV)
.include "${.CURDIR}/../quake3-data/Makefile.include"
.endif

.include <bsd.port.mk>
