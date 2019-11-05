# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	quake2lnx
PORTVERSION=	0.16.2
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org/quake2/files/
DISTNAME=	quake2-r${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Icculus.org version of the original Quake II

LICENSE=	GPLv2

USES=		gmake
ALL_TARGET=	build_release

LIBDIR=		${PREFIX}/lib/${PORTNAME}
PLIST_SUB+=	LIBDIR="${LIBDIR:S|${PREFIX}/||}"

OPTIONS_DEFINE=		X11 GLX EYECANDY SOFTSDL SDLGL SDLCLIENT AA CLIENT \
			SERVER GAME CTF RETEXTURE JOYSTICK REDBLUE IPV6 \
			OPTIMIZED_CFLAGS DOCS
OPTIONS_DEFAULT=	X11 GLX CLIENT SERVER
OPTIONS_DEFINE_i386=	SVGA ASM
OPTIONS_DEFAULT_i386=	ASM

X11_DESC=		Build X11 (software) renderer
GLX_DESC=		Build OpenGL (GLX) renderer
EYECANDY_DESC=		Build client with fancier GL graphics
SOFTSDL_DESC=		Build software SDL renderer
SDLGL_DESC=		Build SDL OpenGL renderer
SDLCLIENT_DESC=		Build SDL client
SVGA_DESC=		Build SVGA renderer
AA_DESC=		Build ASCII graphics renderer
CLIENT_DESC=		Build original client
SERVER_DESC=		Build dedicated server
GAME_DESC=		Build main game (default mod)
CTF_DESC=		Build Capture The Flag mod
RETEXTURE_DESC=		Retextured graphics support
JOYSTICK_DESC=		Joystick support
REDBLUE_DESC=		Enable 3D glasses rendering

.include <bsd.port.options.mk>

###                       #
## CLIENTS AND RENDERERS ##
#                       ###

.if ${PORT_OPTIONS:MX11}
USES+=		xorg
USE_XORG=	x11 xext xxf86dga xxf86vm
MAKE_ARGS+=	BUILD_X11=YES
REF_TARGETS+=	softx
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

.if ${PORT_OPTIONS:MGLX} || ${PORT_OPTIONS:MEYECANDY}
USES+=		gl xorg
USE_GL=		gl
USE_XORG=	x11 xext xxf86dga xxf86vm
MAKE_ARGS+=	BUILD_GLX=YES
REF_TARGETS+=	glx
PLIST_SUB+=	GLX=""
.else
PLIST_SUB+=	GLX="@comment "
.endif

.if ${PORT_OPTIONS:MEYECANDY}
DISTFILES+=	maxpak.pak
USES+=		gl jpeg
USE_GL=		glu
MAKE_ARGS+=	BUILD_QMAX=YES
PLIST_SUB+=	QMAX=""
.else
PLIST_SUB+=	QMAX="@comment "
.endif

.if ${PORT_OPTIONS:MSOFTSDL}
USES+=		sdl
USE_SDL=	sdl
MAKE_ARGS+=	BUILD_SDL=YES
REF_TARGETS+=	softsdl
PLIST_SUB+=	SOFTSDL=""
.else
PLIST_SUB+=	SOFTSDL="@comment "
.endif

.if ${PORT_OPTIONS:MSDLGL}
USES+=		sdl
USE_SDL=	sdl
MAKE_ARGS+=	BUILD_SDLGL=YES
REF_TARGETS+=	sdlgl
PLIST_SUB+=	SDLGL=""
.else
PLIST_SUB+=	SDLGL="@comment "
.endif

.if ${PORT_OPTIONS:MSDLCLIENT}
USES+=		sdl
USE_SDL=	sdl
MAKE_ARGS+=	BUILD_SDLQUAKE2=YES
EXE_TARGETS+=	quake2-sdl
PLIST_SUB+=	SDLCLIENT=""
.else
PLIST_SUB+=	SDLCLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MSVGA}
LIB_DEPENDS+=	libvga.so:graphics/svgalib
MAKE_ARGS+=	BUILD_SVGA=YES
REF_TARGETS+=	soft
PLIST_SUB+=	SVGA=""
.else
PLIST_SUB+=	SVGA="@comment "
.endif

.if ${PORT_OPTIONS:MAA}
LIB_DEPENDS+=	libaa.so:graphics/aalib
MAKE_ARGS+=	BUILD_AA=YES
REF_TARGETS+=	softaa
PLIST_SUB+=	AA=""
.else
PLIST_SUB+=	AA="@comment "
.endif

.if ${PORT_OPTIONS:MCLIENT}
MAKE_ARGS+=	BUILD_CLIENT=YES
EXE_TARGETS+=	quake2
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MSERVER}
MAKE_ARGS+=	BUILD_DEDICATED=YES
PLIST_SUB+=	SERVER=""
EXE_TARGETS+=	q2ded
.else
PLIST_SUB+=	SERVER="@comment "
.endif

###                                #
## GAME, MISSION ADDONS, AND MODS ##
#                                ###

.if ${PORT_OPTIONS:MGAME}
MAKE_ARGS+=	BUILD_GAME=YES
PLIST_SUB+=	GAME=""
.else
PLIST_SUB+=	GAME="@comment "
.endif

.if ${PORT_OPTIONS:MCTF}
MAKE_ARGS+=	BUILD_CTFDLL=YES
PLIST_SUB+=	CTF=""
.else
PLIST_SUB+=	CTF="@comment "
.endif

###                        #
## MISCELLANEOUS TUNABLES ##
#                        ###

.if ${PORT_OPTIONS:MRETEXTURE}
MAKE_ARGS+=	BUILD_RETEXTURE=YES
RUN_DEPENDS+=	${Q2DIR}/baseq2/pak10.pak:games/quake2-extras
.endif

.if ${PORT_OPTIONS:MJOYSTICK}
MAKE_ARGS+=	BUILD_JOYSTICK=YES
.endif

.if ${PORT_OPTIONS:MREDBLUE}
MAKE_ARGS+=	BUILD_REDBLUE=YES
.endif

.if ${PORT_OPTIONS:MIPV6}
MAKE_ARGS+=	HAVE_IPV6=YES
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ARGS+=	OPTIMIZED_CFLAGS="-O3 -ffast-math -funroll-loops -fomit-frame-pointer"
.endif

.if ! ${PORT_OPTIONS:MASM}
MAKE_ARGS+=	NO_X86_ASM=YES
.endif

###                            #
## END OF CONFIGURATION KNOBS ##
#                            ###

post-patch: .SILENT
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${Q2DIR}| ; \
		s|%%LIBDIR%%|${LIBDIR}|' ${WRKSRC}/src/qcommon/files.c \
		${WRKSRC}/src/linux/vid_so.c
	${REINPLACE_CMD} -e 's|dllname, RTLD_LAZY|& \| RTLD_GLOBAL|' \
		${WRKSRC}/src/linux/qgl_linux.c
	${REINPLACE_CMD} -e 's|/js|/joy|' ${WRKSRC}/src/linux/joystick.c
	${REINPLACE_CMD} -e 's|jpeg_mem_src|local_&|' \
		${WRKSRC}/src/ref_candygl/gl_image.c
	${REINPLACE_CMD} -e '/BUILDSTRING/s|Linux|${OPSYS}|' \
		-e '/CPUSTRING/s|Unknown|${ARCH}|' \
		${WRKSRC}/src/qcommon/qcommon.h
.if ${PORT_OPTIONS:MASM}
	${REINPLACE_CMD} -e '/^SHLIBLDFLAGS/s|$$| -Wl,-z,notext|' \
		${WRKSRC}/Makefile
.endif

do-install:
.for tgt in ${EXE_TARGETS}
	${INSTALL_PROGRAM} ${WRKSRC}/release/${tgt} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${LIBDIR}/baseq2
.for tgt in ${REF_TARGETS}
	${INSTALL_PROGRAM} ${WRKSRC}/release/ref_${tgt}.so \
		${STAGEDIR}${LIBDIR}
.endfor
.if ${PORT_OPTIONS:MCTF}
	@${MKDIR} ${STAGEDIR}${LIBDIR}/ctf
	${INSTALL_PROGRAM} ${WRKSRC}/release/ctf/game.so \
		${STAGEDIR}${LIBDIR}/ctf
.endif
.if ${PORT_OPTIONS:MEYECANDY}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/maxpak.pak \
		${STAGEDIR}${LIBDIR}/baseq2
.endif
.if ${PORT_OPTIONS:MGAME}
	${INSTALL_PROGRAM} ${WRKSRC}/release/game.so \
		${STAGEDIR}${LIBDIR}/baseq2
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/docs/3.*_Changes.txt \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/docs/README \
		${STAGEDIR}${DOCSDIR}/README.320
	${INSTALL_DATA} ${WRKSRC}/src/docs/changes.txt \
		${WRKSRC}/src/docs/joystick.txt \
		${WRKSRC}/src/docs/readme.txt ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.mk>
