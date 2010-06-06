# New ports collection makefile for:	ioquake3
# Date created:				3 Jun 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME?=	ioquake3
DISTVERSION?=	1.36
PORTREVISION?=	6
CATEGORIES=	games
MASTER_SITES?=	http://ioquake3.org/files/${DISTVERSION}/

MAINTAINER?=	kamikaze@bsdforen.de
COMMENT?=	Cleaned-up and enhaced version of Quake 3

USE_ZIP?=	yes
# Allow slave ports to turn off zip.
.if ${USE_ZIP} == "no"
.undef USE_ZIP
.endif
USE_GMAKE=	yes

OPTIONS+=	CLIENT "Build client" on \
		GAMELIBS "Build game libraries" off \
		DEDICATED "Build dedicated server" on \
		CURL "Enable cURL for http/ftp download" on \
		OPENAL "Enable OpenAL audio output" on \
		MUMBLE "Enable Mumble support (no dependencies)" on \
		VORBIS "Enable Ogg Vorbis support" on

MAKE_ARGS+=	DEFAULT_BASEDIR="${Q3DIR}" \
		DEFAULT_LIBDIR="${LIBDIR}" \
		HOMEPATH="/.${PORTNAME}" \
		VERSION="${DISTVERSION}" \
		ARCH="${ARCH}"
PLIST_SUB+=	LIBDIR="${LIBDIR:S/${PREFIX}\///}" \
		ARCH="${ARCH}" \
		BINSUFFIX="${BINSUFFIX}"
ALL_TARGET=	release
MAKE_JOBS_SAFE=	yes

LIBDIR=		${PREFIX}/lib/${PORTNAME}
BUILDDIR=	${WRKSRC}/build/release-${OPSYS:L}-${ARCH}
BINSUFFIX?=
Q3CLIENT?=	ioquake3
Q3SERVER?=	ioq3ded
Q3TOOLS?=	q3asm \
		q3cpp \
		q3lcc \
		q3rcc
Q3BASE?=	baseq3 \
		missionpack
Q3INSTALL?=

ONLY_FOR_ARCHS=	amd64 i386

# Make sure TARGET and CFLAGS fit together for cross-compiling.
MACHINE_ARCH=	${ARCH}
.include <bsd.cpu.mk>

.include <bsd.port.options.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED) && \
    defined(WITHOUT_SMP)
IGNORE=		needs at least one of CLIENT, DEDICATED and SMP options
.endif

.if defined(WITH_CLIENT) || defined(WITH_SMP)
# cURL
.if defined(WITH_CURL)
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
#MAKE_ARGS+=	USE_CURL_DLOPEN=0
.else
MAKE_ARGS+=	USE_CURL=0
.endif
# OpenAL
.if defined(WITH_OPENAL)
USE_OPENAL=	al
.else
MAKE_ARGS+=	USE_OPENAL=0
.endif
# SDL
USE_SDL=	sdl
# Vorbis
.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
MAKE_ARGS+=	USE_CODEC_VORBIS=1
.endif
# Mumble
.if defined(WITH_MUMBLE)
MAKE_ARGS+=	USE_MUMBLE=1
.else
MAKE_ARGS+=	USE_MUMBLE=0
.endif
.endif

# SMP is only built with CLIENT.
.if defined(WITH_CLIENT) || defined(WITH_SMP)
MAKE_ARGS+=	BUILD_CLIENT=1
PLIST_SUB+=	CLIENT=""
Q3BIN+=		${Q3CLIENT}
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if defined(WITH_DEDICATED)
MAKE_ARGS+=	BUILD_SERVER=1
PLIST_SUB+=	DEDICATED=""
Q3BIN+=		${Q3SERVER}
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if defined(WITH_GAMELIBS)
MAKE_ARGS+=	BUILD_GAME_SO=1
PLIST_SUB+=	GAMELIBS=""
.else
PLIST_SUB+=	GAMELIBS="@comment "
.endif

# Note that SMP is only supported on OS-X, hence the option has been removed.
.if defined(WITH_SMP)
MAKE_ARGS+=	BUILD_CLIENT_SMP=1
PLIST_SUB+=	SMP=""
Q3BIN+=		${Q3CLIENT}-smp
.else
PLIST_SUB+=	SMP="@comment "
.endif

do-install: ${Q3INSTALL}
.for bin in ${Q3BIN}
	${INSTALL_PROGRAM} ${BUILDDIR}/${bin}.${ARCH} \
		${PREFIX}/bin/${bin}${BINSUFFIX}
.endfor
.for bin in ${Q3TOOLS}
	${INSTALL_PROGRAM} ${BUILDDIR}/tools/${bin} \
		${PREFIX}/bin/${bin}${BINSUFFIX}
.endfor
.if defined(WITH_GAMELIBS)
.for dir in ${Q3BASE}
	${MKDIR} ${LIBDIR}/${dir}
	${INSTALL_PROGRAM} ${BUILDDIR}/${dir}/*.so ${LIBDIR}/${dir}
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

.if !defined(Q3TOTALCONV)
.include "${.CURDIR}/../quake3-data/Makefile.include"
.endif

.include <bsd.port.mk>
