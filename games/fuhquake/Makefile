# New ports collection makefile for:	FuhQuake
# Date created:				01 Jun 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	fuhquake
PORTVERSION=	0.31
CATEGORIES=	games
MASTER_SITES=	http://www.fuhquake.net/files/releases/v${PORTVERSION}/:q \
		ftp://gibbage.mine.nu/clients/fuhquake/releases/v${PORTVERSION}/:q \
		http://danfe.machos.ru/distfiles/qw/:p \
		http://freebsd.nsu.ru/distfiles/qw/:p
DISTNAME=	${PORTNAME}-source-v${PORTVERSION}

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:q \
		${PORTNAME}-linux-v${PORTVERSION}${EXTRACT_SUFX}:q
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-linux-v${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An excellent QuakeWorld client

.if defined(WITH_SHAREWARE_DATA)
DISTFILES+=	q1-shareware-pak0.pak:p
PLIST_SUB+=	SHAREWARE=""
.else
PLIST_SUB+=	SHAREWARE="@comment "
.endif

.if exists(${LOCALBASE}/lib/libvga.so.1)
WITH_SVGA=	yes
.endif

.if exists(${X11BASE}/lib/libxmms.so.4)
WITH_XMMS=	yes
.endif

USE_ZIP=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && !defined(WITHOUT_SVGA) && defined(WITH_SVGA)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
END_TARGETS+=	${PORTNAME}-svga
PLIST_SUB+=	SVGA=""
.else
PLIST_SUB+=	SVGA="@comment "
.endif

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
END_TARGETS+=	${PORTNAME}-x11
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

.if !defined(WITHOUT_GLX)
USE_GL=		yes
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg
END_TARGETS+=	${PORTNAME}-glx
PLIST_SUB+=	GLX=""
.else
PLIST_SUB+=	GLX="@comment "
.endif

.if !defined(WITHOUT_XMMS) && defined(WITH_XMMS) && !(defined(WITHOUT_X11) && defined(WITHOUT_GLX))
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
MAKE_ARGS+=	-DWITH_XMMS PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}
.endif

PKGMESSAGE=	${WRKDIR}/pkg-message

pre-everything::
.if ${ARCH} == "i386" && !defined(WITH_SVGA)
	@${ECHO_MSG} "Define WITH_SVGA to build SVGA client"
.elif !defined(WITHOUT_SVGA)
	@${ECHO_MSG} "Define WITHOUT_SVGA to disable building of SVGA client"
.endif
.if !defined(WITH_XMMS)
	@${ECHO_MSG} "Define WITH_XMMS to enable \`\`MP3 Player'' feature"
.elif !defined(WITHOUT_XMMS)
	@${ECHO_MSG} "Define WITHOUT_XMMS to build without \`\`MP3 Player'' feature"
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
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "Define WITH_OPTIMIZED_CFLAGS to enable extra optimization options"
.endif
.if ${ARCH} == "i386" && !defined(WITHOUT_X86_ASM)
	@${ECHO_MSG} "Define WITHOUT_X86_ASM to disable x86 assembly code"
.endif

MAKEFILE=	${FILESDIR}/Makefile
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/source

post-patch:
	@${REINPLACE_CMD} -e 's|%%BASEDIR%%|${DATADIR}|' ${WRKSRC}/common.c
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|' ${WRKSRC}/mp3_player.c
	@${CP} ${FILESDIR}/*.c ${WRKSRC}

do-build:
.if !defined(WITHOUT_X11)
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} clean x11)
.endif

.if !defined(WITHOUT_GLX)
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} clean glx)
.endif

.if ${ARCH} == "i386" && defined(WITH_SVGA)
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} clean svga)
.endif

do-install:
.for tgt in ${END_TARGETS}
	${INSTALL_PROGRAM} ${WRKSRC}/${tgt} ${PREFIX}/bin
.endfor
	@${MKDIR} ${DATADIR}/qw ${DATADIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/qw/fragfile.dat ${DATADIR}/qw
	${INSTALL_DATA} ${WRKDIR}/qw/qwprogs.dat ${DATADIR}/qw
	${INSTALL_DATA} ${WRKDIR}/qw/spprogs.dat ${DATADIR}/qw
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/pak0.pak ${DATADIR}/${PORTNAME}
.if defined(WITH_SHAREWARE_DATA)
	@${MKDIR} ${DATADIR}/id1
	${INSTALL_DATA} ${_DISTDIR}/q1-shareware-pak0.pak \
		${DATADIR}/id1/pak0.pak
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for txt in FAQ-v0.30-b585 FuhQuake-v0.31-FAQ benchmark config_manager crosshairs \
	linux logitech match_tools mp3 particles pointing rulesets track
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/${txt}.txt ${DOCSDIR}
. endfor
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.txt ${DOCSDIR}
.endif

post-install:
	@${SED} -e 's|$${DATADIR}|${DATADIR}|g' ${.CURDIR}/pkg-message >${PKGMESSAGE}
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
