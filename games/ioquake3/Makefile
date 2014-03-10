# Created by: alepulver
# $FreeBSD$

PORTNAME?=	ioquake3
DISTVERSION?=	1.36
PORTREVISION?=	13
CATEGORIES=	games
MASTER_SITES?=	http://ioquake3.org/files/${DISTVERSION}/
# Using zip this way enables slaves to override it.

MAINTAINER?=	kamikaze@bsdforen.de
COMMENT?=	Cleaned-up and enhanced version of Quake 3

USES=		pkgconfig gmake zip

NO_STAGE=	yes
# Port configuration flags:
# 	CLIENT SERVER TOOLS DLRENDERER GAMELIBS OPUS OPENGL2
IOQ3?=		CLIENT TOOLS GAMELIBS
IOQ3ARCH?=	${ARCH}

.if ! ${IOQ3:MCLIENT} && ! ${IOQ3:MSERVER}
BROKEN=		Slave ports must at least specify IOQ3=CLIENT or IOQ3=SERVER
.endif

# Client options
.if ${IOQ3:MCLIENT}
OPTIONS_DEFINE=	SERVER CURL OPENAL MUMBLE VORBIS DEBUG
OPTIONS_DEFAULT=	SERVER CURL OPENAL MUMBLE VORBIS
SERVER_DESC=	Install dedicated server
MUMBLE_DESC=	Enable Mumble support (no dependencies)
.endif
.if ${IOQ3:MTOOLS}
OPTIONS_DEFINE+=	TOOLS
OPTIONS_DEFAULT+=	TOOLS
TOOLS_DESC=	Enable modding tools
.endif
.if ${IOQ3:MDLRENDERER}
OPTIONS_DEFINE+=	DLRENDERER
OPTIONS_DEFAULT+=	DLRENDERER
DLRENDERER_DESC=	Build dynamically loaded renderer
.endif
.if ${IOQ3:MGAMELIBS}
OPTIONS_DEFINE+=	GAMELIBS
OPTIONS_DEFAULT+=	GAMELIBS
GAMELIBS_DESC=	Build game libraries
.endif
.if ${IOQ3:MOPUS}
OPTIONS_DEFINE+=	OPUS
OPTIONS_DEFAULT+=	OPUS
OPUS_DESC=	Opus audio codec support
.endif

MAKE_ARGS+=	DEFAULT_BASEDIR="${Q3DIR}" \
		DEFAULT_LIBDIR="${PREFIX}/${LIBDIR}" \
		HOMEPATH="${HOMEPATH}" \
		VERSION="${Q3ENGINEVER}" \
		ARCH="${IOQ3ARCH}" \
		TOOLS_CC="${CC}" \
		USE_LOCAL_HEADERS=0
ALL_TARGET=	release

LIBDIR=		lib/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	share/doc/${PORTNAME}${PKGNAMESUFFIX}
BUILDDIR=	${WRKSRC}/build/${ALL_TARGET}-${OPSYS:L}-${IOQ3ARCH}
BINSUFFIX?=
HOMEPATH?=	/.${PORTNAME}
Q3CLIENT?=	ioquake3
Q3SERVER?=	ioq3ded
Q3TOOLS?=	q3asm \
		q3cpp \
		q3lcc \
		q3rcc
Q3DOCS?=	README \
		id-readme.txt \
		md4-readme.txt \
		voip-readme.txt
Q3BASE?=	baseq3 \
		missionpack
Q3GAMELIBS?=	cgame \
		qagame \
		ui
Q3ICON?=	${PREFIX}/share/pixmaps/quake3.xpm
.if ${IOQ3:MOPENGL2}
Q3RENDERER?=	renderer_opengl1_${IOQ3ARCH} renderer_opengl2_${IOQ3ARCH}
.else
Q3RENDERER?=	renderer_opengl1_${IOQ3ARCH}
.endif
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
. if ${IOQ3:MCLIENT}
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

.if ${IOQ3:MCLIENT}
MAKE_ARGS+=	BUILD_CLIENT=1
Q3BIN+=		${Q3CLIENT}
USE_SDL=	sdl
.else
MAKE_ARGS+=	BUILD_CLIENT=0
.endif

.if ${IOQ3:MSERVER}
MAKE_ARGS+=	BUILD_SERVER=1
Q3BIN+=		${Q3SERVER}
.else
MAKE_ARGS+=	BUILD_SERVER=0
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
MAKE_ARGS+=	USE_CURL=1 USE_CURL_DLOPEN=0
.else
MAKE_ARGS+=	USE_CURL=0
.endif

.if ${PORT_OPTIONS:MOPENAL}
USES+=		openal:al
MAKE_ARGS+=	USE_OPENAL=1 USE_OPENAL_DLOPEN=0
.else
MAKE_ARGS+=	USE_OPENAL=0
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
MAKE_ARGS+=	USE_CODEC_VORBIS=1
.else
MAKE_ARGS+=	USE_CODEC_VORBIS=0
.endif

.if ${PORT_OPTIONS:MOPUS}
MAKE_ARGS+=	USE_CODEC_OPUS=1 USE_INTERNAL_OPUS=1
.else
MAKE_ARGS+=	USE_CODEC_OPUS=0
.endif

.if ${PORT_OPTIONS:MMUMBLE}
MAKE_ARGS+=	USE_MUMBLE=1
.else
MAKE_ARGS+=	USE_MUMBLE=0
.endif

.if ${PORT_OPTIONS:MGAMELIBS}
MAKE_ARGS+=	BUILD_GAME_SO=1
.else
MAKE_ARGS+=	BUILD_GAME_SO=0
.endif

# Note that SMP is only supported on OS-X, hence the option has been removed.
.if ${PORT_OPTIONS:MSMP}
MAKE_ARGS+=	BUILD_CLIENT_SMP=1
Q3BIN+=		${Q3CLIENT}-smp
.else
MAKE_ARGS+=	BUILD_CLIENT_SMP=0
.endif

.if ${PORT_OPTIONS:MDLRENDERER}
MAKE_ARGS+=	USE_RENDERER_DLOPEN=1
. if ${IOQ3:MOPENGL2}
Q3DOCS+=	opengl2-readme.txt
. endif
.else
MAKE_ARGS+=	USE_RENDERER_DLOPEN=0
.endif

# Generate a set of install instruction tuples: <cmd>;<src>;<dst>
.for bin in ${Q3BIN}
IOQ3_INST+=	PROGRAM;${bin}.${IOQ3ARCH};bin/${bin}${BINSUFFIX}
.endfor
.if ${PORT_OPTIONS:MTOOLS}
. for bin in ${Q3TOOLS}
IOQ3_INST+=	PROGRAM;tools/${bin};bin/${bin}${BINSUFFIX}
. endfor
.endif
.if ${PORT_OPTIONS:MDLRENDERER}
. for renderer in ${Q3RENDERER}
IOQ3_INST+=	LIB;${renderer}.so;${LIBDIR}/${renderer}.so
. endfor
.endif
.if ${PORT_OPTIONS:MGAMELIBS}
. for dir in ${Q3BASE}
PLIST_DIRS+=	${LIBDIR}/${dir}
.  for lib in ${Q3GAMELIBS}
IOQ3_INST+=	LIB;${dir}/${lib}${IOQ3ARCH}.so;${LIBDIR}/${dir}/${lib}${IOQ3ARCH}.so
.  endfor
. endfor
.endif
.if ${PORT_OPTIONS:MDLRENDERER} || ${PORT_OPTIONS:MGAMELIBS}
PLIST_DIRS+=	${LIBDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
PLIST_DIRS+=	${DOCSDIR}
. for doc in ${Q3DOCS}
IOQ3_INST+=	DATA;../../${doc};${DOCSDIR}/${doc}
. endfor
.endif

# Generate PLIST_FILES
.for inst in ${IOQ3_INST}
PLIST_FILES+=	${inst:C/.*;//}
.endfor

# Generate install target
do-install: ${Q3INSTALL}
.for dir in ${PLIST_DIRS}
	${MKDIR} ${PREFIX}/${dir}
.endfor
.for inst in ${IOQ3_INST}
	${INSTALL_${inst:C/;.*//}} ${BUILDDIR}/${inst:C/[^;]*;//:C/;.*//} \
		${PREFIX}/${inst:C/.*;//}
.endfor

post-install:
	@${JOT} -s '' -b= 78
	@${CAT} ${PKGMESSAGE}
	@${JOT} -s '' -b= 78

.if !defined(Q3TOTALCONV)
.include "${.CURDIR}/../quake3-data/Makefile.include"
.endif

.include <bsd.port.mk>
