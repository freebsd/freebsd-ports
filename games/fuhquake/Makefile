# New ports collection makefile for:	FuhQuake
# Date created:				01 Jun 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	fuhquake
PORTVERSION=	0.28
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.fuhquake.net/files/source/:src \
		http://www.fuhquake.net/files/releases/:dat \
		http://freebsd.nsu.ru/distfiles/:pak
DISTNAME=	${PORTNAME}-source-v${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		${PORTNAME}-linux-v${PORTVERSION}${EXTRACT_SUFX}:dat \
		pak0.pak:pak

MAINTAINER=	danfe@regency.nsu.ru
COMMENT=	An excellent QuakeWorld client

.if defined(WITH_SHAREWARE_DATA)
DISTFILES+=	q1-shareware-pak0.pak:pak
PLIST_SUB+=	SHAREWARE=""
.else
PLIST_SUB+=	SHAREWARE="@comment "
.endif

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-linux-v${PORTVERSION}${EXTRACT_SUFX}

.if exists(${LOCALBASE}/lib/libvga.so.1)
WITH_SVGA=	yes
.endif

.if exists(${X11BASE}/lib/libxmms.so.3)
WITH_XMMS=	yes
.endif

.if ${MACHINE_ARCH} == "i386" && !defined(WITHOUT_SVGA) && defined(WITH_SVGA)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
END_TARGETS+=	${PORTNAME}-svga
PLIST_SUB+=	SVGA=""
.else
PLIST_SUB+=	SVGA="@comment "
.endif

.if !defined(WITHOUT_X11)
LIB_DEPENDS+=	X11.6:${PORTSDIR}/x11/XFree86-4-libraries \
		Xext.6:${PORTSDIR}/x11/XFree86-4-libraries
END_TARGETS+=	${PORTNAME}-x11
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

.if !defined(WITHOUT_GLX)
LIB_DEPENDS+=	GL.1:${PORTSDIR}/x11/XFree86-4-libraries \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg
END_TARGETS+=	${PORTNAME}-glx
PLIST_SUB+=	GLX=""
.else
PLIST_SUB+=	GLX="@comment "
.endif

.if !defined(WITHOUT_XMMS) && defined(WITH_XMMS) && !(defined(WITHOUT_X11) && defined(WITHOUT_GLX))
LIB_DEPENDS+=	xmms.3:${PORTSDIR}/multimedia/xmms
MAKE_ARGS+=	-DWITH_XMMS
.endif

pre-everything::
.if ${MACHINE_ARCH} == "i386" && !defined(WITH_SVGA)
	@${ECHO_MSG} "Define WITH_SVGA to build SVGA client"
.endif
.if !defined(WITH_XMMS)
	@${ECHO_MSG} "Define WITH_XMMS to enable \`\`MP3 Player'' feature"
.endif
.if !defined(WITHOUT_X11)
	@${ECHO_MSG} "Define WITHOUT_X11 to disable building of X11 client"
.endif
.if !defined(WITHOUT_GLX)
	@${ECHO_MSG} "Define WITHOUT_GLX to disable building of GLX client"
.endif
.if defined(WITH_SHAREWARE_DATA)
	@${ECHO_MSG} "Define WITH_SHAREWARE_DATA to install demo version game data"
.endif
.if !defined(WITHOUT_XMMS) && exists(${X11BASE}/lib/libxmms.so.3)
	@${ECHO_MSG} "Define WITHOUT_XMMS to build without \`\`MP3 Player'' feature"
.endif
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "Define WITH_OPTIMIZED_CFLAGS to enable extra optimization options"
.endif
.if ${MACHINE_ARCH} == "i386" && !defined(WITHOUT_X86_ASM)
	@${ECHO_MSG} "Define WITHOUT_X86_ASM to disable x86 assembly code"
.endif

MAKEFILE=	${FILESDIR}/Makefile
USE_REINPLACE=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/source

post-extract:
	@${FIND} -E ${WRKDIR} -type f -iregex ".*\.(c|h|s|txt)" -exec ${FILESDIR}/fix^m.sh '{}' \;
	@${CP} ${FILESDIR}/*.c ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|%%%%BASEDIR%%%%|${DATADIR}|' ${WRKSRC}/common.c
.for file in cmd.h common.h render.h console.h quakedef.h cvar.h cvar_groups.h \
	fmod.h config_manager.h auth.h logging.h ignore.h fchecks.h rulesets.h \
	modules.h mp3_player.h r_local.h movie.c logging.c quotes.h zone.c \
	gl_local.h gl_image.h gl_warp_sin.h
	@${ECHO_CMD} "" >> ${WRKSRC}/${file}
.endfor

do-build:
.if !defined(WITHOUT_X11)
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} clean x11)
.endif

.if !defined(WITHOUT_GLX)
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} clean glx)
.endif

.if ${MACHINE_ARCH} == "i386" && defined(WITH_SVGA)
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} clean svga)
.endif

do-install:
.for tgt in ${END_TARGETS}
	${INSTALL_PROGRAM} ${WRKSRC}/${tgt} ${PREFIX}/bin
.endfor
	@${MKDIR} ${DATADIR}/qw ${DATADIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/qw/qwprogs.dat ${DATADIR}/qw
	${INSTALL_DATA} ${WRKDIR}/qw/spprogs.dat ${DATADIR}/qw
	${INSTALL_DATA} ${DISTDIR}/pak0.pak ${DATADIR}/${PORTNAME}
.if defined(WITH_SHAREWARE_DATA)
	@${MKDIR} ${DATADIR}/id1
	${INSTALL_DATA} ${DISTDIR}/q1-shareware-pak0.pak \
		${DATADIR}/id1/pak0.pak
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for txt in benchmark config_manager crosshairs linux logitech mp3 \
	particles pointing rulesets track
	${INSTALL_DATA} ${WRKDIR}/doc/${txt}.txt ${DOCSDIR}
. endfor
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.txt ${DOCSDIR}
.endif

post-install:
	@${SED} -e 's|$${DATADIR}|${DATADIR}|g' ${PKGMESSAGE}

.include <bsd.port.mk>
