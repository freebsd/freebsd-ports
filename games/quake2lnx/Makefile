# New ports collection makefile for:	Quake2-LNX
# Date created:				11 Jun 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	quake2lnx
PORTVERSION=	0.15
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.icculus.org/quake2/files/:src \
		http://freebsd.nsu.ru/distfiles/q2/:pak
DISTNAME=	quake2-r${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src
.if defined(WITH_EYECANDY)
DISTFILES+=	maxpak.pak:pak
.endif
.if defined(WITH_SHAREWARE_DATA)
DISTFILES+=	pak0.pak:pak \
		players.tgz:pak
.endif
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Cleaned up copy of the original Quake II source code

USE_GMAKE=	yes
USE_REINPLACE=	yes
WANT_SDL=	yes

.include <bsd.port.pre.mk>

###                       #
## CLIENTS AND RENDERERS ##
#                       ###

.if ${ARCH} == "i386" && !defined(WITHOUT_SVGA) \
	&& (defined(WITH_SVGA) || exists(${LOCALBASE}/lib/libvga.so.1))
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
MAKE_ARGS+=	BUILD_SVGA=YES
REF_TARGETS+=	soft
PLIST_SUB+=	SVGA=""
.else
PLIST_SUB+=	SVGA="@comment "
.endif

.if defined(WITH_SDLCLIENT) || defined(WITH_SDL) || defined(WITH_SDLGL) \
	|| ${HAVE_SDL:Msdl}!=""
. if !(defined(WITHOUT_SDLCLIENT) && defined(WITHOUT_SDL) \
	&& defined(WITHOUT_SDLGL))
USE_SDL=	sdl
. endif
. if !defined(WITHOUT_SDLCLIENT)
MAKE_ARGS+=	BUILD_SDLQUAKE2=YES
EXE_TARGETS+=	sdlquake2
PLIST_SUB+=	SDLCLIENT=""
. else
PLIST_SUB+=	SDLCLIENT="@comment "
. endif
. if !defined(WITHOUT_SDL)
MAKE_ARGS+=	BUILD_SDL=YES
REF_TARGETS+=	softsdl
PLIST_SUB+=	SDL=""
. else
PLIST_SUB+=	SDL="@comment "
. endif
. if !defined(WITHOUT_SDLGL)
MAKE_ARGS+=	BUILD_SDLGL=YES
REF_TARGETS+=	sdlgl
PLIST_SUB+=	SDLGL=""
. else
PLIST_SUB+=	SDLGL="@comment "
. endif
.else
PLIST_SUB+=	SDLCLIENT="@comment "
PLIST_SUB+=	SDL="@comment "
PLIST_SUB+=	SDLGL="@comment "
.endif

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
MAKE_ARGS+=	BUILD_X11=YES
REF_TARGETS+=	softx
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

.if !defined(WITHOUT_GLX) || defined(WITH_EYECANDY)
USE_GL=		yes
MAKE_ARGS+=	BUILD_GLX=YES
REF_TARGETS+=	glx
PLIST_SUB+=	GLX=""
.else
PLIST_SUB+=	GLX="@comment "
.endif

.if !defined(WITHOUT_AA) && (defined(WITH_AA) \
	|| exists(${LOCALBASE}/lib/libaa.so.1))
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
MAKE_ARGS+=	BUILD_AA=YES
REF_TARGETS+=	softaa
PLIST_SUB+=	AA=""
.else
PLIST_SUB+=	AA="@comment "
.endif

.if defined(WITH_EYECANDY)
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
MAKE_ARGS+=	BUILD_QMAX=YES
PLIST_SUB+=	QMAX=""
.else
PLIST_SUB+=	QMAX="@comment "
.endif

.if !defined(WITHOUT_CLIENT)
MAKE_ARGS+=	BUILD_CLIENT=YES
EXE_TARGETS+=	quake2
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_SERVER)
MAKE_ARGS+=	BUILD_DEDICATED=YES
PLIST_SUB+=	SERVER=""
EXE_TARGETS+=	q2ded
.else
PLIST_SUB+=	SERVER="@comment "
.endif

###                                #
## GAME, MISSION ADDONS, AND MODS ##
#                                ###

.if !defined(WITHOUT_GAME)
MAKE_ARGS+=	BUILD_GAME=YES
PLIST_SUB+=	GAME=""
.else
PLIST_SUB+=	GAME="@comment "
.endif

.if defined(WITH_CTF)
MAKE_ARGS+=	BUILD_CTFDLL=YES
PLIST_SUB+=	CTF=""
.else
PLIST_SUB+=	CTF="@comment "
.endif

.if defined(WITH_SHAREWARE_DATA)
PLIST_SUB+=	SHAREWARE=""
.else
PLIST_SUB+=	SHAREWARE="@comment "
.endif

###                        #
## MISCELLANEOUS TUNABLES ##
#                        ###

.if defined(WITH_JOYSTICK)
MAKE_ARGS+=	BUILD_JOYSTICK=YES
.endif

.if !defined(WITHOUT_ARTS) && (defined(WITH_ARTS) \
	|| exists (${LOCALBASE}/lib/libartsc.so.0))
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
MAKE_ARGS+=	BUILD_ARTS=YES
.endif

.if defined(WITH_IPV6)
MAKE_ARGS+=	HAVE_IPV6=YES
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
MAKE_ARGS+=	OPTIMIZED_CFLAGS="-O9 -pipe -s -ffast-math -funroll-loops -fomit-frame-pointer -fexpensive-optimizations"
.endif

.if ${ARCH} != "i386" || defined(WITHOUT_X86_ASM)
MAKE_ARGS+=	NO_X86_ASM=YES
.endif

###                            #
## END OF CONFIGURATION KNOBS ##
#                            ###

pre-everything::
.if ${ARCH} == "i386" && !(defined(WITH_SVGA) || exists(${LOCALBASE}/lib/libvga.so.1))
	@${ECHO_MSG} "Define WITH_SVGA to build SVGA driver"
.endif
.if !(defined(WITH_SDL) || ${HAVE_SDL:Msdl}!="")
	@${ECHO_MSG} "Define WITH_SDL to build SDL software driver"
.endif
.if !(defined(WITH_SDLGL) || ${HAVE_SDL:Msdl}!="")
	@${ECHO_MSG} "Define WITH_SDLGL to build SDL OpenGL driver"
.endif
.if !(defined(WITH_SDLCLIENT) || ${HAVE_SDL:Msdl}!="")
	@${ECHO_MSG} "Define WITH_SDLCLIENT to build executable that uses SDL for cdrom and sound"
.endif
.if !(defined(WITH_AA) || exists(${LOCALBASE}/lib/libaa.so.1))
	@${ECHO_MSG} "Define WITH_AA to build ASCII software renderer"
.endif
.if !defined(WITHOUT_X11)
	@${ECHO_MSG} "Define WITHOUT_X11 to disable building of X11 driver"
.endif
.if !defined(WITHOUT_GLX)
	@${ECHO_MSG} "Define WITHOUT_GLX to disable building of GLX driver"
.endif
.if !defined(WITH_EYECANDY)
	@${ECHO_MSG} "Define WITH_EYECANDY to build executable with fancier GL graphics"
.endif
.if !defined(WITHOUT_CLIENT)
	@${ECHO_MSG} "Define WITHOUT_CLIENT to disable building Quake2 client executable"
.endif
.if !defined(WITHOUT_SERVER)
	@${ECHO_MSG} "Define WITHOUT_SERVER to disable building of dedicated server"
.endif
.if !defined(WITHOUT_GAME)
	@${ECHO_MSG} "Define WITHOUT_GAME to build without main game .so"
.endif
.if !defined(WITH_CTF)
	@${ECHO_MSG} "Define WITH_CTF to build Capture The Flag mod"
.endif
.if !defined(WITH_SHAREWARE_DATA)
	@${ECHO_MSG} "Define WITH_SHAREWARE_DATA to install demo version game data"
.endif
.if !defined(WITH_JOYSTICK)
	@${ECHO_MSG} "Define WITH_JOYSTICK to enable joystick support"
.endif
.if !(defined(WITH_ARTS) || exists (${LOCALBASE}/lib/libartsc.so.0))
	@${ECHO_MSG} "Define WITH_ARTS to enable support for aRts sound daemon"
.endif
.if !defined(WITH_IPV6)
	@${ECHO_MSG} "Define WITH_IPV6 to enable experimental IPv6 support"
.endif
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "Define WITH_OPTIMIZED_CFLAGS to enable extra optimization options"
.endif
.if ${ARCH} == "i386" && !defined(WITHOUT_X86_ASM)
	@${ECHO_MSG} "Define WITHOUT_X86_ASM to disable x86 assembly code"
.endif

TGTDIR=		${WRKSRC}/release${ARCH}

post-patch:
	@${REINPLACE_CMD} -e 's|%%%%BASEDIR%%%%|${DATADIR}|' ${WRKSRC}/src/qcommon/files.c

do-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
	${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} build_release)

PLIST_SUB+=	ARCH="${ARCH}"

do-install:
.for tgt in ${EXE_TARGETS}
	${INSTALL_PROGRAM} ${TGTDIR}/${tgt} ${PREFIX}/bin
.endfor
	@${MKDIR} ${DATADIR}/baseq2
.for tgt in ${REF_TARGETS}
	${INSTALL_PROGRAM} ${TGTDIR}/ref_${tgt}.so ${DATADIR}
.endfor
.if !defined(WITHOUT_GAME)
	${INSTALL_PROGRAM} ${TGTDIR}/game${ARCH}.so ${DATADIR}/baseq2
.endif
.if defined(WITH_CTF)
	@${MKDIR} ${DATADIR}/ctf
	${INSTALL_PROGRAM} ${TGTDIR}/ctf/game${ARCH}.so ${DATADIR}/ctf
.endif
.if defined(WITH_SHAREWARE_DATA)
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}/pak0.pak ${DATADIR}/baseq2
	${GUNZIP_CMD} -c ${DISTDIR}/${PORTNAME}/players.tgz | ${TAR} -C ${DATADIR}/baseq2 -xf -
.endif
.if defined(WITH_EYECANDY)
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}/maxpak.pak ${DATADIR}/baseq2
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${SED} -e 's|$${DATADIR}|${DATADIR}|g' ${PKGMESSAGE}

.include <bsd.port.post.mk>
