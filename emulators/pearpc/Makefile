# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pearpc
PORTVERSION=	0.4
PORTREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}.0

MAINTAINER=	novel@FreeBSD.org
COMMENT=	PowerPC architecture emulator

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_XORG=	x11
MAN1=		ppc.1
SUB_FILES=	pkg-message

PLIST_FILES=	bin/ppc etc/ppccfg.example %%DATADIR%%/video.x
PLIST_DIRS=	%%DATADIR%%

OPTIONS_DEFINE=	SDL OPTIMIZED_CFLAGS DEBUG
SDL_DESC=	Use SDL for user interface

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Internal compiler error on ia64
.endif

.if ${PORT_OPTIONS:MSDL}
CONFIGURE_ARGS+=	--enable-ui=sdl
USE_SDL=	sdl
.else
CONFIGURE_ARGS+=	--enable-ui=x11
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math
.else
CONFIGURE_ARGS+=	--disable-fpo
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-profiling	# implies --enable-debug
.endif

.if ${ARCH} == "i386"
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
