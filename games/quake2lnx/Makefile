# New ports collection makefile for:	Quake2-LNX
# Date created:				11 Jun 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	quake2lnx
PORTVERSION=	0.16.2
CATEGORIES=	games
MASTER_SITES=	http://www.icculus.org/quake2/files/:icc \
		ftp://ftp.idsoftware.com/idstuff/quake2/:id
DISTNAME=	quake2-r${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:icc
.if defined(WITH_EYECANDY)
DISTFILES+=	maxpak.pak:icc
.endif
.if defined(WITH_RETEXTURE)
. for i in 10 11 12 13 14 16 17 19
DISTFILES+=	pak${i}.pak:icc
. endfor
.endif
.if defined(WITH_SHAREWARE_DATA) || defined(WITH_MANUAL)
DISTFILES+=	q2-314-demo-x86.exe:id
EXTRACT_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
.endif
.if defined(WITH_XATRIX)
DISTFILES+=	source/xatrixsrc320.shar.Z:id
.endif
.if defined(WITH_ROGUE)
DISTFILES+=	source/roguesrc320.shar.Z:id
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
	|| ${HAVE_SDL:Msdl} != ""
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

.if defined(WITH_XATRIX)
MAKE_ARGS+=	BUILD_XATRIX=YES
Q2MP+=		xatrix
IS_INTERACTIVE=	yes
PLIST_SUB+=	XATRIX=""
.else
PLIST_SUB+=	XATRIX="@comment "
.endif

.if defined(WITH_ROGUE)
MAKE_ARGS+=	BUILD_ROGUE=YES
Q2MP+=		rogue
IS_INTERACTIVE=	yes
PLIST_SUB+=	ROGUE=""
.else
PLIST_SUB+=	ROGUE="@comment "
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

.if defined(WITH_RETEXTURE)
MAKE_ARGS+=	BUILD_RETEXTURE=YES
PLIST_SUB+=	RETEX=""
.else
PLIST_SUB+=	RETEX="@comment "
.endif

.if defined(WITH_REDBLUE)
MAKE_ARGS+=	BUILD_REDBLUE=YES
.endif

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

.if defined(WITH_MANUAL)
PLIST_SUB+=	MANUAL=""
.else
PLIST_SUB+=	MANUAL="@comment "
.endif

###                            #
## END OF CONFIGURATION KNOBS ##
#                            ###

pre-everything::
.if ${ARCH} == "i386" && !(defined(WITH_SVGA) || exists(${LOCALBASE}/lib/libvga.so.1))
	@${ECHO_MSG} "Define WITH_SVGA to build SVGA driver"
.endif
.if !(defined(WITH_SDL) || ${HAVE_SDL:Msdl} != "")
	@${ECHO_MSG} "Define WITH_SDL to build SDL software driver"
.endif
.if !(defined(WITH_SDLGL) || ${HAVE_SDL:Msdl} != "")
	@${ECHO_MSG} "Define WITH_SDLGL to build SDL OpenGL driver"
.endif
.if !(defined(WITH_SDLCLIENT) || ${HAVE_SDL:Msdl} != "")
	@${ECHO_MSG} "Define WITH_SDLCLIENT to build executable that uses SDL for CDROM and sound"
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
.if !defined(WITH_XATRIX)
	@${ECHO_MSG} "Define WITH_XATRIX to install \"The Reckoning\" (Xatrix) mission pack .so"
.endif
.if !defined(WITH_ROGUE)
	@${ECHO_MSG} "Define WITH_ROGUE to install the \"Ground Zero\" (Rogue) mission pack .so"
.endif
.if !defined(WITH_SHAREWARE_DATA)
	@${ECHO_MSG} "Define WITH_SHAREWARE_DATA to install demo version game data"
.endif
.if !defined(WITH_MANUAL)
	@${ECHO_MSG} "Define WITH_MANUAL to install the official Quake II HTML manual"
.endif
.if !defined(WITH_RETEXTURE)
	@${ECHO_MSG} "Define WITH_RETEXTURE to enable support of retextured graphics"
.endif
.if !defined(WITH_REDBLUE)
	@${ECHO_MSG} "Define WITH_REDBLUE to enable red-blue 3D glasses rendering"
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

ALL_TARGET=	build_release
TGTDIR=		${WRKSRC}/release${ARCH}

post-extract:
.if defined(WITH_XATRIX) || defined(WITH_ROGUE)
. for mp in ${Q2MP}
	@${MKDIR} ${WRKSRC}/src/${mp}
	@(cd ${WRKSRC}/src/${mp} && ${GUNZIP_CMD} -c \
		${DISTDIR}/${DIST_SUBDIR}/source/${mp}src320.shar.Z > \
		${mp}src320.shar && ${SH} ./${mp}src320.shar)
	@${REINPLACE_CMD} -e 's/__ $$/&|| defined __FreeBSD__/' \
		${WRKSRC}/src/${mp}/q_shared.c
. endfor
.endif
.if defined(WITH_ROGUE)
	@${REINPLACE_CMD} -e '/^#include <nan.h>/d' ${WRKSRC}/src/rogue/g_local.h
.endif
	@${REINPLACE_CMD} -e 's|/dev/js|/dev/joy|' ${WRKSRC}/src/linux/joystick.c

post-patch:
	@${REINPLACE_CMD} -e 's|%%%%BASEDIR%%%%|${DATADIR}|' ${WRKSRC}/src/qcommon/files.c

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
.if defined(WITH_XATRIX) || defined(WITH_ROGUE)
. for mp in ${Q2MP}
	@${MKDIR} ${DATADIR}/${mp}
	${INSTALL_PROGRAM} ${TGTDIR}/${mp}/game${ARCH}.so ${DATADIR}/${mp}
. endfor
.endif
.if defined(WITH_CTF)
	@${MKDIR} ${DATADIR}/ctf
	${INSTALL_PROGRAM} ${TGTDIR}/ctf/game${ARCH}.so ${DATADIR}/ctf
.endif
.if defined(WITH_SHAREWARE_DATA)
	@${MKDIR} ${DATADIR}/baseq2/players
	${UNZIP_CMD} -oj -d ${DATADIR}/baseq2/players/female \
		${DISTDIR}/${DIST_SUBDIR}/q2-314-demo-x86.exe \
		Install/Data/baseq2/players/female/\*
	${UNZIP_CMD} -oj -d ${DATADIR}/baseq2/players/male \
		${DISTDIR}/${DIST_SUBDIR}/q2-314-demo-x86.exe \
		Install/Data/baseq2/players/male/\*
	${UNZIP_CMD} -oj -d ${DATADIR}/baseq2 \
		${DISTDIR}/${DIST_SUBDIR}/q2-314-demo-x86.exe \
		Install/Data/baseq2/pak0.pak
.endif
.if defined(WITH_RETEXTURE)
. for i in 10 11 12 13 14 16 17 19
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/pak${i}.pak ${DATADIR}/baseq2
. endfor
.endif
.if defined(WITH_EYECANDY)
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/maxpak.pak ${DATADIR}/baseq2
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/docs/README ${DOCSDIR}/README.320
	${INSTALL_DATA} ${WRKSRC}/src/docs/joystick.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/docs/quake2.3dfxgl ${DOCSDIR}
. if defined(WITH_MANUAL)
	${UNZIP_CMD} -oj -d ${DOCSDIR}/quake2_manual \
		${DISTDIR}/${DIST_SUBDIR}/q2-314-demo-x86.exe \
		Install/Data/DOCS/quake2_manual/\* \
		-x Install/Data/DOCS/quake2_manual/images\*
	${UNZIP_CMD} -oj -d ${DOCSDIR}/quake2_manual/images \
		${DISTDIR}/${DIST_SUBDIR}/q2-314-demo-x86.exe \
		Install/Data/DOCS/quake2_manual/images\*
	${UNZIP_CMD} -oj -d ${DOCSDIR} \
		${DISTDIR}/${DIST_SUBDIR}/q2-314-demo-x86.exe \
		Install/Data/DOCS/Manual.html
. endif
.endif

post-install:
	@${SED} -e 's|$${DATADIR}|${DATADIR}|g' ${PKGMESSAGE}

.include <bsd.port.post.mk>
