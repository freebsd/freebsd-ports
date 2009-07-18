# New ports collection makefile for:	sdlquake2
# Date created:				5 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	sdlquake2
PORTVERSION=	0.1.4
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://koti.mbnet.fi/~turol/sdlquake2/

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Combination of R1Q2 and R1GL with SDL code from Quake2Forge

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

USE_BZIP2=	yes
USE_GMAKE=	yes

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on \
		GAME "Build a main game .so file" off

LIBDIR=		${PREFIX}/lib/${PORTNAME}
MAKE_ENV=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR=${LIBDIR:S/${PREFIX}\///}

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_CLIENT)
LIB_DEPENDS+=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png
USE_GL=		yes
USE_SDL=	sdl
MAKE_ENV+=	BUILD_CLIENT=YES
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if defined(WITH_DEDICATED)
MAKE_ENV+=	BUILD_DEDICATED=YES
PLIST_SUB+=	DEDICATED=""
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if defined(WITH_GAME)
MAKE_ENV+=	BUILD_GAME=YES
PLIST_SUB+=	GAME=""
.else
PLIST_SUB+=	GAME="@comment "
.endif

do-install:
	${MKDIR} ${LIBDIR}/baseq2
.if defined(WITH_CLIENT)
	${INSTALL_PROGRAM} ${WRKSRC}/quake2 ${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/ref_sdlgl.so ${LIBDIR}
.endif
.if defined(WITH_DEDICATED)
	${INSTALL_PROGRAM} ${WRKSRC}/q2ded ${PREFIX}/bin/${PORTNAME}-ded
.endif
.if defined(WITH_GAME)
	${INSTALL_PROGRAM} ${WRKSRC}/baseq2/game.so ${LIBDIR}/baseq2
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
