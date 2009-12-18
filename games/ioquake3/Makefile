# New ports collection makefile for:	ioquake3
# Date created:				3 Jun 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME?=	ioquake3
DISTVERSION?=	1.36
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

OPTIONS=	CLIENT "Build client" on \
		GAMELIBS "Build game libraries (when not mandatory)" off \
		DEDICATED "Build dedicated server" on \
		VORBIS "Enable Ogg Vorbis support" on

MAKE_ARGS+=	DEFAULT_BASEDIR="${Q3DIR}" \
		DEFAULT_LIBDIR="${LIBDIR}" \
		HOMEPATH="/.${PORTNAME}" \
		ARCH="${ARCH}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}" \
		ARCH="${ARCH}" \
		BINSUFFIX="${BINSUFFIX}"
ALL_TARGET=	release
MAKE_JOBS_SAFE=	yes

LIBDIR=		${PREFIX}/lib/${PORTNAME}
BUILDDIR=	${WRKSRC}/build/release-${OPSYS:L}-${ARCH}
BINSUFFIX?=

ONLY_FOR_ARCHS=	amd64 i386

# Make sure TARGET and CFLAGS fit together for cross-compiling.
MACHINE_ARCH=	${ARCH}
.include <bsd.cpu.mk>

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED) && \
    defined(WITHOUT_SMP)
IGNORE=		needs at least one of CLIENT, DEDICATED and SMP options
.endif

.if defined(WITH_CLIENT) || defined(WITH_SMP)
# OpenAL
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal
# SDL
USE_SDL=	sdl
# Vorbis
.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
MAKE_ARGS+=	USE_CODEC_VORBIS=1
.endif
.endif

# SMP is only built with CLIENT.
.if defined(WITH_CLIENT) || defined(WITH_SMP)
MAKE_ARGS+=	BUILD_CLIENT=1
PLIST_SUB+=	CLIENT=""
Q3BIN+=		ioquake3
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if defined(WITH_DEDICATED)
MAKE_ARGS+=	BUILD_SERVER=1
PLIST_SUB+=	DEDICATED=""
Q3BIN+=		ioq3ded
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
Q3BIN+=		ioquake3-smp
.else
PLIST_SUB+=	SMP="@comment "
.endif

do-install:
.for bin in ${Q3BIN}
	${INSTALL_PROGRAM} ${BUILDDIR}/${bin}.${ARCH} \
		${PREFIX}/bin/${bin}${BINSUFFIX}
.endfor
.if defined(WITH_GAMELIBS)
.for dir in baseq3 missionpack
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

.include "${.CURDIR}/../quake3-data/Makefile.include"
.include <bsd.port.post.mk>
