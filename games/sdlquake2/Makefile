# Created by: alepulver
# $FreeBSD$

PORTNAME=	sdlquake2
PORTVERSION=	0.1.4
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://koti.mbnet.fi/~turol/sdlquake2/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Combination of R1Q2 and R1GL with SDL code from Quake2Forge

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

USE_BZIP2=	yes
USE_GMAKE=	yes

OPTIONS_DEFINE=	CLIENT DEDICATED GAME
OPTIONS_DEFAULT=	CLIENT DEDICATED
CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server
GAME_DESC=	Build a main game .so file

LIBDIR=		${PREFIX}/lib/${PORTNAME}
MAKE_ENV=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR=${LIBDIR:S/${PREFIX}\///}

NO_STAGE=	yes
.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png
USE_GL=		yes
USE_SDL=	sdl
MAKE_ENV+=	BUILD_CLIENT=YES
CFLAGS+=	-I${LOCALBASE}/include/libpng15
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MDEDICATED}
MAKE_ENV+=	BUILD_DEDICATED=YES
PLIST_SUB+=	DEDICATED=""
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if ${PORT_OPTIONS:MGAME}
MAKE_ENV+=	BUILD_GAME=YES
PLIST_SUB+=	GAME=""
.else
PLIST_SUB+=	GAME="@comment "
.endif

do-install:
	${MKDIR} ${LIBDIR}/baseq2
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2 ${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/ref_sdlgl.so ${LIBDIR}
.endif
.if ${PORT_OPTIONS:MDEDICATED}
	${INSTALL_PROGRAM} ${WRKSRC}/q2ded ${PREFIX}/bin/${PORTNAME}-ded
.endif
.if ${PORT_OPTIONS:MGAME}
	${INSTALL_PROGRAM} ${WRKSRC}/baseq2/game.so ${LIBDIR}/baseq2
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
