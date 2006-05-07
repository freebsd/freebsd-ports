# New ports collection makefile for:	FuhQuake
# Date created:				01 Jun 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	fuhquake
PORTVERSION=	0.31
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.fuhquake.net/files/releases/v${PORTVERSION}/:q \
		http://www.fuhquake.net/files/extras/:s \
		ftp://gibbage.mine.nu/clients/fuhquake/releases/v${PORTVERSION}/:q \
		http://gamefiles.blueyonder.co.uk/blueyondergames/quake/quakeworld/clients/fuhquake/source/:q \
		http://gamefiles.blueyonder.co.uk/blueyondergames/quake/quakeworld/clients/fuhquake/addons/:s
DISTNAME=	${PORTNAME}-source-v${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:q \
		${PORTNAME}-linux-v${PORTVERSION}${EXTRACT_SUFX}:q
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-linux-v${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An excellent QuakeWorld client

WRKSRC=		${WRKDIR}/source

USE_ZIP=	yes

MAKEFILE=	${FILESDIR}/Makefile

OPTIONS=	GLX "Build GLX client" on \
		LITS "Enable coloured lighting" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SKYBOXES "Install skyboxes pak" off \
		X11 "Build X11 client" on \
		X86_ASM "Enable x86 assembly code" on \
		XMMS "Enable MP3 Player feature" off

DATADIR=	${Q1DIR}

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_GLX)
USE_GL=		yes
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	GLX=""
CLIENTS+=	glx
.else
PLIST_SUB+=	GLX="@comment "
.endif

.if defined(WITH_LITS)
DISTFILES+=	${PORTNAME}-lits.rar:s
BUILD_DEPENDS+=	unrar:${PORTSDIR}/archivers/unrar
PLIST_SUB+=	LITS=""
.else
PLIST_SUB+=	LITS="@comment "
.endif

.for f in OPTIMIZED_CFLAGS X86_ASM
.   if defined(WITH_${f})
MAKE_ARGS+=	-DWITH_${f}
.   else
MAKE_ARGS+=	-DWITHOUT_${f}
.   endif
.endfor

.if defined(WITH_SKYBOXES)
DISTFILES+=	${PORTNAME}-skyboxes${EXTRACT_SUFX}:s
EXTRACT_ONLY+=	${PORTNAME}-skyboxes${EXTRACT_SUFX}
PLIST_SUB+=	SKYBOXES=""
.else
PLIST_SUB+=	SKYBOXES="@comment "
.endif

.if defined(WITH_X11)
USE_XLIB=	yes
PLIST_SUB+=	X11=""
CLIENTS+=	x11
.else
PLIST_SUB+=	X11="@comment "
.endif

.if (defined(WITH_XMMS) || exists(${X11BASE}/lib/libxmms.so.4)) && \
    defined(CLIENTS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
MAKE_ARGS+=	-DWITH_XMMS \
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
		PTHREAD_LIBS=${PTHREAD_LIBS}
.endif

.if defined(WITH_LITS)
post-extract:
	@${MKDIR} ${WRKDIR}/lits
	@unrar x -inul ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-lits.rar \
		${WRKDIR}/lits
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%BASEDIR%%|${DATADIR}|' ${WRKSRC}/common.c
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|' ${WRKSRC}/mp3_player.c
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
.if defined(WITH_LITS)
	${CP} -R ${WRKDIR}/lits ${DATADIR}/${PORTNAME}
.endif
.if defined(WITH_SKYBOXES)
	${INSTALL_DATA} ${WRKDIR}/pakX.pak ${DATADIR}/${PORTNAME}/pak1.pak
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/*.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
