# Created by: alepulver
# $FreeBSD$

PORTNAME=	uhexen2
PORTVERSION=	1.5.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Hammer%20of%20Thyrion/${PORTVERSION}/Source \
		SF/${PORTNAME}/Hexen2%20GameData/gamedata-1.28:data
DISTNAME=	hexen2source-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		gamedata-all-1.28${EXTRACT_SUFX}:data
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hexen II source port supporting Linux/FreeBSD/Unix/Windows

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libmad.so:${PORTSDIR}/audio/libmad \
		libvorbis.so:${PORTSDIR}/audio/libvorbis

OPTIONS_MULTI=	BIN
OPTIONS_MULTI_BIN=	HEXEN2 HW
OPTIONS_DEFINE=	LAUNCHER_GTK1 LAUNCHER_GTK2 LAUNCHER_GTK3 DOCS
OPTIONS_DEFAULT=	HEXEN2 HW LAUNCHER_GTK2
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT_i386=	ASM

HEXEN2_DESC=		Build Hexen II clients and servers
HW_DESC=		Build HexenWorld clients and servers
LAUNCHER_GTK1_DESC=	Build graphical (GTK1) game launcher
LAUNCHER_GTK2_DESC=	Build graphical (GTK2) game launcher
LAUNCHER_GTK3_DESC=	Build graphical (GTK3) game launcher

USES=		gmake pkgconfig tar:tgz
USE_SDL=	sdl
USE_GL=		gl
MAKE_ENV=	X11BASE="${LOCALBASE}"
MAKE_JOBS_UNSAFE=yes

SUB_FILES=	pkg-message

PORTSCOUT=	skipb:yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHEXEN2}
MAKE_ENV+=	BUILD_HEXEN2=yes
PLIST_SUB+=	HEXEN2=""
UH2_BIN+=	engine/hexen2/glhexen2 \
		engine/hexen2/hexen2
.else
PLIST_SUB+=	HEXEN2="@comment "
.endif

.if ${PORT_OPTIONS:MHW}
MASTER_SITES+=	SF/${PORTNAME}/Hexen2%20GameData/hexenworld-pakfiles:hw
DISTFILES+=	hexenworld-pakfiles-0.15${EXTRACT_SUFX}:hw
MAKE_ENV+=	BUILD_HW=yes
PLIST_SUB+=	HW=""
UH2_BIN+=	engine/hexenworld/client/glhwcl \
		engine/hexenworld/client/hwcl \
		engine/hexenworld/server/hwsv \
		hw_utils/hwmaster/hwmaster
.else
PLIST_SUB+=	HW="@comment "
.endif

.if ${PORT_OPTIONS:MLAUNCHER_GTK1}
USE_GNOME+=	gtk12
MAKE_ENV+=	BUILD_LAUNCHER_GTK1=yes
PLIST_SUB+=	LAUNCHER_GTK1=""
.else
PLIST_SUB+=	LAUNCHER_GTK1="@comment "
.endif

.if ${PORT_OPTIONS:MLAUNCHER_GTK2}
USE_GNOME+=	gtk20
MAKE_ENV+=	BUILD_LAUNCHER_GTK2=yes
PLIST_SUB+=	LAUNCHER_GTK2=""
.else
PLIST_SUB+=	LAUNCHER_GTK2="@comment "
.endif

.if ${PORT_OPTIONS:MLAUNCHER_GTK3}
USE_GNOME+=	gtk30
MAKE_ENV+=	BUILD_LAUNCHER_GTK3=yes
PLIST_SUB+=	LAUNCHER_GTK3=""
.else
PLIST_SUB+=	LAUNCHER_GTK3="@comment "
.endif

.if ${PORT_OPTIONS:MASM}
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
MAKE_ENV+=	USE_X86_ASM=yes
.else
MAKE_ENV+=	USE_X86_ASM=no
.endif

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

post-patch:
.for f in engine/hexen2/Makefile engine/hexenworld/client/Makefile \
	engine/hexenworld/server/Makefile hw_utils/hwmaster/Makefile \
	launcher/Makefile libs/timidity/Makefile
	@${REINPLACE_CMD} -e \
		'/^USE_X86_ASM/s|^|#| ; \
		 /^CPU_X86/s|^|#| ; \
		 /^CFLAGS/s| -g | | ; \
		 /^CFLAGS/s| -O2 | | ; \
		 /^PTHREAD_LIBS/s|-lpthread|-pthread|' ${WRKSRC}/${f}
.endfor
.for f in engine/h2shared/cd_bsd.c
	@${REINPLACE_CMD} -e \
		's|"acd0"|"cd0"|' ${WRKSRC}/${f}
.endfor
.for f in engine/hexen2/sys_unix.c engine/hexenworld/client/sys_unix.c
	@${REINPLACE_CMD} -e \
		'/parms.basedir/s|= cwd;|= "${DATADIR}";|' ${WRKSRC}/${f}
.endfor

do-install:
.for f in ${UH2_BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}/data1
.for f in default.cfg hexen.rc progs.dat progs2.dat strings.txt
	${INSTALL_DATA} ${WRKDIR}/data1/${f} ${STAGEDIR}${DATADIR}/data1
.endfor
	${INSTALL_DATA} ${WRKDIR}/patchdat/data1/* ${STAGEDIR}${DATADIR}/data1
	@(cd ${WRKDIR} && ${COPYTREE_SHARE} portals ${STAGEDIR}${DATADIR})
.if ${PORT_OPTIONS:MHW}
	${MKDIR} ${STAGEDIR}${DATADIR}/hw
	${INSTALL_DATA} ${WRKDIR}/hw/* ${STAGEDIR}${DATADIR}/hw
.endif
.if ${PORT_OPTIONS:MLAUNCHER_GTK1}
	${INSTALL_PROGRAM} ${WRKSRC}/launcher/h2launcher.gtk1 \
		${STAGEDIR}${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MLAUNCHER_GTK2}
	${INSTALL_PROGRAM} ${WRKSRC}/launcher/h2launcher.gtk2 \
		${STAGEDIR}${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MLAUNCHER_GTK3}
	${INSTALL_PROGRAM} ${WRKSRC}/launcher/h2launcher.gtk3 \
		${STAGEDIR}${PREFIX}/bin
.endif
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
