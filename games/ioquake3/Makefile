# Created by: alepulver
# $FreeBSD$

PORTNAME?=	ioquake3
DISTVERSION?=	1.36
PORTREVISION?=	15
CATEGORIES=	games
MASTER_SITES?=	http://ioquake3.org/files/${DISTVERSION}/
# Using zip this way enables slaves to override it.
EXTRACT_SUFX?=	.zip

MAINTAINER?=	kami@freebsd.org
COMMENT?=	Cleaned-up and enhanced version of Quake 3

LICENSE?=	GPLv2
LICENSE_FILE?=	${WRKSRC}/COPYING.txt

USES=		pkgconfig gmake

# Port configuration flags:
# 	CLIENT SERVER TOOLS DLRENDERER GAMELIBS OPUS OPENGL2
IOQ3?=		CLIENT TOOLS GAMELIBS
IOQ3ARCH?=	${ARCH}
IOQ3SDL?=	sdl

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
IOQ3_OPTIONS=	${IOQ3:MTOOLS} ${IOQ3:MDLRENDERER} ${IOQ3:MGAMELIBS} \
		${IOQ3:MOPUS}
OPTIONS_DEFINE+=	${IOQ3_OPTIONS} DOCS
OPTIONS_DEFAULT+=	${IOQ3_OPTIONS}

TOOLS_DESC=	Enable modding tools
DLRENDERER_DESC=	Build dynamically loaded renderer
GAMELIBS_DESC=	Build game libraries

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
BUILDDIR=	${WRKSRC}/build/${ALL_TARGET}-freebsd-${IOQ3ARCH}
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

DEBUG_VARS=		ALL_TARGET=debug
SERVER_RUN_DEPENDS=	${Q3SERVER}${BINSUFFIX}:games/${PORTNAME}-server
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_MAKE_ARGS=		USE_CURL=1 USE_CURL_DLOPEN=0
CURL_MAKE_ARGS_OFF=	USE_CURL=0
OPENAL_USES=		openal:al
OPENAL_MAKE_ARGS=	USE_OPENAL=1 USE_OPENAL_DLOPEN=0
OPENAL_MAKE_ARGS_OFF=	USE_OPENAL=0
VORBIS_VARS=		NEED_OGG=yes
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_MAKE_ARGS=	USE_CODEC_VORBIS=1
VORBIS_MAKE_ARGS_OFF=	USE_CODEC_VORBIS=0
OPUS_VARS=		NEED_OGG=yes
OPUS_LIB_DEPENDS=	libopusfile.so:audio/opusfile \
			libopus.so:audio/opus
OPUS_MAKE_ARGS=		USE_CODEC_OPUS=1 USE_INTERNAL_OPUS=0
OPUS_MAKE_ARGS_OFF=	USE_CODEC_OPUS=0
MUMBLE_MAKE_ARGS=	USE_MUMBLE=1
MUMBLE_MAKE_ARGS_OFF=	USE_MUMBLE=0
GAMELIBS_MAKE_ARGS=	BUILD_GAME_SO=1
GAMELIBS_MAKE_ARGS_OFF=	BUILD_GAME_SO=0
# Note that SMP is only supported on OS-X, hence the option has been removed.
SMP_VARS=		Q3BIN+=${Q3CLIENT}-smp
SMP_MAKE_ARGS=		BUILD_CLIENT_SMP=1
SMP_MAKE_ARGS_OFF=	BUILD_CLIENT_SMP=0
DLRENDERER_MAKE_ARGS=	USE_RENDERER_DLOPEN=1
DLRENDERER_MAKE_ARGS_OFF=	USE_RENDERER_DLOPEN=0

.include <bsd.port.options.mk>

.if !defined(DESKTOP_ENTRIES)
. if ${IOQ3:MCLIENT}
DESKTOP_ENTRIES+=	"${Q3CLIENT} ${Q3ENGINEVER}" "${COMMENT}"  \
			"${Q3ICON}" "${Q3CLIENT}${BINSUFFIX}" "Game;" false
. endif
. if ${PORT_OPTIONS:MSMP}
DESKTOP_ENTRIES+=	"${Q3CLIENT} ${Q3ENGINEVER} SMP" "${COMMENT}" \
			"${Q3ICON}" "${Q3CLIENT}-smp${BINSUFFIX}" "Game;" false
. endif
.endif

.if ${IOQ3:MCLIENT}
MAKE_ARGS+=	BUILD_CLIENT=1
Q3BIN+=		${Q3CLIENT}
USE_SDL=	${IOQ3SDL}
.else
MAKE_ARGS+=	BUILD_CLIENT=0
.endif

.if ${IOQ3:MSERVER}
MAKE_ARGS+=	BUILD_SERVER=1
Q3BIN+=		${Q3SERVER}
.else
MAKE_ARGS+=	BUILD_SERVER=0
.endif

.if defined(NEED_OGG)
LIB_DEPENDS+=	libogg.so:audio/libogg
MAKE_ARGS+=	USE_INTERNAL_OGG=0
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
. for doc in ${Q3DOCS:O:u}
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
	${MKDIR} ${STAGEDIR}${PREFIX}/${dir}
.endfor
.for inst in ${IOQ3_INST}
	${INSTALL_${inst:C/;.*//}} ${BUILDDIR}/${inst:C/[^;]*;//:C/;.*//} \
		${STAGEDIR}${PREFIX}/${inst:C/.*;//}
.endfor

.if !defined(Q3TOTALCONV)
.include "${.CURDIR}/../quake3-data/Makefile.include"
.endif

.include <bsd.port.mk>
