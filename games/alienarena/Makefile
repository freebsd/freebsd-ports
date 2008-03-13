# New ports collection makefile for:	alienarena
# Date created:				11 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	alienarena
PORTVERSION=	2007.610
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.simtel.com/pub/gamezone/31/5/17/
DISTNAME=	${PORTNAME}2007-20071011-linux

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Alien Arena 2006 (native version)

RUN_DEPENDS=	${DATADIR}/arena/default.cfg:${PORTSDIR}/games/alienarena-data

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes

MAKE_ENV=	WITH_DATADIR=yes WITH_LIBDIR=yes \
		DATADIR="${DATADIR}" LIBDIR="${LIBDIR}"
WRKSRC=		${WRKDIR}/${PORTNAME}2007/source
ALL_TARGET=	build-release

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL "Build SDL sound client (needs CLIENT)" on

PLIST_SUB=	LIBDIR=${LIBDIR:S/${PREFIX}\///}

LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED) && \
    defined(WITHOUT_SDL)
IGNORE=		needs at least one executable (CLIENT, DEDICATED or SDL)
.endif

.if !defined(WITHOUT_CLIENT) || !defined(WITHOUT_SDL)
LIB_DEPENDS+=	curl.4:${PORTSDIR}/ftp/curl \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png
USE_GL=		yes
.endif

.if defined(WITHOUT_CLIENT)
MAKE_ENV+=	BUILD=DEDICATED
.elif defined(WITHOUT_DEDICATED)
MAKE_ENV+=	BUILD=CLIENT
.endif

.if !defined(WITHOUT_CLIENT)
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_DEDICATED)
PLIST_SUB+=	DEDICATED=""
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZED_CFLAGS=YES
.endif

.if !defined(WITHOUT_SDL)
USE_SDL=	sdl
PLIST_SUB+=	SDL=""
.else
MAKE_ENV+=	SDLSOUND=0
PLIST_SUB+=	SDL="@comment "
.endif

do-install:
	${MKDIR} ${LIBDIR}/arena ${LIBDIR}/data1
	cd ${WRKSRC}/release && \
		${INSTALL_PROGRAM} arena/game.so ${LIBDIR}/arena && \
		${INSTALL_PROGRAM} game.so ${LIBDIR}/data1
	${LN} -s ${DATADIR}/arena/* ${LIBDIR}/arena
	${LN} -s ${DATADIR}/botinfo ${LIBDIR}
	${LN} -s ${DATADIR}/data1/* ${LIBDIR}/data1
.if !defined(WITHOUT_CLIENT)
	${INSTALL_PROGRAM} ${WRKSRC}/release/crx \
		${PREFIX}/bin/${PORTNAME}
.endif
.if !defined(WITHOUT_DEDICATED)
	${INSTALL_PROGRAM} ${WRKSRC}/release/crded \
		${PREFIX}/bin/${PORTNAME}-ded
.endif
.if !defined(WITHOUT_SDL)
	${INSTALL_PROGRAM} ${WRKSRC}/release/crx.sdl \
		${PREFIX}/bin/${PORTNAME}-sdl
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
