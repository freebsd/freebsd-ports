# New ports collection makefile for:	alienarena
# Date created:				11 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	alienarena
DISTVERSION=	2006.ge
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org/~ravage/alienarena2006/ \
		http://cor.planetquake.gamespy.com/codered/files/
DISTFILES=	${PORTNAME}-2006ge-x86.run \
		aa2k6updateGE501c-x86.zip

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Alien Arena 2006 (native version)

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	${DATADIR}/arena/default.cfg:${PORTSDIR}/games/alienarena-data

USE_X_PREFIX=	yes
USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GCC=	3.2+
USE_GL=		yes
USE_GMAKE=	yes

BUILD_WRKSRC=	${WRKDIR}/source/linux
WRKSRC=		${WRKDIR}/source
ALL_TARGET=	build_release

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL "Build client that uses SDL for sound" on

SUB_FILES=	alienarena alienarena-ded
SUB_LIST=	LIBDIR=${LIBDIR}
PLIST_SUB=	LIBDIR=${LIBDIR:S/${PREFIX}\///}

LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include <bsd.port.pre.mk>

EXE_TARGETS=	crx crded
SCRIPTS=	alienarena alienarena-ded

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZED_CFLAGS=YES
.endif

.if !defined(WITHOUT_SDL)
USE_SDL=	sdl
MAKE_ENV+=	SDLSOUND=1
EXE_TARGETS+=	crx.sdl
SCRIPTS+=	alienarena-sdl
SUB_FILES+=	alienarena-sdl
PLIST_SUB+=	SDL=""
.else
PLIST_SUB+=	SDL="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f | ${GREP} -Ev \
		'(game/g_main|linux/(gl_glx|(q_sh|snd_)linux))\.c' | \
		${XARGS} ${REINPLACE_CMD} -e 's/__linux__/__unix__/g'

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && \
		${TAIL} -c +8814 ${DISTDIR}/${PORTNAME}-2006ge-x86.run | \
		${TAR} zxf -
	@${TAR} zxf ${WRKDIR}/alienarena-2006ge-src.tar.gz -C ${WRKDIR}
	@${UNZIP_CMD} -qod ${WRKDIR} ${DISTDIR}/aa2k6updateGE501c-x86.zip

do-install:
	${MKDIR} ${LIBDIR}/arena ${LIBDIR}/data1
	cd ${BUILD_WRKSRC}/release && \
		${INSTALL_PROGRAM} arena/game.so ${LIBDIR}/arena && \
		${INSTALL_PROGRAM} game.so ${LIBDIR}/data1
	${LN} -s ${DATADIR}/arena/* ${LIBDIR}/arena
	${LN} -s ${DATADIR}/botinfo ${LIBDIR}
	${LN} -s ${DATADIR}/data1/* ${LIBDIR}/data1
.for f in ${EXE_TARGETS}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/${f} ${LIBDIR}
.endfor
.for f in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKDIR}/${f} ${PREFIX}/bin
.endfor

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
