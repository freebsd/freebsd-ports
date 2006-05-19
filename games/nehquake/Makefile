# New ports collection makefile for:	nehquake
# Date created:				16 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	nehquake
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://qudos.quakedev.com/linux/quake1/
DISTNAME=	NehQuake-bjp-bin-src.linux

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Quake engine designed for playing Nehahra

USE_BZIP2=	yes
USE_DOS2UNIX=	yes
USE_GCC=	3.2+
USE_GL=		yes
USE_GMAKE=	yes

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL "Build SDL client" on

ALL_TARGET=	release
SUB_FILES=	pkg-message

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZED_CFLAGS=YES
.endif

.if !defined(WITHOUT_SDL)
USE_SDL=	sdl
MAKE_ENV+=	BUILD_SDL=YES
PLIST_SUB+=	SDL=""
.else
PLIST_SUB+=	SDL="@comment "
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/nehahra ${PREFIX}/bin
.if !defined(WITHOUT_SDL)
	${INSTALL_PROGRAM} ${WRKSRC}/release/nehahra-sdl ${PREFIX}/bin
.endif
	${MKDIR} ${Q1DIR}/nehahra

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
