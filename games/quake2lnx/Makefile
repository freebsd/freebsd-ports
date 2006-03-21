# New ports collection makefile for:	Quake2-LNX
# Date created:				11 Jun 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	quake2lnx
PORTVERSION=	0.16.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org/quake2/files/:icc \
		http://www.icculus.org/quake2/files/:icc \
		ftp://ftp.idsoftware.com/idstuff/quake2/source/:id
DISTNAME=	quake2-r${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:icc
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Cleaned up copy of the original Quake II source code

USE_GMAKE=	yes
WANT_SDL=	yes

OPTIONS=	X11		"Build X11 software driver" on \
		GLX		"Build GLX driver" on \
		EYECANDY	"Build executable with fancier GL graphics" off \
		SDL		"Build SDL software driver" off \
		SDLGL		"Build SDL OpenGL driver" off \
		SDLCLIENT	"Build executable that uses SDL" off \
		SVGA		"Build SVGA driver (i386 only)" off \
		AA		"Build ASCII software renderer" off \
		CLIENT		"Build client executable" on \
		SERVER		"Build dedicated server executable" on \
		GAME		"Build a main game .so file" on \
		CTF		"Build Capture The Flag mod" off \
		ROGUE		"Build Ground Zero (Rogue) mission pack" off \
		XATRIX		"Build The Reckoning (Xatrix) mission pack" off \
		RETEXTURE	"Enable support of retextured graphics" off \
		JOYSTICK	"Enable joystick support" off \
		REDBLUE		"Enable 3D glasses rendering" off \
		IPV6		"Enable experimental IPv6 support" off \
		ARTS		"Enable support for aRts sound daemon" off \
		OPTIMIZED_CFLAGS "Enable extra optimization options" off \
		X86_ASM		"Enable use of x86 assembly code" on

DATADIR=	${Q2DIR}

ALL_TARGET=	build_release

PLIST_SUB+=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

TGTDIR=		${WRKSRC}/release
LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include <bsd.port.pre.mk>

###                       #
## CLIENTS AND RENDERERS ##
#                       ###

.if defined(WITH_X11)
USE_XLIB=	yes
MAKE_ARGS+=	BUILD_X11=YES
REF_TARGETS+=	softx
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

.if defined(WITH_GLX) || defined(WITH_EYECANDY)
USE_GL=		yes
MAKE_ARGS+=	BUILD_GLX=YES
REF_TARGETS+=	glx
PLIST_SUB+=	GLX=""
.else
PLIST_SUB+=	GLX="@comment "
.endif

.if defined(WITH_EYECANDY)
DISTFILES+=	maxpak.pak:icc
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
MAKE_ARGS+=	BUILD_QMAX=YES
PLIST_SUB+=	QMAX=""
.else
PLIST_SUB+=	QMAX="@comment "
.endif

.if defined(WITH_SDL) || ${HAVE_SDL:Msdl} != ""
USE_SDL=	sdl
MAKE_ARGS+=	BUILD_SDL=YES
REF_TARGETS+=	softsdl
PLIST_SUB+=	SDL=""
.else
PLIST_SUB+=	SDL="@comment "
.endif

.if defined(WITH_SDLGL) && (defined(WITH_SDL) || ${HAVE_SDL:Msdl} != "")
MAKE_ARGS+=	BUILD_SDLGL=YES
REF_TARGETS+=	sdlgl
PLIST_SUB+=	SDLGL=""
.else
PLIST_SUB+=	SDLGL="@comment "
.endif

.if defined(WITH_SDLCLIENT) && (defined(WITH_SDL) || ${HAVE_SDL:Msdl} != "")
MAKE_ARGS+=	BUILD_SDLQUAKE2=YES
EXE_TARGETS+=	sdlquake2
PLIST_SUB+=	SDLCLIENT=""
.else
PLIST_SUB+=	SDLCLIENT="@comment "
.endif

.if ${ARCH} != "i386" && (defined(WITH_SVGA) || exists(${LOCALBASE}/lib/libvga.so.1))
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
MAKE_ARGS+=	BUILD_SVGA=YES
REF_TARGETS+=	soft
PLIST_SUB+=	SVGA=""
.else
PLIST_SUB+=	SVGA="@comment "
.endif

.if defined(WITH_AA) || exists(${LOCALBASE}/lib/libaa.so.1)
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
MAKE_ARGS+=	BUILD_AA=YES
REF_TARGETS+=	softaa
PLIST_SUB+=	AA=""
.else
PLIST_SUB+=	AA="@comment "
.endif

.if defined(WITH_CLIENT)
MAKE_ARGS+=	BUILD_CLIENT=YES
EXE_TARGETS+=	quake2
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if defined(WITH_SERVER)
MAKE_ARGS+=	BUILD_DEDICATED=YES
PLIST_SUB+=	SERVER=""
EXE_TARGETS+=	q2ded
.else
PLIST_SUB+=	SERVER="@comment "
.endif

###                                #
## GAME, MISSION ADDONS, AND MODS ##
#                                ###

.if defined(WITH_GAME)
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

.if defined(WITH_ROGUE)
DISTFILES+=	roguesrc320.shar.Z:id
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_rogue_g__local.h \
		${FILESDIR}/extra-patch-src_rogue_q__shared.c
MAKE_ARGS+=	BUILD_ROGUE=YES
Q2MP+=		rogue
ROGUE_OFF=	454
PLIST_SUB+=	ROGUE=""
.else
PLIST_SUB+=	ROGUE="@comment "
.endif

.if defined(WITH_XATRIX)
DISTFILES+=	xatrixsrc320.shar.Z:id
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_xatrix_q__shared.c
MAKE_ARGS+=	BUILD_XATRIX=YES
Q2MP+=		xatrix
XATRIX_OFF=	441
PLIST_SUB+=	XATRIX=""
.else
PLIST_SUB+=	XATRIX="@comment "
.endif

###                        #
## MISCELLANEOUS TUNABLES ##
#                        ###

.if defined(WITH_RETEXTURE)
.   for i in 10 11 12 13 14 16 17 19
DISTFILES+=	pak${i}.pak:icc
.   endfor
MAKE_ARGS+=	BUILD_RETEXTURE=YES
PLIST_SUB+=	RETEX=""
.else
PLIST_SUB+=	RETEX="@comment "
.endif

.if defined(WITH_JOYSTICK)
MAKE_ARGS+=	BUILD_JOYSTICK=YES
.endif

.if defined(WITH_REDBLUE)
MAKE_ARGS+=	BUILD_REDBLUE=YES
.endif

.if defined(WITH_IPV6)
MAKE_ARGS+=	HAVE_IPV6=YES
.endif

.if defined(WITH_ARTS) || exists (${LOCALBASE}/lib/libartsc.so.0)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
MAKE_ARGS+=	BUILD_ARTS=YES
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
MAKE_ARGS+=	OPTIMIZED_CFLAGS="-O3 -s -ffast-math -funroll-loops -fomit-frame-pointer -fexpensive-optimizations"
.endif

.if ${ARCH} != "i386" || defined(WITHOUT_X86_ASM)
MAKE_ARGS+=	NO_X86_ASM=YES
.endif

###                            #
## END OF CONFIGURATION KNOBS ##
#                            ###

post-extract:
.for mp in ${Q2MP}
	@${MKDIR} ${WRKSRC}/src/${mp}
	@(cd ${WRKSRC}/src/${mp} && ${GUNZIP_CMD} -c \
		${DISTDIR}/${DIST_SUBDIR}/${mp}src320.shar.Z > \
		${mp}src320.shar && \
		${TAIL} +${${mp:U}_OFF} ${mp}src320.shar | ${SH})
.endfor

post-patch: .SILENT
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}| ; \
		s|%%LIBDIR%%|${LIBDIR}|' ${WRKSRC}/src/qcommon/files.c \
		${WRKSRC}/src/linux/vid_so.c
	${REINPLACE_CMD} -e 's|dllname, RTLD_LAZY|& \| RTLD_GLOBAL|' \
		${WRKSRC}/src/linux/qgl_linux.c

do-install:
.for tgt in ${EXE_TARGETS}
	${INSTALL_PROGRAM} ${TGTDIR}/${tgt} ${PREFIX}/bin
.endfor
	@${MKDIR} ${LIBDIR}
.for tgt in ${REF_TARGETS}
	${INSTALL_PROGRAM} ${TGTDIR}/ref_${tgt}.so ${LIBDIR}
.endfor
.if defined(WITH_CTF)
	@${MKDIR} ${LIBDIR}/ctf
	${INSTALL_PROGRAM} ${TGTDIR}/ctf/game.so ${LIBDIR}/ctf
.endif
.if defined(WITH_EYECANDY)
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/maxpak.pak ${DATADIR}/baseq2
.endif
.if defined(WITH_GAME)
	@${MKDIR} ${LIBDIR}/baseq2
	${INSTALL_PROGRAM} ${TGTDIR}/game.so ${LIBDIR}/baseq2
.endif
.if defined(WITH_RETEXTURE)
.   for i in 10 11 12 13 14 16 17 19
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/pak${i}.pak ${DATADIR}/baseq2
.   endfor
.endif
.for mp in ${Q2MP}
	@${MKDIR} ${LIBDIR}/${mp}
	${INSTALL_PROGRAM} ${TGTDIR}/${mp}/game.so ${LIBDIR}/${mp}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/docs/README ${DOCSDIR}/README.320
	${INSTALL_DATA} ${WRKSRC}/src/docs/joystick.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/docs/quake2.3dfxgl ${DOCSDIR}
.endif

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.post.mk>
