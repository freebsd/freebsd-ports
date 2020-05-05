# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	q2p
PORTVERSION=	0.2.20061231
PORTREVISION=	16
CATEGORIES=	games
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/ LOCAL/danfe
DISTNAME=	Q2P-0.2-2006-12-31

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Enhanced OpenGL-only Quake II engine

USES=		gmake tar:bzip2 xorg
USE_XORG=	xxf86dga xext xxf86vm x11
ALL_TARGET=	release

MAKE_ENV=	DATADIR="${Q2DIR}" LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR="${LIBDIR:S|${PREFIX}/||}"
LIBDIR=		${PREFIX}/lib/${PORTNAME}

PORTDOCS=	Q2P_readme.txt Ogg_readme.txt

OPTIONS_DEFINE=	CLIENT CTF DEDICATED GAME GLX OPTIMIZED_CFLAGS OSS \
		SDL SDLGL DOCS
OPTIONS_DEFAULT=	CLIENT DEDICATED GLX OPTIMIZED_CFLAGS OSS SDL SDLGL

CLIENT_DESC=	Build client
CTF_DESC=	Build CTF (Capture The Flag) mod
DEDICATED_DESC=	Build dedicated server
GAME_DESC=	Build main game (default mod)
GLX_DESC=	Build OpenGL renderer
SDL_DESC=	Sound support via SDL
SDLGL_DESC=	Build SDL OpenGL renderer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGLX} || ${PORT_OPTIONS:MSDLGL}
LIB_DEPENDS+=	libpng.so:graphics/png
USES+=		gl jpeg
USE_GL=		glu
.endif

.if ${PORT_OPTIONS:MSDL} || ${PORT_OPTIONS:MSDLGL}
USES+=		sdl
USE_SDL=	sdl
.endif

.if ${PORT_OPTIONS:MCLIENT}
LIB_DEPENDS+=	libvorbis.so:audio/libvorbis
MAKE_ENV+=	BUILD_Q2P=YES
PLIST_SUB+=	CLIENT=""
Q2BIN+=		${PORTNAME}
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MCTF}
MAKE_ENV+=	BUILD_CTF=YES
PLIST_SUB+=	CTF=""
.else
PLIST_SUB+=	CTF="@comment "
.endif

.if ${PORT_OPTIONS:MDEDICATED}
MAKE_ENV+=	BUILD_DEDICATED=YES
PLIST_SUB+=	DEDICATED=""
Q2BIN+=		${PORTNAME}-ded
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if ${PORT_OPTIONS:MGAME}
MAKE_ENV+=	BUILD_GAME=YES
PLIST_SUB+=	GAME=""
.else
PLIST_SUB+=	GAME="@comment "
.endif

.for opt in GLX SDLGL
.  if ${PORT_OPTIONS:M${opt}}
MAKE_ENV+=	BUILD_${opt}=YES
PLIST_SUB+=	${opt}=""
Q2REF+=		${opt:tl:S/glx/gl/:S/sdlgl/sdl/}
.  else
PLIST_SUB+=	${opt}="@comment "
.  endif
.endfor

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ENV+=	OPTIMIZE=YES
.endif

.if ${PORT_OPTIONS:MOSS}
MAKE_ENV+=	BUILD_OSS_SND=YES
PLIST_SUB+=	OSS=""
Q2SND+=		oss
.else
PLIST_SUB+=	OSS="@comment "
.endif

.if ${PORT_OPTIONS:MSDL}
MAKE_ENV+=	BUILD_SDL_SND=YES
PLIST_SUB+=	SDL=""
Q2SND+=		sdl
.else
PLIST_SUB+=	SDL="@comment "
.endif

post-patch:
# Resolve name collision with jpeg-8
	@${REINPLACE_CMD} -e 's|jpeg_mem_src|local_jpeg_mem_src|' \
		${WRKSRC}/ref_gl/gl_image.c

do-install:
.for bin in ${Q2BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/${bin} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${LIBDIR}/baseq2
.for ref in ${Q2REF}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/vid_${ref}.so ${STAGEDIR}${LIBDIR}
.endfor
.for snd in ${Q2SND}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/snd_${snd}.so ${STAGEDIR}${LIBDIR}
.endfor
.if ${PORT_OPTIONS:MCTF}
	@${MKDIR} ${STAGEDIR}${LIBDIR}/ctf
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/ctf/game.so \
		${STAGEDIR}${LIBDIR}/ctf
.endif
.if ${PORT_OPTIONS:MGAME}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/baseq2/game.so \
		${STAGEDIR}${LIBDIR}/baseq2
.endif
	${INSTALL_DATA} ${WRKSRC}/data/baseq2/* ${STAGEDIR}${LIBDIR}/baseq2
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.mk>
