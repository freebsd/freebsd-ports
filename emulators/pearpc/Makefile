# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pearpc
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PowerPC architecture emulator

LICENSE=	GPLv2

USES=		tar:bzip2
USE_XORG=	x11
GNU_CONFIGURE=	yes

BROKEN_ia64=	internal compiler error on ia64

PORTEXAMPLES=	ppccfg.example
PLIST_FILES=	bin/ppc man/man1/ppc.1.gz %%DATADIR%%/video.x

OPTIONS_DEFINE=		DEBUG EXAMPLES OPTIMIZED_CFLAGS SDL

DEBUG_CONFIGURE_ENABLE=	debug
OPTIMIZED_CFLAGS_CFLAGS=	-O3 -ffast-math
OPTIMIZED_CFLAGS_CONFIGURE_ENABLE=	fpo
SDL_USE=		sdl=sdl
SDL_CONFIGURE_ON=	--enable-ui=sdl
SDL_CONFIGURE_OFF=	--enable-ui=x11

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
USE_GCC=	yes
.else
CONFIGURE_ARGS+=	--enable-cpu=generic
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-O3|| ; \
		 s|^\(x86_64\)|amd64\* \| \1| ; \
		 s|-g -O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		 's|video\.x"|${DATADIR}/&|' ${WRKSRC}/ppccfg.example
	@${REINPLACE_CMD} -e \
		's|PROCESS_CPUTIME|THREAD_CPUTIME|' \
		${WRKSRC}/src/system/osapi/posix/systimer.cc

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} video.x \
		${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ppccfg.example \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
