# New ports collection makefile for:	alienarena
# Date created:				11 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	alienarena
PORTVERSION=	2007.604
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://cor.planetquake.gamespy.com/codered/files/
DISTNAME=	${PORTNAME}2007-linux20070225-x86

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Alien Arena 2006 (native version)

RUN_DEPENDS=	${DATADIR}/arena/default.cfg:${PORTSDIR}/games/alienarena-data

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GCC=	3.4+
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:C/-linux.*//}/source
BUILD_WRKSRC=	${WRKSRC}/linux
ALL_TARGET=	build_release

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL "Build client that uses SDL for sound" on

SUB_LIST=	LIBDIR=${LIBDIR}
PLIST_SUB=	LIBDIR=${LIBDIR:S/${PREFIX}\///}

LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED) && \
    defined(WITHOUT_SDL)
IGNORE=		needs at least one executable (CLIENT, DEDICATED or SDL)
.endif

.if !defined(WITHOUT_CLIENT) || !defined(WITHOUT_SDL)
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
USE_GL=		yes
.endif

.if !defined(WITHOUT_CLIENT)
MAKE_ENV+=	CLIENT=1
AA_TARGETS+=	crx
AA_SCRIPTS+=	alienarena
SUB_FILES+=	alienarena
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_DEDICATED)
MAKE_ENV+=	DEDICATED=1
AA_TARGETS+=	crded
AA_SCRIPTS+=	alienarena-ded
SUB_FILES+=	alienarena-ded
PLIST_SUB+=	DEDICATED=""
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZED_CFLAGS=YES
.endif

.if !defined(WITHOUT_SDL)
USE_SDL=	sdl
MAKE_ENV+=	SDLSOUND=1
AA_TARGETS+=	crx.sdl
AA_SCRIPTS+=	alienarena-sdl
SUB_FILES+=	alienarena-sdl
PLIST_SUB+=	SDL=""
.else
PLIST_SUB+=	SDL="@comment "
.endif

post-extract:
	@${FIND} ${WRKSRC} | ${XARGS} ${CHMOD} u+w

post-patch:
	@${FIND} ${WRKSRC} -type f | ${GREP} -Ev \
		'(game/g_main|linux/(gl_glx|(q_sh|snd_)linux))\.c' | \
		${XARGS} ${REINPLACE_CMD} -e 's/__linux__/__unix__/g'

do-install:
	${MKDIR} ${LIBDIR}/arena ${LIBDIR}/data1
	cd ${BUILD_WRKSRC}/release && \
		${INSTALL_PROGRAM} arena/game.so ${LIBDIR}/arena && \
		${INSTALL_PROGRAM} game.so ${LIBDIR}/data1
	${LN} -s ${DATADIR}/arena/* ${LIBDIR}/arena
	${LN} -s ${DATADIR}/botinfo ${LIBDIR}
	${LN} -s ${DATADIR}/data1/* ${LIBDIR}/data1
.for f in ${AA_TARGETS}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/${f} ${LIBDIR}
.endfor
.for f in ${AA_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKDIR}/${f} ${PREFIX}/bin
.endfor

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
