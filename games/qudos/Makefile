# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qudos
PORTVERSION=	0.40.1
PORTREVISION=	19
CATEGORIES=	games
MASTER_SITES=	http://www.bfeared.com/library/quake/archive/quakedev/qudos/quake2/engines/QuDos/
DISTNAME=	QuDos-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		QuDos-${PORTVERSION}.pk3
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Enhanced OpenGL-only Quake II engine

BROKEN=		unfetchable

USES=		gmake tar:bzip2
MAKE_ENV=	WITH_DATADIR=YES WITH_LIBDIR=YES WITH_XMMS=NO \
		DATADIR="${Q2DIR}" LIBDIR="${LIBDIR}" BUILD_ARTS_SND=NO
PLIST_SUB=	LIBDIR="${LIBDIR:S,${PREFIX}/,,}" VER="${PORTVERSION}"
LIBDIR=		${PREFIX}/lib/${PORTNAME}

MOD_LIST=	3ZB2 CTF JABOT ROGUE XATRIX ZAERO

OPTIONS_DEFINE=		3ZB2 BOTS CLIENT CTF DEDICATED GAME GAME_MOD \
			GLX IPV6 JABOT JOYSTICK OSS QMAX REDBLUE RETEXTURE \
			ROGUE SDL SDLGL XATRIX ZAERO DOCS
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFINE_amd64=	ASM
OPTIONS_DEFAULT_i386=	ASM
OPTIONS_DEFAULT_amd64=	ASM

OPTIONS_DEFAULT=	3ZB2 BOTS CLIENT DEDICATED GAME_MOD GLX JOYSTICK OSS \
			QMAX SDL SDLGL

3ZB2_DESC=	Build 3zb2 mod (bots)
BOTS_DESC=	Ace Bot support in mods
CLIENT_DESC=	Build client
CTF_DESC=	Build CTF (Capture The Flag) mod
DEDICATED_DESC=	Build dedicated server
GAME_DESC=	Build main game (default mod)
GAME_MOD_DESC=	Add custom add-ons to the main game
JABOT_DESC=	Build JABot mod (bots)
JOYSTICK_DESC=	Joystick support
QMAX_DESC=	Enable fancier OpenGL graphics
REDBLUE_DESC=	Enable red-blue 3D glasses renderer
RETEXTURE_DESC=	Retextured graphics support
ROGUE_DESC=	Build Ground Zero (Rogue) mission pack
SDLGL_DESC=	Build SDL OpenGL renderer
XATRIX_DESC=	Build The Reckoning (Xatrix) mission pack
ZAERO_DESC=	Build Zaero mission pack

.include <bsd.port.options.mk>

.for mod in ${MOD_LIST}
.  if ${PORT_OPTIONS:M${mod}}
MAKE_ENV+=	BUILD_${mod}=YES
PLIST_SUB+=	${mod}=""
.  else
MAKE_ENV+=	BUILD_${mod}=NO
PLIST_SUB+=	${mod}="@comment "
.  endif
.endfor

.if ${PORT_OPTIONS:MGLX} || ${PORT_OPTIONS:MSDLGL}
USES+=		gl jpeg
USE_GL=		glu
LIB_DEPENDS+=	libpng.so:graphics/png
.endif

.if ${PORT_OPTIONS:MSDL} || ${PORT_OPTIONS:MSDLGL}
USES+=		sdl
USE_SDL=	sdl
.endif

.if ${PORT_OPTIONS:MCLIENT}
LIB_DEPENDS+=	libvorbis.so:audio/libvorbis
MAKE_ENV+=	BUILD_QUAKE2=YES
PLIST_SUB+=	CLIENT=""
Q2BIN+=		${PORTNAME}
.else
MAKE_ENV+=	BUILD_QUAKE2=NO
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MDEDICATED}
MAKE_ENV+=	BUILD_DEDICATED=YES
PLIST_SUB+=	DEDICATED=""
Q2BIN+=		${PORTNAME}-ded
.else
MAKE_ENV+=	BUILD_DEDICATED=NO
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if ${PORT_OPTIONS:MGAME}
MAKE_ENV+=	BUILD_GAME=YES
PLIST_SUB+=	GAME=""
.else
MAKE_ENV+=	BUILD_GAME=NO
PLIST_SUB+=	GAME="@comment "
.endif

.if ${PORT_OPTIONS:MGAME_MOD}
MAKE_ENV+=	WITH_GAME_MOD=YES
.else
MAKE_ENV+=	WITH_GAME_MOD=NO
.endif

.for opt in GLX SDLGL
.  if ${PORT_OPTIONS:M${opt}}
MAKE_ENV+=	BUILD_${opt}=YES
PLIST_SUB+=	${opt}=""
Q2REF+=		${opt:tl}
.  else
MAKE_ENV+=	BUILD_${opt}=NO
PLIST_SUB+=	${opt}="@comment "
.  endif
.endfor

.if ${PORT_OPTIONS:MIPV6}
MAKE_ENV+=	WITH_IPV6=YES
.else
MAKE_ENV+=	WITH_IPV6=NO
.endif

.if ${PORT_OPTIONS:MJOYSTICK}
MAKE_ENV+=	WITH_JOYSTICK=YES
.else
MAKE_ENV+=	WITH_JOYSTICK=NO
.endif

.if ${PORT_OPTIONS:MOSS}
MAKE_ENV+=	BUILD_OSS_SND=YES
PLIST_SUB+=	OSS=""
Q2SND+=		oss
.else
MAKE_ENV+=	BUILD_OSS_SND=NO
PLIST_SUB+=	OSS="@comment "
.endif

.if ${PORT_OPTIONS:MQMAX}
MAKE_ENV+=	WITH_QMAX=YES
.else
MAKE_ENV+=	WITH_QMAX=NO
.endif

.if ${PORT_OPTIONS:MREDBLUE}
MAKE_ENV+=	WITH_REDBLUE=YES
.else
MAKE_ENV+=	WITH_REDBLUE=NO
.endif

.if ${PORT_OPTIONS:MRETEXTURE}
MAKE_ENV+=	WITH_RETEXTURE=YES
.else
MAKE_ENV+=	WITH_RETEXTURE=NO
.endif

.if ${PORT_OPTIONS:MSDL}
MAKE_ENV+=	BUILD_SDL_SND=YES
PLIST_SUB+=	SDL=""
Q2SND+=		sdl
.else
MAKE_ENV+=	BUILD_SDL_SND=NO
PLIST_SUB+=	SDL="@comment "
.endif

.if ${PORT_OPTIONS:MASM}
MAKE_ENV+=	WITH_X86_ASM=YES
.else
MAKE_ENV+=	WITH_X86_ASM=NO
.endif

post-patch:
# Resolve name collision with jpeg-8
	@${REINPLACE_CMD} -e 's|jpeg_mem_src|local_jpeg_mem_src|' \
		${WRKSRC}/src/ref_gl/gl_image.c
# Remove controversial options unsupported by modern compilers (e.g. Clang)
	@${REINPLACE_CMD} -e 's|-falign-loops=2 -falign-jumps=2 ||' \
		${WRKSRC}/src/ref_gl/Makefile ${WRKSRC}/Makefile

post-build:
.for bin in ${Q2BIN}
	@cd ${WRKSRC}/quake2 && ${MV} ${bin:S/qudos/QuDos/} ${bin}
.endfor

do-install:
.for bin in ${Q2BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/${bin} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${LIBDIR}/baseq2
.for ref in ${Q2REF}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/ref_q2${ref}.so \
		${STAGEDIR}${LIBDIR}
.endfor
.for snd in ${Q2SND}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/snd_${snd}.so ${STAGEDIR}${LIBDIR}
.endfor
.if ${PORT_OPTIONS:MGAME}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/baseq2/game.so \
		${STAGEDIR}${LIBDIR}/baseq2
.endif
.for mod in ${MOD_LIST:tl}
.if ${PORT_OPTIONS:M${mod:tu}}
	@${MKDIR} ${STAGEDIR}${LIBDIR}/${mod}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/${mod}/game.so \
		${STAGEDIR}${LIBDIR}/${mod}
.endif
.endfor
	${INSTALL_DATA} ${_DISTDIR}/QuDos-${PORTVERSION}.pk3 \
		${STAGEDIR}${LIBDIR}/baseq2
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/QuDos.txt \
		${WRKSRC}/docs/Ogg_readme.txt ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.mk>
