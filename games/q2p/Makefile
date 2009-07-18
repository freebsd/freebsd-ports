# New ports collection makefile for:	q2p
# Date created:				2007-01-05
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	q2p
PORTVERSION=	0.2.20061231
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://qudos.quakedev.com/linux/quake2/engines/Q2P/
DISTNAME=	Q2P-0.2-2006-12-31

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Ehnaced OpenGL only Quake II engine

USE_BZIP2=	yes
USE_XORG=	xxf86dga xext xxf86vm x11
USE_GMAKE=	yes
ALL_TARGET=	release

OPTIONS=	CLIENT "Build client" on \
		CTF "Build CTF (Capture The Flag) modification" off \
		DEDICATED "Build dedicated server" on \
		GAME "Build a main game .so modification" off \
		GLX "Build OpenGL renderer" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		OSS "Enable Open Sound System sound support" on \
		SDL "Enable SDL sound support" on \
		SDLGL "Build SDL OpenGL renderer" on

MAKE_ENV=	DATADIR="${Q2DIR}" LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"
LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GLX) || !defined(WITHOUT_SDLGL)
USE_GL=		glu
LIB_DEPENDS+=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png
.endif

.if !defined(WITHOUT_SDL) || !defined(WITHOUT_SDLGL)
USE_SDL=	sdl
.endif

.if !defined(WITHOUT_CLIENT)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
MAKE_ENV+=	BUILD_Q2P=YES
PLIST_SUB+=	CLIENT=""
Q2BIN+=		${PORTNAME}
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if defined(WITH_CTF)
MAKE_ENV+=	BUILD_CTF=YES
PLIST_SUB+=	CTF=""
.else
PLIST_SUB+=	CTF="@comment "
.endif

.if !defined(WITHOUT_DEDICATED)
MAKE_ENV+=	BUILD_DEDICATED=YES
PLIST_SUB+=	DEDICATED=""
Q2BIN+=		${PORTNAME}-ded
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if defined(WITH_GAME)
MAKE_ENV+=	BUILD_GAME=YES
PLIST_SUB+=	GAME=""
.else
PLIST_SUB+=	GAME="@comment "
.endif

.for opt in GLX SDLGL
.   if !defined(WITHOUT_${opt})
MAKE_ENV+=	BUILD_${opt}=YES
PLIST_SUB+=	${opt}=""
Q2REF+=		${opt:L:S/glx/gl/:S/sdlgl/sdl/}
.   else
PLIST_SUB+=	${opt}="@comment "
.   endif
.endfor

.if !defined(WITH_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZE=YES
.endif

.if !defined(WITHOUT_OSS)
MAKE_ENV+=	BUILD_OSS_SND=YES
PLIST_SUB+=	OSS=""
Q2SND+=		oss
.else
PLIST_SUB+=	OSS="@comment "
.endif

.if !defined(WITHOUT_SDL)
MAKE_ENV+=	BUILD_SDL_SND=YES
PLIST_SUB+=	SDL=""
Q2SND+=		sdl
.else
PLIST_SUB+=	SDL="@comment "
.endif

do-install:
.for bin in ${Q2BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/${bin} ${PREFIX}/bin
.endfor
	${MKDIR} ${LIBDIR}/baseq2
.for ref in ${Q2REF}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/vid_${ref}.so ${LIBDIR}
.endfor
.for snd in ${Q2SND}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/snd_${snd}.so ${LIBDIR}
.endfor
.if defined(WITH_CTF)
	${MKDIR} ${LIBDIR}/ctf
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/ctf/game.so ${LIBDIR}/ctf
.endif
.if defined(WITH_GAME)
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/baseq2/game.so ${LIBDIR}/baseq2
.endif
	${INSTALL_DATA} ${WRKSRC}/data/baseq2/* ${LIBDIR}/baseq2
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} Q2P_readme.txt Ogg_readme.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
