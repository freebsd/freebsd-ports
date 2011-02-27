# New ports collection makefile for:	qudos
# Date created:				24 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	qudos
PORTVERSION=	0.40.1
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://qudos.quakedev.com/linux/quake2/engines/QuDos/
DISTNAME=	QuDos-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		QuDos-${PORTVERSION}.pk3
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhaced OpenGL only Quake II engine

USE_BZIP2=	yes
USE_GMAKE=	yes

OPTIONS=	3ZB2 "Build 3zb2 modification (bots)" on \
		ARTS "Enable support for aRts sound daemon" off \
		BOTS "Enable Ace Bot support in modifications" on \
		CLIENT "Build client" on \
		CTF "Build CTF (Capture The Flag) modification" off \
		DEDICATED "Build dedicated server" on \
		GAME "Build a main game .so modification" off \
		GAME_MOD "Enable custom addons in main modification" on \
		GLX "Build OpenGL renderer" on \
		IPV6 "Enable IPv6 support" off \
		JABOT "Build JABot modification (bots)" off \
		JOYSTICK "Enable joystick support" off \
		OSS "Enable Open Sound System sound support" on \
		QMAX "Enable fancier OpenGL graphics" on \
		REDBLUE "Enable red-blue 3d glasses renderer" off \
		RETEXTURE "Enable support for retextured graphics" off \
		ROGUE "Build Ground Zero (Rogue) mission pack" off \
		SDL "Enable SDL sound support" on \
		SDLGL "Build SDL OpenGL renderer" on \
		X86_ASM "Enable x86 assembly support" on \
		XATRIX "Build The Reckoning (Xatrix) mission pack" off \
		ZAERO "Build Zaero modification" off

MAKE_ENV=	WITH_DATADIR=YES WITH_LIBDIR=YES WITH_XMMS=NO \
		DATADIR="${Q2DIR}" LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}" VER="${PORTVERSION}"
LIBDIR=		${PREFIX}/lib/${PORTNAME}

MOD_LIST=	3ZB2 CTF JABOT ROGUE XATRIX ZAERO

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

.for mod in ${MOD_LIST}
.   if defined(WITH_${mod})
MAKE_ENV+=	BUILD_${mod}=YES
PLIST_SUB+=	${mod}=""
.   else
MAKE_ENV+=	BUILD_${mod}=NO
PLIST_SUB+=	${mod}="@comment "
.   endif
.endfor

.if !defined(WITHOUT_GLX) || !defined(WITHOUT_SDLGL)
USE_GL=		yes
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png
.endif

.if !defined(WITHOUT_SDL) || !defined(WITHOUT_SDLGL)
USE_SDL=	sdl
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
MAKE_ENV+=	BUILD_ARTS_SND=YES
PLIST_SUB+=	ARTS=""
Q2SND+=		arts
.else
MAKE_ENV+=	BUILD_ARTS_SND=NO
PLIST_SUB+=	ARTS="@comment "
.endif

.if !defined(WITHOUT_CLIENT)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
MAKE_ENV+=	BUILD_QUAKE2=YES
PLIST_SUB+=	CLIENT=""
Q2BIN+=		${PORTNAME}
.else
MAKE_ENV+=	BUILD_QUAKE2=NO
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_DEDICATED)
MAKE_ENV+=	BUILD_DEDICATED=YES
PLIST_SUB+=	DEDICATED=""
Q2BIN+=		${PORTNAME}-ded
.else
MAKE_ENV+=	BUILD_DEDICATED=NO
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if defined(WITH_GAME)
MAKE_ENV+=	BUILD_GAME=YES
PLIST_SUB+=	GAME=""
.else
MAKE_ENV+=	BUILD_GAME=NO
PLIST_SUB+=	GAME="@comment "
.endif

.if !defined(WITHOUT_GAME_MOD)
MAKE_ENV+=	WITH_GAME_MOD=YES
.else
MAKE_ENV+=	WITH_GAME_MOD=NO
.endif

.for opt in GLX SDLGL
.   if !defined(WITHOUT_${opt})
MAKE_ENV+=	BUILD_${opt}=YES
PLIST_SUB+=	${opt}=""
Q2REF+=		${opt:L}
.   else
MAKE_ENV+=	BUILD_${opt}=NO
PLIST_SUB+=	${opt}="@comment "
.   endif
.endfor

.if defined(WITH_IPV6)
MAKE_ENV+=	WITH_IPV6=YES
.else
MAKE_ENV+=	WITH_IPV6=NO
.endif

.if defined(WITH_JOYSTICK)
MAKE_ENV+=	WITH_JOYSTICK=YES
.else
MAKE_ENV+=	WITH_JOYSTICK=NO
.endif

.if !defined(WITHOUT_OSS)
MAKE_ENV+=	BUILD_OSS_SND=YES
PLIST_SUB+=	OSS=""
Q2SND+=		oss
.else
MAKE_ENV+=	BUILD_OSS_SND=NO
PLIST_SUB+=	OSS="@comment "
.endif

.if !defined(WITHOUT_QMAX)
MAKE_ENV+=	WITH_QMAX=YES
.else
MAKE_ENV+=	WITH_QMAX=NO
.endif

.if defined(WITH_REDBLUE)
MAKE_ENV+=	WITH_REDBLUE=YES
.else
MAKE_ENV+=	WITH_REDBLUE=NO
.endif

.if defined(WITH_RETEXTURE)
MAKE_ENV+=	WITH_RETEXTURE=YES
.else
MAKE_ENV+=	WITH_RETEXTURE=NO
.endif

.if !defined(WITHOUT_SDL)
MAKE_ENV+=	BUILD_SDL_SND=YES
PLIST_SUB+=	SDL=""
Q2SND+=		sdl
.else
MAKE_ENV+=	BUILD_SDL_SND=NO
PLIST_SUB+=	SDL="@comment "
.endif

.if !defined(WITHOUT_X86_ASM)
MAKE_ENV+=	WITH_X86_ASM=YES
.else
MAKE_ENV+=	WITH_X86_ASM=NO
.endif

post-patch:
# Resolve name collision with jpeg-8
	${REINPLACE_CMD} -e 's|jpeg_mem_src|local_jpeg_mem_src|' \
		${WRKSRC}/src/ref_gl/gl_image.c

post-build:
.for bin in ${Q2BIN}
	@cd ${WRKSRC}/quake2 && ${MV} ${bin:S/qudos/QuDos/} ${bin}
.endfor

do-install:
.for bin in ${Q2BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/${bin} ${PREFIX}/bin
.endfor
	${MKDIR} ${LIBDIR}/baseq2
.for ref in ${Q2REF}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/ref_q2${ref}.so ${LIBDIR}
.endfor
.for snd in ${Q2SND}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/snd_${snd}.so ${LIBDIR}
.endfor
.if defined(WITH_GAME)
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/baseq2/game.so ${LIBDIR}/baseq2
.endif
.for mod in ${MOD_LIST:L}
.if defined(WITH_${mod:U})
	${MKDIR} ${LIBDIR}/${mod}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/${mod}/game.so ${LIBDIR}/${mod}
.endif
.endfor
	${INSTALL_DATA} ${_DISTDIR}/QuDos-${PORTVERSION}.pk3 ${LIBDIR}/baseq2
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/QuDos.txt ${WRKSRC}/docs/Ogg_readme.txt \
		${DOCSDIR}
.endif

.include <bsd.port.post.mk>
