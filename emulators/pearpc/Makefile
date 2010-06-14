# New ports collection makefile for:	PearPC
# Date created:				22 May 2004
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pearpc
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}.0

MAINTAINER=	novel@FreeBSD.org
COMMENT=	PowerPC architecture emulator

GNU_CONFIGURE=	yes
USE_XORG=	x11
MAN1=		ppc.1
SUB_FILES=	pkg-message

PLIST_FILES=	bin/ppc etc/ppccfg.example %%DATADIR%%/video.x
PLIST_DIRS=	%%DATADIR%%

OPTIONS=	SDL		 "Use SDL for user interface"	  off \
		OPTIMIZED_CFLAGS "Make an optimized build"	  off \
		DEBUG		 "Make debug+profiled build"	  off \
		JITC		 "Enable JITC support (x86 only)" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Internal compiler error on ia64
.endif

# GTK and QT interfaces are broken in this version
#
#.if defined(WITH_QT)
#CONFIGURE_ARGS+=	--enable-ui=qt
#USE_QT_VER=	3
#QTDIR?=		${QT_PREFIX}
#CONFIGURE_ENV+=	QTDIR="${QTDIR}"
#.else
#CONFIGURE_ARGS+=	--enable-ui=nogui
#.endif

.if defined(WITH_SDL)
CONFIGURE_ARGS+=	--enable-ui=sdl
USE_SDL=	sdl
.else
CONFIGURE_ARGS+=	--enable-ui=x11
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math
.else
CONFIGURE_ARGS+=	--disable-fpo
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-profiling	# implies --enable-debug
.endif

.if defined(WITH_JITC) && ${ARCH} == "i386"
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
CONFIGURE_ARGS+=	--enable-cpu=jitc_x86
.else
CONFIGURE_ARGS+=	--enable-cpu=generic
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|-g -O2||;s|-O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|PROCESS_CPUTIME|THREAD_CPUTIME|' \
		${WRKSRC}/src/system/osapi/posix/systimer.cc
	@${REINPLACE_CMD} -e 's|video\.x"|${DATADIR}/&|' \
		${WRKSRC}/ppccfg.example

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/video.x ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ppccfg.example ${PREFIX}/etc
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
