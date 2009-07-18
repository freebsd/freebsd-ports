# New ports collection makefile for:	FuhQuake
# Date created:				01 Jun 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	fuhquake
PORTVERSION=	0.31
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.fuhquake.net/files/releases/v${PORTVERSION}/ \
		ftp://gibbage.mine.nu/clients/fuhquake/releases/v${PORTVERSION}/ \
		http://gamefiles.blueyonder.co.uk/blueyondergames/quake/quakeworld/clients/fuhquake/source/ \
		http://www.fuhquake.net/files/misc/:misc
DISTNAME=	${PORTNAME}-source-v${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-linux-v${PORTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An excellent QuakeWorld client

USE_ZIP=	yes
MAKEFILE=	${FILESDIR}/Makefile
WRKSRC=		${WRKDIR}/source

OPTIONS=	GLX "Build GLX client" on \
		HUD "High quality HUD images" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		X11 "Build X11 client" on \
		X86_ASM "Enable x86 assembly code" on \
		XMMS "Enable MP3 Player feature" off

DATADIR=	${Q1DIR}
MAKE_ENV=	DATADIR="${DATADIR}"

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if !defined(WITH_GLX) && !defined(WITH_X11)
IGNORE=		needs at least one client (GLX or X11)
.endif

.if defined(WITH_GLX)
USE_GL=		yes
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	GLX=""
CLIENTS+=	glx
.else
PLIST_SUB+=	GLX="@comment "
.endif

.if defined(WITH_HUD)
DISTFILES+=	fuh-hud${EXTRACT_SUFX}:misc
PLIST_SUB+=	HUD=""
.else
PLIST_SUB+=	HUD="@comment "
.endif

.for f in OPTIMIZED_CFLAGS X86_ASM
.   if defined(WITH_${f})
MAKE_ARGS+=	-DWITH_${f}
.   else
MAKE_ARGS+=	-DWITHOUT_${f}
.   endif
.endfor

.if defined(WITH_X11)
USE_XORG=	x11 xxf86dga
PLIST_SUB+=	X11=""
CLIENTS+=	x11
.else
PLIST_SUB+=	X11="@comment "
.endif

.if (defined(WITH_XMMS) || exists(${LOCALBASE}/lib/libxmms.so.4)) && \
    defined(CLIENTS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
MAKE_ARGS+=	-DWITH_XMMS \
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
		PTHREAD_LIBS=${PTHREAD_LIBS}
.endif

post-patch:
	@${CP} ${FILESDIR}/*.c ${WRKSRC}

do-build:
.for f in ${CLIENTS}
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} clean ${f})
.endfor

do-install:
.for f in ${CLIENTS}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-${f} ${PREFIX}/bin
.endfor
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/qw/*.dat ${DATADIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/pak0.pak ${DATADIR}/${PORTNAME}
.if defined(WITH_HUD)
	${MKDIR} ${DATADIR}/${PORTNAME}/textures/wad
	${INSTALL_DATA} ${WRKDIR}/qw/charset.png ${DATADIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/qw/textures/wad/* \
		${DATADIR}/${PORTNAME}/textures/wad
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/*.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
